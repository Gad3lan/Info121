#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int N;
    bool permutation = true;
    cout << "Entrer le nombre l'elements de la suite : ";
    cin >> N;
    vector<int> liste(N);
    vector<int> listeOcc(N);
    for (int i = 0; i < N; i++) {
        cin >> liste[i];
        listeOcc[liste[i]]++;
    }
    for (int i = 0; i < N; i++) {
        if (listeOcc[i] != 1) {
            permutation = false;
            break;
        }
    }
    if (permutation) 
        cout << "La suite est une permutation" << endl;
    else {
        cout << "La suite n'est pas une permutation, voici le tableau des occurences : " << endl;
        for (int i = 0; i < N; i++) {
            cout << i;
            if (i < N-1) 
                cout << setw(4);
        }
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout << listeOcc[i];
            if (i < N-1) 
                cout << setw(4);
        }
        cout << endl;
    }
    return 0;
}
