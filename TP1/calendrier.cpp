#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

vector<string> nom_mois = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet",
"Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
vector<string> nom_jours = {"lu", "ma", "me", "je", "ve", "sa", "di"};
vector<int> long_mois = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void afficheCalendrier(int mois) {
    cout << nom_mois[mois - 1] << endl << " ";
    for (int i = 0; i < 7; i++) {
        cout << nom_jours[i] << " ";
    }
    cout << endl << setw(3);
    for (int i = 1; i <= long_mois[mois-1]; i++) {
        cout << i << setw(3);
        if (i % 7 == 0) 
            cout << endl;
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 12; i++) {
        afficheCalendrier(i);
        cout << endl;
    }
    return 0;
}
