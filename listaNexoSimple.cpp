#include "ListaNexoSimple.h"
#include <iostream>


ListaNexoSimple::ListaNexoSimple(){
    this->head = nullptr;
}

ListaNexoSimple::ListaNexoSimple(Nodo* n){
    this->head = n;
}

Nodo* ListaNexoSimple::getHead(){
    return this->head;
}

void ListaNexoSimple::setHead(Nodo* n){
    this->head = n;
}

/*
void ListaNexoSimple::agregar(int x){
    if(!this->head){
        this->head = new Nodo(x);
    }
    Nodo* aux = this->head;
    while(aux->getNext() != nullptr){
        aux = aux->getNext();
    }
    aux->setNext(new Nodo(x));
}
*/

ListaNexoSimple::~ListaNexoSimple() {
    Nodo* current = head;
    while (current != nullptr) {
        Nodo* next = current->getNext();
        delete current;  // Borra el nodo
        current = next;  // Avanza al siguiente nodo
    }
}

void ListaNexoSimple::agregarFicha(Ficha* ficha) {
    if (!this->head) {
        this->head = new Nodo(ficha); // Cambiar Nodo para aceptar un puntero a Ficha
    } else {
        Nodo* aux = this->head;
        while (aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        aux->setNext(new Nodo(ficha));
    }
}