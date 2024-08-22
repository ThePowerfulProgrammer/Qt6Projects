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
    void displayPrime(int primeNumber);
    void threadFinished();

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
    QThread *thread1;


};

#endif // PRIMEDIALOG_H
