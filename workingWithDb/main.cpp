#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    QString path = "C:/Users/ashis/OneDrive/Desktop/Python/Python Advanced Development/CAFEAPI/instance/cafes.db";

    db.setDatabaseName(path);

    qDebug() << "Attempting to open the db: \n";

    if (!db.open())
    {
        qDebug() << "Fail \n";

    }
    else
    {
        qDebug() << "Success \n";
        for (QString &table: db.tables(QSql::AllTables))
        {
            qDebug() << table << "\n";
        }




        QSqlQuery query(db);

        query.exec("SELECT * FROM cafe");

        while (query.next())
        {
            qDebug() << query.value(0).toString()  << "  " << query.value(1).toString();
            qDebug() << "\n";
        }

    }

    return a.exec();
}
