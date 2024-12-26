int boton = 8;
int led = 7;
int botonEstado;

void setup() {
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  botonEstado = digitalRead(boton);
  delay(100);
  if(botonEstado == 0)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
