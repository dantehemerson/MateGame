#ifndef OPCIONES_H
#define OPCIONES_H

#include <iostream>
#include <array>
#include <windows.h>
#include "boton.h"
#include "sonido.h"
#include "tema.h"


typedef std::vector<int> vi;

enum BotonesRespuestas {
    BOTON_SALIR = -505,
    BOTON_A = 1,
    BOTON_B,
    BOTON_C,
    BOTON_D
};

class Opciones {
    public:
        Opciones();
        vi elegirTablas();
        int elegirRespuesta(int alternativas[], int correcta);
        void establecerTema(Tema &theme);

    private:
        short x;
        short y;
        short espacioX;
        short espacioY;
        short ancho;
        short alto;
        short colorFondo;
        short colorFondoBoton;
        short colorTextoBoton;
        short colorTextoBotonPresionado;
        short colorFondoBotonPresionado;
        short colorTextoSeleccionado;
        short colorFondoSeleccionado;
        short colorFondoAtras;
        short colorFondoEmpezar;
        short colorTextoEmpezar;
        vi tablas;
};

Opciones::Opciones() {
    x = y = 0;
    espacioX = 3;
    espacioY = 2;
    colorFondoBoton = CELESTE;
    colorTextoBoton = BLANCO_BRILLANTE;
    colorTextoBotonPresionado = VERDE_CLARO;
    colorFondoBotonPresionado = NEGRO;
    colorTextoSeleccionado = BLANCO_BRILLANTE;
    colorFondoSeleccionado = BLANCO_BRILLANTE;
    colorFondoEmpezar = AZUL;
    colorFondoAtras = ROJO;
    colorTextoEmpezar = BLANCO_BRILLANTE;
    ancho = 13;
    alto = 3;
}

void Opciones::establecerTema(Tema &theme) {
    colorFondo = theme.obtenerFondo();
    colorFondoBoton = theme.obtenerFondoBoton();
    colorTextoBoton = theme.obtenerTextoBoton();
    colorFondoBotonPresionado = theme.obtenerFondoBotonPress();
    colorTextoBotonPresionado = theme.obtenerTextoBotonPress();
    colorFondoSeleccionado = theme.obtenerFondoBotonSelec();
    colorFondoEmpezar = theme.obtenerFondoEmpezar();
    colorFondoAtras = theme.obtenerColorFondoAtras();
}


