int TrigPin = 5;
int EchoPin = 4;
int Ledpin = 6;
long rast, cm;
int i;
int incomingByte = 0;
void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(Ledpin, OUTPUT);
}
void loop() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  rast = pulseIn(EchoPin, HIGH);
  cm = (rast * 340) / 20000;
  if (cm > 46) {
    cm = 46;
  }
  Serial.println(cm);
  if (Serial.available() > 0) {
    incomingByte = Serial.read() - '0';
  }
  if ((cm >= 3) and (incomingByte == 1)) {
    i = (255 / (80 - 3)) * (cm - 3);
  } else {
    i = 0;
  }
  analogWrite(Ledpin, i);
  delay(10);
}