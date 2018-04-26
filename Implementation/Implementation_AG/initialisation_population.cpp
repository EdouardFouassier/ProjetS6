//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///       initialisation_population.cpp        ///
//////////////////////////////////////////////////
#include "initialisation_population.h"


//////// ALORS ÇA, FAUT M'EXPLIQUER L'INTERET ////////
// int Individu::tailleIndividu = 0;
// int Individu::nombreCritere = 0;
// float Individu::probaMutation = 0;

// Constructeurs //
Individu::Individu() {}
Individu::Individu(int taille) {
	Individu::tailleIndividu = taille;
	Individu::chromosome[taille];
	for(int i = 0; i < taille; i ++){
		this->chromosome[i] = 0;
	}

}

// Destructeur //
Individu::~Individu() {}

// Getteurs//
int* Individu::getChromosome(){
	return this->chromosome; 
}
int Individu::getScore(int i){
	return this->score[i];
}
int Individu::getRang(int i){
	return this->rang[i];
}
int Individu::getTailleIndividu(){
	return this->tailleIndividu;
}
	
// Setteurs //
void Individu::setGene(int gene, int i){
	this->chromosome[i] = gene;
}
void Individu::setChromosome(int* chromosome2){
	this->chromosome = chromosome2;
	// Non pas comme ça //
}
void Individu::setScore(int score, int i){
	this->score[i] = score;
}
void Individu::setRang(int rang, int i){
	this->rang[i] = rang;
}
void Individu::setTailleIndividu(int tailleIndividu2){
	this->tailleIndividu = tailleIndividu2;
	// Et ça c'est sensé être un static, ça n'a pas de sens de set un static //
}

// Méthodes //
Individu Individu::codage(int valeur) {}
int Individu::decodage(Individu i) {}
bool Individu::evaluationIndividu(string fonctionFitness, int indiceScore) {}
int Individu::mutation(int gene) {}
bool Individu::probAlea(float prob) {}
double Individu::calculFitness(const char* c, double x) {}


//// Pardon, je me suis un peu énervée... ////