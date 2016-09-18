/**
*   @file main.cpp Archivo principal del juego
*   @name DIVERTIMATE
*   @version 1.0.0
*
*   Copyright (C) 2016 - Grupo de Alumnos - Todos Los Derechos Reservados.
*
*   Este programa que enseña matematicas a niños de una forma divertida.
*   Esta hecho en modo consola con la libreria estandar de Windows(windows.h).
*/

/* Por si haya algun error al compilar asegurece de incluir en
    Setting -> Compiler -> LinkerSettings -> y en other linker settings
    incluir lo siguiente (sin los parentesis):
    (-lwinmm)        y OK.
*/

#include <iostream>
#include <thread>

/** Inclucion de los archivo de cabezera que pertenecen al proyecto */
#include "gotoxy.h"
#include "tema.h"
#include "menu.h"
#include "opciones.h"
#include "juego.h"
#include "puntajes.h"

#define MAX_NOMBRE 12

using namespace std;

#pragma comment(lib, "winmm")

typedef vector<string> vs;
typedef vector<int> vi;


int main() {

    system("title DIVERTIMATE - GAME");
    system("mode con cols=65 lines=26");

    hideCursor(true); // Oculta el cursor.

    vs opcionesPrincipales; // Opciones principales para el menu.
    opcionesPrincipales.push_back("JUGAR");
//    opcionesPrincipales.push_back("PUNTAJES");
    opcionesPrincipales.push_back("TEMAS");
    opcionesPrincipales.push_back("PUNTAJES");

    //opcionesPrincipales.push_back("VER PUNTAJES");
    opcionesPrincipales.push_back("ACERCA DE");
    opcionesPrincipales.push_back("SALIR");

    vs opcionesJugar; // Opciones para cuando se presione en JUGAR.
    opcionesJugar.push_back("UN JUGADOR");
    opcionesJugar.push_back("DOS JUGADORES");

    vi tablas; // Vector para las tablas que se seleccionarán.
    bool salir = false;
    char nombreJugador[MAX_NOMBRE];
    char nombreJugador2[MAX_NOMBRE];
    bool nuevoJuego;
    static Wave start("sounds/chimes.WAV");
    static Wave about("sounds/crash_bandico.WAV");
    about.play(true);


    Tema tema;
    Puntaje puntaje;
    Juego juego;
    Opciones opciones;
    Menu menu(opcionesPrincipales);
    menu.establecerAncho(30);
    juego.establecerObjPuntaje(puntaje);

    // Establece los temas
    opciones.establecerTema(tema);
    menu.establecerTema(tema);
    juego.establecerTema(tema);
    puntaje.establecerTema(tema);

    menu.animarMenu(true); // Anima el menu la primera vez que se ejecuta

    //Inciando la barra de carga
    tema.cls();
    barraDeCarga(9, 18, 5);
   // start.play(true);

    do {
        tema.cls(); // Borra la pantalla con el color del tema
        gotoxy(20, 3);
        setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
        cout << "BIENVENIDO A \"DIVERTIMATE\"";
        setColor(tema.obtenerColorLineasTitulo(), tema.obtenerFondo());
        pintarBordes(35, 2, 15, 2, 205, 186, 201, 187, 200, 188, false, 15);
        setColor(tema.obtenerColorBordeMenu(), tema.obtenerFondo());
        pintarBordes(41, 16, 12, 6, 196, 179, 218,191,192,217);
        menu.establecerOpciones(opcionesPrincipales);
        menu.establecerPosicion(14, 7);
        /* Muestra el menu principal */
        menu.mostrar();
        menu.animarMenu(false);

        switch(menu.obtenerOpcionSeleccionada()) {
            case 1: // --- JUGAR ---
                tema.cls();
                gotoxy(21, 5);
                setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
                cout << "ELIGE TU MODO DE JUEGO";
                setColor(tema.obtenerColorBordeMenu(), tema.obtenerFondo());
                pintarBordes(41, 7, 12, 8, 196, 179, 218,191,192,217);
                menu.establecerOpciones(opcionesJugar);
                menu.establecerPosicion(14, 9);
                /* Muestra el menu con las opciones Jugar */
                menu.mostrar();

                switch(menu.obtenerOpcionSeleccionada()) {
                    case 1: // --- UN JUGADOR ---
                        tema.cls();
                        setColor(tema.obtenerColorBordeMenu(), tema.obtenerFondo());
                        strcpy(nombreJugador2, " ");
                        pedirNombre(nombreJugador, tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
                        juego.establecerNombres(nombreJugador, nombreJugador2);
                        juego.establecerModo(UN_JUGADOR);
                        do {
                            tema.cls();
                            nuevoJuego = false;
                            gotoxy(15, 4);
                            setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
                            cout << nombreJugador;
                            setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
                            cout << " SELECCIONA LAS TABLAS QUE DESEAS " << endl;

                            tablas = opciones.elegirTablas();

                            if(tablas[tablas.size() - 1] != BOTON_SALIR) {
                                tema.cls();
                                juego.establecerTabla(tablas);
                                juego.iniciar();
                                if(!juego.esSalir()) {
                                    // Si se presiono en volver a jugar
                                    nuevoJuego = juego.jugarOtraVez();
                                }
                            }
                        } while(nuevoJuego);
                        break;

                    case 2:
                        tema.cls();
                        setColor(tema.obtenerColorBordeMenu(), tema.obtenerFondo());
                        pedirNombre(nombreJugador, nombreJugador2, tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
                        juego.establecerNombres(nombreJugador, nombreJugador2);
                        juego.establecerModo(DOS_JUGADORES);
                        do {
                            tema.cls();
                            nuevoJuego = false;
                            gotoxy(5, 4);
                            setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
                            cout << nombreJugador ;
                            setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
                            cout << " Y " ;
                            setColor(tema.obtenerColorTextoTitulo(), tema.obtenerFondo());
                            cout << nombreJugador2;
                            setColor(tema.obtenerColorTexto(), tema.obtenerFondo());
                            cout << " SELECCIONEN LAS TABLAS QUE DESEAN " << endl;

                            tablas = opciones.elegirTablas();

                            if(tablas[tablas.size() - 1] != BOTON_SALIR) {
                                tema.cls();
                                juego.establecerTabla(tablas);
                                juego.iniciar();
                                if(!juego.esSalir()) {
                                    // Si se presiono en volver a jugar
                                    nuevoJuego = juego.jugarOtraVez();
                                }
                            }
                        } while(nuevoJuego);
                        break;

                    default:
                        break;

                }
                break;

            case 2: // --- TEMA --
                tema.cls();
                gotoxy(11, 2);
                setColor(BLANCO_BRILLANTE, tema.obtenerFondo());
                cout << "--- * SELECCIONA EL TEMA QUE TE GUSTE * ---";
                tema.establecerPosicion(7, 6);
                tema.elegirTema();
                opciones.establecerTema(tema);
                menu.establecerTema(tema);
                juego.establecerTema(tema);
                puntaje.establecerTema(tema);
                break;

            case 3: // --- PUNTAJES ---
                tema.cls();
                puntaje.mostrarPuntajes();
                break;

            case 4: // --- ACERCA DE ---
                tema.cls();
                mostrarAcercaDe(9, 0, tema.obtenerFondo());
                break;

            case 5: // --- SALIR ---
            default:
                salir = true;
                break;
        }
    } while(!salir);

    return(EXIT_SUCCESS);
} // Fin del main.
