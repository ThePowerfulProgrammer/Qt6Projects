#include "registrationdialog.h"
#include "registration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "registrationlistwriter.h"
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
#include <QStandardItem>
#include <QInputDialog>
#include <QFileDialog>


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
    columnLabels << "Name" << "Type" << "Email" << "Booking Date" << "Fee" << "Affiliation" << "Additional Info";
    model->setHorizontalHeaderLabels(columnLabels);

    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setShowGrid(true);
    tableView->setSortingEnabled(true);
    tableView->setColumnWidth(1, tableView->columnWidth(1)+10);
    tableView->setColumnWidth(2, tableView->columnWidth(2)+15);
    tableView->setColumnWidth(3, tableView->columnWidth(3)+10);
    tableView->setColumnWidth(4, tableView->columnWidth(4)+10);
    tableView->setColumnWidth(5, tableView->columnWidth(5)+5);
    tableView->setColumnWidth(5, tableView->columnWidth(5)+5);
    tableView->setColumnWidth(6, tableView->columnWidth(6)+5);
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

    // create the 5th row
    writeBtn = new QPushButton("Create XML", this);
    QHBoxLayout *fifthRow = new QHBoxLayout;
    fifthRow->addWidget(writeBtn);

    // Signals and slots
    connect(ok, SIGNAL(clicked()), this, SLOT(createRegistration()));
    connect(confirmAction, SIGNAL(clicked()), this, SLOT(runRegistrationListFunction()));
    connect(writeBtn, SIGNAL(clicked()), this, SLOT(runRegistrationWriterFunction()));

    // main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);
    mainLayout->addLayout(fifthRow);

    setWindowTitle("Conference Registration System");
    setMinimumWidth(800);
    setLayout(mainLayout);
}

