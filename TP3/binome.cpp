#include<iostream>
#include <iomanip>
#include<cstdlib>

using namespace std;
double epsilon = 1e-6;

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

double abs(double x) {
	if (x < 0)
		x*=-1;
	return x;
}

/** Calculer le factoriel d'un entier
 *  @param n un entier
 *  @return un entier
 **/
double factoriel(int n) {
    if (n < 0) {
        cerr << "Factoriel argument negatif file " << __FILE__ << " line " << __LINE__ << endl;
        exit(1);
    }
    double res = 1, i;
    for (i = 1 ; i <= n ; i ++) {
        res *= i;
    }
    return res;
}

/** Tester la fonction factorielle
 **/
void testFactoriel() {
    ASSERT(factoriel(0) == 1);
    ASSERT(factoriel(1) == 1);
    ASSERT(factoriel(2) == 2);
    ASSERT(factoriel(4) == 24);
    ASSERT(factoriel(9) == 362880);
}

/** Calculer le binome de Newton
 *  @param n entier, p entier, n >= p
 *  @return un entier
 **/
int binome(int n, int p) {
	return factoriel(n)/(factoriel(p)*factoriel(n-p));
}

/** Tester la fonction binome
 **/
void testBinome() {
    // valeur de base
    ASSERT(binome(0, 0) == 1);
    ASSERT(binome(3, 2) == 3);
    ASSERT(binome(4, 2) == 6);
    ASSERT(binome(5, 3) == 10);
    ASSERT(binome(10, 5) == 252);
}

double square(double x) {
	return x*x;
}

double power(double x, int n) {
	if (n == 0)
		return 1;
	else
		return x * power(x, n-1);
}

void testSquare() {
	ASSERT(square(5) == 25);
	ASSERT(square(10) == 100);
	ASSERT(square(7) == 49);
	ASSERT(square(square(5)) == 625);
	ASSERT(square(-4) == 16);
}

bool presqueEgal(double x, double y) {
	return abs(x-y) <= epsilon*abs(x) && abs(x-y) <= epsilon*abs(y);
}

void testpresqueEgal() {
	ASSERT(presqueEgal(1,1+epsilon/2) == true);
	ASSERT(presqueEgal(1, 1) == true);
	ASSERT(presqueEgal(1+1, 2) == true);
	ASSERT(presqueEgal(0, 0) == true);
	ASSERT(presqueEgal(1, 1+2*epsilon) == false);
	ASSERT(presqueEgal(0, 1) == false);
}

double racineCarre(double x) {
	double un = x;
	while(!presqueEgal(square(un), x)) {
		un = (un + x/un)/2;
	}
	return un;
}

void testracineCarre() {
	double res = racineCarre(0);
	ASSERT(res <= 0 + epsilon && res >= 0 - epsilon);
	res = racineCarre(1);
	ASSERT(res <= 1 + epsilon && res >= 1 - epsilon
	);
	res = racineCarre(4);
	ASSERT(res <= 2 + epsilon && res >= 2 - epsilon);
	res = racineCarre(2);
	ASSERT(res <= 1.41421356 + epsilon && res >= 1.41421356 - epsilon);
}

double racineNieme(double x, int n) {
	double un = x;
	while(!presqueEgal(power(un, n), x)) {
		un = (1./n) * (((n-1)*un) + (x/power(un, n-1)));
	}
	return un;
}

void testracineNieme() {
	double res = racineNieme(2, 5);
	ASSERT(res <= 1.1486983 + epsilon && res >= 1.1486983 - epsilon);
}

double exponentielle(double a) {
	double tot = 0;
	double tmp = -64564;
	for (int i = 0; !presqueEgal(tmp, tot); i++) {
		tmp = tot;
		tot += power(a, i)/factoriel(i);
	}
	return tot;
}

void testExponentielle() {
	double res = exponentielle(0);
	ASSERT(res <= 1 + epsilon && res >= 1 - epsilon);
	res = exponentielle(1);
	ASSERT(res <= 2.71828182 + epsilon && res >= 2.71828182 - epsilon);
}

double exponentielle2(double a) {
	double tot = 1;
	double tmp = -56453;
	double puis = 1;
	double fact = 1;

	for (int i = 1; !presqueEgal(tot, tmp); i++){
		tmp = tot;
		puis *= a;
		fact *= i;
		tot += puis/fact;
	}
	return tot;
}

void testExponentielle2() {
	double res = exponentielle2(0);
	ASSERT(res <= 1 + epsilon && res >= 1 - epsilon);
	res = exponentielle2(1);
	ASSERT(res <= 2.71828182 + epsilon && res >= 2.71828182 - epsilon);
}

double logarithme(double a) {
	double un = a;
	double tmp = -135464;
	while(!presqueEgal(un, tmp)) {
		tmp = un;
		un = un + a / exponentielle(un) - 1;
	}
	return un;
}

bool verifie(double a) {
	return presqueEgal(a, exponentielle(logarithme(a)));
}

double racine2(double a) {
	return exponentielle(logarithme(a)/2);
}

double racinenieme2 (double a, double n) {
	return exponentielle(logarithme(a)/n);
}

/** Fonction principale
 **/
int main() {
    testFactoriel();
    testBinome();
    testSquare();
    testpresqueEgal();
    testracineCarre();
    testracineNieme();
    testExponentielle();
    testExponentielle2();
    
    //double x;
    //cout << "Entrer un nombre : ";
    //cin >> x;
    //cout << "La racine carré de " << x << " est : " << racineCarre(x) << endl;
    
    return 0;
}
