#ifndef DIALOGO_H
#define DIALOGO_H

#include "tema.h"

enum BotonDialogo {BOTON_NO, BOTON_SI, BOTON_NUEVO_JUEGO, BOTON_MENU_PRINCIPAL};
enum BotonEstilo {INTERROGATIVO, ACEPTABLE};

class Dialogo {

    public:
        Dialogo();
        void mostrar();
        void ocultar();
        void establecerDimension(short dimenAncho, short dimenAlto);
        void establecerPosicion(short X, short Y);
        void establecerEstilo();
        void establecerTema(Tema &theme);
        void establecerTitulo(std::string title);
        void establecerCuerpo(std::string body);
        bool esSi() const;

    private:
        short x;
        short y;
        short fondoColorDialogo;
        short tituloColorDialogo;
        short cuerpoColorDialogo;
        short fondoBotonDialogo;
        short textoBotonDialogo;
        short fondoBorrar;
        short ancho;
        short alto;
        bool si;
        std::string titulo;
        std::string cuerpo;
};

Dialogo::Dialogo() {
    si = false;
    ancho = 37;
    alto = 8;
    x = y = 0;
    fondoBotonDialogo = NEGRO;
    textoBotonDialogo = BLANCO_BRILLANTE;
    fondoColorDialogo = PLOMO;
    tituloColorDialogo = NEGRO;
    cuerpoColorDialogo = BLANCO_BRILLANTE;
    fondoBorrar = NEGRO;
}

void Dialogo::mostrar() {
    static Wave notify("sounds/notify.wav");
    static Wave no("sounds/Speech_Off.wav");
    static Wave yes("sounds/Speech_On.wav");
    notify.play(true);
    // Fondo del dialogo
    setColor(fondoColorDialogo, fondoColorDialogo);
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        std::cout << "                                        ";
    }

    gotoxy(x + ((ancho - titulo.length())/2), y + 1);
    setColor(tituloColorDialogo, fondoColorDialogo);
    std::cout << titulo;
    gotoxy(x + ((ancho - cuerpo.length())/2), y + 3);
    setColor(cuerpoColorDialogo, fondoColorDialogo);
    std::cout << cuerpo;
    pintarBordes(ancho, alto, x, y);
    setColor(NEGRO, AMARILLO);

    static DMOUSE raton;
    bool clickeado = false;

    Boton botonSi;
    Boton botonNo;

    botonNo.establecerTexto("NO");
    botonSi.establecerTexto("SI");

    botonNo.establecerDimesion(13,1);
    botonSi.establecerDimesion(13,1);
    botonSi.establecerPosicion(x + ((ancho - (botonNo.obtenerAncho() * 2 )) / 2), y + alto - 2);
    botonNo.establecerPosicion(botonSi.obtenerXFin() + 4, y + alto - 2);
    botonSi.establecerColor(BLANCO_BRILLANTE, NEGRO);
    botonNo.establecerColor(BLANCO_BRILLANTE, NEGRO);
    botonNo.establecerColorPresionado(PLOMO, BLANCO_BRILLANTE);
    botonSi.establecerColorPresionado(PLOMO, BLANCO_BRILLANTE);

    botonNo.mostrar();
    botonSi.mostrar();
    do {
        mouse(&raton); // Espera el click del mouse

        if(raton.buttonPressed == MOUSE_BUTTON_LEFT) {
            // Boton Si
            if(raton.coordinates.X >= botonSi.obtenerX()
                && raton.coordinates.X <= botonSi.obtenerXFin()
                && raton.coordinates.Y >= botonSi.obtenerY()
                && raton.coordinates.Y <= botonSi.obtenerYFin()) {
                yes.play(true);
                botonSi.click();
                si = true;
                clickeado = true;
            }
            // Boton no
            else if(raton.coordinates.X >= botonNo.obtenerX()
                && raton.coordinates.X <= botonNo.obtenerXFin()
                && raton.coordinates.Y >= botonNo.obtenerY()
                && raton.coordinates.Y <= botonNo.obtenerYFin()) {
                si = false;
                no.play(true);
                botonNo.click();
                ocultar();
                clickeado = true;
            }
        }
    } while(!clickeado);
}

void Dialogo::ocultar() {
    setColor(fondoBorrar, fondoBorrar);
    for(int i = 0; i <= alto; i++) {
        gotoxy(x, y + i);
        std::cout << "                                         ";
    }
}

bool Dialogo::esSi() const {
    return si;
}

void Dialogo::establecerTitulo(std::string title) {
    titulo = title;
}

void Dialogo::establecerCuerpo(std::string body) {
    cuerpo = body;
}

void Dialogo::establecerDimension(short dimenAncho, short dimenAlto) {
    ancho = dimenAncho;
    alto = dimenAlto;
}

void Dialogo::establecerTema(Tema &theme) {
    fondoBorrar = theme.obtenerFondo();
    fondoColorDialogo = theme.obtenerFondoDialogo();
}

void Dialogo::establecerPosicion(short X, short Y) {
    x = X;
    y = Y;
}

#endif // DIALOGO_H
