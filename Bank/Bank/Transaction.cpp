#include "Transaction.h"
#include "DataBase.h"

Transaction::Transaction() {
	set_debit_account("");
	set_transfer_account("");
	set_amount(0);
	set_currency_of_operation(0);
	Date date_temp;
	set_date(date_temp); 
	set_status(0);
}

std::istream& operator>>(istream& in, Transaction& t) {
	Date date_temp;
	int debit_currency = -1;
	int transfer_currency = -1;
	t.set_date(date_temp);
	string s;
	cout << "Введите номер вашего счета: ";
	cin >> s;
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	bool is_accept = false;

	while (!is_accept) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = base_debit[i];
			if (curr.get_debit_id() == s) {
				is_accept = true;
				debit_currency = curr.get_currency();
			}
		}
		if (!is_accept) {
			cout << "Счета с таким номером не существует, попробуйте еще раз: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_debit_account(s);
	cout << "Введите счет, на который будет совершен перевод: ";
	cin >> s;
	is_accept = false;

	while (!is_accept) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = base_debit[i];
			if (curr.get_debit_id() == s) {
				is_accept = true;
				transfer_currency = curr.get_currency();
			}
		}
		if (!is_accept) {
			cout << "Счета с таким номером не существует, попробуйте еще раз: ";
		}
		if (s == t.get_debit_account()) {
			cout << "Номер введенного счета совпадает с номером счета с которого будет производиться перевод, попробуйте еще раз: ";
			is_accept = false;
		}
		if (!is_accept) cin >> s;
	}
	t.set_transfer_account(s);
	double temp_amount;
	cout << "Введите сумму перевода: ";
	cin >> temp_amount;
	t.set_amount(temp_amount);
	is_accept = true;
	if (debit_currency != transfer_currency) {
		cout << "Валюты счетов не совпадают, транзакция отклонена.";
		is_accept = false;
	}
	if (is_accept) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = base_debit[i];
			if (curr.get_debit_id() == t.get_debit_account()) {
				if (curr.get_limit() <= temp_amount || curr.get_limit() == 0) {
					if (curr.get_balance() >= temp_amount) {
						curr.set_balance(curr.get_balance() - temp_amount);
					}
					else {
						cout << "На счете недостаточно средств, транзакция отменена.";
						t.set_status(0);
						is_accept = false;
					}
				}
				else {
					cout << "Сумма превышает лимит, транзакция отменена.";
					t.set_status(0);
					is_accept = false;
				}
			}
		}
	}
	if (is_accept) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = base_debit[i];
			if (curr.get_debit_id() == t.get_transfer_account()) {
				curr.set_balance(curr.get_balance() + temp_amount);
			}
		}
	}
	t.set_amount(temp_amount);
	if (is_accept) t.set_status(1);
	return in;
}