#include "génération.h"

/**** CONSTRUCTEURS****/

Population::Population(){
	
}

Population::Population(const Population& P){
	
}

Population::Population(string donnees){
	
}

Population::~Population(){

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

int Population::getNombreGenerationMax(){		//fonction qu'on a oubliée dans le cds :(
	return this->nombreGenerationMax;
}


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

bool Population::testConvergence(){
	return NULL;
}

bool Population::testNombreGeneration(){
	if(this->getNumeroGeneration() < this->getNombreGenerationMax() )
		return true;
	return false;
}

bool Population::testPopulationRemplie(){
	//if taille(ensemble )  < nombreIndividu   	renvoie vrai			pb : on a rien qui nous dit combien d'individu il y a déjà...
}

/**** LES ALGOS ****/

Population Population::evaluation(){
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
	return 0;
}