#pragma once
#include "DebitCard.h"
#include "DataBase.h"

DebitCard::DebitCard() {
	set_card_id("");
	set_debit_id("");
	set_pay_system(0);
	set_limit(0);
	Date temp_date;
	set_validity_period(temp_date);
}

int DebitCard::get_debit_currency() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = base_debit[i];
		if (curr.get_debit_id() == get_debit_id()) {
			return curr.get_currency();
		}
	}
}


std::istream& operator>>(istream& in, DebitCard& t) {
	cout << "������� ����� �����, � �������� ������ ��������� �����: ";
	string s;
	cin >> s;
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	bool is_accept = false;

	while (!is_accept) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = base_debit[i];
			if (curr.get_debit_id() == s) {
				is_accept = true;
				curr.set_has_card(true);
			}
		}
		if (!is_accept) {
			cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_debit_id(s);
	cout << "�������� ��������� �������. \n������� 0, ���� ������ ������� Lisa, 1 - MasterBart, 2 - HoMiR: ";
	int n;
	cin >> n;
	t.set_pay_system(n);
	cout << "������� 0, ���� �� ������ ������������� ����� �� �����, -1, " <<
		"���� ������ ���������� ����� ����� ��,��� �� �����, ����� ������� �����: ";
	double limit;
	cin >> limit;
	limit = int(limit * 100) / 100;
	if (limit == -1) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = base_debit[i];
			if (curr.get_debit_id() == s) {
				t.set_limit(curr.get_limit());
			}
		}
	}
	else t.set_limit(limit);
	Date temp;
	temp.set_year(temp.get_year() + 4);
	t.set_validity_period(temp);
	string temp_id = data_base->get_max_id_card();
	t.set_card_id(temp_id);
	cout << "����������� ������ �������, ����� ����� �����: " << temp_id << endl;
	data_base->add_card(t);
	return in;
}

void DebitCard::rebinding_card() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitCard> base_card = data_base->get_base_card();
	vector <DebitAccount> base_account = data_base->get_base_debit();
	string card, account;
	int num_of_debit_account, num_of_debit_card;
	cout << "������� ����� �����, ������� ������ �������������: ";
	cin >> card;
	bool is_accept = false;
	while (!is_accept) {
		for (int i = 0; i < base_card.size(); i++) {
			DebitCard curr = base_card[i];
			if (curr.get_card_id() == card) {
				is_accept = true;
				num_of_debit_card = i;
			}
		}
		if (!is_accept) {
			cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
		}
		if (!is_accept) cin >> card;
	}
	cout << "������� ����� �����, � �������� ������ ������������� �����: ";
	cin >> account;
	is_accept = false;
	while (!is_accept) {
		for (int i = 0; i < base_account.size(); i++) {
			DebitAccount curr = base_account[i];
			if (curr.get_debit_id() == account) {
				is_accept = true;
				num_of_debit_account = i;
			}
		}
		if (!is_accept) {
			cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
		}
		if (is_accept) {
			if (base_account[num_of_debit_account].get_has_card()) {
				cout << "� ������� ����� ��� ��������� �����, ������� ������ ����: ";
				is_accept = false;
			}
		}
		if (!is_accept) cin >> card;
	}
	base_card[num_of_debit_card].set_debit_id(account);
	data_base->set_base_card(base_card);
}
