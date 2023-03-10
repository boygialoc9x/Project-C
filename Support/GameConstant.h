#pragma once

#include "../ZyUwU/ZyUwU.h"

USING_NS_ALL;

class LayerConstant
{
public:
    LayerConstant(std::string sLayerId, bool bIsVisible)
    {
        g_sLayerId = sLayerId;
        g_bIsVisible = bIsVisible;
    }
    std::string g_sLayerId;
    bool g_bIsVisible;
};

static LayerConstant metaLayer = LayerConstant("meta", false);
static LayerConstant backgroundLayer = LayerConstant("background", true);

static std::string globalFont("fonts/arial.ttf");
