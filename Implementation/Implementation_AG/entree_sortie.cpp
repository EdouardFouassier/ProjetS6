//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.cpp             ///
//////////////////////////////////////////////////

#include "entree_sortie.h"

using namespace std;

// Validation
//~ bool testCoherenceDonnees(string nomFichier) {
//~ }

bool estEntierPositif(string valeur){
    QString tmp=QString::fromStdString(valeur);
    bool ok;
    int val=tmp.toInt(&ok,10);
     if(ok && val==(int)val && val >= 0)
        return true;
    else {
		return false;
	}
}

bool estFloatPositif(string valeur){
    QString tmp=QString::fromStdString(valeur);
    bool ok;
    float val=tmp.toFloat(&ok);
    if (ok && val>0) { return true; }
    else { return false; }
	
}

bool estProbabilite(string valeur) {
    QString tmp=QString::fromStdString(valeur);
    bool ok;
    float val=tmp.toFloat(&ok);
    if(ok && (val <= 1) && (val >= 0)) {
    return true; }
    else {
			return false;
		}
}

bool estString(string valeur) {
	string s;
    regex e ("^-?\\d+");
    stringstream s2; 
    s2 << valeur;
    s2 >> s;
    if (regex_match (s,e)) return false;
    else return true;
}

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
			else { if ( ((fonction[i+1] == 'i') && (fonction[i+2] == 'n') && (fonction[i+3] == 'h')) || ((fonction[i+1] == 'q') && (fonction[i+2] == 'r') && (fonction[i+3] == 't')) ){ i += 3; }
			else { return false; }}}
		else { 
		if (fonction[i] == 't') {
			if ( ((fonction[i+1] == 'a') && (fonction[i+2] == 'n')) ) { i += 2; }
			else { if ( ((fonction[i+1] == 'a') && (fonction[i+2] == 'n') && (fonction[i+3] == 'h')) ){ i += 3; }
			else { return false; }}}
		else {
		if ((fonction[i] != 'x') && (fonction[i] != '1') && (fonction[i] != '2') && (fonction[i] != '3') && (fonction[i] != '4') && (fonction[i] != '5') && (fonction[i] != '6') && (fonction[i] != '7') &&
		(fonction[i] != '8') && (fonction[i] != '9') && (fonction[i] != '0') && (fonction[i] != '+') && (fonction[i] != '-') && (fonction[i] != ' ') && (fonction[i] != '/') && (fonction[i] != '*') && (fonction[i] != '%') && (fonction[i] != '^') && (fonction[i] != ',') && (fonction[i] != '(') && (fonction[i] != ')') ) { return false; }
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


    } { // 4/(3+x)
		double a = 1;
		int y = 0;
		int ouvrante2 = 0; int fermante2 = 0;
        char* fonction2 = new char[fonction.length() + 1];
		for(i = 0; i < size; i++) {	
		if (fonction[i] == '/'){ 
			if (fonction[i+1] == '(') { 
				ouvrante2++;
				i = i + 2;
				while (ouvrante2 != fermante2) {
					fonction2[y] = fonction[i];
					 if (fonction[i] == '(') { ouvrante++; }
					if (fonction[i] == ')') { fermante++; }
					i++;
					y++;
				}
				}
				else { if(fonction[i + 1] == '0') { return false;} else { return true; } }
		
		
		}
		}
		//calculfitness(fonction2, a);
		return true; }
}

// Lecture
//~ int* lireStat(FILE *F) {
//~ }

string* lireInfoRegen(string nomFichier){
	
	ifstream fichier(nomFichier.c_str(), ios::in);
	if(fichier) {
		string *tableauInfoRegen;										
		tableauInfoRegen = new string[10];								//On declare un tableau de string qu'on initialise a NULL
		string sautligne;
		getline(fichier,sautligne);										//On saute les deux premieres lignes du fichier
		getline(fichier,sautligne);
		fichier >> tableauInfoRegen[0] >> tableauInfoRegen[1]			//On lit les lignes du fichier que l'on stocke dans les cases du tableau, 0 -> Taux de crossover, 1 -> Taille de la population
				>> tableauInfoRegen[3] >> tableauInfoRegen[2]			//3 -> Nombre de generation max, 2 -> nombre de criteres 
				>> tableauInfoRegen[6] >> tableauInfoRegen[8]			//6 -> Fonction fitness1, 8 -> Critere Fonction fitness1
				>> tableauInfoRegen[4] >> tableauInfoRegen[7]			//4 -> Valeur approchée Fonction fitness1, 7 -> Fonction fitness2
				>> tableauInfoRegen[9] >> tableauInfoRegen[5];			//9 -> Critere Fonction fitness2, 5 -> Valeur approchée Fonction fitness1
		fichier.close();												//On ferme le fichier
		
		//~ printf("\n");		
		//~ cout << tableauInfoRegen[0] << " Taux de crossover " << endl;
		//~ cout << tableauInfoRegen[1] << " Taille de la population "<< endl;
		//~ cout << tableauInfoRegen[2] << " nombre de criteres " << endl;
		//~ cout << tableauInfoRegen[3] << " Noombre de generation max " << endl;
		//~ cout << tableauInfoRegen[4] << " Valeur approchée Fct1 " << endl;
		//~ cout << tableauInfoRegen[5] << " Valeur approchée Fct2 " << endl;
		//~ cout << tableauInfoRegen[6] << " Fct1 " << endl;
		//~ cout << tableauInfoRegen[7] << " Fct2 " << endl;
		//~ cout << tableauInfoRegen[8] << " Premier critere " << endl;
		//~ cout << tableauInfoRegen[9] << " Deuxieme critere " << endl;
		
		return tableauInfoRegen;										//On retourne le tableau
	}
	
	else {
		cerr << "Erreur ouverture fichier" << endl;
		return NULL;
	}
}

