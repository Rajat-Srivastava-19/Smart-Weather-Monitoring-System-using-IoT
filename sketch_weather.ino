#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2         // DHT11 connected to Digital Pin 2
#define DHTTYPE DHT11    // Sensor type
DHT dht(DHTPIN, DHTTYPE);

#define MQ135_PIN A0     // MQ135 connected to Analog Pin A0

// Initialize LCD (16x2) with I2C Address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    dht.begin();
    lcd.init();
    lcd.backlight();  // Turn on LCD backlight
    lcd.setCursor(0, 0);
    lcd.print("Weather Monitor");
    delay(2000);
}

void loop() {
    // Read Temperature & Humidity
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Read Air Quality
    int air_quality = analogRead(MQ135_PIN);

    // Display Data on Serial Monitor
    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.print("°C | Humidity: ");
    Serial.print(humidity);
    Serial.print("% | Air Quality: ");
    Serial.println(air_quality);

    // Display Data on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp : ");
    lcd.print(temperature);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Hum : ");
    lcd.print(humidity);
     lcd.print(" %");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" AQI : ");
    lcd.print(air_quality);
     lcd.print(" ppm");

     lcd.setCursor(0,1);
  if(air_quality<=100 and air_quality>0)
    lcd.print(" Very Good ");
  if(air_quality<=200 and air_quality>100)
    lcd.print(" Good AQI. ");
  if(air_quality<=300 and air_quality>200)
  lcd.print(" Poor AQI. ");  
  if(air_quality<400 and air_quality>300)
    lcd.print("Very Poor AQI.");
  if(air_quality<500 and air_quality>400)
    lcd.print("Extremely Poor.");

    delay(2000);  // Refresh every 2 seconds
}
