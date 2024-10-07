#ifndef FICHA_H
#define FICHA_H
#include <string>
#include <vector>

class Ficha {
private:
    std::string subClase;           //Subclase de la ficha
    int vida;                         //Vida de la ficha
    int ataque;                     //Ataque de la ficha
    int defensa;                    //Defensa de la ficha
    int rango;                      //Rango de ataque de la ficha
    bool habilidadEspecialUsada;    //Booleano para ver si la ficha uso su habilidad especial

    public:
        Ficha(std::string subClase, int vida, int ataque, int defensa, int rango);


    // Metodos para stats
    std::string getSubClase() const;
    int getVida() const;
    int getAtaque()const;
    int getDefensa()const;
    int getRango()const;

    // Metodo habilidad especial luego de usarse
    bool getHabilidadEspecialUsada()const;;

    // Metodo para activar habilidad Especial
    void usarHabilidadEspecial(Ficha* objetivo, std::vector<Ficha*>& enemigos);

    //Metodo para recibir daño
    void recibirDaño(int cantidad);

    //Metodo para atacar
    void atacar(Ficha* objetivo);

    //Metodo leer desde archivo
    static Ficha cargarDesdeArchivo(const std::string& nombreArchivo, int idFicha);

    //Metodo para mostrar ficha
    void mostrarFicha() const;

    // Destructor
    ~Ficha();

};

#endif //FICHA_H
