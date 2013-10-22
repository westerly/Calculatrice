#include "mainwindow.h"
#include "ui_mainwindow.h"


#define PI 3.14159

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadStack();
    loadSettings();

    affectSignals();
    affectActions();

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(217, 228, 241));
    setPalette(p);

}

MainWindow::~MainWindow()
{
    saveStack();
    saveSettings();
    delete ui;   
}

void MainWindow::affectActions()
{
   connect(ui->actionEntier,SIGNAL(triggered()),this,SLOT(menuConstanteEntier()));
   connect(ui->actionReelle,SIGNAL(triggered()),this,SLOT(menuConstanteReelle()));
   connect(ui->actionRationelle,SIGNAL(triggered()),this,SLOT(menuConstanteRationelle()));


   connect(ui->actionDegre,SIGNAL(triggered()),this,SLOT(menuUniteDegre()));
   connect(ui->actionRadiant,SIGNAL(triggered()),this,SLOT(menuUniteRadiant()));

   connect(ui->actionComplexeOui,SIGNAL(triggered()),this,SLOT(menuActionComplexeOui()));
   connect(ui->actionComplexeNon,SIGNAL(triggered()),this,SLOT(menuActionComplexeNon()));

   connect(ui->actionClavierOui,SIGNAL(triggered()),this,SLOT(menuActionClavierOui()));
   connect(ui->actionClavierNon,SIGNAL(triggered()),this,SLOT(menuActionClavierNon()));

}

 void MainWindow::affectSignals()
 {
    connect(this->ui->Button_0,SIGNAL(clicked()),this,SLOT(num0PressedButton()));
    connect(this->ui->Button_1,SIGNAL(clicked()),this,SLOT(num1PressedButton()));
    connect(this->ui->Button_2,SIGNAL(clicked()),this,SLOT(num2PressedButton()));
    connect(this->ui->Button_3,SIGNAL(clicked()),this,SLOT(num3PressedButton()));
    connect(this->ui->Button_4,SIGNAL(clicked()),this,SLOT(num4PressedButton()));
    connect(this->ui->Button_5,SIGNAL(clicked()),this,SLOT(num5PressedButton()));
    connect(this->ui->Button_6,SIGNAL(clicked()),this,SLOT(num6PressedButton()));
    connect(this->ui->Button_7,SIGNAL(clicked()),this,SLOT(num7PressedButton()));
    connect(this->ui->Button_8,SIGNAL(clicked()),this,SLOT(num8PressedButton()));
    connect(this->ui->Button_9,SIGNAL(clicked()),this,SLOT(num9PressedButton()));

    connect(this->ui->Button_enter,SIGNAL(clicked()),this,SLOT(enterPressButton()));
    connect(this->ui->Button_del,SIGNAL(clicked()),this,SLOT(delPressButton()));
    connect(this->ui->Button_plus,SIGNAL(clicked()),this,SLOT(plusPressButton()));
    connect(this->ui->Button_moins,SIGNAL(clicked()),this,SLOT(moinsPressButton()));
    connect(this->ui->Button_fois,SIGNAL(clicked()),this,SLOT(foisPressButton()));
    connect(this->ui->Button_divise,SIGNAL(clicked()),this,SLOT(divisePressButton()));
    connect(this->ui->Button_space,SIGNAL(clicked()),this,SLOT(espacePressButton()));
    connect(this->ui->Button_comma,SIGNAL(clicked()),this,SLOT(commaPressButton()));
    connect(this->ui->Button_pow,SIGNAL(clicked()),this,SLOT(powPressButton()));
    connect(this->ui->Button_mod,SIGNAL(clicked()),this,SLOT(modPressButton()));


    connect(this->ui->Button_sin,SIGNAL(clicked()),this,SLOT(sinPressButton()));
    connect(this->ui->Button_cos,SIGNAL(clicked()),this,SLOT(cosPressButton()));
    connect(this->ui->Button_tan,SIGNAL(clicked()),this,SLOT(tanPressButton()));
    connect(this->ui->Button_sinh,SIGNAL(clicked()),this,SLOT(sinhPressButton()));
    connect(this->ui->Button_cosh,SIGNAL(clicked()),this,SLOT(coshPressButton()));
    connect(this->ui->Button_tanh,SIGNAL(clicked()),this,SLOT(tanhPressButton()));
    connect(this->ui->Button_ln,SIGNAL(clicked()),this,SLOT(lnPressButton()));
    connect(this->ui->Button_log,SIGNAL(clicked()),this,SLOT(logPressButton()));
    connect(this->ui->Button_inv,SIGNAL(clicked()),this,SLOT(invPressButton()));
    connect(this->ui->Button_sqrt,SIGNAL(clicked()),this,SLOT(sqrtPressButton()));
    connect(this->ui->Button_cube,SIGNAL(clicked()),this,SLOT(cubePressButton()));
    connect(this->ui->Button_fact,SIGNAL(clicked()),this,SLOT(factPressButton()));
    connect(this->ui->Button_eval,SIGNAL(clicked()),this,SLOT(evalPressButton()));
    connect(this->ui->Button_sign,SIGNAL(clicked()),this,SLOT(signPressButton()));
    connect(this->ui->Button_sqr,SIGNAL(clicked()),this,SLOT(sqrPressButton()));

    connect(this->ui->Button_dollar,SIGNAL(clicked()),this,SLOT(dollarPressButton()));

    connect(this->ui->Button_cote,SIGNAL(clicked()),this,SLOT(cotePressButton()));

    connect(this->ui->spinBoxNumberItemDisplay,SIGNAL(valueChanged(int)),this,SLOT(displayPile()));

    connect(this->ui->Button_SWAP,SIGNAL(clicked()),this,SLOT(swapPressButton()));
    connect(this->ui->Button_MEAN,SIGNAL(clicked()),this,SLOT(meanPressButton()));
    connect(this->ui->Button_DROP,SIGNAL(clicked()),this,SLOT(dropPressButton()));
    connect(this->ui->Button_DUP,SIGNAL(clicked()),this,SLOT(dupPressButton()));
    connect(this->ui->Button_CLEAR,SIGNAL(clicked()),this,SLOT(clearPressButton()));
    connect(this->ui->Button_SUM,SIGNAL(clicked()),this,SLOT(sumPressButton()));

}


void MainWindow::saveSettings()
{
    QDomDocument docSettings("settings");
    QFile fileSettings("settings.xml");
    QDomElement p;
    QTextStream streamOut;
    if (fileSettings.open(QIODevice::WriteOnly))
    {
        p = docSettings.createElement("settings"); // création de la balise "settings"
        docSettings.appendChild(p); // filiation de la balise "settings"
        streamOut.setDevice(&fileSettings); // association du flux au fichier

        QDomElement complexe = docSettings.createElement("complexe"); // création de la balise "complexe"
        p.appendChild(complexe); // filiation de la balise "complexe"
        if(ui->actionComplexeOui->isChecked())
        {
            complexe.appendChild(docSettings.createTextNode("oui")); //Ajout de la valeur du paramètre complexe
        }else{
            complexe.appendChild(docSettings.createTextNode("non"));
        }

        QDomElement typeConstante = docSettings.createElement("typeConstante"); // création de la balise "complexe"
        p.appendChild(typeConstante); // filiation de la balise "typeConstante"
        if(ui->actionEntier->isChecked())
        {
            typeConstante.appendChild(docSettings.createTextNode("entier")); //Ajout de la valeur du paramètre type de constante
        }else if(ui->actionRationelle->isChecked())
        {
            typeConstante.appendChild(docSettings.createTextNode("rationnel")); //Ajout de la valeur du paramètre type de constante
        }else if(ui->actionReelle->isChecked())
        {
            typeConstante.appendChild(docSettings.createTextNode("reel")); //Ajout de la valeur du paramètre type de constante
        }

        QDomElement degree = docSettings.createElement("degree"); // création de la balise "degree"
        p.appendChild(degree); // filiation de la balise "degree"
        if(ui->actionDegre->isChecked())
        {
            degree.appendChild(docSettings.createTextNode("degree")); //Ajout de la valeur du paramètre degree
        }else if(ui->actionRadiant->isChecked())
        {
            degree.appendChild(docSettings.createTextNode("radiant")); //Ajout de la valeur du paramètre degree
        }

        QDomElement clavier = docSettings.createElement("clavier"); // création de la balise "clavier"
        p.appendChild(clavier); // filiation de la balise "clavier"
        if(ui->actionClavierOui->isChecked())
        {
            clavier.appendChild(docSettings.createTextNode("oui")); //Ajout de la valeur du paramètre clavier
        }else if(ui->actionClavierNon->isChecked())
        {
            clavier.appendChild(docSettings.createTextNode("non")); //Ajout de la valeur du paramètre clavier
        }

        QDomNode noeud = docSettings.createProcessingInstruction("xml","version=\"1.0\""); // insertion en début de document de <?xml version="1.0" ?>
        docSettings.insertBefore(noeud,docSettings.firstChild());
        docSettings.save(streamOut,2); // sauvegarde dans le flux (deux espaces de décalage dans l'arborescence)
        fileSettings.close();
    }

}


void MainWindow::saveStack()
{
    QDomDocument docPile("pile");
    QFile filePile("pile.xml");
    QDomElement p;
    QTextStream streamOut;
    if (filePile.open(QIODevice::WriteOnly))
    {
        p = docPile.createElement("pile"); // création de la balise "pile"
        docPile.appendChild(p); // filiation de la balise "pile"
        streamOut.setDevice(&filePile); // association du flux au fichier
        for (int i = 0 ; i < pile.size() ; ++i)
        {
            QDomElement element = docPile.createElement("element"); // création de la balise "element"
            p.appendChild(element); // filiation de la balise "element"
                    element.appendChild(docPile.createTextNode(pile.at(i)->getValueString())); //Ajout de la valeur
        }
        QDomNode noeud = docPile.createProcessingInstruction("xml","version=\"1.0\""); // insertion en début de document de <?xml version="1.0" ?>
        docPile.insertBefore(noeud,docPile.firstChild());
        docPile.save(streamOut,2); // sauvegarde dans le flux (deux espaces de décalage dans l'arborescence)
        filePile.close();
    }
}

