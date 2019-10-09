#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)

#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

#define CARDCS 4     // Card chip select pin
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = 
  Adafruit_VS1053_FilePlayer(SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);


 
void setup() 
{
//
// musicPlayer.GPIO_pinMode(4, OUTPUT);
(! musicPlayer.begin());
SD.begin(CARDCS);
musicPlayer.setVolume(1,1);
musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);
//musicPlayer.GPIO_digitalWrite(4, HIGH);
Serial.begin(57600);


}


void loop() 
{

 musicPlayer.GPIO_digitalWrite(4, HIGH);
  
if (musicPlayer.GPIO_digitalRead(5) == HIGH)
          {
            Serial.println("ola!");
            Serial.println(analogRead);
//          musicPlayer.GPIO_digitalWrite(7, HIGH);
          musicPlayer.playFullFile("martha.mp3");
//          delay(1000);
        }
//          if (musicPlayer.GPIO_digitalRead(5) == LOW)
//          {
//          musicPlayer.paused("track001.mp3");
//            delay(1000);
//          }
//   if (musicPlayer.GPIO_digitalRead(3) == HIGH)
//          {
//          musicPlayer.playFullFile("test3.mp3");
//          delay(1000);
//          }
//    if (musicPlayer.GPIO_digitalRead(4) == HIGH)
//          {
//          musicPlayer.playFullFile("test4.mp3");
//          delay(1000);
//          }
//    if (musicPlayer.GPIO_digitalRead(5) == HIGH)
//          {
//          musicPlayer.playFullFile("test5.mp3");
//          delay(1000);
//          }
//     if (musicPlayer.GPIO_digitalRead(6) == HIGH)
//          {
//          musicPlayer.playFullFile("test6.mp3");
//          delay(1000);
//          }
//     if (musicPlayer.GPIO_digitalRead(7) == HIGH)
//          {
//          musicPlayer.playFullFile("test7.mp3");
//          delay(1000);      
//          }
 }
 
