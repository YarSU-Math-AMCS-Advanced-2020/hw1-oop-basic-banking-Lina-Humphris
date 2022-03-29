#pragma once
#include <ctime>
#include <iostream>

using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;
	int _hour;
	int _minute;
	int _second;
public:
	Date();

	void set_day(int day) { _day = day; };
	void set_month(int month) { _month = month; };
	void set_year(int year) { _year = year; };
	void set_hour(int hour) { _hour = hour; };
	void set_minute(int minute) { _minute = minute; };
	void set_second(int second) { _second = second; };

	int get_day() { return _day; };
	int get_month() { return _month; };
	int get_year() { return _year; };
	int get_hour() { return _hour; };
	int get_minute() { return _minute; };
	int get_second() { return _second; };

	Date operator=(Date a);

	friend std::ostream& operator<<(ostream& out, Date& t);
	friend std::istream& operator>>(istream& in, Date& t);

};

