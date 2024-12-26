int i;
int l;
int k;
int o;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  for(o=7;o>1;o--){
    for(k=2;k<o;k++){
      digitalWrite(k, HIGH);
      delay(500);
      digitalWrite(k, LOW);
      delay(500);
    }
    digitalWrite(o, HIGH);
    delay(500);
  }
  for(l=2;l<8;l++){
    if(l==2){
      digitalWrite(l, LOW);
      delay(500);
    }
    else{
      digitalWrite(l, LOW);
      delay(500);
      for(i=l-1;i>1;i--){
        digitalWrite(i, HIGH);
        delay(500);
        digitalWrite(i, LOW);
        delay(500);
      }
    }
  }
}
