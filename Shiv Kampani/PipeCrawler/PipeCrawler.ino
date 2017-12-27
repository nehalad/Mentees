#define M1Speed 5
#define M2Speed 4
#define M1Direction 0 
#define M2Direction 2

void setup() {
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(1000);
  backward();
  delay(1000);
  stopmotors();
}

void forward() {
  analogWrite(5, 1023);
  analogWrite(4, 1023);
  digitalWrite(0, HIGH);
  digitalWrite(2, HIGH);
}

void backward() {
  analogWrite(5, 1023);
  analogWrite(4, 1023);
  digitalWrite(0, LOW);
  digitalWrite(2, LOW);
}

void stopmotors() {
  analogWrite(5, 0);
  analogWrite(4, 0);
}


