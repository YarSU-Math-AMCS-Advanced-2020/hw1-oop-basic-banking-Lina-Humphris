#include "LegalEnitityBankAccount.h"
#include "DataBase.h"

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
	cout << "������� ����� �������� ��� ����������������� �����: ";
	cin >> s;
	t.set_phone_number(s);
	cout << "������� �������� ��������: ";
	cin >> s;
	t.set_name(s);
	cout << "������� ���� �������� ��������: " << endl;
	Date temp_date;
	cin >> temp_date;
	t.set_establishing_date(temp_date);
	cout << "������� TIN: ";
	cin >> s;
	t.set_TIN(s);
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_account();
	t.set_account_id(temp_id);
	cout << "����������� ������ �������, ��� �������� id: " << temp_id << endl;
	data_base->add_legal_account(&t);
	return in;
}

std::ostream& operator<<(ostream& out, LegalEnitityBankAccount& t) {
	cout << "��� ID: " << t.get_account_id() << endl;
	Addres d = t.get_adress();
	cout << "��� �����: " << endl << d;
	cout << "��� ����� ��������: " << t.get_phone_number() << endl;
	cout << "�������� ����� ��������: " << t.get_name() << endl;
	Date temp = t.get_establishing_date();
	cout << "���� ����������� ����� ��������: " << endl << temp;
	cout << "��� TIN: " << t.get_TIN() << endl;
	return out;
}

void LegalEnitityBankAccount::change_name() {
	cout << "������� ����� �������� ��������: ";
	string temp;
	cin >> temp;
	set_name(temp);
}

void LegalEnitityBankAccount::change_establishing_date() {
	cout << "������� ����� ���� �������� ��������: ";
	Date temp;
	cin >> temp;
	set_establishing_date(temp);
}

void LegalEnitityBankAccount::change_TIN() {
	cout << "������� ����� TIN: ";
	string temp;
	cin >> temp;
	set_TIN(temp);
}