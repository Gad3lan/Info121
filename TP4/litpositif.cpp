#include<iostream>
#include<string>

using namespace std;

void litpositif(int &res, int &nbErr) {
	int resultat;
	nbErr = -1;
	do {
		nbErr++;
		cout << "Donner la valeur de l'entier positif : ";
		cin >> resultat;
	} while (resultat < 0);
}

int main() {
	int nb, err;
	litpositif(nb, err);
	cout << "Entier positif lu: " << nb << "\nNombre d'erreurs: " << err << endl;
	return 0;
}
