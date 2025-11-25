# Joystick-Testing

Joystick-Output-Testing.ino has my process of learning how the outputs of the Arduino joystick function and can be recorded.


Forward-Backward-Testing.ino has my process for learning how to control the motor power using Pulse Width Modulation based on the joystick. The percentage forward or reverse on the joystick is the duty cycle for the PWM. The motor is attached to digital out pins 2 and 3 on the Arduino MEGA. When the joystick is in the forward position, pin 2 is set LOW and pin 3 is set as the PWM. When the joystick is in the reverse direction, pin 3 is set LOW and pin 2 is set as the PWM. The same thing occurs for the second motor attached to pins 4 and 5.

Left-Right-Testing.ino has my process for learning how to control the left/right motion of the RC car. The servo that controls the direction of the front wheels is at 90 degrees when straight ahead, 45 degrees when at it's full left, and 135 degrees when at it's full right.
