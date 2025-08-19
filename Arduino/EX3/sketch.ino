int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int contador = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  digitalWrite(led1, bitRead(contador, 0));
  digitalWrite(led2, bitRead(contador, 1));
  digitalWrite(led3, bitRead(contador, 2));
  digitalWrite(led4, bitRead(contador, 3));

  contador++;
  if (contador > 15) {
    contador = 0;
  }

  delay(5000); // meio segundo
}
