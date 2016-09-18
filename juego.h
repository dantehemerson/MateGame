#ifndef JUEGO_H
#define JUEGO_H

#include "funciones.h"
#include "boton.h"
#include "opciones.h"
#include "gotoxy.h"
#include "sonido.h"
#include "dialogo.h"
#include "puntajes.h"

#define TOTAL_PREGUNTAS 10

#ifndef MAX_NOMBRE
    #define MAX_NOMBRE 12
#endif // MAX_NOMBRE

typedef std::vector<int> vi;

// Constantes que representan el modo de juego y los turnos de los jugadores.
enum ModoJuego {
    UN_JUGADOR = 1,
    DOS_JUGADORES,
};

enum Turno {TURNO_JUGADOR_1 = 1, TURNO_JUGADOR_2};

class Juego {
    public:
        Juego();
        // Inicia el juego
        void iniciar();

        /**
        *   Establece las tablas que se van a utizar en el juego
        *   @param arrTablas : El arreglo con las tablas. */
        void establecerTabla(vi arrTablas);
        short obtenerPuntajeJugador() const;
        short obtenerPuntajeJugador2() const;

        void establecerTema(Tema &theme);

        /** Establece el modo del juego (1 jugador ó 2 Jugadores) */
        void establecerModo(int modoJuego);

        /** Establece los nombres de los jugadores para mostrar en el juego*/
        void establecerNombres(char *jugador1, char *jugador2);


        void establecerObjPuntaje(Puntaje &puntaje);


        void finDelJuego();

        bool jugarOtraVez();

        bool esSalir() const;

    private:
        void pintarTurno(); // Funcion que pinta el turno del jugador.
        void respuestaCorrecta(int X, int Y);
        void respuestaIncorrecta(int X, int Y);
        void guardar1Jugador();
        void guardarDuelo();
        short turno;
        char *nombreJugador;
        char *nombreJugador2;
        short puntosJugador;
        Tema tema;
        Puntaje puntos;
        Dialogo dialogo;
        short puntosJugador2;
        vi tablas;
        bool otraVez;
        bool salir;
        short modo;
};

Juego::Juego() {
    modo = UN_JUGADOR;
    puntosJugador = puntosJugador2 = 0;
    salir = false;
}

void Juego::establecerTabla(vi arrTablas) {
    tablas = arrTablas;
}

bool Juego::esSalir() const {
    return salir;
}

short Juego::obtenerPuntajeJugador() const {
    return puntosJugador;
}

short Juego::obtenerPuntajeJugador2() const {
    return puntosJugador2;
}
void Juego::establecerNombres(char *jugador1, char *jugador2) {
    nombreJugador = jugador1;
    nombreJugador2 = jugador2;
}

void Juego::pintarTurno() {
    gotoxy(26, 1);
    std::cout << "TURNO DE " << (turno == TURNO_JUGADOR_1 ? nombreJugador : nombreJugador2);
    setColor(VERDE_CLARO, tema.obtenerFondo());
    int x = (turno == TURNO_JUGADOR_1 ? 0 : 62);
    gotoxy(x, 7);
    std::cout << char(219) << char(219) << char(219);
    gotoxy(x, 8);
    std::cout << char(219) << char(219) << char(219);
    gotoxy(x, 9);
    std::cout << char(219) << char(219) << char(219);
}

void Juego::establecerModo(int modoJuego) {
    modo = modoJuego;
}

