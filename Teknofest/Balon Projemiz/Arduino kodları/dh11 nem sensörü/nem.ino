#include <DHT.h>

#define DHTPIN 2     // nem ölçerin sinyal pini
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 NEM ÖLÇER UYGULAMASI"); // Başlangıç mesajı
  dht.begin();
}

void loop() {
  delay(2000); // 2 saniye bekle
  float h = dht.readHumidity(); // nem ölç
  float t = dht.readTemperature(); // sıcaklık ölç

  if (isnan(h) || isnan(t)) { 
    Serial.println("DHT11'den veri okunamadı.");
    return;
  }

  Serial.print("Nem(%): ");
  Serial.println(h);
  Serial.print("Sıcaklık(C): ");
  Serial.println(t); // değerleri yaz
}
