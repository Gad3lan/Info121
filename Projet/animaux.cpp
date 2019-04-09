#include "header.hpp"

Animal creerAnimal(Coord p, typeAnimal t) {
	Animal a;
	switch(t) {
		case renard :
			a.type = t; 
			a.nourInit = 5;
			a.nourLapin = 5;
			a.nourReprod = 8;
			a.maxNour = 10;
			a.probNaissanceRenard = 5;
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
			a. probNaissanceLapin = 30;
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

void repro(Grille &g, typeAnimal t, Coord c) {
	EnsCoord e = voisins(c, g, vide);
	switch (t)
	{
		case renard :
			if (g.cases[c.y][c.x].nourLapin >= g.cases[c.y][c.x].nourReprod && e.taille > 0) {
				if (rand()%100 <= g.cases[c.y][c.x].probNaissanceRenard) {
					Coord newc = coordAlea e);
					g.cases[newc.y][newc.x] = creerAnimal(newc, renard);
				}
			}
			break;
		case lapin :
			if (e.taille >= g.cases[c.y][c.x].espaceLibreNaissanceLapin) {
				if (rand()%100 <= g.cases[c.y][c.x].probNaissanceLapin) {
					Coord newc = coordAlea e);
					g.cases[newc.y][newc.x] = creerAnimal(newc, lapin);
				}
			}
			break;
		default:
			break;
	}
}