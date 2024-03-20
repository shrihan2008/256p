// blue 35
// black 23
// red 4
//yellow 27 
//green 2

// ground 2

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>

#include <ezButton.h>

#define screenWidth 128
#define screenHeight 64

ezButton button1(13);
ezButton button2(33);
ezButton button3(14);
ezButton button4(27);
ezButton button5(26);

int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
int flag=0;
Adafruit_SSD1306 displayOled(screenWidth,screenHeight,&Wire,-1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  button1.setDebounceTime(25);
  button2.setDebounceTime(25);
  button3.setDebounceTime(25);
  button4.setDebounceTime(25);
  button5.setDebounceTime(25);

   if(!displayOled.begin(SSD1306_SWITCHCAPVCC,0x3c)){
      Serial.println(F("SSD1306a allocation failed"));

      for(;;);
  }

  displayOled.clearDisplay();
  displayOled.setTextSize(1);
  displayOled.setTextColor(WHITE);
  displayOled.setCursor(2,5);
  displayOled.println("Start");
  displayOled.setCursor(2,21);
  displayOled.println("voting");
  displayOled.display();  
  delay(20);


}
void loop() {

   button1.loop();
   button2.loop();
   button3.loop();
   button4.loop();
   button5.loop();
   if(flag==0){
     displayOled.clearDisplay();
     displayOled.setTextSize(1);
     displayOled.setTextColor(WHITE);
     displayOled.setCursor(2,0);
     displayOled.println("A-Blue");
     displayOled.setCursor(2,16);
     displayOled.println("B-Black");
     displayOled.setCursor(2,32);
     displayOled.println("C-Red");
     displayOled.setCursor(2,48);
     displayOled.println("D-Yellow");
    displayOled.display();
     flag=1;
  }
  delay(10); // this speeds up the simulation
}
