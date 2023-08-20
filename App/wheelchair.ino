
#include "Wheelchair.h"
#include "MAX30100_PulseOximeter.h"
/* Global Variables */
int Current_Mode, HeartRate, SPO2, Current_Move, Obstacle_Distance, Temperature;

void setup()
{
  //  pinMode(3,OUTPUT);
  //  pinMode(4,OUTPUT);
  //  digitalWrite(4,LOW);
  //  digitalWrite(3,LOW);
  init_Controller();
  init_Serial();
  init_Current_Mode_Selector();
  init_Obstacle_Avoidance();
  //init_Healthcare_System();
}

void loop()
{
 // delay(10);
//  read_Current_Mode();
  Current_Mode =EYE_GAZE_Mode;
  //  Serial.print("Current mode: ");
  //  switch (Current_Mode)
  //  {
  //    case 1:
  //      Serial.print("BCI_Mode");
  //      break;
  //
  //    case 2:
  //      Serial.print("EYE_GAZE_Mode");
  //      break;
  //
  //    case 3:
  //      Serial.print("ROS_Mode");
  //      break;
  //
  //    case 4:
  //      Serial.print("JOYSTICK_Mode ");
  //      break;
  //  }
 // Serial.print(Current_Mode);
 // send_Data_To_Raspberry();
  //send_Data_To_Uno();
  read_Current_move();
  ///Serial.print("    Current move: ");
  ///Serial.print(Current_Move);
  // check_Obstacle();
  ///Serial.print("    obstaclde distance: ");
  ///Serial.println(Obstacle_Distance);
  //check_Obstacle_Alert();
//  get_Forward_Distance();
//  get_Right_Distance();
  // get_Left_Distance();
//Serial.print("test");
 //get_Left_Distance_Asenq();
//Serial.print("test");
  controller();
  //read_Temperature_Sensor();
  delay(10);
    //read_Oximeter();
  //delay(10);
}
