#include "validatordialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QButtonGroup>
#include <QPushButton>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDebug>

validatorDialog::validatorDialog(QWidget *parent) : QDialog(parent)
{
    QButtonGroup *groupBox = new QButtonGroup(this);

    checkBox = new QCheckBox("It must consist of a minimum of five characters and no spaces are allowed.",this);

    checkBoxTwo = new QCheckBox("It must consist of 5 characters, where the third character can be either a digit or "
                                "an alphabetic character (a-f or A-F).",this);

    checkBoxThree = new QCheckBox("It must consist of a minimum of four and a maximum of six digits and the starting "
                                    "digit cannot be 0.",this);

    groupBox->addButton(checkBox);
    groupBox->addButton(checkBoxTwo);
    groupBox->addButton(checkBoxThree);

    QVBoxLayout *firstRow = new QVBoxLayout();
    firstRow->addWidget(checkBox);
    firstRow->addWidget(checkBoxTwo);
    firstRow->addWidget(checkBoxThree);
    firstRow->addSpacing(5);

    lineedit = new QLineEdit(this);
    lineedit->setPlaceholderText("Enter Password");

    QVBoxLayout *secondRow = new QVBoxLayout();
    secondRow->addWidget(lineedit);
    secondRow->addSpacing(5);

    QPushButton *validateBtn = new QPushButton("Validate", this);
    QVBoxLayout *thirdRow = new QVBoxLayout();
    thirdRow->addWidget(validateBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);

    connect(validateBtn, SIGNAL(clicked(bool)), this, SLOT(isValid()));
    setLayout(mainLayout);
    setWindowTitle("Assignment3_Question3_Password_Validator");


}

bool validatorDialog::isValid()
{
    if ((checkBox->isChecked() || checkBoxTwo->isChecked() || checkBoxThree->isChecked()) && lineedit->text() == "" )
    {
        QMessageBox::information(nullptr,"Empty Password", "Enter a password to check against");
    }

    // Crosscheck password against regexp
    if (checkBox->isChecked() || checkBoxTwo->isChecked() || checkBoxThree->isChecked())
    {
        if (checkBox->isChecked() && lineedit->text() != "")
        {
            QRegularExpression re; // the one needed for assignment
            re.setPattern("^[\\w!@#$%^&*()]{5,}$");
            QRegularExpression renew("^(Bk|Mg)[0-3][0-9][0-9]_([bcdfghjklmnpqrstvxyz]|"
                                     "[abcdefghijklmnopqrstuvwxyz][bcdfghjklmnpqrstvxyz])$"); // the one needed for exam

            // Words containing a number anywhere in the word.
            // • Words containing a capital letter in any position other than the start of the word.
            // • Words containing special characters (such as #, *, /, @, ^, etc.) within the word, except if
            // the character is at the start or end of the word. A hyphen (-) is considered acceptable.

            QRegularExpression test1("\\d+");
            QRegularExpression test2("^([A-Za-z])([A-Z])");


            QRegularExpression exp("^(G|K|W)[A-Z][a-z0-9]{1,}\\s$"); // Oct/Nov 2021

            QRegularExpressionMatch match = renew.match(lineedit->text(), 0,QRegularExpression::NormalMatch);
            bool hasMatch = match.hasMatch();
            qDebug() << "Match? " << hasMatch << "\n";

            if (hasMatch)
            {
                QMessageBox::information(nullptr,"Success", QString("Your Password %1 is valid").arg(lineedit->text()));
            }
            else
            {
                QMessageBox::warning(nullptr,"Failure", QString("Your Password %1 is not valid").arg(lineedit->text()));
            }
        }
        else if (checkBoxTwo->isChecked() && lineedit->text() != "")
        {
            QRegularExpression re;
            re.setPattern("^..[0-9a-fA-F].{2}$");
            QRegularExpressionMatch match = re.match(lineedit->text(),0,QRegularExpression::NormalMatch);
            bool hasMatch = match.hasMatch();
            qDebug() << "Match? " << hasMatch << "\n";
            if (hasMatch)
            {
                QMessageBox::information(nullptr,"Success", QString("Your Password %1 is valid").arg(lineedit->text()));
            }
            else
            {
                QMessageBox::warning(nullptr,"Failure", QString("Your Password %1 is not valid").arg(lineedit->text()));
            }
        }
        else if (checkBoxThree->isCheckable() && lineedit->text() != "")
        {
            QRegularExpression re;
            re.setPattern("^[1-9]\\d{3,5}$");

            QRegularExpressionMatch match = re.match(lineedit->text(), 0, QRegularExpression::NormalMatch);
            bool hasMatch = match.hasMatch();
            qDebug() << "Match: "<< hasMatch << "\n";
            if (hasMatch)
            {
                QMessageBox::information(nullptr,"Success", QString("Your Password %1 is valid").arg(lineedit->text()));
            }
            else
            {
                QMessageBox::warning(nullptr,"Failure", QString("Your Password %1 is not valid").arg(lineedit->text()));
            }
        }
        return true;
    }

    QMessageBox::warning(nullptr,"Validation Error", "Enter a password\nSelect a pattern from above to cross check against");
    return false;

}


// void Customer::listFromXml(QString s) {
//     QDomDocument doc;
//     if (!doc.setContent(&xmlString)){
//         QDomElement root = doc.rootElement();
//         if(root.tagName() == "customer")       {
//             QDomNode node = root.firstChild();
//             while(!node.isNull()){
//                 QDomElement element = node.element();
//                 if(!element.isNull()){
//                     if(element.tagName() == "customer type"){
//                         QString type{element.attribute()};
//                         QString name;
//                         QString other;
//                         QDomNode n = node.firstChild();
//                         while (!n.isNull()){
//                             // get the tag values for this customer
//                             n = n.nextTag();
//                         }
//                     }
//                 }
//                 node = node.nextSibling();
//             }
//         }
//     }
// }










