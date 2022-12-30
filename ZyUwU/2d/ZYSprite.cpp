#include "ZYSprite.h"
#include "../renderer/backend/Device.h"
#include "../renderer/ccShaders.h"

NS_ZY_BEGIN
//Nova Sprite
ZYSprite::ZYSprite()
{

}
ZYSprite* ZYSprite::create(const char* pFileName)
{
	ZYSprite* pElement = new (std::nothrow) ZYSprite();
	if (pElement && pElement->initWithFile(pFileName))
	{
		pElement->autorelease();
		pElement->firstInit();
		return pElement;
	}
	CC_SAFE_DELETE(pElement);
	return nullptr;
}
void ZYSprite::log()
{
	CCLOG("CALL ZYSPRITE SIZE: %f - %f", this->getContentSize().width, this->getContentSize().height);
	CCLOG("CALL ZYSPRITE POS: %f - %f", this->getPositionX(), this->getPositionY());
}
ZYSprite* ZYSprite::create(cocos2d::Texture2D *p)
{
	ZYSprite* pE = new (std::nothrow) ZYSprite();
	if(pE && pE->initWithTexture(p))
	{
		pE->autorelease();
		pE->firstInit();
		return pE;
	}
	CC_SAFE_DELETE(p);
	return nullptr;
}
bool ZYSprite::firstInit()
{
	this->setScale();
	return true;
}
void ZYSprite::setScale()
{
	cocos2d::Sprite::setContentSize(cocos2d::Size(this->getContentSize().width * ZYDirector::getInstance()->getContentScaleWidth(), this->getContentSize().height * ZYDirector::getInstance()->getContentScaleHeight()));
}
bool ZYSprite::initWithFile(const std::string& filename)
{
	if (!this->isValidFile(filename))
	{
		CCLOG("Call ZYSprite: This file doesn't exist");
		return false;
	}
	return this->cocos2d::Sprite::initWithFile(filename);
}


//ZyUwU Sprite Blur
ZYSpriteBlur::~ZYSpriteBlur()
{
}
ZYSpriteBlur* ZYSpriteBlur::create(const char* pPszFileName)
{
	ZYSpriteBlur* pElement = new (std::nothrow) ZYSpriteBlur();

	if (pElement && pElement->initWithFile(pPszFileName))
	{
		pElement->autorelease();
		return pElement;
	}
	CC_SAFE_DELETE(pElement);
	return nullptr;
}
ZYSpriteBlur* ZYSpriteBlur::create(cocos2d::Texture2D *p)
{
	ZYSpriteBlur* pE = new (std::nothrow) ZYSpriteBlur();

	cocos2d::Rect rect = cocos2d::Rect::ZERO;
	rect.size = p->getContentSize();
	if(pE && pE->initWithTexture(p, rect))
	{
		pE->autorelease();
		return pE;
	}
	CC_SAFE_DELETE(p);
	return nullptr;
}
bool ZYSpriteBlur::initWithTexture(cocos2d::Texture2D* pTexture, const cocos2d::Rect& rect)
{
	this->m_fBlurRadius = 0;
	if (cocos2d::Sprite::initWithTexture(pTexture, rect))
	{
		#if CC_ENABLE_CACHE_TEXTURE_DATA
		auto pListener = cocos2d::EventListenerCustom::create(EVENT_RENDERER_RECREATED,
			[this](cocos2d::EventCustom* pEvent)
			{
				this->initProgram();
			}
		);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(pListener, this);
		#endif 
		this->initProgram();
		return true;
	}
	return false;
}

void ZYSpriteBlur::initProgram()
{
	std::string sFragSource = cocos2d::FileUtils::getInstance()->getStringFromFile(
		cocos2d::FileUtils::getInstance()->fullPathForFilename("Shaders/SimpleBlur.fsh"));

    auto program = cocos2d::backend::Device::getInstance()->newProgram(cocos2d::positionTextureColor_vert, sFragSource.data());
    auto programState = new cocos2d::backend::ProgramState(program);
    this->setProgramState(programState);
    CC_SAFE_RELEASE(programState);
    CC_SAFE_RELEASE(program);
    
    auto size = getTexture()->getContentSizeInPixels();

    SET_UNIFORM(_programState, "resolution", size);
    SET_UNIFORM(_programState, "blurRadius", m_fBlurRadius);
    SET_UNIFORM(_programState, "sampleNum", 7.0f);
    SET_UNIFORM(_programState, "u_PMatrix", cocos2d::Director::getInstance()->getMatrix(cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION));
	
}

void ZYSpriteBlur::setBlurRadius(float fRadius)
{
	this->m_fBlurRadius = fRadius;
	SET_UNIFORM(_programState,"blurRadius", this->m_fBlurRadius);
}

void ZYSpriteBlur::setBlurSampleNumber(float fNumber)
{
	this->m_fBlurSampleNumber = fNumber;
	SET_UNIFORM(_programState, "sampleNum", this->m_fBlurSampleNumber);
}

NS_ZY_END