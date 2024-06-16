#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 Nisal = Adafruit_SSD1306(128,64,&Wire);

void setup() {

  Nisal.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 
}

//int x = hi;

void loop() {

  Nisal.clearDisplay();
  Nisal.setTextColor(WHITE);

  Nisal.setTextSize(2);
  Nisal.setCursor(0,0);
  Nisal.print("Hello");
  
  Nisal.setTextSize(2);
  Nisal.setCursor(20,22);
  Nisal.print("World");
  delay(100);

  Nisal.display();

  Nisal.dim(true);
  delay(500);
  Nisal.dim(false);
  delay(500);

}
