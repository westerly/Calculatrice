/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 19. Jun 12:05:52 2012
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      52,   11,   11,   11, 0x0a,
      72,   11,   11,   11, 0x0a,
      92,   11,   11,   11, 0x0a,
     112,   11,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     152,   11,   11,   11, 0x0a,
     172,   11,   11,   11, 0x0a,
     192,   11,   11,   11, 0x0a,
     212,   11,   11,   11, 0x0a,
     231,   11,   11,   11, 0x0a,
     248,   11,   11,   11, 0x0a,
     266,   11,   11,   11, 0x0a,
     284,   11,   11,   11, 0x0a,
     304,   11,   11,   11, 0x0a,
     323,   11,   11,   11, 0x0a,
     343,   11,   11,   11, 0x0a,
     362,   11,   11,   11, 0x0a,
     379,   11,   11,   11, 0x0a,
     396,   11,   11,   11, 0x0a,
     416,   11,   11,   11, 0x0a,
     434,   11,   11,   11, 0x0a,
     451,   11,   11,   11, 0x0a,
     468,   11,   11,   11, 0x0a,
     485,   11,   11,   11, 0x0a,
     503,   11,   11,   11, 0x0a,
     521,   11,   11,   11, 0x0a,
     539,   11,   11,   11, 0x0a,
     555,   11,   11,   11, 0x0a,
     572,   11,   11,   11, 0x0a,
     589,   11,   11,   11, 0x0a,
     607,   11,   11,   11, 0x0a,
     624,   11,   11,   11, 0x0a,
     642,   11,   11,   11, 0x0a,
     660,   11,   11,   11, 0x0a,
     678,   11,   11,   11, 0x0a,
     696,   11,   11,   11, 0x0a,
     714,   11,   11,   11, 0x0a,
     728,   11,   11,   11, 0x0a,
     746,   11,   11,   11, 0x0a,
     763,   11,   11,   11, 0x0a,
     780,   11,   11,   11, 0x0a,
     799,   11,   11,   11, 0x0a,
     817,   11,   11,   11, 0x0a,
     839,   11,   11,   11, 0x0a,
     861,   11,   11,   11, 0x0a,
     887,   11,   11,   11, 0x0a,
     904,   11,   11,   11, 0x0a,
     923,   11,   11,   11, 0x0a,
     947,   11,   11,   11, 0x0a,
     971,   11,   11,   11, 0x0a,
     994,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0num0PressedButton()\0"
    "num1PressedButton()\0num2PressedButton()\0"
    "num3PressedButton()\0num4PressedButton()\0"
    "num5PressedButton()\0num6PressedButton()\0"
    "num7PressedButton()\0num8PressedButton()\0"
    "num9PressedButton()\0enterPressButton()\0"
    "delPressButton()\0plusPressButton()\0"
    "foisPressButton()\0divisePressButton()\0"
    "moinsPressButton()\0espacePressButton()\0"
    "commaPressButton()\0powPressButton()\0"
    "modPressButton()\0dollarPressButton()\0"
    "swapPressButton()\0sinPressButton()\0"
    "cosPressButton()\0tanPressButton()\0"
    "sinhPressButton()\0coshPressButton()\0"
    "tanhPressButton()\0lnPressButton()\0"
    "logPressButton()\0invPressButton()\0"
    "sqrtPressButton()\0sqrPressButton()\0"
    "cubePressButton()\0factPressButton()\0"
    "evalPressButton()\0signPressButton()\0"
    "cotePressButton()\0displayPile()\0"
    "meanPressButton()\0dupPressButton()\0"
    "sumPressButton()\0clearPressButton()\0"
    "dropPressButton()\0menuConstanteEntier()\0"
    "menuConstanteReelle()\0menuConstanteRationelle()\0"
    "menuUniteDegre()\0menuUniteRadiant()\0"
    "menuActionComplexeOui()\0menuActionComplexeNon()\0"
    "menuActionClavierOui()\0menuActionClavierNon()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: num0PressedButton(); break;
        case 1: num1PressedButton(); break;
        case 2: num2PressedButton(); break;
        case 3: num3PressedButton(); break;
        case 4: num4PressedButton(); break;
        case 5: num5PressedButton(); break;
        case 6: num6PressedButton(); break;
        case 7: num7PressedButton(); break;
        case 8: num8PressedButton(); break;
        case 9: num9PressedButton(); break;
        case 10: enterPressButton(); break;
        case 11: delPressButton(); break;
        case 12: plusPressButton(); break;
        case 13: foisPressButton(); break;
        case 14: divisePressButton(); break;
        case 15: moinsPressButton(); break;
        case 16: espacePressButton(); break;
        case 17: commaPressButton(); break;
        case 18: powPressButton(); break;
        case 19: modPressButton(); break;
        case 20: dollarPressButton(); break;
        case 21: swapPressButton(); break;
        case 22: sinPressButton(); break;
        case 23: cosPressButton(); break;
        case 24: tanPressButton(); break;
        case 25: sinhPressButton(); break;
        case 26: coshPressButton(); break;
        case 27: tanhPressButton(); break;
        case 28: lnPressButton(); break;
        case 29: logPressButton(); break;
        case 30: invPressButton(); break;
        case 31: sqrtPressButton(); break;
        case 32: sqrPressButton(); break;
        case 33: cubePressButton(); break;
        case 34: factPressButton(); break;
        case 35: evalPressButton(); break;
        case 36: signPressButton(); break;
        case 37: cotePressButton(); break;
        case 38: displayPile(); break;
        case 39: meanPressButton(); break;
        case 40: dupPressButton(); break;
        case 41: sumPressButton(); break;
        case 42: clearPressButton(); break;
        case 43: dropPressButton(); break;
        case 44: menuConstanteEntier(); break;
        case 45: menuConstanteReelle(); break;
        case 46: menuConstanteRationelle(); break;
        case 47: menuUniteDegre(); break;
        case 48: menuUniteRadiant(); break;
        case 49: menuActionComplexeOui(); break;
        case 50: menuActionComplexeNon(); break;
        case 51: menuActionClavierOui(); break;
        case 52: menuActionClavierNon(); break;
        default: ;
        }
        _id -= 53;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
