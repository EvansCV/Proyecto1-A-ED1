#include "Pantalla.h"

Pantalla::Pantalla(int rs, int en, int d4, int d5, int d6, int d7)
    : Componente(-1), lcd(rs, en, d4, d5, d6, d7), 
      previousMillis(0), interval(2000), pantallaActual(0), nivelLuz("Alta"),
      modo("Fiesta"), numLeds(5), luz("Nivel de luz"), estadoModo("Modo Actual"),
      cantidadLeds("Num de Leds") {}

void Pantalla::iniciar() {
    lcd.begin(16, 2); // Para iniciar la pantalla con 16 columnas y 2 filas.
    lcd.clear(); // Limpia la pantalla.
    Serial.begin(9600); 
}

int Pantalla::leer() {
    return 0; // No aplicable
}

void Pantalla::escribir(int valor) {
    lcd.clear();
    lcd.print(valor);
}

void Pantalla::imprimirPantalla(Sensor fotoresistencia) {

  // Leer luz de forma análoga
  int light = fotoresistencia.leer();

  // Determinar el nivel de luz.
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

    // Mostrar pantalla de forma cíclica
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
  delay(100); // Pequeño delay para suavizar la lectura del sensor

}



