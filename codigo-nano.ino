#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int entradas[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int botaoPin = A0;

int posicaoCursor = 0;
bool botaoAnterior = LOW;
unsigned long ultimoPiscar = 0;
bool mostrarCaractere = true;
const unsigned long intervaloPiscar = 500;

// Bloco cheio para piscar
byte blocoCheio[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  for (int i = 0; i < 12; i++) {
    pinMode(entradas[i], INPUT);
  }

  pinMode(botaoPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.createChar(0, blocoCheio);  // Define caractere 0 como bloco sólido
  lcd.setCursor(0, 0);
  lcd.print("BIN:            ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void loop() {
  uint16_t valor = 0;

  // Leitura dos pinos de entrada
  for (int i = 0; i < 12; i++) {
    int leitura = digitalRead(entradas[i]);
    valor |= (leitura << i);
  }

  // Exibir valor binário na linha 0
  lcd.setCursor(4, 0);
  for (int i = 11; i >= 0; i--) {
    lcd.print((valor >> i) & 1);
  }

  char caractere = mapValorParaChar(valor);

  // Leitura do botão com detecção de borda de descida
  bool botaoAtual = digitalRead(botaoPin) == LOW;
  if (botaoAtual && !botaoAnterior) {
    // Salva o caractere e avança
    if (caractere != '-' && posicaoCursor < 16) {
      lcd.setCursor(posicaoCursor, 1);
      lcd.print(caractere);
      posicaoCursor++;
    }
  }
  botaoAnterior = botaoAtual;

  // Efeito de piscar
  unsigned long agora = millis();
  if (agora - ultimoPiscar >= intervaloPiscar) {
    ultimoPiscar = agora;
    mostrarCaractere = !mostrarCaractere;

    lcd.setCursor(posicaoCursor, 1);
    if (mostrarCaractere) {
      lcd.print(caractere);
    } else {
      lcd.write(byte(0));  // Bloco sólido
    }
  }

  delay(10);  // Pequeno delay para estabilidade
}

// ---------------------------
// Função de mapeamento
// ---------------------------
char mapValorParaChar(uint16_t valor) {
  if ((valor & ((1 << 11) | (1 << 1))) == ((1 << 11) | (1 << 1))) {
    switch (valor & 0x07FD) {
      case 4:    return '|';
      case 8:    return '+';
      case 16:   return '(';
      case 32:   return '<';
      case 64:   return '.';
      case 128:  return '¢';
    }
  }

  if ((valor & ((1 << 10) | (1 << 1))) == ((1 << 10) | (1 << 1))) {
    switch (valor & 0x03FD) {
      case 4:    return '¬';
      case 8:    return ';';
      case 16:   return ')';
      case 32:   return '*';
      case 64:   return '$';
      case 128:  return '!';
    }
  }

  if ((valor & ((1 << 9) | (1 << 1))) == ((1 << 9) | (1 << 1))) {
    switch (valor & 0x01FD) {
      case 64:   return ',';
      case 32:   return '%';
      case 16:   return '_';
      case 8:    return '>';
      case 4:    return '?';
    }
  }

  if ((valor & (1 << 1)) != 0) {
    switch (valor & 0xFFD) {
      case 128:  return ':';
      case 64:   return '#';
      case 32:   return '@';
      case 16:   return '\'';
      case 8:    return '=';
      case 4:    return '"';
    }
  }

  if ((valor & (1 << 11)) != 0) {
    switch (valor & 0x07FF) {
      case 256: return 'A';
      case 128: return 'B';
      case 64:  return 'C';
      case 32:  return 'D';
      case 16:  return 'E';
      case 8:   return 'F';
      case 4:   return 'G';
      case 2:   return 'H';
      case 1:   return 'I';
      case 0:   return '&';
    }
  }

  if ((valor & (1 << 10)) != 0) {
    switch (valor & 0x03FF) {
      case 256: return 'J';
      case 128: return 'K';
      case 64:  return 'L';
      case 32:  return 'M';
      case 16:  return 'N';
      case 8:   return 'O';
      case 4:   return 'P';
      case 2:   return 'Q';
      case 1:   return 'R';
      case 0:   return '-';
    }
  }

  if ((valor & (1 << 9)) != 0) {
    switch (valor & 0x01FF) {
      case 128: return 'S';
      case 64:  return 'T';
      case 32:  return 'U';
      case 16:  return 'V';
      case 8:   return 'W';
      case 4:   return 'X';
      case 2:   return 'Y';
      case 1:   return 'Z';
      case 0:   return '0';
    }
  }

  for (int i = 0; i < 9; i++) {
    if (valor == (1 << i)) {
      return '9' - i;
    }
  }

  return ' ';
}