void MainWindow::loadSettings()
{
    QDomDocument docSettings("settings");
    QFile fileSettings("settings.xml");
    if (!fileSettings.open(QIODevice::ReadOnly))
    {
        fileSettings.close();
    }else{
        if (!docSettings.setContent(&fileSettings))
        {
            fileSettings.close();
        }else{
            QDomElement docElem = docSettings.documentElement();
            QDomNode node = docElem.firstChild();
            QDomElement e = node.toElement();
            if(e.text() == "oui")
            {
                ui->actionComplexeOui->setChecked(true);
                ui->actionComplexeNon->setChecked(false);
            }else if(e.text()=="non")
            {
                ui->actionComplexeOui->setChecked(false);
                ui->actionComplexeNon->setChecked(true);
            }
            node = node.nextSibling();
            e = node.toElement();
            if(e.text()=="entier")
            {
                ui->actionEntier->setChecked(true);
                ui->actionReelle->setChecked(false);
                ui->actionRationelle->setChecked(false);
            }else if(e.text()=="reel")
            {
                ui->actionReelle->setChecked(true);
                ui->actionEntier->setChecked(false);
                ui->actionRationelle->setChecked(false);
            }else if(e.text()=="rationnel")
            {
                ui->actionRationelle->setChecked(true);
                ui->actionReelle->setChecked(false);
                ui->actionEntier->setChecked(false);
            }

            node = node.nextSibling();
            e = node.toElement();
            if(e.text()=="degree")
            {
                ui->actionDegre->setChecked(true);
                ui->actionRadiant->setChecked(false);
            }else if(e.text()=="radiant")
            {
                ui->actionRadiant->setChecked(true);
                ui->actionDegre->setChecked(false);
            }

            node = node.nextSibling();
            e = node.toElement();
            if(e.text()=="oui")
            {
                ui->actionClavierOui->setChecked(true);
                ui->actionClavierNon->setChecked(false);
                actualiseWindowKeyboard();
            }else if(e.text()=="non")
            {
                ui->actionClavierOui->setChecked(false);
                ui->actionClavierNon->setChecked(true);
                actualiseWindowKeyboard();
            }
        }
    }
}

void MainWindow::loadStack()
{

    QDomDocument docPile("pile");
    QFile filePile("pile.xml");
    if (!filePile.open(QIODevice::ReadOnly))
    {
        filePile.close();
    }else{
        if (!docPile.setContent(&filePile))
        {
            filePile.close();
        }else{
            QDomElement docElem = docPile.documentElement();
            QDomNode node = docElem.firstChild();
            while(!node.isNull())
            {
                // Conversion d'un noeud en élément
                QDomElement e = node.toElement();
                if(!e.isNull())
                {
                    // On empile l'element en fonction du texte récupéré
                    pushInStack(e.text());
                }
                node = node.nextSibling();
            }
            displayPileInWindow();
        }
    }
}

void MainWindow::actualiseWindowKeyboard()
{
    if(ui->actionClavierOui->isChecked())
    {
        ui->clavierSecondaire->setVisible(true);
        ui->listExceptionWarning->setGeometry(10,270,601,61);
        ui->listWidgetPileDilsplay->setGeometry(620,40,81,291);
        ui->spinBoxNumberItemDisplay->setGeometry(620,10,41,22);
        this->setFixedHeight(392);
        this->setFixedWidth(711);
    }else if(ui->actionClavierNon->isChecked())
    {
        ui->clavierSecondaire->setVisible(false);
        ui->listExceptionWarning->setGeometry(10,270,301,61);
        ui->listWidgetPileDilsplay->setGeometry(330,40,81,291);
        ui->spinBoxNumberItemDisplay->setGeometry(330,10,41,22);
        this->setFixedHeight(392);
        this->setFixedWidth(425);
    }
}


void MainWindow::displayPile()
{
    displayPileInWindow();
}

void MainWindow::cotePressButton()
{
  ui->lineEdit->setText(ui->lineEdit->text()+"'");
}

void MainWindow::dollarPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"$");
}

void MainWindow::num0PressedButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"0");
}
void MainWindow::num1PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"1");
}
void MainWindow::num2PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"2");
}
void MainWindow::num3PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"3");
}
void MainWindow::num4PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"4");
}
void MainWindow::num5PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"5");
}
void MainWindow::num6PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"6");
}
void MainWindow::num7PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"7");
}
void MainWindow::num8PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"8");
}
void MainWindow::num9PressedButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"9");
}
void MainWindow::sinPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"SIN");
}
void MainWindow::cosPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"COS");
}
void MainWindow::tanPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"TAN");
}
void MainWindow::sinhPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"SINH");
}
void MainWindow::coshPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"COSH");
}
void MainWindow::tanhPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"TANH");
}
void MainWindow::lnPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"LN");
}
void MainWindow::logPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"LOG");
}
void MainWindow::invPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"INV");
}
void MainWindow::sqrtPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"SQRT");
}
void MainWindow::cubePressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"CUBE");
}
void MainWindow::factPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"!");
}
void MainWindow::evalPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"EVAL");
}
void MainWindow::signPressButton()
{
ui->lineEdit->setText(ui->lineEdit->text()+"SIGN");
}
void MainWindow::sqrPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"SQR");
}

void MainWindow::swapPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"SWAP");
}

void MainWindow::dupPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"DUP");
}

void MainWindow::meanPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"MEAN");
}

void MainWindow::sumPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"SUM");
}

void MainWindow::clearPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"CLEAR");
}

void MainWindow::dropPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"DROP");
}

void MainWindow::pushInStack(QString textField)
{
    try{
       if(StringIsInteger(textField))
       {
            int integerToPush = textField.toInt();
            if(integerToPush==0 && textField!="0")
            {
                throw calculatrice_exception("L'entier entré dépasse les capacités de la calculatrice.");
            }else{
                pile.push(new entier(integerToPush));
            }
       }else if(StringIsReel(textField))
       {
                float reelToPush=textField.toFloat();
                pile.push(new reel(reelToPush));
       }else if(StringIsRationnel(textField))
       {
            QStringList listeSplit = textField.split("/");
            QString numerateurString = listeSplit.at(0);
            QString denominateurString = listeSplit.at(1);
            int numerateur = numerateurString.toInt();
            int denominateur = denominateurString.toInt();
            if((numerateur==0 && numerateurString!="0") || (denominateur==0 && denominateurString!="0"))
            {
                throw calculatrice_exception("Le rationnel entré dépasse les capacités de la calculatrice.");
            }else{
                pile.push(new rationnel(numerateur,denominateur));
            }
       }else if(StringIsComplexe(textField))
       {
            if(ui->actionComplexeOui->isChecked())
            {
                pile.push(new complexe(textField));
            }else{
                throw (calculatrice_exception("Impossible d'empiler le complexe, vous devez être en mode complexe."));
            }

       }else{
             // Sinon c'est que le textField est une expression
             pile.push(new expression(textField));
       }
    }catch(calculatrice_exception c){
       treatException(c);
    }
}


void MainWindow::enterPressButton()
{
    ui->listExceptionWarning->clear();

    QString textField = ui->lineEdit->text();

    try{
       if(ui->lineEdit->text().isEmpty())
       {
            DUP();
            displayPileInWindow();
       }else{
           if(StringIsInteger(textField))
           {
                int integerToPush = textField.toInt();
                if(integerToPush==0 && textField!="0")
                {
                    throw calculatrice_exception("L'entier entré dépasse les capacités de la calculatrice.");
                }else{

                    pile.push(new entier(integerToPush));
                    // On fait un clear du lineEdit
                    ui->lineEdit->clear();
                    displayPileInWindow();
                }
           }else if(StringIsReel(textField))
           {
                    float reelToPush=textField.toFloat();
                    pile.push(new reel(reelToPush));
                    // On fait un clear du lineEdit
                    ui->lineEdit->clear();
                    displayPileInWindow();

           }else if(StringIsRationnel(textField))
           {
                QStringList listeSplit = textField.split("/");
                QString numerateurString = listeSplit.at(0);
                QString denominateurString = listeSplit.at(1);
                int numerateur = numerateurString.toInt();
                int denominateur = denominateurString.toInt();
                if((numerateur==0 && numerateurString!="0") || (denominateur==0 && denominateurString!="0"))
                {
                    throw calculatrice_exception("Le rationnel entré dépasse les capacités de la calculatrice.");
                }else{
                    pile.push(new rationnel(numerateur,denominateur));
                    // On fait un clear du lineEdit
                    ui->lineEdit->clear();
                    displayPileInWindow();
                }
           }else if(StringIsComplexe(textField))
           {
                if(ui->actionComplexeOui->isChecked())
                {
                    pile.push(new complexe(textField));
                   // On fait un clear du lineEdit
                    ui->lineEdit->clear();
                    displayPileInWindow();
                }else{
                    throw (calculatrice_exception("Impossible d'empiler le complexe, vous devez être en mode complexe."));
                }

           }else if(StringIsExpression(textField))
           {
               // Supression des ' avant d'empiler l'expression
                 textField = textField.remove(0,1);
                 textField = textField.remove(textField.size()-1,1);
                 pile.push(new expression(textField));
                 ui->lineEdit->clear();
                 displayPileInWindow();

           }else if(textField=="EVAL")
           {
                treatEVALExp();
           }else if(isValidBinaryOperator(textField))
           {
                element * res=makeBinaryOperation(textField);
                if(res!=0)
                {
                    // On fait un clear du lineEdit
                    pile.push(convertElementResultat(res));
                    ui->lineEdit->clear();
                    displayPileInWindow();
                }
           }else if(isValidUnaryOperator(textField))
           {
                element * res=makeUnaryOperation(textField);
                if(res!=0)
                {
                    // On fait un clear du lineEdit
                    pile.push(convertElementResultat(res));
                    ui->lineEdit->clear();
                    displayPileInWindow();
                }
           }else if(textField=="CLEAR")
           {
                pile.clear();
                displayPileInWindow();
                ui->lineEdit->clear();
           }else if(textField=="DROP")
           {
                DROP();
                displayPileInWindow();
                ui->lineEdit->clear();
           }else if(textField=="DUP")
           {
                DUP();
                displayPileInWindow();
                ui->lineEdit->clear();
           }else{
               ui->listExceptionWarning->addItem("Entrée non valide...");
           }
       }
    }catch(calculatrice_exception c){
       treatException(c);
    }

}

