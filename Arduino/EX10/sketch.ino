int led = 13;

// Tempo base (ms)
int ponto = 200;         // duração de um ponto
int traco = ponto * 3;   // duração de um traço
int pausaSimbolo = ponto;     // pausa entre pontos e traços
int pausaLetra = ponto * 3;   // pausa entre letras
int pausaPalavra = ponto * 7; // pausa entre palavras

// Mensagem a ser transmitida
String mensagem = "SOS CHATGPT";

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for (int i = 0; i < mensagem.length(); i++) {
    char c = toupper(mensagem[i]);

    if (c == ' ') {
      delay(pausaPalavra); // espaço entre palavras
    } else {
      enviaMorse(c);
      delay(pausaLetra);
    }
  }

  delay(3000); // espera antes de repetir
}
 
void enviaMorse(char c) {
  switch (c) {
    case 'A': sinal(".-"); break;
    case 'B': sinal("-..."); break;
    case 'C': sinal("-.-."); break;
    case 'D': sinal("-.."); break;
    case 'E': sinal("."); break;
    case 'F': sinal("..-."); break;
    case 'G': sinal("--."); break;
    case 'H': sinal("...."); break;
    case 'I': sinal(".."); break;
    case 'J': sinal(".---"); break;
    case 'K': sinal("-.-"); break;
    case 'L': sinal(".-.."); break;
    case 'M': sinal("--"); break;
    case 'N': sinal("-."); break;
    case 'O': sinal("---"); break;
    case 'P': sinal(".--."); break;
    case 'Q': sinal("--.-"); break;
    case 'R': sinal(".-."); break;
    case 'S': sinal("..."); break;
    case 'T': sinal("-"); break;
    case 'U': sinal("..-"); break;
    case 'V': sinal("...-"); break;
    case 'W': sinal(".--"); break;
    case 'X': sinal("-..-"); break;
    case 'Y': sinal("-.--"); break;
    case 'Z': sinal("--.."); break;
    case '1': sinal(".----"); break;
    case '2': sinal("..---"); break;
    case '3': sinal("...--"); break;
    case '4': sinal("....-"); break;
    case '5': sinal("....."); break;
    case '6': sinal("-...."); break;
    case '7': sinal("--..."); break;
    case '8': sinal("---.."); break;
    case '9': sinal("----."); break;
    case '0': sinal("-----"); break;
  }
}

void sinal(String codigo) {
  for (int i = 0; i < codigo.length(); i++) {
    if (codigo[i] == '.') {
      digitalWrite(led, HIGH);
      delay(ponto);
      digitalWrite(led, LOW);
    } else if (codigo[i] == '-') {
      digitalWrite(led, HIGH);
      delay(traco);
      digitalWrite(led, LOW);
    }
    delay(pausaSimbolo); // pausa entre ponto/traço
  }
}
