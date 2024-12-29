#ifndef COMPONENTE_H
#define COMPONENTE_H

class Componente {
protected:
    int pin;

public:
    Componente(int pin) : pin(pin) {}
    virtual void iniciar() = 0;
    virtual int leer() = 0;
    virtual void escribir(int valor) = 0;
    virtual ~Componente() {}
};

#endif
