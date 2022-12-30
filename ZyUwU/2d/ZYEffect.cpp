#include "ZYEffect.h"
#include "../renderer/backend/Device.h"
#include "../renderer/ccShaders.h"

NS_ZY_BEGIN

//ZyUwU Blur Effect
bool ZYBlurEffect::init()
{
    if(!m_pSprite) return false;
    cocos2d::Rect rect = cocos2d::Rect::ZERO;
    rect.size = m_pSprite->getTexture()->getContentSize();
    initWithTexture(m_pSprite->getTexture(), rect);
    return true;
}

bool ZYBlurEffect::initWithTexture(cocos2d::Texture2D *pTexture, const cocos2d::Rect &rect)
{
    this->m_fBlurRadius = 0;
    if (m_pSprite->initWithTexture(pTexture, rect))
    {
#if CC_ENABLE_CACHE_TEXTURE_DATA
        auto pListener = cocos2d::EventListenerCustom::create(EVENT_RENDERER_RECREATED,
															  [this](cocos2d::EventCustom* pEvent)
															  {
																  this->initProgram();
															  }
		);
		m_pSprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pListener, m_pSprite);
#endif
        this->initProgram();
        return true;
    }
    return false;
}
void ZYBlurEffect::initProgram()
{

    std::string sFragSource = cocos2d::FileUtils::getInstance()->getStringFromFile(
            cocos2d::FileUtils::getInstance()->fullPathForFilename("Shaders/SimpleBlur.fsh"));

    auto program = cocos2d::backend::Device::getInstance()->newProgram(cocos2d::positionTextureColor_vert, sFragSource.data());
    auto programState = new cocos2d::backend::ProgramState(program);
    m_pSprite->setProgramState(programState);
    CC_SAFE_RELEASE(programState);
    CC_SAFE_RELEASE(program);

    auto size = m_pSprite->getTexture()->getContentSizeInPixels();

    SET_UNIFORM(m_pSprite->getProgramState(), "resolution", size);
    SET_UNIFORM(m_pSprite->getProgramState(), "blurRadius", m_fBlurRadius);
    SET_UNIFORM(m_pSprite->getProgramState(), "sampleNum", 7.0f);
    SET_UNIFORM(m_pSprite->getProgramState(), "u_PMatrix", cocos2d::Director::getInstance()->getMatrix(cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION));
}

void ZYBlurEffect::setBlurSampleNumber(float fNumber)
{
    this->m_fBlurSampleNumber = fNumber;
    SET_UNIFORM(m_pSprite->getProgramState(), "sampleNum", this->m_fBlurSampleNumber);
}
void ZYBlurEffect::setBlurRadius(float fRadius)
{
    this->m_fBlurRadius = fRadius;
    SET_UNIFORM(m_pSprite->getProgramState(),"blurRadius", this->m_fBlurRadius);
}

NS_ZY_END