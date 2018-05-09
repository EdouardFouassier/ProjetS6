//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              génération.h                  ///
//////////////////////////////////////////////////
#ifndef __GENERATION_H
#define __GENERATION_H

#include "initialisation_population.h"
#include "entree_sortie.h"
#include <string>
#include <vector>
using namespace std;


class Population{

private:
	static int nombreIndividus;
	static int nombreCriteres;
	vector<Individu*> ensemble; 
	static int numeroGeneration;
	static int* criteres; 		//alors qu'ici ça marche avec rien ¯\_(ツ)_/¯
	static float valeurApprochee;
	static float valeurApprochee2; ///pas dans le cds///
	static string fitness1;
	static string fitness2;
	static int nombreGenerationMax;
	static float probaCroisement;

public: 
	/* LES CONSTRUCTEURS ET DESTRUCTEUR*/
	Population();
	Population(Population const& P);
	Population(string* const& donnees); 		//données est censé être un tableau mais ça compile pas quand j'en fais un tab
	~Population();



	/*LES GETTEURS*/
	int getNombreIndividus();
	vector<Individu*> getEnsemble();
	int getNumeroGeneration();
	string getFitness1();
	string getFitness2();
	float getValeurApprochee();
	float getValeurApprochee2(); //pas dans le cds
	int getNombreGenerationMax();
	int getNombreCriteres(); //pas dans le cds
	
	/*LES SETTEURS*/
	void setNombreIndividus(int nbIndiv);
	void setEnsemble(Individu &nouv); //modifié par rapport au cds
	void setNumeroGeneration(int numGen);
	void setFitness1(string fit1);
	void setFitness2(string fit2);
	void setValeurApprochee(float val);
	void setValeurApprochee2(float val); //pas dans le cds 
	void setProbaCroisement(float proba);
	void setNombreGenerationMax (int nbGen);
	

	/*LES TESTS*/
	Population testArret();
	bool testNombreGeneration();
	bool testConvergence();
	bool testPopulationRemplie();

	/* LES ALGORITHMES DE CREATION DE GENERATION*/
	void evaluation(); 
	void triPopulation (int indiceScore); //signature modifié / cds
	void maximisation (int indiceScpre); //pas dans cds
	void minimisation (int indiceScore); //pas dans cds
	void triValeur (int indiceScore); //pas dans cds
	Individu* selectionner(int iCritere); // modifié / cds : ajout parametre et fonctionnement modifié 
	void crossover(Individu *Parent1, Individu *Parent2);
	Population creerGeneration(Population P);
	int nombreAlea(int inf, int sup);

};


#endif
