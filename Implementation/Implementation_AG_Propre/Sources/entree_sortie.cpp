/////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///              entree_sortie.cpp             ///
//////////////////////////////////////////////////

#include "../Headers/entree_sortie.h"

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
	while(i != 13) { 
			//fichier >> donnees;cout<<donnees<<endl;
		getline(fichier, donnees); 
		//cout<<i<<" "<<donnees<<" "<<donnees.length()<<endl;
		   //donnees.erase(donnees.length(),1);
		if (i == 0) {
			x = estEntierPositif(donnees);
			if(!x || stoi(donnees)>32 || stoi(donnees)<1)x=false;
			if(!x ){
				throw string("Erreur taille individu \n");
				return false;
			}
		}
        if (i == 1) {
			x = estProbabilite(donnees);
			if(!x || stoi(donnees)>1 || stoi(donnees)<0)x=false;
			if(!x){
				throw string("Erreur taux de mutation \n");
				return false;
			}
		}
        if (i == 2) {
			x = estProbabilite(donnees);
			if(!x || stoi(donnees)>1 || stoi(donnees)<0)x=false;
			if(!x){
				throw string("Erreur taux de crossover \n");
				return false;
			}
		}
        if (i == 3) {
			x = estEntierPositif(donnees);
			if(!x || stoi(donnees)>100 || stoi(donnees)<2)x=false;
			if(!x){
				throw string("Erreur taille population \n");
				return false;
			}
		}
        if (i == 4) {
			x = estEntierPositif(donnees);
			if(!x || stoi(donnees)>1000 || stoi(donnees)<1)x=false;
			if(!x){
				throw string("Erreur nombre de génération \n");
				return false;
			}
		}
        if (i == 5) { 
			x = estEntierPositif(donnees);
			if(!x || stoi(donnees)!=1 && stoi(donnees)!=2 )x=false;
			fitness2 = donnees;
			if(!x){throw string("Erreur nombre de critère \n");
				return false;
			}
		}
        if (i == 6) { 
			x = estParsable(" "+donnees+" ");
			if(!x || donnees.length()==0){
				throw string("Erreur fitness1 \n");
				return false;
			}
		}
        if (i == 7) { 
			x = estEntierPositif(donnees);
			if(!x || stoi(donnees)!=1 && stoi(donnees)!=2 && stoi(donnees)!=3) x=false;
			critere = donnees;
			if(!x){
				throw string("Erreur critère fitness1 \n");
				return false;
			}
		}
        if (i == 8 && critere == "3") {
			x = estFloatPositif(donnees);
			if(!x || stoi(donnees)>1000 || stoi(donnees)<-1000)x=false;
			if(!x){
				throw string("Erreur valeur approchée\n fitness1 \n");
				return false;
			}
		}
        if(fitness2 == "2")
        {
				if (i == 9) {
					x = estParsable(donnees);
					if(!x || donnees.length()==0){
						throw string("Erreur fitness2 \n");
						return false;
					}
				}
				if (i == 10){
					x = estEntierPositif(donnees);
					if(!x || stoi(donnees)!=1 && stoi(donnees)!=2 && stoi(donnees)!=3) x=false;
					critere = donnees;
					if(!x){
						throw string("Erreur critère fitness2 \n");
						return false;
					}
				}
				if (i == 11 && critere == "3"){
					x = estFloatPositif(donnees);
					if(!x || stoi(donnees)>1000 || stoi(donnees)<-1000)x=false;
					if(!x){
						throw string("Erreur valeur approchée\n fitness2 \n");
						return false;
					}
				}
		}
		if (i == 12) {
			if(donnees.length()!=3 || (donnees[0]!='0' && donnees[0]!='1') || (donnees[1]!='0' && donnees[1]!='1') 
				|| (donnees[2]!='0' && donnees[2]!='1')){
				throw string("Erreur formats de sortie");
				return false;
			}
		}
        i++;
           
	}
	fichier.close(); 
	return true;
    }
    else { //cerr << "Erreur ouverture fichier \n" << endl; return false;
		throw string("Erreur fichier de paramètre introuvable \n");
		}

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
		//calculfitness(" " + fonction2 + " ", a)
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
				if (calculfitness(fonction2, a) == 0) { delete[] fonction2;return false; }
				
				}
				else { if(fonction[i + 1] == '0') { delete[] fonction2;return false;} }
		
		i = temp;
		while (y != 0) { fonction2[y] = 0; y--; }
		ouvrante2 = 0; fermante2 = 0;
		}
		
		}
		delete[] fonction2;
		return true; }
}

