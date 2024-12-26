#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2)

#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);

byte LecturaUID[4];
byte Usuario1[4] = {0x7A, 0xEE, 0x17, 0x02}; //Brandon C 302 Card
byte Usuario2[4] = {0x53, 0xBC, 0xB8, 0x2C}; //Brandon C 302 Llavero
byte Usuario3[4] = {0x17, 0x07, 0x55, 0x86}; // Celeste S 302 Card
byte Usuario4[4] = {0x8A, 0x18, 0xDE, 0x00}; // Celeste S 302 Llavero
byte Usuario5[4] = {0x63, 0xA6, 0x2B, 0x28}; // Vicente J 302 Card 0x63, 0xA6, 0x2B, 0x28
byte Usuario6[4] = {0x13, 0x92, 0x47, 0x14}; // Vicente J 302 Llavero
byte Usuario7[4] = {0xF3, 0x1F, 0x12, 0xAD}; // Franco A 302 Card
byte Usuario8[4] = {0x64, 0x17, 0xCE, 0xCF}; // Franco A 302 Llavero
byte Usuario9[4] = {0x26, 0xB4, 0x7E, 0x00}; // Misael G 302 Card
byte Usuario10[4] = {0x07, 0x6F, 0x1F, 0x86}; // Misael G 302 Llavero
//byte Usuario5[4] = {0xE3, 0x2E, 0x81, 0xA7}; // Diego A 302 Card
//byte Usuario6[4] = {0x00, 0x00, 0x00, 0x00}; // Diego A 302 Llavero


unsigned long tiempoInicio = 0;    // Tiempo para controlar el inicio de los mensajes
unsigned long tiempoEspera = 500; // Tiempo de espera para procesar la tarjeta (0.5 segundos)
unsigned long tiempoMostrar = 3000; // Tiempo de duración del mensaje en pantalla (3 segundos)
bool esperando = false;            // Bandera para controlar el tiempo de espera
bool mostrandoMensaje = false;    // Bandera para saber si estamos mostrando un mensaje

void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  
  lcd.init();
  lcd.backlight();
  bienvenida();
}

void loop() {
  lcd.display();
  if (esperando) {
    if (millis() - tiempoInicio >= tiempoEspera) {
      esperando = false;
      procesarTarjeta();
    }
    return;
  }

  if (mostrandoMensaje) {
    if (millis() - tiempoInicio >= tiempoMostrar) {
      mostrandoMensaje = false;
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      bienvenida();
    }
    return;
  }

  // Verificar si hay una nueva tarjeta
  if (!mfrc522.PICC_IsNewCardPresent())
    return;
  if (!mfrc522.PICC_ReadCardSerial())
    return;

  // Leer el UID de la tarjeta
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    LecturaUID[i] = mfrc522.uid.uidByte[i];
  }

  // Iniciar la espera de 0.5 segundos
  tiempoInicio = millis();
  esperando = true;
  Serial.println("tiempoInicio");
}

void procesarTarjeta() {
  lcd.clear();
  if (comparaUID(LecturaUID, Usuario1)) {
    mostrarMensaje("Brandon C.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario2)) {
    mostrarMensaje("Brandon C.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario3)) {
    mostrarMensaje("Celeste S.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario4)) {
    mostrarMensaje("Celeste S.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario5)) {
    mostrarMensaje("Vicente J.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario6)) {
    mostrarMensaje("Vicente J.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario7)) {
    mostrarMensaje("Franco A.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario8)) {
    mostrarMensaje("Franco A.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario9)) {
    mostrarMensaje("Misael G.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else if (comparaUID(LecturaUID, Usuario10)) {
    mostrarMensaje("Misael G.", "Nivel 302");
    digitalWrite(7, HIGH);
  } else {
    mostrarMensaje("Usuario", "No autorizado!");
    digitalWrite(6, HIGH);
  }

  mfrc522.PICC_HaltA();
}

void bienvenida() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido!");
  lcd.setCursor(0, 1);
  lcd.print("Identifiquese");
  
}

void mostrarMensaje(String linea1, String linea2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1);
  lcd.setCursor(0, 1);
  lcd.print(linea2);

  // Guardar el tiempo en que se inició el mensaje
  tiempoInicio = millis();
  mostrandoMensaje = true;
}

boolean comparaUID(byte lectura[], byte usuario[]) {
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (lectura[i] != usuario[i])
      return false;
  }
  return true;
}
