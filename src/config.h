/*
    Autores:
    �scar Valderrama Garc�a (soryandroid@gmail.com)
    �ngel Moreno Ontoria
*/

#pragma once // directiva de preprocesador que evita que el archivo de cabecera se incluya de nuevo
#define TAM 40

// Se declararn las funciones y estructuras

typedef struct
{
    unsigned int numLDis : 5; // Campo de bits para el n�mero de letras que se pueden utilizar
    unsigned int numLCom : 4; // Campo de bits para el n�mero de letras que forman la combinaci�n
    unsigned int numIntentos : 7; // Campo de bits para el n�mero de intentos
    unsigned int repeticion : 1; // Campo de bits que indica si puede contener letras repetidas o no
    unsigned int cronometro : 1; // Campo de bits que indica si est� el cron�metro activado
    unsigned int duelo : 1; // Campo de bits que indica si est� el modo duelo activado
} sConfig;

void menuConfig(int*);

void salvaConfig(sConfig);

void mostrarConfig(sConfig); // los argumentos corresponden a la configuraci�n inicial del programa que lee del archivo config.ini

void leeConfig(sConfig *);

void leeConfigPrede(sConfig *);