void MainWindow::treatElementOfExpression(QString textField)
{
   ui->listExceptionWarning->clear();

   if(StringIsInteger(textField))
   {
        int integerToPush = textField.toInt();
        if(integerToPush==0 && textField!="0")
        {
            throw calculatrice_exception("L'entier entré dépasse les capacités de la calculatrice.");
        }else{

            pile.push(new entier(integerToPush));
            displayPileInWindow();
        }
   }else if(StringIsReel(textField))
   {
            float reelToPush=textField.toFloat();         
            pile.push(new reel(reelToPush));
            displayPileInWindow();

   }else if(StringIsRationnel(textField))
   {
        QStringList listeSplit = textField.split("/");
        QString numerateurString = listeSplit.at(0);
        QString denominateurString = listeSplit.at(1);
        int numerateur = numerateurString.toInt();
        int denominateur = denominateurString.toInt();
        if((numerateur==0 && numerateurString!="0") || (denominateur==0 && denominateurString!="0"))
        {
            throw calculatrice_exception("Le rationnel entré dépasse les capacités de la calculatrice.");
        }else{

            pile.push(new rationnel(numerateur,denominateur));
            displayPileInWindow();
        }
   }else if(StringIsComplexe(textField))
   {
        if(ui->actionComplexeOui->isChecked())
        {
            pile.push(new complexe(textField));
            displayPileInWindow();
        }else{
            throw (calculatrice_exception("Impossible d'empiler le complexe, vous devez être en mode complexe."));
        }

   }else if(StringIsExpression(textField))
   {
       // Supression des ' avant d'empiler l'expression
         textField = textField.remove(0,1);
         textField = textField.remove(textField.size()-1,1);
         pile.push(new expression(textField));
         displayPileInWindow();

   }else if(isValidBinaryOperator(textField))
   {
        element * res=makeBinaryOperation(textField);
        if(res!=0)
        {
            pile.push(convertElementResultat(res));
            displayPileInWindow();
        }
   }else if(isValidUnaryOperator(textField))
   {
        element * res=makeUnaryOperation(textField);
        if(res!=0)
        {
            // On fait un clear du lineEdit
            pile.push(convertElementResultat(res));
            displayPileInWindow();
        }
   }else if(textField=="CLEAR")
        {
            pile.clear();
            displayPileInWindow();
            ui->lineEdit->clear();
        }else if(textField=="DROP")
        {
            DROP();
            displayPileInWindow();
            ui->lineEdit->clear();
        }else if(textField=="DUP")
        {
            DUP();
            displayPileInWindow();
            ui->lineEdit->clear();
        }
}

const element * MainWindow::convertElementResultat(const element * el)
{
      const element * elConvert;
      const reel * elReel = dynamic_cast<const reel*>(el);
      if(elReel!=0)
      {
         if(ui->actionEntier->isChecked())
         {
              elConvert = new entier(elReel);
              ui->listExceptionWarning->addItem("Conversion du réel: "+elReel->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
         }else{
             elConvert=el;
         }
      }else{
          const rationnel * elRationnel = dynamic_cast<const rationnel*>(el);
          if(elRationnel!=0)
          {
              if(ui->actionEntier->isChecked())
              {
                  elConvert = new entier(elRationnel);
                  ui->listExceptionWarning->addItem("Conversion du rationnel: "+elRationnel->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
              }else if(ui->actionReelle->isChecked())
              {
                  elConvert = new reel(elRationnel);
                  ui->listExceptionWarning->addItem("Conversion du rationnel: "+elRationnel->getValueString()+" en reel, résultat: "+elConvert->getValueString()+".");
              }else{
                  elConvert=el;
              }
          }else{
              const complexe * elComplexe = dynamic_cast<const complexe*>(el);
              if(elComplexe!=0)
              {
                   elConvert = new complexe(convertElementResultat(elComplexe->getPartieIm()),convertElementResultat(elComplexe->getPartieReel()));
              }else{
                   elConvert=el;
              }
          }
      }

      return elConvert;
}



void MainWindow::treatEVALExp()
{
    try{

        if(pile.isEmpty())
        {
            throw(calculatrice_exception("La pile est vide, impossible d'éffectuer l'opération unaire demandée."));
        }else{
            const element * el = pile.pop();
            const expression * elExp = dynamic_cast<const expression*>(el);
            if(elExp==0)
            {
                throw(calculatrice_exception("Impossible d'effectuer la commande EVAL, l'opérande sur lequel elle s'applique n'est pas une expression.",el));
            }else{
                // el est une expression
                displayPileInWindow();
                ui->lineEdit->setText(el->getValueString());

                QStringList listeSplit = elExp->getValueString().split(" ");
                for(int i=0;i<listeSplit.size();i++)
                {
                    treatElementOfExpression(listeSplit.at(i));
                    displayPileInWindow();
                    ui->lineEdit->setText(ui->lineEdit->text().remove(0,listeSplit.at(i).size()+1));
                }
                displayPileInWindow();

                ui->listExceptionWarning->addItem("L'évaluation de l'opération est terminé.");
            }
        }
    }catch(calculatrice_exception c){
       treatException(c);
    }
}

element * MainWindow::makeUnaryOperation(QString textField)
{
    element * res=0;

    if(pile.isEmpty())
    {
        throw(calculatrice_exception("La pile est vide, impossible d'éffectuer l'opération unaire demandée."));
    }else{
        const element * el = pile.pop();
        if(el->isComplexe() && ui->actionComplexeNon->isChecked())
        {
            throw(calculatrice_exception("Impossible d'effectuer l'opération unaire demandé sur un complexe, le mode complexe n'est pas activé.",el));
        }

        const expression * exp1 = dynamic_cast<const expression*>(el);
        if(exp1!=0)
        {
              QString newExp=el->getValueString();
              newExp.insert(newExp.size()," "+textField);
              res = new expression(newExp);
        }else if(textField=="SIN")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération SIN sur un complexe.",el));
            }else{
                if(ui->actionDegre->isChecked())
                {
                    res = SIN(el,0);
                }else{
                    res = SIN(el,1);
                }
            }
        }else if(textField=="COS")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération COS sur un complexe.",el));
            }else{
                if(ui->actionDegre->isChecked())
                {
                    res = COS(el,0);
                }else{
                    res = COS(el,1);
                }
            }
        }else if(textField=="TAN")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération TAN sur un complexe.",el));
            }else{
                if(ui->actionDegre->isChecked())
                {
                    res = TAN(el,0);
                }else{
                    res = TAN(el,1);
                }
            }
        }else if(textField=="COSH")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération COSH sur un complexe.",el));
            }else{
                if(ui->actionDegre->isChecked())
                {
                    res = COSH(el,0);
                }else{
                    res = COSH(el,1);
                }
            }
        }else if(textField=="SINH")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération SINH sur un complexe.",el));
            }else{
                if(ui->actionDegre->isChecked())
                {
                    res = SINH(el,0);
                }else{
                    res = SINH(el,1);
                }
            }
        }else if(textField=="TANH")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération TANH sur un complexe.",el));
            }else{
                if(ui->actionDegre->isChecked())
                {
                    res = TANH(el,0);
                }else{
                    res = TANH(el,1);
                }
            }
        }else if(textField=="LN")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération LN sur un complexe.",el));
            }else{
                res = LN(el);
            }
        }else if(textField=="LOG")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération LOG sur un complexe.",el));
            }else{
                res = LOG(el);
            }
        }else if(textField=="INV")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération INV sur un complexe.",el));
            }else{
                res = el->INV();
            }
        }else if(textField=="SQRT")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération SQRT sur un complexe.",el));
            }else{
                res = SQRT(el);
            }
        }else if(textField=="SQR")
        {

            res = SQR(el);

        }else if(textField=="CUBE")
        {
           res = CUBE(el);
        }else if(textField=="!")
        {
            const complexe * complexelEl = dynamic_cast<const complexe*>(el);
            if(complexelEl!=0)
            {
                throw(calculatrice_exception("Impossible d'effectuer l'opération ! sur un complexe.",el));
            }else{
                res = factorielle(el);
            }
        }else if(textField=="SUM")
        {
            if(el->isComplexe())
            {
                throw(calculatrice_exception("Impossible d'éffectuer l'opération SUM avec une opérande complexe.",el));
            }else{
                res = SUM(el);
                if(res!=0)
                {
                    const complexe * complexelElRes = dynamic_cast<const complexe*>(res);
                    if(complexelElRes!=0 && ui->actionComplexeNon->isChecked())
                    {
                        throw(calculatrice_exception("Le résultat de SUM est un complexe, impossible de l'empiler car vous n'avez pas activé le mode complexe.",el));
                    }else{
                        const reel * reelEl = dynamic_cast<const reel*>(el);
                        const entier * elConvert;
                        if(reelEl!=0)
                        {
                            elConvert = new entier(reelEl);
                        }else{
                             const rationnel * rationnelEl = dynamic_cast<const rationnel*>(el);
                             if(rationnelEl!=0)
                             {
                                 elConvert = new entier(rationnelEl);
                             }else{
                                 elConvert = dynamic_cast<const entier*>(el);
                             }
                        }
                        for(int i=0;i<elConvert->getValue();i++){pile.pop();}
                    }
                }
            }
        }else if(textField=="MEAN")
        {
            if(el->isComplexe())
            {
                throw(calculatrice_exception("Impossible d'éffectuer l'opération MEAN avec une opérande complexe.",el));
            }else{
                res = MEAN(el);
                if(res!=0)
                {
                    const complexe * complexelElRes = dynamic_cast<const complexe*>(res);
                    if(complexelElRes!=0 && ui->actionComplexeNon->isChecked())
                    {
                        throw(calculatrice_exception("Le résultat de MEAN est un complexe, impossible de l'empiler car vous n'avez pas activé le mode complexe.",el));
                    }else{
                        const reel * reelEl = dynamic_cast<const reel*>(el);
                        const entier * elConvert;
                        if(reelEl!=0)
                        {
                            elConvert = new entier(reelEl);
                        }else{
                             const rationnel * rationnelEl = dynamic_cast<const rationnel*>(el);
                             if(rationnelEl!=0)
                             {
                                 elConvert = new entier(rationnelEl);
                             }else{
                                 elConvert = dynamic_cast<const entier*>(el);
                             }
                        }
                        for(int i=0;i<elConvert->getValue();i++){pile.pop();}
                    }
                }
            }
        }
    }

    return res;
}

