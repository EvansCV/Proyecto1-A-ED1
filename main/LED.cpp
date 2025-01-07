#include "LED.h"

LED::LED(int pinR, int pinG, int pinB) 
    : Componente(-1), pinR(pinR), pinG(pinG), pinB(pinB) {}


void LED::iniciar() {
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
    apagar(); // Asegurarse de iniciar apagado
}

void LED::escribir(int valor) {
    // Implementación requerida por la clase base, por ejemplo:
    // Encender un color básico dependiendo del valor recibido
    if (valor == 0) {
        escribir(255, 255, 255); // Apagar
    } else if (valor == 1) {
        escribir(0, 255, 255); // Rojo
    } else if (valor == 2) {
        escribir(255, 0, 255); // Verde
    } else if (valor == 3) {
        escribir(255, 255, 0); // Azul
    }
}

void LED::escribir(int valorR, int valorG, int valorB) {
    analogWrite(pinR, valorR); // Escribir al canal rojo
    analogWrite(pinG, valorG); // Escribir al canal verde
    analogWrite(pinB, valorB); // Escribir al canal azul

    stateR = valorR;
    stateG = valorG;
    stateB = valorB;
}


bool LED::encendido() {
  return (stateR < 255 || stateG < 255 || stateB < 255);
}


int LED::leer() {
    return -1; // No aplicable
}

void LED::apagar() {
    analogWrite(pinR, 255);
    analogWrite(pinG, 255);
    analogWrite(pinB, 255);

    stateR = 255;
    stateG = 255;
    stateB = 255;
}

void LED::parpadear(int red, int green, int blue, int intervalo) {
  escribir(red, green, blue);  // Encender LED con el color especificado
  delay(intervalo);
  escribir(255, 255, 255);
  delay(intervalo);
}




