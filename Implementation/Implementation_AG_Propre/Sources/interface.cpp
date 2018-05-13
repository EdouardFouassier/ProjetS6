//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///               interface.cpp                ///
//////////////////////////////////////////////////
#include "../Headers/interface.h"


string Interface::nomFichierSortie = "";
bool Interface::encours=0;

Interface::Interface() : QWidget()
{
    encours=false;

    fenetre=new QWidget();

    valider = new QPushButton("&Lancer");
    valider->setFont(QFont("Comic Sans MS", 10));

    quitter = new QPushButton("&Quitter");
    quitter->setFont(QFont("Comic Sans MS", 10));

    arreter = new QPushButton("&Arreter");
    arreter->setFont(QFont("Comic Sans MS", 10));

    parcourir = new QPushButton("...");
    parcourir->setFont(QFont("Comic Sans MS", 10));

    aide = new QPushButton("Aide");
    aide->setFont(QFont("Comic Sans MS", 10));

    nbGen=new QSpinBox;
    nbGen->setMaximum(1000);
    nbGen->setMinimum(1);
    nbGen->setValue(50);
    tailleIndi=new QSpinBox;
    tailleIndi->setMaximum(32);
    tailleIndi->setMinimum(1);
    tailleIndi->setValue(12);
    taillePop=new QSpinBox;
    taillePop->setMaximum(100);
    taillePop->setMinimum(2);
    taillePop->setValue(20);
    tauxMut=new QDoubleSpinBox;
    tauxMut->setMaximum(1);
    tauxMut->setMinimum(0);
    tauxMut->setDecimals(3);
    tauxMut->setValue(0.2);
    tauxCross=new QDoubleSpinBox;
    tauxCross->setMaximum(1);
    tauxCross->setMinimum(0);
    tauxCross->setDecimals(3);
    tauxCross->setValue(0.8);
    valeurF1=new QDoubleSpinBox;
    valeurF1->setMaximum(1000);
    valeurF1->setMinimum(-1000);
    valeurF1->setDecimals(3);
    valeurF2=new QDoubleSpinBox;
    valeurF2->setMaximum(1000);
    valeurF2->setMinimum(-1000);
    valeurF2->setDecimals(3);
    maxF1=new QRadioButton;
    maxF2=new QRadioButton;
    minF1=new QRadioButton;
    minF2=new QRadioButton;
    appF1=new QRadioButton;
    appF2=new QRadioButton;
    F1=new QLineEdit;
    F1->setText("2+x");
    F2=new QLineEdit;
    liensFichier=new QLineEdit;
    nomFichier=new QLineEdit;
    nbF=new QComboBox;
    nbF->addItem("1");
    nbF->addItem("2");

    checkXFig=new QCheckBox("xFig");
    checkPostScrit=new QCheckBox("PostScrit");
    checkLaTeX=new QCheckBox("LaTeX");

    labNbF=new QLabel("Nombre de fonctions fitness");
    labNbGen=new QLabel("Nombre de génération max");
    labTailleIndi=new QLabel("Taille des individus");
    labTaillePop=new QLabel("Taille de la population");
    labTauxMut=new QLabel("Taux de mutation");
    labTauxCross=new QLabel("Taux de crossover");
    labNomFichier=new QLabel("Nom du fichier de sortie");
    labMinF1=new QLabel("↓");
    labMinF2=new QLabel("↓");
    labMaxF1=new QLabel("↑");
    labMaxF2=new QLabel("↑");
    labAppF1=new QLabel("=");
    labAppF2=new QLabel("=");
    labParcourir=new QLabel("Entrer le fichier de paramètres :");




    layoutF1 = new QHBoxLayout();
    layoutF1->addWidget(F1);
    layoutF1->addWidget(labMinF1);
    layoutF1->addWidget(minF1);
    layoutF1->addWidget(labMaxF1);
    layoutF1->addWidget(maxF1);
    layoutF1->addWidget(labAppF1);
    layoutF1->addWidget(appF1);
    layoutF1->addWidget(valeurF1);

    layoutF2 = new QHBoxLayout();
    layoutF2->addWidget(F2);
    layoutF2->addWidget(labMinF2);
    layoutF2->addWidget(minF2);
    layoutF2->addWidget(labMaxF2);
    layoutF2->addWidget(maxF2);
    layoutF2->addWidget(labAppF2);
    layoutF2->addWidget(appF2);
    layoutF2->addWidget(valeurF2);

    groupF1=new QGroupBox();
    groupF1->setLayout(layoutF1);
    groupF2 = new QGroupBox();
    groupF2->setLayout(layoutF2);

    layoutParcourir=new QHBoxLayout();
    layoutParcourir->addWidget(liensFichier);
    layoutParcourir->addWidget(parcourir);

    layoutOut=new QHBoxLayout();
    layoutOut->addWidget(checkLaTeX);
    layoutOut->addWidget(checkPostScrit);
    layoutOut->addWidget(checkXFig);

    layoutdroitehaut = new QVBoxLayout();
    layoutdroitehaut->addWidget(labTauxCross);
    layoutdroitehaut->addWidget(tauxCross);
    layoutdroitehaut->addWidget(labTauxMut);
    layoutdroitehaut->addWidget(tauxMut);


    layoutdroitemilieu = new QVBoxLayout();
    layoutdroitemilieu->addLayout(layoutOut);
    layoutdroitemilieu->addWidget(labNomFichier);
    layoutdroitemilieu->addWidget(nomFichier);

    layoutdroitebas = new QVBoxLayout();
    layoutdroitebas->addWidget(labParcourir);
    layoutdroitebas->addLayout(layoutParcourir);

    layoutgauche = new QVBoxLayout();
    layoutgauche->addWidget(labNbF);
    layoutgauche->addWidget(nbF);
    layoutgauche->addWidget(groupF1);
    layoutgauche->addWidget(groupF2);
    layoutgauche->addWidget(labNbGen);
    layoutgauche->addWidget(nbGen);
    layoutgauche->addWidget(labTailleIndi);
    layoutgauche->addWidget(tailleIndi);
    layoutgauche->addWidget(labTaillePop);
    layoutgauche->addWidget(taillePop);

    layoutbas = new QHBoxLayout();
    layoutbas->addWidget(aide);
    layoutbas->addWidget(valider);
    layoutbas->addWidget(arreter);
    layoutbas->addWidget(quitter);


    mainLayout = new QGridLayout();
    mainLayout->addLayout(layoutgauche,0,0,5,1);
    mainLayout->addLayout(layoutdroitehaut,0,2,1,1);
    mainLayout->addLayout(layoutdroitemilieu,2,2,1,1);
    mainLayout->addLayout(layoutdroitebas,4,2,1,1);
    mainLayout->addLayout(layoutbas,5,0,1,3);

    QObject::connect(parcourir, SIGNAL(clicked()), this, SLOT(chercher()));
    QObject::connect(nbF, SIGNAL(currentIndexChanged(int)), this, SLOT(enableF2(int)));
    QObject::connect(appF1, SIGNAL(clicked(bool)), this, SLOT(afficherAppF1()));
    QObject::connect(appF2, SIGNAL(clicked(bool)), this, SLOT(afficherAppF2()));
    QObject::connect(minF1, SIGNAL(clicked(bool)), this, SLOT(cacherAppF1()));
    QObject::connect(maxF1, SIGNAL(clicked(bool)), this, SLOT(cacherAppF1()));
    QObject::connect(minF2, SIGNAL(clicked(bool)), this, SLOT(cacherAppF2()));
    QObject::connect(maxF2, SIGNAL(clicked(bool)), this, SLOT(cacherAppF2()));
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(connectLancer()));
    QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(connectQuitter()));
    QObject::connect(arreter, SIGNAL(clicked()), this, SLOT(connectArreter()));
    QObject::connect(aide, SIGNAL(clicked()), this, SLOT(connectAide()));

    groupF1->setTitle("Fitness1");
    groupF2->setTitle("Fitness2");

    this->setFixedSize(800,400);
    this->setLayout(mainLayout);
    minF1->setChecked(1);
    minF2->setChecked(1);
    checkLaTeX->setChecked(1);
    groupF2->setVisible(0);
    valeurF1->setVisible(0);
    valeurF2->setVisible(0);

    QPalette p;
    p.setBrush(QPalette::Active,QPalette::Window,QBrush(QColor(255,255,255,255)));
    this->setPalette(p);
    this->autoFillBackground();
}

