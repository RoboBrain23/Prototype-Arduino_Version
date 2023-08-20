
void init_Current_Mode_Selector()
{
  pinMode(Mode_PIN, INPUT);
}

void read_Current_Mode()
{
  int mode_reading = analogRead(Mode_PIN);
  
  if (mode_reading < ROS_THRESHOLD)
    Current_Mode = ROS_Mode;

  else if (mode_reading < BCI_THRESHOLD)
    Current_Mode = BCI_Mode;

  else if (mode_reading < EYEGAZE_THRESHOLD)
    Current_Mode = EYE_GAZE_Mode;

  else if (mode_reading <= JOYSTCK_THRESHOLD)
    Current_Mode = JOYSTICK_Mode;
}
