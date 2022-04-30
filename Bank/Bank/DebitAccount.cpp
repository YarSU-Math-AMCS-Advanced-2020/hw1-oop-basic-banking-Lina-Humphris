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

DebitAccount::DebitAccount(string _owner_id, double _balance, double _limit, int _currency) {
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_debit();
	set_debit_id(temp_id);
	set_owner_id(_owner_id);
	set_balance(_balance);
	set_limit(_limit);
	set_currency(_currency);
	set_has_card(false);
	data_base->add_debit(this);
}

void DebitAccount::change_limit() {
	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	double limit;
	int n;
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = *base_debit[i];
		if (curr.get_debit_id() == get_debit_id()) {
			n = i;
		}
	}
	cout << "������� ����� �� ������ ����� �� ����� ��� 0, ���� �� ������ ������������� �����: ";
	cin >> limit;
	base_debit[n]->set_limit(int(limit * 100) / 100);
	data_base->set_base_debit(base_debit);

}


std::istream& operator>>(istream& in, DebitAccount& t) {
	cout << "������� ��� ID: ";
	string s;
	cin >> s;
	DataBase* data_base = DataBase::getInstance();
	vector <PersonalBankAccount*> base_personal_account = data_base->get_base_personal_account();
	vector <LegalEnitityBankAccount*> base_legal_account = data_base->get_base_legal_account();
	bool is_accept = false;
	while (!is_accept) {
		for (int i = 0; i < base_personal_account.size(); i++) {
			PersonalBankAccount curr = *base_personal_account[i];
			if (curr.get_account_id() == s) {
				is_accept = true;
			}
		}
		for (int i = 0; i < base_legal_account.size(); i++) {
			LegalEnitityBankAccount curr = *base_legal_account[i];
			if (curr.get_account_id() == s) {
				is_accept = true;
			}
		}
		if (!is_accept) {
			cout << "������������ � ����� ID �� ����������, ���������� ��� ���: ";
		}
		if (!is_accept) cin >> s;
	}
	t.set_owner_id(s);
	cout << "������� ����� �� ������ ����� �� ����� ��� 0, ���� �� ������ ������������� �����: ";
	double n;
	cin >> n;
	t.set_limit(int(n * 100) / 100);
	cout << "������� 0, ���� ������ ������� ���� � ���������� ������. \n������� 1, ���� ������ ������� ���� � �������� ���.";
	cout << "������� 2, ���� ������ ������� ���� � ����.";
	int temp;
	cin >> temp;
	t.set_currency(temp);
	string temp_id = data_base->get_max_id_debit();
	t.set_debit_id(temp_id);
	cout << "����������� ������ �������, ��� �������� id: " << temp_id << endl;
	data_base->add_debit(&t);
	return in;
}

std::ostream& operator<<(ostream& out, DebitAccount& t) {
	cout << "ID �����: " << t.get_debit_id() << endl;
	cout << "ID ������� �����: " << t.get_owner_id() << endl;
	cout << "������: " << t.get_balance() << endl;
	cout << "�����: " << t.get_limit() << endl;
	cout << "������: ";
	int cur = t.get_currency();
	if (cur == 0) cout << "�����" << endl;
	else if (cur == 1) cout << "�������" << endl;
	else cout << "����" << endl;
	bool has_card = t.get_has_card();
	if (has_card) cout << "� ������� ����� ��������� �����" << endl;
	else cout << "� ������� ����� �� ��������� �����" << endl;
	return out;
}

void DebitAccount::delete_debit_account() {

	DataBase* data_base = DataBase::getInstance();
	vector <DebitAccount*> base_debit = data_base->get_base_debit();
	int n;
	cout << "������� 1 ���� ������ ��������� ������ �� ������ ����, ����� ������� 0, ����� ����� ��.";
	cin >> n;
	if (n == 1) {
		set_limit(0);
		cout << "������� ����� �����, �� ������� ����� �������� �������: ";
		string s;
		cin >> s;
		bool is_accept = false;
		int transfer_currency;
		string transfer;
		while (!is_accept) {
			for (int i = 0; i < base_debit.size(); i++) {
				DebitAccount curr = *base_debit[i];
				if (curr.get_debit_id() == s) {
					is_accept = true;
					transfer_currency = curr.get_currency();
					transfer = s;
				}
			}
			if (!is_accept) {
				cout << "����� � ����� ������� �� ����������, ���������� ��� ���: ";
			}
			if (s == get_debit_id()) {
				cout << "����� ���������� ����� ��������� � ������� ����� � �������� ����� ������������� �������, ���������� ��� ���: ";
				is_accept = false;
			}
			if (!is_accept) cin >> s;
			if (is_accept && get_currency() != transfer_currency) {
				cout << "������ ������ �� ���������, ������� ������ ���� �� ������� ����� �������� �������: ";
				cin >> s;
				is_accept = false;
			}
		}
		Transaction del_acc(get_debit_id(), transfer, get_balance(), get_currency());
	}
	vector <DebitAccount*> new_base_debit;
	for (int i = 0; i < base_debit.size(); i++) {
		DebitAccount curr = *base_debit[i];
		if (curr.get_debit_id() != get_debit_id()) {
			new_base_debit.push_back(base_debit[i]);
		}
	}
	data_base->set_base_debit(new_base_debit);
}
