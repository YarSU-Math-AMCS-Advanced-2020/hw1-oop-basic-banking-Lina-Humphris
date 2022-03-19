#pragma once
#include <iostream>
#include "CashTransaction.h"
#include "DebitAccount.h"

using namespace std;

class CashIn :
    public CashTransaction
{
public:
    CashIn();
    friend std::istream& operator>>(istream& in, CashIn& t);

};