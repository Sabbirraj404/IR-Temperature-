 
//Prateek
//www.prateeks.in

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Define I2C address of lcd, number of columns and rows
LiquidCrystal_I2C lcd(0x27, 20, 4);

double temp_amb;
double temp_obj;

void setup()
{
  Serial.begin(9600);
  Serial.println("Temperature Sensor MLX90614");

  //Initialize LCD I2C
  lcd.init();
  lcd.backlight();

  //Initialize MLX90614
  mlx.begin();
 
}

void loop()
{

  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();
  if(temp_obj > 37) {
   
   Serial.print("Warning...HIGH TEMP...");
   lcd.clear();
   lcd.print("HIGH TEMP...");
   delay(50);}
  else{
    
  }
 
  //lcd display 
  lcd.setCursor(0, 0);
  lcd.print("Room Temp:");
  lcd.setCursor(10, 0);
  lcd.print(temp_amb);
  lcd.setCursor(15, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.print("Body Temp:");
  lcd.setCursor(10, 1);
  lcd.print(temp_obj);
  lcd.setCursor(15, 1);
  lcd.write(1);

  //Serial Monitor
  Serial.print("Room Temp = ");
  Serial.println(temp_amb);
  Serial.print("Object temp = ");
  Serial.println(temp_obj); 

  delay(50);
}
