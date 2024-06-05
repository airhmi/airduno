#include <Airhmi.h>

AirButton b0 = AirButton("EButton1");
AirLabel t0 = AirLabel("t0");
AirGauge g0 = AirGauge( "Gauage1");


AirVariable var1 = AirVariable("var1");
AirVariable var2 = AirVariable("var2");
AirVariable var3 = AirVariable("var3");

char buffer[100] = {0};

void b0PopCallback(void *ptr)
{
  // Butona basıldığında yapılacak işlemler
  //t0.setText("Hello, AirHMI!"); // Ekran üzerindeki metin nesnesini güncelle
  var1.VarSeti(5);
  int val = var2.VarGeti();
  var3.VarSeti(val);
  
  
}

AirTouch *air_listen_list[] = {
  &b0,
  NULL
};

void setup()
{
  Serial.begin(115200);
  airInit();

  // Butonun pop olayına dinleyici ekleyin
  b0.attachPop(b0PopCallback, &b0);
}

void loop()
{
 
  airLoop(air_listen_list);

}