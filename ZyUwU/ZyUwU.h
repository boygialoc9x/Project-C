#pragma once

#define ZYUWU_VERSION 0x0

//All file includes here

//cocos2dx
#include "cocos2d.h"

//math
#include "ZyUwU/math/ZYFraction.h"
#include "ZyUwU/math/SmartAlgorithm.h"

//gacha
#include "ZyUwU/gacha/ZYGacha.h"

//platform
#include "ZyUwU/platform/ZYMacros.h"

//2d
#include "ZyUwU/2d/ZYSprite.h"
#include "ZyUwU/2d/ZYEffect.h"
#include "ZyUwU/2d/ZYLabel.h"

//base
#include "ZyUwU/base/ZYDirector.h"
#include "ZyUwU/base/ZYSupport.h"

//database
#include "ZyUwU/data-manager/ZYDatabase.h"
#include "data-manager/json/single_include/nlohmann/json.hpp"

//audio

NS_ZY_BEGIN

static const char* zyuwuVversion();

NS_ZY_END

