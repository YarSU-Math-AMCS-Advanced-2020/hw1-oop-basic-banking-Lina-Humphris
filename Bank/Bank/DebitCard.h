#pragma once
#include <string>
#include "Date.h"

using namespace std;

class DebitCard
{
private:
	string _card_id;
	string _debit_id; //id �����
	int _pay_system; // 0 - Lisa, 1 - MasterBart, 2 - HoMiR
	double _limit;
	Date _validity_period;
public:
	DebitCard();

	void set_card_id(string card_id) { _card_id = card_id; };
	void set_debit_id(string debit_id) { _debit_id = debit_id; };
	void set_pay_system(int pay_system) { _pay_system = pay_system; };
	void set_limit(double limit) { _limit = limit; };
	void set_validity_period(Date validity_period) { _validity_period = validity_period; };

	string get_card_id() { return _card_id; };
	string get_debit_id() { return _debit_id; };
	int get_pay_system() { return _pay_system; };
	double get_limit() { return _limit; };
	Date get_validity_period() { return _validity_period; }
	int get_debit_currency();
	void rebinding_card();
	void delete_card();
	void change_limit();

	friend std::istream& operator>>(istream& in, DebitCard& t);
	friend std::ostream& operator<<(ostream& out, DebitCard& t);
};
