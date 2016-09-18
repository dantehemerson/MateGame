#ifndef NUMERO_H
#define NUMERO_H

#include <iostream>
#include <cstdlib>

#include "gotoxy.h"


class Numero {
    public:
        Numero(int num);
        void mover();
        void establecerFondo(short color);
    private:
        int color;
        short colorFondo;
        int x;
        int y;
        int numero;

};

Numero::Numero(int num) : numero(num) {
    color = 1;
    x = 1;
    y = 8;
    numero = 4;
    colorFondo = NEGRO;
}
void Numero::establecerFondo(short color) {
    colorFondo = color;
}
void Numero::mover() {
    color = rand() % 16;
    setColor(color, colorFondo);
    y = rand() % 25;
    numero = rand() % 10;
    if(x > 8 && x < 58) {
        x = 58;
    }
    if(x > 63) {
        x = 1;
    }
    gotoxy(x, y);
    std::cout << numero;
    gotoxy(x-1, y);
    std::cout << " ";

    x++;


}
#endif // NUMERO_H

