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
#include <fstream>
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
//~ int* lireStat(FILE *F) {
//~ }

string* lireInfoRegen(string nomFichier);
float* lireInitialisation(string nomFichier);
//~ int lireScoreIndividu(string nomFichierPopulation, int generation, int indice);

// Ecriture
class Interface;
bool ecrireFichierDonnees(Interface *interface, string nomFichier);
//~ bool ecrirePopulation(Population P, string nomFichier);
//~ bool calculerEcrireStats(Population P, string nomFichierPopulation, string nomFichierStats);
//~ bool ecrireFichier(string nomFichierSortie, string nomFichierParametr, string nomFichierStats);
//~ bool ecrireLatex(string nomFichierSortie);
//~ bool ecrirePostscript(string nomFichierSortie);
//~ bool ecrireXfig(string nomFichierSortie);
//bool ecrireUnScore(int score, File *F); //lui je sais plus si on l'a laissé dans le cahier des specs


#endif
