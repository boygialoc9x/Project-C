#include "ZYDirector.h"

NS_ZY_BEGIN

ZYDirector* ZYDirector::sp_pInstance = nullptr;

ZYDirector::ZYDirector()
{
    m_pContentScale_Width = cocos2d::Director::getInstance()->getVisibleSize().width/zy::designResolutionSize.width;
    m_pContentScale_Height = cocos2d::Director::getInstance()->getVisibleSize().height/zy::designResolutionSize.height;
}

void ZYDirector::setContentScaleWidth(float fScaleFactor)
{
    if(fScaleFactor != m_pContentScale_Width)
    {
        m_pContentScale_Width = fScaleFactor;
    }
}

void ZYDirector::setContentScaleHeight(float fScaleFactor)
{
    if(fScaleFactor != m_pContentScale_Height)
    {
        m_pContentScale_Height = fScaleFactor;
    }
}

void ZYDirector::setContenScaleWidth(Fraction tFraction)
{
    if(tFraction.toFloat() != m_pContentScale_Width)
    {
        m_pContentScale_Width = tFraction.toFloat();
    }
}
void ZYDirector::setContenScaleHeigth(Fraction tFraction)
{
    if(tFraction.toFloat() != m_pContentScale_Width)
    {
        m_pContentScale_Height = tFraction.toFloat();
    }
}

NS_ZY_END
