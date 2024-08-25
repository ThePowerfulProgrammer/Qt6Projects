#ifndef PRIMEDIALOG_H
#define PRIMEDIALOG_H

#include <QDialog>
#include <QObject>
#include <QSpinBox>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>
#include "PrimeFinder.h"

class PrimeDialog : public QDialog
{
    Q_OBJECT
public:
    PrimeDialog(QWidget *parent = 0);

private slots:
    void startFindingPrimes();
    void displayPrime(int threadNumber,int primeNumber);
    void threadFinished(int threadNumber);
    void deleteThreads();


private:

    QSpinBox *startNumber;
    QSpinBox *endNumber;
    QSpinBox *numberOfThreads;
    QPushButton *btn;

    QTextEdit *textEdit;
    QTextEdit *textEditTwo;
    QTextEdit *textEditThree;
    QTextEdit *textEditFour;


    PrimeFinder *worker1;
    PrimeFinder *worker2;
    PrimeFinder *worker3;
    PrimeFinder *worker4;

    QThread *thread1;
    QThread *thread2;
    QThread *thread3;
    QThread *thread4;


};

#endif // PRIMEDIALOG_H
