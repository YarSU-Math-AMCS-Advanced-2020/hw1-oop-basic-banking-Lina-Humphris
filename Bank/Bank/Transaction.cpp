#include "Transaction.h"

Transaction::Transaction() {
	set_debit_account("");
	set_transfer_account("");
	set_amount(0);
	set_currency_of_operation(0);
	Date date_temp;
	set_date(date_temp); //пока нинаю, нужно ли этот метод тут прописывать
	set_status(0);
}
// Change
std::istream& operator>>(istream& in, Transaction& t) {
	string s;
	cout << "Введите номер вашего счета: ";
	cin >> s;
	t.set_debit_account(s);
	cout << "Введите счет, на который будет совершен перевод: ";
	cin >> s;
	t.set_transfer_account(s);
	double temp_amount;
	cout << "Введите сумму перевода: ";
	cin >> temp_amount;
	t.set_amount(temp_amount);
	// добавить сравнение валют, и в случае совпадения set_currency_of_operation
	//добавить проверку на лимит и на кол-во денег
	Date date_temp;
	t.set_date(date_temp);
	//если все ок, ставим статус
	return in;
}
