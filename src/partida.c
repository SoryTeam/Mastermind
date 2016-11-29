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

#define VERDADERO 1
#define FALSO 0
#define TAM 40

void jugarPartida(sListaJugadores *listaJug, sJugador *jugadAct, sConfig config) //Indica que se está ejecutando la función

{
    srand(time(NULL)); // introduce una semilla para que la función rand no genere siempre números aleatorios en el mismo orden
    char  topeRango;
    int contador = 0, punt_partida = 0, acertado, h, m, s, tot_s;
    float tiempo_partida = 0;
    clock_t principio, fin;
    char clave[30];
    char claveJugador [30];
    char *p_clave;
    int k = 0, Rep = 0, a = VERDADERO, elemVect, IDjugador, error = 0, i;
    char *p_clave2, *p_clave3;
    sPartida partidaActual;
    sHora hora;
    sFecha fecha;
    char nombre[13];

    IDjugador = jugadAct->ID;

    p_clave = clave;

    topeRango=config.numLDis+96; // TopeRango indica en ascii la letra máxima que se puede introducir (con configuración pred. la f)

    if (config.duelo==0)
    {

        generaCombi(p_clave, config); // llamada a función, genera una clave válida

    }
    else
    {
        introduceCombiJugador(p_clave, config); // llamada a función, pide a un jugador una clave válida
    }

    if (config.duelo == 0)
    {
        system("cls");
        printf("%c", 201);
        for (k=0; k<=77; k++)
            printf("%c", 205);
        printf("%c", 187);
        printf("%c", 186);
        for (k=0; k<=77; k++)
            printf(" ");
        printf("%c", 186);
        printf("%c", 186);
        printf("\t\t        \250SER\265S CAPAZ DE ADIVINAR LA CLAVE?");
        for (k=0; k<=20; k++)
            printf(" ");
        printf("%c%c", 186, 186);
        for (k=0; k<=77; k++)
            printf(" ");
        printf("%c", 186);
        printf("%c", 200);
        for (k=0; k<=77; k++)
            printf("%c", 205);
        printf("%c", 188);
        printf("\n\n    ");
        printf("Presiona una tecla cuando est\202s listo . . . ");
        system("pause>null");
        system("cls");
        k=0;
    }
    else
    {
        system("cls");
        printf("%c", 201);
        for (k=0; k<=77; k++)
            printf("%c", 205);
        printf("%c", 187);
        printf("%c", 186);
        for (k=0; k<=77; k++)
            printf(" ");
        printf("%c", 186);
        printf("%c", 186);
        printf("\t\t AHORA LE TOCA AL OTRO JUGADOR ADIVINAR LA CLAVE");
        for (k=0; k<=14; k++)
            printf(" ");
        printf("%c%c", 186, 186);
        for (k=0; k<=77; k++)
            printf(" ");
        printf("%c", 186);
        printf("%c", 200);
        for (k=0; k<=77; k++)
            printf("%c", 205);
        printf("%c", 188);
        printf("\n\n    ");
        printf("Presiona una tecla cuando est\202s listo . . . ");
        system("pause>null");
        system("cls");
        k=0;
    }

    if (config.cronometro==1)
    {
        principio = clock(); // inicia el cronómetro si está activado
    }

    do
    {
        p_clave = claveJugador;

        if(config.repeticion==1)
        {
            // pide al jugador que juega una combinación válida
            do
            {
                error = 0;
                system("cls"); // Limpia la pantalla
                printf("\n\n   Jugador: Introduce %d letras entre la a y %c (ambas inclusive):\n\n    ", config.numLCom, topeRango);

                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                fgets(claveJugador, 30, stdin);
                claveJugador[strlen(claveJugador)-1] = '\0';// escribe el carácter nulo al final de la cadena para indicar el fin de la misma
                if (strlen(claveJugador) != config.numLCom)
                {
                    printf("\n  N\243mero de letras introducidas erroneo.\n  ");
                    printf("\7");
                    error = 1;
                }
                p_clave2 = claveJugador;
                i = 0;

                while(p_clave2[i]!='\0')
                {

                    if((p_clave2[i])<'a' || (p_clave2[i])>topeRango)
                    {
                        printf("\n  Introduce letras v\240lidas.");
                        printf("\7");
                        error = 1;
                        break;
                    }
                    i++;

                }
                if(error == 1)
                {
                    printf("\n\n  ");
                    system("pause");
                }
            }
            while(error);

            k = 0;

            while (claveJugador[k] != '\0')
            {
                *p_clave = claveJugador[k];
                p_clave++;
                k++;
            }
            *p_clave = '\0';
        }
        else // Se comprueba que no haya letras repetidas
        {
            // pide al jugador que juega una combinación válida
            do
            {
                system("cls"); // Limpia la pantalla
                a = VERDADERO;
                Rep = 0;
                do
                {
                    error = 0;
                    system("cls"); // Limpia la pantalla

                    printf("\n\n   Jugador: Introduce %d letras entre la a y %c (ambas inclusive):\n\n    ", config.numLCom, topeRango);

                    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                    fgets(claveJugador, 30, stdin);
                    claveJugador[strlen(claveJugador)-1] = '\0';// escribe el carácter nulo al final de la cadena para indicar el fin de la misma

                    if (strlen(claveJugador) != config.numLCom)
                    {
                        printf("\n   N\243mero de letras introducidas erroneo.\n  ");
                        printf("\7");
                        error = 1;
                    }
                    p_clave2 = claveJugador;
                    i = 0;

                    while(p_clave2[i]!='\0')
                    {
                        if((p_clave2[i])<'a' || (p_clave2[i])>topeRango)
                        {
                            printf("\n  Introduce letras v\240lidas.");
                            printf("\7");
                            error = 1;
                            break;
                        }
                        i++;

                    }
                    if(error == 1)
                    {
                        printf("\n\n  ");
                        system("pause");
                    }
                }
                while (error);

                // Direcciona un par de punteros temporales a la clave
                p_clave2 = claveJugador;
                p_clave3 = claveJugador;

                p_clave2++;

                while(*p_clave2 != '\0') // Ahora se comprueba que los elementos no estén repetidos
                {
                    Rep = 0;
                    p_clave3 = claveJugador;

                    while(*p_clave3 != '\0')
                    {
                        if(*p_clave2 == *p_clave3)
                        {
                            Rep++;
                        }
                        p_clave3++;
                    }
                    p_clave2++;
                    if(Rep >= 2)
                    {
                        printf("\n  Cadena introducida no v\240lida.\n\n  ");
                        printf("\7");
                        a = FALSO;
                        system("pause"); // Pausa la ejecución del programa
                        break;
                    }
                }
            }
            while(a == FALSO);

            k = 0;

            while (claveJugador[k] != '\0')
            {
                *p_clave = claveJugador[k];
                p_clave++;
                k++;
            }
            *p_clave = '\0';
        }

        acertado = compruebaCombiJugador(clave, claveJugador, config); // llamada a función, comprueba si la clave introducida es la correcta y en caso contrario da pistas
        // Si fallas te lo indica junto con el número de intentos restantes
        if ((acertado != 1 && contador < config.numIntentos) && (config.numIntentos - contador - 1) > 0)
        {
            contador++;
            printf("\n   Combinaci\242n err\242nea. Por favor vuelve a intentarlo.\n\n   intentos restantes %d\n\n   ", config.numIntentos - contador);
            system("pause"); // Pausa la ejecución del programa
            system("cls"); // Limpia la pantalla
        }
        // En el último intento cambia el control de error
        else if ((acertado != 1 && contador < config.numIntentos) && (config.numIntentos - contador) > 0)
        {
            contador++;
            printf("\n   Combinaci\242n err\242nea. No te quedan intentos :(\n\n   ");
            system("pause"); // Pausa la ejecución del programa
            system("cls"); // Limpia la pantalla
        }
    }
    while(acertado != 1 && contador < config.numIntentos);

    contador++;

    if (config.cronometro == 1) // Transforma el tiempo empleado de segundos a los valores estándar (horas, mins, sec...)
    {
        fin = clock(); // para el cronómetro si está activado el modo cronómetro
        tiempo_partida = difftime (fin, principio)/CLOCKS_PER_SEC;
        tot_s = tiempo_partida;
        s = tot_s % 60;
        tot_s = tot_s / 60;
        m = tot_s % 60;
        tot_s = tot_s / 60;
        h = tot_s % 60;

        printf("\n   El tiempo empleado ha sido: ");
        if (h != 0)
        {
            printf("%d hora(s) ", h);
            if (m != 0)
            {
                printf("%d minuto(s) ", m);
                if (s != 0)
                {
                    printf("%d segundo(s) ", s);
                }
            }
            else
            {
                printf("%d segundo(s) ", s);
            }
        }
        else if (m != 0)
        {
            printf("%d minuto(s) ", m);
            if (s != 0)
            {
                printf("%d segundo(s) ", s);
            }
        }
        else
        {
            printf("%d segundo(s) ", s);
        }
        printf("\n");
    }

    // Ahora calcula los puntos de la partida, si se han agotado los intentos el valor es 0.
    if (config.repeticion == 1)
    {
        punt_partida = config.numLDis * config.numLCom * (config.numIntentos - contador + 1) * 3;
    }
    else
    {
        punt_partida = config.numLDis * config.numLCom * (config.numIntentos - contador + 1);
    }

    printf("\n   Has alcanzado la puntuaci\242n de: %d puntos", punt_partida);

    if (contador>=config.numIntentos)
    {
        system("cls"); // Limpia la pantalla
        printf("\7");
        printf("\n\n   Lo siento, se ha excedido el n\243mero de intentos.  \n   Otra vez ser\240, \n   int\202ntalo de nuevo...\n\n   Insert coin...\n\n   ");
    }
    else
    {
        printf("\n\n   \255Enhorabuena m\240quina!  \2\n   Lo has conseguido.\n\n   ");
    }

    // Se guarda la hora y la fecha del reloj del ordenador
    extraeHora (&hora);
    extraeFecha (&fecha);

    for(k = 0; k < listaJug->nJugadores; k++) // Ahora se halla en qué posicion del vector está el jugador mediante el ID
    {
        if(listaJug->VRegistros[k].ID == IDjugador)
        {
            elemVect = k;
            break;
        }
    }

    listaJug->VRegistros[elemVect].partidas++; // Actualiza las partidas del jugador

    if (contador<=config.numIntentos) // Actualiza la puntuación máxima
    {
        listaJug->VRegistros[elemVect].MPuntuacion += punt_partida;
    }

    strcpy(nombre, (listaJug->VRegistros[elemVect].nombre));


    // Carga los datos de la partida actual para luego enviarlos a partidas.dat y partidas.bin
    partidaActual.ID = IDjugador;
    strcpy(partidaActual.nombre, nombre);
    partidaActual.intentos = contador;
    partidaActual.tiempo = tiempo_partida;
    partidaActual.puntosConseguidos = punt_partida;
    strcpy(partidaActual.combinacion,clave);
    partidaActual.letrasDisponibles = config.numLDis;
    partidaActual.letrasCombinacion = config.numLCom;
    partidaActual.numeroIntentos = config.numIntentos;
    partidaActual.repeticion = config.repeticion;
    partidaActual.modoDuelo = config.duelo;
    partidaActual.partHora = hora;
    partidaActual.partFech = fecha;

    agregaPartida(partidaActual); // Llamada a función, agrega la partida jugada a partidas.bin y partidas.dat

    if(jugadAct->MPuntuacion < punt_partida) // Actualiza la mejor puntuación
    {
        jugadAct->MPuntuacion = punt_partida;
    }

    jugadAct->partidas++; // Actualiza las partidas del jugador actual



    // Ajustes de presentación
    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    return;
}

