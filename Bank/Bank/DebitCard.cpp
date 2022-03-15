#include "DebitCard.h"
#include "DataBase.h"

DebitCard::DebitCard() {
	set_card_id("");
	set_debit_id("");
	set_pay_system(0);
	set_limit(0);
	Date temp_date;
	set_validity_period(temp_date);
}

std::istream& operator>>(istream& in, DebitCard& t) {
	cout << "Введите номер счета, к которому хотите привязать карту: ";
	string s;
	cin >> s;
	t.set_debit_id(s);
	cout << "Выберите платежную систему. \nВведите 0, если хотите выбрать Lisa, 1 - MasterBart, 2 - HoMiR: ";
	int n;
	cin >> n;
	t.set_pay_system(n);
	cout << "Введите 0, если не хотите устанавливать лимит на карту, -1, " <<
		"если хотите установить лимит такой же,как на счете, 1 - если другой: ";
	// //
	Date temp;
	temp.set_year(temp.get_year() + 4);
	t.set_validity_period(temp);
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_card();
	t.set_card_id(temp_id);
	cout << "Регистрация прошла успешно, номер вашей карты: " << temp_id << endl;
	data_base->add_card(t);
	return in;
}