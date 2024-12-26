#include <LiquidCrystal.h>

int light;
unsigned long previousMillis = 0;  // Almacena el tiempo anterior
const long interval = 2000;        // Intervalo de 2 segundos para el LCD

// Configuración de LCD
LiquidCrystal lcd(8, 7, 10, 11, 12, 13);

// Variables (CAMBIAR ESTOS VALORES PARA SABER EN QUE ESTA)
String nivelLuz = "Alta";      // Nivel de luz inicial
String modo = "Fiesta";        // Modo inicial
int numLeds = 5;               // Número de LEDs encendidos

// Variables (ESTE ES EL ENCABEZADO)
String luz = "Nivel de Luz";
String estadoModo = "Modo Actual";
String cantidadLeds = "Num de Leds";

int pantallaActual = 0;  // Controla qué pantalla se muestra

void setup() {
  lcd.begin(16, 2);  // Inicializa LCD (16 columnas, 2 filas)
  lcd.clear();       // Limpia la pantalla
  Serial.begin(9600);
}

void loop() {
  // Leer luz de forma continua
  light = analogRead(A0);
  Serial.print("Luz detectada: ");
  Serial.println(light);

  // Determinar nivel de luz
  if (light < 200) {
    nivelLuz = "Baja";
  } else {
    nivelLuz = "Alta";
  }

  // Verificar si ha pasado el intervalo de 2 segundos
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Reiniciar el temporizador

    lcd.clear();  // Limpia la pantalla

    // Mostrar pantallas de forma cíclica
    if (pantallaActual == 0) {
      // Mostrar nivel de luz
      int espacios1 = (16 - luz.length()) / 2;
      lcd.setCursor(espacios1, 0);
      lcd.print(luz);
      int espacios2 = (16 - nivelLuz.length()) / 2;
      lcd.setCursor(espacios2, 1);
      lcd.print(nivelLuz);
    } else if (pantallaActual == 1) {
      // Mostrar modo
      int espacios3 = (16 - estadoModo.length()) / 2;
      lcd.setCursor(espacios3, 0);
      lcd.print(estadoModo);
      int espacios4 = (16 - modo.length()) / 2;
      lcd.setCursor(espacios4, 1);
      lcd.print(modo);
    } else if (pantallaActual == 2) {
      // Mostrar número de LEDs
      int espacios5 = (16 - cantidadLeds.length()) / 2;
      lcd.setCursor(espacios5, 0);
      lcd.print(cantidadLeds);

      String numLedsStr = String(numLeds);
      int espacios6 = (16 - numLedsStr.length()) / 2;
      lcd.setCursor(espacios6, 1);
      lcd.print(numLedsStr);
    }

    // Cambiar a la siguiente pantalla
    pantallaActual = (pantallaActual + 1) % 3;
  }

  delay(100);  // Pequeño delay para suavizar la lectura del sensor
}