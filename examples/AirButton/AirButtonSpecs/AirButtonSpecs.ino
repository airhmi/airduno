#include <Airhmi.h>

AirButton b0 = AirButton("EButton1");

void b0PopCallback(void *ptr)
{
  char buffer[10];
  int currentValue = 0;

  // Mevcut buton değerini al
  b0.getText(buffer, sizeof(buffer));
  currentValue = atoi(buffer); // String'i acinteger'a çevir
  
  // Değeri bir arttır
  currentValue++;

  // Yeni değeri tekrar butona ve etikete yaz
  sprintf(buffer, "%d", currentValue);
  b0.setText(buffer);
  
  //delay(50);
  // Butonun görsel özelliklerini değiştir
  b0.Set_background_color(0xFF0000 + (currentValue * 0x050505)); // Arka plan rengi dinamik değişir
  //delay(50);
  b0.Set_press_background_color(0x00FF00 + (currentValue * 0x030303)); // Basılınca arka plan değişir
  //delay(50);
  b0.Set_font_size(12 + (currentValue % 10)); // Yazı boyutu değişir
  //delay(50);
  b0.Set_font_color(0xFFFFFF - (currentValue * 0x010101)); // Yazı rengi değişir
  //delay(50);
  b0.Set_pen_width(2 + (currentValue % 5)); // Çerçeve kalınlığı değişir
  //delay(50);
  b0.Set_pen_color(0x0000FF + (currentValue * 0x020202)); // Kenarlık rengi değişir

  // Yeni görsel efektler
  //delay(50);
  b0.Set_visible(1); // Butonu görünür yap
  //delay(50);
  b0.Set_active(1); // Butonu aktif yap
  //delay(50);
  b0.Set_left(50 + (currentValue % 20) * 5); // Butonun sol koordinatını değiştir
  //delay(50);
  b0.Set_top(50 + (currentValue % 10) * 5); // Butonun üst koordinatını değiştir
  //delay(50);
  b0.Set_width(100 + (currentValue % 10) * 2); // Buton genişliğini değiştir
  //delay(50);
  b0.Set_height(50 + (currentValue % 5) * 2); // Buton yüksekliğini değiştir

  //delay(50);
  // Dinamik renk değişimi için RGB formatı
  char colorRGB[10];
  sprintf(colorRGB, "#%02X%02X%02X", (currentValue * 10) % 256, (currentValue * 5) % 256, (currentValue * 3) % 256);
  b0.Set_font_colorRGB(colorRGB); // Yazı rengini dinamik olarak değiştir
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
