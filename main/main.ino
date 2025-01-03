#include "LED.h"
#include "Sensor.h"
#include "Pantalla.h"
#include "Boton.h"

// Creación de instancias.
Pantalla lcd(8, 7, 10, 11, 12, 13);
Sensor fotoresistencia(A0);
LED ledRGB1(16, 17, 18);
LED ledRGB2(19, 20, 21);

void setup() {
  lcd.iniciar();
  ledRGB1.iniciar();
  ledRGB2.iniciar();
}

void loop() {
  lcd.imprimirPantalla(fotoresistencia); // Desplegar info en la pantalla del LCD.
  ledRGB1.escribir(255, 0, 0); // Setea el primer led en rojo.
  ledRGB2.escribir(255, 255, 255); // Setea el primer led en blanco.
  delay(2000);
  // Invertir colores de los leds.

  ledRGB1.escribir(255, 255, 255); // Setea el primer led en blanco.
  ledRGB2.escribir(255, 0, 0); // Setea el primer led en rojo.
  delay(2000);
}

