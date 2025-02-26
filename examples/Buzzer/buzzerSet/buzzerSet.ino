#include <Airhmi.h>

AirBuzzer buzzer = AirBuzzer("Buzzer1");

void setup()
{
  Serial.begin(115200);
  airInit();

}

void loop()
{

  buzzer.Set_Buzzer(100);
  
  delay(1000);

}
