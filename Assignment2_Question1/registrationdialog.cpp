#include "registrationdialog.h"

#include <QStandardItemModel>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QHeaderView>
#include <QMetaProperty>
#include <QDebug>


// I will create the base UI
RegistrationDialog::RegistrationDialog(QWidget *parent) : QDialog(parent, Qt::Window | Qt::WindowTitleHint
                          | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint), regList()
{
    // create the 1st row
    addName = new QLineEdit(this);
    addName->setFocus();
    addName->setPlaceholderText("Name: ");

    addEmail = new QLineEdit(this);
    addEmail->setPlaceholderText("name@site.com ");

    addAffliation = new QLineEdit(this);
    addAffliation->setPlaceholderText("Uni");

    ok = new QPushButton("OK",this);

    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(addName);
    firstRow->addWidget(addEmail);
    firstRow->addWidget(addAffliation);
    firstRow->addSpacing(20);
    firstRow->addWidget(ok);

    // create the 2nd row
    typeOfRegistration = new QComboBox(this);
    QStringList list;
    list << "Standard Registration" << "Student Registration" << "Guest Registration";
    typeOfRegistration->addItems(list);

    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(typeOfRegistration);

    // create the third row

    model = new QStandardItemModel(this);
    QStringList columnLabels;
    columnLabels << "Name" << "Type" << "Booking Date" << "Fee";
    model->setHorizontalHeaderLabels(columnLabels);

    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setShowGrid(true);
    tableView->setSortingEnabled(true);
    tableView->setColumnWidth(3, tableView->columnWidth(3)+100);
    tableView->horizontalHeader()->setStretchLastSection(true);


    QHBoxLayout *thirdRow = new QHBoxLayout;
    thirdRow->addWidget(tableView);

    // create the 4th row
    moreActions = new QComboBox(this);

    QStringList actions;
    for (int i = 0; i< regList->metaObject()->propertyCount(); ++i)
    {
        QMetaProperty metaproperty = regList->metaObject()->property(i);
        qDebug() << metaproperty.name();
    }

    actions << "Placeholder";
    moreActions->addItems(actions);

    QHBoxLayout *fourthRow = new QHBoxLayout;
    fourthRow->addWidget(moreActions);


    // main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);

    setWindowTitle("Conference Registration System");
    setLayout(mainLayout);
}























RegistrationDialog::~RegistrationDialog()
{

}
