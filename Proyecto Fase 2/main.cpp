#include <windows.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <conio.h>  // Para _getch()

using namespace std;

// PROTOTIPOS
void esperarTecla();
void Menu_FigurasGeometricas();
void dibujarCirculo();
void dibujarCuadrado();
void dibujarTriangulo();
void dibujarRectangulo();
void dibujarLinea();
void dibujarRombo();
void dibujarHexagono();
void opcionSalir();
void opcionInvalida();
void limpiarPantalla();
void seleccionarColorCaracter();
void seleccionarCaracter();
void grabarPantalla();
void abrirArchivo();

char caracterDibujo = '*';
int colorCaracter = 7; // Color blanco por defecto

int main() {
    system("cls");
    esperarTecla();
    return 0;
}

void esperarTecla() {
    while (true) {
        cin.clear();
        if (GetAsyncKeyState(VK_F12)) {
            Menu_FigurasGeometricas();
            break;
        } else if (GetAsyncKeyState(VK_ESCAPE)) {
            break;
        }
        Sleep(100); // Sleep for a while to reduce CPU usage
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
    cout << "\n5.  Linea";
    cout << "\n6.  Rombo";
    cout << "\n7.  Hexagono";
    cout << "\n8.  Seleccionar Caracter de Dibujo";
    cout << "\n9.  Limpiar Pantalla";
    cout << "\n10. Seleccionar Color de Caracter";
    cout << "\n11. Grabar Pantalla";
    cout << "\n12. Abrir Archivo";
    cout << "\n13. Salir";
    cout << endl << endl;
    cout << "Selecciona una Opcion :     ";
    cin >> valor;

    switch (valor) {
        case 1: dibujarCirculo(); break;
        case 2: dibujarCuadrado(); break;
        case 3: dibujarTriangulo(); break;
        case 4: dibujarRectangulo(); break;
        case 5: dibujarLinea(); break;
        case 6: dibujarRombo(); break;
        case 7: dibujarHexagono(); break;
        case 8: seleccionarCaracter(); break;
        case 9: limpiarPantalla(); break;
        case 10: seleccionarColorCaracter(); break;
        case 11: grabarPantalla(); break;
        case 12: abrirArchivo(); break;
        case 13: opcionSalir(); break;
        default: opcionInvalida(); break;
    }
}

void seleccionarCaracter() {
    system("cls");
    cout << "Favor ingresa el caracter para dibujar: ";
    cin >> caracterDibujo;
    Menu_FigurasGeometricas();
}

void seleccionarColorCaracter() {
    system("cls");
    cout << "Favor ingresa el codigo del color (0-15): ";
    cin >> colorCaracter;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCaracter);
    Menu_FigurasGeometricas();
}

