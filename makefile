
all: clean la1

la1: main.c camada\ de\ dados.o camada\ de\ interface.o logica\ de\ programa.o
	gcc main.c camada\ de\ dados.o camada\ de\ interface.o logica\ de\ programa.o

####################################################################################################

camada\ de\ dados.o:
	gcc -c camada\ de\ dados.c

camada\ de\ interface.o:
	gcc -c camada\ de\ interface.c

comandos.o:
	gcc -c comandos.c

logica\ de\ programa.o:
	gcc -c logica\ de\ programa.c

clean:
	rm -f *.o