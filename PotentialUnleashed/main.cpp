#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <QVariantList>


#include "mainwindow.h"


// QString path = QFileDialog::getOpenFileName();
// QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
// db.setDatabaseName(path);

// if (db.open())
// {
//     QSqlQuery query;
//     // query.exec("INSERT INTO USER (user_id,username,age,gender,training_experience,body_weight,goal) "
//     //            "VALUES (1,'SomeName', 24,'M','intemediate',90,'fat-loss')");

//     // query.exec("CREATE TABLE Exercise ("
//     //            "exercise_id PRIMARY KEY,"
//     //            "name VARCHAR(40) NOT NULL,"
//     //            "sets INT NOT NULL,"
//     //            "reps INT NOT NULL,"
//     //            "weight REAL NOT NULL,"
//     //            "rir INT NOT NULL,"
//     //            "rest INT NOT NULL,"
//     //            "progression VARCHAR(100) NOT NULL "
//     //            ")");


//     query.exec("SELECT * FROM USER");
//     qDebug() << query.isActive();

//     while (query.next())
//     {
//         qDebug() << query.value(0) << " " << query.value(1).toString() << " " << query.value(2).toString() << " " << query.value(3).toString() << " " << query.value(4).toString() <<
//             " " << query.value(5).toString() << " " << query.value(6).toString() << " " << query.value(7).toString();
//     }
// }

/*



*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();


    return a.exec();
}
