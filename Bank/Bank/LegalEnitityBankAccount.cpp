#include "LegalEnitityBankAccount.h"

LegalEnitityBankAccount::LegalEnitityBankAccount() {
	set_account_id("");
	Addres temp_addres;
	set_addres(temp_addres);
	set_phone_number("");
	set_name("");
	Date temp_date;
	set_establishing_date(temp_date);
	set_TIN("");
}

std::istream& operator>>(istream& in, LegalEnitityBankAccount& t) {
	Addres temp;
	cin >> temp;
	t.set_addres(temp);
	string s;
	cout << "Введите номер телефона как одинадцатизначное число: ";
	cin >> s;
	t.set_phone_number(s);
	cout << "Введите название кампании: ";
	cin >> s;
	t.set_name(s);
	cout << "Введите дату создания кампании: " << endl;
	Date temp_date;
	cin >> temp_date;
	t.set_establishing_date(temp_date);
	cout << "Введите TIN: ";
	cin >> s;
	t.set_TIN(s);
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_account();
	t.set_account_id(temp_id);
	cout << "Регистрация прошла успешно, Вам присвоен id: " << temp_id << endl;
	data_base->add_account(t);
	return in;
}

void LegalEnitityBankAccount::change_name() {
	cout << "Введите новое название компании: ";
	string temp;
	cin >> temp;
	this->set_name(temp);
}

void LegalEnitityBankAccount::change_establishing_date() {
	cout << "Введите новую дату создания компании: ";
	Date temp;
	cin >> temp;
	this->set_establishing_date(temp);
}

void LegalEnitityBankAccount::change_TIN() {
	cout << "Введите новый TIN: ";
	string temp;
	cin >> temp;
	this->set_TIN(temp);
}