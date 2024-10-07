//
// Created by lopez on 05-10-2024.
//

#ifndef TABLERO_H
#define TABLERO_H

#include "listaNexoSimple.h"


class Tablero {
    private:
    ListaNexoSimple** matriz;
    int filas;
    int columnas;

    public:
    Tablero(int filas, int columnas);
    void colocarFicha(Ficha* ficha,int fila, int columna);
    void eliminarFicha(int fila, int columna);
    bool estaBloqueado(int fila, int columna);

    //Destructor
    ~Tablero();
};



#endif //TABLERO_H