Interface::Interface(string nom,string fichier) : Interface(){
	liensFichier->setText(QString::fromStdString(fichier));
	nomFichier->setText(QString::fromStdString(nom));
	connectLancer();
}

void * Interface::algoGenetique(void * arg){
	//~ cout<<"lolentree"<<endl;
	Population *p=new Population(lireInfoRegen(nomFichierSortie+"/"+nomFichierSortie+"_Parametres.txt")),*p_new=nullptr;
	
	int tailleI=p->getEnsemble()[0]->getTailleIndividu();
	//~ for(int i=0; i<p->getNombreIndividus();i++) {
        //~ cout<<"Individu "<<i<<" ";
		//~ for(int j=0;j<tailleI;j++){ cout<<p->getEnsemble()[i]->getChromosome()[j] << " / ";}
		//~ cout<<endl;
	//~ }
	//~ cout<<endl;
	//~ cout<<endl;
	
	cout<<p->getNumeroGeneration()<<endl;
	cout<<endl<<"ITERATION "<<0<<endl;
	cout<<p->getNumeroGeneration()<<endl;
	p->evaluation();
	cout<<p->getNumeroGeneration()<<endl;
	cout<<"evaluation faite"<<endl;
	ecrirePopulation(p,nomFichierSortie+"/"+nomFichierSortie+"_Populations.txt");
	cout<<"population écrite"<<endl;
	cout<<p->getNumeroGeneration()<<endl;
	calculerEcrireStats(p,nomFichierSortie+"/"+nomFichierSortie+"_Populations.txt",nomFichierSortie+"/"+nomFichierSortie+"_Stats.txt");
	ecrirePopulation(p,nomFichierSortie+"/"+nomFichierSortie+"_Populations.txt");
	cout<<"stat écrite"<<endl;
	for(int j=1;/*j<p->getNombreGenerationMax()*/p->testArret(nomFichierSortie) && encours==1;j++){            //tant que testArret
		

		cout<<"avant new pop"<<p->getNumeroGeneration()<<endl;
		p_new=new Population();
		cout<<"apres new pop"<<p->getNumeroGeneration()<<endl;
		p_new=p_new->creerGeneration(p);
		cout<<"apres creer"<<p->getNumeroGeneration()<<endl;
		//~ for(int i=0;i<p->getNombreIndividus() ;i++){           //créerGénération
			//~ p_new->crossover((p->selectionner(0)),(p->selectionner(0)));
            //~ std::cout<<"individu "<<i<<" créé"<<std::endl;
		//~ }
		//~ cout<<"creation de la nouvelle population"<<endl;
		delete p;
		cout<<"avant swap"<<p->getNumeroGeneration()<<endl;
		p=p_new;
		cout<<"apres swap"<<p->getNumeroGeneration()<<endl;
		cout<<"ancienne population = nouvelle population"<<endl;
		cout<<p->getNumeroGeneration()<<endl;
		cout<<endl<<"ITERATION "<<j<<endl;
		cout<<p->getNumeroGeneration()<<endl;
		p->evaluation();
		cout<<p->getNumeroGeneration()<<endl;
		cout<<"evaluation faite"<<endl;
		ecrirePopulation(p,nomFichierSortie+"/"+nomFichierSortie+"_Populations.txt");
		cout<<"population écrite"<<endl;
		cout<<p->getNumeroGeneration()<<endl;
		calculerEcrireStats(p,nomFichierSortie+"/"+nomFichierSortie+"_Populations.txt",nomFichierSortie+"/"+nomFichierSortie+"_Stats.txt");
		ecrirePopulation(p,nomFichierSortie+"/"+nomFichierSortie+"_Populations.txt");
		cout<<"stat écrite"<<endl;
        //~ for(int i=0; i<p->getNombreIndividus();i++) {
            //~ cout<<"Individu "<<i<<endl;
            //~ for(int y=0;y<tailleI;y++){ 
                //~ cout<<p->getEnsemble()[i]->getChromosome()[y] << " / ";

            //~ }
            //~ cout<<endl;
        //~ }
	}
	string param=nomFichierSortie+"/"+nomFichierSortie+"_Parametres.txt";
	ecrireFichier(nomFichierSortie,param,p);
	//~ ecrireLatex(nomFichierSortie,p);
	cout<< "FIN" <<endl;
	encours=0;
	p->setNumeroGeneration(0);
	delete p;
	return NULL;
	//QProcess::startDetached(QString::fromStdString("pdflatex "+nomFichierSortie+"/"+nomFichierSortie+".tex"));
	//QDesktopServices::openUrl(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() +QString::fromStdString( "/"+nomFichierSortie+"/"+nomFichierSortie+".pdf")));
	
}

