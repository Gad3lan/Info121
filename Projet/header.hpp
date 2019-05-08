#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <unistd.h>

using namespace std;

const int TAILLE = 20;
const int MAXOBJ = TAILLE*TAILLE;

const int probRenard = 7;
const int probLapin = 20;

struct Coord {
	int x;
	int y;
};

struct EnsCoord {
	int taille;
	Coord ens[MAXOBJ];
};

enum typeAnimal {renard, lapin, vide};

struct Animal {
	typeAnimal type;
	int nourInit;
	int nourLapin;
	int nourReprod;
	int maxNour;
	float probNaissanceRenard;
	int espaceLibreNaissanceLapin;
	float probNaissanceLapin;
	Coord pos;
};

struct Grille {
	Animal cases[TAILLE][TAILLE];
};

Coord versPos(int x, int y);
void ajouteCoord(EnsCoord &e, Coord c);
bool mangeRenard(Grille &g, Grille &newg, Animal &a, Coord c);
Animal creerAnimal(Coord p, typeAnimal t);
Grille initGrille();
EnsCoord voisins(Coord c, Grille g, typeAnimal t);
Coord coordAlea(EnsCoord e);
bool estDansEC(EnsCoord e, Coord c);
void afficheEns(EnsCoord e);
void retireCoord(EnsCoord &e, Coord c);
void repro(Grille &g, typeAnimal t, Coord c);
Grille deplacement(Grille &g, Grille newg, typeAnimal t);
Grille creeGrilleVide();
void afficheGrille(Grille g);
Grille deplacementGlobal(Grille g);
void compteAnimal(Grille g);
void clear();
