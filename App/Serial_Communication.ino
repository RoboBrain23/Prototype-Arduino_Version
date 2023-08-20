
#include <SoftwareSerial.h>


/* UART Communication Definition */
SoftwareSerial UNOSerial(10,11);
SoftwareSerial RpiSerial(14,15);

void init_Serial()
{
  Serial.begin(9600);
 // Serial3.begin(SERIAL_BAUDRATE);    // Initialize Mega's serial port to communicate with R-pi.
 // UNOSerial.begin(UNO_BAUDRATE);
 // RpiSerial.begin(RPI_BAUDRATE);
}

void send_Data_To_Raspberry()
{
  String Message = create_Formatted_Msg();
 // RpiSerial.write(Message.c_str());
  Serial.write(Message.c_str());
  //Serial.print(" Msg: ");
  //Serial.print(Message);
}


void send_Data_To_Uno()
{
  UNOSerial.write(Current_Mode);
}

String create_Formatted_Msg()
{
  String ID_String = String(WHEELCHAIR_ID);
  String Current_Mode_String = String(Current_Mode);
  String Temperature_String = String(Temperature);
  String HeartRate_String = String(HeartRate);
  String SPO2_String = String(SPO2);

  // Format Message: #ID#Current_Mode#Temperature#Heartrate#SPO2#
  String FormattedMessage = '#' + ID_String + '#' + Current_Mode_String + '#' + Temperature_String + '#' + HeartRate_String + '#' + SPO2_String + '#'+'\n' ;

  return FormattedMessage;
}

void receive_Data_From_Raspberry()
{
  char input;
  if (Serial.available())
  {
    input = Serial.read();
    switch (input)
    {
      case'F':
        Current_Move = FORWARD;
       // digitalWrite(3,HIGH);
        break;

      case'R':
        Current_Move = RIGHT;
        break;

      case'L':
        Current_Move = LEFT;
        break;

      case'S':
        Current_Move = STOP;
      //  digitalWrite(3,LOW);
        break;

      case'N':
      default:
        Current_Move = STOP; //non
        break;
    }
     // Serial.print("  ");
      //Serial.print(input);
      //Serial.print("  ");
  }
  else
  {
  //Serial.print(" ... ");
  //Current_Move = NON;
 // Current_Move = STOP;
  }
}
