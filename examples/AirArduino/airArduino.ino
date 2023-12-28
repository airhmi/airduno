#include <Airhmi.h>

AirButton b0 = AirButton("EButton1");
AirLabel t0 = AirLabel("ELabel1");
AirLabel t3 = AirLabel("ELabel3");
AirLabel t4 = AirLabel("ELabel4");
AirGauge g0 = AirGauge( "Gauage1");
AirVariable v0 = AirVariable("Var0");
AirPicture p0 = AirPicture("EImage1");

AirShape s0 = AirShape("EShape1");


char buffer[100] = {0};
int i=0;

void b0PopCallback(void *ptr)
{
  // Butona basıldığında yapılacak işlemler
  t0.setText("Hello AirHMI!"); // Ekran üzerindeki metin nesnesini güncelle
  t0.Set_fontColor(123456789);
  b0.setText("Deneme");
 
}

void b0PushCallback(void *ptr)
{
  // Butona basıldığında yapılacak işlemler
  t0.setText("Hello AirHMI 2!"); // Ekran üzerindeki metin nesnesini güncelle
  t0.Set_fontColor(987654321);
  
}

void p0PopCallback(void *ptr)
{
  // Butona basıldığında yapılacak işlemler
  t3.setText("IMAGE OK."); // Ekran üzerindeki metin nesnesini güncelle
  t3.Set_fontColor(987654321);
  t3.Set_fontSize(32);
}

void p0PushCallback(void *ptr)
{
  // Butona basıldığında yapılacak işlemler
  t3.setText("IMAGE."); // Ekran üzerindeki metin nesnesini güncelle
  t3.Set_fontColor(123456789);
  t3.Set_fontSize(32);
}


void s0PopCallback(void *ptr)
{
  // Butona basıldığında yapılacak işlemler
  t4.setText("SHAPE OK."); // Ekran üzerindeki metin nesnesini güncelle
  t4.Set_fontColor(987654321);
  t4.Set_fontSize(32);
}

void s0PushCallback(void *ptr)
{
  // Butona basıldığında yapılacak işlemler
  t4.setText("SHAPE."); // Ekran üzerindeki metin nesnesini güncelle
  t4.Set_fontColor(123456789);
  t4.Set_fontSize(32);
}

AirTouch *air_listen_list[] = {
  &b0,
  &p0,
  &s0,  
  NULL
};

void setup()
{
  Serial.begin(115200);
  airInit();

  // Butonun pop olayına dinleyici ekleyin
  b0.attachPop(b0PopCallback, &b0);
  b0.attachPush(b0PushCallback, &b0);
  p0.attachPop(p0PopCallback,&p0);
  p0.attachPush(p0PushCallback,&p0);
  s0.attachPop(s0PopCallback,&s0);
  s0.attachPush(s0PushCallback,&s0);  
  //Serial.println("115200");
}

void loop()
{
 
  //while(true)
  {
    airLoop(air_listen_list);
    //v0.VarSet("deneme");
    //delay(1000);

  }
  //char buf[16];
  //itoa(i, buf, 10);
  //t0.setText(buf);
  //i++;
  //delay(10);
  //b0.setText("xxxxas");
  //b0.Set_background_color(123123123);
  //b0.Set_background_colorTo(1234);
  //b0.Set_press_background_color(345);
  //b0.Set_press_background_colorTo(3452);
  //b0.Set_pen_width(5);
  //b0.Set_pen_color(234234);
  //b0.Set_pen_colorRGB("#123123");
  //b0.Set_font_size(12);
  //b0.setFont("Arial");
  
  //b0.Set_font_color(2342);
  //delay(1000);
  //b0.Set_font_colorRGB("#2342442");
  //b0.Set_visible(1);
  //delay(1000);
  //b0.Set_visible(0);
  //b0.Set_active(0);
  //b0.Set_left(100);
  //b0.Set_top(100);
  //b0.Set_width(500);
  //b0.Set_height(100);

  //char data[20];
  //memset(data, 0, sizeof(data));
  //b0.getText(data, 20);
  //Serial.println("Reciived data:");
  //Serial.println(data);
  
  //uint32_t number = 0;
  //b0.Get_background_color(&number);
  //Serial.print("Result:");
  //Serial.println(number);
  
  //g0.Set_visible(1);

  //delay(1000);

  // İhtiyaca göre diğer işlemleri gerçekleştir
}