void RegistrationDialog::createRegistration()
{
    if (!addName->text().isEmpty() && !addEmail->text().isEmpty() && !addAffliation->text().isEmpty() && typeOfRegistration->currentText() != "Registration Type▾")
    {
        if (typeOfRegistration->currentText() == "Standard Registration")
        {
            QString name = addName->text();
            QString affliation = addAffliation->text();
            QString email = addEmail->text();

            Person p(name, affliation, email);
            Registration *r = new Registration(p);
            if(regList.addRegistration(r))
            {

                QStandardItem *name_item = new QStandardItem(name);
                QStandardItem *type_item = new QStandardItem(r->metaObject()->className());
                QStandardItem *email_item = new QStandardItem(r->getAttendee().getEmail());
                QStandardItem *booking_date_item = new QStandardItem(r->getBookingDate().toString("dd.MM.yyyy"));
                QStandardItem *reg_fee_item = new QStandardItem(QString::number(r->calculateFee()));
                QStandardItem *aff_item = new QStandardItem(r->getAttendee().getAffliation());
                QStandardItem *add_item = new QStandardItem("None");

                // insert a new row to the model
                int row =  model->rowCount();
                model->insertRow(row, QList<QStandardItem*>() << name_item << type_item <<email_item << booking_date_item << reg_fee_item << aff_item << add_item);
            }
        }
        else if (typeOfRegistration->currentText() == "Student Registration")
        {
            QString name = addName->text();
            QString affliation = addAffliation->text();
            QString email = addEmail->text();

            Person p(name, affliation, email);
            QString qualification = QInputDialog::getText(this, "Confirm Qualification", "Enter qualification",QLineEdit::Normal);
            StudentRegistration *student = new StudentRegistration(p, qualification);
            if (regList.addRegistration(student))
            {
                QStandardItem *name_item = new QStandardItem(name);
                QStandardItem *type_item = new QStandardItem(student->metaObject()->className());
                QStandardItem *email_item = new QStandardItem(student->getAttendee().getEmail());
                QStandardItem *booking_date_item = new QStandardItem(student->getBookingDate().toString("dd.MM.yyyy"));
                QStandardItem *reg_fee_item = new QStandardItem(QString::number(student->STANDARD_FEE));
                QStandardItem *aff_item = new QStandardItem(student->getAttendee().getAffliation());
                QStandardItem *add_item = new QStandardItem(student->Qualification());


                // insert a new row to the model
                int row =  model->rowCount();
                model->insertRow(row, QList<QStandardItem*>() << name_item << type_item << email_item << booking_date_item << reg_fee_item << aff_item << add_item);
            }
        }
        else
        {
            QString name = addName->text();
            QString affliation = addAffliation->text();
            QString email = addEmail->text();

            Person p(name, affliation, email);
            QString category = QInputDialog::getText(this, "Confirm Category", "Enter category",QLineEdit::Normal);
            GuestRegistration *guest= new GuestRegistration(p, category);

            if(regList.addRegistration(guest))
            {

                QStandardItem *name_item = new QStandardItem(name);
                QStandardItem *type_item = new QStandardItem(guest->metaObject()->className());
                QStandardItem *email_item = new QStandardItem(guest->getAttendee().getEmail());
                QStandardItem *booking_date_item = new QStandardItem(guest->getBookingDate().toString("dd.MM.yyyy"));
                QStandardItem *reg_fee_item = new QStandardItem(QString::number(guest->STANDARD_FEE));
                QStandardItem *aff_item = new QStandardItem(guest->getAttendee().getAffliation());
                QStandardItem *add_item = new QStandardItem(guest->Category());


                // insert a new row to the model
                int row =  model->rowCount();
                model->insertRow(row, QList<QStandardItem*>() << name_item << type_item << email_item << booking_date_item << reg_fee_item << aff_item << add_item);
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
            bool ok;
            QString name = QInputDialog::getText(this,"Search Register", "Search Name", QLineEdit::Normal, "Name: ", &ok).trimmed();
            if (!name.isNull() && ok)
            {
                if (regList.isRegistered(name))
                {
                    QMessageBox::information(this, "Attendee found", QString("Attendee %1 is registered").arg(name));
                }
                else if (!regList.isRegistered(name) ||  name.isNull())
                {
                    QMessageBox::warning(this, "Attendee not found", QString("Attendee %1 is not registered").arg(name));
                }
            }
            else
            {
                QMessageBox::warning(this, "Name Search error", "Cannot search for an empty string\nTry Again");
            }
        }
        else if (moreActions->currentIndex() == 3)
        {
            bool ok;
            QString t = QInputDialog::getText(this,"Total Fee", "Type", QLineEdit::Normal, "Search?", &ok).trimmed();
            if (!t.isNull() && ok)
            {
                QMessageBox::information(this, "Total Due", QString("Total amount due for %1 is: %2").arg(t).arg(QString::number(regList.totalFee(t))));
            }
            else
            {
                QMessageBox::warning(this,"Total Due Error", "Cannot Search for an empty string");
            }

        }
        else if (moreActions->currentIndex() == 4)
        {
            bool ok;
            QString a = QInputDialog::getText(this, "Affliation Search", "Affliation", QLineEdit::Normal, "unisa", &ok).trimmed();
            if (!a.isNull())
            {
                QMessageBox::information(this, "Total Affliation Registration", QString("Number of People Registered with %1 is: %2").arg(a).arg(regList.totalRegistration(a)));
            }
            else
            {
                QMessageBox::warning(this,"Total Affliation Registration Error", "Cannot search for an empty text");
            }
        }
        else if (moreActions->currentIndex() == 1)
        {
            QMessageBox::information(this, "Add Registration", "Use the UI above to register a user.");
        }
    }
}

void RegistrationDialog::runRegistrationWriterFunction()
{
    if (regList.getAttendeeList().size() > 0)
    {
        QString path = QFileDialog::getSaveFileName(this, "Write Location", QDir::currentPath(), "Xml Files (*.xml)");
        RegistrationListWriter regListWriter(path, regList);
    }
    else
    {
        QMessageBox::warning(this,"Write Error", "Cannot write from an empty table\nFill in data");
    }
}



RegistrationDialog::~RegistrationDialog()
{
}


