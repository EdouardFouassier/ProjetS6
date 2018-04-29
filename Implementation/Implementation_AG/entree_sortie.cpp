//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.cpp             ///
//////////////////////////////////////////////////

#include "entree_sortie.h"

using namespace std;

// Validation
//~ bool testCoherenceDonnees(string nomFichier) {

	//~ int i = 0;
	//~ ifstream fichier(nomFichier, ios::in);
	//~ string donnees;
	//~ bool x;
	//~ int fitness2 = 0;
	//~ if(fichier)  
    //~ { 
	//~ while(i != 12) { 
			
		   //~ getline(fichier, donnees); 
           //~ if (i == 0) { x = estEntierPositif(donnees); }
           //~ if (i == 1) { x = estProbabilite(donnees); }
           //~ if (i == 2) { x = estProbabilite(donnees); }
           //~ if (i == 3) { x = estEntierPositif(donnees); }
           //~ if (i == 4) { x = estEntierPositif(donnees); }
           //~ if (i == 5) { x = estEntierPositif(donnees); }
           //~ if (i == 6) { x = estParsable(donnees); }
           //~ if (i == 7) { x = estEntierPositif(donnees); }
           //~ if (i == 8) { if (!donnees.empty()) { x = estEntierPositif(donnees); } }
           //~ if (i == 9) { if (!donnees.empty()) { x = estParsable(donnees); fitness2 = 1; } }
           //~ if ((i == 10) && (fitness2 == 1)) { x = estEntierPositif(donnees); }
           //~ if (i == 11) { if (!donnees.empty()) { x = estEntierPositif(donnees); } }
           //~ if (x == false) { return false; }
           //~ i++;
           
	//~ }
	//~ fichier.close(); 
	//~ return true;
    //~ }
    //~ else { cerr << "Erreur ouverture fichier \n" << endl; return false;}

//~ }


bool testCoherenceDonnees(string nomFichier) {

	int i = 0;
	ifstream fichier(nomFichier, ios::in);
	string donnees, finChaine, critere, fitness2;
	bool x;
	if(fichier)  
    { 
	while(i != 12) { 
			fichier >> donnees;
		   getline(fichier, finChaine); 
           if (i == 0) { x = estEntierPositif(donnees); }
           if (i == 1) { x = estProbabilite(donnees); }
           if (i == 2) { x = estProbabilite(donnees); }
           if (i == 3) { x = estEntierPositif(donnees); }
           if (i == 4) { x = estEntierPositif(donnees); }
           if (i == 5) { x = estEntierPositif(donnees); fitness2 = donnees;}
           if (i == 6) { x = estParsable(donnees); }
           if (i == 7) { x = estEntierPositif(donnees); critere = donnees;}
           if (i == 8 && critere == "3") { x = estFloatPositif(donnees); }
           if(fitness2 == "2")
           {
				if (i == 9) { x = estParsable(donnees); }
				if (i == 10){ x = estEntierPositif(donnees); critere = donnees;}
				if (i == 11 && critere == "3"){ x = estFloatPositif(donnees); }
		   }
				if (x == false) { return false; }
           i++;
           
	}
	fichier.close(); 
	return true;
    }
    else { cerr << "Erreur ouverture fichier \n" << endl; return false;}

}


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
    tmp.toFloat(&ok);
    if (ok) { return true; }
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
	
	//~ if (estString(fonction) == false) { return false; }
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


    } { // (2/(4+2))
		double a = 1;
		int temp = 0;
		int y = 0;
		
		int ouvrante2 = 0; int fermante2 = 0;
        char* fonction2 = new char[fonction.length() + 1];
		for(i = 0; i < size; i++) {	
		if (fonction[i] == '/'){ 
			
			temp = i + 1;
			if (fonction[i+1] == '(') { 
				fonction2[y] = '(';
				y++;
				ouvrante2++;
				i = i + 2;
				while (ouvrante2 != fermante2) {
					
					
					fonction2[y] = fonction[i];
					if (fonction[i] == '(') { ouvrante2++; }
					if (fonction[i] == ')') { fermante2++; }
					
					i++;
					y++;
				}
				if (calculfitness(fonction2, a) == 0) { return false; }
				
				}
				else { if(fonction[i + 1] == '0') { return false;} }
		
		i = temp;
		while (y != 0) { fonction2[y] = 0; y--; }
		ouvrante2 = 0; fermante2 = 0;
		}
		
		}
		
		return true; }
}

