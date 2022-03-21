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
Transaction::Transaction(string debit_account, string transfer_account, double amount, int currency_of_operation) {
	set_debit_account(debit_account);
	set_transfer_account(transfer_account);
	set_amount(amount);
	set_currency_of_operation(currency_of_operation);
	Date date_temp;
	set_date(date_temp);
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	vector <DebitCard> base_card = data_base->get_base_card();
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = base_debit[i];
		if (curr.get_debit_id() == get_debit_account()) {
			if (curr.get_limit() <= amount || curr.get_limit() == 0) {
				if (curr.get_balance() >= amount) {
					curr.set_balance(curr.get_balance() - amount);
				}
				else {
					set_status(0);//возможно добавление выброса исключения с последующим отловом
					return;
				}
			}
			else {
				set_status(0);
				return;
			}
		}
	}
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = base_debit[i];
		if (curr.get_debit_id() == get_transfer_account()) {
			curr.set_balance(curr.get_balance() + amount);
		}
	}
	data_base->set_base_debit(base_debit);
	set_status(1);
}

std::istream& operator>>(istream& in, Transaction& t) {
	Date date_temp;
	t.set_date(date_temp);
	bool is_accept = false;
	int debit_currency = -1;
	int transfer_currency = -1;
	cout << "Выберите 0 если хотите проделать операцию с вкладами, 1 если с картами";
	int n;
	cin >> n;
	string s;
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount> base_debit = data_base->get_base_debit();
	vector <DebitCard> base_card = data_base->get_base_card();
	if (n == 1) {
		cout << "Введите номер вашей карты:";
		cin >> s;
		string debit;
		while (!is_accept) {
			for (int i = 0; i < base_card.size(); i++) {
				DebitCard curr = base_card[i];
				if (curr.get_card_id() == s) {
					is_accept = true;
					debit = curr.get_debit_id();
					debit_currency = curr.get_debit_currency();
				}
			}
			if (!is_accept) {
				cout << "Карты с таким номером не существует, попробуйте еще раз: ";
			}
			if (!is_accept) cin >> s;
		}
		t.set_debit_account(debit);
		cout << "Введите номер карты, на который будет совершен перевод: ";
		cin >> s;
		is_accept = false;
		while (!is_accept) {
			for (int i = 0; i < base_card.size(); i++) {
				DebitCard curr = base_card[i];
				if (curr.get_debit_id() == s) {
					is_accept = true;
					debit = curr.get_debit_id();
					transfer_currency = curr.get_debit_currency();
				}
			}
			if (!is_accept) {
				cout << "Карты с таким номером не существует, попробуйте еще раз: ";
			}
			if (debit == t.get_debit_account()) {
				cout << "Номер введенной карты совпадает с номером карты с которой будет производиться перевод, попробуйте еще раз: ";
				is_accept = false;
			}
			if (!is_accept) cin >> s;
		}
		t.set_transfer_account(debit);
	}
	else {
		cout << "Введите номер вашего счета: ";
		cin >> s;
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
		cout << "Введите номер счета, на который будет совершен перевод: ";
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
	}
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
		data_base->set_base_debit(base_debit);
	}
	t.set_amount(temp_amount);
	t.set_currency_of_operation(debit_currency);
	if (is_accept) t.set_status(1);
	vector <Transaction> base_transaction = data_base->get_base_transaction();
	data_base->add_transaction(t);
	return in;
}
