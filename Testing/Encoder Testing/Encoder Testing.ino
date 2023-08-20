#define PPR 60            // Pulses Per Revolution of the encoder.
#define WCFC 39           // Wheel circumference in cm.  // 37.7143 old value
#define distance_test 100 // The distance in cm.  

#define RM_Int 0  // Right Motor Mixed interrupt at pin 2 INT 0
#define LM_Int 1  // Left Motor Mixed interrupt at  pin 3 INT 1

#define R_DIR   5
#define L_DIR   8
#define R_speed 6
#define L_speed 9

#define forward  1
#define backward 0

#define Speed 70

boolean Stop;
int RM_Int_current, LM_Int_current, current, distance_in_pulses;

void setup() {

  distance_in_pulses = ( distance_test / WCFC ) * PPR * 2;

  pinMode(R_DIR,  OUTPUT);
  pinMode(L_DIR,  OUTPUT);
  pinMode(R_speed, OUTPUT);
  pinMode(R_speed, OUTPUT);

   attachInterrupt(RM_Int, RM_Int_Handler, RISING);
   attachInterrupt(LM_Int, LM_Int_Handler, RISING);
  
  Serial.begin(9600);
  Serial.println("... Starting .../n/n");
  Serial.print("distance_in_pulses: "); 
  Serial.println(distance_in_pulses);
  Serial.print("/n/n/n");
}



void loop()
{
  delay(5000);  // wait 5 seconds before start moving.
 
  if(!Stop)
  {
         // go_forward
   
         analogWrite(R_speed, Speed);
         analogWrite(L_speed, Speed);
         digitalWrite(R_DIR, forward);
         digitalWrite(L_DIR, forward);
  }
  
}


void RM_Int_Handler()
{
  RM_Int_current++;  
 
  Serial.print("                          RM_Int_current: ");
  Serial.println(RM_Int_current);   
  /*
     current= (RM_Int_current+LM_Int_current)/2;
      if(current>distance_in_pulses)
        {
         //stop
        digitalWrite(R_speed, 0);
        digitalWrite(L_speed, 0);
        Stop =1; 
        Serial.println("________Stop Right Motor______");
        Serial.print("Average current pulses: ");
        Serial.println(current);
        }*/
}

void LM_Int_Handler()
{
  LM_Int_current++;  
 
  Serial.print("LM_Int_current: ");
  Serial.println(LM_Int_current);
 
   /*  current= (RM_Int_current+LM_Int_current)/2;
      if(LM_Int_current>distance_in_pulses)
        {
         //stop
        digitalWrite(R_speed, 0);
        digitalWrite(L_speed, 0);
        Stop =1;
        Serial.println("________Stop Left Motor______");
        Serial.print("Average current pulses: ");
        Serial.println(current);
        }*/
}
