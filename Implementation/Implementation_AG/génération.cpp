//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              génération.cpp                ///
//////////////////////////////////////////////////
#include "génération.h"

using namespace std;

/**** CONSTRUCTEURS****/

Population::Population()
	: nombreIndividus(0), nombreCriteres(0), ensemble(NULL),criteres(NULL), valeurApprochee(0.0),
	 fitness1(""), fitness2(""), nombreGenerationMax(0), probaCroisement(0.0)
{
	numeroGeneration = 0;
}

Population::Population(Population const& P)
	: nombreIndividus(P.nombreIndividus), nombreCriteres(P.nombreCriteres),
	 ensemble(P.ensemble),criteres(P.criteres), valeurApprochee(P.valeurApprochee),
	 fitness1(P.fitness1), fitness2(P.fitness2), nombreGenerationMax(P.nombreGenerationMax),
	 probaCroisement(P.probaCroisement) 
{
	numeroGeneration = P.numeroGeneration;
}

Population::Population(string* const& donnees){
	float tmpTauxCross, tmpValApp;
	int tmpTaillePop, tmpNbCrit, tmpGMax, tmpCrit1, tmpCrit2;
	string tmpFit1, tmpFit2;


	tmpTaillePop = stoi(donnees[1], 0, 10);
	tmpNbCrit = stoi(donnees[2], 0, 10);
	nombreGenerationMax = stoi(donnees[3], 0, 10);	

	
	tmpFit1 = donnees[5];
	tmpFit2 = donnees[6];
	tmpCrit1 = stoi(donnees[7], 0, 10);
	tmpCrit2 = stoi(donnees[8], 0, 10);
	//this->setProbaCroisement((float)donnees[0]);
}

/**** DESTRUCTEUR ****/

Population::~Population(){

}


/**** GETTEURS ****/
/*
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

Individu[] getEnsemble(){
	return this->ensemble;
}

int Population::getNombreGenerationMax(){		//fonction qu'on a oubliée dans le cds :(
	return this->nombreGenerationMax;
}

int Population::getNombreCriteres(){			//fonction qu'on a oubliée dans le cds :(
	return this->nombreCriteres;
}

int[] Population::getCriteres(){				//fonction qu'on a oubliée dans le cds :(
	return this->criteres;
}

float Population::getProbaCroisement(){			//fonction qu'on a oubliée dans le cds :(
	return this->probaCroisement;
}
*/
/**** SETTEURS ****/
/*
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

*/

/**** TESTS ****/
/*
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
*/
/**** LES ALGOS ****/
/*
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
*/
