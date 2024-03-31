
#include <SoftwareSerial.h>
SoftwareSerial MyBlue(0, 1); // RX | TX
int flag = 0;

int stepG = 5;
int dirG = 8;
int stepD = 6;
int dirD = 7;
int Tvit;


int buzz = 11;

int echo = 10;
int trig = 9;

float duration, distance, dist;
int period = 10000;
unsigned long time_now = 0;


void setup()
{
  Serial.begin(9600);
  MyBlue.begin(9600);
  pinMode(dirD, OUTPUT);
  pinMode(dirG, OUTPUT);
  pinMode(stepD, OUTPUT);
  pinMode(stepG, OUTPUT);

  Tvit = 500;
  while (!Serial.available());
  dist = Serial.parseFloat();
  Serial.println("init dist");
  Serial.print(dist);

}


void loop()
{

  if (MyBlue.available())
    flag = MyBlue.read();
  switch (flag) {
    case 'w':
      moveForward();
      while (flag == 'w') {
        time_now = millis();
        digitalWrite(trig, HIGH);
        while (millis() < time_now + period) {
          digitalWrite(trig, LOW);

          duration = pulseIn(echo, HIGH);
          distance = (duration / 2) / 29.1;
          if (distance <= dist) {
            Serial.print("7bees awa hbes");
          }
        }
        motorrun();
      }
      break;
    case 's':
      moveBackward();
      while (flag == 's') {
        motorrun();
      }
      break;
    case 'a':
      moveLeft();
      while (flag == 'a') {
        motorrun();
      }
      break;
    case 'd':
      moveRight();
      while (flag == 'd') {
        motorrun();
      }
      break;
    case 'b':
      (Tvit >= 3200) ? Tvit = 3200 : Tvit += 1;
      Serial.print(Tvit);
      Serial.print("\n");
      break;
    case 'x':
      (Tvit <= 300) ? Tvit = 300 : Tvit -= 1;
      Serial.print(Tvit);
      Serial.print("\n");
      break;

  }
}




float obstacl() {
  time_now = millis();
  digitalWrite(trig, HIGH);
  while (millis() < time_now + period) {
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 29.1;
    return distance;
  }
  return dist + 10;
}



void moveForward() {

  digitalWrite(dirD, HIGH);
  digitalWrite(dirG, HIGH);
}
void moveBackward() {
  digitalWrite(dirD, LOW);
  digitalWrite(dirG, LOW);

}
void moveRight() {
  digitalWrite(dirD, HIGH);
  digitalWrite(dirG, LOW);

}
void moveLeft() {
  digitalWrite(dirD, LOW);
  digitalWrite(dirG, HIGH);

}
void motorrun() {
  digitalWrite(stepD, HIGH);
  digitalWrite(stepG, HIGH);
  delayMicroseconds(100);
  digitalWrite(stepD, LOW);
  digitalWrite(stepG, LOW);
  delayMicroseconds(Tvit);
  if (MyBlue.available())
    flag = MyBlue.read();
}
