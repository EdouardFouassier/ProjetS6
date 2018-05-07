#include "../Headers/interface.h"
#include "../Headers/initialisation_population.h"
#include <unistd.h>
#include "../Headers/entree_sortie.h"
#include "../Headers/génération.h"
#include <time.h>

using namespace std;


int main(/*int argc, char *argv[]*/)
{

       srand(time(NULL));
    string donnees[10];
    //proba croisement
    donnees[0] = "0.1"; 
    //nb Indiv & nb Generation Max
    donnees[1] = "5"; donnees[2] = "100";
    //nb crit, crit1, crit 2
    donnees[3] = "2"; donnees[4] = "1"; donnees[5] = "3";
    //fit1 et fit2
    donnees[6] = "2 + x"; donnees[7] = "2/(4 + x)";
    //valApp1 et 2

    donnees[8] = "-1.0"; donnees[9] = "23.5";

    
    //TEST DES CONSTRUCTEURS / DESTRUCTEUR//
    Population pop1(donnees);

    float donneesI[3];
    donneesI[0] = 10.0;
    donneesI[1] = 0.01;
    donneesI[2] = 2.0;
    Individu init(donneesI);
    Individu i1(10), i2(10);
    pop1 = pop1.crossover(i1,i2);
    cout<<"crossover réussi"<<endl;

    return 0;


}
