# Open-Ride-On

Ride-on eletric cars arduino project. Allows the soft start and soft slowdown of IBT_2 H-bridge using Arduino.
	Here is a good write up related to the H-Bridge: https://www.hessmer.org/blog/2013/12/28/ibt-2-h-bridge-with-arduino/ although we be using an accelerator pedal to activate automatic linear acceleration of the vehicle. The motor will also be ramping down when the accelerator pedal is not being depressed. 
 

Using an Arduino and an IBT-2 H-bridge you can tune the acceleration and deceleraton of your child's ride on car.

I will add further notes, pictures, and further features soon.

The below items will be needed to perform this upgrade:

- Arduino - I use the Arduino Micro for small applicatons like this. <br>
- IBT_2 BTS7960 H-Bridge (43amp max and control for up to 27volts)<br>
- 12v or 24v - 5v adapter - You can use a USB car charger (cigarette lighter) if you would like to. <br>
- Project Box - Just a plastic housing for your Arduino, H-bridge,and wires to go inside. You can make it out of Legos if you want to. <br>
- X switch for polarity reversal - Eventually I would like to control a three position switch for when the drive/park/reverse switch code is written and tested.<br>   
- Dupont connectors/wires<br>
- Button wire connectors<br>

Optional items:<br>
- Ferrule connectors and Ferrule crimper<br>

<b>Note on vehicle traction:</b><br>
<br>
If using driven rubber tires or tires with better traction, be sure to set the deceleration so that it does not decelerate too quickly or it will destroy the plastic gears in the gearbox and possibly break the gearbox housing. Ask me how I know... :)<br>

This is an improvement over the Patchbots soft-start-code as it allows for slow deceleration of the vehicle instead of abruptly stopping when the accelerator is not being pressed. <br>

<b>Future features:</b><br> 

Drive/Park/Reverse switch control<br>
- Control motor direction depending on drive mode selection
- Slow to complete stop before proceeding in different 
direction
	
Pitch angle sensor to limit motor speed<br>
- Implement MPU6050 sensor to track pitch, yaw, and roll to
slow or stop vehicle when specific angles are reached.<br>
- This will be helpful for those using these vehicles in varying topography (hilly) as we can ramp down the motor based on the pitch of the vehicle. This will help the vehicle not runaway or maintain speed when it is going downhill.<br>

Skid Steer Control - Forward/reverse control of tracks or wheels on left and right sides of vehicle<br>

Future Testing: <br>
<br>
Parallel connection of IBT_2 BTS7960 H-Bridge for higher amperage applications<br>
- I would like to test and see how these H-Bridges perform when wired in parallel.<br> 
- This may be a good application of larger two person ride on vehicles or for riders with more mass.<br>
- The IBT_2 BTS7960 is rated for 43amp and can control up to 27volts. I have seen them fail with much less than 43amp run through them.<br>
- By running two or more in parallel you could better distribute the amperage load across multiple H-bridges.<br>
- You could even run one H-bridge to each motor.<br>

For those driving four or more tires. <br>
- Four-wheel drive / front-wheel drive / Rear wheel drive switching controlled by microcontroller.<br>
- Series and parallel switching of motors with microcontroller or by switching<br>
- Use one H-Bridge per axle maybe.
 
Series and parallel wiring diagrams for similar performance to an open differential or limit slip differential.<br>
- In testing different wiring schemes I have found that wiring two motors in series performs like an open differential. It makes sense as when one motor is stopped the other motor gets the rest of the power. I found that wiring two or motors in parallel performs more like a limited slip differential. This is helpful when wiring the front axle to be powered in a four-wheel drive application as it will steer better and have less drag from the motors if they are wired in series.  
 

