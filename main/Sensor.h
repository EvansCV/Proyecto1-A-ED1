#ifndef SENSOR_H
#define SENSOR_H

#include "Componente.h"
#include <Arduino.h>

class Sensor : public Componente {
public:
    Sensor(int pin);
    void iniciar() override;
    int leer() override;
    void escribir(int valor) override;
};

#endif


