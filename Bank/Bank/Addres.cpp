#include "Addres.h"


Addres::Addres(string country, string region, string locality, string street, string index, int house, int flat) {
	set_country(country);
	set_region(region);
	set_locality(locality);
	set_street(street);
	set_index(index);
	set_house(house);
	set_flat(flat);
}

Addres Addres::operator=(Addres a)
{
	set_country(a.get_country());
	set_region(a.get_region());
	set_locality(a.get_locality());
	set_street(a.get_street());
	set_index(a.get_index());
	set_house(a.get_house());
	set_flat(a.get_flat());
	return *this;
}

std::istream& operator>>(istream& in, Addres& t) {
	cout << "Введите страну: ";
	string s;
	cin >> s;
	t.set_country(s);
	cout << "Введите регион: ";
	cin >> s;
	t.set_region(s);
	cout << "Введите населенный пункт: ";
	cin >> s;
	t.set_locality(s);
	cout << "Введите улицу: ";
	cin >> s;
	t.set_street(s);
	cout << "Введите номер дома: ";
	int n;
	cin >> n;
	t.set_house(n);
	cout << "Введите номер квартиры: ";
	cin >> n;
	t.set_flat(n);
	cout << "Введите индех: ";
	cin >> s;
	t.set_index(s);

	return in;
}

std::ostream& operator<<(ostream& out, Addres& t) {
	cout << "Страна: " << t.get_country() << endl;
	cout << "Регион: " << t.get_region() << endl;
	cout << "Населенный пункт: " << t.get_locality() << endl;
	cout << "Улица: " << t.get_street() << endl;
	cout << "Номер дома: " << t.get_house() << endl;
	cout << "Номер квартиры: " << t.get_flat() << endl;
	cout << "Индех: " << t.get_index() << endl;

	return out;
}