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
	cout << "������� ��� ID: ";
	string s;
	cin >> s;
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
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_debit();
	t.set_debit_id(temp_id);
	cout << "����������� ������ �������, ��� �������� id: " << temp_id << endl;
	data_base->add_debit(t);
	return in;
}


