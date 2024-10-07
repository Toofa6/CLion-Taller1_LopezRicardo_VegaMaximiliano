#pragma once
#include "ficha.h"

class Nodo{
private:
    Ficha* ficha;
    Nodo* next;
public:
    Nodo(); // Constructor
    Nodo(Ficha* f); // Constructor que recibe un puntero a Ficha
    Nodo(Ficha* f, Nodo* n); // Constructor que recibe un puntero a Ficha y un puntero a Nodo

    Ficha* getFicha();
    Nodo* getNext();
    void setFicha(Ficha* f);
    void setNext(Nodo* n);

    ~Nodo(); // Destructor
};