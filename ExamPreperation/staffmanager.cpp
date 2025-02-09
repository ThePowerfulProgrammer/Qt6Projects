#include "staffmanager.h"

StaffManager::StaffManager() {}

QList<StaffMember *> StaffManager::getStaffMembersList() const
{
    return StaffMembersList;
}
