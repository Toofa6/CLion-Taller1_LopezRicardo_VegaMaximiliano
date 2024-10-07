#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "ficha.h"
#include "ListaNexoSimple.h"
#include "tablero.h"


//Funciones menu
void menuPrincipal(Tablero& tableroJugador, Tablero& tableroEnemigo, std::vector<Ficha*>& listaFichas);
void comenzarCombate(Tablero& tableroJugador, Tablero& tableroEnemigo, std::vector<Ficha*>& listaFichas);
void cambiarFichas(std::vector<Ficha*>& listaFichas);
void cambiarPosicionFichas(Tablero& tableroJugador);
void menuEstadisticas();



int main() {

    Tablero tableroJugador(4,3);
    Tablero tableroEnemigo(4,3);


    //Aca se leen las fichas, esto es funcional pero creo que dependiente de la ubicacion del archivo "fichas.txt"
    std::ifstream archivoFichas("C:/Users/maxi_/Desktop/Taller1EstructuraDeDatosw/fichas.txt");
    if (!archivoFichas.is_open()) {
        std::cout <<"Error al abrir el archivo" << std::endl;
        return 1;
    }
        std::vector<Ficha*> listaFichas;
        std::string linea;

        // Leer el archivo línea por línea
        while (std::getline(archivoFichas, linea)) {
            std::cout << "Leyendo linea: " << linea << std::endl;

            std::stringstream ss(linea);
            std::string subClase;
            int vida;
            int ataque;
            int defensa;
            int rango;

            // Separar los campos
            if (std::getline(ss, subClase, ',') && (ss >> vida).ignore() && (ss >> ataque).ignore() && (ss >> defensa).ignore() && (ss >> rango)) {

                Ficha* nuevaFicha = new Ficha(subClase, vida, ataque, defensa, rango);
                listaFichas.push_back(nuevaFicha);

                // Con esto verificamos que se crea correctamente una linea despues de leerla
                std::cout << "Ficha creada: " << subClase << " " << vida << " " << ataque << " " << defensa << " " << rango << std::endl;
                } else {
                    std::cout << "Error al leer los datos de la línea: " << linea << std::endl;
                }
        }

        // Mostrar las fichas
        for (Ficha* ficha : listaFichas) {
            ficha->mostrarFicha();
        }

        archivoFichas.close();



    //Aca se leen los escenarios

    std::ifstream archivoEscenarios("C:/Users/maxi_/Desktop/Taller1EstructuraDeDatosw/escenarios.txt");
    if (!archivoEscenarios.is_open()) {
        std::cout << "Error al abrir el archivo de escenarios" << std::endl;
        return 1;
    }

    std::string escenario;
    while (std::getline(archivoEscenarios, escenario)) {
        if (escenario.find("Escenario") != std::string::npos) {
            std::cout << "Leyendo " << escenario << std::endl;

            std::string cabecera;
            std::getline(archivoEscenarios, cabecera); // Leer la línea de orden "Ficha,Fila,Columna"

            // confirmar
            if (cabecera.empty() || cabecera != "Ficha,Fila,Columna") {
                std::cout << "Error: orden no valido " << cabecera << std::endl;
                continue; // Sigue leyendo la sigueinte
            }

            // Mostrar contenido del escenario
            std::cout << escenario << std::endl;

            // Leer las lineas que contienen la info
            while (std::getline(archivoEscenarios, linea)) {
                if (linea.empty() || linea.find("Escenario") != std::string::npos) { // si esta vacia continua
                    archivoEscenarios.seekg(-linea.length() - 1, std::ios_base::cur); // regresar al ptunero
                    break;
                }

                std::stringstream ss(linea);
                std::string subClaseFicha;
                int fila, columna;

                // espacio entre campos
                if (std::getline(ss, subClaseFicha, ',') &&
                    (ss >> fila).ignore() &&
                    (ss >> columna)) {

                    // Mostrar lo leido
                    std::cout << "  " << subClaseFicha << "," << fila << "," << columna << std::endl;

                    // Buscar la ficha en listaFichas y colocarla en el tablero
                    for (Ficha* ficha : listaFichas) {
                        if (ficha->getSubClase() == subClaseFicha) {
                            tableroJugador.colocarFicha(ficha, fila - 1, columna - 1);
                            break;
                        }
                    }
                } else {
                    std::cout << "Error al leer los datos: " << linea << std::endl;
                }
            }
        }
    }

    archivoEscenarios.close();

    std::cout << "iniciando el juego" << std::endl;
    menuPrincipal(tableroJugador, tableroEnemigo, listaFichas); // Llamar al menú principal

    for (Ficha *ficha : listaFichas) {
        delete ficha;
    }

    return 0;
}




//Funcion menu principal, utilizar numeros para navegar
void menuPrincipal(Tablero &tableroJugador, Tablero &tableroEnemigo, std::vector<Ficha *> &listaFichas) {
    int opcion;
    do {
        std::cout << "  " << std::endl;
        std::cout << ".................Menu Principal..................." << std::endl;
        std::cout << "1) Comenzar combate" << std::endl;
        std::cout << "2) Cambiar fichas del equipo" << std::endl;
        std::cout << "3) Cambiar pposicion de las fichas" << std::endl;
        std::cout << "4) Menu estadisticas" << std::endl;
        std::cout << "5) Cerrar juego" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                comenzarCombate(tableroJugador,tableroEnemigo,listaFichas);
                break;
            case 2:
                cambiarFichas(listaFichas);
                break;
            case 3:
                cambiarPosicionFichas(tableroJugador);
                break;
            case 4:
                menuEstadisticas();
                break;
            case 5:
                std::cout <<"Cerrando el juego" << std::endl;
                break;
            default:
                std::cout << "Opcion no valida, intenta otra opcion";
                break;

        }
    }  while (opcion != 5);
}




void comenzarCombate(Tablero &tableroJugador, Tablero &tableroEnemigo, std::vector<Ficha *> &listaFichas) {
    std::cout << "Comenzando combate...";
}

void cambiarPosicionFichas(Tablero& tableroJugador) {
    std::cout << "Cambiando posicion de las fichas...";

}

void menuEstadisticas() {
    std::cout << "Mostrando estadisticas...";

}

void cambiarFichas(std::vector<Ficha*>& listaFichas) {
    std::cout << "Cambiando fichas del equipo...";

    for (int i = 0; i < listaFichas.size(); ++i) {
        std::cout << i + 1 << ") " << listaFichas[i]->getSubClase() << std::endl;
    }

    std::cout << "Ingrese el numero de la ficha que desea cambiar: ";
    int index;
    std::cin >> index;

    if (index > 0 && index <= listaFichas.size()) {
        std::cout << "Cambiando la ficha " << listaFichas[index - 1]->getSubClase() << std::endl;
        // FALTA LA LOGICA ACA
    } else {
        std::cout << "Opcion no valida.\n";
    }
}



