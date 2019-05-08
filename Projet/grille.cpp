#include "header.hpp"

Grille initGrille() {
	Grille g;
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			int r = rand()%100;
			Coord pos = versPos(j, i);
			if (r < probRenard) g.cases[i][j] = creerAnimal(pos, renard);
			else if (r < probRenard+probLapin) g.cases[i][j] = creerAnimal(pos, lapin);
			else g.cases[i][j] = creerAnimal(pos, vide);
		}
	}
	return g;
}

Grille deplacement(Grille &g, Grille newg, typeAnimal t) {
	EnsCoord animeaux;
	animeaux.taille = 0;
	for (int i = 0; i < TAILLE; i++)
		for (int j = 0; j < TAILLE; j++)
			if (g.cases[i][j].type == t)
				ajouteCoord(animeaux, versPos(j, i));
	while (animeaux.taille > 0) {
		Coord pos = coordAlea(animeaux);
		Animal animal = g.cases[pos.y][pos.x];
		if (!mangeRenard(g, newg, animal, pos)) {
            Coord newc;
			EnsCoord ensSrc = voisins(pos, g, vide);
            EnsCoord ensDest = voisins(pos, newg, vide);
			do {
				if (ensSrc.taille > 0) {
					newc = coordAlea(ensSrc);
					retireCoord(ensSrc, newc);
				} else {
					newc = pos;
					break;
				}
			} while (!estDansEC(ensDest, newc) && ensDest.taille != 0);
			animal.pos = newc;
			newg.cases[newc.y][newc.x] = animal;
		}
		retireCoord(animeaux, pos);
	}
	return newg;
}

// Grille deplacement(Grille &g, Grille newg, typeAnimal t) {
// 	for (int i = 0; i < TAILLE; i++) {
// 		for (int j = 0; j < TAILLE; j++) {
// 			if (g.cases[i][j].type == t && t != vide) {
// 				Coord newc;
// 				EnsCoord ensSrc, ensDest;
// 				EnsCoord ensLapin = voisins(versPos(j, i), g, lapin);
// 				if (t == renard && ensLapin.taille > 0) {
// 					newc = coordAlea(ensLapin);
// 					g.cases[newc.y][newc.x] = creerAnimal(newc, vide);
// 					g.cases[i][j].nourLapin++;
// 				} else {
// 					ensSrc = voisins(versPos(j, i), g, vide);
// 					do {
// 						if (t == renard) {
// 							if (g.cases[i][j].nourLapin <= 0)
// 								g.cases[i][j] = creerAnimal(versPos(j, i), vide);
// 							g.cases[i][j].nourLapin--;
// 						}
// 						if (ensSrc.taille > 0) {
// 							newc = coordAlea(ensSrc);
// 							retireCoord(ensSrc, newc);
// 							ensDest = voisins(versPos(j, i), newg, vide);

// 						} else {
// 							newc.x = j;
// 							newc.y = i;
// 							break;
// 						}
// 					} while (!estDansEC(ensDest, newc) && ensDest.taille != 0);
// 				}
// 				newg.cases[newc.y][newc.x] = g.cases[i][j];
// 				newg.cases[i][j] = creerAnimal(versPos(j, i), vide);
// 			}
// 		}
// 	}
// 	return newg;
// }

Grille creeGrilleVide() {
	Grille g;
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			g.cases[i][j] = creerAnimal(versPos(j, i), vide);
		}
	}
	return g;
}

Grille deplacementGlobal(Grille g) {
	Grille newg = creeGrilleVide();
	newg = deplacement(g, newg, renard);
	newg = deplacement(g, newg, lapin);
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			repro(newg, newg.cases[i][j].type, versPos(j, i));
		}
	}
	return newg;
}
