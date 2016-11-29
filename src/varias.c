/*
    Autores:
    Óscar Valderrama García (soryandroid@gmail.com)
    Ángel Moreno Ontoria
*/

#include <stdio.h> // directiva de preprocesador que incluye la libreria necesaria para E/S
#include <stdlib.h> // directiva de preprocesador que incluye una libreria
#include <string.h> // directiva de preprocesador que incluye la libreria útil para trabajar con cadenas de caracteres
#include <time.h> // directiva de preprocesador que incluye la libreria útil para trabajar con funciones de tiempo
#include "tiempo.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "baseDatos.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "config.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "menu.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "partida.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "varias.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "ordena.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "ampli.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto

#define TAM 40

void intro () //introduce al jugador al juego
{
    int k;
    printf("%c", 201);
    for (k=0; k<=77; k++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (k=0; k<=77; k++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t\t\t   \255BIENVENIDO A MASTERMIND!");
    for (k=0; k<=26; k++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (k=0; k<=77; k++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (k=0; k<=77; k++)
        printf("%c", 205);
    printf("%c", 188);
    printf("\n\t\t\t    Instrucciones del juego\n\n    El objetivo del proyecto es crear una versi\242n del cl\240sico juego del \n Mastermind. Mastermind es un juego de mesa, de ingenio y reflexi\242n, para dos \n jugadores.\n\n    ");
    printf("Se juega en un tablero con fichas blancas y negras peque\244as y fichas de \n otros colores, de un tama\244o algo superior. Uno de los jugadores escoge un \n n\243mero de fichas de colores, 4 en el juego original, y pone una combinaci\242n\n secreta oculta de ese tama\244o.");
    printf(" El otro jugado, tomando fichas de colores del\n mismo conjunto, aventura una posibilidad de combinaci\242n tratando de acertar la\n original.");
    printf(" El jugador que puso el c\242digo secreto le informa mediante fichas\n negras y blancas sobre lo cerca que se ha quedado de acertar la combinaci\242n.");
    printf("\n Las fichas negras repesentan las fichas de color colocadas en la posici\242n\n correcta, es decir, que est\240n en la misma posici\242n en la combinaci\242n secreta.");
    printf("\n Las fichas blancas representan las fichas de color presentes en la\n combinaci\242n secreta, pero colocadas en distinta posici\242n.");
    printf("\n\n    El juego termina al averiguarse la combinaci\242n (es decir, se consigue una\n combinaci\242n con cuatro negras), o bien se agota el tablero (se supera el m\240ximo n\243mero de intentos que tiene el jugador para acertar la combinaci\242n secreta).");
    printf("\n\n    En nuestro caso, el programa ser\240 un juego para un jugador, que tendr\240 que\n adivinar una combinaci\242n de letras, generada por el ordenador.");
    printf(" La raz\242n de\n utilizar letras en lugar de colores es que en la consola del sistema no podemos utilizar colores, y tampoco dibujar c\241rculos, porque solamente podemos escribir texto y algunos s\241mbolos especiales.\n\n    ");
    return;
}

void salir() //Muestra un mensaje de despedida

{
    int k;

    printf("%c", 201);
    for (k=0; k<=77; k++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (k=0; k<=77; k++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t\t     \255\255\255GRACIAS POR JUGAR A MASTERMIND!!!");
    for (k=0; k<=21; k++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (k=0; k<=77; k++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (k=0; k<=77; k++)
        printf("%c", 205);
    printf("%c\n\n    ", 188);


    system("pause"); // Pausa la ejecución del programa //Pausa el programa
    system("cls"); // Limpia la pantalla //Limpia la pantalla

    return;

}