vi Opciones::elegirTablas() {
    x = 4;
    y = 8;
    espacioX = 3;
    espacioY = 2;
    ancho = 13;
    alto = 3;


    setColor(BLANCO_BRILLANTE);
    static Wave tick("sounds/btn.wav");
    static std::array<Boton, 12> boton;
    static Boton botonEmpezar;
    static Boton botonAtras;

    botonAtras.establecerColor(colorTextoEmpezar, colorFondoAtras);
    botonAtras.establecerDimesion(11, 1);
    botonAtras.establecerTexto("< Atras");
    botonAtras.establecerColorPresionado(colorTextoBotonPresionado, colorFondoBotonPresionado);
    botonAtras.establecerPosicion(2, 1);

    botonEmpezar.establecerColor(colorTextoEmpezar, colorFondoEmpezar);
    botonEmpezar.establecerDimesion(15, 3);
    botonEmpezar.establecerTexto("Empezar");
    botonEmpezar.establecerColorPresionado(colorTextoBotonPresionado, colorFondoBotonPresionado);
    botonEmpezar.establecerPosicion(47, 20);
    botonEmpezar.establecerColorBorrar(colorFondo);

    for(int i = 0; i < boton.size(); i++) {
        boton[i].establecerDimesion(ancho, alto);
        boton[i].establecerColor(colorTextoBoton, colorFondoBoton);
        boton[i].establecerColorSeleccionado(colorTextoSeleccionado, colorFondoSeleccionado);
        boton[i].establecerTitulo(i + 1);
        boton[i].establecerSeleccionado(false);
    }

    boton[0].establecerPosicion(x, y);
    boton[1].establecerPosicion(boton[0].obtenerXFin() + espacioX, y);
    boton[2].establecerPosicion(boton[1].obtenerXFin() + espacioX, y);
    boton[3].establecerPosicion(boton[2].obtenerXFin() + espacioX, y);
    boton[4].establecerPosicion(x, boton[0].obtenerYFin() + espacioY);
    boton[5].establecerPosicion(boton[4].obtenerXFin() + espacioX, boton[0].obtenerYFin() + espacioY);
    boton[6].establecerPosicion(boton[5].obtenerXFin() + espacioX, boton[0].obtenerYFin() + espacioY);
    boton[7].establecerPosicion(boton[6].obtenerXFin() + espacioX, boton[0].obtenerYFin() + espacioY);
    boton[8].establecerPosicion(x, boton[4].obtenerYFin() + espacioY);
    boton[9].establecerPosicion(boton[8].obtenerXFin() + espacioX, boton[4].obtenerYFin() + espacioY);
    boton[10].establecerPosicion(boton[9].obtenerXFin() + espacioX, boton[4].obtenerYFin() + espacioY);
    boton[11].establecerPosicion(boton[10].obtenerXFin() + espacioX, boton[4].obtenerYFin() + espacioY);

    for(int i = 0; i < boton.size(); i++) {
        boton[i].mostrar();
        Sleep(20);
    }
    botonAtras.mostrar();

    static DMOUSE raton;
    bool clickeado = false;

    do {
        mouse(&raton); // Epera el click del mouse
        if(raton.buttonPressed == MOUSE_BUTTON_LEFT) { // Click izquierdo

            if(raton.coordinates.X >= x && raton.coordinates.X <= boton[3].obtenerXFin()) {

                if(raton.coordinates.Y >= y && raton.coordinates.Y <= boton[9].obtenerYFin()) {
                    for(size_t i = 0; i < boton.size(); i++) {
                        if(raton.coordinates.X >= boton[i].obtenerX()
                           && raton.coordinates.X <= boton[i].obtenerXFin()
                           && raton.coordinates.Y >= boton[i].obtenerY()
                           && raton.coordinates.Y <= boton[i].obtenerYFin()) {
                            //tick.play(true);
                            boton[i].establecerSeleccionado(!boton[i].estaSeleccionado());
                            boton[i].mostrar();
                            break;
                        }
                    }

                    // Agrega las tablas seleccionadas al arreglo.
                    tablas.clear();
                    for(size_t i = 0; i < boton.size(); i++) {
                        if(boton[i].estaSeleccionado()) {
                            tablas.push_back(i + 1);
                        }
                    }

                    /* Si almenos a seleccionado una tabla entonces muestra el boton empezar
                        de otro modo lo oculta. */
                    if(tablas.size() != 0) {
                        botonEmpezar.mostrar();
                    }
                    else {
                        botonEmpezar.borrarBoton();
                    }

                }
            }

            if(raton.coordinates.X >= botonAtras.obtenerX()
                && raton.coordinates.X <= botonAtras.obtenerXFin()
                && raton.coordinates.Y >= botonAtras.obtenerY()
                && raton.coordinates.Y <= botonAtras.obtenerYFin()) {
                botonAtras.click();
                tablas.push_back(BOTON_SALIR);
                clickeado = true;
            }
            else if(raton.coordinates.X >= botonEmpezar.obtenerX()
                && raton.coordinates.X <= botonEmpezar.obtenerXFin()
                && raton.coordinates.Y >= botonEmpezar.obtenerY()
                && raton.coordinates.Y <= botonEmpezar.obtenerYFin()) {
                botonEmpezar.click();
                clickeado = true;
            }
        }

    } while (!clickeado);

    return tablas;
}

