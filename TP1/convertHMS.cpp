#include <iostream>
#include <vector>

using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
				       << " line " << __LINE__ << ": " #test << endl


/** Converti une durée en Heure, Minute, Seconde en seconde
 *  @param hms un tableau d'entier 
 *  @return un entier corrorespondant à la conversion de hms en secondes
 **/
int convertHMS2S(vector<int> hms) {
    return (hms[0] * 3600 + hms[1] * 60 + hms[2]);
}

void testConvertHMS2S() {
    ASSERT( convertHMS2S({10,10,2}) == 36602 );
    ASSERT( convertHMS2S({23,59,59}) == 86399);
    ASSERT( convertHMS2S({0,0,0}) == 0);
    ASSERT( convertHMS2S({23,59,60}) == 86400);
    ASSERT( convertHMS2S({23,60,0}) == 86400);
    ASSERT( convertHMS2S({24,0,0}) == 86400);
}

/** À compléter
 *  @param un entier d
 *  @return un tableau d'entier correspondant à la conversion des secondes en heure, minutes et secondes
 **/
vector<int> convertS2HMS(int d) {
    vector<int> hms(3);
    while(d > 0) {
        if (d >= 3600) {
            d -= 3600;
            hms[0]++;
        } else if (d >= 60) {
            d -= 60;
            hms[1]++;
        } else {
            d -= 1;
            hms[2]++;
        }
    }
    return hms;
}

void testConvertS2HMS() {
    ASSERT( convertS2HMS(36602) == vector<int>({10,10,2}) );
    ASSERT( convertS2HMS(86399) == vector<int>({23,59,59}));
    ASSERT( convertS2HMS(0) == vector<int>({0,0,0}));
    ASSERT( convertS2HMS(86400) == vector<int>({24,0,0}));
    ASSERT( convertS2HMS(61) == vector<int>({0,1,1}));
}


void testHMS(vector<int> hms) {
    ASSERT( hms.size() == 3);
    ASSERT( hms[0] < 24 && hms[0] >= 0 );
    ASSERT( hms[1] < 60 && hms[1] >= 0 );
    ASSERT( hms[2] < 60 && hms[2] >= 0 );
}

int main() {
    testConvertHMS2S();
    testConvertS2HMS();

    for (int i = 0; i <= 80000; i++) {
        testHMS(convertS2HMS(i));
    }
    return 0;
}
