#include <iostream>
#include "PolyAbstr.hpp"

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

/////////////////////////////////////////////////////////////////////////////////
//                   Utilisation du type abstrait : affichages                 //
/////////////////////////////////////////////////////////////////////////////////

using namespace std;

/* affiche le monome d'un polynome
 * @param[in] i Degré du monome
 * @param[in] co Coefficient du monome
 * @param[in] premier Est-ce le premier monome affiché pour un polynome ?
 */
void afficheMonome(int i, float co, bool premier) {
	if (co != 0) {
		// affiche le signe
		if (co > 0 && not premier) {
			cout << " + ";
		}
		if (co < 0) {
			cout << " - ";
			co = -co;
		}
		// affiche le coefficient
		if ((co != 1) || (i == 0))
			cout << co;
		// affiche la puissance de X
		if (i > 1) cout << "X^" << i;
		else if (i == 1) cout << "X";
	  }
}


/* Affiche un polynome dans la console
 * @param[in] p Polynome à afficher
 */
void affichePoly(Polynome p) {
	int d, i;
	if (estNulPoly(p)) cout << 0 << endl;
	else {
	d = degrePoly(p);
		afficheMonome(d, coeffPoly(p, d), true);
		for (i = d-1; i >= 0; i--)
			afficheMonome(i, coeffPoly(p, i), false);
		cout << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////
//             Utilisation du type abstrait : fonction vue en cours            //
/////////////////////////////////////////////////////////////////////////////////

/* Multiple un polynome par une constante
 * @param[in/out] p Polynome à multiplier
 * @param[in] la Constante
 */
void multPolyConst(Polynome &p, float a) {
	int d, i;
	float c;

	if (a == 0)
		PolynomeNul(p);
	else {
		d = degrePoly(p);
		for (i=0; i<=d; i++) {
			c = coeffPoly(p, i);
			modifierCoeffPoly(p, i, c*a);
		}
	  }
}

/* Dérive un polynome
 * @param[in] p Polynome à dériver
 * @param[out] res le résultat de la dérivation
 */
void deriveePoly(Polynome p, Polynome &res) {
	int d, i;
	d = degrePoly(p);
	PolynomeNul(res);
	for (i=0; i<d; i++) {
		modifierCoeffPoly(res, i, (i+1)*coeffPoly(p, i+1));
	}
}

/////////////////////////////////////////////////////////////////////////////////
//               Utilisation du type abstrait : fonction à écrire              //
/////////////////////////////////////////////////////////////////////////////////

float evalPoly(Polynome p, float x);
float evalHornerPoly(Polynome p, float x);
void polynomeCoeffEgaux(Polynome &p, int degree, float coeff);
void produitPolyXn(Polynome p, int n, Polynome &res);
void produitPoly(Polynome p, Polynome q, Polynome &res);
void puissancePoly(Polynome p, int n, Polynome &res);

void polynomeCoeffEgaux(Polynome &p, int degree, float coeff){
	for (int i=0; i<=degree; i++) {
		modifierCoeffPoly(p, i, coeff);
	}
}

float evalPoly(Polynome p, float x){
	int d, i; 
	float res=0;
	d = degrePoly(p);
	for (i=d; i>=0; i--) {
		res+= puissance(x, i)*coeffPoly(p, i);
	}
	return res;
}



float evalHornerPoly(Polynome p, float x){
	int d, i; 
	d = degrePoly(p);
	float res = coeffPoly(p, d);
	for (i=d-1; i>=0; i--) {
	   // cout<<res<<" "<<coeffPoly(p, i)<<endl;
		res= res*x +coeffPoly(p, i);
	   // cout<<"res: "<< res<<endl;
	}
	return res;
}


void ajoutePoly(Polynome &p, Polynome q){
	for (int i = degrePoly(q); i>=0; i--){
		modifierCoeffPoly(p, i, coeffPoly(q, i)+coeffPoly(p, i));//puissance degre
	}
}

void produitPolyXn(Polynome p, int n, Polynome &res){
	for (int i = degrePoly(p); i>=0; i--){
		modifierCoeffPoly(res, i+n, coeffPoly(p, i));
	}
}

void produitPoly(Polynome p, Polynome q, Polynome &res){
	Polynome res1;
	float coeff;
	for (int i = degrePoly(q); i>=0; i--){
		//affichePoly(res1);
		//ajoutePoly(res, res1);
		PolynomeNul(res1);

		coeff=coeffPoly(q, i);
		produitPolyXn(p, i, res1);
		multPolyConst(res1, coeff);
		affichePoly(res);
		affichePoly(res1);
		ajoutePoly(res, res1);

	}
}

void puissancePoly(Polynome p, int n, Polynome &res) {
	int compteur=0;
		Polynome res1, puissance;
		PolynomeNul(res1);
		while(compteur<n){
			PolynomeNul(puissance);
			modifierCoeffPoly(puissance, compteur, 1.);
			ajoutePoly(res, puissance );
			for(int i= degrePoly(res)-1; i>0; i--){
				modifierCoeffPoly(res, i, coeffPoly(res, i) + coeffPoly(res, i-1));
		}
		affichePoly(res);
		compteur++;
	}
}

int main() {
	Polynome p, q, r, s, mille, test, mitroglou, test1, test2, res, test3, test4, res1, polynome1, polynomeres ;
	/*
	//TESTS
	olynomeNul(p);
	modifierCoeffPoly(p, 5,  4.);
	modifierCoeffPoly(p, 2, -5.);
	modifierCoeffPoly(p, 1,  1.);
	modifierCoeffPoly(p, 0, -1.);

	cout << "Le polynome p est : ";
	affichePoly(p);

	ASSERT( egalPoly(p, p) );

	cout << "Le polynome 3*p est : ";
	q = p;
	multPolyConst(q, 3.);
	affichePoly(q);

	cout << "La derivee de p est : ";
	deriveePoly(p, q);
	affichePoly(q);

	ASSERT( not egalPoly(p, q) );

	//Q2
	PolynomeNul(p);
	modifierCoeffPoly(p, 4,  1.);
	  
	modifierCoeffPoly(p, 2, 2.);
	modifierCoeffPoly(p, 0,  -5.);
	// cout << "X^4 + 2 X^2 - 5 evalue en 2 : " << EvalPoly(p, 2.) << endl; //Doit afficher 19

	cout << "Le polynome egal de 3 et 2 de test est : ";
	PolynomeNul(r);
	polynomeCoeffEgaux(r, 3 ,2.);  
	affichePoly(r);

	cout << "Test de eval poly: ";
	PolynomeNul(s);
	polynomeCoeffEgaux(s, 4 ,1);
	polynomeCoeffEgaux(s, 3 ,0);  
	polynomeCoeffEgaux(s, 2 ,2);
	polynomeCoeffEgaux(s, 1 ,0);  
	polynomeCoeffEgaux(s, 0,-5);  
	affichePoly(s);
	cout<<" le resultat est "<<evalPoly(s, 2)<<endl;

	PolynomeNul(mille);
	polynomeCoeffEgaux(mille, 10000 , 1.0001);  
	cout<<" le resultat de mille est "<<  evalPoly(mille, 1.0001)<<endl;

	//cout<<" le resultat de mille est avec evalHornerPoly "<<  evalHornerPoly(mille, 1.0001)<<endl;
	PolynomeNul(test);
	modifierCoeffPoly(test, 3,  -2.);
	modifierCoeffPoly(test, 2, 3.);
	modifierCoeffPoly(test, 1,  -5.);
	modifierCoeffPoly(test, 0, 6.);
	cout<< "fsoifuh"<<endl;
	affichePoly(test);
	cout<<" le resultat de mille est "<<  evalHornerPoly(mille, 1.0001)<<endl;

	PolynomeNul(mitroglou);
	modifierCoeffPoly(mitroglou, 10,  1.);
	modifierCoeffPoly(mitroglou, 9,  -99.);
	affichePoly(mitroglou);
	cout<<" Normal "<<  evalPoly(mitroglou, 100)<<endl;
	cout<<"Horner  "<<  evalHornerPoly(mitroglou, 100)<<endl;

	PolynomeNul(test1);
	PolynomeNul(test2);

	modifierCoeffPoly(test1, 10,  1.);
	modifierCoeffPoly(test2, 9,  -99.);
	ajoutePoly(test1,test2);
	affichePoly(test1);
	PolynomeNul(res);

	produitPolyXn(test1, 100,res);
	affichePoly(res);

	PolynomeNul(test1);
	PolynomeNul(test2);

	modifierCoeffPoly(test1, 10,  1.);
	modifierCoeffPoly(test1, 9,  10.);

	modifierCoeffPoly(test2, 10,  1.);
	modifierCoeffPoly(test2, 9,  10.);

	affichePoly(test1);
	affichePoly(test2);

	ajoutePoly(test1,test2);
	affichePoly(test1);

	cout<<endl;
	PolynomeNul(test3);
	PolynomeNul(test4);  
	PolynomeNul(res1);


	modifierCoeffPoly(test3, 5,  4.);
	modifierCoeffPoly(test3, 2,  -5.);
	modifierCoeffPoly(test3, 1,  1.);
	modifierCoeffPoly(test3, 0,  -1.);

	modifierCoeffPoly(test4, 3,  1.);
	modifierCoeffPoly(test4, 1,  2.);
	modifierCoeffPoly(test4, 0,  -1.);
	cout<<"Poly1"<<endl;
	affichePoly(test3);
	cout<<"Poly2"<<endl;
	affichePoly(test4);
	cout<<endl;
	cout<<endl;
	produitPoly(test3, test4, res1);
	affichePoly(res1);*/

	PolynomeNul(polynomeres);
	PolynomeNul(polynome1);
	modifierCoeffPoly(polynome1, 0,  1.);
	affichePoly(polynomeres);

	affichePoly(polynome1);
	//ajoutePoly(polynomeres, polynome1);

	puissancePoly(polynome1,8, polynomeres);

	return 0;
}
