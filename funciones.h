#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

#include "raton.cc"
#include "boton.h"
#include "numero.h"

#define MAX_W 13
#define MAX_H 10


/* Arreglos bidimensionales de tipo char para los numeros */
char CERO[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
};

char UNO[MAX_H][MAX_W] {
    "    XXXXX  ",
    "    XXXXX  ",
    "    XXXXX  ",
    "     XXXX  ",
    "     XXXX  ",
    "     XXXX  ",
    "     XXXX  ",
    "     XXXX  ",
    "     XXXX  ",
};

char DOS[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "        XXXX",
    "        XXXX",
    "XXXXXXXXXXXX",
    "XXXX        ",
    "XXXX        ",
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
};

char TRES[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "        XXXX",
    "        XXXX",
    "XXXXXXXXXXXX",
    "        XXXX",
    "        XXXX",
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
};

char CUATRO[MAX_H][MAX_W] {
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXXXXXXXXXX",
    "        XXXX",
    "        XXXX",
    "        XXXX",
    "        XXXX",
};

char CINCO[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "XXXX        ",
    "XXXX        ",
    "XXXXXXXXXXXX",
    "        XXXX",
    "        XXXX",
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
};

char SEIS[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "XXXX        ",
    "XXXX        ",
    "XXXXXXXXXXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
};

char SIETE[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "        XXXX",
    "        XXXX",
    "        XXXX",
    "        XXXX",
    "        XXXX",
    "        XXXX",
    "        XXXX",
};
char OCHO[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXXXXXXXXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
};
char NUEVE[MAX_H][MAX_W] {
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
    "XXXX    XXXX",
    "XXXX    XXXX",
    "XXXXXXXXXXXX",
    "        XXXX",
    "        XXXX",
    "XXXXXXXXXXXX",
    "XXXXXXXXXXXX",
};

char POR[MAX_H][MAX_W] {
    "            ",
    "            ",
    "XXXX    XXXX",
    " XXXX  XXXX ",
    "   XXXXXX   ",
    " XXXX XXXX  ",
    "XXXX    XXXX",
};


void pintarPor(int x, int y) {
    /* Dos bucles anidados para recorrer todos los elementos
        del arreglo*/
    for(int i = 0; i < MAX_H; i++) {
       for(int j = 0; j < MAX_W; j++) {
            gotoxy(x + j, y + i); // Posiciona el cursor
            /* No se pintara la X del arreglo sino que se cambiara por un caracter
                de la tabla ASCCI, se verá mejor. */
            if(POR[i][j] == 'X') {
                std::cout << "*";
            }
        }
    }
}

/**
*   Función que pinta el arreglo bidimiensional con los números
*   @param numero : Es el arreglo que se utilizara para pintar
*   @param x, y   : La posicion en que se empezara a pintar el número.
*/
void pintarNumero(char numero[][MAX_W], int x, int y) {
    /* Dos bucles anidados para recorrer todos los elementos
        del arreglo*/
    for(int i = 0; i < MAX_H; i++) {
       for(int j = 0; j < MAX_W; j++) {
            gotoxy(x + j, y + i); // Posiciona el cursor
            /* No se pintara la X del arreglo sino que se cambiara por un caracter
                de la tabla ASCCI, se verá mejor. */
            if(numero[i][j] == 'X') {
                std::cout << char(219);
            }
        }
    }
}

/** Muestra los numeros según el parámetro que reciba */
void muestraNumero(int numero, int x, int y) {
    //Pintamos el número deacuerdo al argumento que nos den.
    switch(numero) {
        case 0:
            pintarNumero(CERO, x, y);
            break;
        case 1:
            pintarNumero(UNO, x, y);
            break;
        case 2:
            pintarNumero(DOS, x, y);
            break;
        case 3:
            pintarNumero(TRES, x, y);
            break;
        case 4:
            pintarNumero(CUATRO, x, y);
            break;
        case 5:
            pintarNumero(CINCO, x, y);
            break;
        case 6:
            pintarNumero(SEIS, x, y);
            break;
        case 7:
            pintarNumero(SIETE, x, y);
            break;
        case 8:
            pintarNumero(OCHO, x, y);
            break;
        case 9:
            pintarNumero(NUEVE, x, y);
            break;
        case 10:
            pintarNumero(UNO, x-3, y);
            pintarNumero(CERO, x + MAX_W-6, y);
            break;
        case 11:
            pintarNumero(UNO, x-3, y);
            pintarNumero(UNO, x + MAX_W - 8, y);
            break;
        case 12:
            pintarNumero(UNO, x-3, y);
            pintarNumero(DOS, x + MAX_W - 6, y);
            break;

        default:
            break;
    }
    return;
}


