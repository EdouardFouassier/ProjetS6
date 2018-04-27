//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///        initialisation_population.h         ///
//////////////////////////////////////////////////

#ifndef __INITIALISATION_POPULATION_H
#define __INITIALISATION_POPULATION_H

#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include "tinyexpr/tinyexpr.h"
using namespace std;

class Individu{
private:
	static int tailleIndividu;
	static int nombreCritere;
	static float probaMutation;
	int* chromosome;
	int* score;
	int* rang;
	// int[tailleIndividu] chromosome;
	// int[nombreCritere] score;
	// int[nombreCritere] rang;
	

public:
	// Constructeurs
	Individu();	// Constructeur par défaut
	Individu(int taille); // Constructeur qui crée un Individu aléatoire
	Individu(float donnees[3]); //Constructeur qui initialise ls données (qu'on utilise qu'une seule fois) les données sont envoyées par io

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
