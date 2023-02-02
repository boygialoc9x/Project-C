#include "Map.h"

MapManager* MapManager::sp_pInstance = nullptr;
//cocos2d::TMXTiledMap* MapManager::p_pTileMap = nullptr;

///// MAP MANAGER

//Constructor

MapManager::MapManager()
{
}

//Public

bool MapManager::init()
{


  	return true;
}

cocos2d::TMXTiledMap* MapManager::getTileMap()
{
	return p_pTileMap;
}
cocos2d::TMXLayer* MapManager::getLayer(std::string sLayerId)
{
	auto it = p_mLayers.find(sLayerId);
	if(it == p_mLayers.end())
	{
		return nullptr;
	}
	return it->second;
}
void MapManager::loadTileMap(std::string sMapName)
{
	this->p_pTileMap = cocos2d::TMXTiledMap::create(sMapName.c_str());

	//p_mLayers[metaLayer.g_sLayerId] = this->p_pTileMap->getLayer(metaLayer.g_sLayerId);
	//p_mLayers[backgroundLayer.g_sLayerId] = this->p_pTileMap->getLayer(backgroundLayer.g_sLayerId);

	LOAD_LAYER(p_pTileMap, metaLayer, p_mLayers);
	LOAD_LAYER(p_pTileMap, backgroundLayer, p_mLayers);

	//this->p_pLayer = this->p_pTileMap->getLayer("collision");
	//this->p_pLayer->setVisible(false);

	//p_pPhysicBody = cocos2d::PhysicsBody::createEdgeBox(p_pLayer->getContentSize());
	//p_pPhysicBody->setContactTestBitmask(5);
	//p_pPhysicBody->setDynamic(false);

	//auto edgeBody = cocos2d::PhysicsBody::createEdgeBox(this->p_pTileMap->getMapSize(), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 1);
	//m_pNode->setPhysicsBody(edgeBody);
	//m_pNode->setPosition(this->p_pTileMap->getMapSize() / 2);

	//m_pSprite = p_pLayer->getTileAt(cocos2d::Point(39,26));
	//m_pSprite->setPhysicsBody(m_pPhysicBody);
	//this->p_pLayer->setPhysicsBody(p_pPhysicBody);
	//this->p_pObjectGroup = this->p_pTileMap->getObjectGroup("collision_1");
}

void MapManager::setScale(cocos2d::Point cScale)
{
	cScale = ZYDirector::getInstance()->recalculateScale(cScale);

	this->p_pTileMap->setMapSize(Size(p_pTileMap->getMapSize().width*cScale.x, p_pTileMap->getMapSize().height*cScale.y));
}

void MapManager::setAnchorPoint(cocos2d::Point anchor)
{
	this->p_pTileMap->setAnchorPoint(anchor);
}

Point MapManager::getPosition()
{
	return this->p_pTileMap->getPosition();
}

void MapManager::config()
{
	p_fAngleAlpha = atan(this->p_pTileMap->getTileSize().height/this->p_pTileMap->getTileSize().width);
	p_fAngleBeta = PI/2 - p_fAngleAlpha;
	this->log();

	this->setScale(Point(ZYDirector::getInstance()->getContentScaleWidth(), ZYDirector::getInstance()->getContentScaleHeight()));
	this->setAnchorPoint(Point::ANCHOR_MIDDLE);
}

void MapManager::setPosition(Point pos)
{
	this->p_pTileMap->setPosition(pos);
}

void MapManager::cleaner()
{
	this->p_pTileMap->release();
	this->p_pObjectGroup->release();
}

cocos2d::Size MapManager::getMapPixelSize()
{
	return cocos2d::Size(this->p_pTileMap->getMapSize().width * this->p_pTileMap->getTileSize().width, this->p_pTileMap->getMapSize().height * this->p_pTileMap->getTileSize().height);
}

cocos2d::Point MapManager::getTileCoordForPosition(cocos2d::Point pos)
{
	int x = pos.x / this->p_pTileMap->getTileSize().width;
	int y = ((this->p_pTileMap->getMapSize().height * this->p_pTileMap->getTileSize().height) - pos.y) / this->p_pTileMap->getTileSize().height;
	//cocos2d::log((std::to_string(x) + " - " + std::to_string(y)).c_str());
	return cocos2d::Point(x, y);
}

Point MapManager::getPositionForTileCoord(Point pos)
{
	float x = (int)pos.x * this->p_pTileMap->getTileSize().width;
	return cocos2d::Point(x,0);
}

void MapManager::log()
{
	ZY_EZ_LOG;
}

std::string MapManager::toString(int nTab)
{
	std::string ts;
	std::string tab = ZY_SP_TAB(nTab);
	std::string tab1 = ZY_SP_TAB(nTab + 1)

	std::string layerToString;
	for (auto it = p_mLayers.begin(); it != p_mLayers.end(); it++)
	{
		layerToString += (tab1 + " > " + it->second->getLayerName());
	}

	ts += (tab + " + Position: " + ZYSP_VTS(p_pTileMap->getPosition()));
	ts += (tab + " + Size in Pixel: " + ZYSP_STS(getMapPixelSize()));
	ts += (tab + " + Size in Tile: " + ZYSP_STS(p_pTileMap->getMapSize()));
	ts += (tab + " + Tile Size: " + ZYSP_STS(p_pTileMap->getTileSize()));
	ts += (tab + " + Layer Map: " + ZYSP_NTS(p_mLayers.size()) + layerToString);
	ts += (tab + " + Angle Alpha: " + ZYSP_NTS(p_fAngleAlpha) + " | Angle Beta: " + ZYSP_NTS(p_fAngleBeta));

	return ts;
}

void MapManager::loadMapFromFile(std::string sFileName)
{

}