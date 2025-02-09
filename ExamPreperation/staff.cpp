#include "staff.h"

StaffMember::StaffMember() {}

void StaffMember::setName(const QString &newName)
{
    name = newName;
}

void StaffMember::setBirthDate(const QDate &newBirthDate)
{
    birthDate = newBirthDate;
}

void StaffMember::setAppointmentType(AppointmentType newAppointmentType)
{
    appointmentType = newAppointmentType;
}


