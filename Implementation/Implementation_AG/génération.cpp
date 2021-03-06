//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              génération.cpp                ///
//////////////////////////////////////////////////
#include "génération.h"


/**** STATIC ****/

float Population::probaCroisement = -1.0;
int Population::nombreIndividus = -1;
int Population::nombreGenerationMax = -1;
int Population::nombreCriteres = -1;
int* Population::criteres = nullptr;
string Population::fitness1 = "";
string Population::fitness2 = "";
float Population::valeurApprochee = -1.0;
float Population::valeurApprochee2 = -1.0; ///pas dans le cds///

int Population::numeroGeneration = 0;

/**** CONSTRUCTEURS****/

Population::Population() : ensemble(0) //test OK
{
	numeroGeneration += 1;
	//std::cout<<"CREATION SUCCESS"<<endl;
}

Population::Population(Population const& P) : ensemble(P.ensemble) //test OK
{
	numeroGeneration += 1;
	//std::cout<<"CREATION SUCCESS"<<endl;
	
}

Population::Population(string* const& donnees) :  ensemble(0) //test OK
{

	/*std::cout<<"Donnees recues par le constructeur :"<<std::endl;
    std::cout<<"proba croisement = "<<std::stof(donnees[0],nullptr)<< std::endl;
    std::cout<<"taille population = "<<std::stoi(donnees[1], nullptr, 10)<<"  nombre de Generation Max = " <<std::stoi(donnees[2], nullptr, 10)<<std::endl;
    std::cout<<"nombre de critères = "<<std::stoi(donnees[3], nullptr, 10)<<" critère 1 = "<<std::stoi(donnees[4], nullptr, 10)<<"  critère 2 = "<<std::stoi(donnees[5], nullptr, 10)<<std::endl;
    std::cout<<"fitness1 = "<<donnees[6]<<" fitness2 = "<<donnees[7]<<std::endl;
    std::cout<<"valeurApprochee1 = "<<std::stof(donnees[8], nullptr)<<" valeurApprochee2 = "<<std::stof(donnees[9], nullptr)<<std::endl;*/

	/** INITIALISATION DES DONNEES INVARIABLES **/
	probaCroisement = std::stof(donnees[0],nullptr); // string to float
	nombreIndividus = std::stoi(donnees[1], nullptr, 10);
	nombreGenerationMax = std::stoi(donnees[2], nullptr, 10);	
	nombreCriteres = std::stoi(donnees[3], nullptr, 10);

	/** INITIALISATION DES DONNEES VARIABLES **/
	if(nombreCriteres == 1 || nombreCriteres == 2){
		if(nombreCriteres == 1){ 							 //si on à un seul critere
			criteres = (int*)malloc(nombreCriteres*sizeof(int)); //initialisation de la taille du tableau de criteres
			criteres[0] = std::stoi(donnees[4], nullptr, 10);    //initialisation du critere
			fitness1 = donnees[6];                               //initialisation de la fonction fitness

			if (criteres[0] == 3)								 //si le critere est la recherche d'une valeur approchée
				valeurApprochee = std::stof(donnees[8], nullptr);//initialisation de la valeur approchée

		}
		else {
			criteres = (int*)malloc(nombreCriteres*sizeof(int)); //initialisation de la taille du tableau de criteres
			criteres[0] = std::stoi(donnees[4], nullptr, 10);    //initialisation du critere 1
			criteres[1] = std::stoi(donnees[5], nullptr, 10);    //initialisation du critere 2
			fitness1 = donnees[6];                               //initialisation de la fonction fitness 1
			fitness2 = donnees[7];                               //initialisation de la fonction fitness 2
	
			if (criteres[0] == 3)								 //si le critere 1 est la recherche d'une valeur approchée
				valeurApprochee = std::stof(donnees[8], nullptr);//initialisation de la valeur approchée 1
			if (criteres[1] == 3)								 //si le critere  2est la recherche d'une valeur approchée
				valeurApprochee2 = std::stof(donnees[9], nullptr);//initialisation de la valeur approchée 2
		}
		numeroGeneration += 1;
	}
	else std::cerr<<"nombre de critères non conforme"<<std::endl;

	/*POPULATION INITIALE*/
	/*float idonnees[3];
    idonnees[0] = 4.0;
    idonnees[1] = 0.01;
    idonnees[2] = 1.0;*/
	for(int i = 0; i < nombreIndividus; i++){
		Individu *nouv = new Individu(lireInitialisation(donnees[10]));
		ensemble.push_back(nouv);
	}
	//std::cout<<"CREATION SUCCESS"<<endl;
}


