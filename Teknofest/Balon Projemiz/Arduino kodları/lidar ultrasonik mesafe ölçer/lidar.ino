#include <SoftwareSerial.h>

SoftwareSerial lidarSerial(10, 11);
// RX pini 10, TX pini 11 olarak ayarladım

void setup() {
  Serial.begin(9600); // Seri monitör için baud hız ayarı
  lidarSerial.begin(115200); // LIDAR sensöründen veri almak için baud hız ayarı
}

void loop() {
  while (lidarSerial.available()) {
    char c = lidarSerial.read();
    Serial.write(c); 
  }
}
