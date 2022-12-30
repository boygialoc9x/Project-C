#pragma once
#include "cocos2d.h"
#include "ZyUwU/ZyUwU.h"

class XProperties : public cocos2d::Ref
{
public:
	inline int getPriority()
	{
		return this->p_nPriority;
}

	inline std::string getName()
	{
		return this->p_sName;
	}
private:
	std::string p_sName;
	int p_nPriority;
	std::string p_sDeputizeTexture;
};
