//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///       initialisation_population.cpp        ///
//////////////////////////////////////////////////
#include "../Headers/initialisation_population.h"
using namespace std;


//////// Valeurs statiques ////////
int Individu::tailleIndividu = 0;
int Individu::nombreCritere = 0;
float Individu::probaMutation = 0;
int* chromosome = NULL;
float* score = NULL;
int* rang = NULL;

// Constructeurs //
Individu::Individu() {	
	this->score =(float*) malloc(this->nombreCritere*sizeof(float));
	this->rang =(int*) malloc(this->nombreCritere*sizeof(int));				// ça ok Ce constructeur ne fait rien
	this->chromosome = (int*)malloc((this->tailleIndividu+1)*sizeof(int));
	for(int i = 0; i < this->tailleIndividu+1; i++){
		chromosome[i] = 0;
	}
}
Individu::Individu(int taille) {		// ça ok Ce constructeur crée seulement un chromosome aléatoire
	this->chromosome = NULL;
	this->score =(float*) malloc(this->nombreCritere*sizeof(float));
	this->rang =(int*) malloc(this->nombreCritere*sizeof(int));
	this->tailleIndividu = taille;
	this->chromosome = (int*)malloc((this->tailleIndividu+1)*sizeof(int));
	for(int i = 0; i < taille+1; i++){
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
	this->chromosome = (int*)malloc((this->tailleIndividu+1)*sizeof(int));
	for(int i = 0; i < this->tailleIndividu+1; i++){
		chromosome[i] = rand()%2;
	}
	//// Initialisation de score et rang ////
	this->score =(float*) malloc(this->nombreCritere*sizeof(float));
	this->rang =(int*) malloc(this->nombreCritere*sizeof(int));
	for(int i = 0; i < this->nombreCritere; i++){
		this->score[i] = 0.0;
		this->rang[i] = 0;
	}
}

Individu::Individu(Individu &indiv){

	this->chromosome = (int*)malloc((this->tailleIndividu+1)*sizeof(int));
	for(int i=0;i<tailleIndividu+1;i++){
		this->chromosome[i]=indiv.getChromosome()[i];
	}
	this->score =(float*) malloc(this->nombreCritere*sizeof(float));
	this->rang =(int*) malloc(this->nombreCritere*sizeof(int));
	for(int i = 0; i < this->nombreCritere; i++){
		this->score[i] = 0.0;
		this->rang[i] = 0;
	}
}

// Destructeur //
Individu::~Individu() {
	cout<<"DESTRUCTEUR INDIVIDU"<<endl;
	delete[] score;
	delete[] rang;
	delete[] chromosome;
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
float Individu::getScore(int i){ 			// ça ok
	return this->score[i];
}
int Individu::getRang(int i){ 			// ça ok
	return this->rang[i];
}
int Individu::getTailleIndividu(){ 		// ça ok
	return this->tailleIndividu;
}

int Individu::getGene(int i){
	return this->chromosome[i];
}


	
// Setteurs //
void Individu::setGene(int gene, int i){
	this->chromosome[i] = gene;
}
void Individu::setChromosome(int* chromosome2){
	this->chromosome = chromosome2;
	// Non pas comme ça //
}
void Individu::setScore(float score, int i){
	this->score[i] = score;
}
void Individu::setRang(int rang, int i){
	this->rang[i] = rang;
}


// Méthodes //
Individu Individu::codage(int valeur) {		/// Ca ok avec négatif
	int inter = valeur;
	Individu indiv(tailleIndividu);	// Nouvel individu //
	int* res;			// Résultat qui sera le int* chromosome de indiv //
	res = (int*)malloc((this->tailleIndividu+1)*sizeof(int));	// réservation du tableau res //
	int i = 1;
	int j = 0;
	while(valeur != 0){
		res[i] = abs(valeur % 2);
		valeur /= 2;
		i++;
	}
	if(i <= tailleIndividu){				/// Compléter le chiffre de 0
		while(i != tailleIndividu + 1){
			res[i] = 0;
			i++;
		}
	}
	if(inter < 0)			// Négatif
		res[i] = 1;
	else					// Positif
		res[i] = 0;
	for(int k = i; k > 0; k--){
		indiv.chromosome[j] = res[k];
		j++;
	}
	return indiv;
}
int Individu::decodage(Individu i) { 			// ça ok avec prise en compte du neg
	int res = 0;
	int k = 0;
	for(int j = i.getTailleIndividu(); j >= 1; j--){
		res += i.chromosome[j] * pow(2, k);  /// res = chromosome[j] * 2 puissance j
		k++;
	}
	if(i.chromosome[0] == 1)
		res *= -1;
	return res;
}
//// Pour évaluation, ça ne m'arrange pas d'avoir un decodage(Individu) ///
int Individu::decodage(int* binaire) { 			// ça ok avec prise en compte du neg
	int res = 0;
	int k = 0;
	for(int j = getTailleIndividu(); j >= 1; j--){
		res += binaire[j] * pow(2, k);  /// res = chromosome[j] * 2 puissance j
	k++;
	}
	if(binaire[0] == 1)
		res *= -1;
	return res;
}
bool Individu::evaluationIndividu(string fonctionFitness, int indiceScore) { // ça ok (sauf vérif')
	double tmpScore = calculfitness(fonctionFitness.c_str(), decodage(this->chromosome));	// .c_str : convert string to char*
	this->score[indiceScore] = tmpScore;
	//~ std::cout<<"Score : "<< this->score[indiceScore] << std::endl;
	return true;	// Pas de vérif' pour le moment
}
int Individu::mutation(int gene) const {
	if(probAlea(this->probaMutation))
		return (gene+1)%2;
	return gene;
}
bool Individu::probAlea(float prob) const {
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
