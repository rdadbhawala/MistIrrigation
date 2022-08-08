#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

int p1 = 13;
int p2 = 12;

void setup() {
  // put your setup code here, to run once:
  // if !file.exists(rtcwrite)
  // // rtc.write, set file
  // end if
  // delay 10 secs

  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);

  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);

  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);

  delay(3000);
  waterThePlants(p1, 5000);
  waterThePlants(p2, 5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (time matches) 
  // // water the plants
  // endif

  if (isItTimeToWaterThePlants() == 1) {
    long p1Millis = 45000;
    long p2Millis = 45000;

    waterThePlants(p1, p1Millis);
    waterThePlants(p2, p2Millis);
  } else {
    digitalWrite(p1, HIGH);
    digitalWrite(p2, HIGH);
  }
  delay(5000);
}

int isItTimeToWaterThePlants() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    printTime(tm);
    // if (tm.Minute % 2 == 0) {
    if (tm.Hour == 8 && tm.Minute == 30) {
      return 1;
    }
  } else {

    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
    }
    Serial.println();
  }

  return 0;
}

void  printTime(tmElements_t tm) {
  Serial.print(tmYearToCalendar(tm.Year));
  Serial.write('/');
  Serial.print(tm.Month);
  Serial.write('/');
  Serial.print(tm.Day);
  Serial.print(" ");
  print2digits(tm.Hour);
  Serial.write(':');
  print2digits(tm.Minute);
  Serial.write(':');
  print2digits(tm.Second);
  Serial.println();
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

void waterThePlants(int pumpPin, long timeInMillis) {
  Serial.print(pumpPin);
  Serial.print(" ");
  Serial.print(timeInMillis);
  Serial.print(" ON ");
  digitalWrite(pumpPin, LOW);
  while (timeInMillis > 0) {
    int sleepTime = min(timeInMillis, 10000);
    Serial.print(sleepTime);
    Serial.print(" ");
    delay(sleepTime);
    timeInMillis -= sleepTime;
  }
  digitalWrite(pumpPin, HIGH);
  Serial.println("OFF");
}
