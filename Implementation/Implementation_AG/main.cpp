#include "interface.h"
#include "initialisation_population.h"
#include <unistd.h>
#include "entree_sortie.h"


int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);

    //~ Interface interface; //crée la fenetre
    //~ interface.show(); //affiche...
    
    
    int i = 1;
    bool x = estEntierPositif(i);
    printf(x ? "true\n" : "false\n");
   // return app.exec();
    return 0;
}
