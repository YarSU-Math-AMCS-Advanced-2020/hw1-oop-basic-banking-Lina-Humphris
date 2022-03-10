#pragma once
#include "BankAccount.h"
#include "Date.h"
#include <string>

using namespace std;

class LegalEnitityBankAccount :
    public BankAccount
{
private:
    string _name;
    Date _establishing_date;
    string _TIN;
    Addres _legal_addres;
public:
    LegalEnitityBankAccount(string name, Date establishing_date, string TIN, Addres legal_addres);

    void set_name(string name);
    void set_establishing_date(Date establishing_date);
    void set_TIN(string TIN);
    void set_legal_addres(Addres legal_addres);
};