void Juego::finDelJuego() {
    otraVez = false;
    tema.cls();
    static Wave aplauso("sounds/APPLAUSE.WAV");
    static Wave trompeta("sounds/Trumpet1.wav");
    if(modo == UN_JUGADOR) {
        gotoxy(26, 2);
        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        std::cout << "FIN DEL JUEGO";
        gotoxy(21, 3);
        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        std::cout << "MODO   : UN JUGADOR";
        gotoxy(3, 5);
        std::cout << "NOMBRE : " << nombreJugador;
        barra(18, 7, obtenerPuntajeJugador(), TOTAL_PREGUNTAS - obtenerPuntajeJugador());

        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        gotoxy(23, 13);
        std::cout << "PUNTAJE TOTAL : " << obtenerPuntajeJugador() * 10;

        gotoxy(21, 15);
        std::cout << nombreJugador << " ";
        if(obtenerPuntajeJugador() == 10) {
            std::cout << "ERES EXCELENTE";
            aplauso.play(true);
        }
        else if(obtenerPuntajeJugador() >= 8 ) {
            std::cout << "ERES BUENO";
            //trompeta.play(true);
        }
        else if(obtenerPuntajeJugador() >= 6 ) {
            std::cout << "ERES REGULAR";
            //trompeta.play(true);
        }
        else if(obtenerPuntajeJugador() >= 3 ) {
            std::cout << "ERES MASO";
        }
        else if(obtenerPuntajeJugador() >= 1) {
            std::cout << "ERES MALO";
        }
        else if(obtenerPuntajeJugador() >= 0 ) {
            std::cout << "ERES MUY MALO";
        }
    }

    else {
        gotoxy(26, 1);
        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        std::cout << "FIN DEL JUEGO";
        gotoxy(21, 3);
        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        std::cout << "MODO   : DOS JUGADORES";
        gotoxy(3, 4);
        std::cout << nombreJugador;
        barra(18, 5, obtenerPuntajeJugador(), TOTAL_PREGUNTAS / 2 - obtenerPuntajeJugador());

        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        gotoxy(3, 11);
        std::cout << nombreJugador2;
        barra(18, 12, obtenerPuntajeJugador2(), TOTAL_PREGUNTAS / 2 - obtenerPuntajeJugador2());

        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        gotoxy(20, 19);
        if(obtenerPuntajeJugador() > obtenerPuntajeJugador2()) {
            std::cout << "EL GANADOR ES : " << nombreJugador;
        }
        else if(obtenerPuntajeJugador() < obtenerPuntajeJugador2()) {
            std::cout << "EL GANADOR ES : " << nombreJugador2;
        }
        else {
            std::cout << "HUBO UN EMPATE!!!";
        }
    }


    static DMOUSE raton;
    bool clickeado = false;

    Boton jugarNuevamente;
    Boton menuPrincipal;

    jugarNuevamente.establecerTexto("JUGAR OTRA VEZ");
    menuPrincipal.establecerTexto("MENU PRINCIPAL");

    menuPrincipal.establecerDimesion(18,3);
    jugarNuevamente.establecerDimesion(18,3);
    jugarNuevamente.establecerPosicion(11, 22);
    menuPrincipal.establecerPosicion(jugarNuevamente.obtenerXFin() + 7, 22);
    jugarNuevamente.establecerColor(BLANCO_BRILLANTE, VERDE);
    menuPrincipal.establecerColor(BLANCO_BRILLANTE, VERDE);
    menuPrincipal.establecerColorPresionado(PLOMO, BLANCO_BRILLANTE);
    jugarNuevamente.establecerColorPresionado(PLOMO, BLANCO_BRILLANTE);

    menuPrincipal.mostrar();
    jugarNuevamente.mostrar();
    do {
        mouse(&raton); // Espera el click del mouse

        if(raton.buttonPressed == MOUSE_BUTTON_LEFT) {
            // Boton Si
            if(raton.coordinates.X >= jugarNuevamente.obtenerX()
                && raton.coordinates.X <= jugarNuevamente.obtenerXFin()
                && raton.coordinates.Y >= jugarNuevamente.obtenerY()
                && raton.coordinates.Y <= jugarNuevamente.obtenerYFin()) {
                jugarNuevamente.click();
                otraVez = true;
                clickeado = true;
            }
            // Boton no
            else if(raton.coordinates.X >= menuPrincipal.obtenerX()
                && raton.coordinates.X <= menuPrincipal.obtenerXFin()
                && raton.coordinates.Y >= menuPrincipal.obtenerY()
                && raton.coordinates.Y <= menuPrincipal.obtenerYFin()) {
                menuPrincipal.click();
                clickeado = true;
            }
        }
    } while(!clickeado);
} // Fin funcion fin del juego

