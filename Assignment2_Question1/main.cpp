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
    Person p2("Azura", "Affliated with the dogs of Doom", "pup@puppers.com");
    Person p3("Azura", "Affliated with the dogs of Doom", "dog@gmail.com");
    Person p4("AshKetchum", "Affliated with Team Rocket", "pokemon@pokedex.com");

    Registration reg1(p1);
    Registration reg2(p2); // copy of reg1
    Registration reg3(p3);
    Registration reg4(p4);

    StudentRegistration student(p1, "BSc Comp Sci"); // copy of reg1
    GuestRegistration guest(p1, "Lecturer"); // copy of reg1


    RegistrationList regList;

    qDebug() << "\n\n\n\n\n\n";
    qDebug() << student.toString() << "\n";




    return a.exec();
}
