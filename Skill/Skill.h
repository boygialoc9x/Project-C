#pragma once

#include "../ZyUwU/ZyUwU.h"
#include "../Statics/Statics.h"
#include "../GameObject/GameObject.h"
#include "SkillStatics/SkillStatics.h"
//#include "SkillCard/SkillCard.h"

USING_NS_ALL;

class SkillCard;

BEGIN_CREATE_REFCLASS(Skill, GameObject)

public:
    static Skill* createWithProperties(XProperties *pProperties, SkillStatics *pStatics, bool bIsClone = true, bool bIsClean = false);

public:
    virtual void update(float dt);

public:
    CREATE_CLONE_SET_FUNC(setProperties, XProperties, m_pProperties);
    CREATE_CLONE_SET_FUNC(setStatics, SkillStatics, m_pSkillStatics);

protected:
    SkillStatics *m_pSkillStatics;
    SkillCard *m_pSkillCard;

END_CREATE_REFCLASS
