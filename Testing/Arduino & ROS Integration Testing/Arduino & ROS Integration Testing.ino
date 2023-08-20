#include <ros.h>
#include <geometry_msgs/Point32.h> //For sending encoder msg
#include <geometry_msgs/Twist.h> //For cmd_vel subscription
#include <Encoder.h> //Encoder library

//---- Define motor pins
#define L_PWM 6 //Left Motor PWM pin
#define L_DIR 8 //Left Motor Direction pin
#define R_PWM 9 //Right Motor PWM pin
#define R_DIR 5 //Right Motor Direction pin

//-------------Encoder definitions
Encoder R_enc(19, 18); //right motor encoder goes for pins 19 18
Encoder L_enc(21, 20); //left motor encoder goes for pins 21 20
long RoldPosition  = -999;
long LoldPosition  = -999;

//-------------Robot parameters definition------------
#define L 0.33
#define R 0.05

//--------------------------------Motors VARS-----------------------------------
// initializing variables
float vel=0.0; //as Twist msgs depend on Vector3 which is float64
float omega=0.0;
float VR,VL;

//-----------------------ROS Setup-----------------------
ros::NodeHandle  nh;
//------------------------------Publish init----------------------------------------------
geometry_msgs::Point32 Point_msg;
ros::Publisher enc_pub("/encoder", &Point_msg); 
//------------------------------Subscribe init--------------------------------------------
void motors_cb(const geometry_msgs::Twist& msg)
{
  vel = msg.linear.x  ;
  omega = msg.angular.z;
  
  VR = (2*vel + omega*L) / (2*R); 
  VL = (2*vel - omega*L) / (2*R); 

  Serial.print("speed: ");
  Serial.print(vel);
  
  Serial.print("  Left: ");
  Serial.print(VL);

  Serial.print("  Right: ");
  Serial.print(VR);
  
  //-----right motor------
  if (VR < 0) {
    digitalWrite(R_DIR, HIGH);
    analogWrite(R_PWM, abs(VR));   
  } else {
    digitalWrite(R_DIR, LOW);
    analogWrite(R_PWM, VR);   
  }

  //-----left motor------
  if (VL < 0) {
    digitalWrite(L_DIR, HIGH);
    analogWrite(L_PWM, abs(VL));   
  } else {
    digitalWrite(L_DIR, LOW);
    analogWrite(L_PWM, VL);   
  }
}
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &motors_cb);

void setup() 
{
  Serial.begin(57600);    

  //--------------Motor setup--------------
  pinMode(L_PWM, OUTPUT);
  pinMode(L_DIR, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(R_DIR, OUTPUT);

  digitalWrite(L_DIR, LOW);
  digitalWrite(R_DIR, LOW);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM, 0);
  //---------------------------------------

  //---------------------------ROS Setup
  nh.advertise(enc_pub);  
  nh.subscribe(sub);      
}

void loop() 
{ 
  //Right Encoder
  long RnewPosition = R_enc.read();
  if (RnewPosition != RoldPosition) {
    RoldPosition = RnewPosition; 
    Serial.println(RnewPosition);
  } 

  //----left encoder
  long LnewPosition = L_enc.read();
  if (LnewPosition != LoldPosition) {
    LoldPosition = LnewPosition; //update positions
    Serial.println(LnewPosition);
  }  
  //-------end of encoder

  //-----------------------ROS publishing  
  Point_msg.x = RnewPosition;
  Point_msg.y = LnewPosition;
  enc_pub.publish(&Point_msg);
  //-------------        
  nh.spinOnce(); 
  delay(10);
}  


