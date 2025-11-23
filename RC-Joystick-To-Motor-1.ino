
const int x_max = 530;
const int x_nominal = 489;
const int x_min = -480;

const int y_max = 490;
const int y_nominal = 526;
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

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int switch_input = digitalRead(22);
  int x_input = (analogRead(A0) - x_nominal) / 10;
  x_input *= 10;
  int y_input = (analogRead(A1) - y_nominal) / 10;
  y_input *= 10;

  Serial.print("Switch: ");
  Serial.print(switch_input);
  Serial.print("\n");

  Serial.print("X-axis: ");
  Serial.print(x_input);
  Serial.print("\n");
  
  Serial.print("Y-axis: ");
  Serial.print(y_input);
  Serial.print("\n");

  if (switch_input) { digitalWrite(13, LOW); }
  if (!switch_input) { digitalWrite(13, HIGH); }

  double pwm = 0.00;

  if (y_input > 0)
  {
    pwm = 255*abs(y_input/double(y_max));

    digitalWrite(Motor1Pin1, LOW);
    analogWrite(Motor1Pin2, int(pwm));
    digitalWrite(Motor2Pin1, LOW);
    analogWrite(Motor2Pin2, int(pwm));
    Serial.print("Forward\n");
  }
  else if (y_input < 0)
  {
    pwm = 255*abs(y_input/double(y_min));
    int pwn_int = pwm;

    analogWrite(Motor1Pin1, int(pwm));
    digitalWrite(Motor1Pin2, LOW);
    analogWrite(Motor2Pin1, int(pwm));
    digitalWrite(Motor2Pin2, LOW);
    Serial.print("Backward\n");
  }
  else
  {
    digitalWrite(Motor1Pin1, LOW);
    digitalWrite(Motor1Pin2, LOW);
    digitalWrite(Motor2Pin1, LOW);
    digitalWrite(Motor2Pin2, LOW);
    Serial.print("Stop\n");
  }

  Serial.print("PWM: ");
  Serial.print(int(pwm));
  Serial.print("\n");

  Serial.print("\n\n");
  delay(250);
}













