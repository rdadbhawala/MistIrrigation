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

  pinMode(p2, OUTPUT);
  pinMode(p1, OUTPUT);

  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (time matches) 
  // // water the plants
  // endif

  if (isItTimeToWaterThePlants() == 1) {
    waterThePlants(p1);
    waterThePlants(p2);
  }
  delay(30000);
}

int isItTimeToWaterThePlants() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    printTime(tm);
    if (tm.Hour == 7 && tm.Minute == 30) {
      return 1;
    }

    // if ((tm.Second / 10) % 2 == 0) {
    //   digitalWrite(p1, LOW);
    //   delay(10000);
    //   digitalWrite(p1, HIGH);
    // } else {
    //   digitalWrite(p2, LOW);
    //   delay(10000);
    //   digitalWrite(p2, HIGH);
    // }

  } else {
    // beep 3 times for rtc error

    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
    }
    Serial.println();
    delay(9000);
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

void waterThePlants(int pumpPin) {
  digitalWrite(pumpPin, LOW);
  delay(60000);
  digitalWrite(pumpPin, HIGH);
}
