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
	cout << "������� ����� �������� ��� ����������������� �����: ";
	cin >> s;
	t.set_phone_number(s);
	cout << "������� �������: ";
	cin >> s;
	t.set_surname(s);
	cout << "������� ���: ";
	cin >> s;
	t.set_name(s);
	cout << "������� ��������: ";
	cin >> s;
	t.set_patronymic(s);
	cout << "������� ���� ��������: " << endl;
	Date temp_date;
	cin >> temp_date;
	t.set_birth_date(temp_date);
	cout << "";
	return in;
}
