#pragma once
#include "cocos2d.h"
#include "../platform/ZYMacros.h"
#include "../base/ZYDirector.h"
NS_ZY_BEGIN

class ZYSprite : public cocos2d::Sprite
{
public:
	static ZYSprite* create(const char* pFileName);
	static ZYSprite* create(cocos2d::Texture2D *p);
public:
	bool firstInit();
	void log();
	virtual bool initWithFile(const std::string& filename);
	void forceReplace(ZYSprite *p)
	{
		this->setTexture(p->getTexture());
	}
	void setScale();
	CLEANER_ZYFUNC(ZYSprite);
private:
	ZYSprite();
	FILE_CHECKER_ZYFUNC(ZYSprite);
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
