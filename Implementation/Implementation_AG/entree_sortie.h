//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.h               ///
//////////////////////////////////////////////////


#ifndef __ENTREE_SORTIE_H
#define __ENTREE_SORTIE_H

#include <string.h>
#include <stdlib.h>
using namespace std;

// Validation
//~ bool testCoherenceDonnees(string nomFichier) {
//~ }

bool estEntierPositif(auto valeur) {
    if (valeur >= 0) {
        return true;
    }
    else {
        return false;
    }
}

//~ bool estFloatPositif(auto valeur) {
//~ }

//~ bool estProbabilite(auto valeur) {
//~ }

//~ bool estString(auto valeur) {
//~ }

//~ bool estParsable(string fonction) {
//~ }

// Lecture
//~ int* lireStat(FILE *F) {
//~ }

#endif