// Lecture
//~ int* lireStat(FILE *F) {
//~ }

string* lireInfoRegen(string nomFichier){
	
	ifstream fichier(nomFichier.c_str(), ios::in);						//On ouvre le fichier en lecture
	if(fichier) {
		string *tableauInfoRegen;										
		tableauInfoRegen = new string[10];								//On declare un tableau de string de dix cases
		string sautligne;												//On cree une variable string qui nous servira a sauter des lignes
		getline(fichier,sautligne);										//On saute les deux premieres lignes du fichier
		getline(fichier,sautligne);
		fichier >> tableauInfoRegen[0] >> tableauInfoRegen[1]			//On lit les lignes du fichier que l'on stocke dans les cases du tableau, 0 -> Taux de crossover, 1 -> Taille de la population
				>> tableauInfoRegen[2] >> tableauInfoRegen[3]			//2 -> Nombre de generation max, 3 -> Nombre de criteres 
				>> tableauInfoRegen[6] >> tableauInfoRegen[4]			//6 -> Fonction fitness1, 4 -> Critere Fonction fitness1
				>> tableauInfoRegen[8] >> tableauInfoRegen[7]			//8 -> Valeur approchée Fonction fitness1, 7 -> Fonction fitness2
				>> tableauInfoRegen[5] >> tableauInfoRegen[9];			//5 -> Critere Fonction fitness2, 9 -> Valeur approchée Fonction fitness1
		fichier.close();												//On ferme le fichier
		
		//~ printf("\n");		
		//~ cout << tableauInfoRegen[0] << " Taux de crossover " << endl;
		//~ cout << tableauInfoRegen[1] << " Taille de la population "<< endl;
		//~ cout << tableauInfoRegen[2] << " Nombre de generation max " << endl;
		//~ cout << tableauInfoRegen[3] << " nombre de criteres " << endl;
		//~ cout << tableauInfoRegen[4] << " Premier critere " << endl;
		//~ cout << tableauInfoRegen[5] << " Deuxieme critere " << endl;
		//~ cout << tableauInfoRegen[6] << " Fct1 " << endl;
		//~ cout << tableauInfoRegen[7] << " Fct2 " << endl;
		//~ cout << tableauInfoRegen[8] << " Valeur approchée Fct1 " << endl;
		//~ cout << tableauInfoRegen[9] << " Valeur approchée Fct2 " << endl;
		
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
		tableauInitialisation = new float[3];							//On cree un tableau de floattant de trois cases
		
		fichier >> tableauInitialisation[0] >> tableauInitialisation[1];//On lit les lignes deux premieres lignes du fichier que l'on stocke dans les cases du tableau, 0 -> Taille des individus, 1 -> Taux de mutation
		string sautligne;
		getline(fichier,sautligne);										//On saute les trois lignes suivante du fichier	pour aller jusqu'a la valeur du nombre de criteres				
		getline(fichier,sautligne);
		getline(fichier,sautligne);
		getline(fichier,sautligne);
		fichier >> tableauInitialisation[2];							//On lit la sixieme ligne que l'on stocke dans la derniere case du tableau, 3 -> Nombre de criteres 
		fichier.close();												//On ferme le fichier
				
		//~ cout << tableauInitialisation[0] << " Taille Individu "<< endl;
		//~ cout << tableauInitialisation[1] << " Taux Mutation " << endl;
		//~ cout << tableauInitialisation[2] << " Nombre de critères " << endl;
		
		return tableauInitialisation;									//On retourne le tableau
	}
	
	else {
		cerr << "Erreur ouverture fichier" << endl;
		return NULL;
	}
}


