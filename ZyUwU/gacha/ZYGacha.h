#pragma once

#include "../math/ZYFraction.h"
#include "../platform/ZYMacros.h"


#include "cocos2d.h"

NS_ZY_BEGIN

BEGIN_CREATE_REFCLASS(GachaItem, cocos2d::Ref)

public:
    inline int getRate() {return this->m_nRate;}
public:
    static std::vector<GachaItem*> createVec(GachaItem * pItem, ...) CC_REQUIRES_NULL_TERMINATION;

protected:
    int m_nRate, m_nAmount;
    std::string m_sItemType;

END_CREATE_REFCLASS

BEGIN_CREATE_INSTANCE_REFCLASS(ZYGacha, cocos2d::Ref)
public:

    /**
     * Test the lucky
     *
     * @praama fRate: the change to be success
     * @pragma bIsPercent: set TRUE if the input is decimal (0.05)\n
     *                         FALSE if the input is not decimal (5%)
     * @return true: success\n
     *         false: fail
     */
    bool getRandom(float fRate, bool bIsDecimal = true);


    static std::vector<GachaItem*> successList(std::vector<GachaItem*> vList);

END_CREATE_REFCLASS
NS_ZY_END