element * MainWindow::SQR(const element *el)
{
    const entier * entierEl = dynamic_cast<const entier*>(el);
    element * res = 0;
    if(entierEl!=0)
    {
        res = *entierEl * entierEl;
    }else{
        const reel * reelEl = dynamic_cast<const reel*>(el);
        if(reelEl!=0)
        {
            res = *reelEl * reelEl;
        }else{
            const complexe * complexeEl = dynamic_cast<const complexe*>(el);
            if(complexeEl!=0)
            {
                res = *complexeEl * complexeEl;
            }else{
                const rationnel * rationnelEl = dynamic_cast<const rationnel*>(el);
                if(rationnelEl!=0)
                {
                    res = *rationnelEl * rationnelEl;
                }
            }
        }
    }

    return res;
}

element * MainWindow::CUBE(const element *el)
{
    element * res;
    const complexe * complexeEl = dynamic_cast<const complexe*>(el);
    if(complexeEl!=0)
    {
        element * elRes = treatComplexeFois(el,el);
        const complexe * complexeElRes = dynamic_cast<const complexe*>(elRes);
        res = *complexeElRes *complexeEl;
    }else{
        res = multiplierElement(el,multiplierElement(el,el));
    }

    return res;
}

bool MainWindow::StringIsExpression(QString textField)
{
    bool isOk=true;
    QRegExp Exp("^'.+'$");
    if(!textField.contains(Exp))
    {
        isOk=false;
    }

    return isOk;
}

bool MainWindow::StringIsInteger(QString text)
{
    bool isOk=true;
    QRegExp Exp("^[-|\\d][\\d]*$");
    if(!text.contains(Exp) || text=="-")
    {
        isOk=false;
    }

    return isOk;
}

bool MainWindow::StringIsReel(QString text)
{
    bool isOk=true;
    QRegExp Exp("^[-|\\d][\\d]*\\.[\\d]+$");
    if(!text.contains(Exp))
    {
        isOk=false;
    }

    return isOk;
}

 bool MainWindow::StringIsComplexe(QString text)
 {
    bool isOk=true;

    if(!text.contains("$"))
    {
        isOk=false;
    }else{
        QStringList listeSplit = text.split("$");
        if(listeSplit.size()>2)
        {
            isOk=false;
        }else{
            QString pImString = listeSplit.at(0);
            QString PreelString = listeSplit.at(1);

            if(!((StringIsInteger(pImString) || StringIsRationnel(pImString) || StringIsReel(pImString))
                && (StringIsInteger(PreelString) || StringIsRationnel(PreelString) || StringIsReel(PreelString))))
            {
                isOk=false;
            }
        }
    }
    return isOk;
 }

 bool MainWindow::StringIsRationnel(QString text)
 {
    bool isOk=true;

    QRegExp Exp("^[-|\\d][\\d]*/[\\d]+$");

    if(!text.contains(Exp))
    {
        isOk=false;
    }

    QRegExp Exp2("^[-|\\d][\\d]*/0+$");
    if(text.contains(Exp2))
    {
        isOk=false;
    }

    return isOk;
 }


void MainWindow::displayPileInWindow()
{
    ui->listWidgetPileDilsplay->clear();
    int nbrItemToDisplay=ui->spinBoxNumberItemDisplay->value();
    QStack<const element*> tmp(pile);

    // ici on regarde le nombre d'éléments de la pile que l'on doit afficher et si il y en a  on les affiche
    if(nbrItemToDisplay<=pile.size()){
        for(int i=0;i<nbrItemToDisplay;i++){
            ui->listWidgetPileDilsplay->addItem(tmp.pop()->getValueString());
        }
    }else{
        for(int i=0;i<pile.size();i++){
            ui->listWidgetPileDilsplay->addItem(tmp.pop()->getValueString());
        }
    }

}

void MainWindow::treatException(calculatrice_exception c)
{
    // Ajout de l'exception dans la liste des excepitons
    ui->listExceptionWarning->addItem(c.get_info());

    const element * el1=c.get_element1();
    const element * el2=c.get_element2();

    if(el2!=0)
    {
        pile.push(el2);
    }
    if(el1!=0)
    {
        pile.push(el1);
    }
}

bool MainWindow::isInteger(QString pInt)
{
    bool isOk=true;
    QRegExp Exp("^[-|\\d][\\d]*.[0]*$");
    if(!pInt.contains(Exp))
    {
        isOk=false;
    }

    return isOk;
}

bool MainWindow::isValidBinaryOperator(QString pTF)
{
    bool isOk1=true;

    QRegExp Exp1 ("^[+|*|/]$");
    // On vérifie ici que l'opérateur est bien un opérateur valide de type binaire +, /, ou * (problème avec le - dans la RegEx donc je le traite après
    if(!pTF.contains(Exp1))
    {
        isOk1=false;
    }
    return (isOk1 || pTF=="-" || pTF=="POW" || pTF=="MOD" || pTF=="SWAP");
}

element * MainWindow::makeBinaryOperation(QString pOp)
{
    const element * el1;
    const element * el2;

    element * res=0;

    QString el1QString;
    QString el2QString;

    if(pile.isEmpty())
    {    
        throw calculatrice_exception("Il n'y a pas assez d'elements dans la pile pour effectuer l'opération: "+pOp+".");
    }else{
        el1=pile.pop();
        if(pile.isEmpty())
        {            
            throw calculatrice_exception("Il n'y a pas assez d'elements dans la pile pour effectuer l'opération: "+pOp+".",el1);
        }else{
              el2=pile.pop();

              const expression * exp1 = dynamic_cast<const expression*>(el1);
              const expression * exp2 = dynamic_cast<const expression*>(el2);
              if(exp1!=0 || exp2!=0)
              {
                  QString newExp=el1->getValueString();
                  //newExp.insert(newExp.size(),QString(" "));
                  newExp.insert(newExp.size()," "+el2->getValueString()+" "+pOp);

                   //QString newExp(exp1->getValueString()+QString(" ")+exp2->getValueString()+QString(" ")+pOp);
                   res = new expression(newExp);

              }else if(pOp=="+")
              {
                  const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                  const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
                  if((complexelEl1!=0 || complexelEl2!=0) && ui->actionComplexeNon->isChecked())
                  {
                     throw(calculatrice_exception("Impossible d'effectuer l'opération + sur un complexe, le mode complexe n'est pas activé.",el1,el2));
                  }else{
                     res=treatOperationPlus(el1,el2);
                  }
              }else if(pOp=="-")
              {
                  const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                  const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
                  if((complexelEl1!=0 || complexelEl2!=0) && ui->actionComplexeNon->isChecked())
                  {
                     throw(calculatrice_exception("Impossible d'effectuer l'opération - sur un complexe, le mode complexe n'est pas activé.",el1,el2));
                  }else{
                        // On appel treatOperationPlus en inversant le signe de el2
                      element * newEl2=el2->SIGN();
                      res=treatOperationPlus(el1,newEl2);
                  }
              }else if(pOp=="*")
              {
                  const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                  const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
                  if((complexelEl1!=0 || complexelEl2!=0) && ui->actionComplexeNon->isChecked())
                  {
                     throw(calculatrice_exception("Impossible d'effectuer l'opération * sur un complexe, le mode complexe n'est pas activé.",el1,el2));
                  }else{
                     res=treatOperationFois(el1,el2);
                  }
              }else if(pOp=="/")
              {
                  const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                  const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
                  if((complexelEl1!=0 || complexelEl2!=0) && ui->actionComplexeNon->isChecked())
                  {
                     throw(calculatrice_exception("Impossible d'effectuer l'opération / sur un complexe, le mode complexe n'est pas activé.",el1,el2));
                  }else{
                     res=treatOperationDiviser(el1,el2);
                  }
              }else if(pOp=="MOD")
              {
                  const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                  const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
                  if(complexelEl1!=0 || complexelEl2!=0)
                  {
                     throw(calculatrice_exception("Impossible d'effectuer un modulo sur un complexe.",el1,el2));
                  }else{
                     res = MOD(el1,el2);
                  }
              }else if(pOp=="POW")
              {
                  const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                  const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
                  if(complexelEl1!=0 || complexelEl2!=0)
                  {
                     throw(calculatrice_exception("Impossible d'effectuer l'opération puissance sur un complexe.",el1,el2));
                  }else{
                     res = POW(el1,el2);
                  }
              }else if(pOp=="SWAP")
              {
                  SWAP(el1,el2);
                  ui->lineEdit->clear();
                  displayPileInWindow();
              }
        }
    }

    return res;
}

element * MainWindow::treatOperationDiviser(const element * el1,const element * el2)
{
    element * res=0;

    // Si on a au moins un opérateur complexe, la fonction treatComplexeFois retournera true si l'opération a été effectué
    if(el1->isComplexe() || el2->isComplexe())
    {
        res=treatComplexeDiviser(el1,el2);
    }else{
        // si aucun opérateur n'est un complexe on tente de faire une multiplication de el1 et el2 (el1 et el2 ne sont pas des complexes)
        res=diviserElement(el1,el2);

    }
    return res;
}

