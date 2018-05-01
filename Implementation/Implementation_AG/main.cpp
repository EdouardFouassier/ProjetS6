#include "interface.h"
#include "initialisation_population.h"
#include <unistd.h>
#include "entree_sortie.h"
#include "génération.h"

using namespace std;


int main(int argc, char *argv[])
{
    /*QApplication app(argc, argv);

    Interface interface; //crée la fenetre
    interface.show(); //affiche...
    
    return app.exec();*/
    
    //Test validation//
    
    //~ bool y = estString("e");
    //~ printf(y ? "true" : "false");
    //~ string fct = "2+x/(4+cos(2))";
    //~ bool x = estParsable(" " + fct + " ");
    //~ bool x = estParsable("2*x/(5+4+x)");
    //~ printf(x ? "true" : "false");
    //~ cout << endl;
    
    //~ bool x = testCoherenceDonnees("DonneesInitiales.txt");
    //~ printf(x ? "true" : "false");
    //~ cout << endl;
    
    //Test validation//

/////// Test Individu ///////
    /*float donnees[3];
    donnees[0] = 4.0;
    donnees[1] = 0.01;
    donnees[2] = 1.0;
    Individu indiv(donnees);
    string fonction = "x*x";
    int indScore = 0;
    indiv.evaluationIndividu(fonction, indScore);
    cout << "Score: " << indiv.getScore(indScore) << endl;
    indiv.~Individu(); */
    /* Individu indiv(5);
    for(int i = 0; i < 6; i++){
        cout << "Chromosome i " << indiv.getChromosome()[i] << endl;
    }
    int a = indiv.decodage(indiv.getChromosome());
    cout << a << endl;

    cout << endl;
    indiv = indiv.codage(-5);
    for(int i = 0; i < 6; i++){
        cout << "Chromosome i " << indiv.getChromosome()[i] << endl;
    }
    int b = indiv.decodage(indiv.getChromosome());
    cout << b << endl;
    indiv.~Individu(); 
    */
/////////////////////////////



    /////////////////////////////
    
    /**TEST DE DU MODULE GENERATION */
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
    std::cout<<"numero generation pop1 = "<<pop1.getNumeroGeneration()<<std::endl; //constructeur par donnees ok



    /* Population pop;
    std::cout<<"creation pop"<<std::endl;
    pop.setNumeroGeneration(100);
    std::cout<<pop.getNumeroGeneration()<<std::endl;
    pop.evaluation();
    std::cout<<"evaluation pop"<<std::endl;
    */ 
    //return 0;
}
