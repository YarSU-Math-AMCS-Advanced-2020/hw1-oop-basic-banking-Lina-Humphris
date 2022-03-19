#pragma once
#include <iostream>
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
	bool _has_card;

public:
	DebitAccount();

	void set_debit_id(string debit_id) { _debit_id = debit_id; };
	void set_owner_id(string owner_id) { _owner_id = owner_id; };
	void set_balance(double balance) { _balance = balance; };
	void set_limit(double limit) { _limit = limit; };
	void set_currency(int currency) { _currency = currency; };
	void set_has_card(bool has_card) { _has_card = has_card; };

	double get_limit() { return _limit; };
	string get_debit_id() { return _debit_id; }
	double get_balance() { return _balance; };
	int get_currency() { return _currency; };
	bool get_has_card() { return _has_card; }

	friend std::istream& operator>>(istream& in, DebitAccount& t);

};



