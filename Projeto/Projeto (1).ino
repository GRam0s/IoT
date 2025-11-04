#include "DHT.h"

#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int ledVerde = 7;
const int ledAmarelo = 8;
const int ledVermelho = 9;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (!isnan(t) && !isnan(h)) {
    Serial.print("Temperatura:");
    Serial.print(t);
    Serial.println("*C");
  } else {
    Serial.println("Erro leitura DHT");
  }

  // LEDs indicam a faixa de temperatura
  if (t < 25) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (t >= 25 && t < 30) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  delay(2000); // Atualiza a cada 2 segundos
}
