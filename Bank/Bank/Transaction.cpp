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

Transaction Transaction::operator=(Transaction t) {
	set_debit_account(t.get_debit_account());
	set_transfer_account(t.get_transfer_account());
	set_amount(t.get_amount());
	set_currency_of_operation(t.get_currency_of_operation());
	set_date(t.get_date());
	set_status(t.get_status());
	return *this;
}

Transaction Transaction::do_transaction(DebitAccount* from, DebitAccount* in, int amount) {
	set_debit_account(from->get_debit_id());
	set_transfer_account(in->get_debit_id());
	set_amount(amount);
	set_currency_of_operation(from->get_currency());
	Date date_temp;
	set_date(date_temp);
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	vector <DebitCard*> base_card = data_base->get_base_card();
	if (from->get_balance() >= amount && (from->get_limit() >= amount || from->get_limit() == 0)) from->set_balance(from->get_balance() - amount);
	else {
		set_status(0);
		return *this;
	}
	in->set_balance(in->get_balance() + amount);
	set_status(1);
	return *this;

}

Transaction::Transaction(DebitAccount* from, DebitAccount* in, int amount) {
	Transaction t = do_transaction(from, in, amount);
	DataBase* data_base = DataBase::getInstance();
	set_debit_account(t.get_debit_account());
	set_transfer_account(t.get_transfer_account());
	set_amount(t.get_amount());
	set_currency_of_operation(t.get_currency_of_operation());
	set_date(t.get_date());
	set_status(t.get_status());
	data_base->add_transaction(this);
}
Transaction::Transaction(DebitCard* from, DebitAccount* in, int amount) {
	Transaction t = do_transaction(from->get_debit_id(), in, amount);
	DataBase* data_base = DataBase::getInstance();
	set_debit_account(t.get_debit_account());
	set_transfer_account(t.get_transfer_account());
	set_amount(t.get_amount());
	set_currency_of_operation(t.get_currency_of_operation());
	set_date(t.get_date());
	set_status(t.get_status());

	data_base->add_transaction(this);

}
Transaction::Transaction(DebitAccount* from, DebitCard* in, int amount) {
	Transaction t = do_transaction(from, in->get_debit_id(), amount);
	DataBase* data_base = DataBase::getInstance();
	set_debit_account(t.get_debit_account());
	set_transfer_account(t.get_transfer_account());
	set_amount(t.get_amount());
	set_currency_of_operation(t.get_currency_of_operation());
	set_date(t.get_date());
	set_status(t.get_status());

	data_base->add_transaction(this);
}
Transaction::Transaction(DebitCard* from, DebitCard* in, int amount){
	Transaction t = do_transaction(from->get_debit_id(), in->get_debit_id(), amount);
	DataBase* data_base = DataBase::getInstance();
	set_debit_account(t.get_debit_account());
	set_transfer_account(t.get_transfer_account());
	set_amount(t.get_amount());
	set_currency_of_operation(t.get_currency_of_operation());
	set_date(t.get_date());
	set_status(t.get_status());

	data_base->add_transaction(this);
}

Transaction::Transaction(string debit_account, string transfer_account, double amount, int currency_of_operation) {
	set_debit_account(debit_account);
	set_transfer_account(transfer_account);
	set_amount(amount);
	set_currency_of_operation(currency_of_operation);
	Date date_temp;
	set_date(date_temp);
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	vector <DebitCard*> base_card = data_base->get_base_card();
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = *base_debit[i];
		if (curr.get_debit_id() == get_debit_account()) {
			if (curr.get_limit() <= amount || curr.get_limit() == 0) {
				if (curr.get_balance() >= amount) {
					curr.set_balance(curr.get_balance() - amount);
				}
				else {
					set_status(0);//�������� ���������� ������� ���������� � ����������� �������
					data_base->add_transaction(this);

					return;
				}
			}
			else {
				set_status(0);
				data_base->add_transaction(this);

				return;
			}
		}
	}
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = *base_debit[i];
		if (curr.get_debit_id() == get_transfer_account()) {
			curr.set_balance(curr.get_balance() + amount);
		}
	}
	data_base->set_base_debit(base_debit);
	set_status(1);
	data_base->add_transaction(this);
}

