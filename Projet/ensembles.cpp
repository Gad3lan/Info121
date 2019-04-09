#include "header.hpp"

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
				e.ens[e.taille] = versPos(j, i);
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