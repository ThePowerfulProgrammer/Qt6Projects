#include <QApplication>
#include <QDebug>
#include "registrationdialog.h"
#include "registrationfactory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // RegistrationFactory *creator = RegistrationFactory::GetInstance();
    // Person p("ash", "ash@gmaill.com", "ut");
    // Person p1("ashs", "ash@gmaill.com", "ut");
    // Person p2("ashg", "ash@gmaill.com", "ut");
    // qDebug() << creator->FactoryMethod("Registration",p, "")->metaObject()->className() << "\n";
    // qDebug() << creator->FactoryMethod("StudentRegistration",p1, "BSc Comp SCi")->metaObject()->className() << "\n";
    // qDebug() << creator->FactoryMethod("GuestRegistration",p2, "Visitor")->metaObject()->className() << "\n";


    RegistrationDialog dialog;
    dialog.show();
    return a.exec();
}
