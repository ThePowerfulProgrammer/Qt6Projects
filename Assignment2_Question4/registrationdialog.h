#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H


#include "registrationlist.h"
#include "abstractregistrationfactory.h"
#include <QDialog>

class QStandardItemModel;
class QTableView; // model + view + (delegate) MVC (MVD) design pattern
class  QLineEdit;
class QPushButton;
class QComboBox;


class RegistrationDialog : public QDialog
{

    Q_OBJECT
public:
    RegistrationDialog(QWidget *parent = 0);
    ~RegistrationDialog();

public slots:
    void createRegistration();
    void runRegistrationListFunction();
    void runRegistrationWriterFunction();
    void runRegistrationReaderFunction();

private:
    // 1st row
    QLineEdit *addName;
    QLineEdit *addEmail;
    QLineEdit *addAffliation;
    QPushButton *ok;

    // 2nd row
    QComboBox *typeOfRegistration;

    // 3rd row
    QStandardItemModel *model;
    QTableView *tableView;

    // 4th row
    QComboBox *moreActions;
    RegistrationList regList;
    QPushButton *confirmAction;

    // 5th row
    QPushButton *writeBtn;

    // 6th row
    QPushButton *readBtn;

    // Factory objects
    AbstractRegistrationFactory *factory;
};

#endif // REGISTRATIONDIALOG_H
