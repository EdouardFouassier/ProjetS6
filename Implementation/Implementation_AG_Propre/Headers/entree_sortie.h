//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.h               ///
//////////////////////////////////////////////////
/// \author Groupe Sujet 4
/// \file entree_sortie.h

#ifndef __ENTREE_SORTIE_H
#define __ENTREE_SORTIE_H

#include <string>
#include <stdlib.h>
#include <iostream>  
#include <typeinfo>
#include "interface.h"
#include "génération.h"
#include "tinyexpr/tinyexpr.h"
#include <regex>
#include <sstream>
#include <fstream>

using namespace std;

// Validation
/// \fn bool testCoherenceDonnees(string)
/// \brief Appels de différentes fonctions afin de vérifier que les valeurs données par l'utilisateurs sont valides
/// \param string nomFichier
/// \return TRUE si toutes les données sont valides, FALSE sinon.
bool testCoherenceDonnees(string nomFichier);

/// \fn bool estEntierPositif(string)
/// \brief Fonction permettant de déterminer si la valeur passée en paramètre est un entier positif ou non.
/// \param string valeur
/// \return TRUE si la valeur passé en argument est un entier positif, renvoie FALSE sinon.
bool estEntierPositif(string valeur);

/// \fn bool estFloatPositif(string)
/// \brief Fonction permettant de déterminer si la valeur passée en paramètre est un nombre décimal positif ou non.
/// \param string valeur
/// \return Renvoie TRUE si la valeur passé en argument est un nombre décimal positif, renvoie FALSE sinon.
bool estFloatPositif(string valeur);

/// \fn bool estProbabilite(string)
/// \brief Fonction permettant de déterminer si la valeur passée en paramètre est un nombre décimal compris entre 0 et 1 (inclus) ou non.
/// \param string valeur
/// \return Renvoie TRUE si la valeur passé en argument est un nombre décimal compris dans l'intervalle [0; 1], renvoie FALSE sinon.
bool estProbabilite(string valeur);

/// \fn bool estString(string)
/// \brief Fonction permettant de déterminer si la valeur passée en paramètre est une chaine de caractères.
/// \param string valeur
/// \return Renvoie TRUE si la valeur passé en argument est une chaine de caractères, renvoie FALSE sinon.
bool estString(string valeur);

/// \fn bool estParsable(string)
/// \brief Fonction permettant de déterminer si la chaine de caractère passée en paramètre peut être lue par le parser qui effectue le calcul.
/// \param string fonction
/// \return Renvoie TRUE si la chaine de caractère est correcte, renvoie FALSE sinon.
bool estParsable(string fonction);

// Lecture
/// \fn float* lireStat(FILE*)
/// \brief Fonction permettant de d'obtenir toutes les statistiques de la génération en cours.
/// \param FILE* F est un pointeur sur le fichier des statistiques
/// \return Renvoie un tableau de float contenant l'ensemble des statistique pour la génération en cours.
float* lireStat(FILE *F);	//Dans le cds c'est un int mais comme les scores seront des flottants bah...

/// \fn string* lireInfoRegen(string)
/// \brief Fonction permettant de 
/// \param string nomFichier 
/// \return Renvoie un tableau de chaines de caractères permettant de créer une nouvelle génération.
string* lireInfoRegen(string nomFichier);

/// \fn string* lireInfoRegen(string)
/// \brief Fonction permettant de 
/// \param string nomFichier 
/// \return Renvoie un tableau de chaines de caractères permettant de créer une nouvelle génération.
float* lireInitialisation(string nomFichier);
float* lireScoreIndividu(string nomFichierPopulation, int generation, int indice);

// Ecriture
class Interface;
bool ecrireFichierDonnees(Interface *interface, string nomFichier);
class Population;
bool ecrirePopulation(Population *P, string nomFichier);
bool calculerEcrireStats(Population *P, string nomFichierPopulation, string nomFichierStats);
bool ecrireFichier(string nomFichierSortie, string nomFichierParametr, string nomFichierStats);
bool ecrireLatex(string nomFichierSortie);
bool ecrirePostscript(string nomFichierSortie);
bool ecrireXfig(string nomFichierSortie);
//~ bool ecrireUnScore(int score, File *F);  //Alors... Elle est dans le cds mais... Askip elle est useless, Wallah c'est un bruit qui court dans la téci


#endif