int leePartidas(sPartida **VarchPart)
{
    FILE* partidas;
    int k = 0, i = 0;

    partidas=fopen("partidas.bin", "rb"); //Abre un nuevo archivo para leer partidas

    if (partidas == NULL) // El programa avisa en caso de que no se pueda abrir el archivo partidas.bin
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    // A continuación se calcula el número de paridas que hay en el archivo
    fseek(partidas, 0, SEEK_END);
    i = ftell(partidas)/sizeof(sPartida);
    fseek(partidas, 0, SEEK_SET);

    // Ahora se redimensiona el vector al tamaño necesario
    *(VarchPart) = realloc(*(VarchPart), i*sizeof(sPartida));


    for(k = 0; feof(partidas)==0 ; k++) // Lee el archivo hasta que se termine y lo carga en VarchPart
    {
        fread(&((*VarchPart)[k]), sizeof(sPartida), 1, partidas); // el primer argumento escrito asi: VarchPart[k] tampoco da error de compilación
    }


    if (fclose(partidas)!=0)
    {
        printf("\7");
        printf( "Problemas al cerrar el archivo\n" );
        system("pause"); // Pausa la ejecución del programa
        printf("\n");
    }
    return i; // retorna el numero de partidas
}

void muestraPartidas(sListaPartidas todasPart)

