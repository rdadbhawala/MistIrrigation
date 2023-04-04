int relay_1 = 4;
int relay_2 = 7;
int relay_3 = 8;
int relay_4 = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

void setPin(int pinNo) {
  Serial.print("Setting Pin # ");
  Serial.print(pinNo);
  Serial.print(" high ");
  digitalWrite(pinNo, HIGH);
  Serial.print(" delay ");
  delay(3000);
  Serial.print(" low ");
  digitalWrite(pinNo, LOW);
  Serial.println(" done");
}

void loop() {

  for (int ctr = 1; ctr <= 13; ctr++) {
    setPin(ctr);
  }

  // digitalWrite(relay_1, HIGH);
  // digitalWrite(relay_2, HIGH);
  // digitalWrite(relay_3, HIGH);
  // digitalWrite(relay_4, HIGH);

  // Serial.println("All relays ON");

  // delay(1000);

  // digitalWrite(relay_1, LOW);
  // digitalWrite(relay_2, LOW);
  // digitalWrite(relay_3, LOW);
  // digitalWrite(relay_4, LOW);

  // Serial.println("All relays OFF");

  // delay(1000);
}