#include "interface.h"
#include "initialisation_population.h"
#include <unistd.h>
#include "entree_sortie.h"
#include "génération.h"


int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);

    //Interface interface; //crée la fenetre
    //interface.show(); //affiche...
    
    
    //Test validation//
    
    //~ bool y = estString(2);
    //~ printf(y ? "true" : "false");
    bool x = estParsable("((2+x/)4))");
    printf(x ? "true" : "false");
    
    //Test validation//
    
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
