#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum genre {homme, femme};
enum orientation {hetero, homo};

struct Personne {
	string nom;
	string prenom;
	int annee;
	genre sexe;
	orientation orientation_sexuelle;
};

Personne nouvellePersonne(string n, string p, int a, genre s, orientation o) {
	return {n, p, a, s, o};
}

bool estFaisable(Personne p1, Personne p2) {
	return (p1.sexe != p2.sexe && p1.orientation_sexuelle == p2.orientation_sexuelle && p1.orientation_sexuelle == hetero) || (p1.sexe == p2.sexe && p1.orientation_sexuelle == p2.orientation_sexuelle && p1.orientation_sexuelle == homo);
}

void afficherCoupleFaisable(vector<Personne> pop) {
	for (unsigned int i = 0; i < pop.size(); i++) {
		for (unsigned int j = i + 1; j < pop.size(); j++) {
			if (estFaisable(pop[i], pop[j]))
				cout << pop[i].prenom << " " << pop[i].nom << " et " << pop[j].prenom << " " << pop[j].nom << endl;
		}  
	}
}

int main() {
	vector<Personne> population = {
		nouvellePersonne("Bonnet", "Jean", 1979, homme, homo),
		nouvellePersonne("Lefebvre", "Michel", 1981, homme, hetero),
		nouvellePersonne("Leroy", "Pierre", 1977, homme, hetero),
		nouvellePersonne("Petit", "Philippe", 1984, homme, hetero),
		nouvellePersonne("Morel", "Alain", 1990, homme, homo),
		nouvellePersonne("Fournier", "Marie", 1985, femme, hetero),
		nouvellePersonne("Durand", "Nathalie", 1989, femme, homo),
		nouvellePersonne("Dubois", "Isabelle", 1975, femme, hetero),
		nouvellePersonne("Moreau", "Catherine", 1982, femme, homo),
		nouvellePersonne("Girard", "Sylvie", 1987, femme, hetero)
	};
	afficherCoupleFaisable(population);
	return 0;
}
