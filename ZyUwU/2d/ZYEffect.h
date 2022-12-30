#pragma once
#include "cocos2d.h"
#include "../platform/ZYMacros.h"
#include "ZYSprite.h"

NS_ZY_BEGIN

class ZYSprite;

class ZYEffect : public cocos2d::Ref
{
public:
    virtual bool initWithTexture(cocos2d::Texture2D *pTexture, const cocos2d::Rect& rect) = 0;
    virtual void initProgram() = 0;
    virtual bool init() = 0;
public:
    void setZYSprite(ZYSprite *pSprite)
    {
        m_pSprite = pSprite;
        this->init();
    }
protected:
    ZYSprite *m_pSprite;
};

class ZYBlurEffect : public ZYEffect
{
public:
    virtual bool initWithTexture(cocos2d::Texture2D *pTexture, const cocos2d::Rect& rect);
    virtual void initProgram();
    virtual bool init();
public:
    void setBlurRadius(float fRadius);
    void setBlurSampleNumber(float fNumber);
protected:
    float m_fBlurRadius;
    float m_fBlurSampleNumber;
};

NS_ZY_END