bool Interface::getEnCours(){
    return encours;
}

void Interface::enableF2(int s){
    if(s==0) groupF2->setVisible(0);
    else groupF2->setVisible(1);
}

void Interface::cacherAppF1(){
    valeurF1->setVisible(0);
}

void Interface::afficherAppF1(){
    valeurF1->setVisible(1);
}

void Interface::cacherAppF2(){
    valeurF2->setVisible(0);
}

void Interface::afficherAppF2(){
    valeurF2->setVisible(1);
}

void Interface::connectAide(){
    QDesktopServices::openUrl(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/try.pdf"));
}

void Interface::connectArreter(){
    if(encours!= 0){
		//~ int reponse=QMessageBox::question(this,"Confirmer?" ,"L'algorithme n'est pas fini.\nEtes vous sure?\nVous pouvez sauvegarder le resultat actuel.", QMessageBox::Yes | QMessageBox::No | QMessageBox::Save);
        //~ if (reponse == QMessageBox::Yes)
        //~ {
            //~ QMessageBox::information(this, "Fermeture", "A bientot");
            //~ close();
        //~ }
        //~ if (reponse == QMessageBox::Save){
			 //~ QMessageBox::information(this, "Fermeture", "Resultat sauvegarder.\nA bientot");
            //~ close();
		//~ }
        int reponse=QMessageBox::question(this,"Confirmer" ,"Arrêter enregistrera le resultat actuel.\nL'algorithme n'est pas fini.\nEtes-vous sûr?", QMessageBox::Yes | QMessageBox::No );
        if (reponse == QMessageBox::Yes)
        {
            //QMessageBox::information(this, "Fermeture", "A bientôt");
            //~ Interface i(this);
            //~ i.show();
            //~ close();
            encours=0;
        }
    }
    else{
        int reponse=QMessageBox::question(this,"C'est facheux" ,"L'algorithme n'a pas été lancé.\nEtes-vous sûr?", QMessageBox::Yes | QMessageBox::No );
        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::information(this, "Fermeture", "A bientôt");
            close();
        }
    }

}

