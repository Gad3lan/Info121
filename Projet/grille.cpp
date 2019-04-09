#include "header.hpp"

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

Grille deplacementGlobal(Grille g) {
	Grille newg = creeGrilleVide();
	newg = deplacement(g, newg, renard);
	//afficheGrille(newg);
	newg = deplacement(g, newg, lapin);
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			repro(newg, newg.cases[i][j].type, toPos(j, i));
		}
	}
	return newg;
}