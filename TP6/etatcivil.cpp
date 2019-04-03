#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

const int MAXPERSONNES = 50;

enum Genre { M, F };

struct Personne{
  string nom;
  Genre genre;
  int indConjoint, indParent1, indParent2;
};

struct EtatCivil {
   Personne tableP[MAXPERSONNES];
   int nbP;
};

int estDans(string n, EtatCivil EC) {
	for (int i = 0; i < EC.nbP; i++) {
		if (EC.tableP[i].nom == n) 
			return i;
	}
	return -1;
}

void testEstDans(EtatCivil EC) {
	ASSERT(estDans("Augustin", EC) == 18);
	ASSERT(estDans("Paul", EC) == -1);
}

void AjoutPersonne(string sonNom, Genre s, int parent1, int parent2, EtatCivil &EC) {
	if (estDans(sonNom, EC) <= 0 && EC.nbP < MAXPERSONNES) {
		EC.tableP[EC.nbP] = {sonNom, s, -1, parent1, parent2};
		EC.nbP++;
	}
}

void AffichePersonne(int ind, EtatCivil EC) {
	if (ind < 0 || ind >= EC.nbP) 
		cout << "Cette personne n'existe pas." << endl;
	else {
		Personne p = EC.tableP[ind];
		cout << "Nom: " << p.nom << endl;
		switch(p.genre) {
			case M : 
				cout << "Genre: Homme" << endl;
				break;
			case F :
				cout << "Genre: Femme" << endl;
				break;
			default :
				cout << "Genre: Inconnu" << endl;
		}
		if (p.indConjoint >= 0 && p.indConjoint < EC.nbP)
			cout << "Conjoint: " << EC.tableP[p.indConjoint].nom << endl;
		if (p.indParent1 >= 0 && p.indParent1 < EC.nbP)
			cout << "Parent1: " << EC.tableP[p.indParent1].nom << endl;
		if (p.indParent2 >= 0 && p.indParent2 < EC.nbP)
			cout << "Parent2: " << EC.tableP[p.indParent2].nom << endl;
	}
	cout << endl;
}

void AfficheEtatCivil(EtatCivil EC) {
	for (int i = 0; i < EC.nbP; i++)
		AffichePersonne(i, EC);
}

bool mariage(string n1, string n2, EtatCivil &EC) {
	int i1 = estDans(n1, EC);
	int i2 = estDans(n2, EC);
	if (i1 >= 0 && i2 >= 0 && i1 != i2 && EC.tableP[i1].indConjoint == -1 && EC.tableP[i2].indConjoint == -1) {
		EC.tableP[i1].indConjoint = i2;
		EC.tableP[i2].indConjoint = i1;
		return true;
	}
	return false;
}

void parent(int id, EtatCivil EC, int e);

void AfficheArbre(Personne p, EtatCivil EC, int e) {
	for (int i = 0; i < e; i++)
		cout << "\t";
	cout << p.nom << endl;
	parent(p.indParent1, EC, e);
	parent(p.indParent2, EC, e);
}

void parent(int id, EtatCivil EC, int e) {
	if (id >= 0) 
		AfficheArbre(EC.tableP[id], EC, e+1);
	else {
		for (int i = 0; i < e+1; i++)
			cout << "\t";
		cout << "Igannu" << endl;
	}
}

void RemplitEtatCivil(EtatCivil &EC) { // remplit l'état civil avec 20 personnes
  AjoutPersonne("Noemie", F, -1, -1, EC);
  AjoutPersonne("Georges", M, -1, -1, EC);
  AjoutPersonne("Albert", M, -1, -1, EC);
  AjoutPersonne("Marie", F, -1, -1, EC);
  AjoutPersonne("Luc", M, 0, -1, EC);
  AjoutPersonne("Valerie", F, -1, 1, EC);
  AjoutPersonne("Stephane", M, 3, 2, EC);
  AjoutPersonne("Helene", F, 5, 4, EC);
  AjoutPersonne("Justine", F, 7, 6, EC);
  AjoutPersonne("Berenice", F, 5, 10, EC);
  AjoutPersonne("John", M, 12, 11, EC);
  AjoutPersonne("Franco", M, -1, -1, EC);
  AjoutPersonne("Viviane", F, -1, -1, EC);
  AjoutPersonne("Pierre", M, 9, 14, EC);
  AjoutPersonne("Remi", M, 16, 15, EC);
  AjoutPersonne("Boris", M, -1, 17, EC);
  AjoutPersonne("Sharon", F, 19, 18, EC);
  AjoutPersonne("Alexandre", M, -1, -1, EC);
  AjoutPersonne("Augustin", M, -1, -1, EC);
  AjoutPersonne("Johanne", F, -1, -1, EC);
}


int main() {
  EtatCivil EC;
  EC.nbP = 0; // il est necessaire d'initialiser le nombre de personnes
  RemplitEtatCivil(EC);
  testEstDans(EC);
  AfficheEtatCivil(EC);
  AjoutPersonne("Richard", M, 9, 16, EC);
  AffichePersonne(20, EC);
  mariage("Johanne", "Georges", EC);
  cout << "Mariage:" << endl;
  AffichePersonne(19, EC);
  AffichePersonne(1, EC);
  AfficheArbre(EC.tableP[5], EC, 0);
}
