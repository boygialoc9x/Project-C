#pragma once

#include "../../ZyUwU/ZyUwU.h"
#include "../../GameObject/GameObject.h"
#include "../Skill.h"
#include "../../Support/GameConstant.h"

BEGIN_CREATE_REFCLASS(SkillCardLabelProperties, cocos2d::Ref)

public:

protected:
    std::string m_sText;
    int m_nFontSize;
    std::string m_sDirection;

END_CREATE_REFCLASS



BEGIN_CREATE_REFCLASS(SkillCard, GameObject)

#define SET_SPRITE_HELPER(__FUNC_NAME__, __SET_VAR__)                   \
void __FUNC_NAME__(std::string sPath)                                   \
{                                                                       \
    if(FILE_CHECKER(sPath)) __SET_VAR__->replaceSprite(sPath.c_str());  \
}                                                                       \

#define SET_LABEL_HELPER(__FUNC_NAME__, __SET_VAR__) \
void __FUNC_NAME__(std::string sString)              \
{                                                    \
    __SET_VAR__->setString(sString);                 \
}                                                    \

#define SET_FULL_VARIABLE(__ACTION__) \
p_pShapeSprite->__ACTION__;           \
p_pNameSprite->__ACTION__;            \
p_pIconSprite->__ACTION__;            \
p_pManaCostSprite->__ACTION__;        \
p_pSkillPointCostSprite->__ACTION__;  \
p_pDescriptionSprite->__ACTION__;     \
p_pCoolDownSprite->__ACTION__;        \
p_pNameLabel->__ACTION__;             \
p_pDescriptionLabel->__ACTION__;      \
p_pManaCostLabel->__ACTION__;         \
p_pSkillPointCostLabel->__ACTION__;   \
p_pCoolDownLabel->__ACTION__;         \


public:
    static SkillCard* createWithProperties();

public:
    virtual void setOpacity(uint8_t opacity);
    virtual void setPosition(const cocos2d::Point &position);
    virtual void update(float dt);
    virtual Action* runAction(Action* action);

public:
    SET_SPRITE_HELPER(setIconSprite, p_pIconSprite);
    SET_SPRITE_HELPER(setShapeSprite, p_pShapeSprite);
    SET_SPRITE_HELPER(setNameSprite, p_pNameSprite);
    SET_SPRITE_HELPER(setManaCostSprite, p_pManaCostSprite);
    SET_SPRITE_HELPER(setSkillPointCostSprite, p_pSkillPointCostSprite);
    SET_SPRITE_HELPER(setDescriptionSprite, p_pDescriptionSprite);
    SET_SPRITE_HELPER(setCoolDownSprite, p_pCoolDownSprite);

    SET_LABEL_HELPER(setNameLabel, p_pNameLabel);
    SET_LABEL_HELPER(setDescriptionLabel, p_pDescriptionLabel);
    SET_LABEL_HELPER(setManaCostLabel, p_pManaCostLabel);
    SET_LABEL_HELPER(setSkillPointCostLabel, p_pSkillPointCostLabel);
    SET_LABEL_HELPER(setCoolDownLabel, p_pCoolDownLabel);

    void config();

private:
    zy::ZYSprite *p_pIconSprite, *p_pShapeSprite, *p_pNameSprite,
        *p_pManaCostSprite, *p_pSkillPointCostSprite, *p_pDescriptionSprite,
        *p_pCoolDownSprite;

    zy::ZYLabel *p_pNameLabel, *p_pDescriptionLabel, *p_pManaCostLabel,
        *p_pSkillPointCostLabel, *p_pCoolDownLabel;

private:
    int const pc_nNameSize = 24, pc_nDescriptionSize = 12, pc_nManaCostSize = 14;
    int const pc_nSkillPointSize = 14, pc_nCoolDown = 14;


END_CREATE_REFCLASS
