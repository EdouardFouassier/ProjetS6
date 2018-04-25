//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              individu.h                  ///
//////////////////////////////////////////////////
#ifndef __GENERATION_H
#define __GENERATION_H

#include "initialisation_population.h"
#include "entree_sortie.h"
#include <string>
using namespace std;


class Individu{

private:
	int[tailleIndividu] chromosome;
	int[nombreCriteres] score;
	int[nombreCriteres] rang;
	static int tailleIndividu;
	static float probaMutation;
	static int nombreCriteres;

public: 
	/* LES CONSTRUCTEURS ET DESTRUCTEUR*/
	Population();
	Population(Population const& P);
	Population(string* const& donnees); 		//données est censé être un tableau mais ça compile pas quand j'en fais un tab
	~Population();



	/*LES GETTEURS*/
	int getNombreIndividus();
	//Individu[] getEnsemble();
	int getNumeroGeneration();
	string getFitness1();
	string getFitness2();
	float getValeurApprochee();
	int getNombreGenerationMax();

	/*LES SETTEURS*/
	void setNombreIndividus(int nbIndiv);
	//Individu [nombreIndividus] setEnsemble(int i, Individu new);
	void setNumeroGeneration(int numGen);
	void setFitness1(string fit1);
	void setFitness2(string fit2);
	void setValeurApprochee(float val);
	void setProbaCroisement(float proba);
	void setNombreGenerationMax (int nbGen);

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
