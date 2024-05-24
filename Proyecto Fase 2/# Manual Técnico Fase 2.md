# Manual Técnico

## Introducción
Este programa en C++ permite dibujar diversas figuras geométricas en la consola de Windows. Además de dibujar figuras, proporciona opciones para configurar el carácter de dibujo, seleccionar el color del carácter, limpiar la pantalla, grabar la pantalla en un archivo y abrir archivos grabados previamente.

## Requisitos del Sistema
- Sistema operativo: Windows.
- Compilador de C++ compatible con la API de Windows.

## Estructura del Código
El código fuente consta de un archivo principal `main.cpp` y hace uso de varias bibliotecas estándar de C++ y de la API de Windows. Aquí se describen los principales componentes y funciones del código:

- **Funciones Principales:**
  - `main()`: Inicia el programa y muestra un mensaje de bienvenida.
  - `esperarTecla()`: Espera la pulsación de teclas para activar el menú principal o salir del programa.
  - `Menu_FigurasGeometricas()`: Muestra el menú principal y gestiona la selección de opciones.

- **Funciones de Dibujo de Figuras Geométricas:**
  - Funciones dedicadas a dibujar círculos, cuadrados, triángulos, rectángulos, líneas, rombos y hexágonos. Solicitan al usuario los parámetros necesarios y utilizan algoritmos específicos para generar la figura en la consola.

- **Funciones de Configuración:**
  - `seleccionarCaracter()`: Permite al usuario seleccionar el carácter de dibujo.
  - `seleccionarColorCaracter()`: Permite al usuario seleccionar el color del carácter.
  - `limpiarPantalla()`: Limpia la pantalla de la consola.
  - `grabarPantalla()`: Permite al usuario grabar el contenido de la pantalla en un archivo de texto.
  - `abrirArchivo()`: Permite al usuario abrir un archivo previamente grabado.

- **Otras Funciones Auxiliares:**
  - `opcionSalir()`: Confirma si el usuario desea salir del programa.
  - `opcionInvalida()`: Maneja las opciones inválidas seleccionadas por el usuario.

## Compilación y Ejecución
Para compilar el programa, se utiliza un compilador de C++ compatible con la API de Windows, como Visual Studio o MinGW. Se puede compilar utilizando el siguiente comando:

```bash
g++ main.cpp -o programa.exe
