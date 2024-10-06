#include "chocolate.h"

int Chocolate::serialNumber = 0;

Chocolate::Chocolate() : m_Name(""), m_isVegan(true)
{

    serialNumber += 1;
}
