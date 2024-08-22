#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "primeDialog.h"


PrimeDialog::PrimeDialog(QWidget *parent) : QDialog(parent)
{
    startNumber = new QSpinBox(this);
    startNumber->setValue(1);
    startNumber->setRange(1,1000);
    QLabel *firstLabel = new QLabel("Start Number: ",this);
    firstLabel->setBuddy(startNumber);


    endNumber = new QSpinBox(this);
    endNumber->setValue(10);
    endNumber->setRange(1,2000);
    QLabel *secondLabel = new QLabel("End Number: ",this);
    secondLabel->setBuddy(endNumber);

    numberOfThreads = new QSpinBox(this);
    numberOfThreads->setRange(1,4);
    QLabel *thirdLabel = new QLabel("Number of threads: ",this);
    thirdLabel->setBuddy(numberOfThreads);

    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(firstLabel);
    firstRow->addWidget(startNumber,2);
    firstRow->addWidget(secondLabel);
    firstRow->addWidget(endNumber,2);
    firstRow->addWidget(thirdLabel);
    firstRow->addWidget(numberOfThreads,1);

    btn = new QPushButton("Start", this);

    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(btn);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);

    setLayout(mainLayout);

    this->setMinimumWidth(600);

}
