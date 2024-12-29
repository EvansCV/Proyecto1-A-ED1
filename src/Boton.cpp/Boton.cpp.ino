#include "Boton.h"

Boton::Boton(int pin) : Componente(pin) {}

void Boton::iniciar() {
    pinMode(pin, INPUT_PULLUP);
}

int Boton::leer() {
    return digitalRead(pin);
}

void Boton::escribir(int valor) {
    // No implementado
}
