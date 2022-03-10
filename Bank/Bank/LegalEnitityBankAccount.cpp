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
	return in;
}