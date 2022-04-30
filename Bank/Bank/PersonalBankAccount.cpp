#include "PersonalBankAccount.h"
#include "DataBase.h"


PersonalBankAccount::PersonalBankAccount() {
	set_account_id("");
	Addres temp;
	set_addres(temp);
	set_phone_number("");
	set_surname("");
	set_name("");
	set_patronymic("");
	Date temp_date;
	set_birth_date(temp_date);
	set_sex(0);
	set_passport("");

}
PersonalBankAccount::PersonalBankAccount(string name, string surname, string patronymic, string TIN, Addres addres, string pnumber, Date birth_date, int sex, string passport) {
	set_addres(addres);
	set_phone_number(pnumber);
	set_surname(surname);
	set_name(name);
	set_patronymic(patronymic);
	set_birth_date(birth_date);
	set_sex(sex);
	set_passport(passport);
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_account();
	set_account_id(temp_id);
	data_base->add_personal_account(this);
}

std::istream& operator>>(istream& in, PersonalBankAccount& t) {
	Addres temp;
	cin >> temp;
	t.set_addres(temp);
	string s;
	cout << "¬ведите номер телефона как одинадцатизначное число: ";
	cin >> s;
	t.set_phone_number(s);
	cout << "¬ведите фамилию: ";
	cin >> s;
	t.set_surname(s);
	cout << "¬ведите им€: ";
	cin >> s;
	t.set_name(s);
	cout << "¬ведите отчество: ";
	cin >> s;
	t.set_patronymic(s);
	cout << "¬ведите дату рождени€: " << endl;
	Date temp_date;
	cin >> temp_date;
	t.set_birth_date(temp_date);
	cout << "";
	int temp_int;
	cout << "¬ведите -1, если вы мужского пола; 1, если вы женского пола; иначе введите 0: ";
	cin >> temp_int;
	t.set_sex(temp_int);
	cout << "¬ведите серию и номер паспорта в виде двенадцатизначного числа: ";
	cin >> s;
	t.set_passport(s);
	DataBase* data_base = DataBase::getInstance();
	string temp_id = data_base->get_max_id_account();
	t.set_account_id(temp_id);
	cout << "–егистраци€ прошла успешно, ¬ам присвоен id: " << temp_id << endl;
	data_base->add_personal_account(&t);
	return in;
}

std::ostream& operator<<(ostream& out, PersonalBankAccount& t) {
	cout << "¬аш ID: " << t.get_account_id() << endl;
	cout << "¬аша фамили€: " << t.get_surname() << endl;
	cout << "¬аше им€: " << t.get_name() << endl;
	cout << "¬аше отчество: " << t.get_patronymic() << endl;
	Addres d = t.get_adress();
	cout << "¬аш адрес: " << endl << d;
	cout << "¬аш номер телефона: " << t.get_phone_number() << endl;
	Date temp = t.get_birth_date();
	cout << "ƒата рождени€: " << temp;
	int sex = t.get_sex();
	cout << "¬аш пол: ";
	if (sex == -1) cout << "мужской" << endl;
	if (sex == 1) cout << "женский" << endl;
	else cout << "пол не указан" << endl;
	cout << "¬аши паспортные данные: " << t.get_passport() << endl;
	return out;
}

void PersonalBankAccount::change_surname() {
	cout << "¬ведите новую фамилию: ";
	string temp;
	cin >> temp;
	set_surname(temp);
}

void PersonalBankAccount::change_name() {
	cout << "¬ведите новое им€: ";
	string temp;
	cin >> temp;
	set_name(temp);
}

void PersonalBankAccount::change_patronymic() {
	cout << "¬ведите новое отчество: ";
	string temp;
	cin >> temp;
	set_patronymic(temp);
}

void PersonalBankAccount::change_birth_date() {
	cout << "¬ведите новую дату рождени€: ";
	Date temp;
	cin >> temp;
	set_birth_date(temp);
}

void PersonalBankAccount::change_sex() {
	cout << "¬ведите -1, если вы мужского пола; 1, если вы женского пола; иначе введите 0: ";
	int temp;
	cin >> temp;
	set_sex(temp);
}

void PersonalBankAccount::change_passport() {
	cout << "¬ведите новые серию и номер паспорта в виде двенадцатизначного числа: ";
	string temp;
	cin >> temp;
	set_passport(temp);
}
