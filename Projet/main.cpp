#include "header.hpp"

int main() {
	srand (time(NULL));
	Grille g = initGrille();
	afficheGrille(g);
	for (int i = 0; i < 200; i++) {
		clear();
		g = deplacementGlobal(g);
		afficheGrille(g);
		compteAnimal(g);
		usleep(100000);
	}
	//compteAnimal(g);
	return 0;
}