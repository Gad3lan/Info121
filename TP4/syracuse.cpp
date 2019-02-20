#include <iostream>
#include <iomanip>
using namespace std;

void syracuse(int &a) {
	if (a%2 == 0)
		a /= 2;
	else 
		a = 3*a + 1;
}

int longueurTransient (int un){
	int i=0;
	while (un != 1) {
		syracuse(un);
		i++;
	}
	return i;
}

void testLongueurTransient() {
	for (int i = 1; i <= 1000; i++) {
		cout << i << ": " <<  longueurTransient(i) << ";  ";
	}
	cout << endl;
}

int main() {
	testLongueurTransient();
	return 0;
}
