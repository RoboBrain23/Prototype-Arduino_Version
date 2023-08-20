
#ifndef WHEELCHAIR_H_
#define WHEELCHAIR_H_

/*************************** Pins Definition **************************/

/* Joystick Pins */
#define JOYSTICK_REFRENCE_PIN   A0   // Could be neglected as it is fixed value  
#define JOYSTICK_F_B_PIN        A1
#define JOYSTICK_R_L_PIN        A2

/* Wheelchair Motors Pins */
#define MOTORS_REFRENCE_PIN     9   // Could be neglected as it is fixed value  
#define MOTORS_F_B_PIN          10  //10 for uno
#define MOTORS_R_L_PIN          11  //11 for uno

/* Healthcare System Pins */
#define TEMPERATURE_PIN         A3
#define OXIMETER_I2C_SDA        20 // for mega  //A4 for nano
#define OXIMETER_I2C_SCL        21 // for mega  //A5 for nano

/* Obstacle Avoidance Pins */
#define TRIG_L                  6
#define ECHO_L                  18
#define TRIG_R                  7
#define ECHO_R                  19
#define TRIG_F                  8
#define ECHO_F                  2
#define BUZZER_PIN              3

/* Mode Selector Pins */
#define Mode_PIN                A4

/*bluetooth module*/
/* 4 >> rx
   5 >> tx
*/

/************************ Variables Definition ************************/

/**** Current_Mode definition *****/
#define BCI_Mode        1
#define EYE_GAZE_Mode   2
#define ROS_Mode        3
#define JOYSTICK_Mode   4
/**********************************/

/**** Movement definition *****/
#define STOP             0
#define FORWARD          1
#define BACKWARD  		   2
#define RIGHT            3
#define LEFT             4
#define FORWARD_RIGHT    5
#define FORWARD_LEFT     6
#define NON              7
/******************************/

#endif // WHEELCHAIR_H_
