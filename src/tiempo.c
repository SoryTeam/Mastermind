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


void extraeFecha (sFecha* fecha) // Guarda la fecha del reloj del ordenador
{


    time_t ahora;

    struct tm *hoy;

    ahora = time (NULL);
    hoy = localtime(&ahora); // llena una estructura tm (local) con los datos actuales del reloj del sistema

    // carga en el programa los datos con formato adecuado

    fecha->dia = (hoy->tm_mday);
    fecha->mes = (hoy->tm_mon) + 1;
    fecha->anio = (hoy->tm_year) + 1900;

    return;
}


void extraeHora (sHora* hora) // Guarda la hora del reloj del ordenador
{
    time_t ahora;

    struct tm *now;

    ahora = time (NULL);
    now = localtime(&ahora); // llena una estructura tm (local) con los datos actuales del reloj del sistema

    // carga en el programa los datos con formato adecuado

    hora->segundos = (now->tm_sec);
    hora->minutos = (now->tm_min);
    hora->hora = (now->tm_hour);

    return;
}
