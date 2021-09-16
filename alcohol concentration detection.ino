#include <LiquidCrystal.h>                //LCD Library
#define beeper    8                       //beeper on Digital 8
#define led       7                       //LED on Digital 7
#define sensor    A0                      //sensor on Analog 0
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    //Create instance of LCD

int gasLevel;                         //int variable for gas level
String quality ;

void setup() 
{
  lcd.begin(16, 2);                       //initial LCD setup
  Serial.begin(9600);                     //start serial comms
  pinMode(beeper,OUTPUT);                 //set beeper for output
  pinMode(led,OUTPUT);                    //set LED for output
  pinMode(sensor,INPUT);                  //set sensor for input
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("                   ");
  lcd.setCursor(0,1);
  lcd.print("                   ");
  gasLevel = analogRead(0);       // read analog input pin 0
 
  gasLevel = analogRead(sensor);
  if(gasLevel<175)
  {
    quality = "GOOD!";
  }
  else if (gasLevel >175 && gasLevel<225)
  {
    quality = "WEAK";
  }
  else if (gasLevel >225 && gasLevel<300)
  {
    quality = "BAD";
  }
  else if (gasLevel >300)
  {
    quality = "DANGEROUS!";
    digitalWrite(beeper,HIGH);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    digitalWrite(beeper,LOW);
  }
lcd.setCursor (0,0);
lcd.print("AirQua=");
Serial.print("Alcohol content=");
lcd.print(gasLevel, DEC);               // prints the value read
lcd.println(" PPM");
Serial.print(gasLevel-60, DEC);               // prints the value read
Serial.println(" PPM");
lcd.setCursor(0,1);
lcd.print("      ");
lcd.print(quality);
Serial.print(quality);
delay(1000);
}

/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 5K pot:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