/**
*   Función de tipo int que retorna un numero aleatorio
*   @param inicio, fin : El rango en que se desea el numero aleatorio.
*   @return Retorna el numero aleatorio
*/
int numeroAleatorio(int inicio, int fin) {
    int aleatorio = inicio + rand() % (fin - inicio + 1);
    return aleatorio;
}


void copiarCaracteres(char *de, char *a, size_t cant) {
    for(int i = 0; i < cant; i++) {
        a[i] = de[i];
    }
}
void leerNombre(char frase[], short limite) {
    int i = 0;
    do {
        frase[i] = (char)_getch();
        if(frase[i] != 8 ) {
            if ((i <= limite && ((frase[i] >= 97 && frase[i] <= 122) || (frase[i] >= 65 && frase[i] <= 90))) || frase[i] == 13 || frase[i] == 32 ){
                if(frase[i] >= 97 && frase[i] <= 122) {
                    frase[i] -= 32;
                }
                // Escribe la letra en mayusculas
                std::cout <<frase[i];
                i++;
            }

        } else if(i > 0) {
            std::cout <<(char)8<<(char)32<<(char)8;
            i--;
        }
        std::cout.flush();
    }while(frase[i-1] != 13);

    frase[i-1] = NULL; // Agrega al final de la cadena el caracter NUll('\0')
    std::cout <<std::endl;
}

void caritaFeliz(int x, int y) {
    gotoxy(x, y);
    std::cout<<"         #########";
    gotoxy(x, ++y);
    std::cout<<"      ####       ####";
    gotoxy(x, ++y);
    std::cout<<"    ###             ###";
    gotoxy(x, ++y);
    std::cout<<"  ###   ###     ###  ###";
    gotoxy(x, ++y);
    std::cout<<" ##    #####   #####   ##";
    gotoxy(x, ++y);
    std::cout<<" ##     ###     ###    ##";
    gotoxy(x, ++y);
    std::cout<<" ##                    ##";
    gotoxy(x, ++y);
    std::cout<<"  ###     ##    ##   ### ";
    gotoxy(x, ++y);
    std::cout<<"   ###     ######   ###";
    gotoxy(x, ++y);
    std::cout<<"      ###         ###";
    gotoxy(x, ++y);
    std::cout<<"         #########";

}


void caritaTriste(int x, int y) {
    gotoxy(x, y);
    std::cout<<"         #########";
    gotoxy(x, ++y);
    std::cout<<"      ####       ####";
    gotoxy(x, ++y);
    std::cout<<"    ###             ###";
    gotoxy(x, ++y);
    std::cout<<"  ###   ###     ###  ###";
    gotoxy(x, ++y);
    std::cout<<" ##    #####   #####   ##";
    gotoxy(x, ++y);
    std::cout<<" ##     ###     ###    ##";
    gotoxy(x, ++y);
    std::cout<<" ##                    ##";
    gotoxy(x, ++y);
    std::cout<<"  ###      ######     ### ";
    gotoxy(x, ++y);
    std::cout<<"   ###   ##     ##   ###";
    gotoxy(x, ++y);
    std::cout<<"      ###         ###";
    gotoxy(x, ++y);
    std::cout<<"         #########";

}


