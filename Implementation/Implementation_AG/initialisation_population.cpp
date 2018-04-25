//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              initialisation_population.cpp ///
//////////////////////////////////////////////////
#include "initialisation_population.h"

int Individu::tailleIndividu = 0;

int Individu::nombreCritere = 0;

float Individu::probaMutation = 0;

//constructeurs//

Individu::Individu()
{
	
}

Individu::Individu(int tailleIndividu)
{
	
}

/**** DESTRUCTEUR ****/

Individu::~Individu(){
}

//getteurs//

int* Individu::getChromosome(){
	return this->chromosome;
}

int Individu::getScore(){
	return this->score;
}

int Individu::getRang(int i){
	return this->rang;
	//faut utiliser i la mais je sais plus comment
}

int* Individu::getTailleIndividu(){
	return this->tailleIndividu;
}
	
// Setteurs //


void Individu::setGene(int gene, int i){
}

void Individu::setChromosome(int* chromosome2){
	this->chromosome = chromosome2;
}

void Individu::setScore(int score, int i){
}

void Individu::setRang(int rang, int i){
}

void Individu::setTailleIndividu(int tailleIndividu2){
	this->tailleIndividu = tailleIndividu2;
}

// Méthodes //

Individu Individu::codage(int valeur){
}

int Individu::decodage(Individu i){
}

bool Individu::evaluationIndividu(string fonctionFitness, int indiceScore){
}

int Individu::mutation(int gene){
}

bool Individu::probAlea(float prob){
}

double Individu::calculFitness(const char* c, double x){
}
