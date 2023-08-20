/*New*/
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

 PulseOximeter pox;
static uint32_t tsLastReport = 0;
/*
const unsigned char bitmap [] PROGMEM =
{
  0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x18, 0x00, 0x0f, 0xe0, 0x7f, 0x00, 0x3f, 0xf9, 0xff, 0xc0,
  0x7f, 0xf9, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xf0,
  0xff, 0xf7, 0xff, 0xf0, 0xff, 0xe7, 0xff, 0xf0, 0xff, 0xe7, 0xff, 0xf0, 0x7f, 0xdb, 0xff, 0xe0,
  0x7f, 0x9b, 0xff, 0xe0, 0x00, 0x3b, 0xc0, 0x00, 0x3f, 0xf9, 0x9f, 0xc0, 0x3f, 0xfd, 0xbf, 0xc0,
  0x1f, 0xfd, 0xbf, 0x80, 0x0f, 0xfd, 0x7f, 0x00, 0x07, 0xfe, 0x7e, 0x00, 0x03, 0xfe, 0xfc, 0x00,
  0x01, 0xff, 0xf8, 0x00, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x3f, 0xc0, 0x00,
  0x00, 0x0f, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};*/

void onBeatDetected() {
  Serial.println("♥ Beat!");
  if ((SPO2 > 0) && (HeartRate > 0)) {
    //oled.drawBitmap( 60, 20, bitmap, 28, 28, 1);
    //oled.display();
  }
}

void init_Healthcare_System()
{
  pinMode(TEMPERATURE_PIN, INPUT);

  Wire.begin();

 while (!pox.begin());  //Todo: Add buzzer alert in case error during Oximeter beginning.

  // Configure sensor to use 7.6mA for LED drive
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  
   // Register a callback routine
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void read_Temperature_Sensor()
{
  static int Temp_Counter = 0;
  Temp_Counter++;

  if (Temp_Counter % Temp_Reading_Interval == 0)
  {
    int Sensor_Value;
    float Temprature_Voltage;

    Sensor_Value = analogRead(TEMPERATURE_PIN);
    Temprature_Voltage = Sensor_Value * ((float)SENSOR_MAX_VOLT_VALUE / LM35_MAX_TEMPERATURE);
    Temperature = Temprature_Voltage * 10;

    if (Temperature < MINIMUM_BODY_TEMPERATURE || Temperature > MAXIMUM_BODY_TEMPERATURE)
      Temperature = INVALID_DATA;
  }
}


void read_Oximeter()
{
 /* static int Oximeter_Reading_Counter = 0;
  Oximeter_Reading_Counter++;

  if (Oximeter_Reading_Counter % Oximeter_Reading_Interval == 0)
  {*/
    pox.update();
	if (millis() - tsLastReport > REPORTING_PERIOD_MS) 
	{
    HeartRate = pox.getHeartRate();
    SPO2 = pox.getSpO2();
  //Serial.println(" SPO2: ");
  // Serial.println(pox.getSpO2());
/*
    if (HeartRate < MINIMUM_HUMAN_HEARTRATE || HeartRate > MAXIMUM_HUMAN_HEARTRATE)
      HeartRate = INVALID_DATA;

    if (SPO2 < MINIMUM_HUMAN_SPO2 || SPO2 > MAXIMUM_HUMAN_SPO2)
      SPO2 = INVALID_DATA;
	  */
	tsLastReport = millis();
	//}
  }
}
