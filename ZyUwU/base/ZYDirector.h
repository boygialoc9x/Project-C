#pragma once

#include "../platform/ZYMacros.h"
#include "../math/ZYFraction.h"
#include "cocos2d.h"
#include "ZYConstant.h"

NS_ZY_BEGIN
BEGIN_CREATE_INSTANCE_REFCLASS(ZYDirector, cocos2d::Director)                          \
public:
    void setContenScaleWidth(Fraction tFraction);
    void setContenScaleHeigth(Fraction tFraction);
    void setContentScaleWidth(float fScaleFactor);
    void setContentScaleHeight(float fScaleFactor);
    void setTheRunningScene(cocos2d::Scene *pScene);
    cocos2d::Scene* getTheRunningScene();
    float getContentScaleWidth() {return m_pContentScale_Width;}
    float getContentScaleHeight() {return m_pContentScale_Height;}
protected:
    float m_pContentScale_Width = 1.0f;
    float m_pContentScale_Height = 1.0f;
    cocos2d::Scene *m_pRunningScene = nullptr;


END_CREATE_INSTANCE_REFCLASS;
NS_ZY_END