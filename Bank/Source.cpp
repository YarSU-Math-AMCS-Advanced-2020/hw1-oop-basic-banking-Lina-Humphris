#pragma once
#include<iostream>
#include "Bank/Transaction.h"
#include <Windows.h>
#include "Bank/Date.h"
#include "Bank/DebitCard.h"
#include "Bank/DataBase.h"
#include "Bank/PersonalBankAccount.h"
#include "Bank/LegalEnitityBankAccount.h"
#include"Bank/CashIn.h"
#include"Bank/CashOut.h"
using namespace std;

void client_registration();
void change_information_of_account();
void account_registration();
void delete_account();
void change_limit_of_account();
void card_registration();
void rebinding_the_card();
void delete_card();
void change_limit_of_card();
void create_transaction();
void create_cash_out_and_cash_in();

int main() {
	//�������� �� ���� �� ��������������, �������� ������ � ������ ������:)
	//�� ������ �������� ��������� ������� ���� �������(����� �����������)
	setlocale(LC_ALL, "");
	//client_registration();
	//change_information_of_account();
	//account_registration();
	//delete_account();
	//change_limit_of_account();
	//card_registration();
	//rebinding_the_card();
	//delete_card();
	//change_limit_of_card();
	//create_transaction();
	//create_cash_out_and_cash_in()
}

template<typename Type>
void print_vector(vector<Type*> v) {
	for (int i = 0; i < v.size(); i++) {
		Type out = *v[i];
		cout << out << endl;
	}
}

void client_registration() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	PersonalBankAccount p2;
	LegalEnitityBankAccount l1;
	LegalEnitityBankAccount l2;
	cin >> p1 >> p2 >> l1 >> l2;
	cout << endl << "���� ������ ��������: " << endl << endl;
	vector<PersonalBankAccount*> p = data_base->get_base_personal_account();
	vector<LegalEnitityBankAccount*> l = data_base->get_base_legal_account();
	print_vector(p);
	print_vector(l);
}

void change_information_of_account() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	LegalEnitityBankAccount l1;
	cin >> p1 >> l1;
	cout << endl << "���� ������ ��������: " << endl << endl;
	vector<PersonalBankAccount*> p = data_base->get_base_personal_account();
	vector<LegalEnitityBankAccount*> l = data_base->get_base_legal_account();
	print_vector(p);
	print_vector(l);
	p1.change_addres();
	p1.change_birth_date();
	p1.change_name();
	p1.change_passport();
	p1.change_patronymic();
	p1.change_phone_number();
	p1.change_sex();
	p1.change_surname();
	l1.change_addres();
	l1.change_establishing_date();
	l1.change_name();
	l1.change_phone_number();
	l1.change_TIN();
	cout << endl << "���� ������ ��������: " << endl;
	print_vector(p);
	print_vector(l);
}

void account_registration() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	LegalEnitityBankAccount l1;
	DebitAccount d1;
	DebitAccount d2;
	cin >> p1 >> l1 >> d1 >> d2;
	cout << endl << "���� ������ ������: " << endl << endl;
	vector<DebitAccount*> d = data_base->get_base_debit();
	print_vector(d);
}

void delete_account() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	LegalEnitityBankAccount l1;
	DebitAccount d1;
	DebitAccount d2;
	cin >> p1 >> l1 >> d1 >> d2;
	vector<DebitAccount*> d = data_base->get_base_debit();
	cout << endl << "���� ������ ������: " << endl << endl;
	print_vector(d);
	d1.delete_debit_account();
	cout << endl << "���� ������ ������: " << endl << endl;
	d = data_base->get_base_debit();
	print_vector(d);
}

void change_limit_of_account() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	DebitAccount d1;
	cin >> p1 >> d1;
	cout << endl << "���� ������ ������: " << endl << endl;
	vector<DebitAccount*> d = data_base->get_base_debit();
	print_vector(d);
	d1.change_limit();
	cout << endl << "���� ������ ������: " << endl << endl;
	print_vector(d);
}

void card_registration() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	DebitAccount d1, d2;
	DebitCard c1, c2;
	cin >> p1 >> d1 >> d2 >> c1 >> c2;
	cout << endl << "���� ������ ����: " << endl << endl;
	vector<DebitCard*> c = data_base->get_base_card();
	print_vector(c);
}

void rebinding_the_card() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	DebitAccount d1, d2;
	DebitCard c1;
	cin >> p1 >> d1 >> d2 >> c1;
	cout << endl << "���� ������ ����: " << endl << endl;
	vector<DebitCard*> c = data_base->get_base_card();
	print_vector(c);
	c1.rebinding_card();
	cout << endl << "���� ������ ����: " << endl << endl;
	print_vector(c);
}

void delete_card() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	DebitAccount d1, d2;
	DebitCard c1, c2;
	cin >> p1 >> d1 >> d2 >> c1 >> c2;
	cout << endl << "���� ������ ����: " << endl << endl;
	vector<DebitCard*> c = data_base->get_base_card();
	print_vector(c);
	c1.delete_card();
	cout << "���� ������ ����: " << endl << endl;
	c = data_base->get_base_card();
	print_vector(c);
}

void change_limit_of_card() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	DebitAccount d1;
	DebitCard c1;
	cin >> p1 >> d1 >> c1;
	cout << endl << "���� ������ ����: " << endl << endl;
	vector<DebitCard*> c = data_base->get_base_card();
	print_vector(c);
	c1.change_limit();
	cout << endl << "���� ������ ����: " << endl << endl;
	print_vector(c);
}

void create_transaction() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	DebitAccount d1, d2;
	DebitCard c1, c2;
	cin >> p1 >> d1 >> d2 >> c1 >> c2;
	Transaction t1, t2;
	cin >> t1 >> t2;
	cout << endl << "���� ������ ����������: " << endl << endl;
	vector<Transaction*> t = data_base->get_base_transaction();
	print_vector(t);
}

void create_cash_out_and_cash_in() {
	DataBase* data_base = DataBase::getInstance();
	PersonalBankAccount p1;
	DebitAccount d1, d2;
	DebitCard c1, c2;
	CashIn i1;
	CashOut o1;
	cin >> p1 >> d1 >> d2 >> c1 >> c2 >> i1 >>o1;
	cout << endl << "���� ������ �������� � ���������: " << endl << endl;
	vector<CashTransaction*> ct = data_base->get_base_cash();
	print_vector(ct);
	cout << endl << "���� ������ ���������: " << endl << endl;
	vector<DebitAccount*> d = data_base->get_base_debit();
	print_vector(d);
}