#include "BankAccount.h"

void BankAccount::change_addres() {
	cout << "������� ����� �����: ";
	Addres temp;
	cin >> temp;
	set_addres(temp);
}

void BankAccount::change_phone_number() {
	cout << "������� ����� ����� ��������: ";
	string temp;
	cin >> temp;
	set_phone_number(temp);
}
