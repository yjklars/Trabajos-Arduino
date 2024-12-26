int i;
int k;
int estado;
int contadorPUSH = 8;
int contadorPOP = 1;
int PUSH = 1;
int POP = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  estado = digitalRead(8);
  delay(250);
  if(estado == LOW && PUSH == 1){
    contadorPUSH--;
    if(contadorPUSH > 1){
      for(k = 2; k < contadorPUSH; k++){
        digitalWrite(k, HIGH);
        delay(500);
        digitalWrite(k, LOW);
        delay(500);
      }
      digitalWrite(contadorPUSH, HIGH);
      delay(500);
      if(contadorPUSH == 2){
        PUSH = 0;
        POP = 1;
        contadorPUSH = 8;
      }
    }
  }else if(estado == LOW && POP == 1){
    contadorPOP++;
    if(contadorPOP < 8){
      if (contadorPOP == 2){
        digitalWrite(contadorPOP, LOW);
        delay(500);
        
      }else{
        digitalWrite(contadorPOP, LOW);
        delay(500);
        for(i=contadorPOP-1; i > 1; i--){
          digitalWrite(i, HIGH);
          delay(500);
          digitalWrite(i, LOW);
          delay(500);
        }
      }
      if(contadorPOP == 7){
        PUSH = 1;
        POP = 0;
        contadorPOP = 1;
      }
    }
  }
}
