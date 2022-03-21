#pragma once
#include "CashOut.h"
#include "DataBase.h"

using namespace std;

CashOut::CashOut() {

}

std::istream& operator>>(istream& in, CashOut& t) {
	string s;
	string account_id;
	cout << "Введите номер карты с которой будет производиться снятие наличных: ";
	cin >> s;
	DataBase* data_base = DataBase::getInstance();
	vector <DebitCard> base_card = data_base->get_base_card();
	bool is_accept = false;
	double card_limit, debit_balance;
	while (!is_accept) {
		for (int i = 0; i < base_card.size(); i++) {
			DebitCard curr = base_card[i];
			if (curr.get_card_id() == s) {
				is_accept = true;
				account_id = curr.get_debit_id();
				card_limit = curr.get_limit();
			}
		}
		if (!is_accept) {
			cout << "Карты с таким номером не существует, попробуйте еще раз: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_card_account(s);
	cout << "Введите сумму которую хотите снять: ";
	double n;
	cin >> n;
	if (n > limit) {
		cout << "Сумма превышает лимит на снятие наличных в одни руки, операция будет отклонена.";
		t.set_status(0);

		vector <CashTransaction> base_cash = data_base->get_base_cash();
		data_base->add_cash_transaction(t);
		return in;
	}
	n = int(n * 100) / 100;
	t.set_amount(n);
	if (n > card_limit) {
		cout << "Сумма превышает лимит карты, операция будет отклонена.";
		t.set_status(0);

		vector <CashTransaction> base_cash = data_base->get_base_cash();
		data_base->add_cash_transaction(t);
		return in;
	}
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = base_debit[i];
		if (curr.get_debit_id() == account_id) {
			debit_balance = curr.get_balance();
			if (n > debit_balance) {
				cout << "Сумма превышает баланс счета, операция будет отклонена.";
				t.set_status(0);

				vector <CashTransaction> base_cash = data_base->get_base_cash();
				data_base->add_cash_transaction(t);
				return in;
			}
			base_debit[i].set_balance(base_debit[i].get_balance() - n);
		}
	}
	data_base->set_base_debit(base_debit);
	vector <CashTransaction> base_cash = data_base->get_base_cash();
	data_base->add_cash_transaction(t);
	return in;
}
