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