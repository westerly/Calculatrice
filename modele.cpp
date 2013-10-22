#include "modele.h"
#include "mainwindow.h"


entier::~entier(){}
reel::~reel(){}
rationnel::~rationnel(){}

complexe::~complexe()
{
    delete pIm;
    delete pReel;
}


entier::entier(int Val)
{
    value=Val;
    setValueString(QString::number(Val));
}

rationnel::rationnel(int pNum,int pDen)
{
    num=pNum;
    deno=pDen;
    setValueString(QString(QString::number(pNum)+"/"+QString::number(pDen)));
}



reel::reel(float pVal)
{
    value=pVal;
    QString valueS;
    valueS.setNum(pVal,'f');
    setValueString(valueS);
}

complexe::complexe(const element* Im,const element* Reel)
{
    pIm=Im;
    pReel=Reel;

    setValueString(Reel->getValueString()+"$"+Im->getValueString());

}

complexe:: complexe(QString text)
{
    QStringList listeSplit = text.split("$");
    QString PreelString = listeSplit.at(0);
    QString pImString = listeSplit.at(1);

    if(MainWindow::StringIsInteger(pImString))
    {
        pIm=new entier(pImString.toInt());
    }else if(MainWindow::StringIsRationnel(pImString))
    {
        pIm=new rationnel(pImString);
    }else{
        pIm=new reel(pImString);
    }

    if(MainWindow::StringIsInteger(PreelString))
    {
        pReel= new entier(PreelString.toInt());
    }else if(MainWindow::StringIsRationnel(PreelString))
    {
        pReel=new rationnel(PreelString);
    }else{
        pReel=new reel(PreelString);
    }

    setValueString(pReel->getValueString()+"$"+pIm->getValueString());

}

rationnel::rationnel(QString txt)
{
    QStringList listeSplit = txt.split("/");
    QString numerateurString = listeSplit.at(0);
    QString denominateurString = listeSplit.at(1);
    int numerateur = numerateurString.toInt();
    int denominateur = denominateurString.toInt();

    num=numerateur;
    deno=denominateur;
    setValueString(numerateurString+"/"+denominateurString);

}

reel::reel(QString txt)
{
    value=txt.toFloat();
    setValueString(txt);
}

element * entier::operator/(const entier * el2)const
{
    if(el2->getValue()==0)
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        return(new rationnel(value,el2->getValue()));
    }
}

element * entier::operator/(const reel * el2)const
{
    if(el2->getValue()==0)
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        return(new reel(value/el2->getValue()));
    }
}

element * entier::operator/(const rationnel * el2)const
{
    if(el2->getNum()==0)
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        return(new rationnel(value*el2->getDeno(),value*el2->getNum()));
    }
}

element * entier::operator/(const complexe * el2)const
{

    if(el2->getCopyPartieIm()->estNul() && el2->getCopyPartieReel()->estNul() )
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        const element * pReel = el2->getPartieReel();
        const element * pIm = el2->getPartieIm();

        element * module = el2->giveModule();

        element * ax = MainWindow::multiplierElement(this , pReel);
        element * moinsAy = MainWindow::multiplierElement(this,pIm->SIGN());

        element * newPartieReel = MainWindow::diviserElement(ax,module);
        element * newPartieIm = MainWindow::diviserElement(moinsAy,module);


        return(new complexe(newPartieIm,newPartieReel));
    }
}



element * entier::operator+(const entier * el2)const
{
    return(new entier(this->getValue()+el2->getValue()));
}

element * entier::operator+(const reel * el2)const
{
    return(new reel(this->getValue()+el2->getValue()));
}

element * entier::operator+(const rationnel * el2)const
{
    int numRes=value*el2->getDeno()+el2->getNum();
    return(new rationnel(numRes,el2->getDeno()));
}

element * entier::operator+(const complexe * el2)const
{
    const element *  PartieReelel2=el2->getPartieReel();

    const entier * entierPartieReel2=dynamic_cast<const entier*>(PartieReelel2);
    if(entierPartieReel2!=0)
    {
        // la partie reel du complexe est un entier
        element * newPartieReel=new entier(entierPartieReel2->getValue()+value);
        return(new complexe(el2->getCopyPartieIm(),newPartieReel));
    }else{
        const reel * reelPartieReel2=dynamic_cast<const reel*>(PartieReelel2);
        if(reelPartieReel2!=0)
        {
          // la partie reel du complexe est un reel
            reel * newPartieReel=new reel(reelPartieReel2->getValue()+value);
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }else{
            const rationnel * rationnelPartieReel2=dynamic_cast<const rationnel*>(PartieReelel2);
            // la partie reel du complexe est un rationnel
            // le numérateur du rationnel représentant la partie reel résultat est
            rationnel * newPartieReel=new rationnel(value*rationnelPartieReel2->getDeno()+rationnelPartieReel2->getNum(),rationnelPartieReel2->getDeno());
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }
    }
 }

