#ifndef TEMA_H
#define TEMA_H

#include <array>
#include <fstream>
#include "boton.h"
#include "raton.cc"
#include "gotoxy.h"

enum Temas {TEMA_VERDE, TEMA_ROJO, TEMA_AZUL, TEMA_CELESTE};

class Tema {
    public:
        Tema();

        void elegirTema();

        void cls();

        short obtenerFondoBotonPress() const;

        short obtenerFondo() const;
        short obtenerTextoBotonPress() const;
        short obtenerColorLineasTitulo() const;
        short obtenerColorBordeMenu() const;
        short obtenerFondoEmpezar() const;
        short obtenerColorTextoTitulo() const;
        void establecerPosicion(int X, int Y);

        short obtenerColorFondoAtras() const;

        short obtenerFondoDialogo() const;

        short obtenerFondoBotonSelec() const;
        void establecerTema(int tema);

        short obtenerColorNumeros() const;
        short obtenerColorTexto() const;

        short obtenerFondoBoton() const;

        short obtenerTextoBoton() const;

    private:
        short colorTexto;
        short fondoBoton;
        short textoBoton;
        short textoBotonPress;
        short fondoBotonPress;
        short fondoBotonSeleccionado;
        short fondoBotonEmpezar;
        short fondo;
        short fondoDialogo;
        short colorLineasTitulo;
        short colorTextoTitulo;
        short colorBordeMenu;
        short colorNumeros;
        short temaSeleccionado;
        short colorFondoAtras;
        short x;
        short y;
};


Tema::Tema() {
    x = y = 0;
    int numeroTema = TEMA_AZUL;
    std::ifstream temaGuardado("tema.dat", std::ios::in);
    if(!temaGuardado) { // No existe el archivo o todavia no ha sido creado
        //std::cerr << "No se pudo abrir el archivo.";
        //system("pause >> null");
       // exit(EXIT_FAILURE);
    }else {
        temaGuardado >> numeroTema;
    }
    if(numeroTema < 0 || numeroTema > 3) {
        numeroTema = TEMA_AZUL; // TEMA POR DEFECTO
    }
    establecerTema(numeroTema);

}

void Tema::elegirTema() {

    std::ofstream temaGuardar("tema.dat", std::ios::out);

    static std::array<Boton, 4> temas; // C++11
    short espacioX = 5;
    short espacioY = 2;


    for(size_t i = 0; i < temas.size(); i++) {
        temas[i].establecerDimesion(24, 6);
    }

    temas[0].establecerPosicion(x, y);
    temas[1].establecerPosicion(temas[0].obtenerXFin() + espacioX , y);
    temas[2].establecerPosicion(x , temas[0].obtenerYFin() + espacioY);
    temas[3].establecerPosicion(temas[2].obtenerXFin() + espacioX, temas[1].obtenerYFin() + espacioY);

    temas[0].establecerColor(BLANCO_BRILLANTE, VERDE);
    temas[1].establecerColor(BLANCO_BRILLANTE, ROJO_CLARO);
    temas[2].establecerColor(BLANCO_BRILLANTE, AZUL_CLARO);
    temas[3].establecerColor(PLOMO, CELESTE_CLARO);


    temas[0].establecerColorPresionado(BLANCO_BRILLANTE, BLANCO);
    temas[1].establecerColorPresionado(BLANCO_BRILLANTE, AZUL);
    temas[2].establecerColorPresionado(BLANCO_BRILLANTE, BLANCO);
    temas[3].establecerColorPresionado(BLANCO_BRILLANTE, AZUL);

    temas[0].establecerTexto("VERDE - MORADO");
    temas[1].establecerTexto("ROJO CLARO - PLOMO");
    temas[2].establecerTexto("AZUL - AZUL CLARO");
    temas[3].establecerTexto("CELESTE - CYAN");

    for(size_t i = 0; i < temas.size(); i++) {
        temas[i].mostrar();
    }

    static DMOUSE raton;
    bool clickeado = false;

    do {
        mouse(&raton); // Espera el click del mouse

        if(raton.buttonPressed == MOUSE_BUTTON_LEFT) {

            for(size_t i = 0; i < temas.size(); i++) {
                if(raton.coordinates.X >= temas[i].obtenerX()
                   && raton.coordinates.X <= temas[i].obtenerXFin()
                   && raton.coordinates.Y >= temas[i].obtenerY()
                   && raton.coordinates.Y <= temas[i].obtenerYFin()) {
                        clickeado = true;
                         if(!temaGuardar) { // No se pudo abrir el archivo para escritura
                        //std::cerr << "No se pudo abrir el archivo para escritura";
                        }
                        else {
                            temaGuardar << i;
                        }
                        temaSeleccionado = Temas(i);
                        temas[i].click();
                        Sleep(30);
                        break;
                }
            }
        }
    } while(!clickeado);

    establecerTema(temaSeleccionado);
} // Fin elegirTema.

