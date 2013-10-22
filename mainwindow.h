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

     // Verifie que le QString entr� en param�tre est bien un entier
     static bool StringIsInteger(QString);

     static bool StringIsReel(QString);

     static bool StringIsRationnel(QString);

     static bool StringIsComplexe(QString);

     static bool isInteger(QString );


     // Renvoie l'addition de deux element el1 et el2 (ATTENTION: el1 et el2 ne doivent pas �tres des complexes)
     static element * additionerElement(const element * el1,const element * el2);

     // Renvoie la multiplication de deux element el1 et el2 (ATTENTION: el1 et el2 ne doivent pas �tres des complexes)
     static element * multiplierElement(const element * el1,const element * el2);

     // Renvoie la division de deux element el1 et el2 (ATTENTION: el1 et el2 ne doivent pas �tres des complexes)
     static element * diviserElement(const element * el1,const element * el2);

private:
    
     // traite une exception (l'affiche � l'utilisateur)
     void treatException(calculatrice_exception);

     // Affecte les signaux aux �l�ments de la fen�tre
     void affectSignals();
     //Permet d'affecter des slots aux actions du menu
     void affectActions();


     //Permet d'afficher la pile sur le fen�tre en fonction du nombre d'�l�ments voulus par l'utilisateur
     void displayPileInWindow();

     // V�rifie que le QString en param�tre est un op�rateur valide pour un entier
     bool isValidBinaryOperator(QString);

     // Permet de faire une op�ration binaire dans la pile de stockage (op�rations: +,-,*,/,POW,MOD) en fonction de l'op�rateur QString pass� en param�tre
     // Retourne un booleen pour savoir si l'op�ration s'est bien d�roul�
     element * makeBinaryOperation(QString);

     // Permet de traiter l'addition de deux elements, renvoie true si l'addition s'est bien pass� et false sinon
     element * treatOperationPlus(const element*,const element*);

    // Permet de traiter la multiplication de deux elements, renvoie true si la multiplication s'est bien pass� et false sinon
     element * treatOperationFois(const element * el1,const element * el2);

     // Permet de traiter la division de deux elements, renvoie true si la division s'est bien pass� et false sinon
     element * treatOperationDiviser(const element * el1,const element * el2);

     // Traite le cas ou un op�rateur au moins est un complexe (pour op +), retourne true si l'op�ration a �t� effectu�
     element * treatComplexePlus(const element* el1,const element * el2);

     // Traite le cas ou un op�rateur au moins est un complexe(pour op *), retourne true si l'op�ration a �t� effectu�
     element * treatComplexeFois(const element* el1,const element * el2);

     // Traite le cas ou un op�rateur au moins est un complexe(pour op /), retourne true si l'op�ration a �t� effectu�
     element * treatComplexeDiviser(const element * el1,const element * el2);


      // Retourne un reel qui est le Sinus de l'�l�ment en fonction du mode (0=degr�, 1 =radiant)
     reel * SIN(const element * el, int mode=0);

     // Retourne un reel qui est le Cosinus de l'�l�ment en fonction du mode (0=degr�, 1 =radiant)
     reel * COS(const element * el, int mode=0);
     // Retourne un reel qui est la tangente de l'�l�ment en fonction du mode (0=degr�, 1 =radiant)
     reel * TAN(const element * el, int mode=0);

     // Retourne un reel qui est le Sinus hyperbolique de l'�l�ment en fonction du mode (0=degr�, 1 =radiant)
     reel * SINH(const element * el, int mode=0);

     // Retourne un reel qui est le Cosinus hyperbolique de l'�l�ment en fonction du mode (0=degr�, 1 =radiant)
     reel * COSH(const element * el, int mode=0);

     // Retourne un reel qui est la tangente hyperbolique de l'�l�ment en fonction du mode (0=degr�, 1 =radiant)
     reel * TANH(const element * el, int mode=0);

     // Retourne un reel qui est le logarithme n�perien de l'�l�ment pass� en param�tre
     reel * LN(const element * el);

     // Retourne un reel qui est le logarithme d�cimal de l'�l�ment pass� en param�tre
     reel * LOG(const element * el);

     // Retourne un reel qui est la racine carr�e de l'�l�ment pass� en param�tre
     reel * SQRT(const element * el);

      // retourne le cube de l'�l�ment pass� en param�tre
     element * CUBE(const element *el);

     // retourne le carr� de l'�l�ment pass� en param�tre
     element * SQR(const element *el);

     // Retourne un entier r�sultat de la factorielle de l'entier pass� en param�tre
     element  * factorielle(const element * el);

     int factorielle(int n);

     // Renvoie l'entier reste de la division de l'entier el1 par l'entier el2 (si el1 et el2 ne sont pas des entiers) il y a conversion
     entier  * MOD(const element * el1, const element * el2);

     // Retourne un element r�sultat de POW(el1,el2)
     element * POW(const element * el1, const element * el2);

     //Permet de convertir et de renvoyer un element pass� en param�tre suivant le mode de constante choisit par l'utilisateur
     //Cette fonction est appel� apr�s chaque �valuation d'un op�rateur
     const element *  convertElementResultat(const element *);


     // Permet de donner l'angle en radians � partir du param�tre exprim� en degr�s
     float giveAngleRadians(float);

     // Permet de savoir si l'op�rateur pass� en param�tre est un op�rateur unaire valide
     bool isValidUnaryOperator(QString pOp);

     // Permet d'effectuer une op�ration unaire, renvoie true si l'op�ration s'est bien pass�
     element * makeUnaryOperation(QString textField);

     // renvoie true si le param�tre est de la forme d'une expression
     bool StringIsExpression(QString textField);

     // Permet de traiter la commande EVAL
     void treatEVALExp();

     // Permet de traiter chaque element de l'expression textField qui est pass� en param�tre
     void treatElementOfExpression(QString textField);


     // Fonction op�ration sur la pile
     void DROP(){if(!pile.isEmpty()){pile.pop();}}
     void DUP();

     // Permet d'�changer el1 et el2 dans la pile
     void SWAP(const element *el1,const element *el2);

     // Permet de faire la somme des el premiers �l�ments de la piles, retourne le r�sultat
     // Si el n'est pas un entier on tente une conversion si elle est possible
     element * SUM(const element * el);

     element * MEAN(const element * el);

     // Fonction permettant de sauvegarder les param�tres utilisateurs lors de la fermeture de l'application
     void saveSettings();
     // Fonction permettant de sauvegarder la pile lors de la fermeture de l'application
     void saveStack();


     // Permet de recharger l'�tat de la pile
     void loadStack();
     // Permet de charger les param�tres utilisateurs
     void loadSettings();

     // Fonction permettant d'empiler dans la pile � partir d'un QString
     // appel� lors de la r�cup�ration de l'�tat de la pile
     void pushInStack(QString );

     //Permet d'actualiser la fen�tre (avec ou sans le mode clavier)
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
