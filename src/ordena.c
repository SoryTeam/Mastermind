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
#define VERDADERO 1
#define FALSO 0



void ordenaID(sPartida *Vpartidas, int nPart)
{
    int i, k;

    sPartida temp;

// algoritmo de ordenación: ordena las partidas por ID en orden creciente, y a igual ID ordena por orden decreciente de puntos
    for(k=0; k < (nPart-1); k++)
    {
        for(i=0; i < (nPart-1); i++)
        {
            if((Vpartidas[i].ID) > (Vpartidas[i+1].ID))
            {
                temp = Vpartidas[i];
                Vpartidas[i] = Vpartidas[i+1];
                Vpartidas[i+1] = temp;
            }
            else if((Vpartidas[i].ID) == (Vpartidas[i+1].ID))
            {
                if(Vpartidas[i].puntosConseguidos < Vpartidas[i+1].puntosConseguidos)
                {
                    temp = Vpartidas[i];
                    Vpartidas[i] = Vpartidas[i+1];
                    Vpartidas[i+1] = temp;
                }
            }
        }
    }

    return;
}

void ordenaPuntos(sPartida *Vpartidas, int nPart)
{
    int i, k;

    sPartida temp;

// algoritmo de ordenación: ordena las partidas por puntos en orden decreciente, y a igual puntos ordena por orden decreciente de letras por combinación.
    for(k=0; k < (nPart-1); k++)
    {
        for(i=0; i < (nPart-1); i++)
        {
            if((Vpartidas[i].puntosConseguidos) < (Vpartidas[i+1].puntosConseguidos))
            {
                temp = Vpartidas[i];
                Vpartidas[i] = Vpartidas[i+1];
                Vpartidas[i+1] = temp;
            }
            else if((Vpartidas[i].puntosConseguidos) == (Vpartidas[i+1].puntosConseguidos))
            {
                if(Vpartidas[i].letrasCombinacion < Vpartidas[i+1].letrasCombinacion)
                {
                    temp = Vpartidas[i];
                    Vpartidas[i] = Vpartidas[i+1];
                    Vpartidas[i+1] = temp;
                }
            }
        }
    }



    return;
}

void ordenaCombi(sPartida *Vpartidas, int nPart)
{
    int i, k;

    sPartida temp;

    // algoritmo de ordenación: ordena las partidas alfabéticamente

    for(k=0; k < (nPart-1); k++)
    {
        for(i=0; i < (nPart-1); i++)
        {
            if(strcmp(Vpartidas[i].combinacion, Vpartidas[i+1].combinacion) > 0)
            {
                temp = Vpartidas[i];
                Vpartidas[i] = Vpartidas[i+1];
                Vpartidas[i+1] = temp;
            }
        }
    }


    return;
}

void ordenaHora(sPartida *Vpartidas, int nPart)
{

    int i, k, cambio = FALSO;

    sPartida temp;


// algoritmo de ordenación: ordena las partidas por fecha de la mas reciente a la mas antigua
    for(k=0; k < (nPart-1); k++)
    {
        for(i=0; i < (nPart-1); i++)
        {
            if((Vpartidas[i].partFech.anio) < (Vpartidas[i+1].partFech.anio))
            {
                cambio = VERDADERO;
            }
            else if((Vpartidas[i].partFech.anio) == (Vpartidas[i+1].partFech.anio))
            {
                if((Vpartidas[i].partFech.mes) < (Vpartidas[i+1].partFech.mes))
                {
                    cambio = VERDADERO;
                }
                else if((Vpartidas[i].partFech.mes) == (Vpartidas[i+1].partFech.mes))
                {
                    if((Vpartidas[i].partFech.dia) < (Vpartidas[i+1].partFech.dia))
                    {
                        cambio = VERDADERO;
                    }
                    else if((Vpartidas[i].partFech.dia) == (Vpartidas[i+1].partFech.dia))
                    {
                        if((Vpartidas[i].partHora.hora) < (Vpartidas[i+1].partHora.hora))
                        {
                            cambio = VERDADERO;
                        }
                        else if((Vpartidas[i].partHora.hora) == (Vpartidas[i+1].partHora.hora))
                        {
                            if((Vpartidas[i].partHora.minutos) < (Vpartidas[i+1].partHora.minutos))
                            {
                                cambio = VERDADERO;
                            }
                            else if((Vpartidas[i].partHora.minutos) == (Vpartidas[i+1].partHora.minutos))
                            {
                                if((Vpartidas[i].partHora.segundos) < (Vpartidas[i+1].partHora.segundos))
                                {
                                    cambio = VERDADERO;
                                }
                            }
                        }
                    }
                }
            }
            if(cambio == VERDADERO)
            {
                temp = Vpartidas[i];
                Vpartidas[i] = Vpartidas[i+1];
                Vpartidas[i+1] = temp;
                cambio = FALSO;
            }
        }
    }

    return;
}
