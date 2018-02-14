#include "Date.h"
#include <string> 
#include <sstream>
using namespace std;

Date::Date()
{
	days = 0;
	date_string = "";
}

Date::~Date()
{
}

int year_to_days(int year) {
	int ytd = 0;
	for (int i = 1; i < year; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) ytd += 366;
		else ytd += 365;
	}
	//cout << "this is YTD, res = " << ytd;
	return ytd;
}

int days_to_year(int &days) {
	int i;
	for (i = 1; days >= 365; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
			if (days == 365 || days == 366) break;
			days -= 366;
		}			
		else if (days == 365) break;
		else days -= 365;
	}
	return i;
}

string toString(int val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}

void Date::init(string dat)
{
	date_string = dat;
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0, mon = 0, year = 0; i < 10; i++) {
		if (i == 0) days += (dat[i] - '0') * 10;
		if (i == 1) days += (dat[i] - '0');
		if (i == 3) mon += (dat[i] - '0') * 10;
		if (i == 4) {
			mon += (dat[i] - '0');
			for (int j = 1; j < mon; j++) {
				days += days_in_month[j-1];
			}
		}
		if (i == 6) year += (dat[i] - '0') * 1000;
		if (i == 7) year += (dat[i] - '0') * 100;
		if (i == 8) year += (dat[i] - '0') * 10;
		if (i == 9) {
			year += (dat[i] - '0');
			days += year_to_days(year);
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) days++;
		}
	}
	
}

void Date::days_to_string()
{
	int days_in_last_year = days;
	int year = days_to_year(days_in_last_year);
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0 && year % 100 || year % 400 == 0)  days_in_month[1] = 29;
	int month = 0;
	for (int i = 0; ; i++) {
		if (days_in_last_year - days_in_month[i] > 0) days_in_last_year -= days_in_month[i];
		else { 
			month = i + 1; 
			break; 
		}
	}
	string s_month;
	(month > 9) ? s_month = toString(month) : s_month = "0" + toString(month);
	string s_days;
	(days_in_last_year > 9) ? s_days = toString(days_in_last_year) : s_days = "0" + toString(days_in_last_year);
	string s_year = toString(year);
	date_string = s_days + "." + s_month + "." + s_year;
}

void Date::string_to_days()
{
	string dat = date_string;
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0, mon = 0, year = 0; i < 10; i++) {
		if (i == 0) days += (dat[i] - '0') * 10;
		if (i == 1) days += (dat[i] - '0');
		if (i == 3) mon += (dat[i] - '0') * 10;
		if (i == 4) {
			mon += (dat[i] - '0');
			for (int j = 1; j < mon; j++) {
				days += days_in_month[j - 1];
			}
		}
		if (i == 6) year += (dat[i] - '0') * 1000;
		if (i == 7) year += (dat[i] - '0') * 100;
		if (i == 8) year += (dat[i] - '0') * 10;
		if (i == 9) {
			year += (dat[i] - '0');
			days += year_to_days(year);
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) days++;
		}
	}

}

Date & Date::operator=(const Date & dat)
{
	if (&dat == this)return *this;
	days = dat.days;
	date_string = dat.date_string;
	return *this;
}

Date Date::operator+(const Date & dat2)
{
	Date result;
	result.days = this->days + dat2.days;
	result.days_to_string();
	return result;
}

Date Date::operator-(const Date & dat2)
{
	Date result;
	result.days = this->days - dat2.days;
	result.days_to_string();
	return result;
}

istream & operator>>(istream & in, Date & t)
{
	string input_data;
	cout << "enter date in format dd.mm.yyyy "; cin >> input_data;
	t.init(input_data);
	return in;
}

ostream & operator<<(ostream & out, const Date & t)
{
	return (out << t.date_string << endl);
}
