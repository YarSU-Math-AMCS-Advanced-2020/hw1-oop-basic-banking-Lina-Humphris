#include "Transaction.h"

Transaction::Transaction() {
	set_debit_account("");
	set_transfer_account("");
	set_amount(0);
	set_currency_of_operation(0);
	Date date_temp;
	set_date(date_temp); //���� �����, ����� �� ���� ����� ��� �����������
	set_status(0);
}
// Change
std::istream& operator>>(istream& in, Transaction& t) {
	string s;
	cout << "������� ����� ������ �����: ";
	cin >> s;
	t.set_debit_account(s);
	cout << "������� ����, �� ������� ����� �������� �������: ";
	cin >> s;
	t.set_transfer_account(s);
	double temp_amount;
	cout << "������� ����� ��������: ";
	cin >> temp_amount;
	t.set_amount(temp_amount);
	// �������� ��������� �����, � � ������ ���������� set_currency_of_operation
	//�������� �������� �� ����� � �� ���-�� �����
	Date date_temp;
	t.set_date(date_temp);
	//���� ��� ��, ������ ������
	return in;
}
