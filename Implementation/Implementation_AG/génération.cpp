//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              génération.cpp                ///
//////////////////////////////////////////////////
#include "génération.h"


/**** STATIC ****/

int Population::nombreIndividus = 0;
int Population::nombreCriteres = 0;
int Population::numeroGeneration = 0;
int* Population::criteres = nullptr;
float Population::valeurApprochee = 0.0;
float Population::valeurApprochee2 = 0.0; ///pas dans le cds///
string Population::fitness1 = "";
string Population::fitness2 = "";
int Population::nombreGenerationMax = 0;
float Population::probaCroisement = 0.0;

/**** CONSTRUCTEURS****/

Population::Population() : ensemble(0)
{
	numeroGeneration += 1;
}

Population::Population(Population const& P) : ensemble(P.ensemble)
{
	numeroGeneration += 1;
	
}

Population::Population(string* const& donnees) :  ensemble(0){
	
	probaCroisement = std::stof(donnees[0],nullptr); // string to float
	nombreIndividus = std::stoi(donnees[1], nullptr, 10);
	nombreCriteres = std::stoi(donnees[2], nullptr, 10);
	nombreGenerationMax = std::stoi(donnees[3], nullptr, 10);	
	valeurApprochee = std::stof(donnees[4], nullptr);
	valeurApprochee2 = std::stof(donnees[5], nullptr); ///pas dans le cds///
	fitness1 = donnees[6];
	fitness2 = donnees[7];
	criteres[0] = std::stoi(donnees[8], nullptr, 10);
	criteres[1] = std::stoi(donnees[9], nullptr, 10);
	numeroGeneration += 1;
	
}

/**** DESTRUCTEUR ****/

Population::~Population(){
	std::cout<<"DESTRUCTEUR POPULATION"<<endl;
	//for(int i = 0; i < this->nombreIndividus;i++)

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

vector<Individu> Population::getEnsemble(){
	return this->ensemble;
}

int Population::getNombreGenerationMax(){		//fonction qu'on a oubliée dans le cds :(
	return this->nombreGenerationMax;
}
/// PAS DANS LE CDS (mais inutiles pour l'instant donc maybe on est bon quand même)
/*
int Population::getNombreCriteres(){			//fonction qu'on a oubliée dans le cds :(
	return this->nombreCriteres;
}

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



/**** TESTS ****/

Population Population::testArret(){
	if(this->testConvergence() && this->testNombreGeneration()){
		//ecrire fichier score
	}
	return *this;
}

bool Population::testConvergence(){
	return NULL;
}

bool Population::testNombreGeneration(){
	//if(this->getNumeroGeneration() < this->getNombreGenerationMax() )
	if (numeroGeneration < nombreGenerationMax)
		return true;
	return false;
}

bool Population::testPopulationRemplie(){
	//if taille(ensemble )  < nombreIndividu   	renvoie vrai			pb : on a rien qui nous dit combien d'individu il y a déjà...
	//solution potentielle au pb, dans cette fonction on teste la taille de l'ensemble et on utilise cette fonction plus souvent que prévu
}

/**** LES ALGOS ****/

Population Population::evaluation(){

string fitnessTmp;
	for (int iCritere = 0; iCritere < nombreCriteres - 1; iCritere ++){
		for (int iIndiv = 0; iIndiv < ensemble.size() - 1; iIndiv ++){
			if(iCritere == 0)
				fitnessTmp = this->fitness1;
			if(iCritere == 1)
				fitnessTmp = this->fitness2;
			this->ensemble[iIndiv].Individu::evaluationIndividu(fitnessTmp, iCritere);
		}
		this->triPopulation(iCritere);
		int cpt = 1;
		for(int iIndiv = 0; iIndiv < ensemble.size() - 2; iIndiv ++){
			while (this->ensemble[iIndiv].Individu::getScore(iCritere) == this->ensemble[iIndiv+1].Individu::getScore(iCritere))
				this->ensemble[iIndiv].Individu::setRang(cpt, iCritere);
			cpt ++;
		}
		if (this->ensemble[ensemble.size()].Individu::getScore(iCritere) == this->ensemble[ensemble.size()-1].Individu::getScore(iCritere))
				this->ensemble[ensemble.size()].Individu::setRang(cpt, iCritere);
		else  
			this->ensemble[ensemble.size()].Individu::setRang(cpt+1, iCritere); 
	}
	return *this;
}

bool Population::triPopulation(int indiceScore){
	return NULL;
}

Individu Population::selectionner(){

}

Population Population::crossover(Individu parent1, Individu parent2){
	return *this;
}

Population Population::creerGeneration(Population P){
	return *this;
}

int Population::nombreAlea(int inf, int sup){
	inf++;	//parce qu'on ne veut pas que inf soit inclu
	return rand()%(sup-inf) + sup;
}

