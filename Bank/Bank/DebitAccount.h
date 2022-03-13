#pragma once
#include <string>
#include "DataBase.h"

using namespace std;

class DebitAccount
{
private:
	string _debit_id;
	string _owner_id;
	string _card_id;
	double _balance;
	double _limit;
	int _currency;

public:
	DebitAccount(string debit_id, string owner_id, double balance, int currency, double limit = -1);

	void set_debit_id(string debit_id);
	void set_owner_id(string owner_id);
	void set_card_id(string card_id);
	void set_balance(double balance);
	void set_limit(double limit);
	void set_currency(int currency);
};

