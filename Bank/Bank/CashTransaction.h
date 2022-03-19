#pragma once
#include <string>
#include "Date.h"

using namespace std;

class CashTransaction
{
protected:
	string _card_account;
	double _amount;
	Date _date;
	bool _status;
	int _place; //Место снятия
	int _place_number;

public:
	CashTransaction();

	void set_card_account(string card_account) { _card_account = card_account; };
	void set_amount(double amount) { _amount = amount; };
	void set_date();
	void set_status(bool status) { _status = status; };
	void set_place(int place) { _place = place; };
	void set_place_number(int place_number) { _place_number = place_number; };

};