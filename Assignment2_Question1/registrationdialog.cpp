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
#include <QDir>
#include <QDebug>


// I will create the base UI
RegistrationDialog::RegistrationDialog(QWidget *parent) : QDialog(parent, Qt::Window | Qt::WindowTitleHint
                          | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint),  regList()
{
    // create the 1st row
    addName = new QLineEdit(this);
    addName->setFocus();
    addName->setPlaceholderText("Name: ");

    addEmail = new QLineEdit(this);
    addEmail->setPlaceholderText("Email: ");

    addAffliation = new QLineEdit(this);
    addAffliation->setPlaceholderText("Affiliation: ");


    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(addName);
    firstRow->addWidget(addEmail);
    firstRow->addWidget(addAffliation);
    firstRow->addSpacing(20);

    // create the 2nd row
    typeOfRegistration = new QComboBox(this);
    QStringList list;
    list << "Registration Type▾" << "Standard Registration" << "Student Registration" << "Guest Registration";
    typeOfRegistration->addItems(list);
    ok = new QPushButton("OK",this);


    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(typeOfRegistration);
    secondRow->addWidget(ok);


    // create the third row

    model = new QStandardItemModel(this);
    QStringList columnLabels;
    columnLabels << "Name" << "Type" << "Booking Date" << "Fee";
    model->setHorizontalHeaderLabels(columnLabels);

    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setShowGrid(true);
    tableView->setSortingEnabled(true);
    tableView->setColumnWidth(1, tableView->columnWidth(1)+10);
    tableView->setColumnWidth(2, tableView->columnWidth(2)+10);
    tableView->setColumnWidth(3, tableView->columnWidth(3)+30);
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
            Registration *r = new Registration(p);
            if(regList.addRegistration(r))
            {

                QStandardItem *name_item = new QStandardItem(name);
                QStandardItem *email_item = new QStandardItem(r->metaObject()->className());
                QStandardItem *booking_date_item = new QStandardItem(r->getBookingDate().toString("dd.MM.yyyy"));
                QStandardItem *reg_fee_item = new QStandardItem(QString::number(r->calculateFee()));

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
    if (moreActions->currentIndex() == 0)
    {
        QMessageBox::information(this, "Choice error", "choose an applicable function");
    }
    else
    {
        if (moreActions->currentIndex() == 2)
        {
            QString name = QInputDialog::getText(this,"Search Register", "Search Name", QLineEdit::Normal).trimmed();
            qDebug() << name << "\n";

            if (regList.isRegistered(name))
            {
                QMessageBox::information(this, "Attendee found", QString("Attendee %1 is registered").arg(name));
            }
            else
            {
                QMessageBox::warning(this, "Attendee not found", QString("Attendee %1 is not registered").arg(name));
            }

        }
        else if (moreActions->currentIndex() == 3)
        {
            QString t = QInputDialog::getText(this,"Total Fee", "Type", QLineEdit::Normal).trimmed();

            QMessageBox::information(this, "Total Due", QString("Total amount due for %1 is: %2").arg(t).arg(QString::number(regList.totalFee(t))));
        }
        else if (moreActions->currentIndex() == 4)
        {
            QString a = QInputDialog::getText(this, "Affliation Search", "Affliation", QLineEdit::Normal).trimmed();
            QMessageBox::information(this, "Total Affiliation Registration", QString("Number of People Registered with %1 is: %2").arg(a).arg(regList.totalRegistration(a)));
        }
        else if (moreActions->currentIndex() == 1)
        {
            QMessageBox::information(this, "Add Registration", "Use the UI above to register a user.");
        }
    }
}

RegistrationDialog::~RegistrationDialog()
{
}

