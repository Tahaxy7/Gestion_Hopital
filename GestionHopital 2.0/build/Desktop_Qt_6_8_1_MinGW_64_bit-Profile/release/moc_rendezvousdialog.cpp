/****************************************************************************
** Meta object code from reading C++ file 'rendezvousdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../GestionHopital 3.00/rendezvousdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rendezvousdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN16RendezVousDialogE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN16RendezVousDialogE = QtMocHelpers::stringData(
    "RendezVousDialog",
    "remplirComboBoxPatients",
    "",
    "remplirComboBoxMedecins",
    "ajouterRendezVous",
    "supprimerRendezVous",
    "chargerRendezVous",
    "afficherDansFormulaire",
    "row",
    "modifierRendezVous"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN16RendezVousDialogE[] = {

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
       7,    1,   61,    2, 0x08,    6 /* Private */,
       9,    0,   64,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject RendezVousDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ZN16RendezVousDialogE.offsetsAndSizes,
    qt_meta_data_ZN16RendezVousDialogE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN16RendezVousDialogE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RendezVousDialog, std::true_type>,
        // method 'remplirComboBoxPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'remplirComboBoxMedecins'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ajouterRendezVous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'supprimerRendezVous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chargerRendezVous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherDansFormulaire'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'modifierRendezVous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void RendezVousDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RendezVousDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->remplirComboBoxPatients(); break;
        case 1: _t->remplirComboBoxMedecins(); break;
        case 2: _t->ajouterRendezVous(); break;
        case 3: _t->supprimerRendezVous(); break;
        case 4: _t->chargerRendezVous(); break;
        case 5: _t->afficherDansFormulaire((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->modifierRendezVous(); break;
        default: ;
        }
    }
}

const QMetaObject *RendezVousDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RendezVousDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN16RendezVousDialogE.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RendezVousDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP