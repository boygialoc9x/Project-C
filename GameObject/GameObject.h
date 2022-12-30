#pragma once

#include "XProperties.h"
#include "../ZyUwU/ZyUwU.H"

class GameObject : public cocos2d::Node
{
public:
	GameObject();
public:
	virtual void update() = 0;
public:
	std::string getName();
	int getPriority();
private:
	XProperties *pProperties;
};