// Lecture
float* lireStat(FILE *F) {
	
	if(F) {
		float *tableauStats;
		tableauStats = new float[3];
		char tableauStatsChar[100];
		string moyScores1 = "", minScores1 = "", maxScores1 = "", moyScores2 = "", minScores2 = "", maxScores2 = "";
		fgets (tableauStatsChar , 100 , F);
		if(tableauStatsChar[0]=='G') fgets (tableauStatsChar , 100 , F);
		//~ fputs (tableauStatsChar, stdout);
		int cpt = 0;
		for (int i = 0; tableauStatsChar[i] != '\n'; i++) {
			//cout << tableauStatsChar[i] ;
			if (tableauStatsChar[i] == ' ') { cpt++;}
			else {
				if (cpt == 1) { moyScores1 += tableauStatsChar[i]; }
				if (cpt == 2) { minScores1 += tableauStatsChar[i]; }
				if (cpt == 3) { maxScores1 += tableauStatsChar[i]; }
				if (tableauStatsChar[i]=='P'){
					tableauStats[0] = stof(moyScores1);
					tableauStats[1] = stof(minScores1);
					tableauStats[2] = stof(maxScores1);
					return tableauStats;
				}
				if (cpt == 4) { moyScores2 += tableauStatsChar[i]; }
				if (cpt == 5) { minScores2 += tableauStatsChar[i]; }
				if (cpt == 6) { maxScores2 += tableauStatsChar[i]; }
			}
		}
		float *tableauStatss=new float[6];
		tableauStatss[0] = stof(moyScores1);
		tableauStatss[1] = stof(minScores1);
		tableauStatss[2] = stof(maxScores1);
		tableauStatss[3] = stof(moyScores2);
		tableauStatss[4] = stof(minScores2);
		tableauStatss[5] = stof(maxScores2);
		delete[] tableauStats;
		return tableauStatss;
		
		//~ cout << tableauStats[0] << endl;
		//~ cout << tableauStats[1] << endl;
		//~ cout << tableauStats[2] << endl;
	}
	else {
		cerr << "Erreur ouverture fichier" << endl;
		return NULL;
	}
}

