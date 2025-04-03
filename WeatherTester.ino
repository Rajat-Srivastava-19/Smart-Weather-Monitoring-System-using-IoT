#include <DHT.h>

#define DHTPIN 2        
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

#define MQ135_PIN A0    

void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
  
    float temperature = dht.readTemperature(); 
    float humidity = dht.readHumidity();

    int air_quality = analogRead(MQ135_PIN);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C  | Humidity: ");
    Serial.print(humidity);
    Serial.print("%  | Air Quality: ");
    Serial.println(air_quality);

    delay(2000);
}
