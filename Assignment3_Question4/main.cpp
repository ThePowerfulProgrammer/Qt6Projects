#include <QApplication>
#include <QThread>
#include "PrimeFinder.h"
#include "primeDialog.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PrimeFinder *worker1 = new PrimeFinder(1,1,10);
    PrimeFinder *worker2 = new PrimeFinder(1,10,20);

    QThread *thread1 = new QThread;
    QThread *thread2 = new QThread;

    worker1->moveToThread(thread1);
    worker2->moveToThread(thread2);

    // Using the new syntax
    QObject::connect(thread1, &QThread::started, worker1, &PrimeFinder::process);
    QObject::connect(worker1, &PrimeFinder::finished, thread1, &QThread::quit);
    QObject::connect(worker1, &PrimeFinder::finished, worker1, &QObject::deleteLater);
    QObject::connect(thread1, &QThread::finished, thread1, &QObject::deleteLater);
    QObject::connect(worker1, &PrimeFinder::primeFound, thread1, &QThread::quit);
    QObject::connect(worker1, &PrimeFinder::primeFound, worker1, &QObject::deleteLater);

    QObject::connect(thread2, &QThread::started, worker2, &PrimeFinder::process);
    QObject::connect(worker2, &PrimeFinder::finished, thread2, &QThread::quit);
    QObject::connect(worker2, &PrimeFinder::finished, worker2, &QObject::deleteLater);
    QObject::connect(thread2, &QThread::finished, thread2, &QObject::deleteLater);



    thread1->start();
    thread2->start();



    PrimeDialog dialog;
    dialog.show();
    return a.exec();
}
