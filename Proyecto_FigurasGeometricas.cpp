#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>

using namespace std;

// Prototipos
void Menu_FigurasGeometricas();
void dibujarCirculo(int radius);
void dibujarCuadrado(int tamanio);
void dibujarTriangulo(int size);
void dibujarRectangulo(int ancho, int alto);
void opcionSalir();
void opcionInvalida();
void gotoxy(int x, int y);
void esperarF12();
void moverFigura(int figuraPosX, int figuraPosY, int figuraAncho, int figuraAlto, char tecla);

int main() {
    esperarF12();
    Menu_FigurasGeometricas();
    return 0;
}

void esperarF12() {
    while (true) {
        if (GetAsyncKeyState(VK_F12)) {
            break;
        }
        Sleep(100);
    }
}

void Menu_FigurasGeometricas() {
    system("cls");
    int valor = 0;

    cout << endl;
    cout << "******************************************\n";
    cout << "               BIENVENIDO                 \n";
    cout << "******************************************\n";
    cout << endl << endl;
    cout << "\n1.  Circulo";
    cout << "\n2.  Cuadrado";
    cout << "\n3.  Triangulo";
    cout << "\n4.  Rectangulo";
    cout << "\n5.  Salir";
    cout << endl << endl;
    cout << "Selecciona una Opción :     ";
    cin >> valor;

    if (valor == 1) {
        int radius;
        cout << "\nIngresa el radio del círculo: ";
        cin >> radius;
        dibujarCirculo(radius);
    } else if (valor == 2) {
        int tamanio;
        cout << "\nIngresa el tamaño del cuadrado: ";
        cin >> tamanio;
        dibujarCuadrado(tamanio);
    } else if (valor == 3) {
        int size;
        cout << "\nIngresa el tamaño del triángulo: ";
        cin >> size;
        dibujarTriangulo(size);
    } else if (valor == 4) {
        int ancho, alto;
        cout << "\nIngresa el ancho del rectángulo: ";
        cin >> ancho;
        cout << "Ingresa el alto del rectángulo: ";
        cin >> alto;
        dibujarRectangulo(ancho, alto);
    } else if (valor == 5) {
        opcionSalir();
    } else {
        opcionInvalida();
    }
}

void dibujarCirculo(int radius) {
    system("cls");
    cout << "\nDibujando círculo en la posición central...\n";

    int centerX = 40; // Posición central X
    int centerY = 10; // Posición central Y

    gotoxy(centerX, centerY);
    cout << "*";

    moverFigura(centerX, centerY, 2 * radius, 2 * radius, 'c');
}

void dibujarCuadrado(int tamanio) {
    system("cls");
    cout << "\nDibujando cuadrado en la posición central...\n";

    int centerX = 40; // Posición central X
    int centerY = 10; // Posición central Y

    gotoxy(centerX - tamanio / 2, centerY - tamanio / 2);
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            if (i == 0 || i == tamanio - 1 || j == 0 || j == tamanio - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
        gotoxy(centerX - tamanio / 2, centerY - tamanio / 2 + i + 1);
    }

    moverFigura(centerX, centerY, tamanio, tamanio, 's');
}

void dibujarTriangulo(int size) {
    system("cls");
    cout << "\nDibujando triángulo en la posición central...\n";

    int centerX = 40; // Posición central X
    int centerY = 10; // Posición central Y

    gotoxy(centerX - size / 2, centerY - size / 2);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i * 2 + 1; j++) {
            cout << "*";
        }
        cout << endl;
        gotoxy(centerX - size / 2 + i + 1, centerY - size / 2 + i + 1);
    }

    moverFigura(centerX, centerY, size, size, 't');
}

void dibujarRectangulo(int ancho, int alto) {
    system("cls");
    cout << "\nDibujando rectángulo en la posición central...\n";

    int centerX = 40; // Posición central X
    int centerY = 10; // Posición central Y

    gotoxy(centerX - ancho / 2, centerY - alto / 2);
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
        gotoxy(centerX - ancho / 2, centerY - alto / 2 + i + 1);
    }

    moverFigura(centerX, centerY, ancho, alto, 'r');
}

void opcionSalir() {
    system("cls");
    cout << "\nSaliendo del programa...\n";
    Sleep(1000); // Espera 1 segundo antes de salir
    exit(0);
}

void opcionInvalida() {
    system("cls");
    cout << "\nOpción inválida. Por favor, selecciona una opción válida.\n";
    Sleep(1000); // Espera 1 segundo para mostrar el mensaje
    Menu_FigurasGeometricas(); // Vuelve al menú de figuras geométricas
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void moverFigura(int figuraPosX, int figuraPosY, int figuraAncho, int figuraAlto, char tecla) {
    int posX = figuraPosX;
    int posY = figuraPosY;

    char movimiento = ' ';
    while (movimiento != 'q') {
        if (_kbhit()) {
            movimiento = _getch();
            switch (movimiento) {
                case 'w':
                    posY -= 1;
                    break;
                case 'a':
                    posX -= 1;
                    break;
                case 's':
                    posY += 1;
                    break;
                case 'd':
                    posX += 1;
                    break;
            }

            system("cls");
            gotoxy(posX - figuraAncho / 2, posY - figuraAlto / 2);
            for (int i = 0; i < figuraAlto; i++) {
                for (int j = 0; j < figuraAncho; j++) {
                    if (i == 0 || i == figuraAlto - 1 || j == 0 || j == figuraAncho - 1) {
                        cout << "* ";
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
                gotoxy(posX - figuraAncho / 2, posY - figuraAlto / 2 + i + 1);
            }
        }
    }
}

