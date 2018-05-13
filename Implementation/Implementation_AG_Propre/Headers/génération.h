//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              génération.h                  ///
//////////////////////////////////////////////////
/// \author Groupe Sujet 4
/// \file génération.h

#ifndef __GENERATION_H
#define __GENERATION_H

#include "initialisation_population.h"
#include "entree_sortie.h"
#include <string>
#include <vector>
using namespace std;

/// \class Population
/// \brief 
class Population{

private:
	static int nombreIndividus;
	static int nombreCriteres;
	vector<Individu*> ensemble; //MODIFICATION CDS : TRANSFORMATION EN VECTOR A JUSTIFIER//
	static int numeroGeneration;
	static int* criteres; 		
	static float valeurApprochee;
	static float valeurApprochee2; //MODIFICATION CDS : AJOUT DE L'ATTRIBUT A JUSTIFIER//
	static string fitness1;
	static string fitness2;
	static int nombreGenerationMax;
	static float probaCroisement;

public: 
	/* LES CONSTRUCTEURS ET DESTRUCTEUR*/
	
	/// \fn Population
	/// \brief Constructeur par défaut de la classe Population
	Population();
	
	/// \fn Population(Population const&)
	/// \brief Constructeur de copie de la classe Population
	/// \param Population const& P
	Population(Population const& P);

	/// \fn Population(string* const&)
	/// \brief Constructeur utilisant les données récurépérer de l'interface graphique ou du fichier de paramètres
	Population(string* const& donnees); //MODIFICATION CDS A JUSTIFIER//	

	/// \fn ~Population()
	/// \brief Destructeur de la classe Population
	~Population();



	/*LES GETTEURS*/
	/// \fn int getNombreIndividus(void)
	/// \brief Getteur permettant d'obtenir le nombre d'individu dans la génération en cours.
	/// \return Le nombre d'individus de la population
	int getNombreIndividus();
	
	/// \fn vector<Individu*> getEnsemble(void)
	/// \brief Getteur permettant d'obtenir l'ensemble des individus de la génération en cours.
	/// \return Le vecteur contenant tous les individus de la génération.
	vector<Individu*> getEnsemble();
	
	/// \fn int getNumeroGeneration(void)
	/// \brief Getteur permettant d'obtenir le numéro de la génération en cours.
	/// \return Le numéro de la population.
	int getNumeroGeneration();
	
	/// \fn string getFitness1(void)
	/// \brief Getteur permettant d'obtenir la première fonction fitnesss (fonction d'évaluation).
	/// \return La première fontion fitness.
	string getFitness1();
	
	/// \fn string getFitness2(void)
	/// \brief Getteur permettant d'obtenir la seconde fonction fitnesss (fonction d'évaluation).
	/// \return La seconde fontion fitness.
	string getFitness2();
	
	/// \fn float getValeurApprochee(void)
	/// \brief Getteur permettant d'obtenir la première valeur approchée.
	/// \return La première valeur approchée.
	float getValeurApprochee();
	
	/// \fn string getValeurApprochee2(void)
	/// \brief Getteur permettant d'obtenir la seconde valeur approchee.
	/// \return La seconde valeur approchée.
	float getValeurApprochee2(); //MODIFICATION CDS : AJOUT DU GETTEUR A JUSTIFIER//
	
	/// \fn int getNombreGenerationMax(void)
	/// \brief Getteur permettant d'obtenir le nombre maximum de génération à atteindre
	/// \return La nombre génération maximum.
	int getNombreGenerationMax(); //MODIFICATION CDS : AJOUT DU GETTEUR A JUSTIFIER//
	
	/// \fn int getNombreCriteres(void)
	/// \brief Getteur permettant d'obtenir le nombre critère
	/// \return La nombre de critère.
	int getNombreCriteres(); //MODIFICATION CDS : AJOUT DU GETTEUR A JUSTIFIER//
	
	/*LES SETTEURS*/
	/// \fn void setNombreIndividus(int)
	/// \brief Setteur de l'attribut nombreIndividu
	/// \param Le nombre d'individus.
	void setNombreIndividus(int nbIndiv);
	
	/// \fn void setEnsemble(Individu)
	/// \brief Setteur permettant d'ajouter un individu au vecteur conntenant l'ensemble des individu de la génération en cours.
	/// \param Nouvel Individu.
	void setEnsemble(Individu &nouv); //MODIFICATION CDS A JUSTIFIER (Individu[nombreIndividu]setEnsemble())//
	
	/// \fn void setNumeroGeneration(int)
	/// \brief Setteur de l'attribut numeroGeneration
	/// \param Le numéro de la génération.
	void setNumeroGeneration(int numGen);
	
	/// \fn void setFitness1(string)
	/// \brief Setteur de l'attribut fitness1 (fonction permettant l'évaluation).
	/// \param La première fonction fitness.
	void setFitness1(string fit1);
	
	/// \fn void setFitness2(string)
	/// \brief Setteur de l'attribut fitness2 (fonction permettant l'évaluation).
	/// \param La seconde fonction fitness.
	void setFitness2(string fit2);
	
	/// \fn void setValeurApprochee(float)
	/// \brief Setteur de l'attribut valeurApprochee.
	/// \param La première valeur approchée.
	void setValeurApprochee(float val);
	
