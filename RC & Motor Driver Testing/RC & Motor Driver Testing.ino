#include <SoftwareSerial.h>

#define R_DIR   5
#define L_DIR   8
#define R_speed 6
#define L_speed 9

#define RX 10
#define TX 11

/*****************/
//#define directSpeed 255
//#define tuenSpeed   100

#define forward  1
#define backward 0
/******************/

SoftwareSerial Blue(RX,TX);

int Speed =255;
void setup() {
  // put your setup code here, to run once:
  pinMode(R_DIR,  OUTPUT);
  pinMode(L_DIR,  OUTPUT);
  pinMode(R_speed, OUTPUT);
  pinMode(R_speed, OUTPUT);
  Blue.begin(9600);
  Serial.begin(9600);
  Serial.println("Starting");
}
char input;
void loop() {
  if(Blue.available()){
   input = Blue.read();
  }

    Serial.println(input);
    switch (input)
    {
      case 'F':
        GO_forward();
        break;

      case 'B':
        GO_backward();
        break;

      case 'R':
        turn_right();
        break;

      case 'L':
        turn_left();
        break;

      case 'S':
        Stop();
        break;

      default:
        if(input >= '1' and input <= '8')
            Speed = 31 * (input - '0');
        /*
          case '1':
          speed=31;
          break;

          case '2':
          speed=62;
          break;

          case '3':
          speed=93;
          break;

          case '4':
          speed=124;
          break;

          case '5':
          speed=151;
          break;

          case '6':
          speed=186;
          break;

          case '7':
          speed=217;
          break;

          case '8':
          speed=248;
          break;
        */
    
  }

}

void GO_forward()
{
  digitalWrite(R_speed, Speed);
  digitalWrite(L_speed, Speed);
  digitalWrite(R_DIR, forward);
  digitalWrite(L_DIR, forward);
}
void GO_backward()
{
  digitalWrite(R_speed, Speed);
  digitalWrite(L_speed, Speed);
  digitalWrite(R_DIR, backward);
  digitalWrite(L_DIR, backward);
}

void turn_right()
{
  digitalWrite(R_speed, Speed);
  digitalWrite(L_speed, Speed);
  digitalWrite(R_DIR, backward);
  digitalWrite(L_DIR, forward);
}

void turn_left()
{
  digitalWrite(R_speed, Speed);
  digitalWrite(L_speed, Speed);
  digitalWrite(R_DIR, forward);
  digitalWrite(L_DIR, backward);
}

void Stop()
{
  digitalWrite(R_speed, 0);
  digitalWrite(L_speed, 0);
}
void set_speed(int in)
{
  Speed = 31 * in;
}
