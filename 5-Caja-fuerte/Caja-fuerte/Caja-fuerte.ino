int A = 11;  // Boton Izquierda
int B = 10;  // Boton Derecha
int R = 5;
int G = 4;
int Y = 6;

int valido = 0;

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(Y, OUTPUT);
}

void loop() {
  int cont = 0;
  int valido = 0;
  digitalWrite(R, HIGH);
  while(!valido) {
    if (cont == 0 && !digitalRead(B)) { // primera entrada mala, reseteo
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont = 0;
      continue;
    }
    if (cont == 1 && !digitalRead(B)) { //segunda entrada mala
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont = 0;
      continue;
    }
    if (cont == 2 && !digitalRead(A)) { //tercera entrada mala
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont = 0;
      continue;
    }
    if (cont == 3 && !digitalRead(B)) { //cuarta entrada mala
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont = 0;
      continue;
    }
    if (!digitalRead(A) && cont == 0) { // primera entrada buena
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont++;
    }
    if (!digitalRead(A) && cont == 1) { // segunda entrada buena
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont++;
    }
    if (!digitalRead(B) && cont == 2) { // tercera entrada buena
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont++;
    }
    if (!digitalRead(A) && cont == 3) { // cuarta entrada buena
      digitalWrite(Y, HIGH);
      delay(500);
      digitalWrite(Y, LOW);
      cont++;
    }
    if (cont == 4) {
      valido = 1;  
    }
  }
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  delay(5000);
  digitalWrite(G, LOW);
}