int Opciones::elegirRespuesta(int alternativas[4], int correcta) {
    x = 5;
    y = 18;
    espacioX = 4;
    espacioY = 2;
    ancho = 25;
    alto = 3;

    int respuesta = 0;
    static Boton botonAtras;

    botonAtras.establecerColor(colorTextoEmpezar, colorFondoAtras);
    botonAtras.establecerDimesion(11, 1);
    botonAtras.establecerTexto("< Atras");
    botonAtras.establecerColorPresionado(colorTextoBotonPresionado, colorFondoBotonPresionado);
    botonAtras.establecerPosicion(2, 1);

    static std::array<Boton, 4> btnAlter;

    if(colorFondoBoton == ROJO_CLARO) {
        colorFondoBoton = ROJO;
    }
    for(size_t i = 0; i < btnAlter.size(); i++) {
        btnAlter[i].establecerDimesion(ancho, alto);
        btnAlter[i].mostrarNumero(true);
        btnAlter[i].establecerTitulo(alternativas[i]);
        btnAlter[i].establecerColor(colorTextoBoton, colorFondoBoton);
        btnAlter[i].establecerColorPresionado(colorTextoBotonPresionado, colorFondoBotonPresionado);
    }
    btnAlter[0].establecerPosicion(x, y);
    btnAlter[1].establecerPosicion(btnAlter[0].obtenerXFin() + espacioX, y);
    btnAlter[2].establecerPosicion(x, btnAlter[0].obtenerYFin() + espacioY);
    btnAlter[3].establecerPosicion(btnAlter[2].obtenerXFin() + espacioX, btnAlter[0].obtenerYFin() + espacioY);

    btnAlter[0].establecerTexto("A) ");
    btnAlter[1].establecerTexto("B) ");
    btnAlter[2].establecerTexto("C) ");
    btnAlter[3].establecerTexto("D) ");

    for(size_t i = 0; i < btnAlter.size(); i++) {
        btnAlter[i].mostrar();
    }
    botonAtras.mostrar();

    static DMOUSE raton;
    bool clickeado = false;

    do {
        mouse(&raton);
        if(raton.buttonPressed == MOUSE_BUTTON_LEFT) { // Click izquierdo

            if(raton.coordinates.X >= x && raton.coordinates.X <= btnAlter[1].obtenerXFin()) {

                if(raton.coordinates.Y >= y && raton.coordinates.Y <= btnAlter[2].obtenerYFin()) {
                    for(size_t i = 0; i < btnAlter.size(); i++) {
                        if(raton.coordinates.X >= btnAlter[i].obtenerX()
                           && raton.coordinates.X <= btnAlter[i].obtenerXFin()
                           && raton.coordinates.Y >= btnAlter[i].obtenerY()
                           && raton.coordinates.Y <= btnAlter[i].obtenerYFin()) {
                            respuesta = btnAlter[i].obtenerTitulo();
                            btnAlter[i].establecerSeleccionado(true);
                            if(respuesta == correcta) {
                                btnAlter[i].establecerColorSeleccionado(NEGRO, VERDE_CLARO);
                            }
                            else {
                                btnAlter[i].establecerColorSeleccionado(NEGRO, ROJO_CLARO);
                                for(int l = 0; l < btnAlter.size(); l++) {
                                    if(btnAlter[l].obtenerTitulo() == correcta) {
                                        btnAlter[l].establecerColorSeleccionado(NEGRO, VERDE_CLARO);
                                        btnAlter[l].establecerSeleccionado(true);
                                        Sleep(20);
                                        btnAlter[l].mostrar();
                                        btnAlter[l].establecerSeleccionado(false);
                                        break;
                                    }
                                }
                            }
                            btnAlter[i].mostrar();
                            btnAlter[i].establecerSeleccionado(false);
                            //btnAlter[i].click();
                            clickeado = true;
                            break;
                        }
                    }
                }
            }

            if(raton.coordinates.X >= botonAtras.obtenerX()
                && raton.coordinates.X <= botonAtras.obtenerXFin()
                && raton.coordinates.Y >= botonAtras.obtenerY()
                && raton.coordinates.Y <= botonAtras.obtenerYFin()) {
                respuesta = BOTON_SALIR;
                botonAtras.click();
                clickeado = true;
            }
        }

    } while (!clickeado);

    return respuesta;
}

#endif // OPCIONES_H
