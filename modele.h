#ifndef MODELE_H
#define MODELE_H


#include "QString"
#include <QStringList>
#include <QStack>


class reel;

class element{

    private:

    QString valueString;

    public:

    virtual ~element(){}

    element(QString el=""):valueString(el){}
    const QString getValueString()const{return valueString;}
    QString getValueString(){return valueString;}
    element(const element*);


    void setValueString(QString valS){valueString=valS;}

    // retourne true si l'element est un complexe et false sinon
    bool isComplexe()const;

    // inverse le signe de l'élément
    virtual element * SIGN() const=0;
    bool estNul()const;

    virtual element * INV()const=0;



};

class expression : public element{

    public:

    expression::expression(QString el){setValueString(el);}
    expression(const expression *);
    ~expression();

    element * SIGN()const{return 0;}
    element * INV()const{return 0;}

};

class reel;
class rationnel;
class complexe;

class entier : public element{

    int value;


    public:


    ~entier();

    element * SIGN() const;

    int getValue()const{return value;}
    void setValue(int val){value=val;setValueString(QString::number(val));}

    entier(const entier *);
    entier(int);
    entier(QString);
    entier(const element *);
    entier(reel * r);
    entier(rationnel * r);

    element * operator+(const entier *)const;
    element * operator+(const reel *)const;
    element * operator+(const rationnel *)const;
    element * operator+(const complexe *)const;


    element * operator*(const entier *)const;
    element * operator*(const reel *)const;
    element * operator*(const rationnel *)const;
    element * operator*(const complexe *)const;

    element * operator/(const entier *)const;
    element * operator/(const reel *)const;
    element * operator/(const rationnel *)const;
    element * operator/(const complexe *)const;

    element * INV()const;



};

class reel : public element{

    float value;


    public:
    element * SIGN() const;

    float getValue()const{return value;}
    void setValue(float val){value=val;}

    ~reel();

    reel(float);
    reel(const rationnel *);
    reel(const reel *);

    // Permet de créer un reel à partir d'un QString comme "0,54484"
    reel(QString);



    element * operator+(const reel * reel2)const;
    element * operator+(const rationnel * rationnelEl2)const;
    element * operator+(const complexe * )const;

    element * operator*(const reel * reel2)const;
    element * operator*(const rationnel * rationnelEl2)const;
    element * operator*(const complexe * )const;

    element * operator/(const entier *)const;
    element * operator/(const reel *)const;
    element * operator/(const rationnel *)const;
    element * operator/(const complexe *)const;

    element * INV()const;
    
};

class rationnel : public element{

    int num;
    int deno;


    public:

    element * SIGN() const;

    ~rationnel();

    void setNum(int n){num=n;}
    void setDeno(int d){deno=d;}

    rationnel(int,int);
    // Permet de construire un rationnel à partir d'un QString, ex: "45/48"
    rationnel(QString);
    rationnel(const rationnel *);

    int getNum()const{return num;}
    int getDeno()const{return deno;}

    // retourne la conversion du rationnel en reel (float)
    float convertInFloat()const;

    element* operator+(const rationnel * el2)const;
    element* operator+(const complexe * el2)const;

    element* operator*(const rationnel * el2)const;
    element* operator*(const complexe * el2)const;

    element * operator/(const entier *)const;
    element * operator/(const reel *)const;
    element * operator/(const rationnel *)const;
    element * operator/(const complexe *)const;

    element * INV()const;

    float giveValeurReel()const{return(num/deno);}


};

class complexe : public element{

    const element* pIm;
    const element* pReel;

    public:

    element * SIGN() const;

    ~complexe();

    complexe(const complexe *);

    const element * getPartieIm()const{return pIm;}
    const element * getPartieReel()const{return pReel;}

    //Renvoie une copie des elements partie Image et partie reel
    element * getCopyPartieIm()const;
    element * getCopyPartieReel()const;

    complexe(const element* Im,const element* Reel);
    // créer un complexe à partir d'un QString
    complexe(QString);

    complexe(complexe *,int);

    element* operator+(const complexe*)const;
    element* operator*(const complexe*)const;

    // renvoie un nouvelle element dont la valeure est le module du complexe
    element * giveModule()const;

    element * INV()const{return 0;}

    element * operator/(const entier *)const;
    element * operator/(const reel *)const;
    element * operator/(const rationnel *)const;
    element * operator/(const complexe *)const;

};

// Cette classe permet la levé les exceptions pouvant survenir lors de la manipulation de la calculatrice par l'utilisateur
// lors d'une opération (Binaire ou Unaire) par exemple:
// 3 attributs: Un QString représentant le texte de l'exception à afficher à l'utilisateur
// 2 pointeurs sur elements pointants sur les éléments auquels fait appel l'opération
class calculatrice_exception{

    QString info;
    const element * el1;
    const element * el2;

    public:
    //Par défault on met les attributs element à 0 (si l'exception ne porte pas sur une opération)
    calculatrice_exception(const QString& s, const  element * pEl1=0, const element * pEl2=0):info(s){el1=pEl1;el2=pEl2;}
    const QString& get_info() const{return info;}
    const element* get_element1()const{return el1;}
    const element* get_element2()const{return el2;}

    // Retourne vrai si le complexe est nul, faux sinon



};








#endif // MODELE_H
