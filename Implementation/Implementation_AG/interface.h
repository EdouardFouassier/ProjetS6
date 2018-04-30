#ifndef INTERFACE_H
#define INTERFACE_H
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

#include "entree_sortie.h"

using namespace std;

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
    string nomFichierSortie;
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
    bool encours;


public:
    Interface();
    //~ Interface(Interface probabilite);
    bool getEnCours();
	string getFonctionFitness1();
	string getFonctionFitness2();
	string getNomFichierSortie();
	int getTaillePopulation();
	int getTailleIndividu();
	int getNbGenerationMax();
	int getCritereF1();
	int getCritereF2();
	float getTauxMutation();
	float getTauxCrossover();
	float getValeurApproxF1();
	float getValeurApproxF2();
	bool getLatex();
	bool getXFig();
	bool getPostScript();
	
    public slots:
    void enableF2(int s);
    void chercher();
    void cacherAppF1();
    void cacherAppF2();
    void afficherAppF1();
    void afficherAppF2();
    void connectLancer();
    void connectQuitter();
    void connectArreter();
    void connectAide();



};

#endif // INTERFACE_H
