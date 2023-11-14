# Kids-Ride-on-Car-Soft-Start---Soft-Slow

Kids ride-on eletric cars for children arduino project. Allows the soft start and soft slowdown of IBT_2 H-bridge using Arduino.

Using an Arduino and an IBT-2 H-bridge you can tune the acceleration and deceleraton of your child's ride on car.

I will add further notes, pictures, and further features soon.

The below items will be needed to perform this upgrade:

Arduino - I use the micro <br>
IBT_2 H-Bridge <br>
12v or 24v - 5v adapter - You can use a USB car charger if you would like to. <br>
Project Box - Just a plastic housing for your Arduino, H-bridge,and wires to go inside. You can make it out of Legos if you want to. 

If using driven rubber tires or tires with better traction, be sure to set the deceleration so that it does not decelerate too quickly or it will destroy the plastic gears in the gearbox and possibly break the gearbox housing. Ask me how I know... :)

This is an improvement over the Patchbots soft-start-code as it allows for slow deceleration of the vehicle instead of abruptly stopping when the accelerator is not being pressed. 

Future features: 

Drive/Park/Reverse switch control

- Control motor direction depending on drive mode selection
- Slow to complete stop before proceeding in different 
direction
	
Pitch angle sensor to limit motor speed
- Implement MPU6050 sensor to track pitch, yaw, and roll to
slow or stop vehicle when specific angles are reached. 
