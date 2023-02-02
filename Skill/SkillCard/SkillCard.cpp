#include "SkillCard.h"

USING_NS_ALL

//**// SKILL-CARD PROPERTIES CLASS

//Constructor

SkillCardLabelProperties::SkillCardLabelProperties() :
m_sText(""),
m_nFontSize(0),
m_sDirection(globalFont)
{

}

//Public

bool SkillCardLabelProperties::init()
{
    return true;
}

void SkillCardLabelProperties::log()
{

}

std::string SkillCardLabelProperties::toString(int nTab)
{
    std::string ts;
    return ts;
}

////**//// SKILL-CARD CLASS

//Constructor

SkillCard::SkillCard() :
p_pIconSprite(ZYSprite::create(m_pProperties->getDeputizeTexture().c_str())),
p_pShapeSprite(ZYSprite::create(m_pProperties->getDeputizeTexture().c_str())),
p_pNameSprite(ZYSprite::create(m_pProperties->getDeputizeTexture().c_str())),
p_pManaCostSprite(ZYSprite::create(m_pProperties->getDeputizeTexture().c_str())),
p_pSkillPointCostSprite(ZYSprite::create(m_pProperties->getDeputizeTexture().c_str())),
p_pDescriptionSprite(ZYSprite::create(m_pProperties->getDeputizeTexture().c_str())),
p_pCoolDownSprite(ZYSprite::create(m_pProperties->getDeputizeTexture().c_str())),
p_pNameLabel(ZYLabel::createWithTTF("", globalFont, pc_nNameSize)),
p_pDescriptionLabel(ZYLabel::createWithTTF("", globalFont, pc_nDescriptionSize)),
p_pManaCostLabel(ZYLabel::createWithTTF("", globalFont, pc_nManaCostSize)),
p_pSkillPointCostLabel(ZYLabel::createWithTTF("", globalFont, pc_nSkillPointSize)),
p_pCoolDownLabel(ZYLabel::createWithTTF("", globalFont, pc_nCoolDown))
{

}

SkillCard* SkillCard::createWithProperties()
{
    return nullptr;
}

//Public

void SkillCard::update(float dt)
{

}

bool SkillCard::init()
{
    this->setName("SKILL - CARD");
    //p_pIconSprite = zy::ZYSprite::create("HelloWorld.png");
    //p_pIconSprite->setPosition(ZYDirector::getInstance()->getTrueVisibleSize()/2);

    //p_pNameLabel = zy::ZYLabel::createWithTTF("AC WY", "fonts/arial.ttf", 50);
    //p_pNameLabel->setPosition(Point(p_pIconSprite->getPositionX(), p_pIconSprite->getPositionY()+20));

    this->addChild(p_pShapeSprite, 0);
    this->addChild(p_pNameSprite, 2);
    this->addChild(p_pManaCostSprite, 3);
    this->addChild(p_pSkillPointCostSprite, 2);
    this->addChild(p_pIconSprite, 1);
    this->addChild(p_pDescriptionSprite, 1);
    this->addChild(p_pCoolDownSprite, 1);

    this->addChild(p_pNameLabel, 4);
    this->addChild(p_pDescriptionLabel, 4);
    this->addChild(p_pManaCostLabel, 4);
    this->addChild(p_pSkillPointCostLabel, 4);
    this->addChild(p_pCoolDownLabel, 4);

    return true;
}

//Public

void SkillCard::config()
{
    //Set Position follow ShapeSprite
    p_pIconSprite->setPosition(p_pShapeSprite->getContentPositionMiddleTop(), Vec2::ANCHOR_MIDDLE_TOP);
    p_pManaCostSprite->setPosition(p_pShapeSprite->getContentPositionTopLeft(), Vec2::ANCHOR_MIDDLE_TOP);

    p_pCoolDownSprite->setPosition(Point(p_pShapeSprite->getContentPositionTopLeft().x, p_pShapeSprite->getContentPositionTopLeft().y - p_pNameSprite->getContentSize().height), Vec2::ANCHOR_TOP_LEFT);

    p_pDescriptionSprite->setPosition(Point(p_pShapeSprite->getContentPositionMiddle().x,
                                            (p_pShapeSprite->getContentSize().height - p_pIconSprite->getContentSize().height)/2 + p_pShapeSprite->getContentPositionMiddleBottom().y));


    //Set Position follow ManaCostSprite
    p_pSkillPointCostSprite->setPosition(Point(p_pManaCostSprite->getContentPositionMiddleTop().x, p_pManaCostSprite->getContentPositionMiddleTop().y - p_pManaCostSprite->getContentSize().height/4*3), Vec2::ANCHOR_MIDDLE_TOP);
    p_pNameSprite->setPosition(p_pManaCostSprite->getContentPositionTopRight(), Vec2::ANCHOR_TOP_LEFT);

    p_pNameLabel->setPosition(p_pNameSprite->getPosition());

    //Set Position follow NameSprite

}

void SkillCard::setOpacity(uint8_t opacity)
{
    //cocos2d::Node::setOpacity(opacity);
    
    if(p_pIconSprite) p_pIconSprite->setOpacity(opacity);
    if(p_pShapeSprite) p_pShapeSprite->setOpacity(opacity);
    if(p_pNameSprite) p_pNameSprite->setOpacity(opacity);
    if(p_pManaCostSprite) p_pShapeSprite->setOpacity(opacity);
    if(p_pSkillPointCostSprite) p_pSkillPointCostSprite->setOpacity(opacity);

    if(p_pNameLabel) p_pNameLabel->setOpacity(opacity);
    if(p_pDescriptionLabel) p_pDescriptionLabel->setOpacity(opacity);
    if(p_pManaCostLabel) p_pManaCostLabel->setOpacity(opacity);
    if(p_pSkillPointCostLabel) p_pSkillPointCostLabel->setOpacity(opacity);
    if(p_pCoolDownLabel) p_pCoolDownLabel->setOpacity(opacity);
}

void SkillCard::setPosition(const cocos2d::Point &position)
{
    if(position != p_pShapeSprite->getContentPositionMiddle())
    {
        p_pShapeSprite->setPosition(position);
        this->config();
    }
}

Action* SkillCard::runAction(Action* action)
{
    CCASSERT(action != nullptr, "Argument must be non-nil");
    SET_FULL_VARIABLE(runAction(action));
    return action;
}

void SkillCard::log()
{
    ZY_EZ_LOG;
}

std::string SkillCard::toString(int nTab)
{
    std::string ts = GameObject::toString(nTab);
    std::string tab = ZYSP_T(nTab);
    ts += (tab + " + Self Position: " + ZYSP_VTS(getPosition()));
    ZY_TSHP(ts, tab, nTab, " > Icon Sprite: ", p_pIconSprite);
    ZY_TSHP(ts, tab, nTab, " > Shape Sprite: ", p_pShapeSprite);
    ZY_TSHP(ts, tab, nTab, " > Name Sprite: ", p_pNameSprite);
    ZY_TSHP(ts, tab, nTab, " > Mana Cost Sprite: ", p_pManaCostSprite);
    ZY_TSHP(ts, tab, nTab, " > Skill Point Cost Sprite: ", p_pSkillPointCostSprite);
    ZY_TSHP(ts, tab, nTab, " > Description Sprite: ", p_pDescriptionSprite);
    ZY_TSHP(ts, tab, nTab, " > Cool Down Sprite: ", p_pCoolDownSprite);
    ZY_TSHP(ts, tab, nTab, " > Name Label: ", p_pNameLabel);
    return ts;
}