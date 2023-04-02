#include <SoftwareSerial.h>
#include <DFRobot_SIM808.h>

#define PIN_TX 3
#define PIN_RX 2

SoftwareSerial mySerial(PIN_TX, PIN_RX);

DFRobot_SIM808 sim808(&mySerial);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  while(!sim808.init())
  {
    Serial.println("Sim808: init error");
    delay(1000);
  }

  delay(3000);

  Serial.println("SIM808: funcionando Correctamente");
}

void loop() {
  while(!sim808.getGPS())
  {
    Serial.println("gps of sim808 is not ready");
  }

  Serial.print(sim808.GPSdata.year);
  Serial.print("/");
  Serial.print(sim808.GPSdata.month);
  Serial.print("/");
  Serial.print(sim808.GPSdata.day);
  Serial.print(" ");
  Serial.print(sim808.GPSdata.hour);
  Serial.print(":");
  Serial.print(sim808.GPSdata.minute);
  Serial.print(":");
  Serial.print(sim808.GPSdata.second);
  Serial.print(":");
  Serial.println(sim808.GPSdata.centisecond);
  Serial.print("latitude: ");
  Serial.println(sim808.GPSdata.lat);
  Serial.print("longitude: ");
  Serial.println(sim808.GPSdata.lon);
  Serial.print("speed_kph: ");
  Serial.println(sim808.GPSdata.speed_kph);
  Serial.print("heading: ");
  Serial.println(sim808.GPSdata.heading);
  Serial.println();
}
