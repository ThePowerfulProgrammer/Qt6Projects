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
    // need to divide end / 4 if end is a multiple of 2
    int start1 = 0, start2=0, start3=0, start4=0;

    int endT1 = 0;
    int endT2 = 0;
    int endT3 = 0;
    int endT4 = 0;

    while (end%2 != 0)
    {
        end +=1;
    }

    endT1 = (end/4);
    endT2 = endT1 + (end/4);
    endT3 = endT2 + (end/4);
    endT4 = endT3 + (end/4);



    thread1 = new QThread;
    thread2 = new QThread;
    thread3 = new QThread;
    thread4 = new QThread;
    // thread4 = new QThread;

    worker1 = new primeWorker(1, start, endT1);
    worker2 = new primeWorker(2,endT1, endT2);
    worker3 = new primeWorker(3, endT2,endT3);
    worker4 = new primeWorker(4,endT3, endT4);


    worker1->moveToThread(thread1);

    connect(thread1, SIGNAL(started()), worker1, SLOT(process()));
    connect(worker1, &primeWorker::primeFound, this, &PrimeDialog::displayPrime);
    connect(worker1, &primeWorker::finished, this, &PrimeDialog::threadFinished);

    // Clean up after the thread finishes
    connect(worker1, &primeWorker::finished, worker1, &QObject::deleteLater);
    connect(thread1, &QThread::finished, thread1, &QObject::deleteLater);

    worker2->moveToThread(thread2);

    connect(thread2, SIGNAL(started()), worker2, SLOT(process()));
    connect(worker2, &primeWorker::primeFound, this, &PrimeDialog::displayPrime);
    connect(worker2, &primeWorker::finished, this, &PrimeDialog::threadFinished);

    // Clean up after the thread finishes
    connect(worker2, &primeWorker::finished, worker2, &QObject::deleteLater);
    connect(thread2, &QThread::finished, thread2, &QObject::deleteLater);

    worker3->moveToThread(thread3);

    connect(thread3, SIGNAL(started()), worker3, SLOT(process()));
    connect(worker3, &primeWorker::primeFound, this, &PrimeDialog::displayPrime);
    connect(worker3, &primeWorker::finished, this, &PrimeDialog::threadFinished);

    // Clean up after the thread finishes
    connect(worker3, &primeWorker::finished, worker3, &QObject::deleteLater);
    connect(thread3, &QThread::finished, thread3, &QObject::deleteLater);


    worker4->moveToThread(thread4);

    connect(thread4, SIGNAL(started()), worker4, SLOT(process()));
    connect(worker4, &primeWorker::primeFound, this, &PrimeDialog::displayPrime);
    connect(worker4, &primeWorker::finished, this, &PrimeDialog::threadFinished);

    // Clean up after the thread finishes
    connect(worker4, &primeWorker::finished, worker4, &QObject::deleteLater);
    connect(thread4, &QThread::finished, thread3, &QObject::deleteLater);

    thread1->start();
    thread2->start();
    thread3->start();
    thread4->start();
}



void PrimeDialog::displayPrime(int threadNumber, int primeNumber)
{
    // Display the prime number in one of the textEdits
    qDebug() << threadNumber << " : " << "RUNNING \n";
    if (threadNumber == 1)
    {
        textEdit->append(QString("Prime: %1\n").arg(primeNumber));
    }
    else if (threadNumber == 2)
    {
        textEditTwo->append(QString("Prime: %1\n").arg(primeNumber));
    }
    else if (threadNumber == 3)
    {
        textEditThree->append(QString("Prime: %1\n").arg(primeNumber));
    }
    else if (threadNumber == 4)
    {
        textEditFour->append(QString("Prime: %1\n").arg(primeNumber));
    }

}

void PrimeDialog::threadFinished(int threadNumber)
{
    if (threadNumber == 1)
    {
        textEdit->append("Thread finished");
    }
    else if (threadNumber == 2)
    {
        textEditTwo->append("Thread finished");
    }
    else if (threadNumber == 3)
    {
        textEditThree->append("Thread finished");
    }
    else if (threadNumber == 4)
    {
        textEditFour->append("Thread finished");
    }


}





















