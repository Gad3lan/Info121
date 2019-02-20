#include <iostream>

using namesapce std;

void permuter(int &c, int &d) {
	int temp;
	temp=c; c=d; d=temp;
}

void ordonner(int &a, int &b) {
	if (a > b)
		permuter(a, b);
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	ordonner(b, c);
	ordonner(a, c);
	ordonner(a, b);
	cout << a << ", " << b << ", " << c << endl;
	return 0;
}
