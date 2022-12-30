#pragma once

#define ZYUWU_VERSION 0x0

//All file includes here

//cocos2dx
#include "cocos2d.h"

//math
#include "math/ZYFraction.h"
#include "math/SmartAlgorithm.h"

//gacha
#include "gacha/ZYGacha.h"

//macros
#include "platform/ZYMacros.h"

//2d
#include "2d/ZYSprite.h"
#include "2d/ZYEffect.h"

//base
#include "base/ZYDirector.h"
#include "base/ZYConstant.h"

//database
#include "data-manager/ZYDatabase.h"
#include "data-manager/json/single_include/nlohmann/json.hpp"

//audio
#include "audio/ZYAudio.h"

NS_ZY_BEGIN

static const char* zyuwuVversion();

NS_ZY_END

