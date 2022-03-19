#pragma once
#include "CashIn.h"
#include "DataBase.h"

using namespace std;

CashIn::CashIn() {

}

std::istream& operator>>(istream& in, CashIn& t) {
	string s;
	string account_id;
	cout << "������� ����� ����� ������� ������ ���������: ";
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
			cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_card_account(s);
	cout << "������� ����� ������� ������ ��������: ";
	double n;
	cin >> n;
	n = int(n * 100) / 100;
	t.set_amount(n);
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = base_debit[i];
		if (curr.get_debit_id() == account_id) {
			debit_balance = curr.get_balance();
			base_debit[i].set_balance(base_debit[i].get_balance() + n);
		}
	}
	data_base->set_base_debit(base_debit);

	return in;
}