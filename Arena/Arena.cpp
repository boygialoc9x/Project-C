#include "Arena.h"

//// Constructor

Arena::Arena() :
m_Coord(Dir::NE, 0)
{
}

//// Public

//Virtual

bool Arena::init()
{
    this->setName("ARENA");
    return true;
}

void Arena::log()
{
    ZY_EZ_LOG;
}

std::string Arena::toString(int nTab)
{
    std::string ts = GameObject::toString(nTab);
    std::string tab = ZY_SP_TAB(nTab);
    ZY_TSHNP(ts, tab, nTab, " Coordinate: ", m_Coord);
    ts += tab + " + Size: " + ZY_SP_NUMBER_TO_STRING(m_Size.width) + " - " + ZY_SP_NUMBER_TO_STRING(m_Size.height);
    ts += tab + " + Is Buyable: " + ZY_SP_NUMBER_TO_STRING((int)m_bIsBuyAble);

    ZY_TSHV(ts, tab, nTab, " + Effect Layer ", m_vEffectLayer);
    ZY_TSHV(ts, tab, nTab, " + Champions ", m_vChampions);

    for(int i = 0; i < m_vChampions.size(); i++){
        ts += tab + " + Champions [" + ZY_SP_NUMBER_TO_STRING(i) + "]" +
                m_vChampions[i]->toString();
    }

    return ts;
}

//public
void Arena::setCoordinate(Coordinate &coord)
{
    if(m_Coord.g_eDir == coord.g_eDir && m_Coord.g_nIndex == coord.g_nIndex)
    {
        return;
    }
    m_Coord.g_eDir = coord.g_eDir;
}

void Arena::autoSortChampion()
{

}

void Arena::autoRotate()
{

}

void Arena::autoSetPosition()
{
}

Point Arena::getMoveAblePosition()
{
    auto n = this->getNumberChampionInArena();
    return Point::ZERO;
}

void Arena::addChampion(ChampionInGame *pChamp)
{
    m_vChampions.push_back(pChamp);
}

//Virtual

void Arena::update(float dt)
{
    if(m_vChampions.size() > 0)
    {
        this->autoSortChampion();
    }
    this->autoRotate();
    this->autoSetPosition();
}