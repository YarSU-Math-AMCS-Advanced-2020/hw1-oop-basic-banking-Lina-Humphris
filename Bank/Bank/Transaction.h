#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Transaction
{
private:
	string _debit_account;
	string _transfer_account;
	double _amount;
	int _currency_of_operation;
	Date _date;
	int _status;
public:
	Transaction(string debit_account, string transfer_account, double amount, int currancy_of_operation, Date date, int status);

	void set_debit_account(string debit_account);
	void set_transfer_account(string transfer_account);
	void set_amount(double amount);
	void set_currency_of_operation(int currency_of_operation);
	void set_date();
	void set_status(int status);
};

