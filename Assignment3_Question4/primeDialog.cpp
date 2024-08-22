#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

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

    textEdit = new QTextEdit(this);
    textEdit->setText("Thread 1\n");
    textEditTwo = new QTextEdit(this);
    textEditTwo->setText("Thread 2\n");
    textEditThree = new QTextEdit(this);
    textEditThree->setText("Thread 3\n");
    textEditFour = new QTextEdit(this);
    textEditFour->setText("Thread 4\n");


    QHBoxLayout *thirdRow = new QHBoxLayout;
    thirdRow->addWidget(textEdit);
    thirdRow->addWidget(textEditTwo);
    thirdRow->addWidget(textEditThree);
    thirdRow->addWidget(textEditFour);




    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);

    connect(btn,SIGNAL(clicked()), this, SLOT(startFindingPrimes()));

    setLayout(mainLayout);

    this->setMinimumWidth(600);

}


void PrimeDialog::startFindingPrimes()
{
    int start = startNumber->value();
    int end = endNumber->value();

    thread1 = new QThread;
    worker1 = new primeWorker(1, start, end);

    worker1->moveToThread(thread1);

    connect(thread1, SIGNAL(started()), worker1, SLOT(process()));
    connect(worker1, &primeWorker::primeFound, this, &PrimeDialog::displayPrime);
    connect(worker1, &primeWorker::finished, this, &PrimeDialog::threadFinished);

    // Clean up after the thread finishes
    connect(worker1, &primeWorker::finished, worker1, &QObject::deleteLater);
    connect(thread1, &QThread::finished, thread1, &QObject::deleteLater);

    thread1->start();
}



void PrimeDialog::displayPrime(int primeNumber)
{
    // Display the prime number in one of the textEdits
    qDebug() << "RUNNING \n";
    textEdit->append(QString("number %1\n").arg(primeNumber));
}

void PrimeDialog::threadFinished()
{
    textEdit->append("Thread finished");
}







