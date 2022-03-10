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
	void set_account_id(string account_id) { _account_id = account_id; };
	void set_addres(Addres addres) { _addres = addres; };
	void set_phone_number(string phone_number) { _phone_number = phone_number; };
};

