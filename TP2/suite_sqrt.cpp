#include <iostream>
#include <iomanip>

using namespace std;

float abs(float x) {
    if (x < 0) 
        x *= -1;
    return x;
}

int main() {
    const float EPSILON = 1e-6;
  int n;
  float a=2., un, un1; // u_n et u_{n+1}
  do {
    cin >> a;
  } while(a <= 0);

  n = 0;  un = a;
  while (abs((un*un)/a - 1)>=EPSILON) {
    un1 = (un + a/un)/2.;       // calcul de u_{n+1}
    n = n+1; un = un1;          // passage de n à n+1
    cout << "n=" << n << ", un=" << setprecision(10) << un << ", un^2=" << un*un << endl;
  }
  return 0;
}
