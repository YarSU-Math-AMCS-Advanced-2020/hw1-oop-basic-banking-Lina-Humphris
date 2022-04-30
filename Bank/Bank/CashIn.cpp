#pragma once
#include "CashIn.h"
#include "DataBase.h"

using namespace std;

CashIn::CashIn(){

}

CashIn::CashIn(string card_account, double amount, bool status, int place, int place_number) {
	set_card_account(card_account);
	set_amount(amount);
	set_date();
	set_status(status);
	set_place(place);
	set_place_number(place_number);

	DataBase* data_base = DataBase::getInstance();
	data_base->add_cash_transaction(this);
}

std::istream& operator>>(istream& in, CashIn& t) {
	string s;
	string account_id;
	cout << "Введите номер карты которую хотите пополнить: ";
	cin >> s;
	DataBase* data_base = DataBase::getInstance();
	vector <DebitCard*> base_card = data_base->get_base_card();
	bool is_accept = false;
	double card_limit, debit_balance;
	while (!is_accept) {
		for (int i = 0; i < base_card.size(); i++) {
			DebitCard curr = *base_card[i];
			if (curr.get_card_id() == s) {
				is_accept = true;
				account_id = curr.get_debit_id()->get_debit_id();
				card_limit = curr.get_limit();
			}
		}
		if (!is_accept) {
			cout << "Карты с таким номером не существует, попробуйте еще раз: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_card_account(s);
	cout << "Введите сумму которую хотите положить: ";
	double n;
	cin >> n;
	n = int(n * 100) / 100;
	t.set_amount(n);
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = *base_debit[i];
		if (curr.get_debit_id() == account_id) {
			debit_balance = curr.get_balance();
			base_debit[i]->set_balance(base_debit[i]->get_balance() + n);
		}
	}
	data_base->set_base_debit(base_debit);

	vector <CashTransaction*> base_cash = data_base->get_base_cash();
	t.set_status(true);
	data_base->add_cash_transaction(&t);
	
	return in;
}
