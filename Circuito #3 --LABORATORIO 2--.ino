//DEFINIMOS LOS PINES QUE UTILIZAREMOS.
const int rightButton = 2;
const int leftButton = 3;
const int pinA = 4;
const int pinB = 5;
const int pinC = 6;
const int pinD = 7;
const int pinE = 8;
const int pinF = 9;
const int pinG = 10;
const int pinDigit1 = 11;

void setup() {
//CONFIGURAMOS LOS PINES.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDigit1, OUTPUT);
  Serial.begin(9600);
}

void showNumber(int num) {
//TABLA PARA MOSTRAR LOS NUMEROS EN EL DISPLAY DE 7 SEGMENTOS
//CADA ELEMENTO DE LA MATRIZ CORRESPONDE A LOS PINES A, B, C, D, E, F Y G.
  int tabla[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };

  if (num >= 0 && num <= 9) {
    digitalWrite(pinA, tabla[num][0]);
    digitalWrite(pinB, tabla[num][1]);
    digitalWrite(pinC, tabla[num][2]);
    digitalWrite(pinD, tabla[num][3]);
    digitalWrite(pinE, tabla[num][4]);
    digitalWrite(pinF, tabla[num][5]);
    digitalWrite(pinG, tabla[num][6]);
  }
}

void showUpward() {
  for (int i = 0; i <= 9; i++) {
    showNumber(i);
    digitalWrite(pinDigit1, HIGH);
    delay(500);
    digitalWrite(pinDigit1, LOW);
    delay(500);
  }
}

void showDownward() {
  for (int i = 9; i >= 0; i--) {
    showNumber(i);
    digitalWrite(pinDigit1, HIGH);
    delay(500);
    digitalWrite(pinDigit1, LOW);
    delay(500);
  }
}
void loop() {
//COMPROVANDO EL ESTADO DEL BOTON IZQUIERDO
  if (digitalRead(leftButton) == HIGH) {
    for (int i = 0; i < 10; i++) {
      showNumber(i);
      delay(500); //RETRASO PARA EVITAR LECTURAS INCORRECTAS
    }
  }

//COMPROVANDO EL ESTADO DEL BOTON DERECHO
  if (digitalRead(rightButton) == HIGH) {
    for (int i = 9; i >= 0; i--) {
      showNumber(i);
      delay(500); //RETRASO PARA EVITAR LECTURAS INCORRECTAS
    }
  }

//COMPROVANDO SI SE AH RECIVIDO UN NUMERO DEL MONITO SERIAL
  if (Serial.available() > 0) {
    int number = Serial.parseInt();
//VERIFICANDO QUE EL NUMERO SEA DE UN SOLO DIGITO
    if (number >= 0 && number <= 9) {
      showNumber(number);
    }
  }
}