void dibujarCirculo() {
    int radius = 0;
    system("cls");
    cout << endl;
    cout << "Favor ingresa el radio del circulo: ";
    cin >> radius;
    system("cls");
    cout << endl;
    double dist;
    for (int i = 0; i <= 2 * radius; i++) {
        for (int j = 0; j <= 2 * radius; j++) {
            dist = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
            if (dist > radius - 0.5 && dist < radius + 0.5) {
                cout << caracterDibujo;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl << endl;
    esperarTecla();
}

void dibujarCuadrado() {
    int tamanio;
    system("cls");
    cout << "Favor ingresa el tamaño del cuadrado: ";
    cin >> tamanio;
    system("cls");
    cout << endl;
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            if (i == 0 || i == tamanio - 1 || j == 0 || j == tamanio - 1)
                cout << caracterDibujo << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
    esperarTecla();
}

void dibujarTriangulo() {
    system("cls");
    cout << endl;
    int size;
    cout << "Ingresa el tamaño del triangulo: ";
    cin >> size;
    system("cls");
    cout << endl;

    int spaces = size - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        if (i == 0 || i == size - 1) {
            for (int j = 0; j < 2 * i + 1; j++) {
                cout << caracterDibujo;
            }
        } else {
            cout << caracterDibujo;
            for (int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            cout << caracterDibujo;
        }
        cout << endl;
        spaces--;
    }
    cout << endl;
    esperarTecla();
}

void dibujarRectangulo() {
    int ancho, alto;
    system("cls");
    cout << endl;

    cout << "Ingresa el ancho del rectangulo: ";
    cin >> ancho;
    cout << "Ingresa el alto del rectangulo: ";
    cin >> alto;
    system("cls");

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1)
                cout << caracterDibujo << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl << endl;
    esperarTecla();
}

void dibujarLinea() {
    int longitud, orientacion;
    system("cls");
    cout << "Favor ingresa la longitud de la linea: ";
    cin >> longitud;
    cout << "Selecciona la orientacion (1: Horizontal, 2: Vertical, 3: Diagonal, 4: Diagonal Invertida): ";
    cin >> orientacion;
    system("cls");

    switch (orientacion) {
        case 1: // Horizontal
            for (int i = 0; i < longitud; i++) cout << caracterDibujo;
            break;
        case 2: // Vertical
            for (int i = 0; i < longitud; i++) cout << caracterDibujo << endl;
            break;
        case 3: // Diagonal
            for (int i = 0; i < longitud; i++) {
                for (int j = 0; j < i; j++) cout << " ";
                cout << caracterDibujo << endl;
            }
            break;
        case 4: // Diagonal Invertida
            for (int i = 0; i < longitud; i++) {
                for (int j = longitud; j > i; j--) cout << " ";
                cout << caracterDibujo << endl;
            }
            break;
        default:
            cout << "Orientacion invalida";
            break;
    }
    cout << endl << endl;
    esperarTecla();
}

void dibujarRombo() {
    int lado;
    system("cls");
    cout << "Favor ingresa la longitud del lado del rombo: ";
    cin >> lado;
    system("cls");

    int n = lado * 2 - 1;
    for (int i = 0; i < n; i++) {
        int espacios = abs(lado - 1 - i);
        for (int j = 0; j < espacios; j++) {
            cout << " ";
        }
        for (int j = 0; j < n - 2 * espacios; j++) {
            cout << caracterDibujo;
        }
        cout << endl;
    }
    cout << endl << endl;
    esperarTecla();
}

void dibujarHexagono() {
    int lado;
    system("cls");
    cout << "Favor ingresa la longitud del lado del hexagono: ";
    cin >> lado;
    system("cls");

    int ancho = 2 * lado - 1;
    int altura = 2 * lado;
    for (int i = 0; i < altura; i++) {
        int espacios = abs(lado - 1 - i);
        for (int j = 0; j < espacios; j++) {
            cout << " ";
        }
        for (int j = 0; j < ancho + lado - 1 - 2 * espacios; j++) {
            cout << caracterDibujo;
        }
        cout << endl;
    }

    cout << endl << endl;
    esperarTecla();
}


void limpiarPantalla() {
    system("cls");
    Menu_FigurasGeometricas();
}

void grabarPantalla() {
    ofstream file;
    string nombreArchivo;
    system("cls");
    cout << "Favor ingresa el nombre del archivo para grabar: ";
    cin >> nombreArchivo;
    file.open(nombreArchivo.c_str());
    if (file.is_open()) {
        // Grabar el contenido de la pantalla en el archivo
        // En este ejemplo no hay una función para leer la pantalla de la consola
        // Implementar grabar el contenido que sea necesario
        file.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }
    Menu_FigurasGeometricas();
}

void abrirArchivo() {
    ifstream file;
    string nombreArchivo;
    system("cls");
    cout << "Favor ingresa el nombre del archivo para abrir: ";
    cin >> nombreArchivo;
    file.open(nombreArchivo.c_str());
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }
    esperarTecla();
}

void opcionSalir() {
    system("cls");
    int opcion;
    cout << endl << endl << endl;
    cout << "Estas seguro que deseas salir...????\n\n";
    cout << "\n1. SI";
    cout << "\n2. NO";
    cout << endl << endl << endl;
    cin >> opcion;

    if (opcion == 2) {
        main();
    }
}

void opcionInvalida() {
    system("cls");
    cout << endl;
    cout << endl;
    cout << "La opción seleccionada es invalida";
    cout << endl << endl << endl;
    system("pause");
    main();
}