int* lireScoreIndividu(string nomFichierPopulation, int generation, int indice){
		
	ifstream fichier(nomFichierPopulation.c_str(), ios::in);			//On ouvre le fichier en lecture
	
	if(fichier) {
		int* scoreIndividu;												
		scoreIndividu = new int[1];										//On cree un tableau d'entiers de une case
		string sautligne;												//On cree une variable string qui nous servira a sauter des lignes
		
		for(int ligneGeneration = 0; ligneGeneration < generation-1; ligneGeneration++)
		{	
			getline(fichier,sautligne);									//La boucle permet de sauter les lignes pour aller jusqu'a la generation qui nous interesse
			getline(fichier,sautligne);									//On saute deux lignes a chaque fois car la premiere contient le premier score et la deuxieme contient le deuxieme score des individus d'une meme population
		}
																		
		for(int indiceIndividu = 0; indiceIndividu < indice; indiceIndividu++) { fichier >> scoreIndividu[0]; }
		getline(fichier,sautligne);										
		fichier >> sautligne;
		if (sautligne == "PasCritere") { 
			//~ cout << scoreIndividu[0] << " Score 1 " << endl;
			return scoreIndividu; 
		}
		else {
			int* scoresIndividu;
			scoresIndividu = new int[2];
			scoresIndividu[0] = scoreIndividu[0];
			delete[] scoreIndividu;
			if (indice == 0) { scoresIndividu[1] = stoi(sautligne); }
			else { 
				for(int indiceIndividu = 1; indiceIndividu < indice; indiceIndividu++) { 
					fichier >> scoresIndividu[1]; 
				} 
			}
			//~ cout << scoresIndividu[0] << " Score 1 " << endl;
			//~ cout << scoresIndividu[1] << " Score 2 " << endl;
			return scoresIndividu;
		}
	}
	else {
		cerr << "Erreur ouverture fichier" << endl;
		return NULL;
	}
}


// Ecriture
bool ecrireFichierDonnees(Interface *interface, string nomFichier) {
	
	ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);		//On ouvre le fichier en ecriture, son contenu est efface

    if(fichier) {
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
	else { return false; }
}

bool ecrirePopulation(Population P, string nomFichier){ //LES TEST SONT ENCORE A FAIRE
    ofstream fichier(nomFichier.c_str(), ios::out);

   if(fichier)
   {
       for(int i=0;i<P.getNombreIndividus()-1;i++){
		   fichier << P.getEnsemble()[i]->getScore(0) << " ";
		   
           //for(int j=0;j<P.getEnsemble()[i].getTailleIndividu();j++){
               //fichier << P.getEnsemble()[i].getChromosome()[j] << " ";
           //}
       }
       fichier << P.getEnsemble()[P.getNombreIndividus()-1]->getScore(0) << endl;
       
       if(P.getNombreCriteres() == 2)
       {
			for(int i=0;i<P.getNombreIndividus()-1;i++){
			fichier << P.getEnsemble()[i]->getScore(1) << " ";
		   
			//for(int j=0;j<P.getEnsemble()[i].getTailleIndividu();j++){
				//fichier << P.getEnsemble()[i].getChromosome()[j] << " ";
			//}
			}
       fichier << P.getEnsemble()[P.getNombreIndividus()-1]->getScore(1) << endl;
       
	   }
	   else { fichier << "PasCritere" << endl; }
       fichier.close();
       return true;
   }
   else return false;

   return true;
}

//~ bool calculerEcrireStats(Population P, string nomFichierPopulation, string nomFichierStats){
//~ }
//~ bool ecrireFichier(string nomFichierSortie, string nomFichierParametre, string nomFichierStats){
//~ }
//~ bool ecrireLatex(string nomFichierSortie){
//~ }
//~ bool ecrirePostscript(string nomFichierSortie){
//~ }
//~ bool ecrireXfig(string nomFichierSortie){
//~ }
//~ bool ecrireUnScore(int score, File *F); //Alors... Elle est dans le cds mais... Askip elle est useless, Wallah c'est un bruit qui court dans la téci

//~ int main (){
	//~ float i = 3.2;
	//~ bool y = estProbabilite(i);
	//~ printf(y ? "true" : "false");
    //~ bool x = estParsable("+ 2 +  2");
    //~ printf(x ? "true" : "false");
//~ }