void Juego::respuestaCorrecta(int X, int Y) {
    setColor(AZUL_CLARO, VERDE_CLARO);
    for(int i = 0; i < 15; i++) {
        gotoxy(X, Y + i);
       std:: cout << "                                              ";
    }
    gotoxy(X + 19, Y + 1);
    std::cout << "CORRECTO!!!";
    gotoxy(X + 14, Y + 2);
    //std::cout << "SIGUE ASI!!!";

    pintarBordes(45, 15, X, Y);
    caritaFeliz(X + 10, Y + 3);
    Sleep(300);
    caritaFelizChick(X + 10, Y + 3);
    Sleep(400);
    caritaFeliz(X + 10, Y + 3);
    Sleep(1000);

    setColor(NEGRO, AMARILLO);
}

void Juego::respuestaIncorrecta(int X, int Y) {
    setColor(NEGRO, ROJO_CLARO);
    for(int i = 0; i < 15; i++) {
        gotoxy(X, Y + i);
       std:: cout << "                                              ";
    }
    gotoxy(X + 14, Y + 14);
    std::cout << "RESPUESTA INCORRECTA!!!";
    pintarBordes(45, 15, X, Y);
    caritaTriste(X + 10, Y + 1);
    Sleep(1500);
    setColor(NEGRO, AMARILLO);

}

void Juego::establecerTema(Tema &theme) {
    tema = theme;
}
void Juego::establecerObjPuntaje(Puntaje &puntaje) {
    puntos = puntaje;
}
bool Juego::jugarOtraVez() {
    return otraVez;
}
void Juego::guardar1Jugador() {

    puntos.guardarPuntajeJugador(nombreJugador, nombreJugador2, obtenerPuntajeJugador() * 10, 1);
}

void Juego::guardarDuelo() {
    short ganador;
    if(obtenerPuntajeJugador() > obtenerPuntajeJugador2()) {
        ganador = GANO_JUGADOR1;
    }
    else if(obtenerPuntajeJugador() < obtenerPuntajeJugador2()) {
        ganador = GANO_JUGADOR_2;
    }
    else {
        ganador = EMPATE;
    }
    puntos.guardarPuntajeDuelo(nombreJugador, nombreJugador2, obtenerPuntajeJugador() * 10, ganador);
}

