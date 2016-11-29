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
    unsigned int numLDis : 5; // Campo de bits para el número de letras que se pueden utilizar
    unsigned int numLCom : 4; // Campo de bits para el número de letras que forman la combinación
    unsigned int numIntentos : 7; // Campo de bits para el número de intentos
    unsigned int repeticion : 1; // Campo de bits que indica si puede contener letras repetidas o no
    unsigned int cronometro : 1; // Campo de bits que indica si está el cronómetro activado
    unsigned int duelo : 1; // Campo de bits que indica si está el modo duelo activado
} sConfig;

void menuConfig(int*);

void salvaConfig(sConfig);

void mostrarConfig(sConfig); // los argumentos corresponden a la configuración inicial del programa que lee del archivo config.ini

void leeConfig(sConfig *);

void leeConfigPrede(sConfig *);


