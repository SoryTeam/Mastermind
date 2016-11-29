
all: MasterMind.exe

MasterMind.exe: baseDatos.o config.o mainMaster.o menus.o partida.o varias.o tiempo.o ordena.o varias.o
	gcc -o MasterMind.exe baseDatos.o config.o mainMaster.o menus.o partida.o varias.o tiempo.o ordena.o

baseDatos.o: baseDatos.c baseDatos.h
	gcc -c -Wall baseDatos.c

config.o: config.c config.h
	gcc -c -Wall config.c

mainMaster.o: mainMaster.c 
	gcc -c -Wall mainMaster.c

menus.o: menus.c menu.h partida.h
	gcc -c -Wall menus.c

ordena.o: ordena.c ordena.h
	gcc -c -Wall ordena.c

partida.o: partida.c partida.h
	gcc -c -Wall partida.c

tiempo.o: tiempo.c tiempo.h
	gcc -c -Wall tiempo.c

varias.o: varias.c varias.h
	gcc -c -Wall varias.c

varias.o: ampli.c ampli.h
	gcc -c -Wall ampli.c

clean:
	del baseDatos.o config.o mainMaster.o menus.o partida.o varias.o tiempo.o ordena.o varias.o
