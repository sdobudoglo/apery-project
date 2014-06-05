/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef BASE_TYPES_H
#define BASE_TYPES_H

#include <QList>
#include <QMap>
#include <QMultiMap>
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
#include <QDebug>

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

template<typename KeyType, typename ValueType>
struct AMultiMap
{
    typedef QMultiMap<KeyType,ValueType> type;
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
struct EventType
{
    EventType(quint32 global_type, quint32 type) : m_globalType(global_type)
      , m_type(type) {}

    inline quint32 globalType() { return m_globalType; }
    inline quint32 type() { return m_type; }

    typedef quint32 EventIntType;

private:
    EventIntType m_globalType;
    EventIntType m_type;
};


#endif /*BASE_TYPES_H*/
