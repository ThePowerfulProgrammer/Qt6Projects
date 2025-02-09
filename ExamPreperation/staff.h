#ifndef STAFF_H
#define STAFF_H
#include <QString>
#include <QDate>


class StaffMember
{
public:    
    enum AppointmentType {PERMANENT=0, PARTTIME=1, CONTRACT=2 };
    StaffMember();
    StaffMember(QString name, QDate birthDate, AppointmentType appointmentType);

    QString getName();
    QString getDate(); // will modify the birthDate to represent a QString
    AppointmentType getAppointmentType();

    void setName(const QString &newName);
    void setBirthDate(const QDate &newBirthDate);
    void setAppointmentType(AppointmentType newAppointmentType);

private:
    QString name;
    QDate birthDate;
    AppointmentType appointmentType;
};

#endif // STAFF_H
