#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtCore/qmath.h>
#include <QTextStream>
#include <QFile>
#include <QtXml/QDomDocument>
#include "modele.h"


namespace Ui
{
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
    Ui::MainWindow * ui;

    QStack<const element*> pile;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

     // Verifie que le QString entré en paramètre est bien un entier
     static bool StringIsInteger(QString);

     static bool StringIsReel(QString);

     static bool StringIsRationnel(QString);

     static bool StringIsComplexe(QString);

     static bool isInteger(QString );


     // Renvoie l'addition de deux element el1 et el2 (ATTENTION: el1 et el2 ne doivent pas êtres des complexes)
     static element * additionerElement(const element * el1,const element * el2);

     // Renvoie la multiplication de deux element el1 et el2 (ATTENTION: el1 et el2 ne doivent pas êtres des complexes)
     static element * multiplierElement(const element * el1,const element * el2);

     // Renvoie la division de deux element el1 et el2 (ATTENTION: el1 et el2 ne doivent pas êtres des complexes)
     static element * diviserElement(const element * el1,const element * el2);

private:
    
     // traite une exception (l'affiche à l'utilisateur)
     void treatException(calculatrice_exception);

     // Affecte les signaux aux éléments de la fenêtre
     void affectSignals();
     //Permet d'affecter des slots aux actions du menu
     void affectActions();


     //Permet d'afficher la pile sur le fenêtre en fonction du nombre d'éléments voulus par l'utilisateur
     void displayPileInWindow();

     // Vérifie que le QString en paramètre est un opérateur valide pour un entier
     bool isValidBinaryOperator(QString);

     // Permet de faire une opération binaire dans la pile de stockage (opérations: +,-,*,/,POW,MOD) en fonction de l'opérateur QString passé en paramètre
     // Retourne un booleen pour savoir si l'opération s'est bien déroulé
     element * makeBinaryOperation(QString);

     // Permet de traiter l'addition de deux elements, renvoie true si l'addition s'est bien passé et false sinon
     element * treatOperationPlus(const element*,const element*);

    // Permet de traiter la multiplication de deux elements, renvoie true si la multiplication s'est bien passé et false sinon
     element * treatOperationFois(const element * el1,const element * el2);

     // Permet de traiter la division de deux elements, renvoie true si la division s'est bien passé et false sinon
     element * treatOperationDiviser(const element * el1,const element * el2);

     // Traite le cas ou un opérateur au moins est un complexe (pour op +), retourne true si l'opération a été effectué
     element * treatComplexePlus(const element* el1,const element * el2);

     // Traite le cas ou un opérateur au moins est un complexe(pour op *), retourne true si l'opération a été effectué
     element * treatComplexeFois(const element* el1,const element * el2);

     // Traite le cas ou un opérateur au moins est un complexe(pour op /), retourne true si l'opération a été effectué
     element * treatComplexeDiviser(const element * el1,const element * el2);


      // Retourne un reel qui est le Sinus de l'élément en fonction du mode (0=degré, 1 =radiant)
     reel * SIN(const element * el, int mode=0);

     // Retourne un reel qui est le Cosinus de l'élément en fonction du mode (0=degré, 1 =radiant)
     reel * COS(const element * el, int mode=0);
     // Retourne un reel qui est la tangente de l'élément en fonction du mode (0=degré, 1 =radiant)
     reel * TAN(const element * el, int mode=0);

     // Retourne un reel qui est le Sinus hyperbolique de l'élément en fonction du mode (0=degré, 1 =radiant)
     reel * SINH(const element * el, int mode=0);

     // Retourne un reel qui est le Cosinus hyperbolique de l'élément en fonction du mode (0=degré, 1 =radiant)
     reel * COSH(const element * el, int mode=0);

     // Retourne un reel qui est la tangente hyperbolique de l'élément en fonction du mode (0=degré, 1 =radiant)
     reel * TANH(const element * el, int mode=0);

     // Retourne un reel qui est le logarithme néperien de l'élément passé en paramètre
     reel * LN(const element * el);

     // Retourne un reel qui est le logarithme décimal de l'élément passé en paramètre
     reel * LOG(const element * el);

