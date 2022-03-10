#pragma once
#include <string>
#include "Addres.h"

using namespace std;

class BankAccount
{
protected:
	string _account_id;
	Addres _addres;
	string _phone_number;

public:
	BankAccount(string account_id, Addres addres, string phone_number);

	void set_account_id(string account_id);
	void set_addres(Addres addres);
	void set_phone_number(string phone_number);
};

