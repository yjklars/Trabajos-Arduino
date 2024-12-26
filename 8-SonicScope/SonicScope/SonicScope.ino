#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 2, 1, 0 , 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7

int TRIG = 10;
int ECO = 9;
int BUZZ = 3;
int DURACION;
int DISTANCIA;

void setup() {
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH); //obtiene el tiempo desde la emisión del pulso ultrasónico hasta la recepción del mismo
  DISTANCIA = DURACION / 58.2;  //58.2 es una cte especificada por el fabricante que permite obtener la distancia del pulso
  delay(200);
  if (DISTANCIA > 40) {
    lcd.clear();
  }
  else if (DISTANCIA <= 40 && DISTANCIA >= 5) {
    lcd.setCursor(0, 0);
    lcd.print("Current Distance");
    lcd.setCursor(0, 1);
    lcd.print(String(DISTANCIA) + " cm      ");
    digitalWrite(BUZZ, HIGH);
    delay(50);
    digitalWrite(BUZZ, LOW);
    delay(DISTANCIA * 10);
  }
  else if (DISTANCIA < 5 && DISTANCIA >= 0) {
    lcd.setCursor(0, 0);
    lcd.print("STOP            ");
    lcd.setCursor(0, 1);
    lcd.print(String(DISTANCIA) + " cm      ");
    digitalWrite(BUZZ, HIGH);
  }
  else {
    digitalWrite(BUZZ, LOW);
  }
}
