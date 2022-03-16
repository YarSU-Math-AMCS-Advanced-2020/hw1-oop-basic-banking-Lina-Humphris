#include "BankAccount.h"

void BankAccount::change_addres() {
	cout << "¬ведите новый адрес: ";
	Addres temp;
	cin >> temp;
	this->set_addres(temp);
}

void BankAccount::change_phone_number() {
	cout << "¬ведите новый номер телефона: ";
	string temp;
	cin >> temp;
	this->set_addres(temp);
}