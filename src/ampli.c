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

#define TAM2 30



void creaListaJugadoresPartidas(sListaJugadores listaJug, sListaPartidas listaPartida)
{
    sListaJugadoresPartidas jugPartidas;
    sListaPartidaAmpli PartidasResumidas;
    sPartida temp;
    sListaPartidaAmpli temp2[TAM2];
    sPartidaAmpli temp3;
    char nombreMost[13];
    int elemVect = 0;
    int k = 0, i = 0, t = 0;
    int IDmax = 0;

    FILE* jugadores;

    FILE* partidas;

    // redimensiono el vector dinámico según el numero de jugadores

    jugPartidas.Jugadores = NULL;

    (jugPartidas.Jugadores) = realloc((jugPartidas.Jugadores), sizeof(sJugador)*(listaJug.nJugadores));

    // cargo en el vector dinámico los jugadores

    for(k=0; k<(listaJug.nJugadores); k++)
    {
        jugPartidas.Jugadores[k] = listaJug.VRegistros[k];
    }

    jugPartidas.nJugadores = listaJug.nJugadores;

    // Busco el último ID registrado

    for(i = 0; i < listaJug.nJugadores; i++)
    {
        if(listaJug.VRegistros[i].ID > IDmax)
        {
            IDmax = listaJug.VRegistros[i].ID;
        }
    }

// ordeno todas las partidas por ID (orden creciente) para agrupar las partidas de un mismo jugador

    for(k=0; k < (listaPartida.nPartidasV-1); k++)
    {
        for(i=0; i < (listaPartida.nPartidasV-1); i++)
        {
            if((listaPartida.VRegPart[i].ID) > (listaPartida.VRegPart[i+1].ID))
            {
                temp = listaPartida.VRegPart[i];
                listaPartida.VRegPart[i] = listaPartida.VRegPart[i+1];
                listaPartida.VRegPart[i+1] = temp;
            }
        }
    }

// resumo todas las partidas

    PartidasResumidas.partidasResumidas = listaPartida.nPartidasV;

    for(k = 0; k<(listaPartida.nPartidasV); k++)
    {
        PartidasResumidas.VpartidasResumidas[k].puntos = listaPartida.VRegPart[k].puntosConseguidos;
        PartidasResumidas.VpartidasResumidas[k].fecha = listaPartida.VRegPart[k].partFech;
    }

// cargo en cada lista de partida resumidas (miembro del vector) las partidas resumidas de un jugador

    t = 0;

    for(k = 1; k<=IDmax; k++)
    {
        for(i = 0; i<(listaPartida.nPartidasV); i++)
        {
            if(listaPartida.VRegPart[i].ID == k)
            {
                temp2[t].VpartidasResumidas[t] = PartidasResumidas.VpartidasResumidas[i];
                temp2[t].partidasResumidas++;
            }
        }
        jugPartidas.vRegResu[t] = temp2[t];
        jugPartidas.nJugadores = t;
        t++;
    }


// algoritmo de ordenación: ordena las partidas por puntos en orden creciente, y a igual puntos ordena por orden decreciente de letras por combinación.
    for(k=0; k < (jugPartidas.vRegResu[k].partidasResumidas-1); k++)
    {
        for(i=0; i < (jugPartidas.vRegResu[k].partidasResumidas-1); i++)
        {
            if((jugPartidas.vRegResu[k].VpartidasResumidas[i].puntos) > (jugPartidas.vRegResu[k].VpartidasResumidas[i+1].puntos))
            {
                temp3 = (jugPartidas.vRegResu[k].VpartidasResumidas[i]);
                (jugPartidas.vRegResu[k].VpartidasResumidas[i]) = (jugPartidas.vRegResu[k].VpartidasResumidas[i+1]);
                (jugPartidas.vRegResu[k].VpartidasResumidas[i+1]) = temp3;
            }

        }
    }

    jugadores = fopen("partidasAmpli.txt", "at");  //Abre un nuevo archivo para escribir texto

    partidas = fopen("partidaAmpli.bin", "wb"); //Abre un nuevo archivo para escribir texto

    if (jugadores == NULL) // El programa avisa en caso de que no se pueda abrir el archivo config.ini
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    if (partidas == NULL) // El programa avisa en caso de que no se pueda abrir el archivo config.ini
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }


    printf("\n\n Nombre       Puntos de la partida con mas puntos    Fecha");
    for(k = 0; k < listaJug.nJugadores; k++)
    {
        // Busca el nombre del jugador que vamos a mostrar
        for(i = 0; i< listaJug.nJugadores; i++)
        {
            if(listaJug.VRegistros[i].ID == k)
            {
                // Copia el nombre del jugador a una cadena temporal
                for(t = 0; t < 13; t++)
                {
                    nombreMost[t] = listaJug.VRegistros[i].nombre[t];

                    if(listaJug.VRegistros[i].nombre[t] == '\0')
                    {
                        break;
                    }
                }
                break;
            }
        }
        // para cada lista de partidas de un jugador busca la posición de la última partida
        elemVect = jugPartidas.vRegResu[k].partidasResumidas;
        // Muestra las partidas que nos interesan
        printf("\n %s                   %d                         %2d/%2d/%4d", nombreMost, (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].puntos), (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].fecha.dia), (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].fecha.mes), (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].fecha.anio));

        fprintf(jugadores, "\n %s                   %d                         %2d/%2d/%4d", nombreMost, (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].puntos), (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].fecha.dia), (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].fecha.mes), (jugPartidas.vRegResu[k].VpartidasResumidas[elemVect].fecha.anio));

        fwrite(&jugPartidas.vRegResu[k].VpartidasResumidas[elemVect], sizeof(sPartidaAmpli), 1, partidas); // escribe la partida
    }

    if (fclose(jugadores)!=0)
    {
        printf("\7");
        printf( "\nProblemas al cerrar el archivo\n" );
        system("pause"); // Pausa la ejecución del programa
        printf("\n");
    }


    if (fclose(partidas)!=0)
    {
        printf("\7");
        printf( "\nProblemas al cerrar el archivo\n" );
        system("pause"); // Pausa la ejecución del programa
        printf("\n");
    }

    free((jugPartidas.Jugadores));

    printf("\n\n");
    system("pause"); // Pausa la ejecución del programa

    return;
}
