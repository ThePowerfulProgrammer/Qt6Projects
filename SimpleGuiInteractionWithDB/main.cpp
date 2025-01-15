#include <QApplication>
#include "dialog.h"


// QDir currentDir;
// QString path = currentDir.currentPath() + "/myDB.db";
// QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
// db.setDatabaseName(path);
// db.open();

// QSqlQuery query;
// query.exec("CREATE TABLE Workout"
//            "id INTERFER PRIMARY KEY"
//            "exercise VARCHAR(30)");

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog *dialog = new Dialog;
    dialog->show();

    a.exec();

    return 0;
}
