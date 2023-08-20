
static float Right_Ultrasonic_Value, Left_Ultrasonic_Value, Forward_Ultrasonic_Value;

volatile unsigned long Left_pulse_StartTime = 0;
volatile unsigned long Left_pulse_EndTime = 0;
volatile bool Left_pulse_Detected = false;

void init_Obstacle_Avoidance()
{
  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_R, INPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
 // attachInterrupt(digitalPinToInterrupt(ECHO_L), handleInterrupt, CHANGE);
}

void get_Forward_Distance()
{
  int Duration;
  digitalWrite(TRIG_F, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_F, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_F, LOW);
  Duration = pulseIn(ECHO_F, HIGH);
  //  Serial.println("Duration: ");
  //  Serial.println(Duration);
  Forward_Ultrasonic_Value = Duration * 0.034 / 2;

  Serial.print("Forward_Ultrasonic: ");
  Serial.print(Forward_Ultrasonic_Value);
}

void get_Right_Distance()
{
  int Duration;
  digitalWrite(TRIG_R, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_R, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_R, LOW);
  Duration = pulseIn(ECHO_R, HIGH);
  Right_Ultrasonic_Value = Duration * 0.034 / 2;

  //  Serial.println("Duration: ");
  //  Serial.println(Duration);
  Serial.print("  Right_Ultrasonic: ");
  Serial.print(Right_Ultrasonic_Value);
}
void get_Left_Distance_Asenq()
{
  digitalWrite(TRIG_L, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_L, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_L, LOW);
  while (!Left_pulse_Detected)
  {
    pox.update();
    // You can add additional code here if needed
  }
  unsigned long Left_pulse_Duration = Left_pulse_EndTime - Left_pulse_StartTime;

  // Calculate the distance in centimeters
  unsigned int distance = Left_pulse_Duration * 0.034 / 2;
  Left_pulse_Detected = false;
  Serial.print("  Left_Ultrasonic_Value: ");
  Serial.println(distance);
}
void handleInterrupt()
{
  // Check if the Echo pin is HIGH (rising edge)
  if (digitalRead(ECHO_L) == HIGH)
  {
    Left_pulse_StartTime = micros();  // Record the pulse start time
  }
  else
  {
    Left_pulse_EndTime = micros();    // Record the pulse end time
    Left_pulse_Detected = true;       // Set the pulse detection flag
  }
}
int pulseInCustom(uint8_t pin, uint8_t state, unsigned long timeout = 1000000)
{
  unsigned long startTime = micros();  // Start time of the pulse
  unsigned long timeoutEndTime = startTime + timeout;  // End time for the timeout
  unsigned long pulseDuration = 0;  // Duration of the pulse
  
  // Wait for the pulse to start
  while (digitalRead(pin) != state) {
  //  pox.update();
    if (micros() > timeoutEndTime) {
      // Timeout occurred
      return 0;
    }
  }

  // Measure the pulse duration
  while (digitalRead(pin) == state) {
    // pox.update();
    pulseDuration = micros() - startTime;
    if (pulseDuration > timeout) {
      // Timeout occurred
      return 0;
    }
  }
  
  return pulseDuration;
}
void get_Left_Distance()
{
  int Duration;
  digitalWrite(TRIG_L, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_L, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_L, LOW);
  //Duration = pulseIn(ECHO_L, HIGH);
   // Duration = pulseInCustom( ECHO_L, HIGH,1000000);
  Left_Ultrasonic_Value = Duration * 0.034 / 2;
  //  Serial.println("Duration: ");
  //  Serial.println(Duration);
  Serial.print("  Left_Ultrasonic_Value: ");
  Serial.println(Left_Ultrasonic_Value);
}

void check_Obstacle()
{
  switch (Current_Move)
  {
    case FORWARD:
      get_Forward_Distance();
      compare_Threshold(Forward_Ultrasonic_Value);
      break;

    case BACKWARD:
    case STOP:
      Obstacle_Distance = -1;
      break;

    case RIGHT:
      get_Right_Distance();
      compare_Threshold(Right_Ultrasonic_Value);
      break;

    case LEFT:
      get_Left_Distance();
      compare_Threshold(Left_Ultrasonic_Value);
      break;

    case FORWARD_RIGHT:
      get_Forward_Distance();
      get_Right_Distance();
      compare_Threshold (min(Forward_Ultrasonic_Value, Right_Ultrasonic_Value));
      break;

    case FORWARD_LEFT:
      get_Forward_Distance();
      get_Left_Distance();
      compare_Threshold (min(Forward_Ultrasonic_Value, Left_Ultrasonic_Value));
      break;
  }
}

void compare_Threshold(float Distance_Value)
{
  if (Distance_Value < OBSTACLE_THRESHOLD)
    Obstacle_Distance = Distance_Value;
  else
    Obstacle_Distance = -1;
}


void check_Obstacle_Alert()
{
  if (Obstacle_Distance != -1)
  {
    int Volume_Level = map(Obstacle_Distance, 0, OBSTACLE_THRESHOLD, BUZZER_MAXIMUM_TONE, BUZZER_MINIMUM_TONE);
    analogWrite(BUZZER_PIN, Volume_Level);
  }
  else
    analogWrite(BUZZER_PIN, 0);
}

void start_Error_Alert()
{
  analogWrite(BUZZER_PIN, 200);
  delay(500);
  analogWrite(BUZZER_PIN, 0);
  delay(500);
}
