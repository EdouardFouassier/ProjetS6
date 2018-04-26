//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///       initialisation_population.cpp        ///
//////////////////////////////////////////////////
#include "initialisation_population.h"


//////// Valeurs statiques ////////
int Individu::tailleIndividu = 0;
int Individu::nombreCritere = 0;
float Individu::probaMutation = 0;

// Constructeurs //
Individu::Individu() {}		//// Là je ne sais pas trop pour l'instant
Individu::Individu(int taille) {
	for(int i = 0; i < taille; i++){
		this->chromosome[i] = rand()%2;
	}
	// this->tailleIndividu = taille;
	// this->chromosome[taille];
	// for(int i = 0; i < taille; i ++){
		// this->chromosome[i] = 0;
	// }
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


// Méthodes //
/*
Individu Individu::codage(int valeur) {
	Individu indiv = Individu();
	// int inter = 0;
	int* res;
	int i = 0;
	int j = 0;
	while(valeur != 0){
		if(valeur%2 == 0){
			res[i] = 0;
		}
		else{
			res[i] = 1;
		}
		valeur /= 2;
		i++;
	}
	for(int k = i; k > 0; k++){
		this->chromosome[j] = res[k];
		j++;
	}
	return indiv;
}*/
int Individu::decodage(Individu i) {
	int res = 0;
	for(int j = 0; j < i.getTailleIndividu(); j++){
		res += i.chromosome[j] * pow(2, j);  /// res = chromosome[j] * 2 puissance j
	}
	return res;
}
//// Pour évaluation, ça ne m'arrange pas d'avoir un decodage(Individu) ///
int Individu::decodage(int* binaire) {
	int res = 0;
	for(int j = 0; j < sizeof(binaire); j++){
		res += this->chromosome[j] * pow(2, j);  /// res = chromosome[j] * 2 puissance j
	}
	return res;
}

bool Individu::evaluationIndividu(string fonctionFitness, int indiceScore) {
	int res = calculfitness(fonctionFitness.c_str(), decodage(this->chromosome));	// .c_str : convert string to char*
	this->score[indiceScore] = res;
	return true;	// Pas de vérif' pour le moment
}
int Individu::mutation(int gene) {
	if(probAlea(this->probaMutation))
		return (gene+1)%2;
	return gene;
}
bool Individu::probAlea(float prob) {
	double alea = rand()/(double)RAND_MAX; 	//génère un nb dans [0,1]
	
	if(alea < prob) return true;
	return false;
}

double Individu::calculFitness(const char* c, double x) {
	double res = calculfitness(c, x);
	return res;
}


//// Pardon, je me suis un peu énervée... ////
