//
// Created by lopez on 05-10-2024.
//

#include "tablero.h"

#include <iostream>

//Constructor
Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    matriz = new ListaNexoSimple*[filas]; // Filas
    for (int i = 0; i < filas; i++) {
        matriz[i] = new ListaNexoSimple[columnas]; // Colunmas
    }
}

void Tablero::colocarFicha(Ficha* ficha, int fila, int columna) {
    if (!estaBloqueado(fila, columna)) {
        matriz[fila][columna].agregarFicha(ficha); // Agregar la ficha en la lista correspondiente
    } else {
        std::cout << "La posición está bloqueada." << std::endl;
    }
}

void Tablero::eliminarFicha(int fila, int columna) {
    matriz[fila][columna].setHead(nullptr); // Eliminar la ficha (puedes implementar lógica más específica)
}

bool Tablero::estaBloqueado(int fila, int columna) {
    return matriz[fila][columna].getHead() != nullptr; // Retorna true si hay una ficha ocupando el espacio
}

//Destructor
Tablero::~Tablero() {
}