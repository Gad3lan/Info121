#include "header.hpp"

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl; else cout << "reussi\n"

void testEnsembles() {
	Grille g = initGrille();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2)
				g.cases[i][j] = creerAnimal(versPos(j, i), lapin);
			else
				g.cases[i][j] = creerAnimal(versPos(j,i), renard);
		}
	}

	EnsCoord EC = voisins(versPos(1, 1), g, renard);
	cout << "Test taille voisins renard:\t\t\t";
	ASSERT(EC.taille == 5);
	cout << "Test coordonne est dans voisins:\t\t";
	ASSERT(estDansEC(EC, versPos(0, 0)));
	cout << "Test coordonne n'est pas dans voisins:\t\t";
	ASSERT(!estDansEC(EC, versPos(3, 3)));

	Coord c = versPos(4, 4);

	ajouteCoord(EC, c);
	cout << "Test ajout coord:\t\t\t\t";
	ASSERT(estDansEC(EC, c));
	cout << "Test taille ensemble apres ajout coord:\t\t";
	ASSERT(EC.taille == 6);

	retireCoord(EC, c);
	cout << "Test retrait coord:\t\t\t\t";
	ASSERT(!estDansEC(EC, c));
	cout << "Test taille ensemble apres retrait coord:\t";
	ASSERT(EC.taille == 5);

	cout << "Test taille voisins lapin:\t\t\t";
	ASSERT(voisins(versPos(1, 1), g, lapin).taille == 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			g.cases[i][j] = creerAnimal(versPos(j,i), vide);
		}
	}
	cout << "Test taille voisins vide:\t\t\t";
	ASSERT(voisins(versPos(1, 1), g, vide).taille == 8);
}

int main() {
	srand (time(NULL));
	Grille g = initGrille();
	afficheGrille(g);
	for (int i = 0; i < 10; i++) {
		clear();
		g = deplacementGlobal(g);
		afficheGrille(g);
		if(!compteAnimal(g)) {
			cout << "Tous les animeaux sont mort" << endl;
			break;
		}
		usleep(200000);
	}
	cout << "Fin de la simulation" << endl << endl;
	cout << "Phase de test" << endl;
	testEnsembles();
	//compteAnimal(g);
	return 0;
}