#include <Servo.h>
Servo xc;
Servo yc;

int x;
int y;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(7, OUTPUT);
  digitalWrite(7, 1);

  xc.attach(4);  // x подключаем на пин 3
  yc.attach(3);  // y подключаем на пин 4

  xc.write(90);
  yc.write(90);

  x = 90;
  y = 90;
}

void loop() {
  if (60 <= x && x <= 120 && 60 <= y && y <= 120){
    switch (random(8)) {
      case 0:
        y += 2;
        break;
      case 1:
        x += 2;
        y += 2;
        break;
      case 2:
        x += 2;
        break;
      case 3:
        x += 2;
        y -= 2;
        break;
      case 4:
        y -= 2;
        break;
      case 5:
        x -= 2;
        y -= 2;
        break;
      case 6:
        x -= 2;
        break;
      case 7:
        x -= 2;
        y += 2;
        break;
    }
  } else {
    x = 90;
    y = 90;
  }
  Serial.print(x);
  Serial.print("\t");
  Serial.println(y);
  xc.write(x);
  yc.write(y);
  delay(100);
}