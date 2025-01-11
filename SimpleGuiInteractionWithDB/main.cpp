#include <QApplication> // Manages the GUI Application's control flow and main settings --> Without this we would not have widget specific initialization
#include <QSql> // The QSql namespace contains miscellaneous identifiers used throughout the Qt SQL module.
#include <QSqlDatabase>
/**
QSqlDatabase requires a QCoreApplication

The QSqlDatabase class provides an interface for accessing a database through a connection --> What type of db, where is it?
It is the interface via which Qt can communicate with a db.
The connection to the database is provided via one of the database drivers: https://doc.qt.io/qt-6/sql-driver.html#supported-databases
The driver is simply the type of db you are working with.

*/
#include <QSqlQuery> // The QSqlQuery class provides a means of executing and manipulating SQL statements; How you write SQL in Qt
#include <QDebug> // IO

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // default connection
    QString pathToDB = "C:/Users/ashis/OneDrive/Desktop/Python/Python Advanced Development/MyMovieWatchList/instance/movies.db";
    db.setDatabaseName(pathToDB); // set the name/path of the connection or creates a new db

    qDebug() << "Attempting to open the DB\n";

    if (!db.open())
    {
        qDebug() << "Failed to open database\n";
    }
    else
    {
        qDebug() << "DB successfully opened\n";

        qDebug() << "All tables in the db \n";

        for (QString &table: db.tables(QSql::Tables) )
        {
            qDebug() << table << "\n";
        }

        QSqlQuery query("SELECT * FROM movie;");


        while (query.next())
        {
            qDebug() << query.value(0) << " " << query.value(1).toString() << " " << query.value(2) << "\n";
        }



        db.close();

    }

    a.exec();

    return 0;
}
