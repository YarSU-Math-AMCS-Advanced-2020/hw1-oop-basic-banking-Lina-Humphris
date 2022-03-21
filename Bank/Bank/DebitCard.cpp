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
	cout << "Введите номер счета, к которому хотите привязать карту: ";
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
			cout << "Счета с таким номером не существует, попробуйте еще раз: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_debit_id(s);
	cout << "Выберите платежную систему. \nВведите 0, если хотите выбрать Lisa, 1 - MasterBart, 2 - HoMiR: ";
	int n;
	cin >> n;
	t.set_pay_system(n);
	cout << "Введите 0, если не хотите устанавливать лимит на карту, -1, " <<
		"если хотите установить лимит такой же,как на счете, иначе введите лимит: ";
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
	cout << "Регистрация прошла успешно, номер вашей карты: " << temp_id << endl;
	data_base->add_card(t);
	return in;
}

void DebitCard::rebinding_card() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitCard> base_card = data_base->get_base_card();
	vector <DebitAccount> base_account = data_base->get_base_debit();
	string card, account;
	int num_of_debit_account, num_of_debit_card;
	cout << "Введите номер карты, которую хотите перепривязать: ";
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
			cout << "Карты с таким номером не существует, попробуйте еще раз: ";
		}
		if (!is_accept) cin >> card;
	}
	cout << "Введите номер счета, к которому хотите перепривязать карту: ";
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
			cout << "Счета с таким номером не существует, попробуйте еще раз: ";
		}
		if (is_accept) {
			if (base_account[num_of_debit_account].get_has_card()) {
				cout << "К данному счету уже привязана карта, введите другой счет: ";
				is_accept = false;
			}
		}
		if (!is_accept) cin >> card;
	}
	base_card[num_of_debit_card].set_debit_id(account);
	data_base->set_base_card(base_card);
}

void DebitCard::delete_card() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitCard> base_card = data_base->get_base_card();
	vector <DebitCard> new_base_card;
	for (int i = 0; i < base_card.size(); i++) {
		DebitCard curr = base_card[i];
		if (curr.get_card_id() != get_card_id()) {
			new_base_card.push_back(curr);
		}
	}
	data_base->set_base_card(new_base_card);
}