element * MainWindow::treatComplexeDiviser(const element * el1,const element * el2)
{

    element * res=0;

    const entier * ent1 = dynamic_cast<const entier*>(el1);
    // ELEMENT 1 EST UN ENTIER
    if(ent1!=0)
    {
        const complexe * complexe2=dynamic_cast<const complexe*>(el2);
        if(complexe2!=0)
        {
            // ELEMENT 2 EST UN COMPLEXE
             res=*ent1/complexe2;
        }
    }else{
        const reel * reelEl1 = dynamic_cast<const reel*>(el1);
        if(reelEl1!=0)
        {
            //ELEMENT 1 EST UN REEL
            const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
            if(complexelEl2!=0)
            {
                //ELEMENT 2 EST UN COMPLEXE
                res=*reelEl1/complexelEl2;
            }
        }else{
            const rationnel * rationnelEl1 = dynamic_cast<const rationnel*>(el1);
            if(rationnelEl1!=0)
            {
                // L'ELEMENT 1 EST UN RATIONNEL
                const complexe * complexeEl2 = dynamic_cast<const complexe*>(el2);
                if(complexeEl2!=0)
                {
                    //L'ELEMENT 2 EST UN COMPLEXE
                    res=*rationnelEl1/complexeEl2;
                }
            }else{
                const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                if(complexelEl1!=0)
                {
                    // L'ELEMENT 1 EST UN COMPLEXE
                    const complexe * complexeEl2 = dynamic_cast<const complexe*>(el2);
                    if(complexeEl2!=0)
                    {
                        //L'ELEMENT 2 EST UN COMPLEXE
                        res=*complexelEl1/complexeEl2;
                    }else{                      
                        const entier * entierEl2 = dynamic_cast<const entier*>(el2);
                        if(entierEl2!=0)
                        {
                             //L'ELEMENT 2 EST UN ENTIER
                            res=*complexelEl1/entierEl2;
                        }else{
                            const reel * reelEl2 = dynamic_cast<const reel*>(el2);
                            if(reelEl2!=0)
                            {
                                //L'ELEMENT 2 EST UN REEL
                                res=*complexelEl1/reelEl2;
                            }else{
                                const rationnel * rationnelEl2 = dynamic_cast<const rationnel*>(el2);
                                if(rationnelEl2!=0)
                                {
                                    //L'ELEMENT 2 EST UN RATIONNEL
                                    res=*complexelEl1/rationnelEl2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return res;


}

element * MainWindow::treatComplexeFois(const element * el1,const element * el2)
{
    element * res=0;

    const entier * ent1 = dynamic_cast<const entier*>(el1);

    // ELEMENT 1 EST UN ENTIER
    if(ent1!=0)
    {
        const complexe * complexe2=dynamic_cast<const complexe*>(el2);
        if(complexe2!=0)
        {
            // ELEMENT 2 EST UN COMPLEXE
             res=*ent1*complexe2;
        }
    }else{
        const reel * reelEl1 = dynamic_cast<const reel*>(el1);
        if(reelEl1!=0)
        {
            //ELEMENT 1 EST UN REEL
            const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
            if(complexelEl2!=0)
            {
                //ELEMENT 2 EST UN COMPLEXE
                res=*reelEl1*complexelEl2;
            }
        }else{
            const rationnel * rationnelEl1 = dynamic_cast<const rationnel*>(el1);
            if(rationnelEl1!=0)
            {
                // L'ELEMENT 1 EST UN RATIONNEL
                const complexe * complexeEl2 = dynamic_cast<const complexe*>(el2);
                if(complexeEl2!=0)
                {
                    //L'ELEMENT 2 EST UN COMPLEXE
                    res=*rationnelEl1*complexeEl2;
                }
            }else{
                const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                if(complexelEl1!=0)
                {
                    // L'ELEMENT 1 EST UN COMPLEXE
                    const complexe * complexeEl2 = dynamic_cast<const complexe*>(el2);
                    if(complexeEl2!=0)
                    {
                        //L'ELEMENT 2 EST UN COMPLEXE
                        res=*complexelEl1*complexeEl2;
                    }
                }
            }
        }
    }

    // Si on a pas effectué d'opération on rappel la fonction en échangeant el1 et el2
    if(res==0)
    {
        res=treatComplexeFois(el2, el1);
    }

    return res;
}


// Traite le cas ou un opérateur au moins est un complexe, retourne true si l'opération a été effectué
element * MainWindow::treatComplexePlus(const element* el1,const element * el2)
{
    //bool opDone=true;
    element * res=0;

    const entier * ent1 = dynamic_cast<const entier*>(el1);

    // ELEMENT 1 EST UN ENTIER
    if(ent1!=0)
    {
        const complexe * complexe2=dynamic_cast<const complexe*>(el2);
        if(complexe2!=0)
        {
            // ELEMENT 2 EST UN COMPLEXE
             res=*ent1+complexe2;
             //pile.push(res);
        }
    }else{
        const reel * reelEl1 = dynamic_cast<const reel*>(el1);
        if(reelEl1!=0)
        {
            //ELEMENT 1 EST UN REEL
            const complexe * complexelEl2 = dynamic_cast<const complexe*>(el2);
            if(complexelEl2!=0)
            {
                //ELEMENT 2 EST UN COMPLEXE
                res=*reelEl1+complexelEl2;
                //pile.push(res);
            }
        }else{
            const rationnel * rationnelEl1 = dynamic_cast<const rationnel*>(el1);
            if(rationnelEl1!=0)
            {
                // L'ELEMENT 1 EST UN RATIONNEL
                const complexe * complexeEl2 = dynamic_cast<const complexe*>(el2);
                if(complexeEl2!=0)
                {
                    //L'ELEMENT 2 EST UN COMPLEXE
                    res=*rationnelEl1+complexeEl2;
                    //pile.push(res);
                }
            }else{
                const complexe * complexelEl1 = dynamic_cast<const complexe*>(el1);
                if(complexelEl1!=0)
                {
                    // L'ELEMENT 1 EST UN COMPLEXE
                    const complexe * complexeEl2 = dynamic_cast<const complexe*>(el2);
                    if(complexeEl2!=0)
                    {
                        //L'ELEMENT 2 EST UN COMPLEXE
                        res=*complexelEl1+complexeEl2;
                        //pile.push(res);
                    }
                }
            }
        }
    }

    // Si on a pas effectué d'opération on rappel la fonction en échangeant el1 et el2
    if(res==0)
    {
        res=treatComplexePlus(el2, el1);
    }

    return res;
}

element * MainWindow::treatOperationFois(const element * el1,const element * el2)
{
    element * res=0;

    // Si on a au moins un opérateur complexe, la fonction treatComplexeFois retournera true si l'opération a été effectué
    if(el1->isComplexe() || el2->isComplexe())
    {
        res=treatComplexeFois(el1,el2);
    }else{
        // si aucun opérateur n'est un complexe on tente de faire une multiplication de el1 et el2 (el1 et el2 ne sont pas des complexes)
        res=multiplierElement(el1,el2);   
    }

    return res;

}


 element * MainWindow::treatOperationPlus(const element* el1,const element* el2)
 {
    element * res=0;

    // Si on a au moins un opérateur complexe, la fonction treatComplexePlus retournera true si l'opération a été effectué
    if(el1->isComplexe() || el2->isComplexe())
    {
        res=treatComplexePlus(el1,el2);
    }else{
        // si aucun opérateur n'est un complexe on tente de faire une addtion de el1 et el2 (el1 et el2 ne sont pas des complexes)
        res=additionerElement(el1,el2);
        // l'opération s'est bien déroulé
    }

    return res;
}

 element * MainWindow::multiplierElement(const element * el1,const element * el2)
 {
      //Ce booleen sert à savoir si on doit échanger el1 et el2 pour pouvoir effectuer l'addition (si on est passé dans aucun des if)
    bool exchangeEl1El2=false;
    element * res=0;

    const entier * ent1 = dynamic_cast<const entier*>(el1);
    if(ent1!=0)
    {
        //EL1 EST UN ENTIER
        const entier * ent2=dynamic_cast<const entier*>(el2);
        if(ent2!=0)
        {
            //EL2 EST UN ENTIER
             res=(*ent1*(ent2));
        }else{
            const reel * reel2=dynamic_cast<const reel*>(el2);
            // EL2 EST UN REEL
            if(reel2!=0)
            {
                res=*ent1*(reel2);
            }else{
                const rationnel * rationnel2=dynamic_cast<const rationnel*>(el2);
                if(rationnel2!=0)
                {
                    // EL2 EST UN RATIONNEL
                    res=*ent1*(rationnel2);
                }
            }
        }
    }else{
        const reel * reelEl1 = dynamic_cast<const reel*>(el1);
        if(reelEl1!=0)
        {
            //ELEMENT 1 EST UN REEL
            const entier * ent2=dynamic_cast<const entier*>(el2);
            if(ent2!=0)
            {
                // ELEMENT 2 EST UN ENTIER
                res=*ent2*(reelEl1);
            }else{
                const reel * reelEl2 = dynamic_cast<const reel*>(el2);
                if(reelEl2!=0)
                {
                    //ELEMENT 2 EST UN REEL
                    res=*reelEl1*(reelEl2);
                }else{
                    const rationnel * rationnelEl2 = dynamic_cast<const rationnel*>(el2);
                    if(rationnelEl2!=0)
                    {
                        // EL2 EST UN RATIONNEL
                        res=*reelEl1*(rationnelEl2);
                    }
                }
            }
        }else{
            const rationnel * rationnelEl1 = dynamic_cast<const rationnel*>(el1);
            if(rationnelEl1!=0)
            {
                // L'ELEMENT 1 EST UN RATIONNEL
                const rationnel * rationnelEl2 = dynamic_cast<const rationnel*>(el2);
                if(rationnelEl2!=0)
                {
                    //L'ELEMENT 2 EST AUSSI UN RATIONNEL
                    res=*rationnelEl1*(rationnelEl2);
                }else{
                    exchangeEl1El2=true;
                }
            }else{
                exchangeEl1El2=true;
            }
        }
    }

    if(exchangeEl1El2==true)
    {
        return(multiplierElement(el2,el1));
    }else{
        return(res);
    }

 }

 element * MainWindow::diviserElement(const element * el1,const element * el2)
 {
    element * res=0;

    const entier * ent1 = dynamic_cast<const entier*>(el1);
    if(ent1!=0)
    {
        //EL1 EST UN ENTIER
        const entier * ent2=dynamic_cast<const entier*>(el2);
        if(ent2!=0)
        {
            //EL2 EST UN ENTIER
             res=(*ent1/(ent2));
        }else{
            const reel * reel2=dynamic_cast<const reel*>(el2);
            // EL2 EST UN REEL
            if(reel2!=0)
            {
                res=*ent1/(reel2);
            }else{
                const rationnel * rationnel2=dynamic_cast<const rationnel*>(el2);
                if(rationnel2!=0)
                {
                    // EL2 EST UN RATIONNEL
                    res=*ent1/(rationnel2);
                }
            }
        }
    }else{
        const reel * reelEl1 = dynamic_cast<const reel*>(el1);
        if(reelEl1!=0)
        {
            //ELEMENT 1 EST UN REEL
            const entier * ent2=dynamic_cast<const entier*>(el2);
            if(ent2!=0)
            {
                // ELEMENT 2 EST UN ENTIER
                res=*ent2/(reelEl1);
            }else{
                const reel * reelEl2 = dynamic_cast<const reel*>(el2);
                if(reelEl2!=0)
                {
                    //ELEMENT 2 EST UN REEL
                    res=*reelEl1/(reelEl2);
                }else{
                    const rationnel * rationnelEl2 = dynamic_cast<const rationnel*>(el2);
                    if(rationnelEl2!=0)
                    {
                        // EL2 EST UN RATIONNEL
                        res=*reelEl1/(rationnelEl2);
                    }
                }
            }
        }else{
            const rationnel * rationnelEl1 = dynamic_cast<const rationnel*>(el1);
            if(rationnelEl1!=0)
            {
                // L'ELEMENT 1 EST UN RATIONNEL
                const rationnel * rationnelEl2 = dynamic_cast<const rationnel*>(el2);
                if(rationnelEl2!=0)
                {
                    //L'ELEMENT 2 EST AUSSI UN RATIONNEL
                    res=*rationnelEl1/(rationnelEl2);
                }else{
                    const entier * entierEl2 = dynamic_cast<const entier*>(el2);
                    if(entierEl2!=0)
                    {
                         //L'ELEMENT 2 EST UN ENTIER
                        res=*rationnelEl1/(entierEl2);
                    }else{
                        const reel * reelEl2 = dynamic_cast<const reel*>(el2);
                        if(reelEl2!=0)
                        {
                             //L'ELEMENT 2 EST UN REEL
                            res=*rationnelEl1/(reelEl2);
                        }
                    }
                }
            }
        }
    }
    return res;
 }


element * MainWindow::additionerElement(const element * el1,const element * el2)
{
    //Ce booleen sert à savoir si on doit échanger el1 et el2 pour pouvoir effectuer l'addition (si on est passé dans aucun des if)
    bool exchangeEl1El2=false;
    element * res=0;

    const entier * ent1 = dynamic_cast<const entier*>(el1);
    if(ent1!=0)
    {
        //EL1 EST UN ENTIER
        const entier * ent2=dynamic_cast<const entier*>(el2);
        if(ent2!=0)
        {
            //EL2 EST UN ENTIER
             res=(*ent1+ent2);
        }else{
            const reel * reel2=dynamic_cast<const reel*>(el2);
            // EL2 EST UN REEL
            if(reel2!=0)
            {
                res=*ent1+reel2;
            }else{
                const rationnel * rationnel2=dynamic_cast<const rationnel*>(el2);
                if(rationnel2!=0)
                {
                    // EL2 EST UN RATIONNEL
                    res=*ent1+rationnel2;
                }
            }
        }
    }else{
        const reel * reelEl1 = dynamic_cast<const reel*>(el1);
        if(reelEl1!=0)
        {
            //ELEMENT 1 EST UN REEL
            const entier * ent2=dynamic_cast<const entier*>(el2);
            if(ent2!=0)
            {
                // ELEMENT 2 EST UN ENTIER
                res=*ent2+reelEl1;
            }else{
                const reel * reelEl2 = dynamic_cast<const reel*>(el2);
                if(reelEl2!=0)
                {
                    //ELEMENT 2 EST UN REEL
                    res=*reelEl1+reelEl2;
                }else{
                    const rationnel * rationnelEl2 = dynamic_cast<const rationnel*>(el2);
                    if(rationnelEl2!=0)
                    {
                        // EL2 EST UN RATIONNEL
                        res=*reelEl1+rationnelEl2;
                    }
                }
            }
        }else{
            const rationnel * rationnelEl1 = dynamic_cast<const rationnel*>(el1);
            if(rationnelEl1!=0)
            {
                // L'ELEMENT 1 EST UN RATIONNEL
                const rationnel * rationnelEl2 = dynamic_cast<const rationnel*>(el2);
                if(rationnelEl2!=0)
                {
                    //L'ELEMENT 2 EST AUSSI UN RATIONNEL
                    res=*rationnelEl1+rationnelEl2;
                }else{
                    exchangeEl1El2=true;
                }
            }else{
                exchangeEl1El2=true;
            }
        }
    }

    if(exchangeEl1El2==true)
    {
        return(additionerElement(el2,el1));
    }else{
        return(res);
    }
}

void MainWindow::delPressButton()
{
    if(ui->lineEdit->text().isEmpty())
    {
        DROP();
        displayPileInWindow();
    }else{
        ui->lineEdit->backspace();
    }
}

void MainWindow::plusPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"+");
}
void MainWindow::foisPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"*");
}
void MainWindow::divisePressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"/");
}
void MainWindow::moinsPressButton(){
    ui->lineEdit->setText(ui->lineEdit->text()+"-");
}

void MainWindow::espacePressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+" ");
}