void caritaFelizOjosCerrados(int x, int y) {
    gotoxy(x, y);
    std::cout<<"         #########";
    gotoxy(x, ++y);
    std::cout<<"      ####       ####";
    gotoxy(x, ++y);
    std::cout<<"    ###             ###";
    gotoxy(x, ++y);
    std::cout<<"  ###                ###";
    gotoxy(x, ++y);
    std::cout<<" ##    #####   #####   ##";
    gotoxy(x, ++y);
    std::cout<<" ##                    ##";
    gotoxy(x, ++y);
    std::cout<<" ##                    ##";
    gotoxy(x, ++y);
    std::cout<<"  ###     ##    ##   ### ";
    gotoxy(x, ++y);
    std::cout<<"   ###     ######   ###";
    gotoxy(x, ++y);
    std::cout<<"      ###         ###";
    gotoxy(x, ++y);
    std::cout<<"         #########";
}


void caritaFelizChick(int x, int y) {
    gotoxy(x, y);
    std::cout<<"         #########";
    gotoxy(x, ++y);
    std::cout<<"      ####       ####";
    gotoxy(x, ++y);
    std::cout<<"    ###             ###";
    gotoxy(x, ++y);
    std::cout<<"  ###           ###  ###";
    gotoxy(x, ++y);
    std::cout<<" ##    #####   #####   ##";
    gotoxy(x, ++y);
    std::cout<<" ##             ###    ##";
    gotoxy(x, ++y);
    std::cout<<" ##                    ##";
    gotoxy(x, ++y);
    std::cout<<"  ###     ##    ##   ### ";
    gotoxy(x, ++y);
    std::cout<<"   ###     ######   ###";
    gotoxy(x, ++y);
    std::cout<<"      ###         ###";
    gotoxy(x, ++y);
    std::cout<<"         #########";

}





/**
*   Función que genera numeros aleatorios y los va almacenando en un arreglo
*   para obtener numeros aleatorios no repetidos.
*/
void arregloAleatorio(int arreglo[], int tam, int inicio, int fin) {
    int aleatorio = 0;
    bool encontrado;
    // randomiza el generador de números aleatorios, usando la hora actual.
    srand(static_cast<unsigned int>(time(0)));

    for(int i = 0; i < tam; i++) {
        aleatorio = numeroAleatorio(inicio, fin); // Llama a numeroAleatorio() para obtener un numero.
        encontrado = false; // Establece encontrado en false.
        // Compara si el numero aleatorio ya esta en el arreglo.
        for(int b = 0; b < i; b++) {
            if(arreglo[b] == aleatorio) {
                encontrado = true;
                break;
            }
        }
        /* Si el numero ya esta en el arreglo entonces resta uno al
            contador para que repita la acción para el mismo subíndice */
        if(encontrado) {
            i--;
        } else { // Agrega el numero aleatorio al arreglo.
            arreglo[i] = aleatorio;
        }
    }
}

/**
*   Función que genera las alternativas para el juego
*/
void generarAlternativas(int arreglo[4], int num1, int num2) {
    int rCorrecta = num1 * num2;
    int rSuma = num1 + num2;
    if((num1 == 0 && num2 == 0) || (num1 == 2 && num2 == 2)) {
        rSuma++;
    }
    int r3 = rCorrecta + numeroAleatorio(2, 10);
    int r4 = rCorrecta - 1;
    if((num1 == 2 && num2 == 3) || (num1 == 3 && num2 == 2))
        r4 = rCorrecta - 2;


    int aleatorios[4];
    arregloAleatorio(aleatorios, 4, 0, 3);

    arreglo[aleatorios[0]] = rCorrecta;
    arreglo[aleatorios[1]] = rSuma;
    arreglo[aleatorios[2]] = r3;
    arreglo[aleatorios[3]] = r4;
}

// Funcion para pintar bordes
void pintarBordes(int ancho, int alto, int x, int y, int hor = 205, int ver = 186,
                int esqSI = 201, int esqSD = 187, int esqII = 200, int esqID = 188, bool animar = false, short time = 10) {

    gotoxy(x, y);
    std::cout << char(esqSI);

    for(int i = x + 1; i < x + ancho; i++) {
        gotoxy(i, y);
        std::cout << char(hor);
        gotoxy(i, y + alto);
        std::cout << char(hor);
        if(animar) {
            Sleep(time);
        }
    }
    gotoxy(x + ancho, y);
    std::cout << char(esqSD);

    for(int i = y + 1; i < y + alto; i++) {
        gotoxy(x, i);
        std::cout << char(ver);
        gotoxy(x + ancho, i);
        std::cout << char(ver);
        if(animar) {
            Sleep(time);
        }
    }
    gotoxy(x, y + alto);
    std::cout << char(esqII);

    gotoxy(x + ancho, y + alto);
    std::cout << char(esqID);
}


