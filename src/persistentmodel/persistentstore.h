#ifndef PERSISTENTSTORE_H
#define PERSISTENTSTORE_H

#include "warnings-disable.h"

WARNINGS_DISABLE
#include <QMutex>
#include <QObject>
#include <QtSql>
WARNINGS_ENABLE

class PersistentStore;
extern PersistentStore *global_store;

/*!
 * \ingroup persistent
 * \brief The PersistentStore is a QObject which interfaces with a database
 * which stores lists of archives, jobs, and journal entries.
 */
class PersistentStore : public QObject
{
    Q_OBJECT

public:
    PersistentStore();

    //! Initialize the global PersistentStore object.
    static void initializePersistentStore();

    //! Free the global PersistentStore object.  Can only be
    //! called once per initializePersistentStore().
    static void destroy();

    //! Access to the global pointer.  FIXME deprecated, keeping temporarily.
    static PersistentStore &instance()
    {
        Q_ASSERT(global_store != nullptr);
        return (*global_store);
    }

    //! Returns the status of whether the database is initialized or not.
    bool initialized() { return _initialized; }

    //! Returns an empty query attached to the database if it is initialized,
    //! or an unattached query otherwise.
    QSqlQuery createQuery();
    //! Removes the existing database if it is initialized.  Does not lock.
    void purge();

    //! Locks, upgrades the version if it is old, creates a new one otherwise.
    //! Must be run before any other functions in this class.
    bool init();
    //! Closes the database connection (if it exists).  Normally not used by
    //! external classes, with the possible exception of the test suite.
    static void deinit();

public slots:
    //! Locks the database and runs a query.
    bool runQuery(QSqlQuery query);

protected:
    //!@{
    //! Upgrade the database version.
    bool upgradeVersion0();
    bool upgradeVersion1();
    bool upgradeVersion2();
    bool upgradeVersion3();
    bool upgradeVersion4();
    //!@}

private:
    static bool _initialized;
};

#endif // PERSISTENTSTORE_H
