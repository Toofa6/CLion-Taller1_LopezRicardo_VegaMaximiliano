#include "ficha.h"

#include <iostream>
#include <string>

    //Constructor
    Ficha::Ficha(std::string subClase, int vida, int ataque, int defensa, int rango)
        : subClase(subClase), vida(vida), ataque(ataque),defensa(defensa),rango(rango),habilidadEspecialUsada(false){}


//Metodos para los stats de las fichas

    std::string Ficha::getSubClase() const{
        return subClase;
    }

    int Ficha::getVida() const {
    return vida;
    }

    int Ficha::getAtaque() const{
        return ataque;
    }

    int Ficha::getDefensa() const{
        return defensa;
    }

    int Ficha::getRango()const {
        return rango;
    }

    bool Ficha::getHabilidadEspecialUsada() const{
        return habilidadEspecialUsada;
    }



    //Recordar que se utiliza cantidad para la cantidad de daño recibida
    void Ficha::recibirDaño(int cantidad) {
        vida -= cantidad;
        if(vida <= 0) {
            vida = 0;
            std::cout << subClase << " se desmayo " << std::endl;

        } else {
            std::cout << subClase << "recibe "<< cantidad << " puntos de daño, tiene " << vida << " de hp restante" << std::endl;
        }
    }


    //Metodo para atacar
    void Ficha::atacar(Ficha* objetivo) {
        if (objetivo->getVida() > 0) {
            int daño = ataque; // Daño básico
            if (subClase == "Mago") {   // Mago ignora armadura

                objetivo->recibirDaño(daño);
            } else {
                // la formula es daño - armadura
                int dañoReal = daño - objetivo->getDefensa();
                dañoReal = dañoReal > 0 ? dañoReal : 0; // No queremos daños negativos
                objetivo->recibirDaño(dañoReal);
            }
        } else {
            std::cout << objetivo->getSubClase() << " ya esta desmayado." << std::endl;
        }


    }

    //Metodo para mostrar fichas
    void Ficha::mostrarFicha() const {
        std::cout << "Ficha: " << subClase << ", Vida: " << vida << ", Ataque: " << ataque << ", Defensa: " << defensa << ", Rango: " << rango << std::endl;
    }


    //Destructor
    Ficha::~Ficha() {

    }

void Ficha::usarHabilidadEspecial(Ficha* objetivo, std::vector<Ficha*>& enemigos) {
        if (habilidadEspecialUsada) {
            std::cout << "La habilidad especial ya ha sido usada." << std::endl;
            return;
        }

        if(subClase == "Arquero") {
            int daño = static_cast<int>(ataque * 1.5);  // la habilidad hace %150 de daño
            objetivo->recibirDaño(daño); // Daño para el objetivo principal a atacar
            std::cout << "El arquero ataca a " << objetivo->getSubClase() << "causandole " << daño << " de daño!!" << std::endl;

            // Daño a enemigos adjayencetes
            for(Ficha* enemigo : enemigos) {
                //aca falta la logica para esto

                /*
                if () {//aca va la logica para que reciban los adyacentes daño
                    enemigo->recibirDaño(daño);
                    std::cout << "El Arquero ataca a " << enemigo->getSubClase() << " causandole " << daño << " de daño!!" << std::endl;
                } */

            }
        } else if(subClase == "Mago") {
            int daño =static_cast<int>(ataque * 1.5); //la habilidad hace 150% de daño
            objetivo->recibirDaño(daño); // daño al objetivo principal
            std::cout << "El Mago ataca a " << objetivo->getSubClase() << " causandole " << daño << " de daño!!" << std::endl;

            //Daño a enemigos diagonales siguiendo el taller
            for(Ficha* enemigo : enemigos) {
                //Falta la logica de como funcioan esto

                /*
                if () {//aca va la logica para que reciban los diagonaless daño
                    enemigo->recibirDaño(daño);
                    std::cout << "El Mago ataca a " << enemigo->getSubClase() << " causandole " << daño << " de daño!!" << std::endl;
                } */

            }

        } else if(subClase == "Tanque") {
            //Logica de menos daño
            std::cout << "El tanque activa su escudo reducionde el daño por 70% en un turno";


        } else if(subClase == "Espadachin") {
            int daño = static_cast<int>(ataque * 2.5); // 250% de daño
            objetivo->recibirDaño(daño);
            std::cout << "El Espadachin ataca a " << objetivo->getSubClase() << " ignorando su defensa y causandole " << daño << " de daño!!." << std::endl;

        }
        habilidadEspecialUsada = true; // Para que no vuelvan a utilizar las habilidades las fichas
    }