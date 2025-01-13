#include "dialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QSpacerItem>

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent, Qt::Window)
{


    QLabel *label = new QLabel(this);

    label->setText("Connect To A SQL Database");


    comboBox = new QComboBox(this);

    comboBox->addItems(QStringList() << "QSQLITE" << "QIBASE" << "QMYSQL / MARIADB" << "QOCI" << "QODBC" << "QPSQL"
                                     <<  "QDB2" << "QMIMER");
    QPushButton *btn = new QPushButton("Path To DB",this);


    connectBtn = new QPushButton("Connect", this);
    connectBtn->hide();


    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *layoutOne = new QHBoxLayout;
    layoutOne->addWidget(label);

    QHBoxLayout *layoutTwo = new QHBoxLayout;
    layoutTwo->addWidget(comboBox);
    layoutTwo->addWidget(btn);

    QVBoxLayout *layoutThree = new QVBoxLayout;
    layoutThree->addWidget(connectBtn);


    // Signals & Slots AKA callbacks()

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(chooseDBPath()) );
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(showConnectionBtn()));
    connect(connectBtn, SIGNAL(clicked(bool)), this, SLOT(createConnection()) );

    mainLayout->addLayout(layoutOne);
    mainLayout->addLayout(layoutTwo);
    mainLayout->addLayout(layoutThree);

    setMinimumWidth(400);
    setLayout(mainLayout);


}

void Dialog::chooseDBPath()
{

    dbPath = QFileDialog::getOpenFileName(this, QString("Select %1 DB").arg(comboBox->currentText()),
                                                  "C:/Users/ashis/OneDrive/Desktop", "DB Files (*.db)");

    qDebug() << dbPath << "\n";
}

void Dialog::showConnectionBtn()
{
    connectBtn->show();
}

void Dialog::createConnection()
{
    db = QSqlDatabase::addDatabase(comboBox->currentText());
    db.setDatabaseName(dbPath);



    if (!db.open())
    {
        QMessageBox::warning(this, "DB Connection Fail", "Failure! DB Connection is unable to open\n");
    }
    else
    {
        QMessageBox::information(this, "DB Connection Success!", "Congrats! DB is open\n");
        QStringList tables = db.tables(QSql::Tables);
        QString tableString;

        for (QString &table: tables)
        {
            tableString.append(table + "\n");

        }

        QMessageBox::information(this, "All tables", tableString);

        QSqlQuery query(db);
        query.exec(QString("SELECT * FROM %1;").arg(tables[0]) );

        while(query.next())
        {
            qDebug() << query.value(0).toString() << " " << query.value(1).toString() << "\n";
        }

    }


}
