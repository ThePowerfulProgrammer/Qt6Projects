#include <QApplication>
#include <QDebug>

#include "registrationdialog.h"
#include "registrationfactory.h"
#include "studentregistration.h"
#include "guestregistration.h"


#include <QFileDialog>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RegistrationFactory* factory = new RegistrationFactory;
    Registration *reg = factory->createRegistration("Registration");

    Registration *sreg = factory->createRegistration("StudentRegistration");
    StudentRegistration *studentObj = dynamic_cast<StudentRegistration*>(sreg);

    Registration *greg = factory->createRegistration("GuestRegistration");
    GuestRegistration *guestObj = dynamic_cast<GuestRegistration*>(greg);



    qDebug() << studentObj->toString() << "\n";
    qDebug() << studentObj->calculateFee() << "\n";
    qDebug() << guestObj->toString() << "\n";
    qDebug() << guestObj->calculateFee() << "\n";
    delete reg;
    delete sreg;
    delete greg;
    guestObj = nullptr;
    studentObj = nullptr;

    RegistrationDialog dialog;
    dialog.show();


    return a.exec();
}
