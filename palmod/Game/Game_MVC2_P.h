#pragma once
#include "Game_MVC2_D.h"

class CGame_MVC2_P :
    public CGame_MVC2_D
{
public:
    CGame_MVC2_P(void);
    ~CGame_MVC2_P(void);

    //Static functions
    static UINT16 uRuleCtr;

    static UINT16 GetRuleCtr() { return uRuleCtr; };
    static void ResetRuleCtr() { uRuleCtr = 0; };

    static sFileRule GetNextRule();
    static sFileRule GetRule(UINT16 nRuleId);
};
