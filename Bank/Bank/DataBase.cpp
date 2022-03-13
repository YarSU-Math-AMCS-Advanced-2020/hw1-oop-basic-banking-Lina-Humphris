#include "DataBase.h"

DataBase* DataBase::p_instance = 0;

string DataBase::id_to_string(long long id) {
	string s = to_string(id);
	string id_str = "";
	for (int i = 0; i < s.length(); i++)
		id_str += '0';
	id_str += s;
	return id_str;
}

string DataBase::get_max_id_account() {
	return(id_to_string(_max_id_account));
}

string DataBase::get_max_id_debit() {
	return(id_to_string(_max_id_debit));
}

string DataBase::get_max_id_card() {
	return(id_to_string(_max_id_card));
}