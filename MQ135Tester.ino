#define MQ135_PIN A0  // Define MQ135 sensor connected to A0

void setup() {
    Serial.begin(9600);  // Start serial communication
    pinMode(13,OUTPUT);
}

void loop() {
    int sensorValue = analogRead(MQ135_PIN);  // Read analog value from MQ135
    float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    //Serial.print(" | Voltage: ");
    //Serial.println(voltage);
    delay(1000); // Wait 1 second before next reading
    if(sensorValue>130){
      digitalWrite(13,HIGH);
      Serial.println("Smoke found");
      delay(1000);
    }
    digitalWrite(13,LOW);
}
