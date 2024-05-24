# Manual de Usuario

## Introducción
Este programa en C++ te permite dibujar diversas figuras geométricas en la consola de Windows. Además de dibujar figuras, ofrece opciones para configurar el carácter de dibujo, seleccionar el color del carácter, limpiar la pantalla, grabar la pantalla en un archivo y abrir archivos grabados previamente.

## Interfaz de Usuario
Al iniciar el programa, se mostrará un mensaje de bienvenida y se esperará a que el usuario presione una tecla. Una vez activado, se mostrará el menú principal con las siguientes opciones:

1. **Círculo**: Permite dibujar un círculo en la consola.
2. **Cuadrado**: Permite dibujar un cuadrado en la consola.
3. **Triángulo**: Permite dibujar un triángulo en la consola.
4. **Rectángulo**: Permite dibujar un rectángulo en la consola.
5. **Línea**: Permite dibujar una línea en la consola en diferentes orientaciones.
6. **Rombo**: Permite dibujar un rombo en la consola.
7. **Hexágono**: Permite dibujar un hexágono en la consola.
8. **Seleccionar Carácter de Dibujo**: Permite al usuario seleccionar el carácter que se utilizará para dibujar las figuras.
9. **Limpiar Pantalla**: Limpia la pantalla de la consola.
10. **Seleccionar Color de Carácter**: Permite al usuario seleccionar el color del carácter utilizado para dibujar.
11. **Grabar Pantalla**: Guarda el contenido actual de la pantalla en un archivo de texto.
12. **Abrir Archivo**: Permite al usuario abrir un archivo grabado previamente para ver su contenido.
13. **Salir**: Sale del programa.

## Uso del Programa
- Para seleccionar una opción del menú, ingresa el número correspondiente y presiona Enter.
- Sigue las instrucciones en pantalla para ingresar los parámetros necesarios, como el tamaño del círculo, cuadrado, triángulo, etc.
- Después de cada acción, se mostrará el resultado en la consola y se esperará a que el usuario presione una tecla para volver al menú principal.
- Si necesitas volver al menú principal en cualquier momento, presiona la tecla F12.
- Si deseas salir del programa en cualquier momento, presiona la tecla Escape o selecciona la opción "Salir" en el menú principal.

## Compilación y Ejecución
- Este programa se compila utilizando un compilador de C++ compatible con la API de Windows, como Visual Studio o MinGW.
- Para compilar el programa, utiliza el siguiente comando en la terminal:
  ```bash
  g++ main.cpp -o programa.exe
