#pragma once
#include "CashTransaction.h"

using namespace std;

class CashOut :
    public CashTransaction
{
    int limit;
};