/**** DESTRUCTEUR ****/

Population::~Population() //a revoir
{
	int size = ensemble.size();
	for(int i = 0; i < size; i++){
		ensemble.pop_back();
	}
}

/**** GETTEURS ****/

int Population::getNombreIndividus(){
	return this->nombreIndividus;
}

int Population::getNumeroGeneration(){
	return this->numeroGeneration;
}

string Population::getFitness1(){
	return this->fitness1;
}

string Population::getFitness2(){
	return this->fitness2;
}

float Population::getValeurApprochee(){
	return this->valeurApprochee;
}

float Population::getValeurApprochee2(){
	return this->valeurApprochee2;
}

vector<Individu*> Population::getEnsemble(){
	return this->ensemble;
}

int Population::getNombreGenerationMax(){		//fonction qu'on a oubliée dans le cds :(
	return this->nombreGenerationMax;
}

/// UTILE DANS ecrirePopulation POUR RECUPERER LE NOMBRE DE CRITERES

int Population::getNombreCriteres(){			//fonction qu'on a oubliée dans le cds :(
	return this->nombreCriteres;
}

/// PAS DANS LE CDS (mais inutiles pour l'instant donc maybe on est bon quand même)

/*
int[] Population::getCriteres(){				//fonction qu'on a oubliée dans le cds :(
	return this->criteres;
}

float Population::getProbaCroisement(){			//fonction qu'on a oubliée dans le cds :(
	return this->probaCroisement;
}*/

/**** SETTEURS ****/

void Population::setNombreIndividus(int nbIndiv){
	this->nombreIndividus = nbIndiv;
}

void Population::setNumeroGeneration(int num){
	this->numeroGeneration = num;
}

void Population::setFitness1(string fit1){
	this->fitness1 = fit1;
}

void Population::setFitness2(string fit2){
	this->fitness2 = fit2;
}

void Population::setValeurApprochee(float val){
	this->valeurApprochee = val;
}

void Population::setValeurApprochee2(float val){
	this->valeurApprochee2 = val;
}

void Population::setProbaCroisement(float proba){
	this->probaCroisement = proba;
}

void Population::setNombreGenerationMax(int nb){
	this->nombreGenerationMax = nb;
}

void Population::setEnsemble(Individu &nouv){
	this->ensemble.push_back(&nouv);
}



/**** TESTS ****/

Population Population::testArret() //pourquoi ça doit renvoyer un population? || a finir
{  
	if(this->testConvergence() && this->testNombreGeneration()){
		//calculerEcrireStats(this*, string nomFichierPopulation, string nomFichierStats)
		//d'apres cds : on continue l'itération
							//on envoie la population au module io
	}
	else {
		//on envoie juste la pop à l'io
	}

	return *this;
}

bool Population::testConvergence() //a implementer
{
	
	FILE *f;
    f = fopen("TestFiles/StatsTest.txt", "r");
    float *TestTab;
    int i = 0;
    TestTab = lireStat(f);
   	int temp = TestTab[0];
   	TestTab = lireStat(f);
   	for (i = 0; i < 4; i++) {
		if((temp <= (TestTab[0] + 0.015*TestTab[0])) && (temp >= (TestTab[0] - 0.015*TestTab[0])))
		{
			temp = TestTab[0];
			TestTab = lireStat(f);
		}
		else { return false; }
	}


    delete[] TestTab;
    fclose(f);
	return true;
}

