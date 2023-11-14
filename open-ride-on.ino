// =======================================================================================
//                                  Kid Motorz 12V Conversion -- Shelby Cobra
// =======================================================================================
//                            Modified youtube.com\PatchBOTS Code by: vintagegamingsystems
// =======================================================================================
//                                    microcontroller  ---  Arduino Micro
// --------------------------------------------------------------------------------------
//
//                                               Arduino Micro
//                                               ------------
//                                               |           |
//                                      +--------------------------------+
//                                      |                                |
//                                      | [ ]D13~             D12|A11[ ] | 
//                                      | [ ]+3V3                ~D11[ ] |  
//                                      | [ ]AREF            ~D10|A10[ ] |
//                                      | [ ]A0|D18            ~D9|A9[ ] | 
//                                      | [ ]A1|D19             D8|A8[ ] |
//                                      | [ ]A2|D20                D7[ ] |
//                                      | [ ]A3|D21            ~D6|A7[ ] | RPWM
//                                      | [ ]A4|D22               ~D5[ ] | Accelerator Switch
//                                      | [ ]A5|D23            ~D4|A6[ ] |
//                                      | [ ]NC               ~D3|SCL[ ] | 
//                                      | [ ]NC                D2/SDA[ ] |
//       IBT_2 H-Bridge VCC, EN_L, EN_R | [ ]+5                   GND[ ] | Accelerator Switch GND                               
//                                      | [ ]Reset              Reset[ ] |
//                   IBT_2 H-Bridge GND | [ ]GND                D0/RX[ ] |
//                                      | [ ]VIN                D1/TX[ ] |
//                                      | [ ]MISO/D14          D17/SS[ ] |
//                                      | [ ]SCK/D15         D16/MOSI[ ] |
//                                      +--------------------------------+
//
//
// ---------------------------------------------------------------------------------------
//                                   NOTES
// ---------------------------------------------------------------------------------------
// Code ramps motor up while accelerator is depressed and ramps motor down when accelerator is not pressed.
// 
// ---------------------------------------------------------------------------------------
//                                   definitions
// ---------------------------------------------------------------------------------------

#define Switch  5 //defines Pin 5 on the Arduino for the digital switch at the gas pedal
// Changed this so I could input 5volts for gas pedal detection.
#define RPWM 6  // Wire this to RPWM on the BTS7960 motor controller. 
//#define LPWM 10 // This isn't used in the code.  It would give us a reverse function via the motor controller, which isn't really useful in this setting. 


//Below are variables we will be using in the code.
int gasSwitch = 1;

int pwmWrite = 0; //default boot up speed is 0
int rampSpeed; //this will be the starting point of our "ramp ups" in Speed 2 and Speed 3



void setup() {  //this section just tells the arduino what pins will be doing what

  Serial.begin(38400);

  pinMode (Switch, INPUT_PULLUP); // Changed this so I could input 5volts for gas pedal detection.
  pinMode (RPWM, OUTPUT);
//  pinMode (LPWM, OUTPUT);
  //analogWrite(RPWM, HIGH);
}


// ---------------------------------------------------------------------------------------
//                                  MAIN PROGRAM LOOP
// ---------------------------------------------------------------------------------------

void loop() {  //THIS IS THE START OF OUR MAIN LOOP

  //**************************GET VALUES*********************************************

  gasSwitch = digitalRead(Switch); //check to see if Gas Pedal is engaged
  Serial.print(gasSwitch);


  if (true) 
      { 
      pwmWrite = 215; //this value determines the top PWM value at the 2nd setting. The number is out of 255 so in this case 215/255 is about 85% power. Change value as you see fit
      //rampSpeed = 0; //Changed this 0 so we don't draw power when the gas pedal is not pressed.
        while   (gasSwitch == 1) 
        { //this while loop stops everything while the gas pedal is open.
          Serial.print("GasSwitch");
          Serial.println(gasSwitch);
          Serial.println(rampSpeed);
          if (rampSpeed > 0)
           { rampSpeed--; // Subtract 1 to ramp speed to decrease motor speed
           delay(4); // Delays ramp speed decrease to slow the vehicle down slowly
            Serial.println(rampSpeed);
            analogWrite(RPWM, rampSpeed); //while the gas pedal is open, write our starting point to the motors.
            gasSwitch = digitalRead(Switch); //check again to see to if gas pedal is pressed.
        }
        Serial.println(rampSpeed);
            analogWrite(RPWM, rampSpeed); //while the gas pedal is open, write our starting point to the motors.
            gasSwitch = digitalRead(Switch); //check again to see to if gas pedal is pressed.
        
      }
        rampSpeed=70; //Our goal is to ramp up to "pwmWrite."  I chose 175 as a starting point for that ramp based on the fact that I've run that value a lot without problems for the gears.
        while (gasSwitch == 0 ) 
        { //if Gas Pedal is pressed....
          Serial.print("Gas_ON: ");
          Serial.println(gasSwitch);
            if (rampSpeed < pwmWrite) 
            { //and rampSpeed is below our top speed....
               Serial.print("RampSpeed: ");
               Serial.println(rampSpeed);
               rampSpeed++; //add 1 to ramp speed
               delay(40); //40//delay before running the previous two lines again.  In my bench tests, a 20ms delay equals a 1 second ramp up from 175 to 215.  40ms = 2 seconds, 60 = 3 seconds, 80 = 4 seconds and so on. This will vary, but a decent starting point.
               analogWrite(RPWM, rampSpeed);
               Serial.println(RPWM);
            }
      analogWrite(RPWM, rampSpeed); //write the current value of rampSpeed (when the if statement catches up to the final "pwmWrite" speed, it will hang there until the foot is taken off the gas).
      gasSwitch = digitalRead(Switch); //check again to see to if gas pedal is pressed.
        }
      }

}

//Use for debugging. 


//Serial.print("PWM Write: ");
//Serial.print(pwmWrite);
//Serial.print(", ");
//Serial.print("RampSpeed: ");
//Serial.print(rampSpeed);
//Serial.print(", ");
//Serial.println("24V");