{
    int i;

    printf("\n Partida  ID  Nombre  Int.   Tiempo   Puntos  Combinaci\242n    D\241a      Hora\n\n");
    // Ahora muestra las partidas que le llegan de todasPart
    for(i=0; i<(todasPart.nPartidasV); i++)
    {
        printf("   %d     %d    %s   %d     %d       %d       %s     %2d/%2d/%4d   %2d:%2d:%2d\n", (i+1), todasPart.VRegPart[i].ID, todasPart.VRegPart[i].nombre,todasPart.VRegPart[i].intentos, todasPart.VRegPart[i].tiempo, todasPart.VRegPart[i].puntosConseguidos, todasPart.VRegPart[i].combinacion, todasPart.VRegPart[i].partFech.dia,  todasPart.VRegPart[i].partFech.mes,  todasPart.VRegPart[i].partFech.anio,  todasPart.VRegPart[i].partHora.hora, todasPart.VRegPart[i].partHora.minutos, todasPart.VRegPart[i].partHora.segundos);
    }
    printf("\n\n    ");
    system("pause"); // Pausa la ejecución del programa
    return ;
}

void agregaPartida(sPartida partActual)

{
    FILE* partidas;

    // Guarda los datos de la última partida en partidas.dat

    partidas=fopen("partidas.dat", "at"); //Abre un nuevo archivo para escribir texto

    if (partidas == NULL) // El programa avisa en caso de que no se pueda abrir el archivo config.ini
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    // Escribe la partida con el formato adecuado

    fprintf(partidas, "%d %s %d %d %d %s %d %d %d %d %d ", partActual.ID, partActual.nombre, partActual.intentos, partActual.tiempo, partActual.puntosConseguidos, partActual.combinacion, partActual.letrasDisponibles, partActual.letrasCombinacion, partActual.numeroIntentos, partActual.repeticion, partActual.modoDuelo);
    fprintf(partidas, "%2d/%2d/%4d ", partActual.partFech.dia, partActual.partFech.mes, partActual.partFech.anio);
    fprintf(partidas, "%2d:%2d:%2d\n", partActual.partHora.hora, partActual.partHora.minutos, partActual.partHora.segundos);

    if (fclose(partidas)!=0)
    {
        printf("\7");
        printf( "Problemas al cerrar el archivo\n" );
        system("pause"); // Pausa la ejecución del programa
        printf("\n");
    }

    // Guarda los datos de la última partida en partidas.bin

    partidas=fopen("partidas.bin", "ab"); //Abre un nuevo archivo para escribir texto

    if (partidas == NULL) // El programa avisa en caso de que no se pueda abrir el archivo config.ini
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    fwrite(&partActual, sizeof(sPartida), 1, partidas); // escribe la partida

    if (fclose(partidas)!=0)
    {
        printf("\7");
        printf( "Problemas al cerrar el archivo\n" );
        system("pause"); // Pausa la ejecución del programa
        printf("\n");
    }
    return;
}

