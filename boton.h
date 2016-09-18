/**
*   @file boton.h -
*/

#ifndef BOTON_H
#define BOTON_H

#include <string>
#include "gotoxy.h"

class Boton {

    public:
        Boton();

        void mostrar();
        void click();
        void establecerPosicion(short X, short Y);
        void establecerColor(short textoColor, short fondoColor);
        void establecerColorPresionado(short textoColor, short fondoColor);
        void establecerColorSeleccionado(short textoColor, short fondoColor);
        void establecerColorBorrar(short color);
        void establecerDimesion(short ancho, short alto);
        void establecerTexto(std::string txt);
        void establecerTitulo(short);
        short obtenerTitulo() const;
        short obtenerX() const;
        void borrarBoton();
        void mostrarNumero(bool valor);
        short obtenerY() const;
        bool estaSeleccionado();
        void establecerSeleccionado(bool selec);
        short obtenerYFin() const;
        short obtenerXFin() const;
        short obtenerAncho() const;
        short obtenerAlto() const;

    private:
        void pintarBoton(); // Pinta el boton
        short titulo; // Titulo para el boton
        std::string texto;
        bool mostrarNum;
        short x;  // Posicion en X en que se empezara a pintar el boton.
        short y; // Posicion en Y en que se empezara a pintar el boton.
        short ancho; // Ancho del boton
        short alto;   // Alto del boto.
        short colorTexto;
        short colorFondo;
        short colorTextoPresionado; // Color de text cuando se da click en el boton.
        short colorFondoPresionado; // Color del fondo cuando se da click en el boton.

        // Colores para cuando el boton esta seleccionado.
        short colorTextoSeleccionado;
        short colorFondoSeleccionado;
        short colorBorrar;

        bool seleccionado; // Indica si el boton esta seleccionado o no.
};

Boton::Boton() {
    x = y = 5;
    ancho = 14;
    alto = 4;
    titulo = 0;
    colorFondo = CELESTE;
    colorTexto = BLANCO_BRILLANTE;
    colorFondoPresionado = VERDE_CLARO;
    colorTextoPresionado = NEGRO;
    colorTextoSeleccionado = BLANCO_BRILLANTE;
    colorFondoSeleccionado = MORADO;
    colorBorrar = NEGRO;
    mostrarNum = false;
    seleccionado = false;

}

void Boton::mostrar() {
    if(seleccionado) {
        setColor(colorTextoSeleccionado, colorFondoSeleccionado);
    }
    else {
        setColor(colorTexto, colorFondo);
    }
    pintarBoton();
}

short Boton::obtenerTitulo() const {
    return titulo;
}

void Boton::click() {
    setColor(colorTextoPresionado, colorFondoPresionado);
    pintarBoton();
    Sleep(140);
    setColor(colorTexto, colorFondo);
    pintarBoton();
    Sleep(18);
}

void Boton::pintarBoton() {
    for(int i = 0; i < alto; i++) {
        for(int j = 0; j < ancho; j++) {
            gotoxy(x + j, y + i);
            std::cout << " ";
        }
    }
    //Pintando el titulo para el boton
    gotoxy(x + ((ancho - texto.length())/2) , y + alto/2);
    std::cout << texto;
    if(texto.length() == 0 || mostrarNum) {
        std::cout << titulo;
    }

}

void Boton::borrarBoton() {
    setColor(colorBorrar, colorBorrar);
    for(int i = 0; i < alto; i++) {
        for(int j = 0; j < ancho; j++) {
            gotoxy(x + j, y + i);
            std::cout << " ";
        }
    }
}

void Boton::establecerDimesion(short valorAncho, short valorAlto) {
    ancho = valorAncho;
    alto = valorAlto;
}

void Boton::establecerSeleccionado(bool selec) {
    seleccionado = selec;
}

bool Boton::estaSeleccionado() {
    return seleccionado;
}

void Boton::establecerTexto(std::string txt) {
    texto = txt;
}
void Boton::establecerTitulo(short title) {
    titulo = title;
}
void Boton::establecerColor(short textoColor, short fondoColor) {
    colorTexto = textoColor;
    colorFondo = fondoColor;
}

void Boton::establecerColorPresionado(short textoColor, short fondoColor) {
    colorFondoPresionado = fondoColor;
    colorTextoPresionado = textoColor;
}

void Boton::establecerColorBorrar(short color ) {
    colorBorrar = color;
}
void Boton::establecerPosicion(short X, short Y) {
    x = X;
    y = Y;
}

void Boton::mostrarNumero(bool valor) {
    mostrarNum = valor;
}

void Boton::establecerColorSeleccionado(short textoColor, short fondoColor) {
    colorFondoSeleccionado = fondoColor;
    colorTextoSeleccionado = textoColor;
}
short Boton::obtenerAlto() const {
    return alto;
}

short Boton::obtenerAncho() const {
    return ancho;
}

short Boton::obtenerX() const {
    return x;
}

short Boton::obtenerY() const {
    return y;
}

short Boton::obtenerXFin() const {
    return x + ancho - 1;
}

short Boton::obtenerYFin() const {
    return y + alto - 1;
}

#endif // BOTON_H
