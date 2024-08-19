#ifndef VALIDATORDIALOG_H
#define VALIDATORDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QLineEdit>

class validatorDialog : public QDialog
{
    Q_OBJECT
public:
    validatorDialog(QWidget *parent = 0);

public slots:
    bool isValid();

private:
    QCheckBox *checkBox;
    QCheckBox *checkBoxTwo;
    QCheckBox *checkBoxThree;


    QLineEdit *lineedit;
};

#endif // VALIDATORDIALOG_H
