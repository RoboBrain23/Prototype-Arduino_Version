
static int Joystick_F_B_Value, Joystick_R_L_Value, Joystick_Refrence_Value, Motors_F_B_Value, Motors_R_L_Value;

void init_Controller()
{
  /* Set Motors pins Current_Mode */
  pinMode(MOTORS_REFRENCE_PIN, OUTPUT);
  pinMode(MOTORS_F_B_PIN,      OUTPUT);
  pinMode(MOTORS_R_L_PIN,      OUTPUT);

  /* Set neutral motors voltage */
  analogWrite(MOTORS_REFRENCE_PIN, 128);
  analogWrite(MOTORS_F_B_PIN,      128);
  analogWrite(MOTORS_R_L_PIN,      128);


  /* Set joystick pins Current_Mode */
  pinMode(JOYSTICK_REFRENCE_PIN, INPUT);
  pinMode(JOYSTICK_F_B_PIN,      INPUT);
  pinMode(JOYSTICK_R_L_PIN,      INPUT);
}

void set_Current_Move()
{
  if (Joystick_F_B_Value < (512 - DEAD_BAND) && Joystick_R_L_Value > (512 + DEAD_BAND))
    Current_Move = FORWARD_RIGHT;

  else if (Joystick_F_B_Value > (512 + DEAD_BAND) && Joystick_R_L_Value < (512 - DEAD_BAND))
    Current_Move = FORWARD_LEFT;

  else if (Joystick_F_B_Value < (512 - DEAD_BAND))
    Current_Move = FORWARD;

  else if (Joystick_F_B_Value > (512 + DEAD_BAND))
    Current_Move = BACKWARD;

  else if (Joystick_R_L_Value > (512 + DEAD_BAND))
    Current_Move = RIGHT;

  else if (Joystick_R_L_Value < (512 - DEAD_BAND))
    Current_Move = LEFT;

  else
    Current_Move = STOP;
}

void read_Joystick()
{
  Joystick_Refrence_Value = analogRead(JOYSTICK_REFRENCE_PIN);  // Todo: implement reference value validation function that turn on buzzer in case it is invalid.
  Joystick_F_B_Value      = analogRead(JOYSTICK_F_B_PIN);
  Joystick_R_L_Value      = analogRead(JOYSTICK_R_L_PIN);

  set_Current_Move();
}

void control_Motors_By_Joystick()
{
  analogWrite(MOTORS_F_B_PIN, map(Joystick_F_B_Value, 0, 1023, 0, 255));
  analogWrite(MOTORS_R_L_PIN, map(Joystick_R_L_Value, 0, 1023, 0, 255));
}

void control_Motors_Analog()
{
  switch (Current_Move)
  {
    case FORWARD:
      Motors_F_B_Value += FORWARD_ACCELERATION;
      if (Motors_F_B_Value > 1023)
        Motors_F_B_Value = 1023;

      if (Motors_R_L_Value > 512)                   // Try to set R_L value to 512 instead of gradual decreasing/increasing it.
      {
        Motors_R_L_Value -= NORMAL_TURN_ACCELERATION;
        if (Motors_R_L_Value < 512)
          Motors_R_L_Value = 512;
      }

      else  if (Motors_R_L_Value < 512)
      {
        Motors_R_L_Value += NORMAL_TURN_ACCELERATION;
        if (Motors_R_L_Value > 512)
          Motors_R_L_Value = 512;
      }
      break;

    case RIGHT:
      Motors_R_L_Value += TURN_ACCELERATION;
      if (Motors_R_L_Value > 1023)
        Motors_R_L_Value = 1023;
      break;

    case LEFT:
      Motors_R_L_Value -= TURN_ACCELERATION;
      if (Motors_R_L_Value < 0)
        Motors_R_L_Value = 0;
      break;

    case STOP:
      if (Motors_F_B_Value > 512)
      {
        Motors_F_B_Value -= STOP_ACCELERATION;
        if (Motors_F_B_Value < 512)
          Motors_F_B_Value = 512;
      }

      else if (Motors_F_B_Value < 512)
      {
        Motors_F_B_Value += STOP_ACCELERATION;
        if (Motors_F_B_Value > 512)
          Motors_F_B_Value = 512;
      }

      if (Motors_R_L_Value > 512)
      {
        Motors_R_L_Value -= STOP_ACCELERATION;
        if (Motors_R_L_Value < 512)
          Motors_R_L_Value = 512;
      }

      else if (Motors_R_L_Value < 512)
      {
        Motors_R_L_Value += STOP_ACCELERATION;
        if (Motors_R_L_Value > 512)
          Motors_R_L_Value = 512;
      }
      break;

    case NON:
    default:
      if (Motors_F_B_Value > 512)
      {
        Motors_F_B_Value -= NORMAL_FORWARD_ACCELERATION;
        if (Motors_F_B_Value < 512)
          Motors_F_B_Value = 512;
      }

      else if (Motors_F_B_Value < 512)
      {
        Motors_F_B_Value += NORMAL_FORWARD_ACCELERATION;
        if (Motors_F_B_Value > 512)
          Motors_F_B_Value = 512;
      }

      if (Motors_R_L_Value > 512)
      {
        Motors_R_L_Value -= NORMAL_TURN_ACCELERATION;
        if (Motors_R_L_Value < 512)
          Motors_R_L_Value = 512;
      }

      else  if (Motors_R_L_Value < 512)
      {
        Motors_R_L_Value += NORMAL_TURN_ACCELERATION;
        if (Motors_R_L_Value > 512)
          Motors_R_L_Value = 512;
      }
      break;

  }

  analogWrite(MOTORS_F_B_PIN, map(Motors_F_B_Value, 0, 1023, 200, 56));
  analogWrite(MOTORS_R_L_PIN, map(Motors_R_L_Value, 0, 1023, 200, 56));

}


void controller()
{
  switch (Current_Mode)
  {
    case BCI_Mode:
    case EYE_GAZE_Mode:
      control_Motors_Second_Approach();
     // control_Motors_Analog();
      break;

    case JOYSTICK_Mode:

      control_Motors_By_Joystick();
      break;
  }
}


void read_Current_move()
{
  switch (Current_Mode)
  {
    case ROS_Mode:
      break;

    case BCI_Mode:
    case EYE_GAZE_Mode:
      receive_Data_From_Raspberry();
      break;

    case JOYSTICK_Mode:
      read_Joystick();
      break;
  }
}

void control_Motors_Second_Approach()
{
  switch (Current_Move)
  {
    case FORWARD:
      Motors_F_B_Value = 1023;
      Motors_R_L_Value = 512;
      break;

    case RIGHT:
      Motors_F_B_Value = 512;
      Motors_R_L_Value = 0;
      break;

    case LEFT:
      Motors_F_B_Value = 512;
      Motors_R_L_Value = 1023;
      break;

    case STOP:
      Motors_F_B_Value = 512;
      Motors_R_L_Value = 512;
      break;

  }
  analogWrite(MOTORS_REFRENCE_PIN, 128);
  analogWrite(MOTORS_F_B_PIN, map(Motors_F_B_Value, 0, 1023, 200, 56));
  analogWrite(MOTORS_R_L_PIN, map(Motors_R_L_Value, 0, 1023, 56, 200));
}
