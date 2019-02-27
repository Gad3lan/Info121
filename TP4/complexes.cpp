#include <iostream>

using namespace std;

const float EPSILON = 1e-6;

struct Complexe {
	float re, im;
};

void saisie(Complexe &c) {
	cout << "Saisir la valeur de a: ";
	cin >> c.re;
	cout << "Saisir la valeur de b: ";
	cin >>c.im;
}

void affiche(Complexe c) {
	cout << c.re << " + " << c.im << "i" << endl;
}

Complexe somme(Complexe c1, Complexe c2) {
	return {c1.re + c2.re, c1.im + c2.im};
}

Complexe sub(Complexe c1, Complexe c2) {
	return {c1.re-c2.re, c1.im - c2.im};
}

void conjugue(Complexe &c) {
	c.im *= -1;
}

Complexe produit(Complexe c1, Complexe c2)  {
	return {(c1.re*c2.re) - (c1.im*c2.im), (c1.re*c2.im) + (c1.im*c2.re)};
}

Complexe div(Complexe c, float d) {
	return {c.re/d, c.im/d};
}

float norme_carre(Complexe c) {
	return c.re*c.re + c.im*c.im;
}

Complexe inverse(Complexe c) {
	Complexe conj = c;
	conjugue(conj);
	return div(conj, norme_carre(c));
}

Complexe sqrt(Complexe c) {
	Complexe u;
	if (c.re < 0)
		u = {c.re, EPSILON};
	else 
		u = c;
	while(norme_carre(sub(produit(u, u), c))/norme_carre(c) > EPSILON*EPSILON)
		u = div(somme(u, produit(c,inverse(u))), 2);
	return u;
}

int main() {
	Complexe c = {1.2367, -4.5};
	Complexe c2 = {2, 1};
	Complexe conj = c;
	conjugue(c);
	cout << "Affichage des 2 complexes :" << endl;
	affiche(c);
	affiche(c2);
	cout << "Somme des 2 complexes :" << endl;
	affiche(somme(c, c2));
	cout << "Conjugué du premier complexe :" << endl;
	affiche(conj);
	cout << "Produit des 2 complexes :" << endl;
	affiche(produit(c, c2));
	cout << "Inverse du premier complexe :" << endl;
	affiche(inverse(c));
	cout << "Racine carre du premier complexe :" << endl;
	affiche(sqrt(c));
}

