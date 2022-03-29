#include "BankAccount.h"

void BankAccount::change_addres() {
	cout << "¬ведите новый адрес: ";
	Addres temp;
	cin >> temp;
	set_addres(temp);
}

void BankAccount::change_phone_number() {
	cout << "¬ведите новый номер телефона: ";
	string temp;
	cin >> temp;
	set_phone_number(temp);
}