/**
*   Funcion que pide el nombre del jugador.
*/
void pedirNombre(char jugador[], short colorText = CELESTE_CLARO, short fondo = NEGRO) {
    gotoxy(14, 9);
    std::cout << "INGRESA TU NOMBRE >";
    pintarBordes(13, 2, 34, 8, 196, 179, 218,191,192,217);
    hideCursor(false);
    setColor(colorText, fondo);
    gotoxy(36, 9);
    leerNombre(jugador, 9);
    hideCursor(true);
}

/**
*   Funcion sobrecargada pide los nombres a los jugadores.
*
*/
void pedirNombre(char jugador1[], char jugador2[], short colorText = CELESTE_CLARO, short fondo = NEGRO) {
    hideCursor(false);
    gotoxy(15, 9);
    std::cout << "NOMBRE JUGADOR 1 > " ;
    pintarBordes(14, 2, 34, 8, 196, 179, 218,191,192,217);
    gotoxy(15, 13);
    std::cout << "NOMBRE JUGADOR 2 > ";
    pintarBordes(14, 2, 34, 12, 196, 179, 218,191,192,217);

    setColor(colorText, fondo);
    gotoxy(36, 9);
    leerNombre(jugador1, 9);
    gotoxy(36, 13);
    leerNombre(jugador2, 9);

    hideCursor(true);
}

void barra(int x, int y, int buenas, int malas, bool animar = true) {
    short mayor = (buenas > malas ? buenas : malas);

    gotoxy(x - 12, y);
    setColor(NEGRO, VERDE_CLARO);
    std::cout << "BUENAS : " << buenas;
    gotoxy(x - 12, y + 3);
    setColor(BLANCO_BRILLANTE, ROJO_CLARO);
    std::cout << "MALAS  : " << malas;


    for(int i = 0; i <= mayor * 4; i+=4) {
        for(int k = i; k <= i + 3; k++) {
            if(i < buenas * 4) {
                setColor(VERDE_CLARO, NEGRO);
                gotoxy(x + k, y);
                std::cout << char(219);
                gotoxy(x + k, y+1);
                std::cout << char(219);
            }
            if(i < malas * 4) {
                setColor(ROJO_CLARO, NEGRO);
                gotoxy(x + k, y + 3);
                std::cout << char(219);
                gotoxy(x + k, y+4);
                std::cout << char(219);
            }
            Sleep(20);
        }
    }
}



