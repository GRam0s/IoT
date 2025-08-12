const int buttonPin = A1;
const int ledPin = 13;

int ledState = LOW;            // estado do LED
int lastReading = HIGH;        // última leitura bruta do pino (INPUT_PULLUP = HIGH quando solto)
int stableState = HIGH;        // última leitura estável (debounced)

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // se houve mudança de leitura, resetamos o timer do debounce
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  // só aceitamos uma nova mudança se estiver estável por > debounceDelay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != stableState) {
      stableState = reading;
      // aqui detectamos o evento do botão: na configuração INPUT_PULLUP,
      // o botão PRESSED apresenta LOW (pulldown para GND), então detectamos LOW.
      if (stableState == LOW) {
        // Toggle no LED apenas quando o botão é pressionado
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }

  lastReading = reading;
}