element * entier::operator*(const entier * el2)const
{
    return(new entier(value*el2->getValue()));
}

element * entier::operator*(const reel * el2)const
{
     return(new reel(value*el2->getValue()));
}

element * entier::operator*(const rationnel * el2)const
{
    // 2 * 1/4 = (2*1)/4 = 2/4
    int numRes=value*el2->getNum();
    return(new rationnel(numRes,el2->getDeno()));
}

element * entier::operator*(const complexe * el2)const
{
    const element *  PartieReelel2=el2->getPartieReel();

    const entier * entierPartieReel2=dynamic_cast<const entier*>(PartieReelel2);
    if(entierPartieReel2!=0)
    {
        // la partie reel du complexe est un entier
        element * newPartieReel=(*this)*(entierPartieReel2);
        return(new complexe(el2->getCopyPartieIm(),newPartieReel));
    }else{
        const reel * reelPartieReel2=dynamic_cast<const reel*>(PartieReelel2);
        if(reelPartieReel2!=0)
        {
          // la partie reel du complexe est un reel
            element * newPartieReel=(*this)*(reelPartieReel2);
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }else{
            const rationnel * rationnelPartieReel2=dynamic_cast<const rationnel*>(PartieReelel2);
            // la partie reel du complexe est un rationnel
            // le numérateur du rationnel représentant la partie reel résultat est
            element * newPartieReel=(*this)*(rationnelPartieReel2);
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }
    }
}

element * complexe::getCopyPartieIm()const
  {
     const entier * partieImEntiere=dynamic_cast<const entier*>(pIm);
     if(partieImEntiere!=0)
     {
           return( new entier(partieImEntiere->getValue()));
     }else{
         const rationnel * partieImRationnel=dynamic_cast<const rationnel*>(pIm);
         if(partieImRationnel!=0)
         {
            return(new rationnel(partieImRationnel->getNum(),partieImRationnel->getDeno()));
         }else{
             const reel * partieImReel=dynamic_cast<const reel*>(pIm);
             return(new reel(partieImReel->getValue()));
         }
     }
  }

element * complexe::getCopyPartieReel()const
  {
     const entier * partieReelEntiere=dynamic_cast<const entier*>(pReel);
     if(partieReelEntiere!=0)
     {
           return( new entier(partieReelEntiere->getValue()));
     }else{
         const rationnel * partieReelRationnel=dynamic_cast<const rationnel*>(pReel);
         if(partieReelRationnel!=0)
         {
            return(new rationnel(partieReelRationnel->getNum(),partieReelRationnel->getDeno()));
         }else{
             const reel * partieReelReel=dynamic_cast<const reel*>(pReel);
             return(new reel(partieReelReel->getValue()));
         }
     }
  }

element * reel::operator/(const entier * el2)const
{
    return(new reel(this->getValue()/el2->getValue()));
}
element * reel::operator/(const reel * el2)const
{
    return(new reel(this->getValue()/el2->getValue()));
}
element * reel::operator/(const rationnel * el2)const
{
    float el2Convert = el2->convertInFloat();
    return(new reel(this->getValue()/el2Convert));
}

element * reel::operator/(const complexe * el2)const
{
    if(el2->getCopyPartieIm()->estNul() && el2->getCopyPartieReel()->estNul() )
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        const element * pReel = el2->getPartieReel();
        const element * pIm = el2->getPartieIm();

        element * module = el2->giveModule();

        element * ax = MainWindow::multiplierElement(this , pReel);
        element * moinsAy = MainWindow::multiplierElement(this,pIm->SIGN());

        element * newPartieReel = MainWindow::diviserElement(ax,module);
        element * newPartieIm = MainWindow::diviserElement(moinsAy,module);


        return(new complexe(newPartieIm,newPartieReel));
    }
}


element * reel::operator+(const reel * reel2)const
{
    return(new reel(value+reel2->getValue()));
}

element * reel::operator+(const rationnel * rationnelEl2)const
{
    // Onconvertit le rationnel en reel
    float rationnnelTranslateInFloat=rationnelEl2->convertInFloat();
    return(new reel(rationnnelTranslateInFloat+value));
}


