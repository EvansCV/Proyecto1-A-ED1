#include "Sensor.h"

Sensor::Sensor(int pin) : Componente(pin) {}

void Sensor::iniciar() {
    pinMode(pin, INPUT);
}

int Sensor::leer() {
    return analogRead(pin);
}

void Sensor::escribir(int valor) {
    // No implementado, opcional según necesidades
}

