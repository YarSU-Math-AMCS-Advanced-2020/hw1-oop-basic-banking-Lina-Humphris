#pragma once
#include <string>
#include "Date.h"

using namespace std;

class CashTransaction
{
protected:
	string _debit_account;
	double _amount;
	Date _date;
	bool _status;
	int _place; //Место снятия
	int _place_number;

public:
	CashTransaction();

	void set_debit_account(string debit_account) { _debit_account = debit_account; };
	void set_amount(double amount) { _amount = amount; };
	void set_date();
	void set_status(bool status) { _status = status; };
	void set_place(int place) { _place = place; };
	void set_place_number(int place_number) { _place_number = amount; };

};

