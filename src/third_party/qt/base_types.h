/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef BASE_TYPES_H
#define BASE_TYPES_H

#include <QList>
#include <QMap>
#include <QQueue>
#include <QSharedPointer>
#include <QStringList>
#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QTimer>
#include <QObject>

/* containers */
template<typename TypeName>
struct AList
{
    typedef QList<TypeName> type;
};

template<typename KeyType, typename ValueType>
struct AMap
{
    typedef QMap<KeyType,ValueType> type;
};

template<typename TypeName>
struct AQueue
{
    typedef QQueue<TypeName> type;
};

typedef QStringList AStringList;
typedef QVariantMap AVariantMap;


/* smart pointers */
template<typename PointType>
struct ASharedPointer
{
    typedef QSharedPointer<PointType> type;
};


/* base qt types */
typedef QString AString;
typedef QVariant AVariant;
typedef QObject AObject;


/* multithreading */
typedef QThread AThread;
typedef QMutex AMutex;
typedef QMutexLocker AMutexLocker;


/* local types */


/* events */
typedef void (*EventFinishCbk)();
typedef quint32 EventType;


#endif /*BASE_TYPES_H*/
