#include "LED.h"

LED::LED(int pin) : Componente(pin) {}

void LED::iniciar() {
    pinMode(pin, OUTPUT);
}

int LED::leer() {
    return digitalRead(pin);
}

void LED::escribir(int valor) {
    digitalWrite(pin, valor);
}
