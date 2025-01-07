#include "LED.h"
#include "Sensor.h"
#include "Pantalla.h"
#include "Boton.h"


// Creación de instancias.
Pantalla lcd(8, 7, 10, 11, 12, 13);
Sensor fotoresistencia(A0);
LED ledRGB1(16, 17, 18); // Patio trasero
LED ledRGB2(19, 20, 21); // Patio frontal
LED ledRGB3(22, 23, 24); // Cuartos
LED ledRGB4(25, 26, 27); // Sala
LED ledRGB5(28, 29, 30); // Cocina
LED ledRGB6(31, 32, 33); // Traga luz
Boton botonModoIlAuto(34);
Boton botonCambiarModo(35); 
Boton botonPatioT(36);
Boton botonPatioF(37);
Boton botonCuarto(38);
Boton botonSala(39);
Boton botonCocina(40);
Boton botonPatioInt(41);


// Constantes 

bool modoIlAuto = false; // Variable que define si la iluminación será automática o no.
int valorModo = 0; // Esta define el modo, será cambiada cuando el botón correspondiente se presione.
String stringModo = "Apagado";
LED* ledsRGB[] = {&ledRGB1, &ledRGB2, &ledRGB3, &ledRGB4, &ledRGB5, &ledRGB6};
Boton* botonesHabitaciones[] = {&botonPatioT, &botonPatioF, &botonCuarto, &botonSala, &botonCocina, &botonPatioInt};
const int numLeds = sizeof(ledsRGB) / sizeof(ledsRGB[0]); // Número de LEDs en el arreglo.
const int numBotones = sizeof(botonesHabitaciones) / sizeof(botonesHabitaciones[0]); // Número de LEDs en el arreglo.
unsigned long lastDebounceTimes[numBotones] = {0}; // Array utilizado en el debounce


// Función para setear un único color a todas las LED, se utilizará más adelante.
void setColorFAL(int red, int green, int blue){
  for (int i = 0; i < 6; i++) {
    ledsRGB[i]->escribir(red, green, blue);
  }
}


// Alternar entre el modo automático y manual
void cambiarModoIlAuto() {
    if (debounce(&botonModoIlAuto, 0)) {
        modoIlAuto = !modoIlAuto; // Cambiar entre automático y manual
    }
}


// Función que determina la cantidad de LEDs que están encendidos.
int cantidadLEDOn() {
    int quantity = 0;
    for (int i = 0; i < numLeds; i++) {
        if (ledsRGB[i]->encendido()) {
            quantity++;
        }
    }
    return quantity;
}


// Esta función ajusta el brillo de los LEDs según la cantidad de luz detectada por la fotoresistencia.
void ajustarBrilloSegunLuz() {
    int valorFotoresistencia = fotoresistencia.leer();
    int brillo = map(valorFotoresistencia, 1023, 0, 255, 0);
    for (int i = 0; i < numLeds; i++) {
        ledsRGB[i]->escribir(brillo, brillo, brillo);
    }
}


// Función de debounce, para evitar los rebotes al presionar un botón.
bool debounce(Boton* boton, int index) {
     unsigned long currentTime = millis();
     if (currentTime - lastDebounceTimes[index] > 50) {
         lastDebounceTimes[index] = currentTime;
         return boton->leer() == LOW;
     }
     return false;
 }


void cambiarModo() {
  if (botonCambiarModo.leer() == LOW) {
    delay(700);
    if (valorModo != 4) {
      valorModo ++;
    }
    else {
      valorModo = 0;
    }
  } 
}


