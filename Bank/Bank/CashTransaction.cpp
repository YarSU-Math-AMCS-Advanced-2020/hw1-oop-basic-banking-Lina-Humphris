#include "CashTransaction.h"

CashTransaction::CashTransaction() {
	set_debit_account("");
	set_amount(0);
	set_date();
	set_status(false);
	set_place(0);
	set_place_number(0);
}