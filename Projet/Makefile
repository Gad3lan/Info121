CFLAGS = -Wall -std=c++11

all : main

lib: animaux.cpp ensembles.cpp grille.cpp outils.cpp
	g++ $(CFLAGS) -c animaux.cpp ensembles.cpp grille.cpp outils.cpp

main: main.cpp lib
	g++ $(CFLAGS) main.cpp animaux.o ensembles.o grille.o outils.o -o foxwars

clean:
	rm -f foxwars animaux.o ensembles.o grille.o outils.o 