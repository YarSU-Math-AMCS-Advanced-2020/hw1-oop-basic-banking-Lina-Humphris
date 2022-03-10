#define _CRT_SECURE_NO_WARNINGS //дл€ работы localtime
#include "Date.h"

Date::Date() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	set_day(ltm->tm_mday);
	set_month(1 + ltm->tm_mon);
	set_year(1900 + ltm->tm_year);
	set_hour(ltm->tm_hour);
	set_minute(ltm->tm_min);
	set_second(ltm->tm_sec);
}

Date Date::operator=(Date a)
{
	set_day(a.get_day());
	set_month(a.get_month());
	set_year(a.get_year());
	set_hour(a.get_hour());
	set_minute(a.get_minute());
	set_second(a.get_second());
	return *this;
}

std::ostream& operator<<(ostream& out, Date& t) {
	cout<< "Date: " << t.get_day() << "." << t.get_month() << "." << t.get_year() << endl;
	cout << "Time: " << t.get_hour() << ":" << t.get_minute() << ":" << t.get_second() << endl;
	return out;
}

std::istream& operator>>(istream& in, Date& t) {
	int day, month, year;
	cout << "¬ведите число: ";
	cin >> day;
	cout << "¬ведите мес€ц (от 1 до 12): ";
	cin >> month;
	cout << "¬ведите год: ";
	cin >> year;
	t.set_day(day);
	t.set_month(month);
	t.set_year(year);
	t.set_hour(10);
	t.set_minute(0);
	t.set_second(0);
	return in;
}