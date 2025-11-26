# Joystick-Testing

This repository contains all my work for understanding how the Arduino joystick functions and how it can be used to control the RC car. The car is controlled as rear wheel drive and front wheel steer. The programs in this repository have not taken into account how the outermost wheel in a turn spins more than the innermost wheel. That is the next step in the creation of the RC car, and will be put in a different repository.

Joystick-Output-Testing.ino has my process of learning how the outputs of the Arduino joystick function and can be recorded.

Forward-Backward-Testing.ino has my process for learning how to control the motor power using Pulse Width Modulation based on the joystick. The percentage forward or reverse on the joystick is the duty cycle for the PWM. The motor is attached to digital out pins 2 and 3 on the Arduino MEGA. When the joystick is in the forward position, pin 2 is set LOW and pin 3 is set as the PWM. When the joystick is in the reverse direction, pin 3 is set LOW and pin 2 is set as the PWM. The same thing occurs for the second motor attached to pins 4 and 5.

Left-Right-Testing.ino has my process for learning how to control the left/right motion of the RC car. The servo that controls the direction of the front wheels is at 90 degrees when straight ahead, 45 degrees when at it's full left, and 135 degrees when at it's full right.

Full-Joystick-Testing.ino has all my work from the previous programs together in one code to test the full function of the RC car's drive train.

The images included in this repository show my initial wiring of the Arduino to control the RC car. Joystick-Testing-Electronics.jpg shows the full image of the Arduino and surrounding electronics, while Joystick-Testing-Arduino.jpg shows a close up of just the Arduino wiring. The joystick on the bottom left is what controls the stepper motors and servo motor. The stepper motor on the bottom right drives the rear wheels. In this image, there is only one stepper motor because I do not have another. The servo motor on the top right controls the turning of the front wheels and the overall direction of the car.
