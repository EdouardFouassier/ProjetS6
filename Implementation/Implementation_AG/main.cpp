#include "interface.h"
#include "initialisation_population.h"
#include <unistd.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Interface interface; //crée la fenetre
    interface.show(); //affiche...
    return app.exec();
}
