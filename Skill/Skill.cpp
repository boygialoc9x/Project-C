#include "Skill.h"

// SkillStatics

/**  @Note Damage Multiplier work the same as Dota2.
 *   @Formula DMG = 1 - ( (f*R) / (b+f*|R|) )
 *   @With     f is ARMOR FORMULA FACTOR = 0.06\n
 *             R is armor value\n
 *             b is ARMOR FORMULA BASE = 1\n
 *             DMG being the Damage multiplier\n
 */

SkillStatics::SkillStatics()
{
    m_fPhysicDmg, m_fMagicDmg = 0;
    m_fPureDmg = 0;
    m_cPhysicPie, m_cMagicPie = 0;
    m_nCoolDown = 0;
    m_fMnCost, m_fHpCost, m_fSpCost = 0;
    m_cPhysicCrit, m_cMagicCrit = 0;
    m_sDescription = "";
}
bool SkillStatics::init()
{
    return true;
}
SkillStatics* SkillStatics::clone()
{
    auto pElement = SkillStatics::create();

    if(pElement)
    {
        pElement->setMagicDmg(this->getMagicDmg());
        pElement->setPhysicDmg(this->getPhysicDmg());
        pElement->setPhysicPiercing(this->getThePhysicPiercing());
        pElement->setMagicPiercing(this->getTheMagicPiercing());
        pElement->setManaCost(this->getManaCost());
        pElement->setHpCost(this->getHpCost());
        pElement->setSpCost(this->getSpCost());
        pElement->setCoolDown(this->getCoolDown());
        pElement->setPhysicCrit(this->getThePhysicCrit());
        pElement->setMagicCrit(this->getTheMagicCrit());
        pElement->setDescription(this->getDescription());
        return pElement;
    }

    CC_SAFE_DELETE(pElement);
    return nullptr;
}