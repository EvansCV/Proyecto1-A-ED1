#include "LED.h"
#include "Sensor.h"
#include "Pantalla.h"
#include "Boton.h"

// Creación de instancias.
Pantalla lcd(8, 7, 10, 11, 12, 13);
Sensor fotoresistencia(A0);
LED ledRGB1(16, 17, 18);
LED ledRGB2(19, 20, 21);
LED ledRGB3(22, 23, 24);
LED ledRGB4(25, 26, 27);
LED ledRGB5(28, 29, 30);
LED ledRGB6(31, 32, 33);

// Constantes 

int valorModo = 0; // Esta define el modo, será cambiada según el botón que sea presionado.


void setup() {
  lcd.iniciar();
  ledRGB1.iniciar();
  ledRGB2.iniciar();
  ledRGB3.iniciar();
  ledRGB4.iniciar();
  ledRGB5.iniciar();
  ledRGB6.iniciar();

}

void loop() {
  lcd.imprimirPantalla(fotoresistencia); // Desplegar info en la pantalla del LCD.
  // Se activarán los modos de iluminación tomando en cuenta que se tiene activo el modo manual.
}

void modo(int modo) {
  if (modo == 1) {
    modoNoche();
  } else if (modo == 2) {
    modoLectura();
  } else if (modo == 3) {
    modoFiesta();
  } else if (modo == 4) {
    modoRelajacion();
  }

}


// LEDs de color morado para el modo noche, junto con un largo período de parpadeo.
void modoNoche() {
  ledRGB1.parpadear(255, 0, 255, 5000);
  ledRGB2.parpadear(255, 0, 255, 5000);
  ledRGB3.parpadear(255, 0, 255, 5000);
  ledRGB4.parpadear(255, 0, 255, 5000);
  ledRGB5.parpadear(255, 0, 255, 5000);
  ledRGB6.parpadear(255, 0, 255, 5000);
}


// LEDs de color amarillo y blanco para el modo lectura.
void modoLectura() {
  ledRGB1.escribir(255, 255, 255);
  ledRGB2.escribir(255, 255, 0);
  ledRGB3.escribir(255, 255, 0);
  ledRGB4.escribir(255, 255, 0);
  ledRGB5.escribir(255, 255, 255);
  ledRGB6.escribir(255, 255, 0);
}


// Colores rojos, azul y morado para el modoFiesta.
void modoFiesta() {
  ledRGB1.parpadear(0, 0, 255, 1000);
  ledRGB2.parpadear(255, 0, 0, 1000);
  ledRGB3.parpadear(255, 0, 255, 1000);
  ledRGB4.parpadear(0, 0, 255, 1000);
  ledRGB5.parpadear(255, 0, 0, 1000);
  ledRGB6.parpadear(255, 0, 255, 1000);
}

// Colores cian y blanco para el modo relajación.
void modoRelajacion() {
  ledRGB1.escribir(255, 255, 255);
  ledRGB2.escribir(0, 255, 255);
  ledRGB3.escribir(0, 255, 255);
  ledRGB4.escribir(255, 255, 255);
  ledRGB5.escribir(255, 255, 255);
  ledRGB6.escribir(0, 255, 255);
}
