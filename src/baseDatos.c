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
void salvaDatos(sListaJugadores listaJug) // Guarda los datos del jugador
{
    int k;

    FILE* saveData; // Variable especial para manejar archivos de texto

    saveData = fopen("jugadores.dat", "wt"); //Abre un nuevo archivo para almacenar texto, lo crea si no existe

    if (saveData == NULL) // El programa avisa en caso de que no se pueda abrir el archivo jugadores.dat
    {
        printf("\7");
        printf("\n    Error al abrir el archivo.\n\n    ");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }
    // Guarda en el fichero jugadores.dat todos los datos de los jugadores
    for(k = 0; k<listaJug.nJugadores ; k++)
    {
        fprintf(saveData, "%d %s %d %d %d\n", listaJug.VRegistros[k].ID, listaJug.VRegistros[k].nombre, listaJug.VRegistros[k].partidas, listaJug.VRegistros[k].MPuntuacion, listaJug.VRegistros[k].clasificacion);
    }

    if (fclose(saveData)!=0) // El programa avisa en caso de que no se pueda cerrar el archivo jugadores.dat
    {
        printf("\7");
        printf( "\n    Problemas al cerrar el archivo\n" );
        system("pause");
    }
    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado

    return;
}// fin de función

// inicio de función
void leeDatosPartida(sListaJugadores *listaJug) // Lee los datos de la partida
{

    FILE* saveData; // Variable especial para manejar archivos de texto

    int i = 0;

    saveData = fopen("jugadores.dat", "rt"); //Abre un nuevo archivo para leer texto

    if (saveData == NULL) // El programa avisa en caso de que no se pueda abrir el archivo jugadores.dat
    {
        printf("\7");
        printf("\n    Error al abrir el archivo.\n\n    ");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    rewind(saveData); // situa el puntero al principio del archivo

    // Carga en el vector del registro los datos de los jugadores
    for(i = 0; feof(saveData)==0 ; i++) // realiza una interacción de más sin leer nada de jugadores.dat.
    {
        listaJug->VRegistros = realloc((listaJug->VRegistros), (i+1)*sizeof(sJugador)); // incrementa en 1 el tamaño del vector para realizar una nueva lectura. Es i+1 pues i empieza a contar de 0 y el tamaño de un vector empieza en 1.

        fscanf(saveData, "%d", &(listaJug->VRegistros[i].ID)); // Guarda en la variable el número de identificación del jugador
        fscanf(saveData, "%s", (listaJug->VRegistros[i].nombre)); // Guarda en la variable el número de identificación del jugador
        fscanf(saveData, "%d", &(listaJug->VRegistros[i].partidas)); // Guarda en la variable las partidas jugadas por dicho jugador
        fscanf(saveData, "%d", &(listaJug->VRegistros[i].MPuntuacion)); // Guarda en la mejor puntuación conseguida por dicho jugador
        fscanf(saveData, "%d", &(listaJug->VRegistros[i].clasificacion)); // Guarda en la variable la clasificación de dicho jugador
    }

    // determina el número de jugadores
    listaJug->nJugadores = i-1; // es i-1 pues en la última interacción extra aumenta i pero no se produce lectura.

    if (fclose(saveData)!=0) // El programa avisa en caso de que no se pueda cerrar el archivo jugadores.dat

    {
        printf("\7");
        printf( "Problemas al cerrar el archivo\n" );
        system("pause");
    }

    return;
}// fin de función

// inicio de función
void ordenaDatos(sListaJugadores *listaJug)
{
    int k, i;

    sJugador temp;

    // Algoritmo de ordenación por puntos en orden descendente mediante dos bucles
    for(k=0; k < (listaJug->nJugadores)-1; k++)
    {
        for(i=0; i < (listaJug->nJugadores)-1; i++)
        {
            if((listaJug->VRegistros[i].MPuntuacion) < (listaJug->VRegistros[i+1].MPuntuacion))
            {
                temp = listaJug->VRegistros[i];
                listaJug->VRegistros[i] = listaJug->VRegistros[i+1];
                listaJug->VRegistros[i+1] = temp;
            }

        }
    }

    // Ahora se cambian(actualizan) los valores de la clasificación, (aunque igual no es necesario está ahi por si acaso)
    for(k = 0; k < listaJug->nJugadores; k++)
    {
        listaJug->VRegistros[k].clasificacion = (k+1);
    }

    return;
} // fin de función


int compruebaNuevoNombreJugador(char nombre[101])

{
    int i = 0, letras = 0, numeros = 0, error = 1, error1 = 1;

    if(strlen(nombre) < 6 || strlen(nombre) > 12) // Comprueba el número de caracteres
    {
        printf("\n\n    N\243mero de caracteres no v\240lido. (6 - 12)");
        error = 0;
    }

    while(nombre[i]!='\0')
    {
        if((nombre[i]>='a'&&nombre[i]<='z') || (nombre[i]>='A'&&nombre[i]<='Z')) // Suma el núm de letras
        {
            letras++;
        }

        else if(nombre[i]>='0'&&nombre[i]<='9') // Suma el núm de números
        {
            numeros++;
        }

        else if(nombre[i]=='_'); // Necesario para que no aparezca caracter no válido cuando metes _ por teclado

        else
        {
            if(error1 == 1)
            {
                printf("\n\n    Alg\243n caracter no es v\240lido, solo se admiten letras, n\243meros y guiones \n    bajos.");
                error1 = 0; // Evita la repetición del printf anterior
            }
            error = 0;
        }
        i++;
    }

    if(numeros == 0) // Control de error
    {
        printf("\n\n    Tienes que introducir al menos un n\243mero.");
        error = 0;
    }

    if(letras < 3) // Control de error
    {
        printf("\n\n    Tienes que introducir al menos dos letras.");
        error = 0;
    }

    printf("\n\n    ");

    return error;
}


int compruebaNombreAnteriorJugador(sListaJugadores lista, char nombre[13])

{
    int i;

    for(i=0; i < lista.nJugadores; i++)
    {
        if(strcmp(nombre, lista.VRegistros[i].nombre) == 0) // Si el nombre del jugador está registrado devuelve 1
        {
            return 1;
        }
    }
    return 0; // En caso contrario devuelve 0
}
