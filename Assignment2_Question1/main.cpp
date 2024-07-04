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
    Person p1("Azura", "Uni", "pup@puppers.com");
    Person p2("Azura", "Affliated with the dogs of Doom", "pup@puppers.com");
    Person p3("Azura", "Uni", "dog@gmail.com");
    Person p4("AshKetchum", "Pokemon", "pokemon@pokedex.com");

    Registration reg1(p1);
    Registration reg2(p2); // copy of reg1
    Registration reg3(p3);
    Registration reg4(p4);

    StudentRegistration *student = new StudentRegistration(Person("Wallace", "Uni", "wallace@wg.com"),  "BSc Comp Sci"); // copy of reg1
    GuestRegistration *guest = new GuestRegistration(Person("Liu kang", "MK", "lk@mk1.com"), "Lecturer"); // copy of reg1


    RegistrationList regList;
    regList.addRegistration(&reg1);
    regList.addRegistration(&reg2); // is a copy of reg1
    regList.addRegistration(student);
    regList.addRegistration(guest);
    regList.addRegistration(&reg3);
    regList.addRegistration(&reg4);

    // qDebug() << reg1.toString() << "\n";
    // qDebug() << student->toString() << "\n";
    // qDebug() << guest->toString() << "\n";

    // qDebug() << "\n\n\n\n\n\n";




    // qDebug() << regList.isRegistered("Azura") << "\n";
    // qDebug() << regList.isRegistered("Bob") << "\n";
    // qDebug() << regList.isRegistered("AshKetchum") << "\n";

    // qDebug() << "Total registered with Uni: "<< regList.totalRegistration("Uni") << "\n";
    // qDebug() << "Total registered with Pokemon: "<< regList.totalRegistration("Pokemon") << "\n";

    qDebug() << " number of reg \t"<< regList.m_StandardRegistered << "\n";
    qDebug() << " number of sreg \t"<< regList.m_StudentRegistered << "\n";
    qDebug() << " number of greg \t"<< regList.m_GuestRegistered << "\n";
    return a.exec();
}
