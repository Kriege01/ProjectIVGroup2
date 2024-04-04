/****************************************************************************
** Meta object code from reading C++ file 'window_play.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../window_play.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_play.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSwindow_playENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSwindow_playENDCLASS = QtMocHelpers::stringData(
    "window_play",
    "on_Backbutton3_clicked",
    "",
    "on_connectButton_clicked",
    "onCellClicked",
    "on_rematchButton_clicked",
    "on_SendnameButton_clicked",
    "on_Save_clicked",
    "slotReadyRead"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSwindow_playENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject window_play::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSwindow_playENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSwindow_playENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSwindow_playENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<window_play, std::true_type>,
        // method 'on_Backbutton3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_connectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCellClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rematchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SendnameButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void window_play::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<window_play *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Backbutton3_clicked(); break;
        case 1: _t->on_connectButton_clicked(); break;
        case 2: _t->onCellClicked(); break;
        case 3: _t->on_rematchButton_clicked(); break;
        case 4: _t->on_SendnameButton_clicked(); break;
        case 5: _t->on_Save_clicked(); break;
        case 6: _t->slotReadyRead(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *window_play::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *window_play::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSwindow_playENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int window_play::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
