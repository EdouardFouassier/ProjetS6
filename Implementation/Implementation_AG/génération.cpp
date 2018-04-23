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
string Population::fitness1 = "";
string Population::fitness2 = "";
int Population::nombreGenerationMax = 0;
float Population::probaCroisement = 0.0;

/**** CONSTRUCTEURS****/

Population::Population() : ensemble(nullptr)
{
	numeroGeneration += 1;
}

Population::Population(Population const& P) : ensemble(P.ensemble)
{
	numeroGeneration += 1;
	
}

Population::Population(string* const& donnees) :  ensemble(nullptr){
	
	probaCroisement = std::stof(donnees[0],nullptr); // string to float
	nombreIndividus = std::stoi(donnees[1], nullptr, 10);
	nombreCriteres = std::stoi(donnees[2], nullptr, 10);
	nombreGenerationMax = std::stoi(donnees[3], nullptr, 10);	
	valeurApprochee = std::stof(donnees[4], nullptr);
	fitness1 = donnees[5];
	fitness2 = donnees[6];
	criteres[0] = std::stoi(donnees[7], nullptr, 10);
	criteres[1] = std::stoi(donnees[8], nullptr, 10);
	numeroGeneration += 1;
	
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

int main(){
	return 0;
}