#pragma once

#include "../Arena.h"

USING_NS_ALL;

BEGIN_CREATE_REFCLASS(SpecialArena, Arena)

public:
    virtual void update(float dt);
    virtual void onLand();

END_CREATE_REFCLASS