bool Population::testNombreGeneration()
{
	if (numeroGeneration < nombreGenerationMax)
		return true;
	return false;
}

bool Population::testPopulationRemplie(){
	if(ensemble.size() < nombreIndividus)
		return true;
	return false;
}
/**** LES ALGOS ****/

Population Population::evaluation() //test ok
{
	std::cout<<"EVALUATION"<<std::endl;
	string fitnessTmp;
	if (nombreCriteres == -1)
		std::cerr<<"nombre de critères non conforme"<<std::endl;
	else {		
		for (int iCritere = 0; iCritere < nombreCriteres; iCritere ++){
			//std::cout<<"criteres : "<<iCritere<<" / "<<nombreCriteres<<std::endl;
			for (int iIndiv = 0; iIndiv < ensemble.size(); iIndiv ++){
				if(iCritere == 0)
					fitnessTmp = this->fitness1;
				if(iCritere == 1)
					fitnessTmp = this->fitness2;
				ensemble[iIndiv]->Individu::evaluationIndividu(fitnessTmp, iCritere);
			}
			std::cout<<"icritere : "<<iCritere<<std::endl;
			std::cout<<"critere : "<<criteres[iCritere]<<std::endl;
			this->Population::triPopulation(iCritere);
			int cpt = 1;
			int ensembleSize = ensemble.size() - 1;
			float iScore1, iScore2;
			for(int iIndiv = 0; iIndiv < ensembleSize; iIndiv ++){
				iScore1 = ensemble[iIndiv]->Individu::getScore(iCritere);
				iScore2 = ensemble[iIndiv+1]->Individu::getScore(iCritere); 
				if(iScore1 == iScore2){
					ensemble[iIndiv]->Individu::setRang(cpt, iCritere);
					
				}
				else {
					ensemble[iIndiv]->Individu::setRang(cpt, iCritere);
					cpt ++;
				}
			}
			iScore1 = ensemble[ensembleSize]->Individu::getScore(iCritere);
			iScore2 = ensemble[ensembleSize-1]->Individu::getScore(iCritere);
			cpt = ensemble[ensembleSize-1]->Individu::getRang(iCritere);
			if (iScore1 == iScore2){
				ensemble[ensembleSize]->Individu::setRang(cpt, iCritere);
			}
			else { 
				cpt ++;
				this->ensemble[ensembleSize]->Individu::setRang(cpt, iCritere);
			}
			//for(int i = 0; i < ensembleSize; i++)
        	//	std::cout<<"rang pour critere "<<iCritere<< " : "<<ensemble[i]->getRang(iCritere)<<std::endl;
        	for (int i = 0; i < ensemble.size(); i ++)
    			std::cout<<"critere : "<<iCritere<< " "<<ensemble[i]->getScore(iCritere)<<std::endl;
		}
	}
	return *this;

}

void Population::maximisation(int indiceScore) //test OK, pas dans cds (ameliorable)
{
	std::cout<<"MAXIMISATION"<<std::endl;
	int taille = ensemble.size();
	bool tab_en_ordre = false;
    while(!tab_en_ordre)
	{	
		tab_en_ordre = true;
        	for(int i=0 ; i < taille-1 ; i++)
        	{
           		if(ensemble[i]->Individu::getScore(indiceScore) < ensemble[i+1]->Individu::getScore(indiceScore))
            		{
                		swap(ensemble[i],ensemble[i+1]);
                		tab_en_ordre = false;
            		}
        	}
        taille--;
    }
}

