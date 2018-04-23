//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              génération.h                  ///
//////////////////////////////////////////////////
#ifndef __GENERATION_H
#define __GENERATION_H

#include "initialisation_population.h"
#include "entree_sortie.h"
#include <string>
using namespace std;


class Population{

private:
	static int nombreIndividus;
	static int nombreCriteres;
	//Individu ensemble []; //pb : je sais pas quoi mettre entre les crochets lolz, ça marche pas avec rien
	static int numeroGeneration;
	static int criteres []; 		//alors qu'ici ça marche avec rien ¯\_(ツ)_/¯
	static float valeurApprochee;
	static string fitness1;
	static string fitness2;
	static int nombreGenerationMax;
	static float probaCroisement;

public: 
	/* LES CONSTRUCTEURS ET DESTRUCTEUR*/
	Population();
	Population(const Population& P);
	Population(string donnees);
	~Population();



	/*LES GETTEURS*/
	int getNombreIndividus();
	//Individu[] getEnsemble();
	int getNumeroGeneration();
	string getFitness1();
	string getFitness2();
	float getVAleurApprochee();

	/*LES SETTEURS*/
	void setNombreIndividus(int nbIndiv);
	//Individu [nombreIndividus] setEnsemble(int i, Individu new);
	void setNumeroGeneration(int numGen);
	void setFitness1(string fit1);
	void setFitness2(string fit2);
	void serValeurApprochee(float val);
	void setProbaCroisement(float proba);
	void serNombreGenerationMax (int nbGen);

	/*LES TESTS*/
	Population testArret();
	bool testNombreGeneration();
	bool testConvergence();
	bool testPopulationRemplie();

	/* LES ALGORITHMES DE CREATION DE GENERATION*/
	Population evaluation();
	bool triPopulation (int indiceScore);
	Individu selectionner();
	Population crossover(Individu Parent1, Individu Parent2);
	Population creerGeneration(Population P);
	int nombreAlea(int inf, int sup);

};


#endif