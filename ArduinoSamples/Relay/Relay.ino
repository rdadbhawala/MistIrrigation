int p1 = 13;
int p2 = 12;
int p3 = 8;
int p4 = 7;

void setup() {
  // put your setup code here, to run once:
  // digitalWrite(p1, HIGH);
  // digitalWrite(10, HIGH);
  // digitalWrite(11, HIGH);
  // digitalWrite(p2, HIGH);

  // pinMode(10, OUTPUT);
  // pinMode(11, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p1, OUTPUT);

  // digitalWrite(10, LOW);
  // digitalWrite(11, LOW);
  // digitalWrite(p2, HIGH);
  // digitalWrite(p1, HIGH);

}

void loop() {
  // digitalWrite(10, HIGH);
  // delay(1000);
  // digitalWrite(10, LOW);
  // delay(100);
  // digitalWrite(11, HIGH);
  // delay(1000);
  // digitalWrite(11, LOW);
  // delay(100);
  digitalWrite(p2, LOW);
  delay(2000);
  digitalWrite(p2, HIGH);
  delay(500);
  digitalWrite(p1, LOW);
  delay(2000);
  digitalWrite(p1, HIGH);
  delay(500);
}
