#pragma once

#include "../Arena.h"
#include "GameObject/Economy/Economy.h"

USING_NS_ALL;

BEGIN_CREATE_REFCLASS(Property, Arena)

public:
    virtual void update(float dt);
    virtual void onLand();

protected:
    //Player* m_pOwner;
    Economy *m_pPrice, *m_pTax, *m_pValue;
    float m_fSellMultiple, m_fIncomeMultiple;

END_CREATE_REFCLASS