#ifndef STAFFMANAGER_H
#define STAFFMANAGER_H
#include "staff.h"


class StaffManager
{
public:
    StaffManager();

    void addStaffMember(StaffMember *sm);
    bool removeStaffMember(QString &name, QString &birthDate, QString &appoinmentType);
    QList<StaffMember*> getStaffMembersList() const;

private:
    QList<StaffMember*> StaffMembersList;

};

#endif // STAFFMANAGER_H
