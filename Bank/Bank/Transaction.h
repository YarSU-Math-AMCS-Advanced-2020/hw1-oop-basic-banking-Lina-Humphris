#pragma once
#include <string>
#include "Date.h"
#include "DebitCard.h"

using namespace std;

class Transaction
{
private:
	string _debit_account;
	string _transfer_account;
	double _amount;
	int _currency_of_operation;
	Date _date;
	int _status;// 0 если отклонено, иначе 1
public:
	Transaction();
	Transaction(DebitAccount* from, DebitAccount* in, int amount);
	Transaction(DebitAccount* from, DebitCard* in, int amount);
	Transaction(DebitCard* from, DebitAccount* in, int amount);
	Transaction(DebitCard* from, DebitCard* in, int amount);
	Transaction(string debit_account, string transfer_account, double amount, int currency_of_operation);
	void set_debit_account(string debit_account) { _debit_account = debit_account; };
	void set_transfer_account(string transfer_account) { _transfer_account = transfer_account; };
	void set_amount(double amount) { _amount = amount; };
	void set_currency_of_operation(int currency_of_operation) { _currency_of_operation = currency_of_operation; };
	void set_date(Date date) { _date = date; };
	void set_status(int status) { _status = status; };
	Transaction do_transaction(DebitAccount* from, DebitAccount* in, int amount);

	Transaction operator=(Transaction t);

	string get_debit_account() { return _debit_account; };
	string get_transfer_account() { return _transfer_account; };
	double get_amount() { return _amount; };
	int get_currency_of_operation() { return _currency_of_operation; };
	Date get_date() { return _date; };
	int get_status() { return _status; };

	friend std::istream& operator>>(istream& in, Transaction& t);
	friend std::ostream& operator<<(ostream& out,Transaction& t);
};
