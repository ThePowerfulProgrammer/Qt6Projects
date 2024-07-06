#include "registrationdialog.h"
#include "registration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "person.h"

#include <QStandardItemModel>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QHeaderView>
#include <QMessageBox>
#include <QList>
#include <QStandardItem>
#include <QInputDialog>

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
    list << "Registration Type▾" << "Standard Registration" << "Student Registration" << "Guest Registration";
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
    actions << "More▾"<< "addRegistration" << "isRegistered" << "totalFee" << "totalRegistration";
    moreActions->addItems(actions);
    confirmAction = new QPushButton("Confirm", this);

    QHBoxLayout *fourthRow = new QHBoxLayout;
    fourthRow->addWidget(moreActions);
    fourthRow->addWidget(confirmAction);


    // Signals and slots
    connect(ok, SIGNAL(clicked()), this, SLOT(createRegistration()));
    connect(confirmAction, SIGNAL(clicked()), this, SLOT(runRegistrationListFunction()));

    // main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);

    setWindowTitle("Conference Registration System");
    setLayout(mainLayout);
}

void RegistrationDialog::createRegistration()
{
    if (!addName->text().isEmpty() && !addEmail->text().isEmpty() && !addAffliation->text().isEmpty() && typeOfRegistration->currentText() != "Registration Type▾")
    {
        if (typeOfRegistration->currentText() == "Standard Registration")
        {
            QString name = addName->text();
            QString affiliation = addAffliation->text();
            QString email = addEmail->text();

            Person p(name, affiliation, email);
            Registration r(p);
            if(regList.addRegistration(&r))
            {

                QStandardItem *name_item = new QStandardItem(name);
                QStandardItem *email_item = new QStandardItem(r.metaObject()->className());
                QStandardItem *booking_date_item = new QStandardItem(r.getBookingDate().toString("dd.MM.yyyy"));
                QStandardItem *reg_fee_item = new QStandardItem(QString::number(r.calculateFee()));

                // insert a new row to the model
                int row =  model->rowCount();
                model->insertRow(row, QList<QStandardItem*>() << name_item << email_item << booking_date_item << reg_fee_item);
            }
        }
        else if (typeOfRegistration->currentText() == "Student Registration")
        {
            QString name = addName->text();
            QString affiliation = addAffliation->text();
            QString email = addEmail->text();

            Person p(name, affiliation, email);
            QString qualification = QInputDialog::getText(this, "Confirm Qualification", "Enter qualification",QLineEdit::Normal);
            StudentRegistration *student = new StudentRegistration(p, qualification);
            if (regList.addRegistration(student))
            {

                QStandardItem *name_item = new QStandardItem(name);
                QStandardItem *type_item = new QStandardItem(student->metaObject()->className());
                QStandardItem *booking_date_item = new QStandardItem(student->getBookingDate().toString("dd.MM.yyyy"));
                QStandardItem *reg_fee_item = new QStandardItem(QString::number(student->STANDARD_FEE));

                // insert a new row to the model
                int row =  model->rowCount();
                model->insertRow(row, QList<QStandardItem*>() << name_item << type_item << booking_date_item << reg_fee_item);
            }
        }
        else
        {
            QString name = addName->text();
            QString affiliation = addAffliation->text();
            QString email = addEmail->text();

            Person p(name, affiliation, email);
            QString category = QInputDialog::getText(this, "Confirm Category", "Enter category",QLineEdit::Normal);
            GuestRegistration *guest= new GuestRegistration(p, category);

            if(regList.addRegistration(guest))
            {

                QStandardItem *name_item = new QStandardItem(name);
                QStandardItem *type_item = new QStandardItem(guest->metaObject()->className());
                QStandardItem *booking_date_item = new QStandardItem(guest->getBookingDate().toString("dd.MM.yyyy"));
                QStandardItem *reg_fee_item = new QStandardItem(QString::number(guest->STANDARD_FEE));

                // insert a new row to the model
                int row =  model->rowCount();
                model->insertRow(row, QList<QStandardItem*>() << name_item << type_item << booking_date_item << reg_fee_item);
            }
        }

        addName->clear();
        addAffliation->clear();
        addEmail->clear();
        typeOfRegistration->setCurrentIndex(0);

    }
    else
    {
        QMessageBox::information(this, "Values Missing",  "Add Appropriate Data in the forms");
    }
}

void RegistrationDialog::runRegistrationListFunction()
{
    if (moreActions->currentText() == "More▾")
    {
        QMessageBox::information(this, "Choice error", "choose an applicable function");
    }
    else
    {
        if (moreActions->currentText() == "isRegistered")
        {
            QString name = QInputDialog::getText(this,"Search Register", "Search Name: ", QLineEdit::Normal).trimmed();
            qDebug() << name << "\n";
            qDebug() << regList.isRegistered("Ash") << "\n";
        }
        else if (moreActions->currentText() == "totalFee")
        {
            qDebug() << regList.m_AttendeeList.size() << "\n";
            QString t = QInputDialog::getText(this,"Search Register", "Search Name: ", QLineEdit::Normal).trimmed();
            qDebug() << regList.totalFee(t) << "\n";
        }
    }
}

RegistrationDialog::~RegistrationDialog()
{
}


