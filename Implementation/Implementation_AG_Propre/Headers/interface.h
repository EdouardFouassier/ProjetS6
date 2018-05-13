//////////////////////////////////////////////////
/// Projet S6 - Sujet 4 - Algorithme Génétique ///
///                interface.h                 ///
//////////////////////////////////////////////////
/// \author Groupe Sujet 4
/// \file interface.h

#ifndef INTERFACE_H
#define INTERFACE_H
#include <unistd.h>
#include <string>
#include <iostream>
#include <QProgressBar>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QAbstractButton>
#include <QLCDNumber>
#include <QSlider>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <math.h>
#include <QSpinBox>
#include <cmath>
#include <QLocale>
#include <QLibraryInfo>
#include <QPixmap>
#include <QLabel>
#include <QtGui>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QRadioButton>
#include <QComboBox>
#include <QToolBar>
#include <QCheckBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <sys/stat.h>

#include "entree_sortie.h"
#include "génération.h"

using namespace std;


/// \class Interface
/// \brief Classe permettant de créer et d'interagir avec l'interface graphique du logiciel.
class Interface : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *layoutgauche;
    QVBoxLayout *layoutdroitehaut;
    QVBoxLayout *layoutdroitebas;
    QHBoxLayout *layoutbas;
    QHBoxLayout *layoutF1;
    QHBoxLayout *layoutF2;
    QHBoxLayout *layoutParcourir;
    QVBoxLayout *layoutdroitemilieu;
    QHBoxLayout *layoutOut;
    QPushButton *valider;
    QPushButton *quitter;
    QPushButton *parcourir;
    QPushButton *arreter;
    QPushButton *aide;
    QGraphicsScene *scene;
    QGraphicsView *vue;
    QGridLayout* mainLayout;
    QWidget *fenetre;
    QSpinBox *nbGen;
    QSpinBox *tailleIndi;
    QSpinBox *taillePop;
    QDoubleSpinBox *tauxMut;
    QDoubleSpinBox *tauxCross;
    QDoubleSpinBox *valeurF1;
    QDoubleSpinBox *valeurF2;
    QRadioButton *maxF1;
    QRadioButton *maxF2;
    QRadioButton *minF1;
    QRadioButton *minF2;
    QRadioButton *appF1;
    QRadioButton *appF2;
    QLineEdit *F1;
    QLineEdit *F2;
    QLineEdit *nomFichier;
    QLineEdit *liensFichier;
    QComboBox *nbF;
    QToolBar *toolBar;
    QCheckBox *checkXFig;
    QCheckBox *checkPostScrit;
    QCheckBox *checkLaTeX;
    QGroupBox *groupF1;
    QGroupBox *groupF2;
    QLabel *labNbF;
    QLabel *labNbGen;
    QLabel *labTailleIndi;
    QLabel *labTaillePop;
    QLabel *labTauxMut;
    QLabel *labTauxCross;
    QLabel *labNomFichier;
    QLabel *labMaxF1;
    QLabel *labMaxF2;
    QLabel *labMinF1;
    QLabel *labMinF2;
    QLabel *labAppF1;
    QLabel *labAppF2;
    QLabel *labParcourir;
    QFileDialog *FFile;


//////// attributs

    string fonctionFitness1;
    string fonctionFitness2;
   static string nomFichierSortie;
    int taillePopulation;
    int tailleIndividu;
    int nbGenerationMax;
    int critereF1;
    int critereF2;
    float tauxMutation;
    float tauxCrossover;
    float valeurApproxF1;
    float valeurApproxF2;
    bool latex;
    bool xFig;
    bool postScript;
    static bool encours; //MODIFICATION CDS  A JUSTIFIER :  AJOUT DE L'ATTRIBUT//


