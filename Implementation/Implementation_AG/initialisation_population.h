//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///        initialisation_population.h         ///
//////////////////////////////////////////////////

#ifndef __INITIALISATION_POPULATION_H
#define __INITIALISATION_POPULATION_H

#include <string>
#include <cmath>
#include "tinyexpr/tinyexpr.h"
using namespace std;

class Individu{
private:
	static int tailleIndividu;  //// static c'est relou !
	// int[tailleIndividu] chromosome;
	int* chromosome;
	static int nombreCritere;
	// int[nombreCritere] score;
	int* score;
	// int[nombreCritere] rang;
	int* rang;
	static float probaMutation;

public:
	// Constructeurs
	Individu();	// Constructeur par défaut
	Individu(int taille); // Constructeur qui crée un Individu aléatoire
	Individu::Individu(int donnes[3]); //Constructeur qui initialise ls données (qu'on utilise qu'une seule fois) les données sont envoyées par io

	// Destructeur
	~Individu();

	/*LES GETTEURS*/
	int* getChromosome();
	int getScore(int i);
	int getRang(int i);
	int getTailleIndividu();
	
	// Setteurs
	void setGene(int gene, int i);
	// void setChromosome(int[tailleIndividu] chromosome);
	void setChromosome(int* chromosome);
	void setScore(int score, int i);
	void setRang(int rang, int i);

	// Méthodes
	//Individu codage(int valeur);
	int decodage(Individu i);
	int decodage(int* binaire);
	bool evaluationIndividu(string fonctionFitness, int indiceScore);
	int mutation(int gene);
	bool probAlea(float prob);
	double calculFitness(const char* c, double x);
};

#endif
