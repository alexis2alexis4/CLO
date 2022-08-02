/****************************************************************************
** Meta object code from reading C++ file 'Qt3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../source/Qt3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Qt3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CLOAPI__Qt3_t {
    QByteArrayData data[14];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLOAPI__Qt3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLOAPI__Qt3_t qt_meta_stringdata_CLOAPI__Qt3 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CLOAPI::Qt3"
QT_MOC_LITERAL(1, 12, 17), // "sendToWebUploaded"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 2), // "id"
QT_MOC_LITERAL(4, 34, 6), // "result"
QT_MOC_LITERAL(5, 41, 21), // "sendToWebProjFilePath"
QT_MOC_LITERAL(6, 63, 8), // "filePath"
QT_MOC_LITERAL(7, 72, 14), // "sendTextToCpp3"
QT_MOC_LITERAL(8, 87, 4), // "text"
QT_MOC_LITERAL(9, 92, 20), // "sendToCppAddMaterial"
QT_MOC_LITERAL(10, 113, 3), // "url"
QT_MOC_LITERAL(11, 117, 4), // "name"
QT_MOC_LITERAL(12, 122, 8), // "category"
QT_MOC_LITERAL(13, 131, 21) // "sendToCppProjFilePath"

    },
    "CLOAPI::Qt3\0sendToWebUploaded\0\0id\0"
    "result\0sendToWebProjFilePath\0filePath\0"
    "sendTextToCpp3\0text\0sendToCppAddMaterial\0"
    "url\0name\0category\0sendToCppProjFilePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLOAPI__Qt3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   47,    2, 0x0a /* Public */,
       9,    4,   50,    2, 0x0a /* Public */,
      13,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   10,   11,    3,   12,
    QMetaType::Void,

       0        // eod
};

void CLOAPI::Qt3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Qt3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendToWebUploaded((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendToWebProjFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendTextToCpp3((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sendToCppAddMaterial((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->sendToCppProjFilePath(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Qt3::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qt3::sendToWebUploaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Qt3::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qt3::sendToWebProjFilePath)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CLOAPI::Qt3::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLOAPI__Qt3.data,
    qt_meta_data_CLOAPI__Qt3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CLOAPI::Qt3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLOAPI::Qt3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLOAPI__Qt3.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CLOAPI::Qt3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CLOAPI::Qt3::sendToWebUploaded(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CLOAPI::Qt3::sendToWebProjFilePath(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CLOAPI__Downloader_t {
    QByteArrayData data[11];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLOAPI__Downloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLOAPI__Downloader_t qt_meta_stringdata_CLOAPI__Downloader = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CLOAPI::Downloader"
QT_MOC_LITERAL(1, 19, 7), // "onReady"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "getData"
QT_MOC_LITERAL(4, 36, 6), // "urlstr"
QT_MOC_LITERAL(5, 43, 4), // "name"
QT_MOC_LITERAL(6, 48, 7), // "dirName"
QT_MOC_LITERAL(7, 56, 3), // "id_"
QT_MOC_LITERAL(8, 60, 8), // "onResult"
QT_MOC_LITERAL(9, 69, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 84, 5) // "reply"

    },
    "CLOAPI::Downloader\0onReady\0\0getData\0"
    "urlstr\0name\0dirName\0id_\0onResult\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLOAPI__Downloader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    4,   30,    2, 0x0a /* Public */,
       8,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void CLOAPI::Downloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Downloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onReady(); break;
        case 1: _t->getData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->onResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Downloader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Downloader::onReady)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CLOAPI::Downloader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLOAPI__Downloader.data,
    qt_meta_data_CLOAPI__Downloader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CLOAPI::Downloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLOAPI::Downloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLOAPI__Downloader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CLOAPI::Downloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CLOAPI::Downloader::onReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_CLOAPI__Qt4_t {
    QByteArrayData data[11];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLOAPI__Qt4_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLOAPI__Qt4_t qt_meta_stringdata_CLOAPI__Qt4 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CLOAPI::Qt4"
QT_MOC_LITERAL(1, 12, 13), // "signalToWeb12"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2), // "id"
QT_MOC_LITERAL(4, 30, 21), // "sendToWebProjFilePath"
QT_MOC_LITERAL(5, 52, 8), // "filePath"
QT_MOC_LITERAL(6, 61, 17), // "sendToCppAddColor"
QT_MOC_LITERAL(7, 79, 8), // "colorHex"
QT_MOC_LITERAL(8, 88, 9), // "colorName"
QT_MOC_LITERAL(9, 98, 9), // "palitName"
QT_MOC_LITERAL(10, 108, 21) // "sendToCppProjFilePath"

    },
    "CLOAPI::Qt4\0signalToWeb12\0\0id\0"
    "sendToWebProjFilePath\0filePath\0"
    "sendToCppAddColor\0colorHex\0colorName\0"
    "palitName\0sendToCppProjFilePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLOAPI__Qt4[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   40,    2, 0x0a /* Public */,
      10,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void,

       0        // eod
};

void CLOAPI::Qt4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Qt4 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalToWeb12((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendToWebProjFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendToCppAddColor((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->sendToCppProjFilePath(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Qt4::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qt4::signalToWeb12)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Qt4::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qt4::sendToWebProjFilePath)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CLOAPI::Qt4::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLOAPI__Qt4.data,
    qt_meta_data_CLOAPI__Qt4,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CLOAPI::Qt4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLOAPI::Qt4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLOAPI__Qt4.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CLOAPI::Qt4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CLOAPI::Qt4::signalToWeb12(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CLOAPI::Qt4::sendToWebProjFilePath(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CLOAPI__Qt5_t {
    QByteArrayData data[11];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLOAPI__Qt5_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLOAPI__Qt5_t qt_meta_stringdata_CLOAPI__Qt5 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CLOAPI::Qt5"
QT_MOC_LITERAL(1, 12, 18), // "sendToWebColorWays"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "allColorWays"
QT_MOC_LITERAL(4, 45, 21), // "sendToWebRenderFinish"
QT_MOC_LITERAL(5, 67, 12), // "renderAnswer"
QT_MOC_LITERAL(6, 80, 21), // "sendToCppGetColorWays"
QT_MOC_LITERAL(7, 102, 15), // "sendToCppRender"
QT_MOC_LITERAL(8, 118, 9), // "turntable"
QT_MOC_LITERAL(9, 128, 11), // "isCreateGLB"
QT_MOC_LITERAL(10, 140, 7) // "dirPath"

    },
    "CLOAPI::Qt5\0sendToWebColorWays\0\0"
    "allColorWays\0sendToWebRenderFinish\0"
    "renderAnswer\0sendToCppGetColorWays\0"
    "sendToCppRender\0turntable\0isCreateGLB\0"
    "dirPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLOAPI__Qt5[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x0a /* Public */,
       7,    3,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    8,    9,   10,

       0        // eod
};

void CLOAPI::Qt5::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Qt5 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendToWebColorWays((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendToWebRenderFinish((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendToCppGetColorWays(); break;
        case 3: _t->sendToCppRender((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Qt5::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qt5::sendToWebColorWays)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Qt5::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Qt5::sendToWebRenderFinish)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CLOAPI::Qt5::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLOAPI__Qt5.data,
    qt_meta_data_CLOAPI__Qt5,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CLOAPI::Qt5::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLOAPI::Qt5::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLOAPI__Qt5.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CLOAPI::Qt5::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CLOAPI::Qt5::sendToWebColorWays(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CLOAPI::Qt5::sendToWebRenderFinish(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
