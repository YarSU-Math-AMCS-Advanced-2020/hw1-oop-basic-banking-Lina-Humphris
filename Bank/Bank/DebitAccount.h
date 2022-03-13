#pragma once
#include <string>

using namespace std;

class DebitAccount
{
private:
	string _debit_id;
	string _owner_id;
	double _balance;
	double _limit;
	int _currency;

public:
	DebitAccount();

	void set_debit_id(string debit_id) { _debit_id = debit_id; };
	void set_owner_id(string owner_id) { _owner_id = owner_id; };
	void set_balance(double balance) { _balance = balance; };
	void set_limit(double limit) { _limit = limit; };
	void set_currency(int currency) { _currency = currency; };

	friend std::istream& operator>>(istream& in, DebitAccount& t);

};



