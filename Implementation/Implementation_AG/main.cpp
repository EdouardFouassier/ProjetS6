#include "interface.h"
#include "initialisation_population.h"
#include <unistd.h>
#include "entree_sortie.h"
#include "génération.h"

using namespace std;


int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);

    //Interface interface; //crée la fenetre
    //interface.show(); //affiche...
    
    
    //Test validation//
    
    //~ bool y = estString("e");
    //~ printf(y ? "true" : "false");
    /* bool x = estParsable("((2+x/)4))");
    printf(x ? "true" : "false");
    cout << endl; */
    
    //Test validation//

    /////// Test Individu ///////
    float donnees[3];
    donnees[0] = 5.0;
    donnees[1] = 0.01;
    donnees[2] = 1.0;
    Individu indiv(donnees);
    cout << indiv.getTailleIndividu() << endl;
    // cout << indiv.getProbaMutation() << endl;
    cout << indiv.getChromosome() << endl;




    /////////////////////////////
    
    /**TEST DE DU MODULE GENERATION */
    /*
    Population pop;
    std::cout<<"creation pop"<<std::endl;
    pop.setNumeroGeneration(100);
    std::cout<<pop.getNumeroGeneration()<<std::endl;
    pop.evaluation();
    std::cout<<"evaluation pop"<<std::endl;*/

    //return app.exec();
    return 0;
}
