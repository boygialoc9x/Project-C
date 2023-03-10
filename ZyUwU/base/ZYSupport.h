#pragma once

#include "ZyUwU/platform/ZYMacros.h"
#include "ZYConstant.h"
#include "cocos2d.h"
#include "iomanip"

NS_ZY_BEGIN

#define ZY_SUPPORT_GI zy::ZYSupport::getInstance()

#define ZY_SP_NUMBER_TO_STRING(__NUM__) zy::ZYSupport::getInstance()->numberToString(__NUM__)
#define ZYSP_NTS(__NUM__) ZY_SP_NUMBER_TO_STRING(__NUM__)

#define ZY_SP_SIZE_TO_STRING(__SIZE__) zy::ZYSupport::getInstance()->sizeToString(__SIZE__)
#define ZYSP_STS(__SIZE__) ZY_SP_SIZE_TO_STRING(__SIZE__)

#define ZY_SP_VEC2_TO_STRING(__VEC2__) zy::ZYSupport::getInstance()->vec2ToString(__VEC2__)
#define ZYSP_VTS(__VEC2__) ZY_SP_VEC2_TO_STRING(__VEC2__)

#define ZY_SP_NO_NUMBER_STRING(__STRING__) zy::ZYSupport::getInstance()->noNumberString(__STRING__)
#define ZYSP_NNS(__STRING__) ZY_SP_NO_NUMBER_STRING(__STRING__)

#define ZY_SP_TAB(__NUM__) zy::ZYSupport::getInstance()->tabString(__NUM__);
#define ZYSP_T(__NUM__) ZY_SP_TAB(__NUM__)

#define PI 3.14159265359

BEGIN_CREATE_INSTANCE_REFCLASS(ZYSupport, cocos2d::Ref)

public:
    std::string shorterDecimal(float fNum, int nLength);
    std::string numberToString(float fNum);
    std::string sizeToString(cocos2d::Size size);
    std::string vec2ToString(cocos2d::Point vec2);
    std::string noNumberString(std::string sText);
    std::string tabString(int nTab = 2);

public:
    bool isInt(float fNum);
    bool isOdd(int nNum);

public:
    float radToDegree(float fRad);
    float degreeToRad(float fDegree);

END_CREATE_INSTANCE_REFCLASS

NS_ZY_END
