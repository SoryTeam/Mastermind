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

// inicio de funcion
void menuConfig(int *opcion) // Abre el menú de configuración
{
    int tabla;

    system("cls"); // Limpia la pantalla
    // Se despliega el menú de configuracion

    printf("%c", 201);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t\t\t     Men\243 de configuraci\242n");
    for (tabla=0; tabla<=28; tabla++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (tabla=0; tabla<=77; tabla++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (tabla=0; tabla<=77; tabla++)
        printf("%c", 205);
    printf("%c", 188);

    printf("\n\tSelecciona una opci\242n:\n\n\t    1. Nivel de Dificultad\n\t    2. Configuraci\242n personalizada\n\t    3. Salvar configuraci\242n\n\t    4. Restaurar configuraci\242n predeterminada\n\t    0. Men\243 anterior\n\n");
    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
    printf("\t");
    scanf("%d", opcion); // Almacena la elección del ususario

    printf("\n\n\tLa opci\242n que usted seleccion\242 fue: %d\n\n\n\t", *opcion); //Muestra la elección del usuario

    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    return;
} // fin de funcion

// inicio de funcion
void salvaConfig(sConfig config) // Guarda en el archivo config.ini la configuración del juego
{

    FILE* saveConfig; // Variable especial para manejar archivos de texto

    saveConfig = fopen("config.ini", "wt"); //Abre un nuevo archivo para almacenar texto

    if (saveConfig == NULL) // El programa avisa en caso de que no se pueda abrir el archivo config.ini
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    // Escribe la configuración de MasterMind en un documento de texto tipo .ini
    fprintf(saveConfig, "%d %d %d %d %d %d" , config.numLDis, config.numLCom, config.numIntentos, config.repeticion, config.cronometro, config.duelo);

    printf("\n\n\tSe ha guardado la configuraci\242n correctamente.\n\n\t");

    if (fclose(saveConfig)!=0) // El programa avisa en caso de que no se pueda cerrar el archivo config.ini
    {
        printf( "Problemas al cerrar el archivo\n" );
        printf("\7");
        system("pause");
    }

    return;
}// fin de función

// inicio de funcion
void mostrarConfig(sConfig config)

{
    char indRepet[3];

    system("cls"); // Limpia la pantalla

    if(config.repeticion==1) // Si es posible repetir letras en el juego se almacena 'Si' para mostrarlo más adelante
    {
        indRepet[0]='S';
        indRepet[1]='i';
        indRepet[2]='\0';
    }

    else if(config.repeticion==0) // Si no es posible repetir letras en el juego se almacena 'No' para mostrarlo más adelante
    {

        indRepet[0]='N';
        indRepet[1]='o';
        indRepet[2]='\0';
    }
    else // Muestra un mensaje de error en caso de que la variable repeticion no sea 0 ni 1
    {
        printf("\7");
        printf("\n  Ha habido alg\243n error en la lectura del dato 'repeticion' por favor, restaure la configuraci\242n a la predeterminada y reinicie el programa.\n\n  ");
        system("pause"); // Pausa la ejecución del programa
        return;
    }


    // Muestra en pantalla las condiciones iniciales de MasterMind
    printf("\n\n_______________________________________________________________________________\n");
    printf("  Letras Disponibles\tLetras por combinaci\242n     Intentos     Repetici\242n");
    printf("\n_______________________________________________________________________________\n");
    printf("\t %d\t\t\t  %d\t\t      %d\t            %c%c", config.numLDis, config.numLCom, config.numIntentos, indRepet[0], indRepet[1]);
    printf("\n_______________________________________________________________________________\n\n  ");


    printf("  \250Modo cron\242metro activado?: ");

    if (config.cronometro == 0)
    {
        printf("No");
    }
    else
    {
        printf("Si");
    }

    printf("\n    \250Modo duelo activado?: ");

    if (config.duelo == 0)
    {
        printf("No");
    }
    else
    {
        printf("Si");
    }

    printf("\n\n    ");

    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    return;
}// fin de función


// inicio de funcion
void leeConfig(sConfig *config)

{
    unsigned int temp; // Variable auxiliar para cargar correctamente la configuración

    FILE* entrada; // Variable especial para manejar archivos de texto


    entrada = fopen("config.ini", "rt"); //Abre un nuevo archivo para leer texto

    if (entrada == NULL) // El programa avisa en caso de que no se pueda abrir el archivo config.ini
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    fscanf(entrada, "%d", &temp); // Guarda en la variable el número de letras que se pueden utilizar
    config->numLDis = temp;
    fscanf(entrada, "%d", &temp); // Guarda en la variable el número de letras que forman la combinación
    config->numLCom = temp;
    fscanf(entrada, "%d", &temp); // Guarda en la variable el número de intentos
    config->numIntentos = temp;
    fscanf(entrada, "%d", &temp); // Guarda en la variable si puede contener letras repetidas
    config->repeticion = temp;
    fscanf(entrada, "%d", &temp); // Guarda en la variable si esta activado o no el modo cronómetro
    config->cronometro = temp;
    fscanf(entrada, "%d", &temp); // Guarda en la variable si esta activado o no el modo duelo
    config->duelo = temp;

    if (fclose(entrada)!=0) // El programa avisa en caso de que no se pueda cerrar el archivo config.ini
    {
        printf("\7");
        printf( "Problemas al cerrar el archivo\n" );
        system("pause");
    }
    return;

}// fin de función

// inicio de funcion
void leeConfigPrede(sConfig *config)

{
    unsigned int temp; // Variable auxiliar para cargar correctamente la configuración

    FILE* config_person;

    config_person=fopen("defaultConfig.ini", "rt"); //Abre un nuevo archivo para leer texto

    if (config_person == NULL) // El programa avisa en caso de que no se pueda abrir el archivo defaultConfig.ini
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    fscanf(config_person, "%d", &temp); // Guarda en la variable el número de letras que se pueden utilizar
    config->numLDis = temp;
    fscanf(config_person, "%d", &temp); // Guarda en la variable el número de letras que forman la combinación
    config->numLCom = temp;
    fscanf(config_person, "%d", &temp); // Guarda en la variable el número de intentos
    config->numIntentos = temp;
    fscanf(config_person, "%d", &temp); // Guarda en la variable si puede contener letras repetidas
    config->repeticion = temp;
    fscanf(config_person, "%d", &temp); // Guarda en la variable si esta activado o no el modo cronómetro
    config->cronometro = temp;
    fscanf(config_person, "%d", &temp); // Guarda en la variable si esta activado o no el modo duelo
    config->duelo = temp;

    if (fclose(config_person)!=0) // El programa avisa en caso de que no se pueda cerrar el archivo defaultConfig.ini
    {
        printf("\7");
        printf( "Problemas al cerrar el archivo\n" );
        system("pause");
    }

}// fin de función