std::istream& operator>>(istream& in, Transaction& t) {
	Date date_temp;
	t.set_date(date_temp);
	bool is_accept = false;
	int debit_currency = -1;
	int transfer_currency = -1;
	cout << "�������� 0 ���� ������ ��������� �������� � ��������, 1 ���� � �������";
	int n;
	cin >> n;
	string s;
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	vector <DebitCard*> base_card = data_base->get_base_card();
	if (n == 1) {
		cout << "������� ����� ����� �����:";
		cin >> s;
		DebitAccount* debit = NULL;
		while (!is_accept) {
			for (int i = 0; i < base_card.size(); i++) {
				DebitCard curr = *base_card[i];
				if (curr.get_card_id() == s) {
					is_accept = true;
					debit = curr.get_debit_id();
					debit_currency = curr.get_debit_currency();
				}
			}
			if (!is_accept) {
				cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
			}
			if (!is_accept) cin >> s;
		}
		t.set_debit_account(debit->get_debit_id());
		cout << "������� ����� �����, �� ������� ����� �������� �������: ";
		cin >> s;
		is_accept = false;
		while (!is_accept) {
			for (int i = 0; i < base_card.size(); i++) {
				DebitCard curr = *base_card[i];
				if (curr.get_debit_id()->get_debit_id() == s) {
					is_accept = true;
					debit = curr.get_debit_id();
					transfer_currency = curr.get_debit_currency();
				}
			}
			if (!is_accept) {
				cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
			}
			if (debit->get_debit_id() == t.get_debit_account()) {
				cout << "����� ��������� ����� ��������� � ������� ����� � ������� ����� ������������� �������, ���������� ��� ���: ";
				is_accept = false;
			}
			if (!is_accept) cin >> s;
		}
		t.set_transfer_account(debit->get_debit_id());
	}
	else {
		cout << "������� ����� ������ �����: ";
		cin >> s;
		while (!is_accept) {
			for (int i = 0; i < base_debit.size(); i++) {
				DebitAccount curr = *base_debit[i];
				if (curr.get_debit_id() == s) {
					is_accept = true;
					debit_currency = curr.get_currency();
				}
			}
			if (!is_accept) {
				cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
			}
			if (!is_accept) cin >> s;
		}
		t.set_debit_account(s);
		cout << "������� ����� �����, �� ������� ����� �������� �������: ";
		cin >> s;
		is_accept = false;

		while (!is_accept) {
			for (int i = 0; i < base_debit.size(); i++) {
				DebitAccount curr = *base_debit[i];
				if (curr.get_debit_id() == s) {
					is_accept = true;
					transfer_currency = curr.get_currency();
				}
			}
			if (!is_accept) {
				cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
			}
			if (s == t.get_debit_account()) {
				cout << "����� ���������� ����� ��������� � ������� ����� � �������� ����� ������������� �������, ���������� ��� ���: ";
				is_accept = false;
			}
			if (!is_accept) cin >> s;
		}
		t.set_transfer_account(s);
	}
	double temp_amount;
	cout << "������� ����� ��������: ";
	cin >> temp_amount;
	t.set_amount(temp_amount);
	is_accept = true;
	if (debit_currency != transfer_currency) {
		cout << "������ ������ �� ���������, ���������� ���������.";
		is_accept = false;
	}
	if (is_accept) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = *base_debit[i];
			if (curr.get_debit_id() == t.get_debit_account()) {
				if (curr.get_limit() >= temp_amount || curr.get_limit() == 0) {
					if (curr.get_balance() >= temp_amount) {
						curr.set_balance(curr.get_balance() - temp_amount);
					}
					else {
						cout << "�� ����� ������������ �������, ���������� ��������.";
						t.set_status(0);
						is_accept = false;
					}
				}
				else {
					cout << "����� ��������� �����, ���������� ��������.";
					t.set_status(0);
					is_accept = false;
				}
			}
		}
	}
	if (is_accept) {
		for (int i = 0; i < base_debit.size(); i++) {
			DebitAccount curr = *base_debit[i];
			if (curr.get_debit_id() == t.get_transfer_account()) {
				curr.set_balance(curr.get_balance() + temp_amount);
			}
		}
		data_base->set_base_debit(base_debit);
	}
	t.set_amount(temp_amount);
	t.set_currency_of_operation(debit_currency);
	if (is_accept) t.set_status(1);
	vector <Transaction*> base_transaction = data_base->get_base_transaction();
	data_base->add_transaction(&t);
	return in;
}

std::ostream& operator<<(ostream& out, Transaction& t) {
	cout << "ID, � �������� ���������� �������: " << t.get_debit_account() << endl;
	cout << "ID, ���� ����� �������� �������: " << t.get_transfer_account() << endl;
	cout << "����� ��������: " << t.get_amount() << endl;
	cout << "������: ";
	int pay = t.get_currency_of_operation();
	if (pay == 0) cout << "�����" << endl;
	else if (pay == 1) cout << "�������" << endl;
	else cout << "����" << endl;
	Date temp = t.get_date();
	cout << "���� ���������� ����������: " << temp;
	int res = t.get_status();
	if (res) cout << "���������� ������ �������" << endl;
	else cout << "���������� ��������" << endl;
	return out;
}

