#include <iostream>
#include <cmath>
#include <cstdlib>

#include "MonPolyAbstrEx1.hpp"


void  PolynomeNul(Polynome &p) {
	for (int i = 0; i <= MAX_DEGRE; i++) {
		p.coeffs[i] = 0;
	}
}
bool  egalPoly(Polynome p1, Polynome p2) {
	for (int i = 0; i <= MAX_DEGRE; i++)
		if (p1.coeffs[i] != p2.coeffs[i])
			return false;
	return true;
}
void  modifierCoeffPoly(Polynome &p, int d, float co) {
	p.coeffs[d] = co;
}
int   degrePoly(Polynome p) {
	for (int i = MAX_DEGRE; i >= 0; i--)
		if (p.coeffs[i] != 0)
			return i;
	return -1;
}
float coeffPoly(Polynome p, int d) {
	return p.coeffs[d];
}
bool  estNulPoly(Polynome p) {
	for (int i = 0; i <= MAX_DEGRE; i++) {
		if (p.coeffs[i] != 0)
			return false;
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
//							 fonctions de tests							  //
/////////////////////////////////////////////////////////////////////////////////

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
									   << " line " << __LINE__ << ": " #test << std::endl

void test_PolynomeNul() {
	Polynome p;
	PolynomeNul(p);
	ASSERT(estNulPoly(p));
	ASSERT(coeffPoly(p, 0)==0);
	ASSERT(coeffPoly(p, 1)==0);
}

void test_modifierCoeffPoly() {
	Polynome p;
	PolynomeNul(p);
	modifierCoeffPoly(p, 0, 2);
	ASSERT(coeffPoly(p, 0)==2);
	ASSERT(coeffPoly(p, 1)==0);
	modifierCoeffPoly(p, 1, 42);
	ASSERT(coeffPoly(p, 0)==2);
	ASSERT(coeffPoly(p, 1)==42);
}

void test_degrePoly() {
	Polynome p;
	PolynomeNul(p);
	ASSERT(degrePoly(p) == -1);
	modifierCoeffPoly(p, 0, 2);
	ASSERT(degrePoly(p) == 0);
	modifierCoeffPoly(p, 5, 2);
	ASSERT(degrePoly(p) == 5);
	modifierCoeffPoly(p, 3, 1);
	ASSERT(degrePoly(p) == 5);
	modifierCoeffPoly(p, 5, 0);
	ASSERT(degrePoly(p) == 3);
}

void test_coeffPoly(){
	Polynome p;
	PolynomeNul(p);
	for (int i=0; i<10; i++)
		ASSERT(coeffPoly(p, i)==0);
	modifierCoeffPoly(p, 0, 2);
	ASSERT(coeffPoly(p, 0)==2);
	for (int i=1; i<10; i++)
		ASSERT(coeffPoly(p, i)==0);
	modifierCoeffPoly(p, 3, 42);
	ASSERT(coeffPoly(p, 0)==2);
	ASSERT(coeffPoly(p, 1)==0);
	ASSERT(coeffPoly(p, 2)==0);
	ASSERT(coeffPoly(p, 3)==42);
	for (int i=4; i<10; i++)
		ASSERT(coeffPoly(p, i)==0);
}

void test_estNulPoly(){
	Polynome p;
	PolynomeNul(p);
	ASSERT(estNulPoly(p));
	modifierCoeffPoly(p, 0, 2);
	ASSERT(! estNulPoly(p));
	modifierCoeffPoly(p, 2, 2);
	ASSERT(! estNulPoly(p));
	modifierCoeffPoly(p, 0, 0);
	ASSERT(! estNulPoly(p));
	modifierCoeffPoly(p, 2, 0);
	ASSERT(estNulPoly(p));
}
