#pragma once

#include "../ZyUwU/ZyUwU.h"
#include "../Statics/Statics.h"
#include "../GameObject/GameObject.h"

//
BEGIN_CREATE_REFCLASS(SkillStatics, cocos2d::Ref)
public:
    SkillStatics* clone();
public:
    inline float getPhysicDmg() {return this->m_fPhysicDmg;}
    inline float getMagicDmg() {return this->m_fMagicDmg;}

    inline float getPhysicPiercing() {return m_cPhysicPie.getAmount();}
    inline PercentStatics getThePhysicPiercing() {return this->m_cPhysicPie;}

    inline float getMagicPiercing() {return m_cMagicPie.getAmount();}
    inline PercentStatics getTheMagicPiercing() {return this->m_cMagicPie;}

    inline int getCoolDown() {return this->m_nCoolDown;}

    inline float getManaCost() {return this->m_fMnCost;}
    inline float getHpCost() {return this->m_fHpCost;}
    inline float getSpCost() {return this->m_fSpCost;}

    inline CritStatics getThePhysicCrit() {return this->m_cPhysicCrit;}
    inline float getPhysicCritRate() {return this->m_cPhysicCrit.getRate();}
    inline float getPhysicCritDmgMul() {return this->m_cPhysicCrit.getDmgMultiple();}

    inline CritStatics getTheMagicCrit() {return this->m_cMagicCrit;}
    inline float getMagicCritRate() {return this->m_cMagicCrit.getRate();}
    inline float getMagicCritDmgMul() {return this->m_cMagicCrit.getDmgMultiple();}

    inline std::string getDescription() {return this->m_sDescription;}
public:
    inline void setPhysicDmg(float fDmg) {this->m_fPhysicDmg = fDmg;}
    inline void setMagicDmg(float fDmg) {this->m_fMagicDmg = fDmg;}

    inline void setPhysicPiercing(PercentStatics cPhysicPie) {this->m_cPhysicPie = cPhysicPie;}
    inline void setPhysicPiercing(float fAmount) {this->m_cPhysicPie.setAmount(fAmount);}

    inline void setMagicPiercing(PercentStatics cMagicPie) {this->m_cMagicPie = cMagicPie;}
    inline void setMagicPiercing(float fAmount) {this->m_cMagicPie.setAmount(fAmount);}

    inline void setCoolDown(int nCd) { this->m_nCoolDown = nCd;}

    inline void setManaCost(float fAmount) {this->m_fMnCost = fAmount;}
    inline void setHpCost(float fAmount) {this->m_fHpCost = fAmount;}
    inline void setSpCost(float fAmount) {this->m_fSpCost = fAmount;}

    inline void setPhysicCrit(CritStatics cPhysicCrit) { this->m_cPhysicCrit = cPhysicCrit;}
    inline void setPhysicCritMultiplier(float fAmount) {this->m_cPhysicCrit.setDmgMultiple(fAmount);}
    inline void setPhysicCritRate(float fAmount) {this->m_cPhysicCrit.setRate(fAmount);}

    inline void setMagicCrit(CritStatics cMagicCrit) { this->m_cMagicCrit = cMagicCrit;}
    inline void setMagicCritMultiplier(float fAmount) {this->m_cMagicCrit.setDmgMultiple(fAmount);}
    inline void setMagicCritRate(float fAmount) {this->m_cMagicCrit.setRate(fAmount);}

    inline void setDescription(std::string sDescription) {this->m_sDescription = sDescription;}
protected:
    float m_fPhysicDmg, m_fMagicDmg;
    float m_fPureDmg;
    PercentStatics m_cPhysicPie, m_cMagicPie;
    int m_nCoolDown;
    float m_fMnCost, m_fHpCost, m_fSpCost;
    CritStatics m_cPhysicCrit, m_cMagicCrit;
    std::string m_sDescription;
END_CREATE_REFCLASS

//
BEGIN_CREATE_REFCLASS(Skill, cocos2d::Ref)
protected:
    SkillStatics *m_pSkillStatics;


END_CREATE_REFCLASS
