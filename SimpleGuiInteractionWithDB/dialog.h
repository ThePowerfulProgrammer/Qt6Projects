#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

class QLabel;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QComboBox;

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent=nullptr);

public slots:
    void chooseDBPath();
    void showConnectionBtn();
    void createConnection();


private:
    QSqlDatabase db;


    QComboBox *comboBox;
    QPushButton *connectBtn;
    QString dbPath;
};

#endif // DIALOG_H
