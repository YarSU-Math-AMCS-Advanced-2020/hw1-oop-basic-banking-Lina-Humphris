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
	cout << "ID �����: " << t.get_card_account() << endl;
	cout << "�����: " << t.get_amount() << endl;
	Date temp = t.get_date();
	cout << "����: " << temp;
	int res = t.get_status();
	if (res) cout << "�������� ������ �������" << endl;
	else cout << "�������� ���������" << endl;
	return out;
}