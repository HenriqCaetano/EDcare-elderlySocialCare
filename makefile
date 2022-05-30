saida: main.o idoso.o cuidador.o listaIdoso.o listaCuidador.o local.o
	@gcc -o saida main.o idoso.o cuidador.o listaIdoso.o listaCuidador.o local.o -lm


main.o: main.c idoso.h cuidador.h listaCuidador.h listaIdoso.h local.h
	@gcc -o main.o main.c -c

idoso.o: idoso.c idoso.h listaCuidador.h
	@gcc -o idoso.o idoso.c -c

cuidador.o: cuidador.c cuidador.h
	@gcc -o cuidador.o cuidador.c -c

listaIdoso.o: listaIdoso.c listaIdoso.h idoso.h 
	@gcc -o listaIdoso.o listaIdoso.c -c

listaCuidador.o: listaCuidador.c listaCuidador.h cuidador.h
	@gcc -o listaCuidador.o listaCuidador.c -c

local.o: local.c local.h
	@gcc -o local.o local.c -lm -c 

clean:
	@rm -rf *.o ~saida