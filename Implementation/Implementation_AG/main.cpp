#include "interface.h"
#include "initialisation_population.h"
#include <unistd.h>
#include "entree_sortie.h"
#include "génération.h"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Interface interface; //crée la fenetre
    interface.show(); //affiche...
    
    return app.exec();
    
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
    /* float donnees[3];
    donnees[0] = 4.0;
    donnees[1] = 0.01;
    donnees[2] = 1.0;
    Individu indiv(donnees);
    string fonction = "x*x";
    int indScore = 0;
    indiv.evaluationIndividu(fonction, indScore);
    cout << "Score: " << indiv.getScore(indScore) << endl;
    indiv.~Individu(); */




    /////////////////////////////
    
    /**TEST DE DU MODULE GENERATION */
    /*
    Population pop;
    std::cout<<"creation pop"<<std::endl;
    pop.setNumeroGeneration(100);
    std::cout<<pop.getNumeroGeneration()<<std::endl;
    pop.evaluation();
    std::cout<<"evaluation pop"<<std::endl;*/

    //return 0;
}
