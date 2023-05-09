int sensorPin = A0; // Rüzgar sensörü sinyal pimi
unsigned long duration;
unsigned long starttime;
unsigned long windspeed;
unsigned long lastspeed;
unsigned long lasttime;
float speed;
void setup() {
 Serial.begin(9600);
 pinMode(sensorPin, INPUT);
 digitalWrite(sensorPin, HIGH);
 lasttime = millis();
}
void loop() {
 duration = pulseIn(sensorPin, LOW);
 starttime = millis();
 windspeed = (1000 / (starttime - lasttime)) * duration;
 lasttime = starttime;
 lastspeed = lastspeed * 0.9 + windspeed * 0.1;
 speed = lastspeed / 4.8;
 Serial.print("Rüzgar hızı: ");
 Serial.print(speed);
 Serial.println(" km/saat");
 delay(1000);
}