float rationnel::convertInFloat()const
{
    return(float(num)/float(deno));
}

element * reel::operator+(const complexe * el2)const
{
    const element *  PartieReelel2=el2->getPartieReel();
    element * newPartieReel;

    const entier * entierPartieReel2=dynamic_cast<const entier*>(PartieReelel2);
    if(entierPartieReel2!=0)
    {
        // la partie reel du complexe est un entier
        newPartieReel=*entierPartieReel2+this;
        return(new complexe(el2->getCopyPartieIm(),newPartieReel));

    }else{
        const reel * reelPartieReel2=dynamic_cast<const reel*>(PartieReelel2);
        if(reelPartieReel2!=0)
        {
          // la partie reel du complexe est un reel
            newPartieReel=*reelPartieReel2+this;
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }else{
            const rationnel * rationnelPartieReel2=dynamic_cast<const rationnel*>(PartieReelel2);
            // la partie reel du complexe est un rationnel
            newPartieReel=*this+rationnelPartieReel2;
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }
    }
}

element * reel::operator*(const reel * reel2)const
{
    return(new reel(value*reel2->getValue()));
}
element * reel::operator*(const rationnel * rationnelEl2)const
{
    // On convertit le rationnel en reel
    float rationnnelTranslateInFloat=rationnelEl2->convertInFloat();
    return(new reel(rationnnelTranslateInFloat*value));
}
element * reel::operator*(const complexe * el2)const
{
    const element *  PartieReelel2=el2->getPartieReel();
    element * newPartieReel;

    const entier * entierPartieReel2=dynamic_cast<const entier*>(PartieReelel2);
    if(entierPartieReel2!=0)
    {
        // la partie reel du complexe est un entier
        newPartieReel=(*entierPartieReel2)*(this);
        return(new complexe(el2->getCopyPartieIm(),newPartieReel));

    }else{
        const reel * reelPartieReel2=dynamic_cast<const reel*>(PartieReelel2);
        if(reelPartieReel2!=0)
        {
          // la partie reel du complexe est un reel
            newPartieReel=(*reelPartieReel2)*(this);
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }else{
            const rationnel * rationnelPartieReel2=dynamic_cast<const rationnel*>(PartieReelel2);
            // la partie reel du complexe est un rationnel
            newPartieReel=*this*rationnelPartieReel2;
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }
    }
}

element * rationnel::operator/(const entier * el2)const
{
    if(el2->estNul())
    {
         throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        element * moinsEl2=el2->INV();
        rationnel * moinsEl2Rationnel= dynamic_cast<rationnel*>(moinsEl2);
        element * res = (*moinsEl2Rationnel) * (this) ;
        return(res);
    }
}

element * rationnel::operator/(const reel * el2)const
{
    if(el2->estNul())
    {
         throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        float ratioconvert = this->convertInFloat();

        return(new reel(ratioconvert/el2->getValue()));
    }
}

element * rationnel::operator/(const rationnel * el2)const
{
    if(el2->estNul())
    {
         throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        element * invEl2 = el2->INV();
        rationnel * invEl2Rationnel= dynamic_cast<rationnel*>(invEl2);

        return((*this) * invEl2Rationnel);
    }
}