string* lireInfoRegen(string nomFichier){
	
	ifstream fichier(nomFichier.c_str(), ios::in);						//On ouvre le fichier en lecture
	if(fichier) {
		string *tableauInfoRegen;										
		tableauInfoRegen = new string[11];								//On declare un tableau de string de onze cases
		string sautligne;												//On cree une variable string qui nous servira a sauter des lignes
		getline(fichier,sautligne);										//On saute les deux premieres lignes du fichier
		getline(fichier,sautligne);
		getline(fichier,sautligne);
		tableauInfoRegen[0] = sautligne;								//tauxCrossver				
		getline(fichier,sautligne);
		tableauInfoRegen[1] = sautligne;								//taillePopulation;
		getline(fichier,sautligne);
		tableauInfoRegen[2] = sautligne;								//nombreGenerationMax;
		getline(fichier,sautligne);
		tableauInfoRegen[3] = sautligne;								//nombreCriteres;
		getline(fichier,sautligne);
		tableauInfoRegen[6] = sautligne;								//fonctionFitness1;
		getline(fichier,sautligne);
		tableauInfoRegen[4] = sautligne;								//Critere Fonction fitness1
		getline(fichier,sautligne);
		tableauInfoRegen[8] = sautligne;								//valeurFonctionFitness1;
		getline(fichier,sautligne);
		tableauInfoRegen[7] = sautligne;								//fonctionFitness2;
		getline(fichier,sautligne);
		tableauInfoRegen[5] = sautligne;								//critereFonctionFitness2;
		getline(fichier,sautligne);
		tableauInfoRegen[9] = sautligne;					//valeurFonctionFitness2;
		tableauInfoRegen[10] = nomFichier;
		//~ fichier >> tableauInfoRegen[0] >> tableauInfoRegen[1]			//On lit les lignes du fichier que l'on stocke dans les cases du tableau, 0 -> Taux de crossover, 1 -> Taille de la population
				//~ >> tableauInfoRegen[2] >> tableauInfoRegen[3]			//2 -> Nombre de generation max, 3 -> Nombre de criteres 
				//~ >> tableauInfoRegen[6] >> tableauInfoRegen[4]			//6 -> Fonction fitness1, 4 -> Critere Fonction fitness1
				//~ >> tableauInfoRegen[8] >> tableauInfoRegen[7]			//8 -> Valeur approchée Fonction fitness1, 7 -> Fonction fitness2
				//~ >> tableauInfoRegen[5] >> tableauInfoRegen[9];			//5 -> Critere Fonction fitness2, 9 -> Valeur approchée Fonction fitness1
				
				
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


float* lireScoreIndividu(string nomFichierPopulation, int generation, int indice){
		
	ifstream fichier(nomFichierPopulation.c_str(), ios::in);			//On ouvre le fichier en lecture
	
	if(fichier) {
		float* scoreIndividu;												
		scoreIndividu = new float[1];									//On cree un tableau d'entiers de une case
		string sautligne;												//On cree une variable string qui nous servira a sauter des lignes
		
		for(int ligneGeneration = 1; ligneGeneration < generation; ligneGeneration++)
		{	
			getline(fichier,sautligne);									//La boucle permet de sauter les lignes pour aller jusqu'a la generation qui nous interesse
			getline(fichier,sautligne);									//On saute deux lignes a chaque fois car la premiere contient le premier score et la deuxieme contient le deuxieme score des individus d'une meme population
		}
																		
		for(int indiceIndividu = 0; indiceIndividu <= indice; indiceIndividu++) { fichier >> scoreIndividu[0]; }	//La boucle permet d'aller jusqu'au score de l'individu donné en indice, comme on ecrit tout les scores lus dans la même variable, seul le dernier est conservé
		getline(fichier,sautligne);										//Permet de lire le reste de la ligne et donc de passer a la ligne suivante									
		fichier >> sautligne;											//On lit le premier la premiere chaine de caractère jusqu'au séparateur (soit un espace, soit un retour chariot)
		if (sautligne == "PasCritere") { 								//Si la premiere chaine est egale a "PasCritere" c'est que les individus ne sont evalué que par rapport a un seul critere 
			//~ cout << scoreIndividu[0] << " Score 1 " << endl;
			return scoreIndividu; 										//On retourne donc le tableau avec le score de l'individu
		}
		else {															//Sinon cela signifie que les individus sont evalués par rapport a deux critères, sautligne contient donc un score
			float* scoresIndividu;										
			scoresIndividu = new float[2];								//On cree donc un deuxieme tableau de deux cases
			scoresIndividu[0] = scoreIndividu[0];						//On affecte a la premiere case du nouveau tableau le score stocké dans l'unique case du premier tableau
			delete[] scoreIndividu;										//On supprime le premier tableau puisqu'on ne s'en sert plus
			if (indice == 0) { scoresIndividu[1] = stoi(sautligne); }	//Si le score que l'on cheche est celui du premier individu, on affecte a la deuxieme case du tableau la valeur contenue dans "sautligne"
			else { 														//Sinon on parcourt tout les scores jusqu'a celui de l'individu qui nous interesse
				for(int indiceIndividu = 1; indiceIndividu <= indice; indiceIndividu++) { fichier >> scoresIndividu[1]; } 
			}
			//~ cout << scoresIndividu[0] << " Score 1 " << endl;
			//~ cout << scoresIndividu[1] << " Score 2 " << endl;
			return scoresIndividu;										//On retourne le tableau contenant les deux critères 0 -> score avec le premier critère, 1 -> score avec le deuxième critère 
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
		fichier << interface->getLatex() << interface->getPostScript() << interface->getXFig() << endl;	//Valeur des booleens pour savoir sous quel(s) format(s) le fichier de sortie doit être ecrit
																										//1 si on souhaite l'ecrire en Latex, 0 sinon; 1 si on souhaite l'ecrire en PostScript, 0 sinon; 1 si on souhaite l'ecrire en XFig, 0 sinon
		fichier.close();
		return true;
	}
	else { return false; }
}

bool ecrirePopulation(Population *P, string nomFichier){ //LES TEST SONT ENCORE A FAIRE
	ofstream fichier(nomFichier.c_str(), ios::out | ios::app);

   if(fichier)
   {
	   //cout<<"check1"<<endl;
       for(int i=0;i<P->getNombreIndividus()-1;i++){
		   fichier << P->getEnsemble()[i]->getScore(0) << " ";
		   //cout<<"check5"<<endl;
           //for(int j=0;j<P.getEnsemble()[i].getTailleIndividu();j++){
               //fichier << P.getEnsemble()[i].getChromosome()[j] << " ";
           //}
       }
       fichier << P->getEnsemble()[P->getNombreIndividus()-1]->getScore(0) << endl;
       //cout<<"check2"<<endl;
       if(P->getNombreCriteres() == 2)
       {
			for(int i=0;i<P->getNombreIndividus()-1;i++){
			fichier << P->getEnsemble()[i]->getScore(1) << " ";
		   //cout<<"check4"<<endl;
			//for(int j=0;j<P.getEnsemble()[i].getTailleIndividu();j++){
				//fichier << P.getEnsemble()[i].getChromosome()[j] << " ";
			//}
			}
       fichier << P->getEnsemble()[P->getNombreIndividus()-1]->getScore(1) << endl;
       //cout<<"check3"<<endl;
	   }
	   else { fichier << "PasCritere" << endl; }
       fichier.close();
       return true;
   }
   else return false;

   return true;
}


bool calculerEcrireStats(Population *P, string nomFichierPopulation, string nomFichierStats){
	
	ofstream fichierStats(nomFichierStats.c_str(), ios::out | ios::app);	//On ouvre le fichier en ecriture, son contenu est efface
	
	if(fichierStats) {
		if(P->getNumeroGeneration()==1) fichierStats<< "Generation Moyenne1 Minimum1 Maximum1 Moyenne2 Minimum2 Maximum2"<<endl;
		float *val,*min,*max,*moy;
		//~ cout << P->getNumeroGeneration() << endl;
		val=lireScoreIndividu(nomFichierPopulation, P->getNumeroGeneration(), 0);
		//~ cout << val[0] << endl;
		if(P->getNombreCriteres()==2){ //
			min=new float[2];
			max=new float[2];
			moy=new float[2];
			min[1]=val[1];
			max[1]=val[1];
			moy[1]=val[1];
		}
		else{
			min=new float[1];
			max=new float[1];
			moy=new float[1];
		}
		min[0]=val[0];
		max[0]=val[0];
		moy[0] =val[0];
		delete[] val;
		
		for(int i=1;i<P->getNombreIndividus();i++){
			//~ cout << moy[0] << " " << min[0] << " " << max[0] << endl;
			
			val=lireScoreIndividu(nomFichierPopulation, P->getNumeroGeneration(), i);
			if(min[0]>val[0]) min[0]=val[0];
			if(max[0]<val[0]) max[0]=val[0];
			moy[0]+=val[0];
			if(P->getNombreCriteres()==2){
				//~ cout << moy[0] << " " << min[0] << " " << max[0] << endl;
				if(min[1]>val[1]) min[1]=val[1];
				if(max[1]<val[1]) max[1]=val[1];
				moy[1]+=val[1];
			}
			//~ cout<<endl;
			
			delete[] val;
		}
		moy[0]=(moy[0]-max[0]-min[0])/(P->getNombreIndividus()-2);
		fichierStats <<P->getNumeroGeneration()<<" "<< moy[0] << " " << min[0] << " " << max[0] ;
		if(P->getNombreCriteres() == 2) {							//Si les individus dont evalué par rapport a deux critères
				moy[1]=(moy[1]-max[1]-min[1])/(P->getNombreIndividus()-2);
				fichierStats <<" "<< moy[1] << " " << min[1] << " " << max[1]<< endl ;
			}
		else {
			fichierStats << " PasCritere"<< endl ;					//Si les individus ne sont evalués qu'avec un seul critère, alors on ecrit "PasCritere" 
		}
		delete[] min;
		delete[] max;
		delete[] moy;
		fichierStats.close();
		//~ cout<<endl;											//On ferme le fichier
		return true;
	}
	else {
		cerr << "Erreur ouverture fichier statistiques" <<endl;
		return false;
	}
	
}

bool ecrireFichier(string nomFichierSortie, string nomFichierParametre, string nomFichierStats, Population *P){
 ifstream fichierParam(nomFichierParametre.c_str(), ios::in);      //On ouvre le fichier en lecture

 if(fichierParam) {
  string line;
  for(int i=0;i<13;i++)
  {
   getline(fichierParam,line);
  }
  cout<<line[0]<<line[1]<<line[2]<<endl;
  if(line[0]=='1') { ecrireLatex(nomFichierSortie,P); }
  if(line[1]=='1') { if(line[0]=='1') { ecrirePostscript(nomFichierSortie); }
       else { ecrireLatex(nomFichierSortie,P); ecrirePostscript(nomFichierSortie); 
        string nomFichierEnd = "rm "+nomFichierSortie+"/"+nomFichierSortie+".tex"; system(nomFichierEnd.c_str()); }
       }
  if(line[2]=='1') { ecrireXfig(nomFichierSortie); }
 }
}

bool ecrireLatex(string nomFichierSortie,Population *P){
	string nomFichierEnd = nomFichierSortie+"/"+nomFichierSortie+".tex";
	ofstream fichierLatex(nomFichierEnd.c_str(), ios::out | ios::trunc);
	
	if(fichierLatex) {
		fichierLatex << "\\documentclass[a4paper,11pt]{article}\n\\usepackage[utf8]{inputenc}\n\\usepackage[T1]{fontenc}\n\\usepackage[french]{babel}\n\\usepackage[right=2.5cm, left=2.5cm, bottom=4cm, top=3cm]{geometry}\n\\usepackage{textcomp}\n\\usepackage{graphicx}\n\\usepackage{mathtools,amssymb,amsthm}\n\\usepackage{lmodern,fixltx2e}\n\\usepackage{multirow}\n\\usepackage{array}\n\\usepackage{longtable}\n\\usepackage{fancybox}\n\\usepackage{pgfplots}\n" << endl;
		fichierLatex << "\\title{\\huge "<< nomFichierSortie <<"}\n\\date{}" << endl;
		fichierLatex << "\\begin{document}" << endl;
		fichierLatex << "	\\maketitle\n" << endl;
		fichierLatex << "	Voici les résultats données par le programme : \\\\\\\\" << endl;
		fichierLatex << "	Les données initiales sont :" << endl;
		fichierLatex << "	\\begin{itemize}" << endl;
		float* tabInitialisation = lireInitialisation(nomFichierSortie+"/"+nomFichierSortie+"_Parametres.txt");
		fichierLatex << "		\\item Taille des individus : " << tabInitialisation[0] << endl;
		fichierLatex << "		\\item Taux de mutation : " << tabInitialisation[1] << endl;
		
	
		string* tabInfoRegen = lireInfoRegen(nomFichierSortie+"/"+nomFichierSortie+"_Parametres.txt");
		fichierLatex << "		\\item Taux de crossover : " << tabInfoRegen[0] << endl;
		fichierLatex << "		\\item Taille de la population : " << tabInfoRegen[1] << endl;
		fichierLatex << "		\\item Nombre de génération maximum : " << tabInfoRegen[2] << endl;
		fichierLatex << "		\\item Nombre de critères : " << tabInfoRegen[3] << endl;
		fichierLatex << "		\\item Fonction Fitness 1 : " << tabInfoRegen[6] << endl;
		fichierLatex << "		\\item Critère Fonction Fitness 1 : "; if(tabInfoRegen[4] == "1"){fichierLatex << "Maximisation";} else{ if(tabInfoRegen[4] == "2") {fichierLatex << "Minimisation";} else {fichierLatex << "Valeur approchée";}} fichierLatex << endl;
		if(tabInfoRegen[4] == "3") { fichierLatex << "		\\item Valeur approchée : " << tabInfoRegen[8] << endl; }
		if(tabInfoRegen[3] == "2") {
		fichierLatex << "		\\item Fonction Fitness 2 : " << tabInfoRegen[7] << endl;
		fichierLatex << "		\\item Critère Fonction Fitness 2  : "; if(tabInfoRegen[5] == "1"){fichierLatex << "Maximisation";} else{ if(tabInfoRegen[5] == "2") {fichierLatex << "Minimisation";} else {fichierLatex << "Valeur approchée";}} fichierLatex << endl;
		if(tabInfoRegen[5] == "3") { fichierLatex << "		\\item Valeur approchée : " << tabInfoRegen[9] << endl; }
		}
		fichierLatex << "	\\end{itemize}\n" << endl;
		
		fichierLatex << "	\\begin{center}\\begin{tikzpicture}[yscale=1.5,xscale=1.5]" << endl;
		fichierLatex << "	\\begin{axis}[ no markers, axis lines = left, xlabel = $Generations$, ylabel = {$Moyennes$}, legend pos=outer north east, legend style={font=\\fontsize{8}{9}\\selectfont}, title={\\begin{Bcenter} Evolution des scores par rapport au critère 1 \\end{Bcenter} }]" << endl;
		fichierLatex << "		\\addplot table [x=Generation,y=Moyenne1]{" << nomFichierSortie+"_Stats.txt" << "};" << endl;
		fichierLatex << "		\\addplot table [x=Generation,y=Minimum1]{" << nomFichierSortie+"_Stats.txt" << "};" << endl;
		fichierLatex << "		\\addplot table [x=Generation,y=Maximum1]{" << nomFichierSortie+"_Stats.txt" << "};" << endl;
		fichierLatex << "		\\legend{Moyenne Critere1,Minimum Critere1, Maximum Critere1}" << endl;
		fichierLatex << "	\\end{axis}" << endl;
		fichierLatex << "	\\end{tikzpicture}\\end{center}" << endl;
			
		if(tabInfoRegen[3] == "2") {
			fichierLatex << "	\\begin{center}\\begin{tikzpicture}[yscale=1.5,xscale=1.5]" << endl;
			fichierLatex << "	\\begin{axis}[ no markers, axis lines = left, xlabel = $Generations$, ylabel = {$Moyennes$}, legend pos=outer north east, legend style={font=\\fontsize{8}{9}\\selectfont}, title={\\begin{Bcenter} Evolution des scores par rapport au critère 2 \\end{Bcenter} }]" << endl;
			fichierLatex << "		\\addplot table [x=Generation,y=Moyenne2]{" << nomFichierSortie+"_Stats.txt" << "};" << endl;
			fichierLatex << "		\\addplot table [x=Generation,y=Minimum2]{" << nomFichierSortie+"_Stats.txt" << "};" << endl;
			fichierLatex << "		\\addplot table [x=Generation,y=Maximum2]{" << nomFichierSortie+"_Stats.txt" << "};" << endl;
			fichierLatex << "		\\legend{Moyenne Critere2,Minimum Critere2, Maximum Critere2}" << endl;
			fichierLatex << "	\\end{axis}" << endl;
			fichierLatex << "	\\end{tikzpicture}\\end{center}" << endl;
		}	
		Individu solutions[10]; 
		int cpt=0;
		if(P->getNombreCriteres()==1){
			for(int i=0;i<stoi(tabInfoRegen[1])&&cpt<10;i++){
				//cout<<P->getEnsemble()[i]->getRang(0)<<endl;
				if(P->getEnsemble()[i]->getRang(0)) {
					solutions[cpt]=*P->getEnsemble()[i];
					cpt++;
				}
			}
		}else{
			for(int i=0;i<stoi(tabInfoRegen[1])&&cpt<10;i++){
				//cout<<P->getEnsemble()[i]->getRang(0)<<endl;
				if(cpt<5){
					if(P->getEnsemble()[i]->getRang(0)==1){
						solutions[cpt]=*P->getEnsemble()[i];
						cpt++;
					}
				}
				else {
					if(P->getEnsemble()[i]->getRang(1)==1){
						solutions[cpt]=*P->getEnsemble()[i];
						cpt++;
					}
				}
			}
		}
		
	
		fichierLatex << "	Le meilleur individu est : \\\\\n" << endl;
		fichierLatex << "	\\begin{center}\\begin{tabular}{|c|c|}" << endl;
		fichierLatex << "	\\hline Solution & Valeur 1\\\\"<<endl;

		for(int i=0;i<cpt;i++){
			fichierLatex << "	\\hline ";
			for(int j=0;j<tabInitialisation[0];j++){
				fichierLatex << solutions[i].getChromosome()[j];
			}
			fichierLatex << " & "<< solutions[i].decodage(solutions[i]) <<"\\\\"<<endl;
		}
		fichierLatex << "	\\hline"<<endl<<"	\\end{tabular}\\end{center}\n"<<endl;
		
		fichierLatex << "	\\begin{center}\\begin{longtable}{|>{\\centering}m{2cm}|>{\\centering}m{2cm}|>{\\centering}m{2cm}"; if(tabInfoRegen[3] == "2") { fichierLatex << "|>{\\centering}m{2cm}|>{\\centering}m{2cm}|>{\\centering}m{2cm}|>{\\centering\\arraybackslash}m{2cm}|}" << endl; } else { fichierLatex << "|>{\\centering\\arraybackslash}m{2cm}|}" << endl; }
		fichierLatex << "	\\hline Générations & Moyenne Critère 1 & Minimum Critère 1 & Maximum Critère 1"; if(tabInfoRegen[3] == "2") { fichierLatex << " & Moyenne Critère 2 & Minimum Critère 2 & Maximum Critère 2 \\\\" << endl; } else { fichierLatex << " \\\\" << endl;}
		float *tabStats;
		string nomFichierStats = nomFichierSortie+"/"+nomFichierSortie+"_Stats.txt";
		FILE *F;
		F = fopen(nomFichierStats.c_str(),"r");
		for(int i = 1; i <= P->getNumeroGeneration()-1; i++) {
			tabStats = lireStat(F);
			fichierLatex << "	\\hline " << i << " & " << tabStats[0] << " & " << tabStats[1] << " & " << tabStats[2]; if(tabInfoRegen[3] == "2") { fichierLatex << " & " << tabStats[3] << " & " << tabStats[4] << " & " << tabStats[5] << "\\\\" << endl; } else { fichierLatex << "\\\\" << endl; }
			delete[] tabStats;
		}
		delete[] tabInitialisation;
		delete[] tabInfoRegen;
		fclose(F);
		
		fichierLatex << "	\\hline" << endl;
		fichierLatex << "	\\end{longtable}\\end{center}" << endl;
		
		fichierLatex << "\\end{document}" << endl;
		
		fichierLatex.close();
		return true;
	}
	
	else {
		cerr << "Erreur ouverture fichier latex" << endl;
		return false;
	}
}

bool ecrirePostscript(string nomFichierSortie) {
 
 string latexToDvi = "latex "+nomFichierSortie+"/"+nomFichierSortie+".tex";
 
 if(system(latexToDvi.c_str())) {
  string dviToPostscrit = "dvips "+nomFichierSortie+"/"+nomFichierSortie+".dvi"+" -o "+nomFichierSortie+"/"+nomFichierSortie+".ps";
  if(system(dviToPostscrit.c_str())) { return true; }
  else {
   cerr << "Erreur dviToPostscrit" << endl;
   return false;
  }
 }
 else {
  cerr << "Erreur latexToDvi" << endl;
  return false;
 } 
}

bool ecrireXfig(string nomFichierSortie){
	cout<<"Ouai ouai inchalla ici on va voir si on ecrit le XFig de ses mort parce que walla sa darone elle est pas hallal ."<<endl;
}
//~ bool ecrireUnScore(int score, File *F); //Alors... Elle est dans le cds mais... Askip elle est useless, Wallah c'est un bruit qui court dans la téci

//~ int main (){
	//~ float i = 3.2;
	//~ bool y = estProbabilite(i);
	//~ printf(y ? "true" : "false");
    //~ bool x = estParsable("+ 2 +  2");
    //~ printf(x ? "true" : "false");
//~ }

