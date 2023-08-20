
/****** Wheelchair Identifier ******/
#define WHEELCHAIR_ID           1
/***********************************/

/********* Controller Configuration **********/
#define FORWARD_ACCELERATION          50
#define TURN_ACCELERATION             90
#define NORMAL_FORWARD_ACCELERATION   50
#define NORMAL_TURN_ACCELERATION      80
#define STOP_ACCELERATION             1000
#define DEAD_BAND                     30
/*********************************************/


/**** Current_Mode Selector Configuration ****/
#define ROS_THRESHOLD             255  
#define BCI_THRESHOLD             511
#define EYEGAZE_THRESHOLD         767
#define JOYSTCK_THRESHOLD         1023
/*********************************************/


/** Healthcare System Configuration **/
#define LM35_MAX_TEMPERATURE       150     
#define SENSOR_MAX_VOLT_VALUE      5       
#define Temp_Reading_Interval      100
#define Oximeter_Reading_Interval  200
#define MINIMUM_BODY_TEMPERATURE   0
#define MAXIMUM_BODY_TEMPERATURE   42
#define MINIMUM_HUMAN_HEARTRATE    40
#define MAXIMUM_HUMAN_HEARTRATE    200
#define MINIMUM_HUMAN_SPO2         80
#define MAXIMUM_HUMAN_SPO2         100
#define INVALID_DATA               0
#define REPORTING_PERIOD_MS        1000
/*************************************/


/****** Obstacle Avoidance Configuration *******/
#define OBSTACLE_THRESHOLD      20 // (in cm)
#define BUZZER_MINIMUM_TONE     0
#define BUZZER_MAXIMUM_TONE     255
/***********************************************/


/***** Serial Configuration *****/
#define SERIAL_BAUDRATE  9600
#define RPI_BAUDRATE     9600
#define UNO_BAUDRATE     9600
/********************************/