     // Retourne un reel qui est la racine carrée de l'élément passé en paramètre
     reel * SQRT(const element * el);

      // retourne le cube de l'élément passé en paramètre
     element * CUBE(const element *el);

     // retourne le carré de l'élément passé en paramètre
     element * SQR(const element *el);

     // Retourne un entier résultat de la factorielle de l'entier passé en paramètre
     element  * factorielle(const element * el);

     int factorielle(int n);

     // Renvoie l'entier reste de la division de l'entier el1 par l'entier el2 (si el1 et el2 ne sont pas des entiers) il y a conversion
     entier  * MOD(const element * el1, const element * el2);

     // Retourne un element résultat de POW(el1,el2)
     element * POW(const element * el1, const element * el2);

     //Permet de convertir et de renvoyer un element passé en paramètre suivant le mode de constante choisit par l'utilisateur
     //Cette fonction est appelé après chaque évaluation d'un opérateur
     const element *  convertElementResultat(const element *);


     // Permet de donner l'angle en radians à partir du paramètre exprimé en degrés
     float giveAngleRadians(float);

     // Permet de savoir si l'opérateur passé en paramètre est un opérateur unaire valide
     bool isValidUnaryOperator(QString pOp);

     // Permet d'effectuer une opération unaire, renvoie true si l'opération s'est bien passé
     element * makeUnaryOperation(QString textField);

     // renvoie true si le paramètre est de la forme d'une expression
     bool StringIsExpression(QString textField);

     // Permet de traiter la commande EVAL
     void treatEVALExp();

     // Permet de traiter chaque element de l'expression textField qui est passé en paramètre
     void treatElementOfExpression(QString textField);


     // Fonction opération sur la pile
     void DROP(){if(!pile.isEmpty()){pile.pop();}}
     void DUP();

     // Permet d'échanger el1 et el2 dans la pile
     void SWAP(const element *el1,const element *el2);

     // Permet de faire la somme des el premiers éléments de la piles, retourne le résultat
     // Si el n'est pas un entier on tente une conversion si elle est possible
     element * SUM(const element * el);

     element * MEAN(const element * el);

     // Fonction permettant de sauvegarder les paramètres utilisateurs lors de la fermeture de l'application
     void saveSettings();
     // Fonction permettant de sauvegarder la pile lors de la fermeture de l'application
     void saveStack();


     // Permet de recharger l'état de la pile
     void loadStack();
     // Permet de charger les paramètres utilisateurs
     void loadSettings();

     // Fonction permettant d'empiler dans la pile à partir d'un QString
     // appelé lors de la récupération de l'état de la pile
     void pushInStack(QString );

     //Permet d'actualiser la fenêtre (avec ou sans le mode clavier)
     void actualiseWindowKeyboard();



public slots:

    void num0PressedButton();
    void num1PressedButton();
    void num2PressedButton();
    void num3PressedButton();
    void num4PressedButton();
    void num5PressedButton();
    void num6PressedButton();
    void num7PressedButton();
    void num8PressedButton();
    void num9PressedButton();
    void enterPressButton();
    void delPressButton();
    void plusPressButton();
    void foisPressButton();
    void divisePressButton();
    void moinsPressButton();
    void espacePressButton();
    void commaPressButton();
    void powPressButton();
    void modPressButton();
    void dollarPressButton();

    void swapPressButton();

    void sinPressButton();
    void cosPressButton();
    void tanPressButton();
    void sinhPressButton();
    void coshPressButton();
    void tanhPressButton();
    void lnPressButton();
    void logPressButton();
    void invPressButton();
    void sqrtPressButton();
    void sqrPressButton();
    void cubePressButton();
    void factPressButton();
    void evalPressButton();
    void signPressButton();
    void cotePressButton();
    void displayPile();

    void meanPressButton();
    void dupPressButton();
    void sumPressButton();
    void clearPressButton();
    void dropPressButton();


    // slots menu:

    void menuConstanteEntier();
    void menuConstanteReelle();
    void menuConstanteRationelle();

    void menuUniteDegre();
    void menuUniteRadiant();

    void menuActionComplexeOui();
    void menuActionComplexeNon();

    void menuActionClavierOui();
    void menuActionClavierNon();


};

#endif // MAINWINDOW_H