public:
	/// \fn Inteface()
	/// \brief Constructeur par défaut de la classe Inteface.
    Interface();
    
    /// \fn Interface(string, string)
	/// \brief Constructeur de la classe Inteface.
	/// \param string nom
	/// \param string fichier
    Interface(string nom, string fichier); //MODIFICATION CDS  A JUSTIFIER : AJOUT DU CONSTRUCTEUR Interface (string nom, string fichier)//                                                                                       //
    //~ Interface(Interface inter);
    
    /// \fn bool getEnCours()
	/// \brief Getteur de l'attribut encours.
	/// \return L'attribut encours.
    bool getEnCours(); //MODIFICATION CDS  A JUSTIFIER : AJOUT DE LA METHODE//
    
	/// \fn string getFonctionFitness1()
	/// \brief Getteur permettant d'obtenir la première fonction fitness donnée dans l'interface.
	/// \return L'attribut fonctionFitness1.
	string getFonctionFitness1();
	
	/// \fn string getFonctionFitness2()
	/// \brief Getteur permettant d'obtenir la seconde fonction fitness donnée dans l'interface.
	/// \return L'attribut fonctionFitness2.
	string getFonctionFitness2();
	
	/// \fn string getNomFichierSortie()
	/// \brief Getteur permettant d'obtenir le nom de fichier de résultats donné dans l'interface.
	/// \return L'attribut nomFichierSortie.
	string getNomFichierSortie();
	
	/// \fn int getTaillePopulation()
	/// \brief Getteur permettant d'obtenir la taille pour une population donnée dans l'interface.
	/// \return L'attribut taillePopulation.
	int getTaillePopulation();
	
	/// \fn int getTailleIndividu()
	/// \brief Getteur permettant d'obtenir la taille pour un individu donnée dans l'interface.
	/// \return L'attribut tailleIndividu.
	int getTailleIndividu();
	
	/// \fn int getNbGenerationMax()
	/// \brief Getteur permettant d'obtenir le nombre maximum de génération à atteindre donné dans l'interface.
	/// \return L'attribut nbGenerationMax.
	int getNbGenerationMax();
	
	/// \fn int getCritereF1()
	/// \brief Getteur permettant d'obtenir le type de critère (maximisation, minimisation ou valeur approchée) pour la première fonction fitness donné dans l'interface.
	/// \return L'attribut critereF1.
	int getCritereF1();
	
	/// \fn int getCritereF2()
	/// \brief Getteur permettant d'obtenir le type de critère (maximisation, minimisation ou valeur approchée) pour la seconde fonction fitness donné dans l'interface.
	/// \return L'attribut critereF2.
	int getCritereF2();
	
	/// \fn float getTauxMutation()
	/// \brief Getteur permettant d'obtenir le taux de mutation donné dans l'interface.
	/// \return L'attribut tauxMutation.
	float getTauxMutation();
	
	/// \fn float getTauxCrossover()
	/// \brief Getteur permettant d'obtenir le taux de crossover donné dans l'interface.
	/// \return L'attribut tauxMutation.
	float getTauxCrossover();
	
	/// \fn float getValeurApproxF1()
	/// \brief Getteur permettant d'obtenir la valeur à approchée pour la première fonction fitness donnée dans l'interface.
	/// \return L'attribut valeurApproxF1.
	float getValeurApproxF1();
	
	/// \fn float getValeurApproxF2()
	/// \brief Getteur permettant d'obtenir la valeur à approchée pour la seconde fonction fitness donnée dans l'interface.
	/// \return L'attribut valeurApproxF2.
	float getValeurApproxF2();
	
	/// \fn bool getLatex()
	/// \brief Getteur permettant de savoir si un fichier de sortie en LaTeX est demandé ou non.
	/// \return L'attribut latex.
	bool getLatex();
	
	/// \fn bool getXFig()
	/// \brief Getteur permettant de savoir si un fichier de sortie au format xFig est demandé ou non.
	/// \return L'attribut xFig.
	bool getXFig();
	
	/// \fn bool getPostScript()
	/// \brief Getteur permettant de savoir si un fichier de sortie au format PostScript est demandé ou non.
	/// \return L'attribut postScript.
	bool getPostScript();
	
	/// \fn static void * algoGenetique(void *)
	/// \brief Méthode appelant l'ensemble des méthodes pour le déroulement du programme.
	/// \return NULL
	static void * algoGenetique(void * arg); //MODIFICATION CDS  A JUSTIFIER : void algoGenetique()//
	
    public slots:
    
    /// \fn void enableF2(int)
	/// \brief Méthode permettant d'afficher le champ pour entrer la seconde fonction fitness uniquement si l'utilisateur demande d'en entrer 2.
	/// \param int s
    void enableF2(int s); //MODIFICATION CDS  A JUSTIFIER : AJOUT DE LA METHODE//
    
	/// \fn void chercher()
	/// \brief Méthode permettant d'ouvrir une fenêtre pour sélectionner un fichier.
    void chercher(); //MODIFICATION CDS  A JUSTIFIER : AJOUT DE LA METHODE//
    
	/// \fn void cacherAppF1()
	/// \brief Méthode permettant de ne pas afficher le champ pour entrer une valeur approchée pour la première fonction fitness.
	void cacherAppF1(); //MODIFICATION CDS  A JUSTIFIER : AJOUT DE LA METHODE//
	
	/// \fn void cacherAppF2()
	/// \brief Méthode permettant de ne pas afficher le champ pour entrer une valeur approchée pour la seconde fonction fitness.
	void cacherAppF2(); //MODIFICATION CDS  A JUSTIFIER : AJOUT DE LA METHODE//
	
	/// \fn void aficherAppF1()
	/// \brief Méthode permettant d'afficher le champ pour entrer une valeur approchée pour la première fonction fitness.
    void afficherAppF1();
    
    /// \fn void afficherAppF2()
	/// \brief Méthode permettant d'afficher le champ pour entrer une valeur approchée pour la seconde fonction fitness.
    void afficherAppF2(); //MODIFICATION CDS  A JUSTIFIER : AJOUT DE LA METHODE//
    
	/// \fn void connectLancer()
	/// \brief Méthode permettant de lancer le programme
    void connectLancer();
    
	/// \fn void connectQuitter()
	/// \brief Méthode permettant de quitter le programme (sans sauvegarde).
    void connectQuitter();
    
    /// \fn void connectArreter()
	/// \brief Méthode permettant de arreter le programme (avec sauvegarde).
    void connectArreter();
    
    /// \fn void connectAide()
	/// \brief Méthode permettant d'ouvrir le manuel d'utilisation.
    void connectAide(); //MODIFICATION CDS  A JUSTIFIER : void aide()//
    
 



};

#endif // INTERFACE_H
