#include <iostream>

using namespace std;

int pgcd(int a, int b) {
    int r = a % b;
    while(r > 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "PGCD de " << a << " et " << b << " : " << pgcd(a, b) << endl;
    return 0;
}
