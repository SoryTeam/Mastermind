// Aplicación: MasterMind
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


// La función main inicia la ejecución del programa
int main()
{
    // Declaración de variables con o sin valores iniciales
    int i, q, opcion = -1, opcion2 = -1, opcion3 = -1, opcion4 = -1;
    int IDmax = 0, restaura = 6, restaura2 = 4, restaura3 = 10;
    int validezNombre, validezRep;
    int orden = 0, numPartidas = 1, numPartidasJugador = 1, contadorPart = 0, numPartidas2 = 1;
    int temp = 0;
    int  variableControl = 0;

    char jugadoAntes = 'n';
    char  respuesta = '1';
    char nombre[15];
    char nombre2[15];

    sConfig confTemp;

    sPartida *Vpartidas=NULL, *Vpartidas2=NULL;
    sPartida *VpartidasJugador=NULL;

    sListaPartidas listaPartida, listaPartidaJugador, listaPartida2;


    sJugador jugadAct;

    sListaJugadores listaJug;

    sFecha fecha1, fecha2;



    FILE* jugadores; // Permite el uso de archivos



    listaJug.VRegistros = NULL;
    listaPartida.VRegPart = NULL;
    listaPartida2.VRegPart = NULL;
    listaPartidaJugador.VRegPart = NULL;

    intro(); // Introduce al jugador al juego

    // Ajustes de presentación
    system("pause"); // Pausa la ejecución del programa
    system("cls"); // Limpia la pantalla

    // LLamada a funcion, carga la configuración

    leeConfig(&confTemp);

    // LLamada a funcion, carga los datos de todos los jugadores

    leeDatosPartida(&listaJug);

    do
    {
        system("cls"); // Limpia la pantalla

        // Determina si es un jugador nuevo o no

        printf("\n\n\n    \250Has jugado ya antes? Si(S) // No(N) ");
        fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
        scanf("%c", &jugadoAntes);
        system("cls"); // Limpia la pantalla

        // No es jugador nuevo: Solicita el ID

        if(jugadoAntes == 's' || jugadoAntes == 'S')
        {
            do
            {
                do
                {
                    printf("\n\n\n    Introduce tu nombre o nick:\n\n\n    ");
                    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                    fgets(nombre,15,stdin);
                    nombre[strlen(nombre)-1] = '\0'; // escribe el carácter nulo al final de la cadena para indicar el fin de la misma
                    validezNombre = compruebaNuevoNombreJugador(nombre); // Comprueba si el nombre tiene longitud, caracteres, num de letras y numeros adecuados
                    if(validezNombre == 0)
                    {
                        printf("\n    ");
                        system("pause");
                        system("cls");
                    }

                }
                while (validezNombre == 0);
                validezRep = compruebaNombreAnteriorJugador(listaJug, nombre); // comprueba si el nombre ya existe o no
                if(validezRep == 0) // Control de error
                {
                    printf("El nombre introducido no est\240 registrado.\n\n\n    ");
                    system("pause");
                    system("cls");
                }
            }
            while(validezRep == 0);

            for(q=0; q<listaJug.nJugadores; q++) // Ahora se añaden los datos del jugador a la variable jugadAct
            {
                if(strcmp(nombre, listaJug.VRegistros[q].nombre) == 0)
                {
                    jugadAct = listaJug.VRegistros[q];
                    break;
                }
            }
        }

        // Si es jugador nuevo: Crea un nuevo ID

        else if (jugadoAntes == 'n' || jugadoAntes == 'N')
        {
            // Busca el último ID registrado
            for(i = 0; i < listaJug.nJugadores; i++)
            {
                if(listaJug.VRegistros[i].ID > IDmax)
                {
                    IDmax = listaJug.VRegistros[i].ID;
                }
            }

            do
            {
                do
                {
                    printf("\n\n\n    A continuaci\242n introduce tu nombre o nick.\n\n\n      La longitud del nombre ha de tener entre 6 y 12 caracteres.\n\n      Tiene que tener al menos 2 letras y 1 n\243mero.\n\n      Solo se admite el gui\242n bajo \"_\" como car\240cter especial.\n\n\n    Nombre: ");
                    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                    fgets(nombre,15,stdin);
                    nombre[strlen(nombre)-1] = '\0';// escribe el carácter nulo al final de la cadena para indicar el fin de la misma
                    validezNombre = compruebaNuevoNombreJugador(nombre); // Comprueba si el nombre tiene longitud, caracteres, num de letras y numeros adecuados
                    if(validezNombre == 0)
                    {
                        // Ajustes de presentación
                        printf("\n    ");
                        system("pause");
                        system("cls");
                    }

                }
                while (validezNombre == 0);
                validezRep = compruebaNombreAnteriorJugador(listaJug, nombre); // comprueba si el nombre ya existe o no
                if(validezRep == 1)
                {
                    printf("El nombre introducido ya est\240 registrado.\n\n\n    ");
                    // Ajustes de presentación
                    system("pause");
                    system("cls");
                }
            }
            while(validezRep == 1);
            // Ajustes de presentación
            system("cls");

            // Ahora se añade la información sobre el nuevo jugador a jugadores.dat
            jugadores = fopen("jugadores.dat", "at"); //abre un archivo

            if (jugadores == NULL) // El programa avisa en caso de que no se pueda abrir el archivo jugadores.dat
            {
                printf("\7");
                printf("\n    Error al abrir el archivo.\n\n    ");
                system("pause"); // Pausa la ejecución del programa
                exit (1);
            }
            // escribe los datos del nuevo jugador
            fprintf(jugadores, "%d ", IDmax+1);
            fprintf(jugadores, "%s ", nombre);
            fprintf(jugadores, "%d ", 0);
            fprintf(jugadores, "%d ", 0);
            fprintf(jugadores, "%d\n", IDmax+1);

            if (fclose(jugadores)!=0) // aviso en caso de error al cerrar el archivo jugadores.dat
            {
                printf("\7");
                printf( "\n    Problemas al cerrar el archivo\n" );
                system("pause");
            }

            // Se añade los datos del nuevo jugador a jugadAct
            jugadAct.clasificacion = IDmax+1;
            jugadAct.ID = IDmax+1;
            strcpy(jugadAct.nombre, nombre);
            jugadAct.MPuntuacion = 0;
            jugadAct.partidas = 0;

            // se libera e iguala a NULL antes de cargar de nuevo los datos

            free(listaJug.VRegistros);
            listaJug.VRegistros = NULL;

            // LLamada a funcion, carga los datos de todos los jugadores, ahora además con el nuevo jugador
            leeDatosPartida(&listaJug);

            printf("\n\n    \255Bienvenido al juego! Desde el equipo de programaci\242n te\n    deseamos que lo disfrutes.");
            printf("\n\n    Tu ID de jugador es %d.\n    Actualmente est\240s clasificado %do\n    \250Ser\240s capaz de llegar al 1er puesto?.\n\n    ", IDmax+1, IDmax+1);
            system("pause"); // Pausa la ejecución del programa
            system("cls"); // Limpia la pantalla
        }

        else
        {
            // Indica si se ha introducido una opción no válida
            system("cls"); // Limpia la pantalla
            printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
            printf("\7");
            system("pause"); // Pausa la ejecución del programa
            system("cls"); // Limpia la pantalla
        }

    }
    while(jugadoAntes != 's' && jugadoAntes != 'S'&& jugadoAntes != 'n' && jugadoAntes != 'N');




    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado

// Presenta el menu principal del programa hasta que se introduce una opcion válida

    do
    {
        // Muestra el menu de entrada de MasterMind
        menuPrincipal(&opcion);

        switch (opcion)
        {
        case 1:
            fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado

            do
            {
                // Llama al menu de configuración, luego vuelve al menú principal
                menuConfig(&opcion2);
                // Opciones y sentencias código en función de la opción seleccionada, si no es válida retorna al principio del menú
                switch (opcion2)
                {
                case 1:
                {
                    // LLamada a funcion, muestra la configuracion
                    mostrarConfig(confTemp); // Ejecuta la función mostrarConfig si la elección es 1
                    break;
                }
                case 2:
                    do
                    {
                        // Abre el menú de configuración personalizada
                        menuConfigPerson(&opcion3);

                        switch (opcion3)
                        {
                        case 1:
                            // modifica el valor de letras disponibles, contiene control de error numérico
                            restaura = confTemp.numLDis;
                            do
                            {
                                confTemp.numLDis = restaura;
                                printf("\n\n  Actualmente el n\243mero de letras disponibles en el juego es %d\n", confTemp.numLDis);
                                printf("\n  Introduzca un nuevo valor: "); //Solicita una opción al usuario
                                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                scanf("%d", &temp); // Guarda en la variable el número de la opción elegida
                                confTemp.numLDis = temp;
                                if (temp<=0)
                                {
                                    system("cls"); // Limpia la pantalla
                                    printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                                    printf("\7");
                                    system("pause"); // Pausa la ejecución del programa
                                    system("cls"); // Limpia la pantalla
                                }
                                else
                                {
                                    printf("\n  Opci\242n guardada correctamente.\n\n  ");
                                }
                            }
                            while(temp<=0);
                            restaura = confTemp.numLDis;
                            break;
                        case 2:
                            // modifica el valor de letras por combinación, contiene control de error numérico
                            restaura2 = confTemp.numLCom;
                            do
                            {
                                confTemp.numLCom = restaura2;
                                printf("\n\n  Actualmente el n\243mero de letras por combinaci\242n en el juego es %d", confTemp.numLCom);
                                printf("\n\n  Introduzca un nuevo valor: "); //Solicita una opción al usuario
                                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                scanf("%d", &temp); // Guarda en la variable el número de la opción elegida
                                confTemp.numLCom = temp;
                                if (temp<=0)
                                {
                                    system("cls"); // Limpia la pantalla
                                    printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                                    printf("\7");
                                    system("pause"); // Pausa la ejecución del programa
                                    system("cls"); // Limpia la pantalla
                                }
                                else
                                {
                                    printf("\n  Opci\242n guardada correctamente.\n\n  ");
                                }
                            }
                            while(temp<=0);
                            restaura2 = confTemp.numLCom;
                            break;
                        case 3:
                            // modifica el valor de intentos, contiene control de error numérico
                            restaura3 = confTemp.numIntentos;
                            do
                            {
                                confTemp.numIntentos = restaura3;
                                printf("\n\n  Actualmente el n\243mero de intentos en el juego es %d", confTemp.numIntentos);
                                printf("\n\n  Introduzca el nuevo valor: "); //Solicita una opción al usuario
                                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                scanf("%d", &temp); // Guarda en la variable el número de la opción elegida
                                confTemp.numIntentos = temp;
                                if (temp<=0)
                                {
                                    system("cls"); // Limpia la pantalla
                                    printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                                    printf("\7");
                                    system("pause"); // Pausa la ejecución del programa
                                    system("cls"); // Limpia la pantalla
                                }
                                else
                                {
                                    printf("\n  Opci\242n guardada correctamente.\n\n  ");
                                }
                            }
                            while(temp<=0);
                            restaura3 = confTemp.numIntentos;
                            break;
                        case 4:
                            do
                            {

                                printf("\n\n  \250Desea activar la repetici\242n de letras en el juego?  Si(S) // No(N) "); //Solicita una opción al usuario
                                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                scanf("%c", &respuesta); // Guarda en la variable el número de la opción elegida
                                // Traduce lo introducido por el usuario a lenguaje máquina
                                if (respuesta == 's' || respuesta == 'S')
                                {
                                    confTemp.repeticion = 1;
                                    variableControl=1;
                                }

                                else if (respuesta == 'n' || respuesta == 'N')
                                {
                                    confTemp.repeticion = 0;
                                    variableControl=1;

                                }
                                else // Muestra un mensaje de error en caso de que el ususario se confunda al introducir la variable
                                {
                                    printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                                    printf("\7"); // Sonido de error
                                    // Ajustes de presentación
                                    system ("pause");
                                    system("cls"); // Limpia la pantalla
                                    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                }
                                respuesta = '1';
                            }
                            while(variableControl!=1);  // La petición de datos se repite hasta que el ususario introduzca una opción válida
                            variableControl=0;
                            printf("\n  Opci\242n guardada correctamente.\n\n  ");
                            break;
                        case 5:
                            do
                            {
                                printf("\n\n  \250Desea activar el cron\242metro en el juego?  Si(S) // No(N) "); //Solicita una opción al usuario
                                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                scanf("%c", &respuesta); // Guarda en la variable el número de la opción elegida
                                // Traduce lo introducido por el usuario a lenguaje máquina
                                if (respuesta == 's' || respuesta == 'S')
                                {
                                    confTemp.cronometro = 1;
                                    variableControl=1;
                                }

                                else if (respuesta == 'n' || respuesta == 'N')
                                {
                                    confTemp.cronometro = 0;
                                    variableControl=1;

                                }
                                else // Muestra un mensaje de error en caso de que el ususario se confunda al introducir la variable
                                {
                                    printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                                    printf("\7"); // Sonido de error
                                    // Ajustes de presentación
                                    system ("pause");
                                    system("cls"); // Limpia la pantalla
                                    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                }
                                respuesta = '1';
                            }
                            while(variableControl!=1);  // La petición de datos se repite hasta que el ususario introduzca una opción válida
                            variableControl=0;

                            printf("\n  Opci\242n guardada correctamente.\n\n  ");
                            break;
                        case 6:
                            do
                            {
                                printf("\n\n  \250Desea activar el modo duelo?  Si(S) // No(N) "); //Solicita una opción al usuario
                                fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                scanf("%c", &respuesta); // Guarda en la variable el número de la opción elegida
                                // Traduce lo introducido por el usuario a lenguaje máquina
                                if (respuesta == 's' || respuesta == 'S')
                                {
                                    confTemp.duelo = 1;
                                    variableControl=1;
                                }

                                else if (respuesta == 'n' || respuesta == 'N')
                                {
                                    confTemp.duelo = 0;
                                    variableControl=1;
                                }
                                else // Muestra un mensaje de error en caso de que el ususario se confunda al introducir la variable
                                {
                                    printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                                    printf("\7"); // Sonido de error
                                    // Ajustes de presentación
                                    system ("pause");
                                    system("cls"); // Limpia la pantalla
                                    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                                }
                                respuesta = '1';
                            }
                            while(variableControl!=1);  // La petición de datos se repite hasta que el ususario introduzca una opción válida
                            variableControl=0;

                            printf("\n  Opci\242n guardada correctamente.\n\n  ");
                            break;
                        case 0:
                            opcion3 = 0;
                            break;
                        default:
                            printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                            printf("\7"); // Sonido de error
                            opcion3 = -1;
                        }

                        if (opcion3 != 0)
                        {
                            // Ajustes de presentación
                            system("pause"); // Pausa la ejecución del programa
                            system("cls"); // Limpia la pantalla
                        }
                    }
                    while(opcion3 < 0 || opcion3 > 6);

                    opcion3 = -1;

                    break;
                case 3:
                    system("cls"); // Limpia la pantalla
                    // LLamada a funcion, guarda la configuración actual en el fichero config.ini
                    salvaConfig(confTemp);
                    system("pause"); // Pausa la ejecución del programa
                    break;
                case 4:
                    // Restablece la configuración predeterminada

                    system("cls"); // Limpia la pantalla
                    // LLamada a funcion, lee la configuración por defecto
                    leeConfigPrede(&confTemp);
                    // LLamada a funcion, guarda la configuración por defecto en el fichero config.ini
                    salvaConfig(confTemp);
                    system("pause"); // Pausa la ejecución del programa
                    break;
                case 0:
                    // Vuelve al menú principal
                    opcion2 = 0;
                    break;
                default:
                    // Indica si se ha introducido una opción no válida
                    printf("\n  Opci\242n seleccionada no v\240lida.\n\n  ");
                    printf("\7");
                    system("pause"); // Pausa la ejecución del programa
                    system("cls"); // Limpia la pantalla
                    opcion2 = -1;
                }
            }
            while(opcion2 < 0 || opcion2 > 6);
            opcion2 = -1;
            // Produce el retorno al menu principal
            opcion = -1;
            break;
        case 2:
            // LLamada a funcion, muestra la configuración
            mostrarConfig(confTemp);
            // LLamada a funcion, comienza la partida
            jugarPartida(&listaJug, &jugadAct, confTemp);
            // Cuenta las partidas que se han jugado en esta ejecución
            contadorPart++;
            // LLamada a funcion, ordena los datos
            ordenaDatos(&listaJug);
            // LLamada a funcion, guarda los datos
            salvaDatos(listaJug);
            // Produce el retorno al menu principal
            opcion = -1;
            break;
        case 3:
            // LLamada a funcion, muestra las mejores puntuaciones
            mejoresPuntuaciones(listaJug);
            // LLamada a funcion, carga las partidas
            numPartidas = leePartidas(&Vpartidas);
            do
            {
                // LLamada a funcion, ordena las partidas de acorde al criterio seleccionado
                orden = menuOrdena();

                switch(orden)
                {
                case 1:
                    ordenaID(Vpartidas, numPartidas);
                    break;
                case 2:
                    ordenaPuntos(Vpartidas, numPartidas);
                    break;
                case 3:
                    ordenaCombi(Vpartidas, numPartidas);
                    break;
                case 4:
                    ordenaHora(Vpartidas, numPartidas);
                    break;
                case 0:
                    break;
                default:
                    // Indica si se ha introducido una opción no válida
                    printf("\n Opci\242n seleccionada no v\240lida.\n\n");
                    printf("\7");
                    orden = -1;
                }

                // Ajustes de presentación
                system("pause"); // Pausa la ejecución del programa
                system("cls"); // Limpia la pantalla

            }
            while(orden < 0 || orden > 4);
            if(orden==0)
            {
                // se libera e iguala a NULL
                free(Vpartidas);
                Vpartidas = NULL;
                opcion = -1;
                break;
            }
            // se libera e iguala a NULL antes de cargar de nuevo los datos
            free(listaPartida.VRegPart);
            listaPartida.VRegPart = NULL;

            // LLamada a funcion, crea la lista de partidas
            listaPartida = creaListaPartidas(Vpartidas, numPartidas);

            // se libera e iguala a NULL antes de cargar de nuevo los datos
            free(Vpartidas);
            Vpartidas = NULL;

            // LLamada a funcion, muestra las partidas
            muestraPartidas(listaPartida);
            // Produce el retorno al menu principal
            opcion = -1;
            break;
        case 4:
            do
            {
                do
                {
                    printf("\n\n\n    Introduce un nombre o nick:\n\n\n    ");
                    fflush(stdin); // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado // Limpia el buffer de entrada para que no haya problemas al introducir nuevos datos por teclado
                    fgets(nombre2,15,stdin);
                    nombre2[strlen(nombre2)-1] = '\0';// escribe el carácter nulo al final de la cadena para indicar el fin de la misma
                    validezNombre = compruebaNuevoNombreJugador(nombre2); // Comprueba si el nombre tiene longitud, caracteres, num de letras y numeros adecuados
                    if(validezNombre == 0)
                    {
                        printf("\n    ");
                        system("pause");
                        system("cls");
                    }
                }
                while (validezNombre == 0);
                validezRep = compruebaNombreAnteriorJugador(listaJug, nombre2); // comprueba si el nombre ya existe o no
                if(validezRep == 0)
                {
                    printf("El nombre introducido no est\240 registrado.\n\n\n    ");
                    system("pause");
                    system("cls");
                }
            }
            while(validezRep == 0);

            // Le el archivo partidas.bin y selecciona las que son del jugador introducido
            numPartidasJugador = leePartidasJugador(&VpartidasJugador, nombre2);

            // Ordena las partidas de acuerdo al criterio
            ordenaHora(VpartidasJugador, numPartidasJugador);

            // se libera e iguala a NULL antes de cargar de nuevo los datos
            free(listaPartidaJugador.VRegPart);
            listaPartidaJugador.VRegPart = NULL;

            // LLamada a funcion, crea la lista de partidas
            listaPartidaJugador = creaListaPartidas(VpartidasJugador, numPartidasJugador);

            // se libera e iguala a NULL antes de cargar de nuevo los datos
            free(VpartidasJugador);
            VpartidasJugador = NULL;

            do
            {
                // LLamada a funcion, muestra las partidas de acorde al criterio seleccionado
                menuPartidasJugador(&opcion4);

                switch(opcion4)
                {
                case 1:
                    // LLamada a funcion, muestra las partidas
                    muestraPartidas(listaPartidaJugador);
                    break;
                case 2:
                    printf("\n\n    Introduce una fecha con formato dd/mm/aaaa: ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &fecha1.dia, &fecha1.mes, &fecha1.anio);
                    // LLamada a funcion, muestra las partidas
                    muestraPartidasFecha(listaPartidaJugador, fecha1);
                    break;
                case 3:
                    printf("\n\n    Introduce la primera fecha con formato dd/mm/aaaa: ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &fecha1.dia, &fecha1.mes, &fecha1.anio);
                    printf("\n\n    Introduce la segunda fecha con formato dd/mm/aaaa: ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &fecha2.dia, &fecha2.mes, &fecha2.anio);
                    fflush(stdin);
                    // LLamada a funcion, muestra las partidas
                    muestraPartidasEntreFecha(listaPartidaJugador, fecha1, fecha2);
                    break;
                case 0:
                    break;
                default:
                    // Indica si se ha introducido una opción no válida
                    printf("\n Opci\242n seleccionada no v\240lida.\n\n");
                    printf("\7");
                    system("pause");
                    opcion4 = -1;
                }

                system("cls"); // Limpia la pantalla

            }
            while(opcion4 < 0 || opcion4 > 3);
            if(opcion4==0)
            {
                opcion = -1;
                break;
            }

            // Produce el retorno al menu principal
            opcion = -1;
            break;
        case 5:
            numPartidas2 = leePartidas(&Vpartidas2);
            // se libera e iguala a NULL antes de cargar de nuevo los datos
            free(listaPartida2.VRegPart);
            listaPartida2.VRegPart = NULL;

            // LLamada a funcion, crea la lista de partidas
            listaPartida2 = creaListaPartidas(Vpartidas2, numPartidas2);

            // se libera e iguala a NULL antes de cargar de nuevo los datos
            free(Vpartidas2);
            Vpartidas2 = NULL;

            creaListaJugadoresPartidas(listaJug, listaPartida2);
            // Produce el retorno al menu principal
            opcion = -1;
            break;
        case 0:
            // Muestra el mensaje de despedida y sale del juego
            salir();
            exit (0);
            break;
        default:
            // Indica si se ha introducido una opción no válida
            printf("\n Opci\242n seleccionada no v\240lida.\n\n");
            printf("\7");
            system("pause"); // Pausa la ejecución del programa
            system("cls"); // Limpia la pantalla
            // Produce el retorno al menu principal
            opcion = -1;
        }

    }
    while (opcion != 0);

    return 0; // indica que el programa finaliza sin problemas
} // fin función main