void MainWindow::commaPressButton(){
    ui->lineEdit->setText(ui->lineEdit->text()+".");
}

void MainWindow::powPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"POW");
}
void MainWindow::modPressButton()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"MOD");
}

void MainWindow::menuActionComplexeOui()
{
    ui->actionComplexeNon->setChecked(false);
    ui->actionComplexeOui->setChecked(true);
}

void MainWindow::menuActionComplexeNon()
{
    ui->actionComplexeOui->setChecked(false);
    ui->actionComplexeNon->setChecked(true);
}

void MainWindow::menuActionClavierOui()
{
    ui->actionClavierNon->setChecked(false);
    ui->actionClavierOui->setChecked(true);
    actualiseWindowKeyboard();
}

void MainWindow::menuActionClavierNon()
{
    ui->actionClavierOui->setChecked(false);
    ui->actionClavierNon->setChecked(true);
    actualiseWindowKeyboard();
}

void MainWindow::menuConstanteEntier(){

    // ici on rend les autres bouton à checked = false pour que l'on est toujours q'un bouton du menu coché
    ui->actionEntier->setChecked(true);
    ui->actionReelle->setChecked(false);
    ui->actionRationelle->setChecked(false);
}

void MainWindow::menuUniteDegre(){
    ui->actionRadiant->setChecked(false);
    ui->actionDegre->setChecked(true);
}

void MainWindow::menuUniteRadiant(){
    ui->actionDegre->setChecked(false);
    ui->actionRadiant->setChecked(true);
}

void MainWindow::menuConstanteReelle(){
    // ici on rend les autres bouton à checked = false pour que l'on est toujours q'un bouton du menu coché
    ui->actionReelle->setChecked(true);
    ui->actionEntier->setChecked(false);
    ui->actionRationelle->setChecked(false);
}

void MainWindow::menuConstanteRationelle(){
    // ici on rend les autres bouton à checked = false pour que l'on est toujours q'un bouton du menu coché
    ui->actionRationelle->setChecked(true);
    ui->actionReelle->setChecked(false);
    ui->actionEntier->setChecked(false);
}

reel * MainWindow::SIN(const element * el, int mode)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0 && mode==0)
    {
        //el est un entier et le mode est 0 (degré)
        // on retourne un reel dont la valeur est le sinus de la value de l'entier exprimé en degré
        // on convertit donc la value de l'entier en radiant car qSin prend en paramètre un angle exprimé en radiant
        res = new reel(qSin(giveAngleRadians(elEntier->getValue())));
    }else if(elEntier!=0 && mode==1)
    {
        // Mode radiant
        res = new reel(qSin(elEntier->getValue()));
    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0 && mode==0)
        {
           //el est un reel et le mode est 0 (degré)
           res = new reel(qSin(giveAngleRadians(elReel->getValue())));
        }else if(elReel!=0 && mode==1)
        {
            // Mode radiant
            res = new reel(qSin(elReel->getValue()));
        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            if(mode==0)
            {
                // Mode degré
                res = new reel(qSin(giveAngleRadians(elRationnel->giveValeurReel())));

            }else if(mode ==1)
            {
                res = new reel(qSin(elRationnel->giveValeurReel()));
                //Mode Radiant
            }
        }
    }

    return(res);
}

reel * MainWindow::COS(const element * el, int mode)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0 && mode==0)
    {
        //el est un entier et le mode est 0 (degré)
        // on retourne un reel dont la valeur est le cosinus de la value de l'entier exprimé en degré
        // on convertit donc la value de l'entier en radiant car qCos prend en paramètre un angle exprimé en radiant
        res = new reel(qCos(giveAngleRadians(elEntier->getValue())));
    }else if(elEntier!=0 && mode==1)
    {
        // Mode radiant
        res = new reel(qCos(elEntier->getValue()));
    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0 && mode==0)
        {
           //el est un reel et le mode est 0 (degré)
           res = new reel(qCos(giveAngleRadians(elReel->getValue())));
        }else if(elReel!=0 && mode==1)
        {
            // Mode radiant
            res = new reel(qCos(elReel->getValue()));
        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            if(mode==0)
            {
                // Mode degré
                res = new reel(qCos(giveAngleRadians(elRationnel->giveValeurReel())));

            }else if(mode ==1)
            {
                res = new reel(qCos(elRationnel->giveValeurReel()));
                //Mode Radiant
            }
        }
    }
    return(res);
}

