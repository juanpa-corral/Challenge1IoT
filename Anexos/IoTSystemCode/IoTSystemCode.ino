#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 7, 8, 9, 10);

int TRIG_PIN = 13;
int ECHO_PIN = 12;
int LED_PIN = 6;
int LED_PIN2 = 5;
int LED_PIN3 = 4;
int ALERT = 11;
int INTERRUPTOR_PIN = A0;  // Cambié el pin 1 por A0 para evitar interferencias

long duration;
int distance;
bool lluvia = false;

void setup() {
    lcd.begin(16, 2); // Configura el LCD de 16x2
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_PIN2, OUTPUT);
    pinMode(LED_PIN3, OUTPUT);
    pinMode(ALERT, OUTPUT);
    pinMode(INTERRUPTOR_PIN, INPUT_PULLUP); // Activa resistencia pull-up para el interruptor
  
    Serial.begin(9600);
  
    lcd.setCursor(0, 0);
    lcd.print("Distancia: ");
}

void loop() {
    // Lectura del sensor ultrasónico
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(10);

    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034 / 2;

    // Verificar estado del interruptor (simula sensor de lluvia)
    lluvia = (digitalRead(INTERRUPTOR_PIN) == LOW);

    // Mostrar distancia en el LCD
    lcd.setCursor(10, 0);
    lcd.print("    ");    
    lcd.setCursor(10, 0);
    lcd.print(distance);
    lcd.print("cm");

    // Lógica de LEDs y mensajes de advertencia
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpia la línea

    if (distance < 4) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN2, LOW);
        digitalWrite(LED_PIN3, LOW);
        digitalWrite(ALERT, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("PELIGRO");
    } else if (distance >= 4  && distance <= 8) {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, HIGH);
        digitalWrite(LED_PIN3, LOW);
        digitalWrite(ALERT, LOW);
        lcd.setCursor(0, 1);
        lcd.print("PRECAUCION");
    } else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, LOW);
        digitalWrite(LED_PIN3, HIGH);
        digitalWrite(ALERT, LOW);
        lcd.setCursor(0, 1);
        lcd.print("SEGURO");
    }
    if (lluvia) {
        lcd.print(" LLUVIA");
    }

    delay(700);  // Aumenta el tiempo de ciclo para mejor visibilidad
}