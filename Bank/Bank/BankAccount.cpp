#include "BankAccount.h"

void BankAccount::change_addres() {
	cout << "������� ����� �����: ";
	Addres temp;
	cin >> temp;
	this->set_addres(temp);
}

void BankAccount::change_phone_number() {
	cout << "������� ����� ����� ��������: ";
	string temp;
	cin >> temp;
	this->set_addres(temp);
}