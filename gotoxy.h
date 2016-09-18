/**
*   Libreria gotoxy que se utiliza para posicionar el cursor en la pantalla,
*   ocultar el cursor y cambiar los colores del texto y fondo.
*/

#ifndef GOTOXY_H
#define GOTOXY_H

#include <windows.h>

#define KEY_HOME 71
#define KEY_UP 72
#define KEY_PGUP 73
#define KEY_LEFT 75
#define KEY_CENTER 76
#define KEY_RIGHT 77
#define KEY_END 79
#define KEY_DOWN 80
#define KEY_PGDN 81
#define KEY_INSERT 82
#define KEY_DELETE 83
#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F5 63
#define KEY_F6 64
#define KEY_F7 65
#define KEY_F8 66
#define KEY_F9 67

enum Colores {
    NEGRO, // 0
    AZUL, // 1
    VERDE, // 2
    CELESTE, // 3
    ROJO, // 4
    MORADO, // 5
    AMARILLO, // 6
    BLANCO, // 7
    PLOMO, // 8
    AZUL_CLARO, // 9
    VERDE_CLARO, // 10
    CELESTE_CLARO, // 11
    ROJO_CLARO, // 12
    MORADO_CLARO, // 13
    AMARILLO_CLARO, // 14
    BLANCO_BRILLANTE // 15
};

/**
*  Posiciona el cursor en una coordenada de la pantalla
*  @param x  La posicion en X
*  @param y  La posicion en Y
*/
void gotoxy(int x, int y) {

    COORD mCoord;
    mCoord.X = x;
    mCoord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mCoord);
}

/**
*   Cambia el color de fondo y del texto
*   @param textColor : Color para el texto (1 - 15).
*   @param backgroundColor : Color para el fondo(1 - 15), por defecto es negro.
*/
void setColor(int textColor, int backgroundColor = NEGRO) {

    int color = 16 * backgroundColor + textColor;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  color | (0 * 0x10 + 0x100));
}

/**
*   Oculta ó muestra el paradeo del cursor en la pantalla.
*   @param hide : Si es true oculta el cursor de otro modo lo muestra.
*/
void hideCursor(bool hide = true) {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 20;
    cursorInfo.bVisible = !hide;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

/**
*   Función que borra la pantalla.
*/
void clrscr() {
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
    return;
}

#endif // GOTOXY_H
