#pragma once
#include <iostream>
#include "CashTransaction.h"
#include "DebitAccount.h"

using namespace std;

const int limit = 20000;

class CashOut :
    public CashTransaction
{
protected:
    int _limit = limit;
public:

    CashOut();
    CashOut(string card_account, double amount, bool status, int place, int place_number);
    friend std::istream& operator>>(istream& in, CashOut& t);

};



