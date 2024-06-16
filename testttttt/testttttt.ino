#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_I2C_ADDR 0x3C 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RST_PIN -1 

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RST_PIN);

void setup() {
    Serial.begin(115200);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C ,SCREEN_I2C_ADDR)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.display();
}

void drawFrame1() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(F("Frame 1"));
    display.drawCircle(64, 32, 10, SSD1306_WHITE);
    display.display();
}

void drawFrame2() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(F("Frame 2"));
    display.drawRect(54, 22, 20, 20, SSD1306_WHITE);
    display.display();
}

void loop() {
    drawFrame1();
    delay(500);

    drawFrame2();
    delay(500);
}
