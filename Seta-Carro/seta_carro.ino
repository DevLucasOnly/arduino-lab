const int pinoPotenciometro = A0;
const int pinoLedDireito = 9;
const int pinoLedEsquerdo = 10;
const int pinoBotao = 7;

const int limiteDireita = 800;
const int limiteEsquerda = 200;
const int intervaloPiscada = 300;

unsigned long ultimoTempo = 0;
bool estadoLed = false;

bool piscaAlertaLigado = false;
bool estadoBotaoAnterior = HIGH; // por causa do pull-up interno

void setup() {
  pinMode(pinoLedDireito, OUTPUT);
  pinMode(pinoLedEsquerdo, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  verificarBotao();

  if (piscaAlertaLigado) {
    piscarJuntos();
  } else {
    int valorPot = analogRead(pinoPotenciometro);

    if (valorPot >= limiteDireita) {
      piscar(pinoLedDireito, pinoLedEsquerdo);
    } 
    else if (valorPot <= limiteEsquerda) {
      piscar(pinoLedEsquerdo, pinoLedDireito);
    } 
    else {
      digitalWrite(pinoLedDireito, LOW);
      digitalWrite(pinoLedEsquerdo, LOW);
      estadoLed = false;
    }
  }
}

void verificarBotao() {
  bool estadoBotaoAtual = digitalRead(pinoBotao);

  // detecta o instante em que o botão foi pressionado (borda de descida)
  if (estadoBotaoAtual == LOW && estadoBotaoAnterior == HIGH) {
    piscaAlertaLigado = !piscaAlertaLigado; // liga se estava desligado, desliga se estava ligado
    delay(50); // debounce simples, evita leitura dupla no mesmo toque
  }

  estadoBotaoAnterior = estadoBotaoAtual;
}

void piscar(int pinoAtivo, int pinoInativo) {
  digitalWrite(pinoInativo, LOW);

  unsigned long agora = millis();
  if (agora - ultimoTempo >= intervaloPiscada) {
    ultimoTempo = agora;
    estadoLed = !estadoLed;
    digitalWrite(pinoAtivo, estadoLed ? HIGH : LOW);
  }
}

void piscarJuntos() {
  unsigned long agora = millis();
  if (agora - ultimoTempo >= intervaloPiscada) {
    ultimoTempo = agora;
    estadoLed = !estadoLed;
    digitalWrite(pinoLedDireito, estadoLed ? HIGH : LOW);
    digitalWrite(pinoLedEsquerdo, estadoLed ? HIGH : LOW);
  }
}