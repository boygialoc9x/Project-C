#pragma once

#include "../GameObject/GameObject.h"
#include "../ZyUwU/ZyUwU.h"
#include "../Champion/Champion.h"
#include "../Support/Coordinate.h"
#include "Extension.h"

USING_NS_ALL;

class Arena;
class Property;
class SpecialArena;

enum class HeadDir
{
    FRONT = 1,
    BEHIND = -1
};

enum class MoveType
{
    MOVE_TO,
    MOVE_BY
};

BEGIN_CREATE_REFCLASS(ChampionInGame, Champion)

public:
    static ChampionInGame* createWithChampion(Champion *pChamp, bool bIsClone = true, bool bIsDeleteCloner = false);

public:
    virtual void update(float dt);

public:
//    void move(Coordinate &coord, MoveType eMoveType);
    void autoFlip();
    bool lifeCheck();
    void setLandingArena(Arena *pArena);
    void reloadDataFromMemory(int nRound);
    void addChampChild(ChampionInGame *pChild);
    void setParent(ChampionInGame *pParent);
    std::string getChildsString(int nTab);
    std::string toStringHelper(int nTab = 2, bool bIsShowParent = true);

protected:
    std::map<ChampionAction, ZYSprite*> m_mSprites;
    IngameStatics* m_pIngameStatics;
    Coordinate m_cCoordinate;
    ChampionAction m_eAction;
    std::vector<ChampionInGame*> m_vChilds;
    HeadDir m_eHead;
    std::map<int, Arena*> m_mArenaMemory;
    std::map<int, ChampionInGame*> m_mSelfMemory;
    Arena *m_pLandingArena;
    ChampionInGame* m_pParent;

private:


END_CREATE_REFCLASS