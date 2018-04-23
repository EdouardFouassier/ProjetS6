//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.cpp             ///
//////////////////////////////////////////////////
#include "entree_sortie.h"

using namespace std;

// Validation
//~ bool testCoherenceDonnees(string nomFichier) {
//~ }

bool estEntierPositif(auto valeur){
	
	 if(valeur==(int)valeur && valeur >= 0)
        return true;
    else {
		return false;
	}
}

//~ bool estFloatPositif(auto valeur){
	
	
//~ }

//~ bool estProbabilite(auto valeur) {
//~ }

//~ bool estString(auto valeur) {
//~ }

bool estParsable(string fonction) {

	int size=fonction.size();
	int i = 0;
	int ouvrante = 0;
	int fermante = 0;
	
	//test du bon parenthésage//
	for(i = 0; i < size; i++) {		
		if (fonction[i] == '(') { ouvrante++; }
		if (fonction[i] == ')') { fermante++; }
		if (fermante > ouvrante) { return false; }
	}
	if(ouvrante != fermante) { return false; }
	else {
	
	//test sur l'unicité de la variable et de la bonne orthographe des fonctions(qu'il n'y est ai que x comme variable)//
	for(i = 0; i < size; i++) {	
		if (fonction[i] == 'a'){ 
			if ( ((fonction[i+1] == 'b') && (fonction[i+2] == 's')) ) { i += 2; }
			else { if ( ((fonction[i+1] == 's') && (fonction[i+2] == 'i') && (fonction[i+3] == 'n')) || ((fonction[i+1] == 't') && (fonction[i+2] == 'a') && (fonction[i+3] == 'n')) || ((fonction[i+1] == 'c') && (fonction[i+2] == 'o') && (fonction[i+3] == 's')) ) { i += 3; }
			else { if ( ((fonction[i+1] == 't') && (fonction[i+2] == 'a') && (fonction[i+3] != 'n') && (fonction[i+4] == '2')) ) {i += 4; }
			else { return false; }}}}
		else {
		if (fonction[i] == 'c') {
			if ((fonction[i+1] == 'o') && (fonction[i+2] == 's')) { i += 2; }
			else { if ( ((fonction[i+1] == 'e') && (fonction[i+2] == 'i') && (fonction[i+3] == 'l')) || ((fonction[i+1] == 'o') && (fonction[i+2] == 's') && (fonction[i+3] == 'h')) ) { i += 3; }
			else { return false; }}}
		else {
		if (fonction[i] == 'e') {
			if ( ((fonction[i+1] == 'x') && (fonction[i+2] == 'p')) ) { i += 2; }
			else { return false; }}	
		else {
		if (fonction[i] == 'f') {
			if ( ((fonction[i+1] == 'l') && (fonction[i+2] == 'o') && (fonction[i+3] == 'o') && (fonction[i+4] == 'r')) ) { i += 4; }
			else { return false; }}	
		else {	
		if (fonction[i] == 'l') {
			if ( ((fonction[i+1] == 'n')) ) { i += 1; }
			else { if ( ((fonction[i+1] == 'o') && (fonction[i+2] == 'g')) ) { i += 2; }
			else { if ( ((fonction[i+1] == 'o') && (fonction[i+2] == 'g') && (fonction[i+3] == '1') && (fonction[i+4] == '0')) ) { i += 4; }
			else { return false; }}}}
		else {	
		if (fonction[i] == 'p') {
			if ( ((fonction[i+1] == 'o') && (fonction[i+2] == 'w')) ) { i += 2; }
			else { return false; }}	
		else {	
		if (fonction[i] == 's') {
			if ( ((fonction[i+1] == 'i') && (fonction[i+2] == 'n')) ) { i += 2; }
			else { if ( ((fonction[i+1] == 'i') && (fonction[i+2] == 'n') && (fonction[i+3] == 'h') || ((fonction[i+1] == 'q') && (fonction[i+2] == 'r')) && (fonction[i+3] == 't')) ){ i += 3; }
			else { return false; }}}
		else { 
		if (fonction[i] == 't') {
			if ( ((fonction[i+1] == 'a') && (fonction[i+2] == 'n')) ) { i += 2; }
			else { if ( ((fonction[i+1] == 'a') && (fonction[i+2] == 'n') && (fonction[i+3] == 'h')) ){ i += 3; }
			else { return false; }}}
		else {
		if ((fonction[i] != 'x') && (fonction[i] != '1') && (fonction[i] != '2') && (fonction[i] != '3') && (fonction[i] != '4') && (fonction[i] != '5') && (fonction[i] != '6') && (fonction[i] != '7') &&
		(fonction[i] != '8') && (fonction[i] != '9') && (fonction[i] != '0') && (fonction[i] != '+') && (fonction[i] != '-') && (fonction[i] != ' ') && (fonction[i] != '/') && (fonction[i] != '*') && (fonction[i] != '%') && (fonction[i] != '^') && (fonction[i] != ',')) { return false; }
		}}}}}}}}	
	}
	
	//test sur la bonne utilisation des opérandes (pas de vide apres un '+' ou pas deux '+' d'affilé par exemple)//
	if ((fonction[0] == '+') || (fonction[0] == '-') || (fonction[0] == '/') || (fonction[0] == '*') || (fonction[0] == '%') || (fonction[0] == '^') || (fonction[0] == ',')){ return false; }
	for(i = 0; i < size; i++) {	
		if ((fonction[i] == '+') || (fonction[i] == '-') || (fonction[i] == '/') || (fonction[i] == '*') || (fonction[i] == '%') || (fonction[i] == '^') || (fonction[i] == ',')){
			if ((fonction[i+1] == '+') || (fonction[i+1] == '-') || (fonction[i+1] == '/') || (fonction[i+1] == '*') || (fonction[i+1] == '%') || (fonction[i+1] == '^') || (fonction[i+1] == ',')) { return false; }
			if ((fonction[i+1] == ' ') && (fonction[i+2] == ' ')) { return false; }
			if ((fonction[i-1] == ' ') && (fonction[i-2] == ' ')) { return false; }
	}
	}

	
	} { return true; }
}

// Lecture
//~ int* lireStat(FILE *F) {
//~ }

int main (){
	//~ float i = 3.2;
    bool x = estParsable("+ 2 +  2");
    printf(x ? "true" : "false");
}
