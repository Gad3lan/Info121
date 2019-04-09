#include "header.hpp"

void clear() {
	cout << "\x1B[2J\x1B[H";
}

void afficheGrille(Grille g) {
	for (int i = 0; i < TAILLE; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if (g.cases[i][j].type == renard) cout << "\033[31m\u25A0 ";
			else if (g.cases[i][j].type == lapin) cout << "\033[34m\u25A0 ";
			else {
				cout << "\033[97m\u25A0 ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

Coord versPos(int x, int y) {
	return {x, y};
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