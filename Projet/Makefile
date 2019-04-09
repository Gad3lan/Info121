CFLAGS = -Wall -g -std=c++11 #definition de variable

all : main

lib: animaux.cpp ensembles.cpp grille.cpp outils.cpp
	g++ $(CFLAGS) -c animaux.cpp ensembles.cpp grille.cpp outils.cpp

main: main.cpp lib
	g++ $(CFLAGS) main.cpp animaux.o ensembles.o grille.o outils.o -o tri

clean:
	rm -f main animaux.o ensembles.o grille.o outils.o -o tri