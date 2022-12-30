#pragma once

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
#include "../platform/ZYMacros.h"

NS_ZY_BEGIN
BEGIN_CREATE_INSTANCE_REFCLASS(ZYSoundManager, cocos2d::Ref)
public:
	void playGameFightSound();
	void playMainMenuSound();
	void setVolume();
	void playSoundEffect(std::string sPath);
private:
	int p_nBattleIndex, p_nMenuIndex;
END_CREATE_INSTANCE_REFCLASS;
NS_ZY_END
