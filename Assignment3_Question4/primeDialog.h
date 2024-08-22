#ifndef PRIMEDIALOG_H
#define PRIMEDIALOG_H

#include <QDialog>
#include <QObject>
#include <QSpinBox>
#include <QPushButton>

class PrimeDialog : public QDialog
{
    Q_OBJECT
public:
    PrimeDialog(QWidget *parent = 0);

private:

    QSpinBox *startNumber;
    QSpinBox *endNumber;
    QSpinBox *numberOfThreads;
    QPushButton *btn;




};

#endif // PRIMEDIALOG_H
