/**
*   @file puntajes.h  Se define la clase para mostrar los puntajes y
*   funciones para manejar los datos del programa, crea archivos
*   binarios para la busqueda.
*
*   Primero se define una clase dato que tiene los datos miembro
*   que se necesitan para mostrar los puntajes el tamaño de esta clase
*   se utilizara para definir el tamaño de bytes en el archivo.
*/

#ifndef PUNTAJES_H
#define PUNTAJES_H

#include <fstream> /// Utilizamos la libreria estandar para manipular archivos
#include <string>
#include "funciones.h"

#ifndef MAX_NOMBRE
    #define MAX_NOMBRE 12
#endif // MAX_NOMBRE

/*  Constantes para definir el final del Juego */
enum Ganador{GANO_JUGADOR1 = 1, GANO_JUGADOR_2, EMPATE};

class Dato {
    public:
        /// Constructor
        Dato();
        void establecerNombreJugador(char  nombre[MAX_NOMBRE]);
        std::string obtenerNombreJugador() const;

        void establecerNombreJugador2(char *nombre);
        std::string obtenerNombreJugador2() const;

        void establecerPuntaje(int puntaje);
        int obtenerPuntaje() const;

        void establecerGanadorDuelo(short ganador);
        short obtenerGanadorDuelo() const;

private:
        int puntajeJugador;
        char nombreJugador[MAX_NOMBRE];
        char nombreJugador2[MAX_NOMBRE];
        short ganadorDuelo;
};

Dato::Dato() {
    /* Se inicializan los datos vacios */
    strcpy(nombreJugador, " ");
    strcpy(nombreJugador2, " ");
    puntajeJugador = -999; // Un valor no aceptable en este caso ya que los puntajes son mayores que 0
    ganadorDuelo = GANO_JUGADOR1;
}

/**
*   Funcion que establece el nombre del jugador
*/
void Dato::establecerNombreJugador(char nombre[MAX_NOMBRE]) {
    strcpy(nombreJugador, nombre);
}

std::string Dato::obtenerNombreJugador() const {
    return nombreJugador;
}

void Dato::establecerNombreJugador2(char nombre[MAX_NOMBRE]) {
    strcpy(nombreJugador2, nombre);
}

std::string Dato::obtenerNombreJugador2() const {
    return nombreJugador2;
}

void Dato::establecerGanadorDuelo(short ganador) {
    ganadorDuelo = ganador;
}

short Dato::obtenerGanadorDuelo() const {
    return ganadorDuelo;
}

void Dato::establecerPuntaje(int puntaje) {
    puntajeJugador = puntaje;
}

int Dato::obtenerPuntaje() const {
    return puntajeJugador;
}

class Puntaje {
    public:
        Puntaje();
        void mostrarPuntajes();
        void establecerTema(Tema &);
        void guardarPuntajeJugador(char nombreJugador[], char nombreJugador2[], int puntaje, int ganador);
        void guardarPuntajeDuelo(char nombreJugador[], char nombreJugador2[], int puntaje, int ganador);
    private:
        short x;
        short y;
        Dato dato;
        void pintarDatoJugador(int i, Dato &);
        void pintarDatoDuelo(int i, Dato &);
        short fondoTexto;
        short colorTexto;
        char title[MAX_NOMBRE];
        short colorFondoAtras;
        short colorTextoBotonPresionado;
        short colorFondoBotonPresionado;
};

Puntaje::Puntaje() {
    x = y = 2;
    fondoTexto = NEGRO;
    colorTexto = BLANCO_BRILLANTE;
    colorFondoAtras = ROJO_CLARO;
    colorFondoBotonPresionado = PLOMO;
    colorTextoBotonPresionado = BLANCO_BRILLANTE;
}



