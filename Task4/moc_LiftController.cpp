/****************************************************************************
** Meta object code from reading C++ file 'LiftController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "inc/LiftController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LiftController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LiftController_t {
    QByteArrayData data[16];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiftController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiftController_t qt_meta_stringdata_LiftController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LiftController"
QT_MOC_LITERAL(1, 15, 20), // "ControllerStopSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 18), // "FloorReachedSignal"
QT_MOC_LITERAL(4, 56, 6), // "size_t"
QT_MOC_LITERAL(5, 63, 5), // "floor"
QT_MOC_LITERAL(6, 69, 9), // "Direction"
QT_MOC_LITERAL(7, 79, 9), // "direction"
QT_MOC_LITERAL(8, 89, 15), // "GotTargetSignal"
QT_MOC_LITERAL(9, 105, 12), // "currentFloor"
QT_MOC_LITERAL(10, 118, 11), // "neededFloor"
QT_MOC_LITERAL(11, 130, 15), // "CabinStopSignal"
QT_MOC_LITERAL(12, 146, 16), // "CabinPauseSignal"
QT_MOC_LITERAL(13, 163, 16), // "ButtonPushedSlot"
QT_MOC_LITERAL(14, 180, 16), // "FloorReachedSlot"
QT_MOC_LITERAL(15, 197, 18) // "ControllerStopSlot"

    },
    "LiftController\0ControllerStopSignal\0"
    "\0FloorReachedSignal\0size_t\0floor\0"
    "Direction\0direction\0GotTargetSignal\0"
    "currentFloor\0neededFloor\0CabinStopSignal\0"
    "CabinPauseSignal\0ButtonPushedSlot\0"
    "FloorReachedSlot\0ControllerStopSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiftController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,
       8,    2,   60,    2, 0x06 /* Public */,
      11,    2,   65,    2, 0x06 /* Public */,
      12,    2,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   75,    2, 0x0a /* Public */,
      14,    2,   78,    2, 0x0a /* Public */,
      15,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    9,   10,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    9,   10,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void,

       0        // eod
};

void LiftController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LiftController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ControllerStopSignal(); break;
        case 1: _t->FloorReachedSignal((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< Direction(*)>(_a[2]))); break;
        case 2: _t->GotTargetSignal((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 3: _t->CabinStopSignal((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 4: _t->CabinPauseSignal((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 5: _t->ButtonPushedSlot((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 6: _t->FloorReachedSlot((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< Direction(*)>(_a[2]))); break;
        case 7: _t->ControllerStopSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LiftController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftController::ControllerStopSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LiftController::*)(size_t , Direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftController::FloorReachedSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LiftController::*)(size_t , size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftController::GotTargetSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LiftController::*)(size_t , size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftController::CabinStopSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LiftController::*)(size_t , size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftController::CabinPauseSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LiftController::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LiftController.data,
    qt_meta_data_LiftController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LiftController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiftController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LiftController.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LiftController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LiftController::ControllerStopSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LiftController::FloorReachedSignal(size_t _t1, Direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LiftController::GotTargetSignal(size_t _t1, size_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LiftController::CabinStopSignal(size_t _t1, size_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LiftController::CabinPauseSignal(size_t _t1, size_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
