#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    vector<int> notes = {3, 1, 3, 1, 2, 2, 5, 5, 5, 2, 3, 2, 2, 1, 1, 1, 2,
0, 5, 2, 4, 3, 5, 5, 1, 5, 2, 5, 1, 0, 2, 2, 1, 5};
    vector<int> nbNotes(6);
    for (unsigned int i = 0; i < notes.size(); i++)
        nbNotes[notes[i]]++;
    for (int i = 0; i < 6; i ++) {
        cout << i;
        if (i < 5)
            cout << setw(3);
    }
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << nbNotes[i];
        if (i < 5)
            cout << setw(3);
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << i << " : ";
        for (int j = 0; j < nbNotes[i]; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
