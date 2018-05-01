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

Population::Population() : ensemble(0)
{
	numeroGeneration += 1;
	std::cout<<"CREATION SUCCESS"<<endl;
}

Population::Population(Population const& P) : ensemble(P.ensemble)
{
	numeroGeneration += 1;
	std::cout<<"CREATION SUCCESS"<<endl;
	
}

Population::Population(string* const& donnees) :  ensemble(0){

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
			criteres[1] = std::stoi(donnees[4], nullptr, 10);    //initialisation du critere 2
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
	for(int i = 0; i < nombreIndividus; i++){
		Individu *nouv = new Individu();
		ensemble.push_back(nouv);
	}
	std::cout<<"CREATION SUCCESS"<<endl;
}


/**** DESTRUCTEUR ****/

Population::~Population(){
	std::cout<<"DESTRUCTEUR POPULATION"<<endl;
	std::cout<<ensemble.size()<<endl;
	for(int i = 0; i < ensemble.size();i++){
		delete ensemble[i];
		std::cout<<"individu "<<i<<"détruit"<<std::endl;
	}
	//delete[] &ensemble; 
	//std::cout<<"pointeur sur ensemble détruit"<<std::endl;
	/*if (criteres != nullptr){
		free(criteres);
	}*/
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

Population Population::testArret(){ //pourquoi ça doit renvoyer un population? 
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

bool Population::testConvergence(){
	return NULL;
}

bool Population::testNombreGeneration(){
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

Population Population::evaluation(){// entheorie c'est bon, a tester 

	string fitnessTmp;
	for (int iCritere = 0; iCritere < nombreCriteres - 1; iCritere ++){
		for (int iIndiv = 0; iIndiv < ensemble.size() - 1; iIndiv ++){
			if(iCritere == 0)
				fitnessTmp = this->fitness1;
			if(iCritere == 1)
				fitnessTmp = this->fitness2;
			this->ensemble[iIndiv]->Individu::evaluationIndividu(fitnessTmp, iCritere);
		}
		this->triPopulation(iCritere);
		int cpt = 1;
		for(int iIndiv = 0; iIndiv < ensemble.size() - 2; iIndiv ++){
			while (this->ensemble[iIndiv]->Individu::getScore(iCritere) == this->ensemble[iIndiv+1]->Individu::getScore(iCritere))
				this->ensemble[iIndiv]->Individu::setRang(cpt, iCritere);
			cpt ++;
		}
		if (this->ensemble[ensemble.size()]->Individu::getScore(iCritere) == this->ensemble[ensemble.size()-1]->Individu::getScore(iCritere))
				this->ensemble[ensemble.size()]->Individu::setRang(cpt, iCritere);
		else  
			this->ensemble[ensemble.size()]->Individu::setRang(cpt+1, iCritere); 
	}
	return *this;
}

bool Population::triPopulation(int indiceScore){ //va falloir maroufler parce que le tri a bulle ca pue , a tester
	bool tab_en_ordre = false;
	std::cout<<"critère de tri = "<<criteres[indiceScore]<<std::endl;
	if (criteres[indiceScore] == 1) //MAXIMISATION
	{
		std::cerr<<"MAXIMISATION" <<std::endl;
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
	else if (criteres[indiceScore] == 2) //MINIMISATION
	{
		std::cerr<<"MINIMISATION" <<std::endl;
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
	else if (criteres[indiceScore] == 3) //VALEUR APPROCHEE
	{
		std::cerr<<"VALEUR APPROCHEE" <<std::endl;
		int val;
		if (indiceScore == 1)
			val = valeurApprochee;
		else if (indiceScore == 2)
			val = valeurApprochee2;
		else 
			std::cerr<<"error triPopulation" <<std::endl;

		int taille = ensemble.size();
		vector<Individu*> ensembleTmpSup;  //vecteur regroupant les indiv d'un score inferieur à la valeur
		vector<Individu*> ensembleTmpInf;  //vecteur regroupant les indiv d'un score superieur à la valeur

		/** SEPARATION DU VECTEUR D'INDIVIDU **/
        for(int i=0 ; i < taille ; i++)
        {
         	if(ensemble[i]->Individu::getScore(indiceScore) > val)
              	ensembleTmpSup.push_back(ensemble[i]);
           	else if (ensemble[i]->Individu::getScore(indiceScore) < val)
           		ensembleTmpInf.push_back(ensemble[i]);
        }

        int ensembleSize = ensemble.size();
        for(int i = 0; i < ensembleSize;i++){
			ensemble.pop_back();
		}
    	/** TRI DU VECTEUR INF **/
    	bool tab_en_ordre_tmpinf = false;
    	int tailleInf = ensembleTmpInf.size();
    	while(!tab_en_ordre_tmpinf)
		{	
			tab_en_ordre_tmpinf = true;
        	for(int i=0 ; i < tailleInf-1 ; i++)
        	{
           		if(ensembleTmpInf[i]->Individu::getScore(indiceScore) > ensembleTmpInf[i+1]->Individu::getScore(indiceScore)){
               		swap(ensembleTmpInf[i],ensembleTmpInf[i+1]);
               		tab_en_ordre_tmpinf = false;
               	}
        	}
        	tailleInf--;
    	}
        /** TRI DU VECTEUR SUP **/
        bool tab_en_ordre_tmpsup = false;
        int tailleSup = ensembleTmpSup.size();
    	while(!tab_en_ordre_tmpsup)
		{	
			tab_en_ordre_tmpsup = true;
        	for(int i=0 ; i < tailleSup-1 ; i++)
        	{
           		if(ensembleTmpSup[i]->Individu::getScore(indiceScore) > ensembleTmpSup[i+1]->Individu::getScore(indiceScore)){
               		swap(ensembleTmpSup[i],ensembleTmpSup[i+1]);
               		tab_en_ordre_tmpsup = false;
               	}
        	}
        	tailleSup--;
    	}
        /** FUSION DE INF ET SUP DANS ENSEMBLE **/
        for (int i = 0; i <  ensembleTmpInf.size() ; i ++){
        	ensemble.push_back(ensembleTmpInf[i]);
        }
        for (int i = 0; i <  ensembleTmpSup.size() ; i ++){
        	ensemble.push_back(ensembleTmpSup[i]);
        }

        /**SUPPRESSION DES TMP **/
        for (int i = 0; i <  ensembleTmpInf.size() ; i ++)
        	ensembleTmpInf.pop_back();
        for (int i = 0; i <  ensembleTmpSup.size() ; i ++)
        	ensembleTmpSup.pop_back();

        tab_en_ordre = true;
	}
	else 
		std::cerr<<"error triPopulation" <<std::endl;
	return NULL;
}

Individu Population::selectionner(){

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

/*bool Individu::probAlea(float prob) {
	double alea = rand()/(double)RAND_MAX; 	//génere un nb dans [0,1]
	
	if(alea < prob) return true;
	return false;
}*/

int Population::nombreAlea(int inf, int sup){
	//inf++;	//parce qu'on ne veut pas que inf soit inclu
	return rand()%(sup-inf) + sup;
}



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
*/
