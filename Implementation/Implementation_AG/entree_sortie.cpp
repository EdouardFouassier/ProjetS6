//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.cpp             ///
//////////////////////////////////////////////////
#include "entree_sortie.h"

using namespace std;

// Validation
//~ bool testCoherenceDonnees(string nomFichier) {
//~ }

bool estEntierPositif(auto valeur) {
	
	 if(valeur==(int)valeur && valeur >= 0)
        return true;
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

int main () {
	float i = 3.2;
    bool x = estEntierPositif(i);
    printf(x ? "true" : "false");
}
