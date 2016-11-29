/*
    Autores:
    Óscar Valderrama García (soryandroid@gmail.com)
    Ángel Moreno Ontoria
*/

#pragma once // directiva de preprocesador que evita que el archivo de cabecera se incluya de nuevo
#define TAM 40

// Se declararn las funciones y estructuras

typedef struct
{
    int ID;
    int intentos;
    int tiempo;
    int puntosConseguidos;
    char combinacion[30];
    int letrasDisponibles;
    int letrasCombinacion;
    int numeroIntentos;
    int repeticion;
    int modoDuelo;
    sFecha partFech;
    sHora partHora;
    char nombre[13];
} sPartida;

typedef struct
{
    int nPartidasV;
    sPartida *VRegPart;
} sListaPartidas;


void jugarPartida(sListaJugadores *, sJugador *, sConfig);

int leePartidas(sPartida **);

int leePartidasJugador(sPartida **, char []);

void muestraPartidas(sListaPartidas );

void agregaPartida(sPartida );

void mejoresPuntuaciones(sListaJugadores );

void generaCombi(char *, sConfig);

void introduceCombiJugador (char *, sConfig);

int compruebaCombiJugador (char *, char *, sConfig);

sListaPartidas creaListaPartidas(sPartida *, int);

void muestraPartidasFecha(sListaPartidas, sFecha);

void muestraPartidasEntreFecha(sListaPartidas, sFecha, sFecha);


