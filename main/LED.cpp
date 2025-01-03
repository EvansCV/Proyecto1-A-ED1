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
        escribir(0, 0, 0); // Apagar
    } else if (valor == 1) {
        escribir(255, 0, 0); // Rojo
    } else if (valor == 2) {
        escribir(0, 255, 0); // Verde
    } else if (valor == 3) {
        escribir(0, 0, 255); // Azul
    }
}

void LED::escribir(int valorR, int valorG, int valorB) {
    analogWrite(pinR, valorR); // Escribir al canal rojo
    analogWrite(pinG, valorG); // Escribir al canal verde
    analogWrite(pinB, valorB); // Escribir al canal azul
}

int LED::leer() {
    return -1; // No aplicable
}

void LED::apagar() {
    analogWrite(pinR, 0);
    analogWrite(pinG, 0);
    analogWrite(pinB, 0);
}

void LED::parpadear(int red, int green, int blue, int intervalo) {
  escribir(red, green, blue);  // Encender LED con el color especificado
  delay(intervalo);
  escribir(0, 0, 0);
  delay(intervalo);
}


