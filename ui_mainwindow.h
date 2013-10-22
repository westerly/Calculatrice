/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue 19. Jun 12:05:47 2012
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEntier;
    QAction *actionReelle;
    QAction *actionRationelle;
    QAction *actionRadiant;
    QAction *actionDegre;
    QAction *actionComplexeOui;
    QAction *actionComplexeNon;
    QAction *actionClavierOui;
    QAction *actionClavierNon;
    QWidget *centralWidget;
    QListWidget *listWidgetPileDilsplay;
    QSpinBox *spinBoxNumberItemDisplay;
    QListWidget *listExceptionWarning;
    QLineEdit *lineEdit;
    QGroupBox *clavierPrincipal;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *layoutClavierPrincipal;
    QPushButton *Button_5;
    QPushButton *Button_6;
    QPushButton *Button_4;
    QPushButton *Button_7;
    QPushButton *Button_1;
    QPushButton *Button_9;
    QPushButton *Button_2;
    QPushButton *Button_3;
    QPushButton *Button_0;
    QPushButton *Button_enter;
    QPushButton *Button_del;
    QPushButton *Button_8;
    QPushButton *Button_space;
    QPushButton *Button_comma;
    QPushButton *Button_dollar;
    QPushButton *Button_cote;
    QGroupBox *clavierSecondaire;
    QWidget *gridLayoutWidget;
    QGridLayout *layoutClavierSecondaire;
    QPushButton *Button_divise;
    QPushButton *Button_fois;
    QPushButton *Button_moins;
    QPushButton *Button_plus;
    QPushButton *Button_pow;
    QPushButton *Button_cos;
    QPushButton *Button_tan;
    QPushButton *Button_sinh;
    QPushButton *Button_cosh;
    QPushButton *Button_log;
    QPushButton *Button_inv;
    QPushButton *Button_mod;
    QPushButton *Button_SWAP;
    QPushButton *Button_tanh;
    QPushButton *Button_MEAN;
    QPushButton *Button_CLEAR;
    QPushButton *Button_DROP;
    QPushButton *Button_SUM;
    QPushButton *Button_DUP;
    QPushButton *Button_sign;
    QPushButton *Button_ln;
    QPushButton *Button_eval;
    QPushButton *Button_fact;
    QPushButton *Button_cube;
    QPushButton *Button_sqr;
    QPushButton *Button_sqrt;
    QPushButton *Button_sin;
    QMenuBar *menuBar;
    QMenu *menuType_de_constante;
    QMenu *menuUnit_des_degr_s;
    QMenu *menuComplexe;
    QMenu *menuClavier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(711, 392);
        MainWindow->setMinimumSize(QSize(711, 392));
        MainWindow->setMaximumSize(QSize(711, 392));
        actionEntier = new QAction(MainWindow);
        actionEntier->setObjectName(QString::fromUtf8("actionEntier"));
        actionEntier->setCheckable(true);
        actionEntier->setChecked(true);
        actionEntier->setEnabled(true);
        actionReelle = new QAction(MainWindow);
        actionReelle->setObjectName(QString::fromUtf8("actionReelle"));
        actionReelle->setCheckable(true);
        actionRationelle = new QAction(MainWindow);
        actionRationelle->setObjectName(QString::fromUtf8("actionRationelle"));
        actionRationelle->setCheckable(true);
        actionRationelle->setChecked(false);
        actionRadiant = new QAction(MainWindow);
        actionRadiant->setObjectName(QString::fromUtf8("actionRadiant"));
        actionRadiant->setCheckable(true);
        actionRadiant->setChecked(false);
        actionDegre = new QAction(MainWindow);
        actionDegre->setObjectName(QString::fromUtf8("actionDegre"));
        actionDegre->setCheckable(true);
        actionDegre->setChecked(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Narrow"));
        actionDegre->setFont(font);
        actionComplexeOui = new QAction(MainWindow);
        actionComplexeOui->setObjectName(QString::fromUtf8("actionComplexeOui"));
        actionComplexeOui->setCheckable(true);
        actionComplexeOui->setChecked(true);
        actionComplexeOui->setFont(font);
        actionComplexeNon = new QAction(MainWindow);
        actionComplexeNon->setObjectName(QString::fromUtf8("actionComplexeNon"));
        actionComplexeNon->setCheckable(true);
        actionClavierOui = new QAction(MainWindow);
        actionClavierOui->setObjectName(QString::fromUtf8("actionClavierOui"));
        actionClavierOui->setCheckable(true);
        actionClavierOui->setChecked(true);
        actionClavierOui->setFont(font);
        actionClavierNon = new QAction(MainWindow);
        actionClavierNon->setObjectName(QString::fromUtf8("actionClavierNon"));
        actionClavierNon->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidgetPileDilsplay = new QListWidget(centralWidget);
        listWidgetPileDilsplay->setObjectName(QString::fromUtf8("listWidgetPileDilsplay"));
        listWidgetPileDilsplay->setGeometry(QRect(620, 40, 81, 291));
        listWidgetPileDilsplay->setFont(font);
        spinBoxNumberItemDisplay = new QSpinBox(centralWidget);
        spinBoxNumberItemDisplay->setObjectName(QString::fromUtf8("spinBoxNumberItemDisplay"));
        spinBoxNumberItemDisplay->setGeometry(QRect(620, 10, 41, 22));
        spinBoxNumberItemDisplay->setMaximum(30);
        spinBoxNumberItemDisplay->setValue(10);
        listExceptionWarning = new QListWidget(centralWidget);
        listExceptionWarning->setObjectName(QString::fromUtf8("listExceptionWarning"));
        listExceptionWarning->setGeometry(QRect(10, 270, 601, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Narrow"));
        font1.setPointSize(10);
        listExceptionWarning->setFont(font1);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 301, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Narrow"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit->setFont(font2);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setMaxLength(50);
        lineEdit->setReadOnly(true);
        clavierPrincipal = new QGroupBox(centralWidget);
        clavierPrincipal->setObjectName(QString::fromUtf8("clavierPrincipal"));
        clavierPrincipal->setGeometry(QRect(10, 60, 301, 191));
        horizontalLayoutWidget = new QWidget(clavierPrincipal);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 301, 181));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        layoutClavierPrincipal = new QGridLayout();
        layoutClavierPrincipal->setSpacing(6);
        layoutClavierPrincipal->setObjectName(QString::fromUtf8("layoutClavierPrincipal"));
        layoutClavierPrincipal->setSizeConstraint(QLayout::SetDefaultConstraint);
        Button_5 = new QPushButton(horizontalLayoutWidget);
        Button_5->setObjectName(QString::fromUtf8("Button_5"));

        layoutClavierPrincipal->addWidget(Button_5, 1, 1, 1, 1);

        Button_6 = new QPushButton(horizontalLayoutWidget);
        Button_6->setObjectName(QString::fromUtf8("Button_6"));

        layoutClavierPrincipal->addWidget(Button_6, 1, 2, 1, 1);

        Button_4 = new QPushButton(horizontalLayoutWidget);
        Button_4->setObjectName(QString::fromUtf8("Button_4"));

        layoutClavierPrincipal->addWidget(Button_4, 1, 0, 1, 1);

        Button_7 = new QPushButton(horizontalLayoutWidget);
        Button_7->setObjectName(QString::fromUtf8("Button_7"));

        layoutClavierPrincipal->addWidget(Button_7, 0, 0, 1, 1);

        Button_1 = new QPushButton(horizontalLayoutWidget);
        Button_1->setObjectName(QString::fromUtf8("Button_1"));

        layoutClavierPrincipal->addWidget(Button_1, 2, 0, 1, 1);

        Button_9 = new QPushButton(horizontalLayoutWidget);
        Button_9->setObjectName(QString::fromUtf8("Button_9"));

        layoutClavierPrincipal->addWidget(Button_9, 0, 2, 1, 1);

        Button_2 = new QPushButton(horizontalLayoutWidget);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));

        layoutClavierPrincipal->addWidget(Button_2, 2, 1, 1, 1);

        Button_3 = new QPushButton(horizontalLayoutWidget);
        Button_3->setObjectName(QString::fromUtf8("Button_3"));

        layoutClavierPrincipal->addWidget(Button_3, 2, 2, 1, 1);

        Button_0 = new QPushButton(horizontalLayoutWidget);
        Button_0->setObjectName(QString::fromUtf8("Button_0"));

        layoutClavierPrincipal->addWidget(Button_0, 3, 0, 1, 1);

        Button_enter = new QPushButton(horizontalLayoutWidget);
        Button_enter->setObjectName(QString::fromUtf8("Button_enter"));

        layoutClavierPrincipal->addWidget(Button_enter, 4, 0, 1, 1);

        Button_del = new QPushButton(horizontalLayoutWidget);
        Button_del->setObjectName(QString::fromUtf8("Button_del"));

        layoutClavierPrincipal->addWidget(Button_del, 3, 2, 1, 1);

        Button_8 = new QPushButton(horizontalLayoutWidget);
        Button_8->setObjectName(QString::fromUtf8("Button_8"));

        layoutClavierPrincipal->addWidget(Button_8, 0, 1, 1, 1);

        Button_space = new QPushButton(horizontalLayoutWidget);
        Button_space->setObjectName(QString::fromUtf8("Button_space"));

        layoutClavierPrincipal->addWidget(Button_space, 5, 0, 1, 3);

        Button_comma = new QPushButton(horizontalLayoutWidget);
        Button_comma->setObjectName(QString::fromUtf8("Button_comma"));

        layoutClavierPrincipal->addWidget(Button_comma, 4, 2, 1, 1);

        Button_dollar = new QPushButton(horizontalLayoutWidget);
        Button_dollar->setObjectName(QString::fromUtf8("Button_dollar"));

        layoutClavierPrincipal->addWidget(Button_dollar, 3, 1, 1, 1);

        Button_cote = new QPushButton(horizontalLayoutWidget);
        Button_cote->setObjectName(QString::fromUtf8("Button_cote"));

        layoutClavierPrincipal->addWidget(Button_cote, 4, 1, 1, 1);


        horizontalLayout->addLayout(layoutClavierPrincipal);

        clavierSecondaire = new QGroupBox(centralWidget);
        clavierSecondaire->setObjectName(QString::fromUtf8("clavierSecondaire"));
        clavierSecondaire->setGeometry(QRect(320, 0, 291, 261));
        gridLayoutWidget = new QWidget(clavierSecondaire);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 271, 241));
        layoutClavierSecondaire = new QGridLayout(gridLayoutWidget);
        layoutClavierSecondaire->setSpacing(6);
        layoutClavierSecondaire->setMargin(11);
        layoutClavierSecondaire->setObjectName(QString::fromUtf8("layoutClavierSecondaire"));
        layoutClavierSecondaire->setContentsMargins(0, 0, 0, 0);
        Button_divise = new QPushButton(gridLayoutWidget);
        Button_divise->setObjectName(QString::fromUtf8("Button_divise"));

        layoutClavierSecondaire->addWidget(Button_divise, 3, 0, 1, 1);

        Button_fois = new QPushButton(gridLayoutWidget);
        Button_fois->setObjectName(QString::fromUtf8("Button_fois"));

        layoutClavierSecondaire->addWidget(Button_fois, 2, 0, 1, 1);

        Button_moins = new QPushButton(gridLayoutWidget);
        Button_moins->setObjectName(QString::fromUtf8("Button_moins"));

        layoutClavierSecondaire->addWidget(Button_moins, 1, 0, 1, 1);

        Button_plus = new QPushButton(gridLayoutWidget);
        Button_plus->setObjectName(QString::fromUtf8("Button_plus"));

        layoutClavierSecondaire->addWidget(Button_plus, 0, 0, 1, 1);

        Button_pow = new QPushButton(gridLayoutWidget);
        Button_pow->setObjectName(QString::fromUtf8("Button_pow"));

        layoutClavierSecondaire->addWidget(Button_pow, 4, 0, 1, 1);

        Button_cos = new QPushButton(gridLayoutWidget);
        Button_cos->setObjectName(QString::fromUtf8("Button_cos"));

        layoutClavierSecondaire->addWidget(Button_cos, 1, 1, 1, 1);

        Button_tan = new QPushButton(gridLayoutWidget);
        Button_tan->setObjectName(QString::fromUtf8("Button_tan"));

        layoutClavierSecondaire->addWidget(Button_tan, 2, 1, 1, 1);

        Button_sinh = new QPushButton(gridLayoutWidget);
        Button_sinh->setObjectName(QString::fromUtf8("Button_sinh"));

        layoutClavierSecondaire->addWidget(Button_sinh, 3, 1, 1, 1);

        Button_cosh = new QPushButton(gridLayoutWidget);
        Button_cosh->setObjectName(QString::fromUtf8("Button_cosh"));

        layoutClavierSecondaire->addWidget(Button_cosh, 4, 1, 1, 1);

        Button_log = new QPushButton(gridLayoutWidget);
        Button_log->setObjectName(QString::fromUtf8("Button_log"));

        layoutClavierSecondaire->addWidget(Button_log, 0, 2, 1, 1);

        Button_inv = new QPushButton(gridLayoutWidget);
        Button_inv->setObjectName(QString::fromUtf8("Button_inv"));

        layoutClavierSecondaire->addWidget(Button_inv, 1, 2, 1, 1);

        Button_mod = new QPushButton(gridLayoutWidget);
        Button_mod->setObjectName(QString::fromUtf8("Button_mod"));

        layoutClavierSecondaire->addWidget(Button_mod, 5, 0, 1, 1);

        Button_SWAP = new QPushButton(gridLayoutWidget);
        Button_SWAP->setObjectName(QString::fromUtf8("Button_SWAP"));

        layoutClavierSecondaire->addWidget(Button_SWAP, 7, 0, 1, 1);

        Button_tanh = new QPushButton(gridLayoutWidget);
        Button_tanh->setObjectName(QString::fromUtf8("Button_tanh"));

        layoutClavierSecondaire->addWidget(Button_tanh, 5, 1, 1, 1);

        Button_MEAN = new QPushButton(gridLayoutWidget);
        Button_MEAN->setObjectName(QString::fromUtf8("Button_MEAN"));

        layoutClavierSecondaire->addWidget(Button_MEAN, 8, 0, 1, 1);

        Button_CLEAR = new QPushButton(gridLayoutWidget);
        Button_CLEAR->setObjectName(QString::fromUtf8("Button_CLEAR"));

        layoutClavierSecondaire->addWidget(Button_CLEAR, 8, 1, 1, 1);

        Button_DROP = new QPushButton(gridLayoutWidget);
        Button_DROP->setObjectName(QString::fromUtf8("Button_DROP"));

        layoutClavierSecondaire->addWidget(Button_DROP, 8, 2, 1, 1);

        Button_SUM = new QPushButton(gridLayoutWidget);
        Button_SUM->setObjectName(QString::fromUtf8("Button_SUM"));

        layoutClavierSecondaire->addWidget(Button_SUM, 7, 2, 1, 1);

        Button_DUP = new QPushButton(gridLayoutWidget);
        Button_DUP->setObjectName(QString::fromUtf8("Button_DUP"));

        layoutClavierSecondaire->addWidget(Button_DUP, 7, 1, 1, 1);

        Button_sign = new QPushButton(gridLayoutWidget);
        Button_sign->setObjectName(QString::fromUtf8("Button_sign"));

        layoutClavierSecondaire->addWidget(Button_sign, 6, 0, 1, 1);

        Button_ln = new QPushButton(gridLayoutWidget);
        Button_ln->setObjectName(QString::fromUtf8("Button_ln"));

        layoutClavierSecondaire->addWidget(Button_ln, 6, 1, 1, 1);

        Button_eval = new QPushButton(gridLayoutWidget);
        Button_eval->setObjectName(QString::fromUtf8("Button_eval"));

        layoutClavierSecondaire->addWidget(Button_eval, 6, 2, 1, 1);

        Button_fact = new QPushButton(gridLayoutWidget);
        Button_fact->setObjectName(QString::fromUtf8("Button_fact"));

        layoutClavierSecondaire->addWidget(Button_fact, 5, 2, 1, 1);

        Button_cube = new QPushButton(gridLayoutWidget);
        Button_cube->setObjectName(QString::fromUtf8("Button_cube"));

        layoutClavierSecondaire->addWidget(Button_cube, 4, 2, 1, 1);

        Button_sqr = new QPushButton(gridLayoutWidget);
        Button_sqr->setObjectName(QString::fromUtf8("Button_sqr"));

        layoutClavierSecondaire->addWidget(Button_sqr, 3, 2, 1, 1);

        Button_sqrt = new QPushButton(gridLayoutWidget);
        Button_sqrt->setObjectName(QString::fromUtf8("Button_sqrt"));

        layoutClavierSecondaire->addWidget(Button_sqrt, 2, 2, 1, 1);

        Button_sin = new QPushButton(gridLayoutWidget);
        Button_sin->setObjectName(QString::fromUtf8("Button_sin"));

        layoutClavierSecondaire->addWidget(Button_sin, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 711, 22));
        menuType_de_constante = new QMenu(menuBar);
        menuType_de_constante->setObjectName(QString::fromUtf8("menuType_de_constante"));
        menuType_de_constante->setFont(font);
        menuUnit_des_degr_s = new QMenu(menuBar);
        menuUnit_des_degr_s->setObjectName(QString::fromUtf8("menuUnit_des_degr_s"));
        menuUnit_des_degr_s->setFont(font);
        menuComplexe = new QMenu(menuBar);
        menuComplexe->setObjectName(QString::fromUtf8("menuComplexe"));
        menuComplexe->setFont(font);
        menuClavier = new QMenu(menuBar);
        menuClavier->setObjectName(QString::fromUtf8("menuClavier"));
        menuClavier->setFont(font);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuType_de_constante->menuAction());
        menuBar->addAction(menuComplexe->menuAction());
        menuBar->addAction(menuUnit_des_degr_s->menuAction());
        menuBar->addAction(menuClavier->menuAction());
        menuType_de_constante->addAction(actionEntier);
        menuType_de_constante->addAction(actionReelle);
        menuType_de_constante->addAction(actionRationelle);
        menuUnit_des_degr_s->addAction(actionDegre);
        menuUnit_des_degr_s->addAction(actionRadiant);
        menuComplexe->addAction(actionComplexeOui);
        menuComplexe->addAction(actionComplexeNon);
        menuClavier->addAction(actionClavierOui);
        menuClavier->addAction(actionClavierNon);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice", 0, QApplication::UnicodeUTF8));
        actionEntier->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        actionReelle->setText(QApplication::translate("MainWindow", "R\303\251elle", 0, QApplication::UnicodeUTF8));
        actionRationelle->setText(QApplication::translate("MainWindow", "Rationelle", 0, QApplication::UnicodeUTF8));
        actionRadiant->setText(QApplication::translate("MainWindow", "Radiant", 0, QApplication::UnicodeUTF8));
        actionDegre->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        actionComplexeOui->setText(QApplication::translate("MainWindow", "Oui", 0, QApplication::UnicodeUTF8));
        actionComplexeNon->setText(QApplication::translate("MainWindow", "Non", 0, QApplication::UnicodeUTF8));
        actionClavierOui->setText(QApplication::translate("MainWindow", "Oui", 0, QApplication::UnicodeUTF8));
        actionClavierNon->setText(QApplication::translate("MainWindow", "Non", 0, QApplication::UnicodeUTF8));
        clavierPrincipal->setTitle(QString());
        Button_5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        Button_5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        Button_6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        Button_6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        Button_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        Button_4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        Button_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        Button_7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        Button_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        Button_1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        Button_9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        Button_9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        Button_2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        Button_2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        Button_3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        Button_3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        Button_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        Button_0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        Button_enter->setText(QApplication::translate("MainWindow", "Enter", 0, QApplication::UnicodeUTF8));
        Button_enter->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        Button_del->setText(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        Button_del->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        Button_8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        Button_8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        Button_space->setText(QString());
        Button_space->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        Button_comma->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        Button_comma->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        Button_dollar->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        Button_dollar->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        Button_cote->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        Button_cote->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        clavierSecondaire->setTitle(QString());
        Button_divise->setText(QApplication::translate("MainWindow", "\303\267", 0, QApplication::UnicodeUTF8));
        Button_divise->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        Button_fois->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        Button_fois->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        Button_moins->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        Button_moins->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        Button_plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        Button_plus->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        Button_pow->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        Button_pow->setShortcut(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        Button_cos->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        Button_cos->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        Button_tan->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        Button_tan->setShortcut(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        Button_sinh->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        Button_sinh->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0, QApplication::UnicodeUTF8));
        Button_cosh->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        Button_cosh->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        Button_log->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        Button_log->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        Button_inv->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        Button_inv->setShortcut(QApplication::translate("MainWindow", "I", 0, QApplication::UnicodeUTF8));
        Button_mod->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        Button_mod->setShortcut(QApplication::translate("MainWindow", "M", 0, QApplication::UnicodeUTF8));
        Button_SWAP->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        Button_SWAP->setShortcut(QApplication::translate("MainWindow", "W", 0, QApplication::UnicodeUTF8));
        Button_tanh->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        Button_tanh->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        Button_MEAN->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        Button_MEAN->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        Button_CLEAR->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        Button_CLEAR->setShortcut(QApplication::translate("MainWindow", "Ctrl+Backspace", 0, QApplication::UnicodeUTF8));
        Button_DROP->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        Button_DROP->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+Backspace", 0, QApplication::UnicodeUTF8));
        Button_SUM->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        Button_SUM->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0, QApplication::UnicodeUTF8));
        Button_DUP->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        Button_DUP->setShortcut(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        Button_sign->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        Button_sign->setShortcut(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        Button_ln->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        Button_ln->setShortcut(QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8));
        Button_eval->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        Button_eval->setShortcut(QApplication::translate("MainWindow", "E", 0, QApplication::UnicodeUTF8));
        Button_fact->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        Button_fact->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        Button_cube->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        Button_cube->setShortcut(QApplication::translate("MainWindow", "U", 0, QApplication::UnicodeUTF8));
        Button_sqr->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        Button_sqr->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        Button_sqrt->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        Button_sqrt->setShortcut(QApplication::translate("MainWindow", "Q", 0, QApplication::UnicodeUTF8));
        Button_sin->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        Button_sin->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        menuType_de_constante->setTitle(QApplication::translate("MainWindow", "Type de constante", 0, QApplication::UnicodeUTF8));
        menuUnit_des_degr_s->setTitle(QApplication::translate("MainWindow", "Unit\303\251 des degr\303\251s", 0, QApplication::UnicodeUTF8));
        menuComplexe->setTitle(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        menuClavier->setTitle(QApplication::translate("MainWindow", "Clavier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
