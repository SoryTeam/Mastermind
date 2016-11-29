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
    int partidas;
    int MPuntuacion;
    int clasificacion;
    char nombre[13];
} sJugador;

typedef struct
{
    sJugador *VRegistros;
    int nJugadores;
} sListaJugadores;

void salvaDatos(sListaJugadores);

void leeDatosPartida(sListaJugadores *); // Lee los datos de la partida

void ordenaDatos(sListaJugadores *);

int compruebaNuevoNombreJugador(char []);

int compruebaNombreAnteriorJugador(sListaJugadores, char []);
