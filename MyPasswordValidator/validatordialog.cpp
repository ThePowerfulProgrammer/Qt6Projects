#include "validatordialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QButtonGroup>
#include <QPushButton>

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
    lineedit->setPlaceholderText("Password");

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

    setLayout(mainLayout);

    connect(checkBox, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT());
}
