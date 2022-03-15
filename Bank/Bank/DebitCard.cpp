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
