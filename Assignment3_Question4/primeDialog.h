#ifndef PRIMEDIALOG_H
#define PRIMEDIALOG_H

#include <QDialog>
#include <QObject>
#include <QSpinBox>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>
#include "primeworker.h"

class PrimeDialog : public QDialog
{
    Q_OBJECT
public:
    PrimeDialog(QWidget *parent = 0);

private slots:
    void startFindingPrimes();
    void displayPrime(int threadNumber,int primeNumber);
    void threadFinished(int threadNumber);

private:

    QSpinBox *startNumber;
    QSpinBox *endNumber;
    QSpinBox *numberOfThreads;
    QPushButton *btn;

    QTextEdit *textEdit;
    QTextEdit *textEditTwo;
    QTextEdit *textEditThree;
    QTextEdit *textEditFour;


    primeWorker *worker1;
    primeWorker *worker2;
    primeWorker *worker3;
    primeWorker *worker4;

    QThread *thread1;
    QThread *thread2;
    QThread *thread3;
    QThread *thread4;


};

#endif // PRIMEDIALOG_H
