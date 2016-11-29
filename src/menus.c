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


void menuPrincipal(int *opcion) // Función que abre el menú principal

{
    int tabla;

    // Ajuste de presentación
    system("cls"); // Limpia la pantalla
    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
    // Muestra el menu de entrada de MasterMind

    printf("%c", 201);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t\t\t         Men\243 principal");
    for (tabla=0; tabla<=31; tabla++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 188);

    printf("\n\n     1 - Configuraci\242n.\n");
    printf("     2 - Comenzar la partida.\n");
    printf("     3 - Mejores Puntuaciones.\n");
    printf("     4 - Puntuaciones de jugador.\n");
    printf("     5 - Ampliaci\242n Individual.\n");
    printf("     0 - Salir del programa.\n\n");
    printf("  Selecciona la opci\242n deseada: \n\n   "); //Solicita una opción al usuario
    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
    scanf("%d", opcion); // Guarda en la variable el número de la opción elegida

    printf("\n\n  La opci\242n que usted seleccion\242 fue: %d\n\n\n  ", *opcion); //Muestra la elección del usuario

    // Ajustes de presentación
    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    return;
}

void menuConfigPerson(int* opcion)

{
    char tabla;

    system("cls"); // Limpia la pantalla

    // Muestra el menú

    printf("%c", 201);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t\t       Men\243 de configuraci\242n personalizada");
    for (tabla=0; tabla<=20; tabla++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 188);

    printf("\n    1.  N\243mero de letras disponibles.");
    printf("\n    2.  N\243mero de letras por combinaci\242n.");
    printf("\n    3.  N\243mero de intentos.");
    printf("\n    4.  Repetici\242n de letras.");
    printf("\n    5.  Modo cron\242metro.");
    printf("\n    6.  Modo duelo.");
    printf("\n    0.  Salir de la configuraci\242n personalizada.\n\n");
    printf("  Selecciona la opci\242n deseada: "); //Solicita una opción al usuario

    fflush(stdin);// Limpia el registro del último caracter introducido para que no haya problemas al introducir caracteres por teclado
    scanf("%d", opcion); // Guarda en la variable el número de la opción elegida

    printf("\n\n  La opci\242n que usted seleccion\242 fue: %d\n\n\n  ", *opcion); //Muestra la elección del usuario

    // Ajustes de presentación
    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    return;
}


int menuOrdena()
{
    int opcion, tabla;

    system("cls"); // Limpia la pantalla


    // Muestra el menú

    printf("%c", 201);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t\t              Men\243 de ordenaci\242n");
    for (tabla=0; tabla<=30; tabla++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 188);

    printf("\n     Elige c\242mo quieres ordenar las partidas:\n");
    printf("\n    1.  Ordenar por ID.");
    printf("\n    2.  Ordenar por puntos conseguidos.");
    printf("\n    3.  Ordenar por combinaci\242n secreta.");
    printf("\n    4.  Ordenar por hora.");
    printf("\n    0.  Volver al men\243 principal.\n\n");
    printf("  Selecciona la opci\242n deseada: "); //Solicita una opción al usuario

    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
    scanf("%d", &opcion); // Guarda en la variable el número de la opción elegida

    if(opcion < 0 || opcion > 4)
    {
        opcion = -1;
    }

    printf("\n\n  La opci\242n que usted seleccion\242 fue: %d\n\n\n  ", opcion); //Muestra la elección del usuario

    return opcion;
}

void menuPartidasJugador(int *opcion) // Función que abre el menú principal

{
    int tabla;

    // Ajuste de presentación
    system("cls"); // Limpia la pantalla
    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
    // Muestra el menu de entrada de MasterMind

    printf("%c", 201);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t\t\t         Men\243 principal");
    for (tabla=0; tabla<=31; tabla++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 188);

    printf("\n\n     1. Mostrar todas las partidas del jugador.\n");
    printf("     2. Mostrar las partidas del jugador de una fecha concreta.\n");
    printf("     3. Mostrar las partidas del jugador entre dos fechas.\n");
    printf("     0. Volver al men\243 anterior.\n\n");
    printf("  Selecciona la opci\242n deseada: \n\n   "); //Solicita una opción al usuario
    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
    scanf("%d", opcion); // Guarda en la variable el número de la opción elegida

    printf("\n\n  La opci\242n que usted seleccion\242 fue: %d\n\n\n  ", *opcion); //Muestra la elección del usuario

    // Ajustes de presentación
    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    return;
}
