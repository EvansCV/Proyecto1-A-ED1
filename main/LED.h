#ifndef LED_H
#define LED_H

#include "Componente.h"
#include <Arduino.h>

// Clase que corresponde a los LED RGB.
class LED : public Componente {
private:
  int pinR; // Pin para el canal rojo
  int pinG; // Pin para el canal verde
  int pinB; // Pin para el canal azul
  // Estado para cada uno de las canales
  int stateR;
  int stateG;
  int stateB;

public:
    LED(int pinR, int pinG, int pinB);
    void iniciar() override;
    int leer() override;
    // Método que hereda de la clase componente
    void escribir(int valor) override; 
    // Método propio de la clase, este es para setear los colores de cada LED
    void escribir(int valorR, int valorG, int valorB); // Ajustar brillo o color.
    void apagar(); // Apagar el LED
    // Se necesitan los valores de los colores en los parámetros debido a que en este caso ya que se desconocen los valores de los colores
    void parpadear(int red, int green, int blue, int intervalo); 
    // Esta función sirve para determinar si el LED está encendido o no.
    bool encendido();

};
#endif
