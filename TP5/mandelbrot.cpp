#include <iostream>
#include <cmath>

using namespace std;

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

struct Complexe {
    float re, im;
};


Complexe creeComplexe(float reel, float imaginaire){
    Complexe c;
    c.re = reel;
    c.im = imaginaire;
    return c;
}

bool egaleComplexe(Complexe c1, Complexe c2){
    return (c1.re==c2.re)&&(c1.im==c2.im);
}

Complexe ajouterComplexe(Complexe c1, Complexe c2){
    Complexe resultat;
    resultat.re = c1.re + c2.re;
    resultat.im = c1.im + c2.im;
    return resultat;
}

Complexe multiplierComplexe(Complexe c1, Complexe c2){
	return {(c1.re*c2.re) - (c1.im*c2.im), (c1.re*c2.im) + (c1.im*c2.re)};
}

void testMultiplierComplexe() {
	ASSERT(egaleComplexe(multiplierComplexe({4, 2}, {4, -2}), {20, 0}));
	ASSERT(egaleComplexe(multiplierComplexe({0, 0}, {0, 0}), {0, 0}));
	ASSERT(egaleComplexe(multiplierComplexe({1, 2}, {0, 0}), {0, 0}));
}

float moduleComplexe(Complexe c){
    return sqrt(pow(c.re, 2) + pow(c.im, 2));
}

void testModuleComplexe() {
	ASSERT(moduleComplexe({0, 0}) == 0);
	ASSERT(moduleComplexe({2, 0}) == 2);
	ASSERT(moduleComplexe({0, 4}) == 4);
}

bool znResteBorne(Complexe c){
	Complexe z = creeComplexe(0, 0);
    for (int i = 0; i < 1000; i++) {
    	z = ajouterComplexe(multiplierComplexe(z, z), c);
    	if (moduleComplexe(z) > 1000) 
    		return false;
    }
    return true;
}

void mandelbrot(){
    const float xmin = -2;
    const float xmax = 0;
    const float ymin = -1;
    const float ymax = 1;
    const int resol = 79;
    for(int i=0; i<=resol; i++) {
        for(int j=0; j<=resol; j++) {
            if(znResteBorne(creeComplexe((resol-j)*xmin/resol+j*xmax/resol,
                                         (resol-i)*ymax/resol+i*ymin/resol))) {
                    cout << '#';
            }
            else {
                    cout << ' ';
            }
        }
        cout << endl;
    }
}

int main(){
	mandelbrot();
    return 0;
}
