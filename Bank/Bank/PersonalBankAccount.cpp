#include "PersonalBankAccount.h"
#include "DataBase.h"


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
	data_base->add_personal_account(&t);
	return in;
}

std::ostream& operator<<(ostream& out, PersonalBankAccount& t) {
	cout << "��� ID: " << t.get_account_id() << endl;
	cout << "���� �������: " << t.get_surname() << endl;
	cout << "���� ���: " << t.get_name() << endl;
	cout << "���� ��������: " << t.get_patronymic() << endl;
	Addres d = t.get_adress();
	cout << "��� �����: " << endl << d;
	cout << "��� ����� ��������: " << t.get_phone_number() << endl;
	Date temp = t.get_birth_date();
	cout << "���� ��������: " << temp;
	int sex = t.get_sex();
	cout << "��� ���: ";
	if (sex == -1) cout << "�������" << endl;
	if (sex == 1) cout << "�������" << endl;
	else cout << "��� �� ������" << endl;
	cout << "���� ���������� ������: " << t.get_passport() << endl;
	return out;
}

void PersonalBankAccount::change_surname() {
	cout << "������� ����� �������: ";
	string temp;
	cin >> temp;
	set_surname(temp);
}

void PersonalBankAccount::change_name() {
	cout << "������� ����� ���: ";
	string temp;
	cin >> temp;
	set_name(temp);
}

void PersonalBankAccount::change_patronymic() {
	cout << "������� ����� ��������: ";
	string temp;
	cin >> temp;
	set_patronymic(temp);
}

void PersonalBankAccount::change_birth_date() {
	cout << "������� ����� ���� ��������: ";
	Date temp;
	cin >> temp;
	set_birth_date(temp);
}

void PersonalBankAccount::change_sex() {
	cout << "������� -1, ���� �� �������� ����; 1, ���� �� �������� ����; ����� ������� 0: ";
	int temp;
	cin >> temp;
	set_sex(temp);
}

void PersonalBankAccount::change_passport() {
	cout << "������� ����� ����� � ����� �������� � ���� ������������������ �����: ";
	string temp;
	cin >> temp;
	set_passport(temp);
}