float* lireInitialisation (string nomFichier) {
	
	ifstream fichier(nomFichier.c_str(), ios::in);						//On ouvre le fichier en lecture

	if(fichier) {
		float *tableauInitialisation;		
		tableauInitialisation = new float[2];							
		
		fichier >> tableauInitialisation[0] >> tableauInitialisation[1];//On lit les lignes deux premieres lignes du fichier que l'on stocke dans les cases du tableau, 0 -> Taille des individus, 1 -> Taux de mutation
		fichier.close();												//On ferme le fichier
				
		//~ cout << tableauInitialisation[0] << " Taille Individu "<< endl;
		//~ cout << tableauInitialisation[1] << " Taux Mutation " << endl;
		
		return tableauInitialisation;									//On retourne le tableau
	}
	
	else {
		cerr << "Erreur ouverture fichier" << endl;
		return NULL;
	}
}

//~ int lireScoreIndividu(string nomFichierPopulation, int generation, int indice){
//~ }

// Ecriture
bool ecrireFichierDonnees(Interface *interface, string nomFichier) {
	
	ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);		//On ouvre le fichier en ecriture, son contenu est efface

    if(fichier)
	{
		fichier << interface->getTailleIndividu() <<  endl; 			//Taille Individu
		fichier << interface->getTauxMutation() <<  endl;				//Taux Mutation
		
		fichier << interface->getTauxCrossover() <<  endl;				//Taux Crossover
		fichier << interface->getTaillePopulation() <<  endl;			//Taille Population
		fichier << interface->getNbGenerationMax() <<  endl;			//Nombre de Generation Maximum
		
		if(interface->getCritereF2() == 0) {							//Nombre de criteres, 1 si pas de fonction fitness 2, sinon 2
				fichier << "1" <<  endl;
		}																	
		else { fichier << "2" <<  endl; }
		
		fichier << interface->getFonctionFitness1() <<  endl;			//Fonction Fitness 1
		fichier << interface->getCritereF1() <<  endl;					//Critère Fonction Fitness 1 : 1 -> Maximisation, 2 -> Minimisation, 3 -> Valeur approchée
		if(interface->getCritereF1() == 3) {							//Valeur approchee, si le critere n'a pas ete selectionne, il y a un blanc
				fichier << interface->getValeurApproxF1() <<  endl;
		}																	
		else { fichier << "" <<  endl; }
		
		fichier << interface->getFonctionFitness2() <<  endl;			//Fonction Fitness 2
		if(interface->getCritereF2() != 0) {							//Critère Fonction Fitness 2 : 1 -> Maximisation, 2 -> Minimisation, 3 -> Valeur approchée
				fichier << interface->getCritereF2() <<  endl;
		}																	
		else { fichier << "" <<  endl; }
		if(interface->getCritereF2() == 3) {							//Valeur approchée, si le critere n'a pas ete selectionne il y a un blanc
				fichier << interface->getValeurApproxF2() <<  endl;
		}																	
		else { fichier << "" <<  endl; }

		fichier.close();
		return true;
	}
	else {return false;}
}

bool ecrirePopulation(Population P, string nomFichier){
    ofstream fichier(nomFichier.c_str(), ios::out);

   if(fichier)
   {
       for(int i=0;i<P.getNombreIndividus();i++){
           for(int j=0;j<P.getEnsemble()[i].getTailleIndividu();j++){
               fichier << P.getEnsemble()[i].getChromosome()[j] << " ";
           }
           fichier << endl;
       }
       fichier << endl;
       fichier.close();
       return true;
   }
   else return false;

   return true;
}

//~ bool calculerEcrireStats(Population P, string nomFichierPopulation, string nomFichierStats){
//~ }
//~ bool ecrireFichier(string nomFichierSortie, string nomFichierParametr, string nomFichierStats){
//~ }
//~ bool ecrireLatex(string nomFichierSortie){
//~ }
//~ bool ecrirePostscript(string nomFichierSortie){
//~ }
//~ bool ecrireXfig(string nomFichierSortie){
//~ }
//~ bool ecrireUnScore(int score, File *F); //lui je sais plus si on l'a laissé dans le cahier des specs

//~ int main (){
	//~ float i = 3.2;
	//~ bool y = estProbabilite(i);
	//~ printf(y ? "true" : "false");
    //~ bool x = estParsable("+ 2 +  2");
    //~ printf(x ? "true" : "false");
//~ }

