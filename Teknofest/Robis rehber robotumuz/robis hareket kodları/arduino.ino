// Pin tanımlamaları
const int trigPin = 2;
const int echoPin = 3;
const int motor1Pin1 = 4;
const int motor1Pin2 = 5;
const int motor2Pin1 = 6;
const int motor2Pin2 = 7;
const int motorSpeedPin = 9;

// Değişken tanımlamaları
long duration;
int distance;

void setup() {
  // Pin tanımlamaları
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);

  // Seri haberleşme başlatma
  Serial.begin(9600);
}

void loop() {
  // Ultrasonik sensörden mesafe ölçme
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Araba hareketlerini kontrol etme
  if (distance > 50) {
    // İleri git
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 255);
  } 
  else if (distance > 30) {
    // Sol dönüş yap
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 200);
    delay(500);
  } 
  else if (distance > 30) {
   // İleri git
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 255);
  }
  else if (distance > 50) {
    // Sağ dönüş yap
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin, 200);
    delay(500);
  } 
  else if (distance > 50) {
    // İleri git
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 255);
  } 
  else if (distance > 30) {
    // Sağ dönüş yap
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin, 200);
    delay(500);
  } 
   else if (distance > 30) {
    // İleri git
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 255);
  }
   else if (distance > 50) {
    // Sol dönüş yap
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 200);
    delay(500);
  } 
  else if (distance > 50) {
    // İleri git
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 255);
  } 
  
  else {
    // Dur
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin, 0);
  }
}
