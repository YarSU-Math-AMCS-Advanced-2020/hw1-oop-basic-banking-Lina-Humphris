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
    CashIn(string card_account, double amount, bool status, int place, int place_number);
    friend std::istream& operator>>(istream& in, CashIn& t);

};