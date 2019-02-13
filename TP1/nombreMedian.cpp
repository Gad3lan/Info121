#include <iostream>
#include <vector>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
				       << " line " << __LINE__ << ": " #test << endl

void tri(vector<int> &v) {
    int tmp;
    for (unsigned int i = 1; i < v.size(); i++) {
        for (unsigned int j = 0; j < v.size()-i; j++) {
            if (v[j] > v[j+1]) {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

int nombreMedian(int a, int b, int c) {
    vector<int> nbs = {a, b, c};
    tri(nbs);
    return nbs[1];
}

void testNombreMedian() {
    ASSERT( nombreMedian(0,0,0) == 0 );
    ASSERT( nombreMedian(1,2,3) == 2);
    ASSERT( nombreMedian(5,2,6) == 5);
    ASSERT( nombreMedian(2,6,5) == 5);
}

int main() {
    testNombreMedian();
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Nombre médian : " << nombreMedian(a, b, c) << endl;
    return 0;
}
