//
// Created by lopez on 05-10-2024.
//

#ifndef LISTANEXOSIMPLE_H
#define LISTANEXOSIMPLE_H

#pragma once
#include "ficha.h"
#include "Nodo.h"

class ListaNexoSimple{
private:
    Nodo* head;                     //Puntero al inicio
public:
    ListaNexoSimple();              //Constructor
    ListaNexoSimple(Nodo* n);       //Constructor con nodo inicial
    Nodo* getHead();                //Aca se obtiene el inicial
    void setHead(Nodo* n);          //Establece el nodo indicado como el inicial
    // void agregar(int x);            //Se agrega un elemento nuevo
    void agregarFicha(Ficha* ficha);

    ~ListaNexoSimple();             //Destructor

};

#endif //LISTANEXOSIMPLE_H