void Population::minimisation (int indiceScore)//test OK, pas dans cds (ameliorable)
{
	std::cout<<"MINISATION"<<std::endl;
	int taille = ensemble.size();
	bool tab_en_ordre = false;
    while(!tab_en_ordre)
	{	
		tab_en_ordre = true;
        	for(int i=0 ; i < taille-1 ; i++)
        	{
           		if(ensemble[i]->Individu::getScore(indiceScore) > ensemble[i+1]->Individu::getScore(indiceScore))
            		{
                		swap(ensemble[i],ensemble[i+1]);
                		tab_en_ordre = false;
            		}
        	}
        taille--;
    }
}

void Population::triValeur (int indiceScore)//test OK, pas dans cds (ameliorable)
{
	std::cout<<"VALEUR APPROCHEE"<<std::endl;
	float val;
	bool tab_en_ordre = false;
	if (indiceScore == 1)
		val = valeurApprochee;
	else if (indiceScore == 2)
		val = valeurApprochee2;
	else 
		std::cerr<<"error triPopulation" <<std::endl;

	int taille = ensemble.size();
	int difference;	

    for(int i=0 ; i < taille ; i++)
    {	
        if(val < ensemble[i]->Individu::getScore(indiceScore) ){
            difference = ensemble[i]->Individu::getScore(indiceScore) - val;
        }
        else{ 
            difference = val - ensemble[i]->Individu::getScore(indiceScore);
        }
        ensemble[i]->Individu::setRang(difference, indiceScore);
        //std::cout<<ensemble[i]->Individu::getRang(indiceScore)<<" pour "<<ensemble[i]->Individu::getScore(indiceScore)<<std::endl;
    }

    while(!tab_en_ordre)
	{	
		tab_en_ordre = true;
        for(int i=0 ; i < taille-1 ; i++)
        {
            if(ensemble[i]->Individu::getRang(indiceScore) > ensemble[i+1]->Individu::getRang(indiceScore))
            {
            	swap(ensemble[i],ensemble[i+1]);
               	tab_en_ordre = false;
            }
        }
      	taille--;
    }
}

void Population::triPopulation(int indiceScore) //test OK, signature modifiée / cds
{ 	
	/**A DECOMMENTER POUR TEST **/
	/*std::cout<<"TRI"<<std::endl;
	std::cout<<"indiceScore : "<<indiceScore<<std::endl;
	criteres = (int*)malloc(1*sizeof(int));
	criteres[indiceScore]=3;
	std::cout<<"critere de tri : "<<criteres[indiceScore]<<std::endl;
	~~~~~~~~~~~~~~FIN DU TEST **/
	if (criteres[indiceScore] == 1) //MAXIMISATION
	{
		Population::maximisation(indiceScore);
	}
	else if (criteres[indiceScore] == 2) //MINIMISATION
	{
		
		Population::minimisation(indiceScore);
	}
	else if (criteres[indiceScore] == 3) //VALEUR APPROCHEE
	{
		Population::triValeur(indiceScore);
	}
	else 
		std::cerr<<"error triPopulation" <<std::endl;
	//for (int i = 0; i < ensemble.size(); i ++)
    	//std::cout<<ensemble[i]->getScore(indiceScore)<<std::endl;
}

Individu Population::selectionner(int iCritere) //à implémenter , modifié / cds
{	
	int taillePop = ensemble.size();
	int rang;
	int cpt = 0;
	int rangMax = 0;

	for (int i = 0; i < taillePop; i ++){
		if (ensemble[i]->getRang(iCritere-1) > rangMax)
			rangMax = ensemble[i]->getRang(iCritere-1);
	}

	int tauxApparition[rangMax];

	for(int i = 0; i < taillePop - 1; i++){
		if (ensemble[i]->getRang(iCritere-1) == ensemble[i+1]->getRang(iCritere-1))
			cpt ++;
		else 
			cpt = 0;
		rang = ensemble[i]->getRang(iCritere-1);
		tauxApparition[rang] = (cpt + 1)/taillePop;
	}
	if (ensemble[taillePop-1]->getRang(iCritere-1) == ensemble[taillePop-2]->getRang(iCritere-1)){
		rang = ensemble[taillePop-1]->getRang(iCritere-1);
		tauxApparition[rang] = cpt/taillePop;
	}
	else {
		rang = ensemble[taillePop-1]->getRang(iCritere-1);
		tauxApparition[rang] = 1/taillePop;
	}

	int alea = nombreAlea(1, rangMax);
	
	int rang2 = tauxApparition[alea];
	for(int i = 0; i < taillePop; i++){
		if (ensemble[i]->getRang(iCritere-1) == rang2 && ensemble[i]->getRang(iCritere-1) != rang2 )
			return *ensemble[i];
	}

}

