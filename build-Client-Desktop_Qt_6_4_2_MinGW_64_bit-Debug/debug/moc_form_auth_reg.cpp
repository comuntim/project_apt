/****************************************************************************
** Meta object code from reading C++ file 'form_auth_reg.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../client/form_auth_reg.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_auth_reg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Form_auth_reg_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[31];
    char stringdata4[29];
    char stringdata5[28];
    char stringdata6[17];
    char stringdata7[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Form_auth_reg_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Form_auth_reg_t qt_meta_stringdata_Form_auth_reg = {
    {
        QT_MOC_LITERAL(0, 13),  // "Form_auth_reg"
        QT_MOC_LITERAL(14, 16),  // "return_autrh_reg"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 30),  // "on_pushButton_register_clicked"
        QT_MOC_LITERAL(63, 28),  // "on_pushButton_cancle_clicked"
        QT_MOC_LITERAL(92, 27),  // "on_pushButton_enter_clicked"
        QT_MOC_LITERAL(120, 16),  // "slotDisconnected"
        QT_MOC_LITERAL(137, 14)   // "slotClientRead"
    },
    "Form_auth_reg",
    "return_autrh_reg",
    "",
    "on_pushButton_register_clicked",
    "on_pushButton_cancle_clicked",
    "on_pushButton_enter_clicked",
    "slotDisconnected",
    "slotClientRead"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Form_auth_reg[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form_auth_reg::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Form_auth_reg.offsetsAndSizes,
    qt_meta_data_Form_auth_reg,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Form_auth_reg_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form_auth_reg, std::true_type>,
        // method 'return_autrh_reg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_register_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_cancle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_enter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotClientRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Form_auth_reg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_auth_reg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->return_autrh_reg(); break;
        case 1: _t->on_pushButton_register_clicked(); break;
        case 2: _t->on_pushButton_cancle_clicked(); break;
        case 3: _t->on_pushButton_enter_clicked(); break;
        case 4: _t->slotDisconnected(); break;
        case 5: _t->slotClientRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Form_auth_reg::*)();
            if (_t _q_method = &Form_auth_reg::return_autrh_reg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *Form_auth_reg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_auth_reg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form_auth_reg.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_auth_reg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Form_auth_reg::return_autrh_reg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
