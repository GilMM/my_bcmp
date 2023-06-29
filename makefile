mybcmp:  my_bcmp.o
	gcc -g -Wall -ansi -pedantic my_bcmp.c -o my_bcmp -lm
my_bcmp.o:  my_bcmp.c
	gcc -c -Wall -ansi -pedantic my_bcmp.c -o my_bcmp.o -lm
