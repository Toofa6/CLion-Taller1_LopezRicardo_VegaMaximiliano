#include "Nodo.h"

Nodo::Nodo() {
    this->ficha = nullptr; // Inicializa ficha
    this->next = nullptr;
}

Nodo::Nodo(Ficha* f) {
    this->ficha = f; // Asigna puntero a Ficha
    this->next = nullptr;
}

Nodo::Nodo(Ficha* f, Nodo* n) {
    this->ficha = f; // Asigna puntero a Ficha
    this->next = n;
}

Ficha* Nodo::getFicha(){
    return this->ficha;
}

Nodo* Nodo::getNext(){
    return this->next;
}

void Nodo::setFicha(Ficha* f){
    this->ficha = f;
}

void Nodo::setNext(Nodo* n){
    this->next = n;
}

Nodo::~Nodo(){
    delete this->next;
}
