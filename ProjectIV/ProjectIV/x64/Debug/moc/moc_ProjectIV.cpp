/****************************************************************************
** Meta object code from reading C++ file 'ProjectIV.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ProjectIV.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProjectIV.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSProjectIVENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSProjectIVENDCLASS = QtMocHelpers::stringData(
    "ProjectIV",
    "loginPageWidget",
    "",
    "registerPageWidget",
    "menuPageWidget",
    "loginButtonClicked",
    "onGameButtonClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSProjectIVENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[10];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[15];
    char stringdata5[19];
    char stringdata6[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSProjectIVENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSProjectIVENDCLASS_t qt_meta_stringdata_CLASSProjectIVENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "ProjectIV"
        QT_MOC_LITERAL(10, 15),  // "loginPageWidget"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 18),  // "registerPageWidget"
        QT_MOC_LITERAL(46, 14),  // "menuPageWidget"
        QT_MOC_LITERAL(61, 18),  // "loginButtonClicked"
        QT_MOC_LITERAL(80, 19)   // "onGameButtonClicked"
    },
    "ProjectIV",
    "loginPageWidget",
    "",
    "registerPageWidget",
    "menuPageWidget",
    "loginButtonClicked",
    "onGameButtonClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSProjectIVENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    0,   47,    2, 0x0a,    4 /* Public */,
       6,    0,   48,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ProjectIV::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSProjectIVENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSProjectIVENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSProjectIVENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ProjectIV, std::true_type>,
        // method 'loginPageWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registerPageWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'menuPageWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loginButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGameButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ProjectIV::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProjectIV *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginPageWidget(); break;
        case 1: _t->registerPageWidget(); break;
        case 2: _t->menuPageWidget(); break;
        case 3: _t->loginButtonClicked(); break;
        case 4: _t->onGameButtonClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ProjectIV::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjectIV::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSProjectIVENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ProjectIV::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