reel * MainWindow::TAN(const element * el, int mode)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0 && mode==0)
    {
        res = new reel(tan(giveAngleRadians(elEntier->getValue())));
    }else if(elEntier!=0 && mode==1)
    {
        // Mode radiant
        res = new reel(tan(elEntier->getValue()));
    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0 && mode==0)
        {
           //el est un reel et le mode est 0 (degré)
           res = new reel(tan(giveAngleRadians(elReel->getValue())));
        }else if(elReel!=0 && mode==1)
        {
            // Mode radiant
            res = new reel(tan(elReel->getValue()));
        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            if(mode==0)
            {
                // Mode degré
                res = new reel(tan(giveAngleRadians(elRationnel->giveValeurReel())));

            }else if(mode ==1)
            {
                res = new reel(tan(elRationnel->giveValeurReel()));
                //Mode Radiant
            }
        }
    }
    return(res);
}

reel * MainWindow::SINH(const element * el, int mode)
{
   reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0 && mode==0)
    {
        res = new reel(sinh(giveAngleRadians(elEntier->getValue())));
    }else if(elEntier!=0 && mode==1)
    {
        // Mode radiant
        res = new reel(sinh(elEntier->getValue()));
    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0 && mode==0)
        {
           //el est un reel et le mode est 0 (degré)
           res = new reel(sinh(giveAngleRadians(elReel->getValue())));
        }else if(elReel!=0 && mode==1)
        {
            // Mode radiant
            res = new reel(sinh(elReel->getValue()));
        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            if(mode==0)
            {
                // Mode degré
                res = new reel(sinh(giveAngleRadians(elRationnel->giveValeurReel())));

            }else if(mode ==1)
            {
                res = new reel(sinh(elRationnel->giveValeurReel()));
                //Mode Radiant
            }
        }
    }
    return(res);
}

reel * MainWindow::COSH(const element * el, int mode)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0 && mode==0)
    {
        res = new reel(cosh(giveAngleRadians(elEntier->getValue())));
    }else if(elEntier!=0 && mode==1)
    {
        // Mode radiant
        res = new reel(cosh(elEntier->getValue()));
    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0 && mode==0)
        {
           //el est un reel et le mode est 0 (degré)
           res = new reel(cosh(giveAngleRadians(elReel->getValue())));
        }else if(elReel!=0 && mode==1)
        {
            // Mode radiant
            res = new reel(cosh(elReel->getValue()));
        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            if(mode==0)
            {
                // Mode degré
                res = new reel(cosh(giveAngleRadians(elRationnel->giveValeurReel())));

            }else if(mode ==1)
            {
                res = new reel(cosh(elRationnel->giveValeurReel()));
                //Mode Radiant
            }
        }
    }
    return(res);
}


reel * MainWindow::TANH(const element * el, int mode)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0 && mode==0)
    {
        res = new reel(tanh(giveAngleRadians(elEntier->getValue())));
    }else if(elEntier!=0 && mode==1)
    {
        // Mode radiant
        res = new reel(tanh(elEntier->getValue()));
    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0 && mode==0)
        {
           //el est un reel et le mode est 0 (degré)
           res = new reel(tanh(giveAngleRadians(elReel->getValue())));
        }else if(elReel!=0 && mode==1)
        {
            // Mode radiant
            res = new reel(tanh(elReel->getValue()));
        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            if(mode==0)
            {
                // Mode degré
                res = new reel(tanh(giveAngleRadians(elRationnel->giveValeurReel())));

            }else if(mode ==1)
            {
                res = new reel(tanh(elRationnel->giveValeurReel()));
                //Mode Radiant
            }
        }
    }
    return(res);
}

reel * MainWindow::LN(const element * el)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0)
    {
        int value = elEntier->getValue();
        if(value<=0)
        {
            throw(calculatrice_exception("Impossible d'éffectuer LN de "+el->getValueString()+" , l'opérande doit être positive.",el));
        }else{
            res = new reel(qLn(value));
        }

    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0)
        {
           //el est un reel
            float value = elReel->getValue();
            if(value<=0)
            {
                 throw(calculatrice_exception("Impossible d'éffectuer LN de "+el->getValueString()+" , l'opérande doit être positive.",el));
            }else{
                res = new reel(qLn(value));
            }

        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            float value = elRationnel->giveValeurReel();
            if(value<=0)
            {
                 throw(calculatrice_exception("Impossible d'éffectuer LN de "+el->getValueString()+" , l'opérande doit être positive.",el));
            }else{
                res = new reel(qLn(value));
            }
        }
    }
    return(res);
}

reel * MainWindow::LOG(const element * el)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0)
    {
        int value = elEntier->getValue();
        if(value<=0)
        {
            throw(calculatrice_exception("Impossible d'éffectuer LOG de "+el->getValueString()+" , l'opérande doit être positive.",el));
        }else{
            res = new reel(log(value));
        }

    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0)
        {
           //el est un reel
            float value = elReel->getValue();
            if(value<=0)
            {
                 throw(calculatrice_exception("Impossible d'éffectuer LOG de "+el->getValueString()+" , l'opérande doit être positive.",el));
            }else{
                res = new reel(log(value));
            }

        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            float value = elRationnel->giveValeurReel();
            if(value<=0)
            {
                 throw(calculatrice_exception("Impossible d'éffectuer LOG de "+el->getValueString()+" , l'opérande doit être positive.",el));
            }else{
                res = new reel(log(value));
            }
        }
    }
    return(res);
}

reel * MainWindow::SQRT(const element * el)
{
    reel * res=0;

    const entier * elEntier= dynamic_cast<const entier*>(el);
    if(elEntier!=0)
    {
        int value = elEntier->getValue();
        if(value<0)
        {
            throw(calculatrice_exception("Impossible d'éffectuer SQRT de "+el->getValueString()+" , l'opérande doit être positive ou nulle.",el));
        }else{
            res = new reel(sqrt(value));
        }

    }else{
        const reel * elReel= dynamic_cast<const reel*>(el);
        if(elReel!=0)
        {
           //el est un reel
            float value = elReel->getValue();
            if(value<0)
            {
                 throw(calculatrice_exception("Impossible d'éffectuer SQRT de "+el->getValueString()+" , l'opérande doit être positive ou nulle.",el));
            }else{
                res = new reel(sqrt(value));
            }

        }else{
            const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
            //el est un rationnel
            float value = elRationnel->giveValeurReel();
            if(value<0)
            {
                 throw(calculatrice_exception("Impossible d'éffectuer SQRT de "+el->getValueString()+" , l'opérande doit être positive ou nulle.",el));
            }else{
                res = new reel(sqrt(value));
            }
        }
    }
    return(res);
}

