#ifndef LED_H
#define LED_H

#include "Componente.h"
#include <Arduino.h>

class LED : public Componente {
public:
    LED(int pin);
    void iniciar() override;
    int leer() override;
    void escribir(int valor) override;
};

#endif