void Interface::connectQuitter(){
    if(encours!=0){
        int reponse=QMessageBox::question(this,"Confirmer" ,"Quitter perdra la progression actuel de l'algorithme.\nEtes-vous sûr?", QMessageBox::Yes | QMessageBox::No );
        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::information(this, "Fermeture", "A bientôt");
            close();
        }
    }
    else{
        QMessageBox::information(this, "Fermeture", "A bientôt");
        close();
    }
}

void Interface::connectLancer(){
	bool nomcorrect,sortiecorrect;
	if(encours==0){
		int reponse=QMessageBox::question(this,"Confirmer" ,"Etes-vous sûr de vouloir lancer ?", QMessageBox::Yes | QMessageBox::No );
		if (reponse == QMessageBox::Yes)
		{
			if(liensFichier->text().length()==0){
				fonctionFitness1=F1->text().toUtf8().constData();
				fonctionFitness2=F2->text().toUtf8().constData();
				taillePopulation=taillePop->value();
				tailleIndividu=tailleIndi->value();
				nbGenerationMax=nbGen->value();
				if(maxF1->isChecked()) critereF1=1;
				else {
					if(minF1->isChecked()) critereF1=2;
					else critereF1=3;
				}
				if(nbF->currentIndex()==1){
					if(maxF2->isChecked()) critereF2=1;
					else {
						if(minF2->isChecked()) critereF2=2;
						else critereF2=3;
					}
				}
				else critereF2=0;
				tauxMutation=tauxMut->value();
				tauxCrossover=tauxCross->value();
				valeurApproxF1=valeurF1->value();
				valeurApproxF2=valeurF2->value();
				latex=checkLaTeX->isChecked();
				xFig=checkXFig->isChecked();
				postScript=checkPostScrit->isChecked();
				nomFichierSortie=nomFichier->text().toUtf8().constData();
			
				//~ cout<<getFonctionFitness1()<<endl;
				//~ cout<<getFonctionFitness2()<<endl;
				//~ cout<<getNomFichierSortie()<<endl;
				//~ cout<<getTaillePopulation()<<endl;
				//~ cout<<getTailleIndividu()<<endl;
				//~ cout<<getNbGenerationMax()<<endl;
				//~ cout<<getCritereF1()<<endl;
				//~ cout<<getCritereF2()<<endl;
				//~ cout<<getTauxMutation()<<endl;
				//~ cout<<getTauxCrossover()<<endl;
				//~ cout<<getValeurApproxF1()<<endl;
				//~ cout<<getValeurApproxF2()<<endl;
				//~ cout<<getLatex()<<endl;
				//~ cout<<getXFig()<<endl;
				//~ cout<<getPostScript()<<endl;
				
				/*** TEST ECRITURE LECTURE ***/
				//~ ecrireFichierDonnees(this, "TestFiles/DonneesInitialesTest.txt");
				//~ lireInitialisation("TestFiles/DonneesInitialesTest.txt");
				//~ lireInfoRegen("TestFiles/DonneesInitialesTest.txt");
				//~ lireScoreIndividu("TestFiles/ScoreIndividuTest.txt", 3, 5);
				//~ cout << testCoherenceDonnees("TestFiles/DonneesInitialesTest.txt") << endl;
/*		
				cout<< estEntierPositif("2")<<endl;
				cout<< estEntierPositif("2.5")<<endl;
				cout<< estEntierPositif("-221452")<<endl;
				cout<< estEntierPositif("2a")<<endl;
				cout<< estEntierPositif("a2")<<endl;
				cout<<endl;
		
				cout<< estFloatPositif("2")<<endl;
				cout<< estFloatPositif("2.5")<<endl;
				cout<< estFloatPositif("-221452")<<endl;
				cout<< estFloatPositif("2a")<<endl;
				cout<< estFloatPositif("a2")<<endl;
				cout<<endl;
		
				cout<< estProbabilite("0.2")<<endl;
				cout<< estProbabilite("2.5")<<endl;
				cout<< estProbabilite("-221452")<<endl;
				cout<< estProbabilite("2a")<<endl;
				cout<< estProbabilite("a2")<<endl;
*/				
				try{
					if(nomFichierSortie.length()==0) {
						throw string("Erreur de nom fichier de sortie. \n"); 
						nomcorrect=false;
					}
					else {
						if(QFileInfo(QString::fromStdString(nomFichierSortie)).exists())
						{
							throw string("Erreur ! Nom fichier déjà pris. \n"); 
							nomcorrect=false;
						}
						else{
							ecrireFichierDonnees(this,nomFichierSortie+"_Parametres.txt");
							nomcorrect=true;
						}
					}
					
					
					if(latex || xFig || postScript) sortiecorrect=true;
					else {
						throw string("Erreur de format de sortie. \n");
						sortiecorrect=false;
					}
					if(nomcorrect && sortiecorrect && testCoherenceDonnees(nomFichierSortie+"_Parametres.txt")) {
					QMessageBox::information(this,"Bravo !","Le programme a demarré avec succès.");
					QProcess creaDir,Move,CHMOD;
					creaDir.startDetached(QString::fromStdString("mkdir "+nomFichierSortie));
					Move.startDetached(QString::fromStdString("mv "+nomFichierSortie+"_Parametres.txt"+" "+nomFichierSortie+"/"));
					CHMOD.startDetached(QString::fromStdString("chmod +xwr "+nomFichierSortie+"/"+nomFichierSortie+"_Parametres.txt"));	
					encours=1;
					pthread_t  tid;
					pthread_create(&tid,NULL,&algoGenetique,nullptr);
					}
					
				}
				catch(string const& e){
					if(QFileInfo(QString::fromStdString(nomFichierSortie+"_Parametres.txt")).exists())
						QProcess::startDetached(QString::fromStdString("rm "+nomFichierSortie+"_Parametres.txt"));
					QMessageBox::information(this,"ERROR",QString::fromStdString(e));
				}
			}
			else {
				nomFichierSortie=nomFichier->text().toUtf8().constData();
				
				try{
					if(nomFichierSortie.length()==0) {
						throw string("Erreur de nom fichier de sortie \n"); 
						nomcorrect=false;
					}
					else {
						if(QFileInfo(QString::fromStdString(nomFichierSortie)).exists())
						{
							throw string("Erreur ! Nom fichier déjà pris \n"); 
							nomcorrect=false;
						}
						else{
							nomcorrect=true;
						}
					}
					
					if(nomcorrect && testCoherenceDonnees(liensFichier->text().toUtf8().constData())){
						QMessageBox::information(this,"Bravo !","Le programme est prêt a être lancé.");
						QProcess creadDir,cp,CHMOD;
						creadDir.startDetached(QString::fromStdString("mkdir "+nomFichierSortie));
						cp.startDetached(QString::fromStdString("cp "+string(liensFichier->text().toUtf8().constData())+" "+nomFichierSortie+"/"+nomFichierSortie+"_Parametres.txt"));
						CHMOD.startDetached(QString::fromStdString("chmod +xwr "+nomFichierSortie+"/"+nomFichierSortie+"_Parametres.txt"));
						encours=1;
						pthread_t  tid;
						pthread_create(&tid,NULL,&algoGenetique,nullptr);
					}
				}
				catch(string const& e){
					QMessageBox::information(this,"ERROR",QString::fromStdString(e));
				}
			}
		}
	}
	else QMessageBox::information(this,"Attention","Le programme a déjà demarré");
		
}

