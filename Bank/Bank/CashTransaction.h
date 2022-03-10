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
	CashTransaction(string debit_account, double amount, Date date, bool status, int place, int place_number);

	void set_debit_account(string debit_account);
	void set_amount(double amount);
	void set_date();
	void set_status(bool status);
	void set_place(int place);
	void set_place_number(int place_number);

};

