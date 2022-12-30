#include "ZYAudio.h"
NS_ZY_BEGIN

ZYSoundManager* ZYSoundManager::sp_pInstance = nullptr;

ZYSoundManager::ZYSoundManager()
{

}

void ZYSoundManager::playGameFightSound()
{
//	p_nBattleIndex = cocos2d::AudioEngine::play2d(User::GetInstance()->GetUserSound()->g_sGameFight, true, User::GetInstance()->GetUserSound()->g_fVolume);
	cocos2d::AudioEngine::stop(p_nMenuIndex);
}
void ZYSoundManager::playMainMenuSound()
{
//	p_nMenuIndex = cocos2d::AudioEngine::play2d(User::GetInstance()->GetUserSound()->g_sMenu, true, User::GetInstance()->GetUserSound()->g_fVolume);
	cocos2d::AudioEngine::stop(p_nBattleIndex);
}
void ZYSoundManager::setVolume()
{

}
void ZYSoundManager::playSoundEffect(std::string sPath)
{
//	cocos2d::AudioEngine::play2d(sPath, false, User::GetInstance()->GetUserSound()->g_fVolume);
}
NS_ZY_END
