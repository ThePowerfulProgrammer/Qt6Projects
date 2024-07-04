#include "registration.h"

QMultiMap<QString, QString> Registration::allRegistrations;

Registration::Registration(Person a) : m_Attendee(a), STANDARD_FEE(500),
    m_BookingDate(QDate::currentDate())
{

    if (allRegistrations.contains(a.getName(), a.getEmail()) == true)
    {
        qDebug() << "Registrations cannot be for the same Person with the same email address \n";
    }
    else
    {
        allRegistrations.insert(a.getName(), a.getEmail());
    }
    // remove the below after video
    QMultiMapIterator<QString, QString> i(allRegistrations);
    while (i.hasNext())
    {
        i.next();
        qDebug() << "Key: " << " Value: " << "\n";
        qDebug() << i.key() << " : " << i.value() << "\n";
    }

    qDebug() << "run Complete" << "\n";
}

QDate Registration::getBookingDate()
{
    return m_BookingDate;
}

Person Registration::getAttendee()
{
    return m_Attendee;
}

double Registration::calculateFee()
{
    return STANDARD_FEE;
}

QString Registration::toString()
{
    return QString("%1 %2 ").arg(m_Attendee.toString()).arg(m_BookingDate.toString("dd.MM.yyyy"));
}