void pintarInfo(int x, int y, short fondo) {
    std::string nombreElyne = "Pajares Galvez, Elayne";
    std::string nombreDante = "Calderon Vasquez, Dante Hemerson";
    std::string nombreZuta = "Zuta Garcia, Joseph";
    std::string nombreAndre = "Salinas Cruz, Andre Fernando";
    std::string nombreProfYenni = "Sifuentes Garcia, Yenny";
    std::string nombreGiane = "Aponte Rodriguez, Gianella";

    int ancho = 47;
    setColor(BLANCO_BRILLANTE, fondo);
    pintarBordes(ancho, 24, x, y);
    int centro = 6;

    setColor(BLANCO_BRILLANTE);

    gotoxy(x + 10, y + 1);
    setColor(AMARILLO_CLARO, fondo);
    std::cout << "ACERCA DE \"DIVERTIVATE\" v1.0";


    gotoxy(x + centro - 3, y + 3);
    setColor(BLANCO_BRILLANTE, fondo);
//    std::cout << "Proyecto final de Algoritmos y Programacion";
    std::cout << "DIVERTIMATE es una aplicacion educativa que";
    gotoxy(x + centro - 3, y + 4);
    std::cout << "creada para ayudar a ni\xA4os de primaria a";
    gotoxy(x + centro - 3, y + 5);
    std::cout << "reforzar su conociemiento en el area de";
    gotoxy(x + centro - 3, y + 6);
    std::cout << "matematicas.";
    gotoxy(x + centro - 3, y + 7);
    std::cout << "Este proyecto fue desarrollado por jovenes";
    gotoxy(x + centro - 3, y + 8);
    std::cout << "Universitarios con el proposito de que el";
    gotoxy(x + centro - 3, y + 9);
    std::cout << "aprendizaje sea mas divertido. ";

    gotoxy(x + centro, y + 11);
    setColor(BLANCO_BRILLANTE, fondo);
    std::cout << "PROGRAMADORES : ";

    setColor(BLANCO_BRILLANTE, fondo);
    gotoxy(x + centro, y + 12);
    std::cout << char(254) << " " <<  nombreGiane;

    gotoxy(x + centro, y + 13);
    std::cout << char(254) << " " <<  nombreDante;

    gotoxy(x + centro, y + 14);
    std::cout << char(254) << " " << nombreElyne;

    gotoxy(x + centro, y + 15);
    std::cout << char(254) << " " << nombreAndre;

    gotoxy(x + centro, y + 16);
    std::cout << char(254) << " " <<  nombreZuta;

    gotoxy(x + centro  + 13, y + 18);
    std::cout << "PROFESORA : ";

    gotoxy(x + centro + 7, y + 19);
    std::cout << nombreProfYenni;

    gotoxy(x + centro + 3, y + 21);
    std::cout <<"UNIVERSIDAD NACIONAL DE TRUJILLO";

}

void barraDeCarga(short x, short y, short segundos) {

    pintarBordes(46, 3, x-1, y-1, 196, 179, 218,191,192,217);
    int timer = 30;
    int chart = 219;
    int carg = 0;

    for(int i = 0; i < 45; i++) {
        gotoxy(x + i, y);
        std::cout << char(chart);
        gotoxy(x + i, y + 1);
        std::cout << char(chart);

        if(i % 6 == 0) {
          carg++;
        }
        if(carg > 3) {
            carg = 0;
        }

        gotoxy(28, 16);
        switch(carg) {
            case 0:
                std::cout << "CARGANDO   ";
                break;
            case 1:
                std::cout << "CARGANDO.  ";
                break;
            case 2:
                std::cout << "CARGANDO.. ";
                break;
            case 3:
                std::cout << "CARGANDO...";
                break;
            default:
                break;
        }
        srand(static_cast<unsigned int>(time(0)));
        if(i > 36) {
            timer = numeroAleatorio(20, 40);
        }
        else if(i > 33) {
            timer = numeroAleatorio(60, 160);
        }
         else if(i > 25) {
            timer = numeroAleatorio(20, 40);
        }
        else if(i >= 0) {
            timer = numeroAleatorio(30, 60);
        }
        Sleep(timer);

    }
    Sleep(100);
}

/**
*   Muestra la información del programa
*/
void mostrarAcercaDe(int x, int y, short fondo) {

    bool salir = false;
    int xPress = 22;
    bool plac = false;
    bool derecha = true;
    Numero numero(4);
    numero.establecerFondo(fondo);
    pintarInfo(x, y, fondo);
    int temp = 0;
    setColor(BLANCO_BRILLANTE, fondo);
    gotoxy(x + 6, y + 23);
    std::cout <<"Presiona una tecla para continuar...";
    while(!salir) {
        numero.mover();
        if(_kbhit()) {
            salir = true;
        }
        temp++;
        if(temp > 9999999) {
            temp = 0;
        }
        if(temp % 10 == 0) {
            if(xPress > 28) {
                derecha = false;
            }
            else if(xPress < 11) {
                derecha = true;
            }

            if(derecha) {
                xPress++;
            }
            else {
                xPress--;
            }
            if(temp % 20 == 0) {
                plac = !plac;
            }
            if(plac)
            setColor(ROJO_CLARO, fondo);
            else setColor(BLANCO_BRILLANTE, fondo);
            gotoxy(x + 6, y + 23);
            std::cout <<"Presiona una tecla para continuar...";
        }
        Sleep(40);
    }
}
#endif // FUNCIONES_H
