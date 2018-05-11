//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///        initialisation_population.h         ///
//////////////////////////////////////////////////
/// \author Groupe Sujet 4
/// \file initialisation_population.h

#ifndef __INITIALISATION_POPULATION_H
#define __INITIALISATION_POPULATION_H

#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "tinyexpr/tinyexpr.h"
using namespace std;


/// \class Individu
/// \brief Classe permettant de créer et d'utiliser des Individus.
class Individu{
private:
	static int tailleIndividu;
	static int nombreCritere;
	static float probaMutation;
	int* chromosome;
	float* score;
	int* rang;

public:
	// Constructeurs //
	
	/// \fn Individu()
	/// \brief Constructeur par défaut de la classe Individu
	Individu();	// Constructeur par défaut
	
	/// \fn Individu(int)
	/// \brief Constructeur qui créer un individu aléatoirement
	/// \param int taille donne la taille de l'individu.
	Individu(int taille); // Constructeur qui crée un Individu aléatoire
	
	/// \fn Individu(float[3])
	/// \brief Constructeur qui créer un individu avec les données fournient par l'utilisateur
	/// \param float donnees[3] tableau contenant les trois données récupérées.
	Individu(float donnees[3]); // Constructeur qui initialise ls données (qu'on utilise qu'une seule fois) les données sont envoyées par io
	
	/// \fn Individu(Individu &)
	/// \brief Constructeur de copie d'individu
	/// \param Individu &individu est l'individu à copier
	Individu(Individu &individu); // Constructeur de copie d'un individu
	
	// Destructeur //
	
	/// \fn ~Individu()
	/// \brief Destructeur de la classe Individu
	~Individu();


	// LES GETTEURS //
	
	/// \fn int* getChromosome()
	/// \brief Getteur permettant d'obtenir le tableau chromosome
	/// \return Le chromosome de l'individu
	int* getChromosome();
	
	/// \fn float getScore(int)
	/// \brief Getteur permettant d'obtenir un score à l'indice i..
	/// \param int i est l'indice du tableau des scores.
	/// \return Revoie le score à l'indice i.
	float getScore(int i);
	
	/// \fn int getRang(int)
	/// \brief Getteur permettant d'obtenir un rang à l'indice i..
	/// \param int i est l'indice du tableau des rangs.
	/// \return Revoie le rang à l'indice i.
	int getRang(int i);
	
	/// \fn int getTailleIndividu(int)
	/// \brief Getteur permettant d'obtenir la taille de l'individu
	/// \return Revoie la taille de l'individu.
	int getTailleIndividu();
	
	/// \fn int getGene(int)
	/// \brief Getteur permettant d'obtenir un gene, c'est-à-dire l'indice i du tableau chromosome
	/// \param int i est l'indice du tableau chromosome.
	/// \return Revoie un gene.
	int getGene(int i);
	
	// Setteurs //
	/// \fn void setGene(int, int)
	/// \brief Setteur permettant de modifier le tableau chromosome à l'indice i.
	/// \param int gene est le gene à insérer dans le tableau chromosome.
	/// \param int i est l'indice du tableau chromosome.
	void setGene(int gene, int i);
	
	/// \fn void setChromosome(int*)
	/// \brief Setteur permettant de modifier le tableau chromosome
	/// \param int* chromosome est le tableau chromosome.
	void setChromosome(int* chromosome);
	
	/// \fn void setScore(float, int)
	/// \brief Setteur permettant de modifier le tableau des scores à l'indice i.
	/// \param float score est le score à insérer dans le tableau des scores.
	/// \param int i est l'indice du tableau des scores.
	void setScore(float score, int i);
	
	/// \fn void setRang(int, int)
	/// \brief Setteur permettant de modifier le tableau des rangs à l'indice i.
	/// \param float rang est le rang à insérer dans le tableau des rangs.
	/// \param int i est l'indice du tableau des scores.
	void setRang(int rang, int i);

	// Méthodes //
	
	/// \fn Individu codage(int)
	/// \brief Méthode permettant de transformer un entier en base 10 passé en arguement en binaire. Ce chiffre binaire est stocké dans le tableau chromosme de l'individu.
	/// \param int valeur en base 10
	/// \return L'Individu avec le tableau chromosome modifié.
	Individu codage(int valeur);
	
	/// \fn int decodage(Individu)
	/// \brief Méthode permettant de changer le tableau de chromosome (en binaire) de l'Individu i en une valeur entière en base 10.
	/// \param Individu i avec le tableau de chromosome à décoder
	/// \return La valeur du chromosome de l'Individu i.
	int decodage(Individu i);
	
	/// \fn int decodage(int* binaire)
	/// \brief Méthode permettant de changer un tableau binaire en une valeur entière en base 10.
	/// \param int* binaire tableau de 0 et de 1.
	/// \return Renvoie la valeur en base 10.
	int decodage(int* binaire);
	
	/// \fn bool evaluationIndividu(string, int)
	/// \brief Méthode appelant la méthode calculFitness pour attribuer un score à l'Individu en cours.
	/// \param string fonctionFitness
	/// \param int indiceScore est l'indice du tableau des score où sera ranger le résultat de l'évaluaion de l'Individu.
	/// \return Revoie TRUE s'il n'y a pas eu de problème lors de l'évaluation, FALSE sinon.
	bool evaluationIndividu(string fonctionFitness, int indiceScore) ;
	
	/// \fn int mutation(int)
	/// \brief Méthode permettant de muter un gène selon une probabilité. Si probAlea(float) renvoie TRUE alors gene passé en argument est modifié, sinon non.
	/// \param int gene est le gène à muter.
	/// \return Revoie le gène muté ou non.
	int mutation(int gene) const ;
	
	/// \fn bool probAlea(float)
	/// \brief Méthode permettant générer un nombre entre 0 et 1 pseudo aléatoirement.
	/// \param float prob la probabilité de renvoyer TRUE
	/// \return Revoie TRUE si le nombre généré est inférieur à prob, FALSE sinon.
	bool probAlea(float prob) const;
	
	/// \fn bool calculFitness(const char*, double x)
	/// \brief Méthode appelant la méthode calculfitness (dans tinyexpr.h).
	/// \param const char* c est la fonction d'évaluation (fonction fitness).
	/// \param double x est la variable.
	/// \return Revoie le résultat de l'évaluation.
	double calculFitness(const char* c, double x);
};

#endif
