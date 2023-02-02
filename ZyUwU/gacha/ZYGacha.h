#pragma once

#include "ZyUwU/math/ZYFraction.h"
#include "ZyUwU/platform/ZYMacros.h"


#include "cocos2d.h"

NS_ZY_BEGIN

BEGIN_CREATE_REFCLASS(GachaItem, cocos2d::Ref);

public:
    inline int getRate() {return this->m_nRate;}
    inline int getAmount() {return this->m_nAmount;}
    inline std::string getItemType() {return this->m_sItemType;}

    inline void setRate(int nRate) {this->m_nRate = nRate;}
    inline void setAmount(int nAmount) {this->m_nAmount = nAmount;}
    inline void setItemType(std::string sItemType) {this->m_sItemType = sItemType;}

public:
    static std::vector<GachaItem*> createItemList(GachaItem *pItem, ...) CC_REQUIRES_NULL_TERMINATION;
    static GachaItem* createWithProperties(int nRate , int nAmount , std::string sItemType);
protected:
    int m_nRate, m_nAmount;
    std::string m_sItemType;

END_CREATE_REFCLASS;





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
    bool runGacha(float fRate, bool bIsDecimal = true);
public:
    static std::vector<GachaItem*> generateSuccessList(std::vector<GachaItem*> vList, int nRollTime = 1);

END_CREATE_REFCLASS
NS_ZY_END