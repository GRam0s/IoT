int vermelho = 9;
int verde    = 10;
int azul     = 11;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  // Vermelho
  analogWrite(vermelho, 255);
  analogWrite(verde, 0);
  analogWrite(azul, 0);
  delay(1000);

  // Verde
  analogWrite(vermelho, 0);
  analogWrite(verde, 255);
  analogWrite(azul, 0);
  delay(1000);

  // Azul
  analogWrite(vermelho, 0);
  analogWrite(verde, 0);
  analogWrite(azul, 255);
  delay(1000);

  // Amarelo (Vermelho + Verde)
  analogWrite(vermelho, 255);
  analogWrite(verde, 255);
  analogWrite(azul, 0);
  delay(1000);

  // Ciano (Verde + Azul)
  analogWrite(vermelho, 0);
  analogWrite(verde, 255);
  analogWrite(azul, 255);
  delay(1000);

  // Magenta (Vermelho + Azul)
  analogWrite(vermelho, 255);
  analogWrite(verde, 0);
  analogWrite(azul, 255);
  delay(1000);

  // Branco (todas as cores)
  analogWrite(vermelho, 255);
  analogWrite(verde, 255);
  analogWrite(azul, 255);
  delay(1000);

  // Desliga
  analogWrite(vermelho, 0);
  analogWrite(verde, 0);
  analogWrite(azul, 0);
  delay(1000);
}