void Juego::iniciar() {

    salir = false;
    bool botonNoPrs = false;
    int numeros[TOTAL_PREGUNTAS];
    int alternativas[4];
    int respuesta = 0;
    int subITabla;

    // Sonidos
    static Wave correcto("sounds/right.wav");
    static Wave incorrecto("sounds/wrong.wav");
    Opciones opciones;
    opciones.establecerTema(tema);
    dialogo.establecerTema(tema);

    //dialof.establecerTema(tema);
    dialogo.establecerDimension(40, 8);
    dialogo.establecerTitulo("SEGURO QUE DESEA SALIR?");
    dialogo.establecerCuerpo("No se guardara la partida (*_*)");
    dialogo.establecerPosicion(13, 8);

    /* Inicializa los puntos de cada jugador en 0 */
    puntosJugador = puntosJugador2 = 0;

    // Genera numeros aleatorios no repetidos entre 0 y 12 y los guarda en una arreglo
    arregloAleatorio(numeros, TOTAL_PREGUNTAS, 0, 12);
    int space;


    /* Modo de Juego para un Jugador*/
    if(modo == UN_JUGADOR) {
        space = 0;
        for(int i = 0; i < TOTAL_PREGUNTAS && !salir; i++) {
            srand(static_cast<unsigned int>(time(0)));
            subITabla = rand() % tablas.size();
            // Genera las alternativas para la pregunta.
            generarAlternativas(alternativas, tablas[subITabla], numeros[i]);
            tema.cls();
            do {
                botonNoPrs = false;
                dialogo.ocultar(); // Borra el dialogo si esta mostrado

                space = 0;
                setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
                gotoxy(23, 1);
                std::cout << "Cuanto es...";
                gotoxy(51, 3);
                setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
                std::cout << i + 1 << char(248) << " Pregunta";

                setColor(tema.obtenerColorNumeros(), tema.obtenerFondo());
                gotoxy(51, 5);
                std::cout << "Puntos : " << puntosJugador * 10;
                if(tablas[subITabla] >= 10) {
                    space = 5;
                }
                muestraNumero(tablas[subITabla], 7, 7);
                muestraNumero(numeros[i], 36 + space, 7);
                pintarPor(22 + space,8);

                respuesta = opciones.elegirRespuesta(alternativas, tablas[subITabla] * numeros[i]);

                if(respuesta == BOTON_SALIR) { // Se presiono en el boton salir
                    dialogo.mostrar();
                    botonNoPrs = !dialogo.esSi();
                    salir = (botonNoPrs ? false : true);

                }
                else if(respuesta == tablas[subITabla] * numeros[i]) {
                    correcto.play(true);
                    respuestaCorrecta(8, 1);
                    puntosJugador ++;
                }
                else if(respuesta != tablas[subITabla] * numeros[i]) {
                    incorrecto.play(true);
                    respuestaIncorrecta(8, 1);
                }

            } while(botonNoPrs);
        } // Fin del for

        if(!esSalir()) {
            guardar1Jugador();
            finDelJuego();
        }
    } // Fin Un Jugador


    /* Modo de Juego para Dos Jugadores*/
    else {
        space = 0;
        turno = TURNO_JUGADOR_1;
        for(int i = 0; i < TOTAL_PREGUNTAS && !salir; i++) {
            srand(static_cast<unsigned int>(time(0)));
            subITabla = rand() % tablas.size();
            // Genera las alternativas para la pregunta.
            generarAlternativas(alternativas, tablas[subITabla], numeros[i]);
            tema.cls();
            setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
            pintarTurno();
            do {
                botonNoPrs = false;
                dialogo.ocultar(); // Borra el dialogo si esta mostrado

                space = 0;
                setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
                gotoxy(23, 3);
                std::cout << "Cuanto es...";
                gotoxy(51, 3);
                setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
                std::cout << i + 1 << char(248) << " Pregunta";

                setColor(tema.obtenerColorNumeros(), tema.obtenerFondo());
                gotoxy(1, 5);
                std::cout << nombreJugador << " : " << puntosJugador * 10;
                gotoxy(49, 5);
                std::cout << nombreJugador2 << " : " << puntosJugador2 * 10;

                if(tablas[subITabla] >= 10) {
                    space = 5;
                }
                muestraNumero(tablas[subITabla], 7, 7);
                muestraNumero(numeros[i], 36 + space, 7);
                pintarPor(22 + space,8);

                respuesta = opciones.elegirRespuesta(alternativas, tablas[subITabla] * numeros[i]);

                if(respuesta == BOTON_SALIR) { // Se presiono en el boton salir
                    dialogo.mostrar();
                    botonNoPrs = !dialogo.esSi();
                    salir = (botonNoPrs ? false : true);

                }
                else if(respuesta == tablas[subITabla] * numeros[i]) {
                    if(turno == TURNO_JUGADOR_1) {
                        puntosJugador++;
                    }
                    else {
                        puntosJugador2++;
                    }
                    correcto.play(true);
                    respuestaCorrecta(8, 1);
                }
                else if(respuesta != tablas[subITabla] * numeros[i]) {
                    incorrecto.play(true);
                    respuestaIncorrecta(8, 1);
                }
                turno = (turno == TURNO_JUGADOR_1 ? TURNO_JUGADOR_2 : TURNO_JUGADOR_1);

            } while(botonNoPrs);
        } // Fin del for

        if(!esSalir()) {
            guardarDuelo();
            finDelJuego();
        }
    } // Fin Un Jugador
}
#endif // JUEGO_H
