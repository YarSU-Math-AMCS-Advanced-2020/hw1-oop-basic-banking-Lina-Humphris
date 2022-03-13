#pragma once
#include <string>
#include "Date.h"
#include "DataBase.h"

using namespace std;

class DebitCard
{
private:
	string _card_id;
	string _debit_id; //id счета
	int _pay_system;
	double _limit;
	Date _validity_period;
public:
	DebitCard(string card_id, string debit_id, int pay_system, double limit, Date validity_period);

	void set_card_id(string card_id);
	void set_debit_id(string debit_id);
	void set_pay_system(int pay_system);
	void set_limit(double limit);
	void set_validity_period(Date validity_period);
};

