#pragma once

#include "cocos2d.h"
#include "ZyUwU/platform/ZYMacros.h"
#include "ZyUwU/base/ZYDirector.h"

NS_ZY_BEGIN

class ZYSprite : public cocos2d::Sprite
{
public:
	static ZYSprite* create(const char* pFileName, bool bIsScale = true);
	static ZYSprite* create(cocos2d::Texture2D *p);
public:
	cocos2d::Point getContentPositionWithNewAnchorPoint(cocos2d::Point cNewAnchorPoint);

    cocos2d::Point getContentPositionMiddleTop();
    cocos2d::Point getContentPositionMiddleBottom();
	cocos2d::Point getContentPositionTopLeft();
	cocos2d::Point getContentPositionTopRight();
	cocos2d::Point getContentPositionBottomRight();
	cocos2d::Point getContentPositionBottomLeft();
	cocos2d::Point getContentPositionMiddle();

	cocos2d::Point getDifferentAnchorPoint(cocos2d::Point cNewAnchorPoint);

	virtual std::string toString(int nTab = 2);
	virtual void setPosition(const cocos2d::Vec2& pos, cocos2d::Vec2 newAnchor);
	virtual void setPosition(const cocos2d::Vec2& pos);
	virtual void setPosition(const int xx, const int yy);

	bool firstInit();
	void log();
	virtual bool initWithFile(const std::string& filename);
	bool replaceTexture(std::string sPath);
	bool replaceTexture(ZYSprite *pSprite);
	bool replaceTexture(cocos2d::Texture2D *pTexture);
	bool replaceSprite(std::string sPath);

	void setScale();
	CLEANER_ZYFUNC(ZYSprite);
private:
	ZYSprite();
	virtual ~ZYSprite();
	FILE_CHECKER_ZYFUNC(ZYSprite);
	const char* p_sClassName = typeid(this).name();
};

class ZYSpriteBlur : public cocos2d::Sprite
{
public:
	~ZYSpriteBlur();
	bool initWithTexture(cocos2d::Texture2D *pTexture, const cocos2d::Rect& rect);
	void initProgram();
	void setBlurRadius(float fRadius);
	void setBlurSampleNumber(float fNumber);
public:
	static ZYSpriteBlur* create(const char* pPszFileName);
	static ZYSpriteBlur* create(cocos2d::Texture2D *p);
protected:
	float m_fBlurRadius;
	float m_fBlurSampleNumber;

};

NS_ZY_END
