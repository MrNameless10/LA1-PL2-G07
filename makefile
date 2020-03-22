
all: clean la1

la1: main.c dados.o interface.o logica.o
	gcc main.c dados.o interface.o logica.o

####################################################################################################

dados.o:
	gcc -c dados.c

interface.o:
	gcc -c interface.c

comandos.o:
	gcc -c comandos.c

logica.o:
	gcc -c logica.c

clean:
	rm -f *.o