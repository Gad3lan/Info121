#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

float probRenard = 7;
float probLapin = 20;

struct Coord {
	int x;
	int y;
};

struct EnsCoord {
	vector<Coord> ens;
};

struct Renard {
	int nourInit = 5;
	int nourLapin = 5;
	int nourReprod = 8;
	int maxNour = 10;
	float probNaissance = 0.05;
	Coord pos;
};

struct Lapin {
	float probNaissance = 0.30;
	int espaceLibreNaissance = 4;
	Coord pos;
};

vector<Renard> renards;
vector<Lapin> lapins;

enum Animal {renard, lapin, rien};

using Grille = vector<vector<Animal> >;

Coord toPos(int x, int y) {
	return {x, y};
}

Grille initGrille(int taille) {
	Grille g;
	for (int i = 0; i < taille; i++) {
		vector<Animal> ligne;
		for (int j = 0; j < taille; j++) {
			int r = rand()%100;
			if (r < probRenard) {
				Renard r;
				r.pos = toPos(j, i);
				ligne.push_back(renard);
				renards.push_back(r);
			}
			else if (r < probRenard + probLapin) {
				Lapin l;
				l.pos = toPos(j, i);
				ligne.push_back(lapin);
				lapins.push_back(l);
			}
			else ligne.push_back(rien);
		}
		g.push_back(ligne);
	}
	return g;
}

int main() {
	srand (time(NULL));
	Grille g = initGrille(5);
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (g[i][j] == renard) cout << "R ";
			else if (g[i][j] == lapin) cout << "L ";
			else cout << "0 ";
		}
		cout << endl;
	}
	cout << "Lapins:\n";
	for (int i = 0; i < lapins.size(); i++) {
		cout << lapins[i].pos.x << " " << lapins[i].pos.y << endl;
	}
	cout << "\nRenards:\n";
	for (int i = 0; i < renards.size(); i++) {
		cout << renards[i].pos.x << " " << renards[i].pos.y << endl;
	}
	return 0;
}