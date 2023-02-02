#pragma once

#include "ZyUwU/ZyUwU.h"
#include "GlobalArena.h"
#include "GameObject/GameObject.h"
#include "Support/Coordinate.h"
#include "GameEffect/GameEffect.h"
#include "ChampionInGame/ChampionInGame.h"

USING_NS_ALL;

BEGIN_CREATE_REFCLASS(Arena, GameObject)

public:
    void setCoordinate(Coordinate &coord);
    void autoSortChampion();
    void autoRotate();
    void autoSetPosition();

    Point getMoveAblePosition();
    CREATE_GET_FUNC(getChampionInArena, std::vector<ChampionInGame*>, m_vChampions);
    CREATE_GET_FUNC(getNumberChampionInArena, int, m_vChampions.size());
    void addChampion(ChampionInGame *pChamp);

public:
    virtual void update(float dt);
    virtual void onLand() {};

protected:
    Coordinate m_Coord;
    Size m_Size;
    bool m_bIsBuyAble;
    ZYLabel* m_pTitle;
    std::vector<GameEffect*> m_vEffectLayer;
    std::vector<ZYSprite*> m_vIcons;
    std::vector<ChampionInGame*> m_vChampions;

private:

END_CREATE_REFCLASS


