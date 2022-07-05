 //WEATHER STATION THAT MEASURES HUMIDITY AND TEMPERATURE.
 //Application can be found in agriculture(green house), farming, house.

#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

#include "DHT.h"//imports library for dht11
#define DHTTYPE DHT11 //The sensore type you are using
#define DHTPIN 3//Renames pin 3 DHT11_PIN
DHT dht(DHTPIN, DHTTYPE); //Creates an object of dht11 class
float t,f,humidityValues;
char degreeSymbol = 223;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  measureHumidity();//Calls the function 'measureHumidity'
  
  measureTemperature();//Calls the function 'measureTemperature'

  printReadings();
}
//Creating the function 'measureHumidity'
double measureHumidity()
{
   humidityValues = dht.readHumidity();//Function that gets humidity readings
}

//Creating the function 'measureTemperature()'
double measureTemperature()
{
   t= dht.readTemperature();//Reads in Celsius
  f = dht.readTemperature(true); //Reads in Fehrenheit
}
void printReadings()
{
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.setCursor(0,1);
  lcd.print(humidityValues);
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print(t);
  lcd.print(degreeSymbol);
  lcd.print("C");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print(f);
  lcd.print("F");
  delay(1000);
  lcd.clear();

  Serial.print("Temperature(in Celsius); ");
  Serial.println(t);
  Serial.println("degree Celsius");
  delay(900);

  Serial.print("Temperature(in Fehrenheit): ");
  Serial.print(f);
  Serial.println(" degree Fehrenheit");

  Serial.print("");

  Serial.print("Humidity: ");
  Serial.println(humidityValues);
  delay(900);  
}