void mejoresPuntuaciones(sListaJugadores listaJug) // Muestra la mejor puntuación del jugador
{

    int k;

    printf("\n\n         Posici\242n      Partidas       Puntos          ID     Nombre\n");

    for(k = 0; k < (listaJug.nJugadores); k++)
    {
        printf("\n\t     %d         \t%d          \t%d        \t%d" , listaJug.VRegistros[k].clasificacion, listaJug.VRegistros[k].partidas, listaJug.VRegistros[k].MPuntuacion, listaJug.VRegistros[k].ID);
        if(listaJug.VRegistros[k].ID<10) // Control para que no se descuadre demasiado la tabla, si se usan tabulaciones salta de línea
        {
            printf(" ");
        }
        printf("     %s", listaJug.VRegistros[k].nombre);
    }



    printf("\n\n\n    ");
    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    return;
}


void generaCombi(char *p_clave, sConfig config) // Genera la combinación que tendrá que acertar el jugador

{
    int k=0, i=0;

    srand(time(NULL));

    // Si repetición está activada se utiliza un bucle simple para generar letras aleatorias entre los dos valores
    if (config.repeticion==1)
    {
        for (k = 0; k < config.numLCom; k++)
        {
            *p_clave = (rand()%config.numLDis)+97; // Es +97 porque el resto está entre 0 y numLDis
            p_clave++;
        }
        *p_clave = '\0';
    }
    // Si repetición está desactivada se usa un bucle que obvie las letras ya generadas
    else
    {
        *p_clave = (rand()%config.numLDis)+97;
        p_clave++;

        k = 1;

        do
        {

            *p_clave = (rand()%config.numLDis)+97;

            for(i = k; i>0; i--)
            {
                if (*p_clave == *(p_clave-i))
                {
                    *p_clave = (rand()%config.numLDis)+97;
                    i = k + 1;
                }
            }
            p_clave++;

            k++;
        }
        while (k < config.numLCom);

        *p_clave = '\0';
    }
    return;
}