// Función que define los modos de iluminación.
void modo() {
  cambiarModo();
  if (valorModo == 1) {
    stringModo = "Noche";
    // LEDs de color morado para el modo noche, junto con un largo período de parpadeo.
    ledRGB1.escribir(0, 255, 0);
    ledRGB2.escribir(0, 255, 0);
    ledRGB3.escribir(255, 255, 255);
    ledRGB4.escribir(255, 255, 255);
    ledRGB5.escribir(255, 255, 255);
    ledRGB6.escribir(0, 255, 0);

  } else if (valorModo == 2) {
    stringModo = "Lectura";
    // LEDs de color amarillo para el modo lectura.
    setColorFAL(0, 0, 255);

  } else if (valorModo == 3) {
    stringModo = "Fiesta";
    // Colores rojos para el modo Fiesta.
    ledRGB1.escribir(255, 255, 255);
    ledRGB2.escribir(255, 255, 255);
    ledRGB3.parpadear(0, 255, 255, 1000);
    ledRGB4.parpadear(0, 255, 255, 1000);
    ledRGB5.parpadear(0, 255, 255, 1000);
    ledRGB6.escribir(255, 255, 255);


  } else if (valorModo == 4) {
    stringModo = "Relajación";
    // Colores cian para el modo relajación.
    setColorFAL(255, 0, 0);

  } else if (valorModo == 0) {
    stringModo = "Apagado";
    // Todo apagado.
    setColorFAL(255, 255, 255);
  }
}


void setup() {
// Inicializar la pantalla.
  lcd.iniciar();
// Inicializar cada LED.
  for (int i = 0; i < numLeds; i++) {
    ledsRGB[i]->iniciar();
}
// Inicializar cada botón
for (int i = 0; i < numBotones; i++) {
    botonesHabitaciones[i]->iniciar();
}
// Inicializar fotoresistencia y otros botones.
  fotoresistencia.iniciar();
  botonModoIlAuto.iniciar();
  botonCambiarModo.iniciar();
}    


// Función para apagar y encender luces de forma manual.
void lucesManual() {
  // Para cada modo
  // Modo apagado
  if (valorModo == 0) {
    // Cada LED, en este caso si se enciende cada led debería quedar blanca, al encenderse.
    for (int i = 0; i < 6; i++) {
      if (botonesHabitaciones[i]->leer() == LOW) {
        if (ledsRGB[i]->encendido()) {
          ledsRGB[i]->apagar();
        } else {
          ledsRGB[i]->escribir(0, 0, 0);
        }
      }
    }
  } else if (valorModo == 1){ // Morado para el modo noche
    for (int i = 0; i < 6; i++) {
      if (botonesHabitaciones[i]->leer() == LOW) {
        if (ledsRGB[i]->encendido()) {
          ledsRGB[i]->apagar();
        } else {
          ledsRGB[i]->escribir(0, 255, 0);
        }
      }
    }
  } else if (valorModo == 2){ // Amarillo para el modo lectura.
    for (int i = 0; i < 6; i++) {
      if (botonesHabitaciones[i]->leer() == LOW) {
        if (ledsRGB[i]->encendido()) {
          ledsRGB[i]->apagar();
        } else {
          ledsRGB[i]->escribir(0, 255, 0);
        }
      }
    }
  } else if (valorModo == 3) { // Rojo para el modo fiesta.
    for (int i = 0; i < 6; i++) {
      if (botonesHabitaciones[i]->leer() == LOW) {
        if (ledsRGB[i]->encendido()) {
          ledsRGB[i]->apagar();
        } else {
          ledsRGB[i]->parpadear(0, 255, 255, 1000);
        }
      }
    }
  } else if (valorModo == 4) { // Cian para el modo relajación.
    for (int i = 0; i < 6; i++) {
      if (botonesHabitaciones[i]->leer() == LOW) {
        if (ledsRGB[i]->encendido()) {
          ledsRGB[i]->apagar();
        } else {
          ledsRGB[i]->escribir(255, 0, 0);
        }
      }
    }
  }
}


void loop() {
  cambiarModoIlAuto();
  if (valorModo == 3) {
    lcd.imprimirPantalla(fotoresistencia, stringModo, 3); // Desplegar info en la pantalla del LCD.
  } else if (!modoIlAuto) {
    lcd.imprimirPantalla(fotoresistencia, stringModo, cantidadLEDOn()); // Desplegar info en la pantalla del LCD.
  }
  if (!modoIlAuto) {
    // Se activarán los modos de iluminación tomando en cuenta que se tiene activo el modo manual.
    modo(); 
    lucesManual();
  }
  else { // En este caso las LEDs son iluminadas de forma automática gracias a la fotoresistencia.
    ajustarBrilloSegunLuz();
    lcd.imprimirPantalla(fotoresistencia, "Auto", cantidadLEDOn());
  }
  delay(200);
}



