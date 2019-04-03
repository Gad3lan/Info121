#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

int probRenard = 7;
int probLapin = 20;

const int TAILLE = 10;
const int MAXOBJ = TAILLE*TAILLE;

struct Coord {
	int x;
	int y;
};

struct EnsCoord {
	int taille;
	Coord ens[MAXOBJ];
};

enum typeAnimal {renard, lapin, rien};

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

Coord toPos(int x, int y) {
	return {x, y};
}

Animal creerAnimal(Coord p, typeAnimal t) {
	Animal a;
	switch(t) {
		case renard :
			a.type = t; 
			a.nourInit = 5;
			a.nourLapin = 5;
			a.nourReprod = 8;
			a.maxNour = 10;
			a.probNaissanceRenard = 0.05;
			a.espaceLibreNaissanceLapin = 0;
			a. probNaissanceLapin = 0;
			a.pos = p;
			break;
		case lapin :
			a.type = t; 
			a.nourInit = 0;
			a.nourLapin = 0;
			a.nourReprod = 0;
			a.maxNour = 0;
			a.probNaissanceRenard = 0;
			a.espaceLibreNaissanceLapin = 4;
			a. probNaissanceLapin = 0.3;
			a.pos = p;
			break;
		default :
			a.type = t; 
			a.nourInit = 0;
			a.nourLapin = 0;
			a.nourReprod = 0;
			a.maxNour = 0;
			a.probNaissanceRenard = 0;
			a.espaceLibreNaissanceLapin = 0;
			a. probNaissanceLapin = 0;
			a.pos = p;
			break;
	}
	return a;
}

Grille initGrille() {
	Grille g;
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			float r = rand()%100;
			if (r < probRenard) g.cases[i][j] = creerAnimal(toPos(j, i), renard);
			else if (r < probRenard+probLapin) g.cases[i][j] = creerAnimal(toPos(j, i), lapin);
			else g.cases[i][j] = creerAnimal(toPos(j, i), rien);
		}
	}
	return g;
}

EnsCoord voisins(Coord c, Grille g, typeAnimal t) {
	int minX = c.x-1, maxX = c.x+1, minY = c.y-1, maxY = c.y+1;
	EnsCoord e;
	if (c.x == 0) minX = 0;
	if (c.x == TAILLE-1) maxX = TAILLE-1;
	if (c.y == 0) minY = 0;
	if (c.y == TAILLE-1) maxY = TAILLE-1;
	for (int i = minY; i <= maxY; i++) {
		for (int j = minX; j <= maxX; j++) {
			if (i != c.y && j != c.x && g.cases[c.y][c.x].type == t) {
				e.ens[e.taille] = toPos(j, i);
				e.taille++;
			}
		}
	}
	return e;
}

Coord coordAlea(EnsCoord e) {
	return e.ens[rand()%e.taille];
}

bool estDansEC(EnsCoord e, Coord c) {
	for (int i = 0; i < e.taille; i++) {
		if (c.x == e.ens[i].x && c.y == e.ens[i].y) return true;
	}
	return false;
}

Grille deplacement(Grille g, typeAnimal t) {
	Grille newg;
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if (g.cases[i][j].type == t) {
				do {
					EnsCoord e1 = voisins(toPos(j, i), g, vide);
					Coord newc = coordAlea(e);
					EnsCoord e2 = voisins(toPos(j, i), newg, vide);
				} while (estDansEC(e2, newc));
				
		}
	}
	return newg;
}

Grille deplacementGlobal(Grille g) {
	
}

int main() {
	srand (time(NULL));
	Grille g = initGrille();
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if (g.cases[i][j].type == renard) cout << "R ";
			else if (g.cases[i][j].type == lapin) cout << "L ";
			else cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			cout << g.cases[i][j].pos.x << "," << g.cases[i][j].pos.y << " ";
		}
		cout << endl;
	}
	return 0;
}