// Aquí el jugador introduce la combinación que el otro jugador ha de averiguar
void introduceCombiJugador (char *p_clave, sConfig config)

{
    int k = 0, Rep = 0, a = VERDADERO, i, error = 0;
    int topeRango;

    char clave2[30];
    char *p_clave2, *p_clave3;

    topeRango=config.numLDis+96;

    system("cls");
    printf("%c", 201);
    for (k=0; k<=77; k++)
        printf("%c", 205);
    printf("%c", 187);
    printf("%c", 186);
    for (k=0; k<=77; k++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 186);
    printf("\t     A CONTINUACI\340N UN JUGADOR INTRODUCE LA CLAVE A ADIVINAR");
    for (k=0; k<=10; k++)
        printf(" ");
    printf("%c%c", 186, 186);
    for (k=0; k<=77; k++)
        printf(" ");
    printf("%c", 186);
    printf("%c", 200);
    for (k=0; k<=77; k++)
        printf("%c", 205);
    printf("%c", 188);
    printf("\n\n    ");
    printf("Presiona una tecla cuando est\202s listo . . . ");
    system("pause>null");

    if(config.repeticion==1)
    {
        do // Bucle que comprueba que la combinación introducida es correcta usando una variable de combinación temporal
        {
            error = 0;
            system("cls"); // Limpia la pantalla
            printf("\n\n   Introduce %d letras entre la a y %c (ambas inclusive):\n    ", config.numLCom, topeRango);

            fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
            fgets(clave2, 30, stdin);
            clave2[strlen(clave2)-1] = '\0';// escribe el carácter nulo al final de la cadena para indicar el fin de la misma
            if (strlen(clave2) != config.numLCom)
            {
                printf("\n  N\243mero de letras introducidas err\242neo.");
                printf("\7");
                error = 1;
            }
            p_clave2 = clave2;
            i = 0;

            while(p_clave2[i]!='\0')
            {
                if((p_clave2[i])<'a' || (p_clave2[i])>topeRango)
                {
                    printf("\n  Introduce letras v\240lidas.");
                    printf("\7");
                    error = 1;
                    break;
                }
                i++;

            }
            if(error == 1)
            {
                printf("\n\n  ");
                system("pause");
            }
        }
        while(error);

        k = 0;

        while (clave2[k] != '\0') // Ahora la variable de combinación temportal se pasa a la final.
        {
            *p_clave = clave2[k];
            p_clave++;
            k++;
        }
        *p_clave = '\0';
    }
    else // Se realiza lo mismo pero si la repetición no está activada
    {
        do
        {
            system("cls"); // Limpia la pantalla
            a = VERDADERO;
            Rep = 0;
            do
            {
                error = 0;
                system("cls"); // Limpia la pantalla

                printf("\n\n   Introduce %d letras entre la a y %c (ambas inclusive):\n\n    ", config.numLCom, topeRango);

                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                fgets(clave2, 30, stdin); // Se guarda la variable en una cadena temporal
                clave2[strlen(clave2)-1] = '\0';// escribe el carácter nulo al final de la cadena para indicar el fin de la misma

                if (strlen(clave2) != config.numLCom)
                {
                    printf("\n  N\243mero de letras introducidas err\242neo.\n  ");
                    printf("\7");
                    error = 1;
                }

                p_clave2 = clave2;
                i = 0;

                while(p_clave2[i]!='\0')
                {
                    if((p_clave2[i])<'a' || (p_clave2[i])>topeRango)
                    {
                        printf("\n  Introduce letras v\240lidas.");
                        printf("\7");
                        error = 1;
                        break;
                    }
                    i++;

                }
                if(error == 1)
                {
                    printf("\n\n  ");
                    system("pause");
                }

            }
            while (error);

            // Direcciona un par de punteros temporales a la clave
            p_clave2 = clave2;
            p_clave3 = clave2;

            p_clave2++;

            while(*p_clave2 != '\0') // Ahora se comprueba que los caracteres no estén repetidos
            {
                Rep = 0;
                p_clave3 = clave2;

                while(*p_clave3 != '\0')
                {
                    if(*p_clave2 == *p_clave3)
                    {
                        Rep++;
                    }
                    p_clave3++;
                }
                p_clave2++;
                if(Rep >= 2)
                {
                    printf("\n  Cadena introducida no v\240lida.\n\n  ");
                    printf("\7");
                    a = FALSO;
                    system("pause"); // Pausa la ejecución del programa
                    break;
                }
            }
        }
        while(a == FALSO);

        k = 0;

        while (clave2[k] != '\0') // Ahora se copia la combinacion temporal correctamente escrita a la combinación usada por el programa
        {
            *p_clave = clave2[k];
            p_clave++;
            k++;
        }
        *p_clave = '\0';
    }
    return;
}


