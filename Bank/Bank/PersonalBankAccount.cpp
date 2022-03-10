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
	return in;
}
