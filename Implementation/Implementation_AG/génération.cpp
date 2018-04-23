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
	return 1;
}

string Population::getFitness1(){
	return "";
}

string Population::getFitness2(){
	return "";
}

float getValeurApprochee(){
	return 0.0;
}


/**** SETTEURS ****/

void Population::setNombreIndividus(int nbIndiv){

}

void Population::setNumeroGeneration(int num){

}

void Population::setFitness1(string fit1){

}

void Population::setFitness2(string fit2){

}

void Population::setValeurApprochee(float val){

}

void Population::setProbaCroisement(float proba){

}

void Population::setNombreGenerationMax(int nb){

}



/**** TESTS ****/

Population Population::testArret(){
	return *this;
}

bool Population::testConvergence(){
	return NULL;
}

bool Population::testNombreGeneration(){
	return NULL;
}

bool Population::testPopulationRemplie(){
	return NULL;
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