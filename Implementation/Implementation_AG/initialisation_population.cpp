//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///       initialisation_population.cpp        ///
//////////////////////////////////////////////////
#include "initialisation_population.h"
using namespace std;


//////// Valeurs statiques ////////
int Individu::tailleIndividu = 0;
int Individu::nombreCritere = 0;
float Individu::probaMutation = 0;
int* chromosome = NULL;
int* score = NULL;
int* rang = NULL;

// Constructeurs //
Individu::Individu() {					// ça ok Ce constructeur ne fait rien
	this->chromosome = NULL;
	this->score = NULL;
	this->rang = NULL;
}
Individu::Individu(int taille) {		// ça ok Ce constructeur crée seulement un chromosome aléatoire
	this->chromosome = NULL;
	this->score = NULL;
	this->rang = NULL;
	this->tailleIndividu = taille;
	this->chromosome = (int*)malloc(this->tailleIndividu*sizeof(int));
	for(int i = 0; i < taille; i++){
		this->chromosome[i] = rand()%2;
	}
}
Individu::Individu(float donnees[3]){	// ça ok Ce constructeur crée un chromosome aléatoire et initialise à 0 score et rang
	this->chromosome = NULL;
	this->score = NULL;
	this->rang = NULL;
//// Récup' du tableau donnees : ////
	this->tailleIndividu = donnees[0];
	this->probaMutation = donnees[1];
	this->nombreCritere = donnees[2];
	//// Chromosome random ////
	this->chromosome = (int*)malloc(this->tailleIndividu*sizeof(int));
	for(int i = 0; i < this->tailleIndividu; i++){
		chromosome[i] = rand()%2;
	}
	//// Initialisation de score et rang ////
	this->score =(int*) malloc(this->nombreCritere*sizeof(int));
	this->rang =(int*) malloc(this->nombreCritere*sizeof(int));
	for(int i = 0; i < this->nombreCritere; i++){
		this->score[i] = 0;
		this->rang[i] = 0;
	}
}

// Destructeur //
Individu::~Individu() {
	///// Il n'aime pas /////
	// for(int i = 0; i < this->tailleIndividu; i++){
	//	free(this->chromosome); // tente avec une boucle genre (pour i de 0 ç taillechromosome, free this->chromosome[i])
	// }
	// free(this->score);
	// free(this->rang);
}

// Getteurs//
int* Individu::getChromosome(){ 		// ça ok
	return this->chromosome; 
}
int Individu::getScore(int i){ 			// ça ok
	return this->score[i];
}
int Individu::getRang(int i){ 			// ça ok
	return this->rang[i];
}
int Individu::getTailleIndividu(){ 		// ça ok
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
		res[i] = valeur % 2;
		valeur /= 2;
		i++;
	}
	for(int k = i; k < 0; k--){
		indiv->chromosome[j] = res[k];
		j++;
	}
	return indiv;
}
*/
int Individu::decodage(Individu i) { 			// ça ok
	int res = 0;
	int k = 0;
	for(int j = i.getTailleIndividu() -1; j >= 0; j--){
		res += i.chromosome[j] * pow(2, k);  /// res = chromosome[j] * 2 puissance j
		cout << "chromosome[i]: " << i.chromosome[j] << " ";
		cout << "res: " << res << endl;
		k++;
	}
	return res;
}
//// Pour évaluation, ça ne m'arrange pas d'avoir un decodage(Individu) ///
int Individu::decodage(int* binaire) { 			// ça ok
	int res = 0;
	int k = 0;
	for(int j = getTailleIndividu()-1; j >= 0; j--){
		res += binaire[j] * pow(2, k);  /// res = chromosome[j] * 2 puissance j
	k++;
	}
	return res;
}
bool Individu::evaluationIndividu(string fonctionFitness, int indiceScore) { // ça ok (sauf vérif')
	this->score[indiceScore] = calculfitness(fonctionFitness.c_str(), decodage(this->chromosome));	// .c_str : convert string to char*
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

double Individu::calculFitness(const char* c, double x) { // ça ok
	cout << "c: " << c << "x" << x << endl;
	double res = calculfitness(c, x);
	return res;
}


//// Pardon, je me suis un peu énervée... ////
