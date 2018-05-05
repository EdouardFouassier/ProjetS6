//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.h               ///
//////////////////////////////////////////////////


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
bool testCoherenceDonnees(string nomFichier);

bool estEntierPositif(string valeur);
bool estFloatPositif(string valeur);

bool estProbabilite(string valeur);

bool estString(string valeur);

bool estParsable(string fonction);

// Lecture
float* lireStat(FILE *F);	//Dans le cds c'est un int mais comme les scores seront des flottants bah...

string* lireInfoRegen(string nomFichier);
float* lireInitialisation(string nomFichier);
float* lireScoreIndividu(string nomFichierPopulation, int generation, int indice);

// Ecriture
class Interface;
bool ecrireFichierDonnees(Interface *interface, string nomFichier);
class Population;
bool ecrirePopulation(Population P, string nomFichier);
bool calculerEcrireStats(Population P, string nomFichierPopulation, string nomFichierStats);
bool ecrireFichier(string nomFichierSortie, string nomFichierParametr, string nomFichierStats);
bool ecrireLatex(string nomFichierSortie);
bool ecrirePostscript(string nomFichierSortie);
bool ecrireXfig(string nomFichierSortie);
//~ bool ecrireUnScore(int score, File *F);  //Alors... Elle est dans le cds mais... Askip elle est useless, Wallah c'est un bruit qui court dans la téci


#endif
