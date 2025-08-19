int led = 9;  // pino PWM (no Arduino Uno: 3, 5, 6, 9, 10 ou 11)

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // Aumenta o brilho de 0 até 255
  for (int valor = 0; valor <= 255; valor++) {
    analogWrite(led, valor);
    delay(10);
  }

  // Diminui o brilho de 255 até 0
  for (int valor = 255; valor >= 0; valor--) {
    analogWrite(led, valor);
    delay(10);
  }
}
