#include <DIYcolorsensor.h>

ColorSensor sensor(8, 7, 6, A4);     // Right color sensor
ColorSensor sensor2(4, 3, 2, A5);    // Right mid color sensor
ColorSensor sensor3(A0, 13, 12, A6); // Left mid color sensor
ColorSensor sensor4(A1, A2, A3, A7); // Left color sensor

#define IN1 5
#define IN2 9
#define IN3 10
#define IN4 11

int colorR;
int colorRM;
int colorLM;
int colorL;

float P;
int Kp = 90;
float error;
//margens de sensores para verde, 1.3, 1.3, 3, 1.8
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  calibrationd();
}

void loop() {
  /*sensor3.getColor();
  sensor3.printValues();
  Serial.println(isGreen(sensor3, 3));*/
  followLine();
}