int compruebaCombiJugador (char *clave, char *claveJugador, sConfig config) // *clave y *claveJugador apuntan al principio de las cadenas respectivas todo el proceso

{
    int letrasC=0, letrasD=0, k, i;
    int registro[30]; // Esto servirá para hallar el número de letras correctas y las colocadas en distinta posición, es un vector paralelo a clave[]

    for (k=0; k<30; k++) // Se inicializa los elementos del vector a 0
    {
        registro[k]=0;
    }

    k=0;

    for(i=0; i<config.numLCom; i++)
    {
        for(k=0; k<config.numLCom; k++)
        {
            if (claveJugador[i]==clave[i])
            {
                registro[i]=1; // Si la letra es correcta indica que ese elemento es 1 (para luego contar los elementos)
            }
            else if ((claveJugador[k]==clave[i]) && (registro[i]!=1))
            {
                registro[i]=2; // Si la letra está en otra posición indica que ese elemento es 2
            }
        }
    }

    // Ahora cuenta el número de letras correctas y en distinta posción que hay en el vector
    for (k=0; k<30; k++)
    {
        if (registro[k]==1)
        {
            letrasC++;
        }
        else if (registro[k]==2)
        {
            letrasD++;
        }
    }
    printf("\n\n   %d letra(s) esta(n) en la clave y en la posici\242n correcta.\n\n   %d letra(s) esta(n) en la clave pero en distinta posici\242n\n\n   ", letrasC, letrasD);
    if(config.numLCom==letrasC) // Si ha acertado devuelve 1 y si no 0
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



sListaPartidas creaListaPartidas(sPartida *Vpartidas, int nPart)
{
    int i;

    sListaPartidas listaPartida;

    listaPartida.VRegPart = NULL;

    // Se redimensiona el vector de listaPartida para que quepa el introducido como argumento o Vpartidas
    listaPartida.VRegPart = realloc(listaPartida.VRegPart, nPart*sizeof(sPartida));

    listaPartida.nPartidasV = nPart; // Crea la lista de partidas de jugadores.bin
    for(i = 0; i < nPart; i++)
    {
        (listaPartida.VRegPart[i]) = Vpartidas[i];
    }

    return listaPartida;
}

int leePartidasJugador(sPartida **VpartidasJugador, char nombre[13])

{
    FILE* partidas;
    sPartida temp;
    int i = 0, z = 0, numPartidasJugador = 0, q = 0;

    partidas=fopen("partidas.bin", "rb"); //Abre un nuevo archivo para leer partidas

    if (partidas == NULL) // El programa avisa en caso de que no se pueda abrir el archivo partidas.bin
    {
        printf("\n    Error al abrir el archivo.\n\n    ");
        printf("\7");
        system("pause"); // Pausa la ejecución del programa
        exit (1);
    }

    // Se calcula el número de partidas que hay en partidas.bin
    fseek(partidas, 0, SEEK_END);
    z = ftell(partidas)/sizeof(sPartida);
    // Se hace que el puntero vuelva a apuntar al principio
    fseek(partidas,0, SEEK_SET);

    // Se redimensiona el vector de partidas del jugador de acuerdo a dicho número
    (*(VpartidasJugador)) = realloc((*(VpartidasJugador)), (z*sizeof(sPartida)));

    i = 0;

    for(; feof(partidas)==0 ;) // Se lee el archivo registro a registro hasta el final
    {
        // En cada interacción del bucle se usa temp para leer pues todavía no se sabe si coincide el nombre introducido con el leído
        q = fread(&temp, (sizeof(sPartida)), 1, partidas);

        if(q==0) // sale del bucle cuando no quedan elementos por leer
        {
            break;
        }

        if((strcmp(temp.nombre, nombre)) == 0) // Si el nombre coincide con el introducido guarda la partida en el vector VpartidasJugador
        {
            fseek(partidas,(-sizeof(sPartida)), SEEK_CUR); // retrocede en un elemento para que se pueda leer posteriormente
            fread(&((*VpartidasJugador)[i]), sizeof(sPartida), 1, partidas); // el primer argumento escrito asi: VpartidasJugador[i] tampoco da error de compilación
            i++;
        }
        numPartidasJugador = i; // indica el número de partidas del jugador
    }
    (*(VpartidasJugador)) = realloc((*(VpartidasJugador)), (numPartidasJugador*sizeof(sPartida))); // Se redimensiona el vector de partidas del jugador de acuerdo a dicho número

    if (fclose(partidas)!=0)
    {
        printf("\7");
        printf( "Problemas al cerrar el archivo\n" );
        system("pause"); // Pausa la ejecución del programa
        printf("\n");
    }

    return numPartidasJugador; // retorna el numero de partidas del jugador
}

void muestraPartidasFecha(sListaPartidas lista, sFecha fecha1)

{
    int i, k=0;

    printf("\n Partida  ID  Nombre  Int.   Tiempo   Puntos  Combinaci\242n    D\241a      Hora\n\n");
    // Ahora muestra las partidas que le llegan de todasPart y que coinciden con la fecha que nos interesa
    for(i=0; i<(lista.nPartidasV); i++)
    {
        if((lista.VRegPart[i].partFech.dia == fecha1.dia) && (lista.VRegPart[i].partFech.mes == fecha1.mes) && (lista.VRegPart[i].partFech.anio == fecha1.anio))
        {
            printf("   %d     %d    %s   %d     %d       %d       %s     %2d/%2d/%4d   %2d:%2d:%2d\n", (k+1), lista.VRegPart[k].ID, lista.VRegPart[k].nombre,lista.VRegPart[k].intentos, lista.VRegPart[k].tiempo, lista.VRegPart[k].puntosConseguidos, lista.VRegPart[k].combinacion, lista.VRegPart[k].partFech.dia,  lista.VRegPart[k].partFech.mes,  lista.VRegPart[k].partFech.anio,  lista.VRegPart[k].partHora.hora, lista.VRegPart[k].partHora.minutos, lista.VRegPart[k].partHora.segundos);
            k++;
        }

    }
    printf("\n\n    ");
    system("pause"); // Pausa la ejecución del programa

    return;
}

// El algoritmo que viene a continuación selecciona las partidas entre dos fechas (incluidas) y las muestra
void muestraPartidasEntreFecha(sListaPartidas lista, sFecha fecha1, sFecha fecha2)
{
    int i = 0, contador = 0;

    printf("\n Partida  ID  Nombre  Int.   Tiempo   Puntos  Combinaci\242n    D\241a      Hora\n\n");

    for(i=0; i<(lista.nPartidasV); i++)
    {

        // Si la primera fecha introducida es anterior a la segunda

        // Determina si la fecha de la partida es posterior o igual a la primera fecha introducida
        if((fecha1.anio)<(lista.VRegPart[i].partFech.anio))
        {
            contador++;
        }
        else if ((fecha1.anio)==(lista.VRegPart[i].partFech.anio))
        {
            if ((fecha1.mes)<(lista.VRegPart[i].partFech.mes))
            {
                contador++;
            }
            else if ((fecha1.mes)==(lista.VRegPart[i].partFech.mes))
            {
                if((fecha1.dia)<=(lista.VRegPart[i].partFech.dia))
                {
                    contador++;
                }
            }

        }

        // Determina si la fecha de la partida es anterior o igual a la segunda fecha introducida
        if((fecha2.anio)>(lista.VRegPart[i].partFech.anio))
        {
            contador++;
        }
        else if ((fecha2.anio)==(lista.VRegPart[i].partFech.anio))
        {
            if ((fecha2.mes)>(lista.VRegPart[i].partFech.mes))
            {
                contador++;
            }
            else if ((fecha2.mes)==(lista.VRegPart[i].partFech.mes))
            {
                if((fecha2.dia)>=(lista.VRegPart[i].partFech.dia))
                {
                    contador++;
                }
            }

        }

        // Si la primera fecha introducida es posterior a la segunda

        if(contador != 2)
        {
            contador = 0;

            // Determina si la fecha de la partida es anterior o igual a la primera fecha introducida
            if((fecha1.anio)>(lista.VRegPart[i].partFech.anio))
            {
                contador++;
            }
            else if ((fecha1.anio)==(lista.VRegPart[i].partFech.anio))
            {
                if ((fecha1.mes)>(lista.VRegPart[i].partFech.mes))
                {
                    contador++;
                }
                else if ((fecha1.mes)==(lista.VRegPart[i].partFech.mes))
                {
                    if((fecha1.dia)>=(lista.VRegPart[i].partFech.dia))
                    {
                        contador++;
                    }
                }

            }

            // Determina si la fecha de la partida es posterior o igual a la segunda fecha introducida
            if((fecha2.anio)<(lista.VRegPart[i].partFech.anio))
            {
                contador++;
            }
            else if ((fecha2.anio)==(lista.VRegPart[i].partFech.anio))
            {
                if ((fecha2.mes)<(lista.VRegPart[i].partFech.mes))
                {
                    contador++;
                }
                else if ((fecha2.mes)==(lista.VRegPart[i].partFech.mes))
                {
                    if((fecha2.dia)<=(lista.VRegPart[i].partFech.dia))
                    {
                        contador++;
                    }
                }
            }
        }

        if (contador == 2)
        {
            printf("   %d     %d    %s   %d     %d       %d       %s     %2d/%2d/%4d   %2d:%2d:%2d\n", (i+1), lista.VRegPart[i].ID, lista.VRegPart[i].nombre,lista.VRegPart[i].intentos, lista.VRegPart[i].tiempo, lista.VRegPart[i].puntosConseguidos, lista.VRegPart[i].combinacion, lista.VRegPart[i].partFech.dia,  lista.VRegPart[i].partFech.mes,  lista.VRegPart[i].partFech.anio,  lista.VRegPart[i].partHora.hora, lista.VRegPart[i].partHora.minutos, lista.VRegPart[i].partHora.segundos);
        }

        contador = 0;
    }

    printf("\n\n    ");
    system("pause"); // Pausa la ejecución del programa

    return;
}
