# RC-Car

RC-Joystick-To-Motor-1.ino has my process for learning how to control the motor power using Pulse Width Modulation based on the joystick. The percentage forward or reverse on the joystick is the duty cycle for the PWM. The motor is attached to digital out pins 2 and 3 on the Arduino MEGA. When the joystick is in the forward position, pin 2 is set LOW and pin 3 is set as the PWM. When the joystick is in the reverse direction, pin 3 is set LOW and pin 2 is set as the PWM.
