#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QDialog>
#include <QSpinBox>
#include <QPushButton>

class PrimeFinder : public QDialog
{
    Q_OBJECT
public:
    PrimeFinder(QWidget *parent = 0);

private:

    QSpinBox *startNumber;
    QSpinBox *endNumber;
    QSpinBox *numberOfThreads;
    QPushButton *btn;




};

#endif // PRIMEFINDER_H
