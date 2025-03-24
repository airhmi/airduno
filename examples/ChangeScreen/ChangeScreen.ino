#include <Airhmi.h>

AirPage s0 = AirPage();

char buffer[100] = {0};


AirTouch *air_listen_list[] = {
  NULL
};

void setup()
{
  Serial.begin(115200);
  airInit();

}

void loop()
{
 
  airLoop(air_listen_list);
  
  s0.ChangeScreen("Screen2");
  delay(1000);

  // İhtiyaca göre diğer işlemleri gerçekleştir
}
