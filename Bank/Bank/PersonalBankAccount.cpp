#include "PersonalBankAccount.h"

PersonalBankAccount::PersonalBankAccount() {
	set_account_id("");
	Addres temp;
	set_addres(temp);
	set_phone_number("");
	set_surname("");
	set_name("");
	set_patronymic("");
	Date temp_date;
	set_birth_date(temp_date);
	set_sex(0);
	set_passport("");

}

std::istream& operator>>(istream& in, PersonalBankAccount& t) {
	Addres temp;
	cin >> temp;
	t.set_addres(temp);
	string s;
	cout << "¬ведите номер телефона как одинадцатизначное число: ";
	cin >> s;
	t.set_phone_number(s);
	cout << "¬ведите фамилию: ";
	cin >> s;
	t.set_surname(s);
	cout << "¬ведите им€: ";
	cin >> s;
	t.set_name(s);
	cout << "¬ведите отчество: ";
	cin >> s;
	t.set_patronymic(s);
	cout << "¬ведите дату рождени€: " << endl;
	Date temp_date;
	cin >> temp_date;
	t.set_birth_date(temp_date);
	cout << "";
	int temp_int;
	cout << "¬ведите -1, если вы мужского пола; 1, если вы женского пола; иначе введите 0: ";
	cin >> temp_int;
	t.set_sex(temp_int);
	cout << "¬ведите серию и номер паспорта в виде двенадцатизначного числа: ";
	cin >> s;
	t.set_passport(s);
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_account();
	t.set_account_id(temp_id);
	cout << "–егистраци€ прошла успешно, ¬ам присвоен id: " << temp_id << endl;
	data_base->add_account(t);
	return in;
}

void PersonalBankAccount::change_surname() {
	cout << "¬ведите новую фамилию: ";
	string temp;
	cin >> temp;
	this->set_surname(temp);
}

void PersonalBankAccount::change_name() {
	cout << "¬ведите новое им€: ";
	string temp;
	cin >> temp;
	this->set_name(temp);
}

void PersonalBankAccount::change_patronymic() {
	cout << "¬ведите новое отчество: ";
	string temp;
	cin >> temp;
	this->set_patronymic(temp);
}

void PersonalBankAccount::change_birth_date() {
	cout << "¬ведите новую дату рождени€: ";
	Date temp;
	cin >> temp;
	this->set_birth_date(temp);
}

void PersonalBankAccount::change_sex() {
	cout << "¬ведите -1, если вы мужского пола; 1, если вы женского пола; иначе введите 0: ";
	int temp;
	cin >> temp;
	this->set_sex(temp);
}

void PersonalBankAccount::change_passport() {
	cout << "¬ведите новые серию и номер паспорта в виде двенадцатизначного числа: ";
	string temp;
	cin >> temp;
	this->set_passport(temp);
}
