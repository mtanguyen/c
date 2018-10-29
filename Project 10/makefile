roster: roster.o player.o readline.o
	gcc -o roster roster.o player.o readline.o

roster.o: roster.c player.h readline.h
	gcc -c roster.c

player.o: player.c player.h readline.h
	gcc -c player.c
 
readline.o: readline.c readline.h 
	gcc -c readline.c