void Interface::chercher(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Tous les fichiers (*.*)"));
    dialog.setViewMode(QFileDialog::List);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setLabelText(QFileDialog::LookIn, "Regardez dans :");
    dialog.setLabelText(QFileDialog::FileName, "Nom de fichier :");
    dialog.setLabelText(QFileDialog::FileType, "Type de fichiers :");
    dialog.setLabelText(QFileDialog::Accept, "Selectionner");
    dialog.setLabelText(QFileDialog::Reject, "Annuler");
    QStringList fileNames;
    if(dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        liensFichier->setText(fileNames.at(0));
        fileNames.removeAt(0);
    }
    else
        dialog.reject();
}


string Interface::getFonctionFitness1(){
	return fonctionFitness1;
}

string Interface::getFonctionFitness2(){
	return fonctionFitness2;
}

string Interface::getNomFichierSortie(){
	return nomFichierSortie;
}

	
int Interface::getTaillePopulation(){
	return taillePopulation;
}

int Interface::getTailleIndividu(){
    return tailleIndividu;
}

int Interface::getNbGenerationMax(){
    return nbGenerationMax;
}

int Interface::getCritereF1(){
    return critereF1;
}

int Interface::getCritereF2(){
    return critereF2;
}

float Interface::getTauxMutation(){
    return tauxMutation;
}

float Interface::getTauxCrossover(){
    return tauxCrossover;
}

float Interface::getValeurApproxF1(){
    return valeurApproxF1;
}

float Interface::getValeurApproxF2(){
    return valeurApproxF2;
}

bool Interface::getLatex(){
    return latex;
}

bool Interface::getXFig(){
    return xFig;
}

bool Interface::getPostScript(){
    return postScript;
}

