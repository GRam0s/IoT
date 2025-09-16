int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;

int pot = A0;  // potenciômetro ligado na entrada analógica A0
int valor = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  valor = analogRead(pot);        // lê o potenciômetro (0 a 1023)
  int nivel = map(valor, 0, 1023, 0, 6);  // converte para 0 até 6 LEDs

  // apaga todos
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);

  // acende conforme o nível
  if (nivel >= 1) digitalWrite(led1, HIGH);
  if (nivel >= 2) digitalWrite(led2, HIGH);
  if (nivel >= 3) digitalWrite(led3, HIGH);
  if (nivel >= 4) digitalWrite(led4, HIGH);
  if (nivel >= 5) digitalWrite(led5, HIGH);
  if (nivel >= 6) digitalWrite(led6, HIGH);

  delay(50); // um pequeno atraso para estabilidade
}
