/*
    Autores:
    Óscar Valderrama García (soryandroid@gmail.com)
    Ángel Moreno Ontoria
*/

#pragma once // directiva de preprocesador que evita que el archivo de cabecera se incluya de nuevo
#include "tiempo.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto
#include "baseDatos.h" // directiva de preprocesador que incluye un archivo de cabecera local al proyecto

#define TAM2 30

typedef struct
{
    int puntos;
    sFecha fecha;
} sPartidaAmpli;

typedef struct
{
    int partidasResumidas;
    sPartidaAmpli VpartidasResumidas[TAM];
} sListaPartidaAmpli;

typedef struct
{
    sJugador *Jugadores;
    int nJugadores;
    sListaPartidaAmpli vRegResu[TAM];
} sListaJugadoresPartidas;

void creaListaJugadoresPartidas(sListaJugadores listaJug, sListaPartidas listaPartida);
