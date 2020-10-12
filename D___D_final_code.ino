#include<Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int but_1=6;
const int but_2=7;
const int but_3=8;
const int but_4=9;
const int piezo_pin=10;
const int r_button_pin=13;

void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(but_1,INPUT);
  pinMode(but_2,INPUT);
  pinMode(but_3,INPUT);
  pinMode(but_4,INPUT);
  pinMode(r_button_pin,INPUT);
  pinMode(piezo_pin,OUTPUT);
  
  
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("INNOVATION");
  lcd.setCursor(0,1);
  lcd.print("SKYLINE");
  delay(3000);
 

}

void loop() 
{
     
    lcd.begin(16,2);
    if((digitalRead(but_1))==HIGH)
    {  
      water();
    }
    if((digitalRead(but_2))==HIGH)
    {  
      food();
    }
    if((digitalRead(but_3))==HIGH)
    {  
      washroom();
    }
    if((digitalRead(but_4))==HIGH)
    {  
      emergency();
    }
      
    
}

void reset()
{
    
    if((digitalRead(r_button_pin))==HIGH)
    {
      noTone(piezo_pin);   
    }
    else
    {
      reset();
    }
}

void water()
{
    
    tone(piezo_pin,1000);
    Serial.println("water");
    
    lcd.setCursor(0,0);
    lcd.print("Bed no 102");
    lcd.setCursor(0,1);
    lcd.print("Water");

    reset();
    
  
}

void food()
{
  
  
    tone(piezo_pin,1000);
    Serial.println("food");
   
    lcd.setCursor(0,0);
    lcd.print("Bed no 102");
    lcd.setCursor(0,1);
    lcd.print("Food");

    reset();
   
  }

void washroom()
{   
  
    tone(piezo_pin,1000);
    Serial.println("washroom");

    lcd.setCursor(0,0);
    lcd.print("Bed no 102");
    lcd.setCursor(0,1);
    lcd.print("Washroom");

    reset();
  
}

void emergency()
{
    tone(piezo_pin,1000);
    Serial.println("emergency");
    
    lcd.setCursor(0,0);
    lcd.print("Bed no 102");
    lcd.setCursor(0,1);
    lcd.print("Emergency");

    reset(); 
}

