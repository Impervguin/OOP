/****************************************************************************
** Meta object code from reading C++ file 'LiftCabin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "inc/LiftCabin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LiftCabin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LiftCabin_t {
    QByteArrayData data[15];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiftCabin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiftCabin_t qt_meta_stringdata_LiftCabin = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LiftCabin"
QT_MOC_LITERAL(1, 10, 17), // "FloorPassedSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "size_t"
QT_MOC_LITERAL(4, 36, 5), // "floor"
QT_MOC_LITERAL(5, 42, 9), // "Direction"
QT_MOC_LITERAL(6, 52, 9), // "direction"
QT_MOC_LITERAL(7, 62, 15), // "OpenDoorsSignal"
QT_MOC_LITERAL(8, 78, 10), // "MoveSignal"
QT_MOC_LITERAL(9, 89, 14), // "GetCommandSlot"
QT_MOC_LITERAL(10, 104, 12), // "currentFloor"
QT_MOC_LITERAL(11, 117, 11), // "neededFloor"
QT_MOC_LITERAL(12, 129, 14), // "PauseCabinSlot"
QT_MOC_LITERAL(13, 144, 13), // "StopCabinSlot"
QT_MOC_LITERAL(14, 158, 8) // "moveSlot"

    },
    "LiftCabin\0FloorPassedSignal\0\0size_t\0"
    "floor\0Direction\0direction\0OpenDoorsSignal\0"
    "MoveSignal\0GetCommandSlot\0currentFloor\0"
    "neededFloor\0PauseCabinSlot\0StopCabinSlot\0"
    "moveSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiftCabin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   56,    2, 0x0a /* Public */,
      12,    2,   61,    2, 0x0a /* Public */,
      13,    2,   66,    2, 0x0a /* Public */,
      14,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   10,   11,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   10,   11,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   10,   11,
    QMetaType::Void,

       0        // eod
};

void LiftCabin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LiftCabin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->FloorPassedSignal((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< Direction(*)>(_a[2]))); break;
        case 1: _t->OpenDoorsSignal(); break;
        case 2: _t->MoveSignal(); break;
        case 3: _t->GetCommandSlot((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 4: _t->PauseCabinSlot((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 5: _t->StopCabinSlot((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 6: _t->moveSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LiftCabin::*)(size_t , Direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::FloorPassedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LiftCabin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::OpenDoorsSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LiftCabin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::MoveSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LiftCabin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LiftCabin.data,
    qt_meta_data_LiftCabin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LiftCabin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiftCabin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LiftCabin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LiftCabin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LiftCabin::FloorPassedSignal(size_t _t1, Direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LiftCabin::OpenDoorsSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LiftCabin::MoveSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