//à tester quand toutes les fonctions seront dispos
Population Population::crossover(Individu parent1, Individu parent2){
	/*
	Individu enfant1, enfant2;
	if(probAlea(this->probaCroisement)){
		int ptcrois = nombreAlea(1,this->nombreIndividus);
		
		for(int i = 0; i < ptcrois ;i++){
			enfant1->ensemble[i] = mutation(parent1[i]);
			enfant2->ensemble[i] = mutation(parent2[i]);
		}
		for(i = ptcrois + 1; i < enfant1->tailleIndividu){
			enfant1->ensemble[i] = mutation(parent2[i]);
			enfant2->ensemble[i] = mutation(parent1[i]);
		}
	}
	else{
		enfant1 = parent1;
		enfant2 = parent2;
	}
	if(testPopulationRemplie() ){		//il faudrait quand même vérifier qu'il y a la place pour deux nouveaux individus
		ensemble.push_back(enfant1);
		ensemble.push_back(enfant2);
	}
	*/
	return *this;
}

//à tester quand toutes les fonctions seront dispos
Population Population::creerGeneration(Population P){
	/*
	Population new;
	while(new->testPopulationRemplie){
		new = crossover(P->selectionner(),P->selectionner());		//la population avec deux nouveaux individus
	}
	ecrirePopulation(P, "");		//c'est potentiellement testArret qui fait ça
	P->~Population();
	return new;
	*/
	return *this;
}

/*bool Individu::probAlea(float prob) //pas dans Population
{
	double alea = rand()/(double)RAND_MAX; 	//génere un nb dans [0,1]
	
	if(alea < prob) return true;
	return false;
}*/

int Population::nombreAlea(int inf, int sup) // test OK ? 
{
	//inf++;	//parce qu'on ne veut pas que inf soit inclu
	return rand()%(sup-inf) + sup;
}





