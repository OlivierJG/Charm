#ifndef CHARM_EVENT_H
#define CHARM_EVENT_H

#include <map>

#include <QList>
#include <QtDebug>
#include <QDateTime>
#include <QDomElement>
#include <QDomDocument>

#include "Task.h"

typedef int EventId;

/** An event is a recorded time for a task.
    It records the according task, the duration and a possible
    comment. */
class Event {
public:
    Event();

    bool operator == ( const Event& other ) const;

    bool operator != ( const Event& other ) const
    { return ! operator==( other ); }

    EventId id() const;

    void setId( EventId id );

    int userId() const;

    void setUserId( int userId );

    int reportId() const;

    void setReportId( int userId );

    void setInstallationId( int instId );

    int installationId() const;

    bool isValid() const;

    TaskId taskId() const;

    void setTaskId( TaskId id);

    const QString& comment() const;

    void setComment( const QString& );

    QDateTime startDateTime( Qt::TimeSpec timeSpec = Qt::LocalTime ) const;

    void setStartDateTime( const QDateTime& start = QDateTime::currentDateTime() );

    QDateTime endDateTime( Qt::TimeSpec timeSpec = Qt::LocalTime ) const;

    void setEndDateTime( const QDateTime& end = QDateTime::currentDateTime() );

    /** Returns the duration of this event in seconds. */
    int duration () const;

    void dump() const;

    QDomElement toXml( QDomDocument ) const;

    static Event fromXml( const QDomElement&,  int databaseSchemaVersion = 1 );
    static QString tagName();

private:
    /** The id of the user who owns the event. */
    int m_userid;
    /** The report id. This field is only usefull
     * if the event is imported from a report.
     */
    int m_reportid;
    /** The installation-unique id of the event. */
    int m_installationId;
    int m_id;
    /** The task this event belongs to. */
    TaskId m_taskId;
    /** A possible user comment.
        May be empty. */
    QString m_comment;
    /** The start datetime of the event. */
    QDateTime m_start;
    /** The end datetime of the event. */
    QDateTime m_end;
};

/** A list of events. */
typedef QList<Event> EventList;

/** A list of event ids. */
typedef QList<EventId> EventIdList;

/** A map of events. */
typedef std::map<EventId, Event> EventMap;

void dumpEvents( const EventList& events );

#endif
