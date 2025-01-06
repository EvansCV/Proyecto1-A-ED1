#ifndef PANTALLA_H
#define PANTALLA_H

#include "Componente.h"
#include <LiquidCrystal.h>
#include <Arduino.h>
#include "Sensor.h"

class Pantalla : public Componente {
private:
    LiquidCrystal lcd;
    unsigned long previousMillis;
    const long interval;
    int pantallaActual; 

    // Variables (CAMBIAR ESTOS VALORES PARA SABER EN QUE ESTÁ)
    String nivelLuz;      // Nivel de luz inicial
    String modo;        // Modo inicial
    int numLeds;               // Número de LEDs encendidos

    // Variables (ESTE ES EL ENCABEZADO)
    String luz;
    String estadoModo;
    String cantidadLeds;


public:
    Pantalla(int rs, int en, int d4, int d5, int d6, int d7);
    void iniciar() override;
    int leer() override;
    void escribir(int valor) override;
    void imprimirPantalla(Sensor fotoresistencia, String modo, int numLeds);
};
#endif