	/// \fn void setValeurApprochee2(float)
	/// \brief Setteur de l'attribut valeurApprochee2.
	/// \param La seconde valeur approchée.
	void setValeurApprochee2(float val);//MODIFICATION CDS : AJOUT DU SETTEUR A JUSTIFIER//
	
	/// \fn void setProbaCroisement(float)
	/// \brief Setteur de l'attribut probaCroisement.
	/// \param Une probabilité.
	void setProbaCroisement(float proba);
	
	/// \fn void setNombreGenerationMax(int)
	/// \brief Setteur de l'attribut nombreGenerationMax.
	/// \param Le nombre de génération à atteindre.
	void setNombreGenerationMax (int nbGen);
	

	/*LES TESTS*/	
	/// \fn void testArret(void)
	/// \brief Méthode qui appel testNombreGeneration() et testConvergence().
	/// \return Renvoie TRUE si l'algorithme peut continuer, FALSE sinon.
	bool testArret(string nomFichierSortie); //MODIFICATION CDS A JUSTIFIER (Population testArret())//

	/// \fn bool testNombreGeneration(void)
	/// \brief Méthode permettant de tester le nombre de génération
	/// \return Renvoie TRUE si le nombre de génération est inférieur au nombre de générations à atteindre, FALSE sinon.
	bool testNombreGeneration();
	
	/// \fn bool testConvergence(void)
	/// \brief Méthode permettant de tester si les score de plusieurs génération à la suite sont semblables (scores à +/- 1,5% identique).
	/// \return Renvoie TRUE si les générations convegent, FALSE sinon.
	bool testConvergence(string nomFichierSortie); //MODIFICATION CDS A JUSTIFIER (bool testConvergence())//
	
	/// \fn bool testPopulationRemplie(void)
	/// \brief Méthode permettant si une population est pleine.
	/// \return Renvoie TRUE si la population en cours n'est pas remplie, FALSE sinon.
	bool testPopulationRemplie(); 

	/* LES ALGORITHMES DE CREATION DE GENERATION*/
	/// \fn void evaluation(void)
	/// \brief Méthode permettant de faire l'évaluation des différents individus de la population.
	void evaluation(); //MODIFICATION CDS A JUSTIFIER (Population evaluation())//
	
	/// \fn void triPopulation(int)
	/// \brief Méthode appelant maximisation(int), minimisation(int) ou triValeur(int) selon le critère.
	/// \param int indiceScore est l'indice du tableau des scores
	void triPopulation (int indiceScore); //MODIFICATION CDS A JUSTIFIER (bool triPopulation(int indiceScore))//
	
	/// \fn void maximisation(int)
	/// \brief Méthode permettant de ranger les individus dans le vecteur ensemble de telle manière à ce que les individus soient rangés de celui ayant le plus gros score à celui ayant le plus faible.
	/// \param int indiceScore est l'indice du tableau des scores
	void maximisation(int indiceScpre); //MODIFICATION CDS : AJOUT DE LA METHODE A JUSTIFIER//
	
	/// \fn void minimisation(int)
	/// \brief Méthode permettant de ranger les individus dans le vecteur ensemble de telle manière à ce que les individus soient rangés de celui ayant le plus faible score à celui ayant le plus grand.
	/// \param int indiceScore est l'indice du tableau des scores
	void minimisation(int indiceScore); //MODIFICATION CDS : AJOUT DE LA METHODE A JUSTIFIER//
	
	/// \fn void triValeur(int)
	/// \brief Méthode permettant de ranger les individus dans le vecteur ensemble de telle manière à ce que les individus soient ranger l'individu ayant la plus petite différence avec la valeur à approcher à l'individu ayant la plus grande différence.
	/// \param int indiceScore est l'indice du tableau des scores
	void triValeur(int indiceScore); //MODIFICATION CDS : AJOUT DE LA METHODE A JUSTIFIER//

	/// \fn Individu* selectionner(int)
	/// \brief Méthode permettant de sélectionner des individus avec une certaine probabilité donnée par l'utilisateur. Les individus ayant un meilleurrang auront plus de chance d'être sélectionnés.
	/// \param int iCritere est l'indice utilisé pour le tableau des rangs.
	Individu* selectionner(int iCritere); //MODIFICATION CDS A JUSTIFIER (Individu Selectionner() + fonctionnement) //
	
	/// \fn void crossover(Individu, Individu)
	/// \brief Méthode permettant de générer deux nouveaux individus à partir de deux indiviuds de la génération en cours. Les nouveaux individus sont directement ajoutés au vecteur ensemble.
	/// \param Individu* Parent1 pointeur sur un premier individu.
	/// \param Individu* Parent2 pointeur sur un second individu.
	void crossover(Individu *Parent1, Individu *Parent2); //MODIFICATION CDS A JUSTIFIER (Population crossover (Individu Parent1, Individu parent2)//
	
	/// \fn Population creerGeneration(Population *P)
	/// \brief Méthode permettant de créer une nouvelle population
	/// \param Population* P
	Population* creerGeneration(Population *P); //MODIFICATION CDS A JUSTIFIER (Population creerGeneration(Population p)//
	
	/// \fn int nombreAlea(int, int)
	/// \brief Méthode permettant d'obtenir un nombre pseudo-aléatoire. Notament utilisé dans la méthode du crossover(Individu, Individu).
	/// \param int inf est la borne inférieure
	/// \param int sup est la borne supérieure
	int nombreAlea(int inf, int sup);
};


#endif
