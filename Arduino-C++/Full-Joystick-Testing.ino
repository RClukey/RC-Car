#include <Servo.h>

Servo myServo;
int servoPos;
double pwm;
int x_input, y_input, switch_input;
bool cruise = false;

const int x_max = 540;
const int x_nominal = 480;
const int x_min = -480;

const int y_max = 500;
const int y_nominal = 520;
const int y_min = -520;

const int Motor1Pin1 = 2;   // Left Wheel
const int Motor1Pin2 = 3;
const int Motor2Pin1 = 4;   // Right Wheel
const int Motor2Pin2 = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(22, INPUT);
  digitalWrite(22, HIGH);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);

  myServo.attach(9);
  myServo.write(90);

  Serial.begin(9600);
}

void loop() {
  if (!cruise)
  {
    // put your main code here, to run repeatedly:
    switch_input = digitalRead(22);
    x_input = (analogRead(A0) - x_nominal) / 20;
    x_input *= 20;
    y_input = (analogRead(A1) - y_nominal) / 20;
    y_input *= 20;

    if (switch_input)
    {
      digitalWrite(13, LOW);
    }
    if (!switch_input)
    {
      digitalWrite(13, HIGH);
      cruise = true;
    }
  }
  else
  {
    switch_input = digitalRead(22);
    if (!switch_input)
    {
      digitalWrite(13, LOW);
      cruise = false;

      x_input = (analogRead(A0) - x_nominal) / 20;
      x_input *= 20;
      y_input = (analogRead(A1) - y_nominal) / 20;
      y_input *= 20;
    }
  }

  Serial.print("Cruise Control: ");
  Serial.print(cruise);
  Serial.print("\n");

  Serial.print("X-axis: ");
  Serial.print(x_input);
  Serial.print("\n");
    
  Serial.print("Y-axis: ");
  Serial.print(y_input);
  Serial.print("\n");

  if (y_input > 0)
  {
    pwm = 255*abs(y_input/double(y_max));
    int pwn_int = pwm;
    Serial.print("PWM: ");
    Serial.print(pwn_int);
    Serial.print("\n");

    digitalWrite(Motor1Pin1, LOW);
    analogWrite(Motor1Pin2, pwn_int);
    digitalWrite(Motor2Pin1, LOW);
    analogWrite(Motor2Pin2, pwn_int);
    Serial.print("Forward\n");
  }
  else if (y_input < 0)
  {
    pwm = 255*abs(y_input/double(y_min));
    int pwn_int = pwm;
    Serial.print("PWM: ");
    Serial.print(pwn_int);
    Serial.print("\n");

    analogWrite(Motor1Pin1, pwn_int);
    digitalWrite(Motor1Pin2, LOW);
    analogWrite(Motor2Pin1, pwn_int);
    digitalWrite(Motor2Pin2, LOW);
    Serial.print("Backward\n");
  }
  else
  {
    digitalWrite(Motor1Pin1, LOW);
    digitalWrite(Motor1Pin2, LOW);
    digitalWrite(Motor2Pin1, LOW);
    digitalWrite(Motor2Pin2, LOW);
    Serial.print("PWM: 0\n");
    Serial.print("Stop\n");
  }

  if (x_input < 0)
  {
    servoPos = int(90*abs(x_input/double(x_max)));

    myServo.write(90+servoPos);
      
    Serial.print("Angle: ");
    Serial.print(90+servoPos);
    Serial.print("\n");
    Serial.print("Right\n");
  }
  else if (x_input > 0)
  {
    servoPos = int(90*abs(x_input/double(x_min)));

    myServo.write(90-servoPos);
      
    Serial.print("Angle: ");
    Serial.print(90-servoPos);
    Serial.print("\n");
    Serial.print("Left\n");
  }
  else
  {
    myServo.write(90);
    Serial.print("Straight\n");
  }

  Serial.print("\n\n");
  delay(250);
}













