#pragma once
#include "DebitAccount.h"
#include "BankAccount.h"
#include"PersonalBankAccount.h"
#include "LegalEnitityBankAccount.h"
#include "DebitCard.h"
#include "Transaction.h"
#include "CashTransaction.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class DataBase
{
private:
	static DataBase* p_instance;
	//��� ������������ ������ ����� ������� ����� ������������
	long long _max_id_account = 1; //��� ��������(�� ��������� �� ������������ � �� ������������)
	long long _max_id_card = 1; //��� �����
	long long _max_id_debit = 1; //��� ���������� �����
	vector <PersonalBankAccount*> _base_personal_account;
	vector <LegalEnitityBankAccount*> _base_legal_account;
	vector <DebitAccount*> _base_debit;
	vector <DebitCard*> _base_card;
	vector <Transaction*> _base_transaction;
	vector <CashTransaction*> _base_cash;

	DataBase() {};
	DataBase& operator=(DataBase&);

public:

	static DataBase* getInstance() {
		if (!p_instance)
			p_instance = new DataBase();
		return p_instance;
	}

	string id_to_string(long long id);


	void set_base_card(vector <DebitCard*> base_card) { _base_card = base_card; };
	void set_base_personal_account(vector <PersonalBankAccount*> base_account) { _base_personal_account = base_account; };
	void set_base_legal_account(vector <LegalEnitityBankAccount*> base_account) { _base_legal_account = base_account; };
	void set_base_debit(vector <DebitAccount*> base_debit) { _base_debit = base_debit; };


	//����� ���������� ������ ����� 16, ���� ����� ����� ������, ���������� � ������ ����
	string get_max_id_account();
	string get_max_id_debit();
	string get_max_id_card();

	vector <PersonalBankAccount*> get_base_personal_account() { return _base_personal_account; };
	vector <LegalEnitityBankAccount*> get_base_legal_account() { return _base_legal_account; };
	vector <DebitAccount*> get_base_debit() { return _base_debit; };
	vector <DebitCard*> get_base_card() { return _base_card; };
	vector <Transaction*> get_base_transaction() { return _base_transaction; };
	vector <CashTransaction*> get_base_cash() { return _base_cash; };



	void add_personal_account(PersonalBankAccount* account) { _base_personal_account.push_back(account); };
	void add_legal_account(LegalEnitityBankAccount* account) { _base_legal_account.push_back(account); };
	void add_debit(DebitAccount* debit) { _base_debit.push_back(debit); };
	void add_card(DebitCard* card) { _base_card.push_back(card); };
	void add_transaction(Transaction* transaction) { _base_transaction.push_back(transaction); };
	void add_cash_transaction(CashTransaction* cash_transaction) { _base_cash.push_back(cash_transaction); };
};