/** SELECTION **/
//ce que j'ai ecris

	//int limite = 0;
	//int scoreMax = 0;
	//int nbIndivSelect = 0;
	//int taillePop = ensemble.size();
	//int pourcentage[taillePop];
	//int rangMin = 100;
	/*if (taillePop % 2 == 0) {
		limite = taillePop / 2;
	}
	else {
		limite = (ensemble.size() -1) / 2;
	}
	
	for (i = 0; i < taillePop; i++) {
		scoreMax += ensemble[i]->getR(iCritere-1);
	}*/
	
	
	/*for (int i = 0; i < taillePop; i ++){
		if (ensemble[i]->getRang(iCritere-1) < rangMin)
			rangMin = ensemble[i]->getRang(iCritere-1);
	}
	
//pour le multicritère : choisir limite/2 en fonction du premier score, et le limite/2 en fonction du second
//What ? je vois pas ce que ca fait ca 

	int alea = nombreAlea(rangMin, taillePop);	
	if(ensemble[0]->getRang(iCritere - 1) > alea)
		return *ensemble[0];
	for (int i = 1; i < taillePop; i ++){
		alea = nombreAlea(rangMin, taillePop);	
		if (ensemble[i]->getRang(iCritere - 1) > alea && ensemble[i-1]->getRang(iCritere - 1) < alea)	
			return *ensemble[i];
	}
}*/
//~ Pour le return je suis pas sur de ce qu'on renvoie. On renvoie un tableau avec les nums des individus selectionné ?

	
	
	
//l'algo	
/*if (ensemble.size() % 2 == 0)
	limite = ensemble.size() / 2;
else 
	limite = ensemble.size() -1 / 2;

scoreMax = somme des scores

for(j = 0; j < nombreCritères; j ++){
	for (i = 0; i < ensemble.size(); i ++){
		calculer valeur en pourcentage en fonction du score max 
	}
}
//pour le multicritère : choisir limite/2 en fonction du premier score, et le limite/2 en fonction du second
while (nbIndivSelect < limite){
	if(valeur indiv[1] > alea)
		selectionner indiv
	for (i = 1; i < ensemble.size(); i ++){
		if (valeur indiv[i] > alea && valeur indiv[i-1] < val)
			selectionner indiv[i]
	}
}
return les individus selectionnés 

*/
/** quick sort **/
/*
void quickSort(int tableau[], int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];

    // Si le tableau est de longueur nulle, il n'y a rien à faire. 
    if(debut >= fin)
        return;

    // Sinon, on parcourt le tableau, une fois de droite à gauche, et une
    // autre de gauche à droite, à la recherche d'éléments mal placés,
    // que l'on permute. Si les deux parcours se croisent, on arrête. 
    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    // Maintenant, tous les éléments inférieurs au pivot sont avant ceux
    // supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
    // pour cela... la méthode quickSort elle-même ! 
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

void Population::triPopulation(int indiceScore) //va falloir maroufler parce que le tri a bulle ca pue, test OK
{ 
	if (criteres[indiceScore] == 1) //MAXIMISATION
	{
		int taille = ensemble.size();
    	while(!tab_en_ordre)
		{	
			tab_en_ordre = true;
        	for(int i=0 ; i < taille-1 ; i++)
        	{
            	if(ensemble[i]->Individu::getScore(indiceScore) < ensemble[i+1]->Individu::getScore(indiceScore))
            	{
                	swap(ensemble[i],ensemble[i+1]);
                	tab_en_ordre = false;
            	}
        	}
        	taille--;
    	}
	}
	else if (criteres[indiceScore] == 2) //MINIMISATION
	{
		
		int taille = ensemble.size();
    	while(!tab_en_ordre)
		{	
			tab_en_ordre = true;
        	for(int i=0 ; i < taille-1 ; i++)
        	{
            	if(ensemble[i]->Individu::getScore(indiceScore) > ensemble[i+1]->Individu::getScore(indiceScore))
            	{
                	swap(ensemble[i],ensemble[i+1]);
                	tab_en_ordre = false;
            	}
        	}
        	taille--;
    	}
	}
	else if (criteres[indiceScore] == 3) //VALEUR APPROCHEE
	{
		

		float val;
		if (indiceScore == 1)
			val = valeurApprochee;
		else if (indiceScore == 2)
			val = valeurApprochee2;
		else 
			std::cerr<<"error triPopulation" <<std::endl;

		int taille = ensemble.size();
		int difference;	

        for(int i=0 ; i < taille ; i++)
        {	
        	if(val < ensemble[i]->Individu::getScore(indiceScore) ){
            	difference = ensemble[i]->Individu::getScore(indiceScore) - val;
        	}
            else{ 
            	difference = val - ensemble[i]->Individu::getScore(indiceScore);
            }
            ensemble[i]->Individu::setRang(difference, indiceScore);
            std::cout<<ensemble[i]->Individu::getRang(indiceScore)<<std::endl;
        }

        while(!tab_en_ordre)
		{	
			tab_en_ordre = true;
        	for(int i=0 ; i < taille-1 ; i++)
        	{
            	if(ensemble[i]->Individu::getRang(indiceScore) > ensemble[i+1]->Individu::getRang(indiceScore))
            	{
                	swap(ensemble[i],ensemble[i+1]);
                	tab_en_ordre = false;
            	}
        	}
        	taille--;
    	}
	}
	else 
		std::cerr<<"error triPopulation" <<std::endl;
}
*/