void Tema::establecerTema(int tema) {


    switch(tema) {
        case TEMA_VERDE:
            colorTexto = BLANCO_BRILLANTE;
            fondo = MORADO;
            colorTextoTitulo = BLANCO_BRILLANTE;
            fondoBoton = VERDE;
            textoBoton = BLANCO_BRILLANTE;
            textoBotonPress = BLANCO_BRILLANTE;
            fondoBotonPress = PLOMO;
            fondoDialogo = PLOMO;
            colorNumeros = AMARILLO_CLARO;
            colorLineasTitulo = AMARILLO_CLARO;
            fondoBotonSeleccionado = MORADO_CLARO;
            colorBordeMenu = BLANCO_BRILLANTE;
            fondoBotonEmpezar = AZUL;
            colorFondoAtras = ROJO_CLARO;
            break;
        case TEMA_ROJO:
            colorTexto = BLANCO_BRILLANTE;
            fondo = PLOMO;
            colorTextoTitulo = AMARILLO_CLARO;
            fondoBoton = ROJO_CLARO;
            textoBoton = BLANCO_BRILLANTE;
            textoBotonPress = BLANCO_BRILLANTE;
            fondoBotonPress = PLOMO;
            fondoDialogo = MORADO;
            colorNumeros = AMARILLO_CLARO;
            colorLineasTitulo = VERDE_CLARO;
            fondoBotonSeleccionado = AMARILLO_CLARO;
            colorBordeMenu = BLANCO_BRILLANTE;
            fondoBotonEmpezar = AZUL;
            colorFondoAtras = VERDE;
            break;
        case TEMA_AZUL:
            colorTexto = BLANCO_BRILLANTE;
            fondo = AZUL;
            colorTextoTitulo = AMARILLO_CLARO;
            fondoBoton = AZUL_CLARO;
            textoBoton = BLANCO_BRILLANTE;
            textoBotonPress = BLANCO_BRILLANTE;
            fondoBotonPress = PLOMO;
            fondoDialogo = PLOMO;
            colorNumeros = AMARILLO_CLARO;
            colorLineasTitulo = VERDE_CLARO;
            fondoBotonSeleccionado = AMARILLO_CLARO;
            colorBordeMenu = BLANCO_BRILLANTE;
            fondoBotonEmpezar = ROJO_CLARO;
            colorFondoAtras = ROJO;
            break;
        case TEMA_CELESTE:
            colorTexto = BLANCO_BRILLANTE;
            fondo = CELESTE;
            colorTextoTitulo = AMARILLO_CLARO;
            fondoBoton = CELESTE_CLARO;
            textoBoton = PLOMO;
            textoBotonPress = BLANCO_BRILLANTE;
            fondoBotonPress = PLOMO;
            fondoDialogo = PLOMO;
            colorNumeros = AMARILLO_CLARO;
            colorLineasTitulo = VERDE_CLARO;
            fondoBotonSeleccionado = AZUL;
            colorBordeMenu = BLANCO_BRILLANTE;
            fondoBotonEmpezar = ROJO_CLARO;
            colorFondoAtras = ROJO;
            break;
        default:
            break;

    }
}


void Tema::cls() {
    setColor(BLANCO_BRILLANTE, fondo);
    clrscr();
}

void Tema::establecerPosicion(int X, int Y) {
    x = X;
    y = Y;
}

short Tema::obtenerFondo() const {
    return fondo;
}

short Tema::obtenerColorTextoTitulo() const {
    return colorTextoTitulo;
}

short Tema::obtenerFondoBoton() const {
    return fondoBoton;
}

short Tema::obtenerFondoBotonSelec() const {
    return fondoBotonSeleccionado;
}

short Tema::obtenerTextoBoton() const {
    return textoBoton;
}


short Tema::obtenerFondoBotonPress() const {
    return fondoBotonPress;
}

short Tema::obtenerFondoDialogo() const {
    return fondoDialogo;
}
short Tema::obtenerFondoEmpezar() const {
    return fondoBotonEmpezar;
}

short Tema::obtenerTextoBotonPress() const {
    return textoBotonPress;
}

short Tema::obtenerColorFondoAtras() const {
    return colorFondoAtras;
}

short Tema::obtenerColorNumeros() const {
    return colorNumeros;
}

short Tema::obtenerColorLineasTitulo() const {
    return colorLineasTitulo;
}

short Tema::obtenerColorTexto() const {
    return colorTexto;
}
short Tema::obtenerColorBordeMenu() const {
    return colorBordeMenu;
}

#endif // TEMA_H
