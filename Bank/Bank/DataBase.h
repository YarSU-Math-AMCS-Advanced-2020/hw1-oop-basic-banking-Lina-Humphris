#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "BankAccount.h"
#include "DebitAccount.h"
#include "DebitCard.h"

using namespace std;

class DataBase
{
private:
	static DataBase* p_instance;
	DataBase() {};
	DataBase& operator=(DataBase&);

	//Для безопасности храним номер который будем использовать
	long long _max_id_account = 1; //счетчик один для физ и юр лиц
	long long _max_id_card = 1; 
	long long _max_id_debit = 1; 
	vector <BankAccount> _base_account;
	//vector <DebitAccount> _base_debit; //добавить конструкторы по умолчанию
	//vector <DebitCard> _base_card;

public:
	static DataBase* getInstance() {
		if (!p_instance)
			p_instance = new DataBase();
		return p_instance;
	}

	//будут возвращать id длины 16
	string get_max_id_account();
	string get_max_id_debit();
	string get_max_id_card();
	string id_to_string(long long id);

	void add_account(BankAccount account) { _base_account.push_back(account); };
	//void add_debit(DebitAccount debit) { _base_debit.push_back(debit); };
	//void add_card(DebitCard card) { _base_card.push_back(card); };

	void delete_card(long long card_id); //добавить реализацию
	void delete_debit(long long debit_id);//добавить реализацию
};
