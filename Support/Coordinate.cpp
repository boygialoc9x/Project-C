#include "Coordinate.h"

//Constructor

Coordinate::Coordinate(Dir eDir, int nIndex)
{
    this->g_eDir = eDir;
    this->g_nIndex = nIndex;
}

//Public

void Coordinate::log()
{
    CCLOG("CALL COORDINATE: %s", this->toString().c_str());
}

std::string Coordinate::toString(int nTab)
{
    std::string ts;
    std::string tab = ZY_SP_TAB(nTab);
    ts += (tab + " + Index: " + ZY_SP_NUMBER_TO_STRING(g_nIndex));
    ts += (tab + " + Dir: " + ZY_SP_NUMBER_TO_STRING((int)g_eDir));
    return ts;
}

//Operator
void Coordinate::operator=(Coordinate &c)
{
    this->g_eDir = c.g_eDir;
    this->g_nIndex = c.g_nIndex;
}
