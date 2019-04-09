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
			int r = rand()%100;
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
	e.taille = 0;
	if (c.x == 0) minX = 0;
	if (c.x == TAILLE-1) maxX = TAILLE-1;
	if (c.y == 0) minY = 0;
	if (c.y == TAILLE-1) maxY = TAILLE-1;
	for (int i = minY; i <= maxY; i++) {
		for (int j = minX; j <= maxX; j++) {
			if ((i != c.y || j != c.x) && g.cases[i][j].type == t) {
				e.ens[e.taille] = toPos(j, i);
				e.taille++;
			}
		}
	}
	return e;
}

Coord coordAlea(EnsCoord e) {
	if (e.taille > 1)
		return e.ens[rand()%e.taille];
	else
		return e.ens[0];
}

bool estDansEC(EnsCoord e, Coord c) {
	for (int i = 0; i < e.taille; i++) {
		if (c.x == e.ens[i].x && c.y == e.ens[i].y) return true;
	}
	return false;
}

void afficheEns(EnsCoord e) {
	for (int i = 0; i < e.taille; i++) {
		cout << e.ens[i].x << "," << e.ens[i].y << "  ";
	}
	cout << endl;
}

void retireCoord(EnsCoord &e, Coord c) {
	for (int i = 0; i < e.taille; i++) {
		if (c.x == e.ens[i].x && c.y == e.ens[i].y) {
			e.taille--;
			e.ens[e.taille] = e.ens[i];
			break;
		}
	}
}

Grille deplacement(Grille &g, Grille newg, typeAnimal t) {
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if (g.cases[i][j].type == t && t != rien) {
				Coord newc;
				EnsCoord e1, e2, er;
				er = voisins(toPos(j, i), g, lapin);
				if (t == renard && er.taille > 0) {
					newc = coordAlea(er);
					g.cases[newc.y][newc.x] = creerAnimal(newc, rien);
					g.cases[i][j].nourLapin++;
				} else {
					e1 = voisins(toPos(j, i), g, rien);
					do {
						if (t == renard) {
							if (g.cases[i][j].nourLapin <= 0)
								g.cases[i][j] = creerAnimal(toPos(j, i), rien);
							g.cases[i][j].nourLapin--;
						}
						if (e1.taille > 0) {
							newc = coordAlea(e1);
							retireCoord(e1, newc);
							e2 = voisins(toPos(j, i), newg, rien);

						} else {
							newc.x = j;
							newc.y = i;
							break;
						}
					} while (!estDansEC(e2, newc) && e2.taille != 0);
				}
				newg.cases[newc.y][newc.x] = g.cases[i][j];
				newg.cases[i][j] = creerAnimal(toPos(j, i), rien);
			}
		}
	}
	return newg;
}

Grille creeGrilleVide() {
	Grille g;
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			g.cases[i][j] = creerAnimal(toPos(j, i), rien);
		}
	}
	return g;
}

void afficheGrille(Grille g) {
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if (g.cases[i][j].type == renard) cout << "\033[31mR ";
			else if (g.cases[i][j].type == lapin) cout << "\033[34mL ";
			else {
				cout << "\033[97m0 ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

Grille deplacementGlobal(Grille g) {
	Grille newg = creeGrilleVide();
	newg = deplacement(g, newg, renard);
	//afficheGrille(newg);
	newg = deplacement(g, newg, lapin);
	return newg;
}

void compteAnimal(Grille g) {
	int r = 0;
	int l = 0;
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if (g.cases[i][j].type == renard) r++;
			if (g.cases[i][j].type == lapin) l++;
		}
	}
	cout << "\033[97mNb renards: " << r << ", Nb lapins: " << l << endl;
}

int main() {
	srand (time(NULL));
	Grille g = initGrille();
	afficheGrille(g);
	//compteAnimal(g);
	for (int i = 0; i < 10; i++) {
		g = deplacementGlobal(g);
		afficheGrille(g);
	}
	//compteAnimal(g);
	return 0;
}