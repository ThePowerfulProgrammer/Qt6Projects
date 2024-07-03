#include <QApplication>
#include <QDebug>


#include "person.h"
#include "registration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "registrationlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Person p1("Azura", "Affliated with the dogs of Doom", "pup@puppers.com");
    Registration reg1(p1);
    StudentRegistration student(p1, "BSc Comp Sci");
    GuestRegistration guest(p1, "Lecturer");
    RegistrationList regList;

    regList.addRegistration(&reg1);
    regList.addRegistration(&student);
    regList.addRegistration(&guest);



    qDebug() << p1.getName() << " " << p1.getAffliation() << " " << p1.getEmail() << "\n";
    qDebug() << p1.toString() << "\n";

    qDebug() << reg1.toString() << reg1.calculateFee() << "\n  \n \n ";

    qDebug() << student.toString() << student.calculateFee() << "\n \n \n \n";

    qDebug() << guest.toString() << guest.calculateFee() << "\n \n \n \n \n \n";


    regList.isRegistered("Azura");

    return a.exec();
}