void Puntaje::mostrarPuntajes() {

    static Dato datow;
    static Dato datoDuelo;
    std::ifstream datosJugadorIn("user.dat", std::ios::in | std::ios::binary);
    std::ifstream datosJugadorDuelo("duelos.dat", std::ios::in | std::ios::binary);

    gotoxy(30, 1);
    std::cout << "PUNTAJES";
    gotoxy(5, 3);
    std::cout << "MODO UN JUGADOR";
    pintarBordes(21, 20, 1, 4);

    gotoxy(4, 5);
    std::cout << "NOMBRE    PUNTAJE";
    gotoxy(2, 6);
    //std::cout << "_____________________";
    for(int i = 0; i < 20; i++) {
        std::cout << char(196);
    }
    for(int i = 0; i < 17; i++) {
        gotoxy(3, 7+ i);
        std::cout << "  ---         -";
    }


    gotoxy(37, 3);
    std::cout << "MODO DOS JUGADORES";
    pintarBordes(39, 20, 24, 4);

    gotoxy(34, 5);
    std::cout << "DUELO             GANADOR";
    gotoxy(25, 6);
    for(int i = 0; i < 38; i++) {
        std::cout << char(196);
    }
    for(int i = 0; i < 17; i++) {
        gotoxy(25, 7+ i);
        std::cout << "    --- vs ---               ---";
    }

    int i = 0;

    if(!datosJugadorIn) {
        //std::cerr << "No se pundo abrir";
    }
    else {
        datosJugadorIn.read(reinterpret_cast<char *>(&datow), sizeof(Dato));
        i = 0;
        while(datosJugadorIn && !datosJugadorIn.eof() && i < 18) {
            if(datow.obtenerPuntaje() != 0) {
                pintarDatoJugador(i, datow);
                i++;
            }
            datosJugadorIn.read(reinterpret_cast<char*>(&datow), sizeof(Dato));
        }

    }

    if(datosJugadorDuelo){
        datosJugadorDuelo.read(reinterpret_cast<char *>(&datoDuelo), sizeof(Dato));
        i = 0;
        while(datosJugadorDuelo && !datosJugadorDuelo.eof() && i < 18) {
            if(datoDuelo.obtenerPuntaje() != 0) {
                pintarDatoDuelo(i, datoDuelo);
                i++;
            }
            datosJugadorDuelo.read(reinterpret_cast<char*>(&datoDuelo), sizeof(Dato));
        }

    }

    static Boton botonAtras;
    static DMOUSE raton;
    bool clickeado = false;
    botonAtras.establecerColor(BLANCO_BRILLANTE, colorFondoAtras);
    botonAtras.establecerDimesion(11, 1);
    botonAtras.establecerTexto("< Atras");
    botonAtras.establecerColorPresionado(colorTextoBotonPresionado, colorFondoBotonPresionado);
    botonAtras.establecerPosicion(2, 1);
    botonAtras.mostrar();

    do {
        mouse(&raton); // Epera el click del mouse
        // Verifica si se presiono en salir
        if(raton.buttonPressed == MOUSE_BUTTON_LEFT) { // Click izquierdo
            if(raton.coordinates.X >= botonAtras.obtenerX()
                && raton.coordinates.X <= botonAtras.obtenerXFin()
                && raton.coordinates.Y >= botonAtras.obtenerY()
                && raton.coordinates.Y <= botonAtras.obtenerYFin()) {
                botonAtras.click();
                clickeado = true;
            }
        }

    } while (!clickeado);
}

/**
*   ¨@brief Pinta el dato del jugador en la pantalla
*   @param i la posicion en y
*   @param dato  : parámetro de tipo Dato por referencia que se pasa a la funcion para extraer
*   los datos miembros para mostrar en la pantalla (por ejemplo el nombre del jugador).
*/
void Puntaje::pintarDatoJugador(int i, Dato &dato) {
    gotoxy(3, 7 + i);
    std::cout << "                  ";
    gotoxy(3, 7+ i);
    //dato.obtenerNombreJugador().copy(title, MAX_NOMBRE - 2);
    std::cout << dato.obtenerNombreJugador();
    gotoxy(17, 7+ i);
    std::cout << (dato.obtenerPuntaje() < 0 || dato.obtenerPuntaje() > 3999 ? 0 : dato.obtenerPuntaje());
}

void Puntaje::pintarDatoDuelo(int i, Dato &dato) {
    gotoxy(25, 7 + i);
    std::cout << "                                      ";
    gotoxy(25, 7+ i);
    std::cout << dato.obtenerNombreJugador() << " vs " << dato.obtenerNombreJugador2();
    gotoxy(51, 7+ i);
    // Si la partida es empate entonces escribe EMPATE
    if(dato.obtenerGanadorDuelo() == EMPATE) {
        std::cout << "EMPATE";
    }
    else { // De otro modo escribe el nombre del jugador que gano
        std::cout << (dato.obtenerGanadorDuelo() == GANO_JUGADOR1 ? dato.obtenerNombreJugador() : dato.obtenerNombreJugador2());
    }

}


void Puntaje::guardarPuntajeJugador(char nombreJugador[], char nombreJugador2[], int puntaje, int ganador) {
    dato.establecerNombreJugador(nombreJugador);
    dato.establecerNombreJugador2(nombreJugador2);
    dato.establecerPuntaje(puntaje);
    dato.establecerGanadorDuelo(ganador);

    std::ofstream datosJugador("user.dat", std::ios::out | std::ios::binary| std::ios::app);

    if(!datosJugador) {
        //Error
    }
    else {
        datosJugador.write(reinterpret_cast<const char *> (&dato), sizeof(Dato));
    }
}

/**
*   Guarda el puntaje en el archivo duelos.txt
*   Adjunta al final del archivo el tipo de dato Duelo que contine
*   los parámetros @param nombreJugador, nombre Jugador2 , puntaje, ganador
*   que son los datos que se guardarán en el archivo.
*/
void Puntaje::guardarPuntajeDuelo(char nombreJugador[], char nombreJugador2[], int puntaje, int ganador) {
    dato.establecerNombreJugador(nombreJugador);
    dato.establecerNombreJugador2(nombreJugador2);
    dato.establecerPuntaje(puntaje);
    dato.establecerGanadorDuelo(ganador);

    std::ofstream datosDuelos("duelos.dat", std::ios::out | std::ios::binary| std::ios::app);

    if(!datosDuelos) {
        //Error
    }
    else {
        datosDuelos.write(reinterpret_cast<const char *> (&dato), sizeof(Dato));
    }
}

void Puntaje::establecerTema(Tema &theme) {
    fondoTexto = theme.obtenerFondo();
    colorFondoAtras = theme.obtenerColorFondoAtras();
    colorTextoBotonPresionado = theme.obtenerTextoBotonPress();
    colorFondoBotonPresionado = theme.obtenerFondoBotonPress();
}

#endif // PUNTAJES_H
