#include "CashTransaction.h"


void CashTransaction::set_date() {
	Date temp_date;
	_date = temp_date;
}


CashTransaction::CashTransaction() {
	set_card_account("");
	set_amount(0);
	set_date();
	set_status(false);
	set_place(0);
	set_place_number(0);
}

std::ostream& operator<<(ostream& out, CashTransaction& t) {
	cout << "ID карты: " << t.get_card_account() << endl;
	cout << "Сумма: " << t.get_amount() << endl;
	Date temp = t.get_date();
	cout << "Дата: " << temp;
	int res = t.get_status();
	if (res) cout << "Операция прошла успещно" << endl;
	else cout << "Операция отклонена" << endl;
	return out;
}