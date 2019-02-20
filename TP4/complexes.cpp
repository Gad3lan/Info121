#include <iostream>

using namespace std;

void saisie(int &a, int &b) {
	cout << "Saisir la valeur de a: ";
	cin >> a;
	cout << "Saisir la valeur de b: ";
	cin >> b;
}

void affiche(int a, int b) {
	cout << a << " + i" << b << endl;
}

void somme(int &a1, int &b1, int a2, int b2) {
	a1 += a2;
	b1 += b2;
}

void produit(int &a1, int &b1, int a2, int b2) 
