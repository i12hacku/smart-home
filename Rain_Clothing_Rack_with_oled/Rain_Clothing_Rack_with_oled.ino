#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128,64,&Wire);

int rainsense= A0;  // analog sensor input pin 0
int ldrPin = 4; 
int buzzerout= 10;  // digital output pin 10 - buzzer output
int countval= 0;  // counter value starting from 0 and goes up by 1 every second
int ledout= 11; // digital output pin 11 - led output

//Definitions

void setup() {
  
oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

   Serial.begin(9600);
   pinMode(buzzerout, OUTPUT);
   pinMode(ledout, OUTPUT); 
    pinMode(ldrPin, INPUT); 
   pinMode(rainsense, INPUT);
   
  //motor driver controls
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);


  //Setup the LCD Display
  
  
 // oled.clearDisplay();
 // oled.setTextColor(WHITE);


  

}

void loop() {

    oled.clearDisplay();
  oled.setTextColor(WHITE);

   //Read the data from the 
   int rainSenseReading = analogRead(rainsense);
   int ldrStatus = digitalRead(ldrPin); //saving the digital values received from LDR

   Serial.println(rainSenseReading);  // serial monitoring message 
   Serial.println(ldrStatus);  // serial monitoring message 



    if(rainSenseReading <450){

    oled.clearDisplay();
  oled.setTextColor(WHITE);
  
         oled.setTextSize(2);
         oled.clearDisplay();
         oled.setCursor(20,22);
         oled.print("Raning!");
         oled.display();

        //Rotate motor anticlockwise
          digitalWrite(4, HIGH);
          delay(200);
          digitalWrite(4, LOW);

          delay(500);

          digitalWrite(4,LOW);
          delay(100);
          digitalWrite(4,LOW);

          digitalWrite(buzzerout, HIGH);  // turn off buzzer 
      
      }
      else if((rainSenseReading > 450) or (ldrStatus = 1)){

         oled.setTextSize(2);        
         oled.clearDisplay();
         oled.setCursor(20,22);
         oled.print("Sunny!");

         oled.display();

            
            digitalWrite(5, HIGH);
            delay(200);
            digitalWrite(5, LOW);
            delay(500);

            digitalWrite(5,LOW);
            delay(100);
            digitalWrite(5,LOW);

                digitalWrite(buzzerout, LOW);  // turn off buzzer 
        }
        else if(ldrStatus = 0){
         oled.setTextSize(2);
         oled.setCursor(0,0);
         oled.print("Evening!");

         oled.display();

          digitalWrite(4, HIGH);
          delay(1000);
          digitalWrite(4, LOW);
          
          }
}