element * rationnel::operator/(const complexe * el2)const
{
    if(el2->getCopyPartieIm()->estNul() && el2->getCopyPartieReel()->estNul())
    {
         throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{
        const element * pReel = el2->getCopyPartieReel();
        const element * pIm = el2->getPartieIm();

        element * module = el2->giveModule();

        element * rationnelEl1 = new rationnel(this->getNum(),this->getDeno());

        element * ax = MainWindow::multiplierElement(rationnelEl1 , pReel);
        element * moinsAy = MainWindow::multiplierElement(rationnelEl1,pIm->SIGN());

        element * newPartieReel = MainWindow::diviserElement(ax,module);
        element * newPartieIm = MainWindow::diviserElement(moinsAy,module);


        return(new complexe(newPartieIm,newPartieReel));
    }

}


element* rationnel::operator+(const rationnel * el2)const
{
    return(new rationnel(this->getNum()*el2->getDeno()+this->getDeno()*el2->getNum(),this->getDeno()*el2->getDeno()));
}


element* rationnel::operator+(const complexe * el2)const
{
    const element *  PartieReelel2=el2->getPartieReel();
    element * newPartieReel;

    const entier * entierPartieReel2=dynamic_cast<const entier*>(PartieReelel2);
    if(entierPartieReel2!=0)
    {
        // la partie reel du complexe est un entier
        newPartieReel=*entierPartieReel2+this;
        return(new complexe(el2->getCopyPartieIm(),newPartieReel));

    }else{
        const reel * reelPartieReel2=dynamic_cast<const reel*>(PartieReelel2);
        if(reelPartieReel2!=0)
        {
          // la partie reel du complexe est un reel
            newPartieReel=*reelPartieReel2+this;
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }else{
            const rationnel * rationnelPartieReel2=dynamic_cast<const rationnel*>(PartieReelel2);
            // la partie reel du complexe est un rationnel
            newPartieReel=*this+rationnelPartieReel2;
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }
    }
}

element* rationnel::operator*(const rationnel * el2)const
{
    return(new rationnel(this->getNum()*el2->getNum(),this->getDeno()*el2->getDeno()));
}

element* rationnel::operator*(const complexe * el2)const
{
    const element *  PartieReelel2=el2->getPartieReel();
    element * newPartieReel;

    const entier * entierPartieReel2=dynamic_cast<const entier*>(PartieReelel2);
    if(entierPartieReel2!=0)
    {
        // la partie reel du complexe est un entier
        newPartieReel=*entierPartieReel2*this;
        return(new complexe(el2->getCopyPartieIm(),newPartieReel));

    }else{
        const reel * reelPartieReel2=dynamic_cast<const reel*>(PartieReelel2);
        if(reelPartieReel2!=0)
        {
          // la partie reel du complexe est un reel
            newPartieReel=*reelPartieReel2*this;
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }else{
            const rationnel * rationnelPartieReel2=dynamic_cast<const rationnel*>(PartieReelel2);
            // la partie reel du complexe est un rationnel
            newPartieReel=*this*rationnelPartieReel2;
            return(new complexe(el2->getCopyPartieIm(),newPartieReel));
        }
    }
}

element* complexe::operator+(const complexe* el2)const
{    
    element * pReelEl1=this->getCopyPartieReel();
    element * pImEl1=this->getCopyPartieIm();

    element * pReelEl2=el2->getCopyPartieReel();
    element * PImEl2=el2->getCopyPartieIm();

    element * newPim=MainWindow::additionerElement(pImEl1,PImEl2);
    element * newPreel=MainWindow::additionerElement(pReelEl1,pReelEl2);

    return(new complexe(newPim,newPreel));
}

element* complexe::operator*(const complexe* el2)const
{
    /*
    Soient z1 et z2 deux complexes d’écriture algébriques z 1 = x 1 +i y 1 et z 2 = x 2 +i y 2 .

    On a alors : z 1 z 2 = ( x 1 +i y 1 )( x 2 +i y 2 ) .

    En appliquant les règles du calcul algébrique usuelles, on obtient :

    z 1 z 2 =( x 1 x 2 - y 1 y 2 )+i( x 1 y 2 + x 2 y 1 ) .

    */

    const element * x1=this->getPartieReel();
    const element * y1=this->getPartieIm();

    const element * x2=el2->getPartieReel();
    const element * y2=el2->getPartieIm();

    element * x1x2 = MainWindow::multiplierElement(x1,x2);
    element * y1y2 = MainWindow::multiplierElement(y1,y2);
    // inversion du signe
    y1y2=y1y2->SIGN();

    element * newPartieReel = MainWindow::additionerElement(x1x2,y1y2);

    element * x1y2 = MainWindow::multiplierElement(x1,y2);
    element * x2y1 = MainWindow::multiplierElement(x2,y1);

    element * newPartieIm = MainWindow::additionerElement(x1y2,x2y1);

    return(new complexe(newPartieIm,newPartieReel));
}


bool element::isComplexe() const
{
    const complexe * elementConvert = dynamic_cast<const complexe*>(this);
    if(elementConvert==0)
    {
        return false;
    }else{
        return true;
    }
}

element * complexe::operator/(const entier * el2)const
{
    if(el2->estNul())
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{

       return(new complexe(MainWindow::diviserElement(pIm,el2),MainWindow::diviserElement(pReel,el2)));
    }
}
element * complexe::operator/(const reel * el2)const
{
    if(el2->estNul())
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{

       return(new complexe(MainWindow::diviserElement(pIm,el2),MainWindow::diviserElement(pReel,el2)));
    }
}

element * complexe::operator/(const rationnel * el2)const
{
    if(el2->estNul())
    {
           throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{

       return(new complexe(MainWindow::diviserElement(pIm,el2),MainWindow::diviserElement(pReel,el2)));
    }
}

element * complexe::operator/(const complexe * el2)const
{
    if(el2->getCopyPartieIm()->estNul() && el2->getCopyPartieReel()->estNul())
    {
        throw(calculatrice_exception("Impossible de diviser par zéro",this,el2));
    }else{

        const element * a = pReel;
        const element * b = pIm;

        const element * c = el2->getPartieReel();
        const element * d = el2->getPartieIm();

        element * ac = MainWindow::multiplierElement(a,c);
        element * bd = MainWindow::multiplierElement(b,d);

        element * cb = MainWindow::multiplierElement(c,b);
        element * moinsAD = MainWindow::multiplierElement(a,d)->SIGN();

        element * moduleCD = el2->giveModule();

        return(new complexe(MainWindow::diviserElement(MainWindow::additionerElement(cb,moinsAD),moduleCD),MainWindow::diviserElement(MainWindow::additionerElement(ac,bd),moduleCD)));
    }

}

element * entier::SIGN() const
{
    return(new entier(-(this->getValue())));
}
element * reel::SIGN() const
{
    return(new reel(-(this->getValue())));
}
element * rationnel::SIGN() const
{
    return(new rationnel(-(this->getNum()),this->getDeno()));
}
element * complexe::SIGN() const
{
    const element * pIm=this->getPartieIm();
    const element * pReel=this->getPartieReel();
    element * newPIm=pIm->SIGN();
    element * newPreel=pReel->SIGN();

    return(new complexe(newPIm,newPreel));
}

element * complexe::giveModule()const
{
    const element * pReel = this->getPartieReel();
    element * pReelMul=MainWindow::multiplierElement(pReel,pReel);
    const element * pIm = this->getPartieIm();
    element * pImMul=MainWindow::multiplierElement(pIm,pIm);

    return(MainWindow::additionerElement(pReelMul,pImMul));
}

bool element::estNul()const
{
    bool estNul=false;
    const entier * elementConvert = dynamic_cast<const entier*>(this);
    if(elementConvert!=0 && elementConvert->getValue()==0)
    {
        estNul=true;
    }else{
        const reel * elementConvert = dynamic_cast<const reel*>(this);
        if(elementConvert!=0 && elementConvert->getValue()==0)
        {
            estNul=true;
        }else{
            const rationnel * elementConvert = dynamic_cast<const rationnel*>(this);
            if(elementConvert!=0 && elementConvert->getNum()==0)
            {
                estNul=true;
            }
        }
    }

    return estNul;
}

element * entier::INV()const
{
    return(new rationnel(1,this->getValue()));
}

element * reel::INV()const
{
    return(new reel(1/this->getValue()));
}

element * rationnel::INV()const
{
    return(new rationnel(this->getDeno(),this->getNum()));
}

entier::entier(reel * r)
{
    value=r->getValue();
    setValueString(QString::number(value));
}

 entier::entier(rationnel * r)
 {
     value = r->getNum()/r->getDeno();
     setValueString(QString::number(value));
 }

entier::entier(const element * el)
{
    const reel * elReel = dynamic_cast<const reel*>(el);
    if(elReel!=0)
    {
        value=elReel->getValue();
        setValueString(QString::number(value));
    }else{
        const rationnel * elRationnel = dynamic_cast<const rationnel*>(el);
        if(elRationnel!=0)
        {
            value = elRationnel->getNum()/elRationnel->getDeno();
            setValueString(QString::number(value));
        }
    }
}

reel::reel(const rationnel * el)
{
    value = el->getNum() / el->getDeno();
    QString valueS;
    valueS.setNum(value,'f');
    setValueString(valueS);
}


expression::~expression(){}

complexe::complexe(const complexe * c)
{
    pIm = c->getCopyPartieIm();
    pReel = c->getCopyPartieReel();
    setValueString(pReel->getValueString()+"$"+pIm->getValueString());

}

reel::reel(const reel * r)
{
    value = r->getValue();
    QString valueS;
    valueS.setNum(value,'f');
    setValueString(valueS);
}

rationnel::rationnel(const rationnel * r)
{
    num=r->getNum();
    deno=r->getDeno();
    setValueString(QString(QString::number(num)+"/"+QString::number(deno)));
}

expression::expression(const expression * e)
{
    setValueString(e->getValueString());
}

entier::entier(const entier * e)
{
    value=e->getValue();
    setValueString(QString::number(value));
}

element::element(const element* el)
{

}

