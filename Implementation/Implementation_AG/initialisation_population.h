//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///        initialisation_population.h         ///
//////////////////////////////////////////////////

#ifndef __INITIALISATION_POPULATION_H
#define __INITIALISATION_POPULATION_H

#include <string>
using namespace std;

class Individu{
private:
	static int tailleIndividu;
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
	Individu(int taille); // 

	// Destructeur
	~Individu();

	// Setteurs
	void setGene(int gene, int i);
	// void setChromosome(int[tailleIndividu] chromosome);
	void setChromosome(int* chromosome);
	void setScore(int score, int i);
	void setRang(int rang, int i);
	void setTailleIndividu(int tailleIndividu);

	// Méthodes
	Individu codage(int valeur);
	int decodage(Individu i);
	bool evaluationIndividu(string fonctionFitness, int indiceScore);
	int mutation(int gene);
	bool probAlea(float prob);
	double calculFitness(const char* c, double x);
};

#endif