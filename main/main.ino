#include "LED.h"
#include "Sensor.h"
#include "Pantalla.h"
#include "Boton.h"

// Creación de instancias.
Pantalla lcd(8, 7, 10, 11, 12, 13);
Sensor fotoresistencia(A0);

void setup() {
  lcd.iniciar();
}

void loop() {
  lcd.imprimirPantalla(fotoresistencia); // Desplegar info en la pantalla del LCD.
  
}

