int LED = 7;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(3000);
  digitalWrite(LED, LOW);
  delay(3000);
}
