/*
    Autores:
    Óscar Valderrama García (soryandroid@gmail.com)
    Ángel Moreno Ontoria
*/

#pragma once // directiva de preprocesador que evita que el archivo de cabecera se incluya de nuevo
#define TAM 40

// Se declaran las funciones y las estructuras

typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    int hora;
    int minutos;
    int segundos;
} sHora;

void extraeFecha (sFecha*);

void extraeHora (sHora*);



