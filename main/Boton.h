#ifndef BOTON_H
#define BOTON_H

#include "Componente.h"
#include <Arduino.h>

class Boton : public Componente {
public:
    Boton(int pin);
    void iniciar() override;
    int leer() override;
    void escribir(int valor) override;
};

#endif
