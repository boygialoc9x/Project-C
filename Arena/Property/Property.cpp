#include "Property.h"

//// Constructor

Property::Property() :
m_pPrice(Economy::IngameCoin),
m_pTax(Economy::IngameCoin),
m_pValue(Economy::IngameCoin),
m_fSellMultiple(0),
m_fIncomeMultiple(0)
{

}

//// Public

//Virtual

bool Property::init()
{
    m_bIsBuyAble = true;
    return true;
}

void Property::log()
{
    ZY_EZ_LOG;
}

std::string Property::toString(int nTab)
{
    std::string ts;
    std::string tab = ZY_SP_TAB(nTab);
    ts = Arena::toString();
    ts += tab + " > Price: " + m_pPrice->toString(nTab + 1 );
    ts += tab + " > Tax: " + m_pTax->toString(nTab + 1);
    ts += tab + " > Value: " + m_pValue->toString(nTab + 1);
    ts += tab + " + Sell Multiple: " + ZY_SP_NUMBER_TO_STRING(m_fSellMultiple);
    ts += tab + " + Income Multiple: " + ZY_SP_NUMBER_TO_STRING(m_fIncomeMultiple);
    return ts;
}

void Property::update(float dt)
{

}

void Property::onLand()
{

}