element  * MainWindow::factorielle(const element * el)
{
    const reel * reelEl = dynamic_cast<const reel*>(el);
    const entier * elConvert;
    if(reelEl!=0)
    {
        elConvert = new entier(reelEl);
        ui->listExceptionWarning->addItem("Conversion de "+el->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
    }else{
         const rationnel * rationnelEl = dynamic_cast<const rationnel*>(el);
         if(rationnelEl!=0)
         {
             elConvert = new entier(rationnelEl);
             ui->listExceptionWarning->addItem("Conversion de "+el->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
         }else{
             elConvert = dynamic_cast<const entier*>(el);
         }
    }

    int value = elConvert->getValue();
    if(value<1)
    {
        throw(calculatrice_exception("Impossible d'éffectuer la factorielle de "+elConvert->getValueString()+", l'opérande doit être supérieure ou égale à 1.",el));
    }else{
        return(new entier(factorielle(value)));
    }
}

entier  * MainWindow::MOD(const element * el1, const element * el2)
{
    const entier * ent1= dynamic_cast<const entier*>(el1);
    if(ent1==0)
    {
       ent1= new entier(el1);
       ui->listExceptionWarning->addItem("Conversion de "+el1->getValueString()+" en entier, résultat: "+ent1->getValueString()+".");
    }

    const entier * ent2= dynamic_cast<const entier*>(el2);
    if(ent2==0)
    {
       ent2= new entier(el2);
       ui->listExceptionWarning->addItem("Conversion de "+el2->getValueString()+" en entier, résultat: "+ent2->getValueString()+".");
    }

    if(ent2->getValue()==0)
    {
        throw(calculatrice_exception("Impossible de diviser par zéro.",el1,el2));
    }else{
        return(new entier(fmod(ent1->getValue(),ent2->getValue())));
    }
}

int MainWindow::factorielle(int n)
{
    if(n==1)
    {
        return 1;
    }else{
        return( n * factorielle(n-1));
    }
}

float MainWindow::giveAngleRadians(float pAngleDegre)
{
    return(PI * (pAngleDegre) / 180);
}

element * MainWindow::POW(const element * el1, const element * el2)
{
    element * res=0;
    const entier * el1Entier= dynamic_cast<const entier*>(el1);
    if(el1Entier!=0)
    {
        //el1 est un entier
        const entier * el2Entier = dynamic_cast<const entier*>(el2);
        if(el2Entier!=0)
        {
            // el2 est un entier
            res = new entier(pow(el1Entier->getValue(),el2Entier->getValue()));
        }else{
            const reel * el2Reel= dynamic_cast<const reel*>(el2);
            if(el2Reel!=0)
            {
                //el2 est un reel
                res  = new reel(pow(el1Entier->getValue(),el2Reel->getValue()));
            }else{
                const rationnel * el2Rationnel= dynamic_cast<const rationnel*>(el2);
                if(el2Rationnel!=0)
                {
                    //el2 est un rationnel
                    res = new reel(pow(el1Entier->getValue(),el2Rationnel->giveValeurReel()));
                }
            }
        }
    }else{
        const reel * el1Reel= dynamic_cast<const reel*>(el1);
        if(el1Reel!=0)
        {
            //el1 est un reel
            const entier * el2Entier= dynamic_cast<const entier*>(el2);
            if(el2Entier!=0)
            {
                // el2 est un entier
                res = new reel(pow(el1Reel->getValue(),el2Entier->getValue()));
            }else{
                const reel * el2Reel= dynamic_cast<const reel*>(el2);
                if(el2Reel!=0)
                {
                    //el2 est un reel
                    res = new reel(pow(el1Reel->getValue(),el2Reel->getValue()));
                }else{
                    const rationnel * el2Rationnel= dynamic_cast<const rationnel*>(el2);
                    if(el2Rationnel!=0)
                    {
                        // el2 est un rationnel
                        res = new reel(pow(el1Reel->getValue(),el2Rationnel->giveValeurReel()));
                    }
                }
            }
        }else{
            const rationnel * el1Rationnel= dynamic_cast<const rationnel*>(el1);
            if(el1Rationnel!=0)
            {
                // el1 est un rationnel
                const entier * el2Entier= dynamic_cast<const entier*>(el2);
                if(el2Entier!=0)
                {
                    //el2 est un entier
                    res =  new rationnel(pow(el1Rationnel->getNum(),el2Entier->getValue()),pow(el1Rationnel->getDeno(),el2Entier->getValue()));
                }else{
                    const reel * el2Reel= dynamic_cast<const reel*>(el2);
                    if(el2Reel!=0)
                    {
                        //el2 est un reel
                        res = new reel(pow(el1Rationnel->giveValeurReel(),el2Reel->getValue()));
                    }else{
                        const rationnel * el2Rationnel= dynamic_cast<const rationnel*>(el2);
                        if(el2Rationnel!=0)
                        {
                            //el2 est un rationnel
                            res = new reel(pow(el1Rationnel->giveValeurReel(),el2Rationnel->giveValeurReel()));
                        }
                    }
                }
            }
        }
    }

    return res;
}


 bool MainWindow::isValidUnaryOperator(QString pOp)
{
    bool isOk=true;
    /*
    Les types entre parenthèses sont les types disponibles pour l'utilisation de
    l'opérateur :
    ? SIN : sinus (entier, rationnel, réel)
    ? COS : cosinus (entier, rationnel, réel)
    ? TAN : tangente (entier, rationnel, réel)
    ? SINH : sinus hyperbolique (entier, rationnel, réel)
    ? COSH : cosinus hyperbolique (entier, rationnel, réel)
    ? TANH : tangente hyperbolique (entier, rationnel, réel)
    ? LN : logarithme népérien (entier, rationnel, réel)
    ? LOG : logarithme décimal (entier, rationnel, réel)
    ? INV : inverse (entier, rationnel, réel)
    ? SQRT : racine carré (entier, rationnel, réel)
    ? SQR : fonction carré (entier, rationnel, réel, complexe)
    ? CUBE : fonction cube (entier, rationnel, réel, complexe)
    ? ! : factorielle (entier)
    ? EVAL : évaluation d'une expression (Expression)

    */

    QRegExp Exp ("^(SIN|COS|TAN|SINH|COSH|TANH|LN|LOG|INV|SQRT|SQR|CUBE|EVAL|!|SUM|MEAN)$");
    // On vérifie ici que l'opérateur est bien un opérateur valide de type unaire
    if(!pOp.contains(Exp))
    {
        isOk=false;
    }
    return (isOk);
}

element * MainWindow::MEAN(const element * el)
{
    element * res=0;
    const reel * reelEl = dynamic_cast<const reel*>(el);
    const entier * elConvert;
    if(reelEl!=0)
    {
        elConvert = new entier(reelEl);
        ui->listExceptionWarning->addItem("Conversion de "+el->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
    }else{
         const rationnel * rationnelEl = dynamic_cast<const rationnel*>(el);
         if(rationnelEl!=0)
         {
             elConvert = new entier(rationnelEl);
             ui->listExceptionWarning->addItem("Conversion de "+el->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
         }else{
             elConvert = dynamic_cast<const entier*>(el);
         }
    }

    int value = elConvert->getValue();
    if(value<=1)
    {
        throw(calculatrice_exception("Impossible d'éffectuer MEAN "+elConvert->getValueString()+", l'opérande doit être supérieure à 1.",el));
    }else if(value>pile.size())
    {
        throw(calculatrice_exception("Impossible d'éffectuer MEAN de "+elConvert->getValueString()+", l'opérande est plus grande que la taille de la pile.",el));
    }else{
        QStack<const element*> tmp(pile);
        bool resEstUnComplexe = false;
        int i=2;
        const element * el1=tmp.pop();
        const element * el2=tmp.pop();

        const expression * elExp1= dynamic_cast<const expression*>(el1);
        const expression * elExp2= dynamic_cast<const expression*>(el2);
        if(elExp1!=0 || elExp2!=0)
        {
            throw(calculatrice_exception("Impossible d'éffectuer un MEAN avec une expression.",el));
        }else{
             const complexe * elComplexe1= dynamic_cast<const complexe*>(el1);
             const complexe * elComplexe2= dynamic_cast<const complexe*>(el2);
             if(elComplexe1!=0 || elComplexe2!=0)
             {
                 res = treatComplexePlus(el1,el2);
                 resEstUnComplexe = true;
             }else{
                 res = additionerElement(el1,el2);
             }
        }

        while(i<value)
        {
             const element * elAajouter = tmp.pop();
             const complexe * elComplexe= dynamic_cast<const complexe*>(elAajouter);
             if(elComplexe!=0)
             {
                 res = treatComplexePlus(res,elComplexe);
                 resEstUnComplexe = true;
             }else
             {
                 const expression * elAajouterExp= dynamic_cast<const expression*>(elAajouter);
                 if(elAajouterExp!=0)
                 {
                      throw(calculatrice_exception("Impossible d'éffectuer un SUM avec une expression.",el));
                 }else if(resEstUnComplexe)
                 {
                     res = treatComplexePlus(res,elAajouter);
                 }else{
                     res = additionerElement(res,elAajouter);
                 }
             }
             i++;
        }

        if(resEstUnComplexe)
        {
            res = treatComplexeDiviser(res,elConvert);
        }else{
            res = diviserElement(res,elConvert);
        }
    }
    return res;
}



element * MainWindow::SUM(const element * el)
{
    element * res=0;
    const reel * reelEl = dynamic_cast<const reel*>(el);
    const entier * elConvert;
    if(reelEl!=0)
    {
        elConvert = new entier(reelEl);
        ui->listExceptionWarning->addItem("Conversion de "+el->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
    }else{
         const rationnel * rationnelEl = dynamic_cast<const rationnel*>(el);
         if(rationnelEl!=0)
         {
             elConvert = new entier(rationnelEl);
             ui->listExceptionWarning->addItem("Conversion de "+el->getValueString()+" en entier, résultat: "+elConvert->getValueString()+".");
         }else{
             elConvert = dynamic_cast<const entier*>(el);
         }
    }

    int value = elConvert->getValue();
    if(value<=1)
    {
        throw(calculatrice_exception("Impossible d'éffectuer SUM "+elConvert->getValueString()+", l'opérande doit être supérieure à 1.",el));
    }else if(value>pile.size())
    {
        throw(calculatrice_exception("Impossible d'éffectuer SUM de "+elConvert->getValueString()+", l'opérande est plus grande que la taille de la pile.",el));
    }else{
        QStack<const element*> tmp(pile);
        bool resEstUnComplexe = false;
        int i=2;
        const element * el1=tmp.pop();
        const element * el2=tmp.pop();

        const expression * elExp1= dynamic_cast<const expression*>(el1);
        const expression * elExp2= dynamic_cast<const expression*>(el2);
        if(elExp1!=0 || elExp2!=0)
        {
            throw(calculatrice_exception("Impossible d'éffectuer un SUM avec une expression.",el));
        }else{
             const complexe * elComplexe1= dynamic_cast<const complexe*>(el1);
             const complexe * elComplexe2= dynamic_cast<const complexe*>(el2);
             if(elComplexe1!=0 || elComplexe2!=0)
             {
                 res = treatComplexePlus(el1,el2);
                 resEstUnComplexe = true;
             }else{
                 res = additionerElement(el1,el2);
             }
        }

        while(i<value)
        {
             const element * elAajouter = tmp.pop();
             const complexe * elComplexe= dynamic_cast<const complexe*>(elAajouter);
             if(elComplexe!=0)
             {
                 res = treatComplexePlus(res,elComplexe);
                 resEstUnComplexe = true;
             }else
             {
                 const expression * elAajouterExp= dynamic_cast<const expression*>(elAajouter);
                 if(elAajouterExp!=0)
                 {
                      throw(calculatrice_exception("Impossible d'éffectuer un SUM avec une expression.",el));
                 }else if(resEstUnComplexe)
                 {
                     res = treatComplexePlus(res,elAajouter);
                 }else{
                     res = additionerElement(res,elAajouter);
                 }
             }
             i++;
        }
    }

    return res;
}

void MainWindow::DUP()
{
    element * clone;
    if(!pile.isEmpty())
    {
       const element * el = pile.pop();
       const entier * elEntier= dynamic_cast<const entier*>(el);
       if(elEntier!=0)
       {
          clone = new entier(elEntier);
       }else{
          const reel * elReel= dynamic_cast<const reel*>(el);
          if(elReel!=0)
          {
              clone = new reel(elReel);
          }else{
              const rationnel * elRationnel= dynamic_cast<const rationnel*>(el);
              if(elRationnel!=0)
              {
                  clone = new rationnel(elRationnel);
              }else{
                  const complexe * elComplexe= dynamic_cast<const complexe*>(el);
                  if(elComplexe!=0)
                  {
                      clone = new complexe(elComplexe);
                  }else{
                      const expression * elExp= dynamic_cast<const expression*>(el);
                      if(elExp!=0)
                      {
                          clone = new expression(elExp);
                      }
                  }
              }
          }
       }

       pile.push(el);
       pile.push(clone);
    }
}

void MainWindow::SWAP(const element *el1,const element *el2)
{
     const entier * el1Entier= dynamic_cast<const entier*>(el1);
     const entier * el2Entier= dynamic_cast<const entier*>(el2);

    if(el1Entier==0 || el2Entier==0)
    {
        throw(calculatrice_exception("Impossible d'éffectuer l'opération SWAP, les deux opérandes doivent être des entiers.",el1,el2));
    }else{
        if(el1Entier->getValue()<0 || el1Entier->getValue()>=pile.size() || el2Entier->getValue()<0 || el2Entier->getValue()>=pile.size())
        {
            throw(calculatrice_exception("Impossible d'éffectuer l'opération SWAP, opérandes non valides.",el1,el2));
        }else{
            const element * tmpEl1 = pile.at(el1Entier->getValue());
            pile.replace(el1Entier->getValue(),pile.at(el2Entier->getValue()));
            pile.replace(el2Entier->getValue(), tmpEl1);
        }
    }
}
