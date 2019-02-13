#include <iostream>
#include <string.h>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
				       << " line " << __LINE__ << ": " #test << endl


/** La forme d'un individu
 *  @param repos  nbr de battement cardiaque à la minute au repos
 *  @param effort nbr de battement cardiaque à la minute après l'effort
 *  @param recup  nbr de battement cardiaque à la minute après une minute de récupération
 *  @return une chaîne de caractère décrivant la forme
 **/
string forme(int repos, int effort, int recup) {
	float res = 0.1 * (repos + effort + recup - 200);
	if (res <= 0) 
	    return "excellente";
	else if (res < 5)
	    return "tres bonne";
	else if (res < 10)
	    return "bonne";
	else if (res < 15) 
	    return "moyenne";
	else
	    return "faible";
}


void formeTest(void) {
  ASSERT( forme(60,80,60) == "excellente" );
  ASSERT( forme(70,90,80) == "tres bonne" );
  ASSERT( forme(80,120,80) == "bonne" );
  ASSERT( forme(80,150,100) == "moyenne" );
  ASSERT( forme(90,150,130) == "faible" );
}

int main() {
    int repos, effort, recup;
    formeTest();
    cout << "Rythme cardiaque au repos : ";
    cin >> repos;
    cout << "Rythme cardiaque juste après effort : ";
    cin >> effort;
    cout << "Rythme cardiaque pendant la récupération : ";
    cin >> recup;
    cout << endl << "Votre forme est " << forme(repos, effort, recup) << endl;
    return 0;
}
