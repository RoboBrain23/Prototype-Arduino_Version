#include <SoftwareSerial.h>

#define R_DIR   5
#define L_DIR   8
#define R_speed 6
#define L_speed 9

#define RX 10
#define TX 11

int trig_f=14;
int echo_f=15;

int trig_r=16;
int echo_r=17;

int trig_l=23;
int echo_l=24;

long duration;
float distance;
int flag;

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
  pinMode(trig_f,OUTPUT);
  pinMode(echo_f,INPUT);
  pinMode(trig_r,OUTPUT);
  pinMode(echo_r,INPUT);
  pinMode(trig_l,OUTPUT);
  pinMode(echo_l,INPUT);
  
  Blue.begin(9600);
  Serial.begin(9600);
  Serial.println("Starting");
}
char input;
void loop() {

   if(flag==0)
 {
  forward_distance();
 }
 else if(flag==1)
 {
  right_distance();
 }
 else if(flag==2)
 {
  left_distance();
 }
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

void forward_distance()
{
  digitalWrite(trig_f, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_f, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_f, LOW);
  duration = pulseIn(echo_f, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("forward_Distance: ");
  Serial.println(distance);
  if(distance<20)                     
  {
    Stop();
   }
  delayMicroseconds(1);
}
void right_distance()
{
  digitalWrite(trig_r, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_r, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_r, LOW);
  duration = pulseIn(echo_f, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("right_Distance: ");
  Serial.println(distance);
  
  if(distance<20)                     
  {
    Stop();
   }
  delayMicroseconds(1);
}
void left_distance()
{
  digitalWrite(trig_l, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_l, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_l, LOW);
  duration = pulseIn(echo_f, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("left_Distance: ");
  Serial.println(distance); 

  if(distance<20)                     
  {
    Stop();
   }
  delayMicroseconds(1);
}
void GO_forward()
{
  analogWrite(R_speed, Speed);
  analogWrite(L_speed, Speed);
  digitalWrite(R_DIR, forward);
  digitalWrite(L_DIR, forward);
  flag =0;
}
void GO_backward()
{
  analogWrite(R_speed, Speed);
  analogWrite(L_speed, Speed);
  digitalWrite(R_DIR, backward);
  digitalWrite(L_DIR, backward);
}

void turn_right()
{
  analogWrite(R_speed, Speed);
  analogWrite(L_speed, Speed);
  digitalWrite(R_DIR, backward);
  digitalWrite(L_DIR, forward);
  flag =1;
}

void turn_left()
{
  analogWrite(R_speed, Speed);
  analogWrite(L_speed, Speed);
  digitalWrite(R_DIR, forward);
  digitalWrite(L_DIR, backward);
  flag =2;
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
