#pragma once
#include "DebitCard.h"
#include "DataBase.h"

DebitCard::DebitCard() {
	set_card_id("");
	set_pay_system(0);
	set_limit(0);
	Date temp_date;
	set_validity_period(temp_date);
}

DebitCard::DebitCard(DebitAccount* _debit_id, int _pay_system, double _limit) {
	_debit_id->set_has_card(true);
	DataBase* data_base = DataBase::getInstance();
	set_debit_id(_debit_id);
	set_pay_system(_pay_system);
	set_limit(_limit);
	Date temp;
	temp.set_year(temp.get_year() + 4);
	set_validity_period(temp);
	string temp_id = data_base->get_max_id_card();
	set_card_id(temp_id);
	data_base->add_card(this);
}

int DebitCard::get_debit_currency() {
	return get_debit_id()->get_currency();
}

void DebitCard::change_limit(int new_limit) {
	set_limit(new_limit);
}


void DebitCard::change_limit() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	vector <DebitCard*> base_card = data_base->get_base_card();
	double limit;
	int n;
	cout << "Введите 0, если не хотите устанавливать лимит на карту, -1, " <<
		"если хотите установить лимит такой же,как на счете, иначе введите лимит: ";
	cin >> limit;
	limit = int(limit * 100) / 100;
	if (limit == -1) change_limit(get_debit_id()->get_limit());
	else change_limit(limit);
}


std::istream& operator>>(istream& in, DebitCard& t) {
	cout << "Введите номер счета, к которому хотите привязать карту: ";
	string s;
	cin >> s;
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	bool is_accept = false;
	DebitAccount* temp_debit = NULL;
	while (!is_accept) {
		bool has_card;
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = *base_debit[i];
			if (curr.get_debit_id() == s) {
				is_accept = true;
				has_card = curr.get_has_card();
				base_debit[i]->set_has_card(true);
				temp_debit = &curr;
			}
		}
		if (!is_accept) {
			cout << "Счета с таким номером не существует, попробуйте еще раз: ";
		}
		if (is_accept && has_card) {
			cout << "К данному счету уже привязана карта, попробуйте еще раз: ";
			is_accept = false;
		}
		if (!is_accept) cin >> s;

	}
	t.set_debit_id(temp_debit);
	cout << "Выберите платежную систему. \nВведите 0, если хотите выбрать Lisa, 1 - MasterBart, 2 - HoMiR: ";
	int n;
	cin >> n;
	t.set_pay_system(n);
	cout << "Введите 0, если не хотите устанавливать лимит на карту, -1, " <<
		"если хотите установить лимит такой же,как на счете, иначе введите лимит: ";
	double limit;
	cin >> limit;
	limit = int(limit * 100) / 100;
	if (limit == -1) t.set_limit(t.get_debit_id()->get_limit());
	else t.set_limit(limit);
	Date temp;
	temp.set_year(temp.get_year() + 4);
	t.set_validity_period(temp);
	string temp_id = data_base->get_max_id_card();
	t.set_card_id(temp_id);
	cout << "Регистрация прошла успешно, номер вашей карты: " << temp_id << endl;
	data_base->add_card(&t);
	return in;
}

std::ostream& operator<<(ostream& out, DebitCard& t) {
	cout << "ID карты: " << t.get_card_id() << endl;
	cout << "ID счета, к которому привязана карты: " << t.get_debit_id() << endl;
	cout << "Платежная система: ";
	int pay = t.get_pay_system();
	if (pay == 0) cout << "Lisa" << endl;
	else if (pay == 1) cout << "MasterBart" << endl;
	else cout << "HoMiR" << endl;
	cout << "Лимит: " << t.get_limit() << endl;
	Date temp = t.get_validity_period();
	cout << "Дата окончания действия карты: " << temp << endl;
	return out;
}

void DebitCard::rebinding_card() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitCard*> base_card = data_base->get_base_card();
	vector <DebitAccount*> base_account = data_base->get_base_debit();
	string card, account;
	int num_of_debit_account, num_of_debit_card;
	cout << "Введите номер карты, которую хотите перепривязать: ";
	cin >> card;
	bool is_accept = false;
	while (!is_accept) {
		for (int i = 0; i < base_card.size(); i++) {
			DebitCard curr = *base_card[i];
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
	DebitAccount* temp_debit = NULL;
	while (!is_accept) {
		for (int i = 0; i < base_account.size(); i++) {
			DebitAccount curr = *base_account[i];
			if (curr.get_debit_id() == account) {
				is_accept = true;
				num_of_debit_account = i;
				temp_debit = &curr;
			}
		}
		if (!is_accept) {
			cout << "Счета с таким номером не существует, попробуйте еще раз: ";
		}
		if (is_accept) {
			if (base_account[num_of_debit_account]->get_has_card()) {
				cout << "К данному счету уже привязана карта, введите другой счет: ";
				is_accept = false;
			}
		}
		if (!is_accept) cin >> card;
	}
	base_card[num_of_debit_card]->set_debit_id(temp_debit);
	data_base->set_base_card(base_card);
}

void DebitCard::delete_card() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitCard*> base_card = data_base->get_base_card();
	vector <DebitAccount*> base_account = data_base->get_base_debit();
	vector <DebitCard*> new_base_card;
	for (int i = 0; i < base_card.size(); i++) {
		DebitCard curr = *base_card[i];
		if (curr.get_card_id() != get_card_id()) {
			new_base_card.push_back(base_card[i]);
		}
	}
	get_debit_id()->set_has_card(false);
	data_base->set_base_card(new_base_card);
}
