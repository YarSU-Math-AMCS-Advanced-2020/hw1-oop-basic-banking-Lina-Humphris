#pragma once
#include "DebitAccount.h"
#include "DataBase.h"


using namespace std;

DebitAccount::DebitAccount() {
	set_debit_id("");
	set_owner_id("");
	set_balance(0);
	set_limit(0);
	set_currency(0);
	set_has_card(false);
}

std::istream& operator>>(istream& in, DebitAccount& t) {
	cout << "Введите ваш ID: ";
	string s;
	cin >> s;
	DataBase* data_base = DataBase::getInstance();
	vector <BankAccount> base_account = data_base->get_base_account();
	bool is_accept = false;
	while (!is_accept) {
		for (int i = 0; i < base_account.size(); i++) {
			BankAccount curr = base_account[i];
			if (curr.get_account_id() == s) {
				is_accept = true;
			}
		}
		if (!is_accept) {
			cout << "Пользователя с таким ID не существует, попробуйте еще раз: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_owner_id(s);
	cout << "Введите лимит на снятие денег со счета или 0, если не хотите устанавливать лимит: ";
	double n;
	cin >> n;
	t.set_limit(int(n * 100) / 100);
	cout << "Введите 0, если хотите открыть счет в российских рублях. \nВведите 1, если хотите открыть счет в долларах США.";
	cout << "Введите 2, если хотите открыть счет в евро.";
	int temp;
	cin >> temp;
	t.set_currency(temp);
	string temp_id = data_base->get_max_id_debit();
	t.set_debit_id(temp_id);
	cout << "Регистрация прошла успешно, Вам присвоен id: " << temp_id << endl;
	data_base->add_debit(t);
	return in;
}

void DebitAccount::delete_debit_account() {

	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	int n;
	cout << "Введите 0 если хотите снять деньги со счета, иначе введите 0.";
	cin >> n;
	if (n == 1) {
		set_limit(0);
		cout << "Введите номер счета, на который будет совершен перевод: ";
		string s;
		cin >> s;
		bool is_accept = false;
		int transfer_currency;
		string transfer;
		while (!is_accept) {
			for (int i = 0; i < base_debit.size(); i++) {
				DebitAccount curr = base_debit[i];
				if (curr.get_debit_id() == s) {
					is_accept = true;
					transfer_currency = curr.get_currency();
					transfer = s;
				}
			}
			if (!is_accept) {
				cout << "Счета с таким номером не существует, попробуйте еще раз: ";
			}
			if (s == get_debit_id()) {
				cout << "Номер введенного счета совпадает с номером счета с которого будет производиться перевод, попробуйте еще раз: ";
				is_accept = false;
			}
			if (!is_accept) cin >> s;
			if (is_accept && get_currency() != transfer_currency) {
				cout << "Валюты счетов не совпадают, введите другой счет на который будет совершен перевод: ";
				cin >> s;
				is_accept = false;
			}
		}
		Transaction del_acc(get_debit_id(), transfer, get_balance(), get_currency());
	}
	vector <DebitAccount> new_base_debit;
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = base_debit[i];
		if (curr.get_debit_id() != get_debit_id()) {
			new_base_debit.push_back(curr);
		}
	}
	data_base->set_base_debit(new_base_debit);
}
