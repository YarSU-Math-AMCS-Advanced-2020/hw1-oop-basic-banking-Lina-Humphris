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


