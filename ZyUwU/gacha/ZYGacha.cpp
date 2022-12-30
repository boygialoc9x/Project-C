#include "ZYGacha.h"
NS_ZY_BEGIN

//

GachaItem::GachaItem()
{

}

bool GachaItem::init()
{
    return true;
}

std::vector<GachaItem*> GachaItem::createVec(GachaItem *pItem, ...)
{
    va_list args;
    va_start(args, pItem);

    std::vector<GachaItem*> vList;

    GachaItem *pElement = va_arg(args, GachaItem*);
    vList.push_back(pElement);

    while(pElement != nullptr)
    {
        vList.push_back(pElement);
        pElement = va_arg(args, GachaItem*);
    }
    va_end(args);

    return vList;
}

std::vector<GachaItem*> ZYGacha::successList(std::vector<GachaItem *> vList)
{
    int nTotalRate = 0;
    std::vector<GachaItem*> vSList;
    if(vList.size() < 0) return vSList;

    for(int i = 0; i < vList.size(); i ++)
    {
        nTotalRate+= vList[i]->getRate();
    }


}

//

ZYGacha* ZYGacha::sp_pInstance = nullptr;

ZYGacha::ZYGacha()
{

}

bool ZYGacha::getRandom(float fRate, bool bIsPercent)
{
    if (!bIsPercent) fRate /= 100;

    if (fRate >= 1) return true;
    if (fRate <= 0) return false;

    int nRate = MAXRATE * fRate;

    Fraction frac = Fraction::fastShortCut(nRate, MAXRATE);
    int luckyNumber = cocos2d::random(1, frac.getDenominator());

    CCLOG("-----BEGIN-----");
    frac.log();
    CCLOG("%d", luckyNumber);
    CCLOG("------END------");

    if ( frac.getNumerator() * 2 <= frac.getDenominator() && luckyNumber % 2 == 0 && luckyNumber <= frac.getNumerator() * 2)
    {
        return true;
    }

    if (frac.getNumerator() * 2 > frac.getDenominator())
    {
        if (luckyNumber % 2 == 0)
        {
            return true;
        }
        else if (luckyNumber % 2 != 0 && luckyNumber <= (frac.getNumerator() - (frac.getDenominator() / 2)) - 1)
        {
            return true;
        }
    }

    return false;
}

NS_ZY_END