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
    /*QApplication app(argc, argv);
    Interface *interface;
    if(argc==3) interface=new Interface(string(argv[2]),string(argv[1]));
    else {
        if(argc==2) interface=new Interface("lol",string(argv[1]));
        else interface=new Interface(); //crée la fenetre
    }
    interface->show(); //affiche...    
    return app.exec();*/

    
    //TEST TEST CONVERGENCE//
   
    

    //TEST LIRESTATS//
    FILE *f[10];
    for(int i=0;i<10;i++) {
        f[i]=fopen("TestFiles/StatsTest.txt", "r");
        for(int j=0;j<i;j++){
            lireStat(f[i]);
        }
    }
    
    float *TestTab;
    for(int j=0;j<2;j++){
        for(int k=0;k<10;k++)
        {
            TestTab = lireStat(f[k]);
            for(int i = 0; i<6; i++) { cout << TestTab[i] << " ";}
            cout << endl;
            delete[] TestTab;
        }
        cout<<endl;
    }
    //~ TestTab = lireStat(f);
    //~ for(int i = 0; i<3; i++) { cout << TestTab[i] << " ";}
    //~ cout << endl;
    for(int i=0;i<10;i++) {
        fclose(f[i]);
    }
    
    //Test validation//
    
    //~ bool y = estString("e");
    //~ printf(y ? "true" : "false");
    //~ string fct = "2+x/(4+cos(2))";
    //~ bool x = estParsable(" " + fct + " ");
    //bool x = estParsable("2*x/(5+4+x)");
    //printf(x ? "true" : "false");
    //cout << endl;
    
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
    cout << "Score: " << indiv.getScore(indScore+1) << endl;
    indiv.~Individu();
    */
    /*
    Individu indiv(5);
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
    /*string donnees[10];
    //proba croisement
    //donnees[0] = "0.1"; 
    //nb Indiv & nb Generation Max
    //donnees[1] = "5"; donnees[2] = "100";
    //nb crit, crit1, crit 2
    //donnees[3] = "2"; donnees[4] = "1"; donnees[5] = "3";
    //fit1 et fit2
    //donnees[6] = "2 + x"; donnees[7] = "2/(4 + x)";
    //valApp1 et 2

    donnees[8] = "-1.0"; donnees[9] = "23.5";*/

    
    //TEST DES CONSTRUCTEURS / DESTRUCTEUR//
    //Population pop1(donnees);
    //std::cout<<"numero generation pop1 = "<<pop1.getNumeroGeneration()<<std::endl; //constructeur par donnees ok
    //pop1.evaluation();

    /* Population pop;
    std::cout<<"creation pop"<<std::endl;
    pop.setNumeroGeneration(100);
    std::cout<<pop.getNumeroGeneration()<<std::endl;
    pop.evaluation();
    std::cout<<"evaluation pop"<<std::endl;
    */ 
    //return 0;

    //Population pop2(pop1);
    //std::cout<<"numero generation pop2 = "<<pop2.getNumeroGeneration()<<std::endl; //constructeur de recopie ok
    //Population pop3;
    //std::cout<<"numero generation pop3 = "<<pop3.getNumeroGeneration()<<std::endl; //constructeur par defaut ok
    //destructeur ok, sauf avec constructeur par defaut

    //TEST DU TRI// maximisation ok || minimisation ok || valeur approchée ok
    //1:maximisation et 2:valeur approchée
    /*float donneesI[3];
    donneesI[0] = 10.0;
    donneesI[1] = 0.01;
    donneesI[2] = 2.0;
    Individu indiv1(donneesI), indiv2(donneesI), indiv3(donneesI), indiv4(donneesI), indiv5(donneesI), indiv6(donneesI), indiv7(donneesI), indiv8(donneesI), indiv9(donneesI), indiv10(donneesI);
    indiv1.setScore(5,1); indiv1.setScore(3,2);
    indiv2.setScore(8,1); indiv2.setScore(6,2);
    indiv3.setScore(39,1); indiv3.setScore(24,2);
    indiv4.setScore(24,1); indiv4.setScore(39,2);
    indiv5.setScore(52,1); indiv5.setScore(42,2);
    indiv6.setScore(24,1); indiv6.setScore(65,2);
    indiv7.setScore(44,1); indiv7.setScore(85,2);
    indiv8.setScore(27,1); indiv8.setScore(55,2);
    indiv9.setScore(42,1); indiv9.setScore(83,2);
    indiv10.setScore(68,1); indiv10.setScore(25,2);
    std::cout<<"creation de 10 individu et initialisation de leurs scores"<<std::endl;

    pop3.setEnsemble(indiv1);pop3.setEnsemble(indiv2);
    pop3.setEnsemble(indiv3);pop3.setEnsemble(indiv4);
    pop3.setEnsemble(indiv5);pop3.setEnsemble(indiv6);
    pop3.setEnsemble(indiv7); pop3.setEnsemble(indiv8);
    pop3.setEnsemble(indiv9); pop3.setEnsemble(indiv10);
    std::cout<<"ajout des individus dans pop3.ensemble"<<std::endl;

    pop3.triPopulation(1);
    //pop3.evaluation();
    vector<Individu*> p_ensemble = pop3.getEnsemble();

    std::cout<<"resultat evaluation:"<<std::endl;
    for(int i = 0; i < p_ensemble.size(); i++){
        std::cout<<p_ensemble[i]->getScore(1)<<std::endl;
    }
    

    return 0;*/

/*
    ////TEST SELECTION
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
    pop1.evaluation();
    Individu ind = pop1.selectionner(1);
    
    ind.theIndividu();

    return 0;
*/



}
