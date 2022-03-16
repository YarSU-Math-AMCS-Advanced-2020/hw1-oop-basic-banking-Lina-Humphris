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
	int temp_int;
	cout << "������� -1, ���� �� �������� ����; 1, ���� �� �������� ����; ����� ������� 0: ";
	cin >> temp_int;
	t.set_sex(temp_int);
	cout << "������� ����� � ����� �������� � ���� ������������������ �����: ";
	cin >> s;
	t.set_passport(s);
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_account();
	t.set_account_id(temp_id);
	cout << "����������� ������ �������, ��� �������� id: " << temp_id << endl;
	data_base->add_account(t);
	return in;
}

void PersonalBankAccount::change_surname() {
	cout << "������� ����� �������: ";
	string temp;
	cin >> temp;
	this->set_surname(temp);
}

void PersonalBankAccount::change_name() {
	cout << "������� ����� ���: ";
	string temp;
	cin >> temp;
	this->set_name(temp);
}

void PersonalBankAccount::change_patronymic() {
	cout << "������� ����� ��������: ";
	string temp;
	cin >> temp;
	this->set_patronymic(temp);
}

void PersonalBankAccount::change_birth_date() {
	cout << "������� ����� ���� ��������: ";
	Date temp;
	cin >> temp;
	this->set_birth_date(temp);
}

void PersonalBankAccount::change_sex() {
	cout << "������� -1, ���� �� �������� ����; 1, ���� �� �������� ����; ����� ������� 0: ";
	int temp;
	cin >> temp;
	this->set_sex(temp);
}

void PersonalBankAccount::change_passport() {
	cout << "������� ����� ����� � ����� �������� � ���� ������������������ �����: ";
	string temp;
	cin >> temp;
	this->set_passport(temp);
}
