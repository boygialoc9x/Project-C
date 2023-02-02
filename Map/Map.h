#pragma once

#include "../ZyUwU/ZyUwU.h"
#include "Support/GameConstant.h"
#include "User/Helper.h"

USING_NS_ALL;

#define MAP_MNG_GI MapManager::getInstance()

#define LOAD_LAYER(__TILE_MAP__, __LAYER_CONSTANT__, __LAYER_MAP__) \
{                                                                   \
	auto ret = __TILE_MAP__->getLayer(__LAYER_CONSTANT__.g_sLayerId);\
	if(ret)      \
    {                                                                  \
        __LAYER_MAP__[__LAYER_CONSTANT__.g_sLayerId] = __TILE_MAP__->getLayer(__LAYER_CONSTANT__.g_sLayerId); \
        __LAYER_MAP__[__LAYER_CONSTANT__.g_sLayerId]->setVisible(__LAYER_CONSTANT__.g_bIsVisible);\
    }\
}	\

BEGIN_CREATE_INSTANCE_REFCLASS(MapManager, cocos2d::Ref)                          \

public:
	cocos2d::TMXTiledMap* getTileMap();
	cocos2d::TMXLayer* getLayer(std::string sLayerId);
	void loadTileMap(std::string sMapName);
	cocos2d::Point getPosition();
	void cleaner();
	void setPosition(cocos2d::Point pos);
	void setAnchorPoint(cocos2d::Point anchor);

	void loadMapFromFile(std::string sFileName);

	void config();
	void setScale(cocos2d::Point cScale);

	CREATE_GET_FUNC(getAngleAlphaInRad, float, p_fAngleAlpha);
	CREATE_GET_FUNC(getAngleAlpha, float, ZY_SUPPORT_GI->radToDegree(p_fAngleAlpha));
	CREATE_GET_FUNC(getAngleBetaInRad, float, p_fAngleBeta);
	CREATE_GET_FUNC(getAngleBeta, float, ZY_SUPPORT_GI->radToDegree(p_fAngleBeta));

	/**
	* Check if input position is contact to a collision object
	* 
	* @pragma: position need to be checked 
	* @return: TRUE -> Contaced to a collision object
	* @return: FALSE -> NO Contact happen
	*/
	cocos2d::Size getMapPixelSize();
	cocos2d::Sprite* getSprite() { return this->p_pSprite; }

	cocos2d::Point getTileCoordForPosition(cocos2d::Point pos);
	cocos2d::Point getPositionForTileCoord(Point pos);
private:
	cocos2d::TMXTiledMap* p_pTileMap;
    std::map<std::string, cocos2d::TMXLayer*> p_mLayers;
	cocos2d::PhysicsBody* p_pPhysicBody;
	cocos2d::Sprite* p_pSprite;
	cocos2d::TMXObjectGroup* p_pObjectGroup;
	float p_fAngleAlpha, p_fAngleBeta;

END_CREATE_INSTANCE_REFCLASS;
