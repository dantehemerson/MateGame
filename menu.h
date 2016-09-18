#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

#include "raton.cc"
#include "gotoxy.h"
#include "tema.h"
#include "funciones.h"
#include "sonido.h"

typedef std::vector<std::string> vs;

enum Alineamiento {
    IZQUIERDA,
    CENTRO,
    DERECHA
};

//Clase principal
class Menu {

    public:
        explicit Menu(vs opcionesMenu);

        void mostrar();

        void establecerEspaciado(int espacios);

        void establecerOpciones(vs opcionesMenu);

        void establecerPosicion(int X, int Y);

        void establecerAncho(int anchoMenu);

        void establecerAlineamiento(int alineamientoTexto);

        void establecerTema(Tema&);

        void animarMenu(bool anim);

        void establecerColor(int textoColor, int fondoColor);

        void establecerColorPress(int textoPressColor, int fondoPressColor);

        int obtenerOpcionSeleccionada() const;


    private:

        void pintarOpcion(int opcion);
        int x;
        int y;
        int espaciado;
        vs opciones;
        int ancho;
        int animar;
        int opcionSeleccionada;
        int alineamiento;
        int colorTexto;
        int colorFondo;
        int colorTextoPress;
        int colorFondoPress;
};


Menu::Menu(vs opcionesMenu) : opciones(opcionesMenu){
    alineamiento = CENTRO;
    espaciado = 4;
    animar = false;
    ancho = 30;
    x = y = 0;
    opcionSeleccionada = 0;
    colorTexto = BLANCO_BRILLANTE;
    colorFondo = CELESTE;
    colorFondoPress = VERDE_CLARO;
    colorTextoPress = NEGRO;
}

void Menu::mostrar() {
    static DMOUSE raton;
    static Wave click("sounds/CLICK.WAV");
    bool clickeado = false;

    do {
        if(animar)
        Sleep(80);
        for(size_t i = 0; i < opciones.size(); i++) {
            setColor(colorTexto, colorFondo);
            pintarOpcion(i);
            if(animar)
            Sleep(70);
        }
        mouse(&raton);

        if(raton.buttonPressed == MOUSE_BUTTON_LEFT) {
            if(raton.coordinates.X >= x && raton.coordinates.X < (x + ancho + 2 * espaciado)) {
                if(raton.coordinates.Y >= y && raton.coordinates.Y < (y + 3 * opciones.size())) {
                    for(size_t i = 0; i < opciones.size(); i++) {
                        if(raton.coordinates.Y >= y + i * 3 && raton.coordinates.Y <= y + i * 3 + 2) {
                            opcionSeleccionada = i;
                            click.play(true);
                            clickeado = true;
                        }
                    }
                    setColor(colorTextoPress, colorFondoPress);
                    pintarOpcion(opcionSeleccionada);
                    setColor(NEGRO, NEGRO);
                    Sleep(200);
                }
            }
        }

    } while(!clickeado);
}
void Menu::pintarOpcion(int opcion) {
    unsigned int longitudMax = ancho + 2 * espaciado;
    int espaciosIzquierda = 0;
    int espaciosDerecha = 0;

    int yInicio = y + opcion * 3;

    switch(alineamiento) {
        case IZQUIERDA:
            espaciosIzquierda = espaciado;
            espaciosDerecha = longitudMax - opciones[opcion].length() - espaciado;
            break;
        case DERECHA:
            espaciosIzquierda = longitudMax - opciones[opcion].length() - espaciado;
            espaciosDerecha = espaciado;
            break;
        default:
            espaciosIzquierda = (longitudMax - opciones[opcion].length()) / 2;
            espaciosDerecha  = longitudMax - espaciosIzquierda - opciones[opcion].length();
            break;
    }

    gotoxy(x, yInicio);
    for(int i = 1; i <= longitudMax; i++) {
        std::cout << " ";
    }

    gotoxy(x, ++yInicio);
    for(int i = 1; i <= espaciosIzquierda; i++) {
        std::cout << " ";
    }
    std::cout << opciones[opcion];
    for(int i = 1; i <= espaciosDerecha; i++) {
        std::cout << " ";
    }

    gotoxy(x, ++yInicio);
    for(size_t i = 1; i <= longitudMax; i++) {
        if(opcion == opciones.size() - 1) {
            std::cout << " ";
        }
        else {
            std::cout << "_";
        }
    }
}

void Menu::establecerEspaciado(int espacios) {
    espaciado = espacios;
}

void Menu::establecerOpciones(vs opcionesMenu) {
    opciones = opcionesMenu;
}

void Menu::establecerPosicion(int X, int Y) {
    x = X;
    y = Y;
}

void Menu::establecerTema(Tema &theme) {
    colorFondo = theme.obtenerFondoBoton();
    colorTexto = theme.obtenerTextoBoton();
    colorFondoPress = theme.obtenerFondoBotonPress();
    colorTextoPress = theme.obtenerTextoBotonPress();
}

void Menu::establecerColor(int textoColor, int fondoColor) {
    colorTexto = textoColor;
    colorFondo = fondoColor;
}

void Menu::establecerColorPress(int textoColorPress, int fondoPressColor) {
    colorTextoPress = textoColorPress;
    colorFondoPress = fondoPressColor;
}

void Menu::establecerAncho(int anchoMenu) {
    ancho = anchoMenu;
}

void Menu::establecerAlineamiento(int alineamientoTexto) {
    alineamiento = alineamientoTexto;
}

int Menu::obtenerOpcionSeleccionada() const {
    return opcionSeleccionada + 1;
}

void Menu::animarMenu(bool anim) {
    animar = anim;
}

#endif // MENU_H
