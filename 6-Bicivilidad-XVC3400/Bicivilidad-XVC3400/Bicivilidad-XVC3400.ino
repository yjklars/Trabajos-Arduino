int xPin = A4;
int yPin = A5;

void reseteo(){
  for (int i=2; i<10; i++){
    digitalWrite(i, LOW);
  }
  for (int j=10; j<18; j++){
    digitalWrite(j, HIGH);
  }
}

void forward(){
  reseteo();
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);

  reseteo();
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);

  reseteo();
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);

  reseteo();
  digitalWrite(2, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(13, LOW);

  reseteo();
  digitalWrite(2, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(14, LOW);
  
  reseteo();
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(15, LOW);

  reseteo();
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(16, LOW);

  reseteo();
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(17, LOW);
}

void left(){
  reseteo();
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);

  reseteo();
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(11, LOW);

  
  reseteo();
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(12, LOW);

  
  reseteo();
  for (int i=2; i<10; i++){
    digitalWrite(i, HIGH);
  }
  digitalWrite(13, LOW);
  
  reseteo();
  for (int i=2; i<10; i++){
    digitalWrite(i, HIGH);
  }
  digitalWrite(14, LOW);

  
  reseteo();
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(15, LOW);
  
  reseteo();
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(16, LOW);
  
  reseteo();
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(17, LOW);
}

void right(){
  reseteo();
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);

  reseteo();
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);

  reseteo();
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);

  reseteo();
  for (int i=2; i<10; i++){
    digitalWrite(i, HIGH);
  }
  digitalWrite(13, LOW);
  
  reseteo();
  for (int i=2; i<10; i++){
    digitalWrite(i, HIGH);
  }
  digitalWrite(14, LOW);

  reseteo();
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(15, LOW);

  reseteo();
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(16, LOW);

  reseteo();
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(17, LOW);  
}

void stand(){
  reseteo();
  for (int i=2; i<10; i++){
    digitalWrite(i, HIGH);
  }
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
}

void stop(){
  reseteo();
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  for (int i=10; i<18; i++){
    if(i != 15){
      digitalWrite(i, LOW);
    }
  }
}

void setup(){ 
  for (int j=2; j<18; j++){
    pinMode(j, OUTPUT);
  }
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop(){
  if(analogRead(xPin) < 300 && analogRead(yPin) == 517){
    left();
  }
  if(analogRead(xPin) > 700 && analogRead(yPin) == 517){
    right();
  }
  if((analogRead(xPin) >505 && analogRead(xPin) < 509) && analogRead(yPin) < 300){
    stand();
  }
  if((analogRead(xPin) > 505 && analogRead(xPin) < 509) && analogRead(yPin) > 700){
    stop();
  }

  if((analogRead(xPin) > 505 && analogRead(xPin) < 509) && (analogRead(yPin) > 513 && analogRead(yPin) <519)){
    forward();
  }
  reseteo();
}
