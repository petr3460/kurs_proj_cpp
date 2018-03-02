#include "Date.h"
#include <string> 
#include <sstream>
#include <regex>
using namespace std;



Date::Date()
{
	days = 0;
	date_string = "";
	seconds = 0;
	time_string = "";
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

void Date::init(string dat, string time)
{
	date_string = dat;
	time_string = time;
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int mon = 0, year = 0;
	year = (dat[9] - '0') + (dat[8] - '0') * 10 + (dat[7] - '0') * 100 + (dat[6] - '0') * 1000;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) days_in_month[1] = 29;
	days = year_to_days(year);
	mon = (dat[4] - '0') + (dat[3] - '0') * 10;
	for (int j = 1; j < mon; j++) {
		days += days_in_month[j - 1];
	}
	days += (dat[1] - '0') + (dat[0] - '0') * 10;

	seconds = (time[0] - '0') * 36000 + (time[1] - '0') * 3600 + (time[3] - '0') * 600 + (time[4] - '0') * 60 + (time[6] - '0') * 10 + (time[7] - '0');
}

void Date::seconds_to_string()
{
	string hh, mm, ss;
	hh = toString(seconds / 3600);
	if (hh.length() < 2) hh = "0" + hh;
	mm = toString((seconds % 3600) / 60);
	if (mm.length() < 2) mm = "0" + mm;
	ss = toString((seconds % 3600) % 60);
	if (ss.length() < 2) ss = "0" + ss;
	time_string = hh + ":" + mm + ":" + ss;
}

void Date::init(int d, int t)
{
	days = d;
	if (t >= 86400) {
		seconds = t - 86400; 
		days++;
	}  
	else if (t < 0) {
		seconds = 86400 + t;
		days--;
	}
	else seconds = t;	
	seconds_to_string();
	days_to_string();
}

int Date::get_days()
{
	return this->days;
}

int Date::get_sec() 
{
	return this->seconds;
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
	while (s_year.length() < 4) s_year = "0" + s_year;
	date_string = s_days + "." + s_month + "." + s_year;
}


Date & Date::operator=(const Date & dat)
{
	if (&dat == this)return *this;
	days = dat.days;
	seconds = dat.seconds;
	date_string = dat.date_string;
	time_string = dat.time_string;
	return *this;
}


Date Date::operator+(const Date & dat2)
{
	Date result;
	result.days = this->days + dat2.days;
	if (this->seconds + dat2.seconds < 86400) result.seconds = this->seconds + dat2.seconds;
	else {
		result.seconds = this->seconds + dat2.seconds - 86400;
		result.days++;
	}
	result.seconds_to_string();
	result.days_to_string();
	return result;
}


Date Date::operator-(const Date & dat2)
{
	Date result;
	result.days = this->days - dat2.days;
	if (this->seconds >= dat2.seconds) result.seconds = this->seconds - dat2.seconds;
	else {
		result.seconds = 86400 + this->seconds - dat2.seconds;
		result.days--;
	}	
	result.seconds_to_string();
	result.days_to_string();
	return result;
}

Date Date::operator-(const int & op2) {
	Date result;
	result.days = this->days - op2;
	result.seconds = this->seconds;
	result.time_string = this->time_string;
	result.days_to_string();
	return result;
}

Date Date::operator+(const int & op2) {
	Date result;
	result.days = this->days + op2;
	result.seconds = this->seconds;
	result.time_string = this->time_string;
	result.days_to_string();
	return result;
}


istream & operator>>(istream & in, Date & t)
{
	string input_data;
	string input_time;
	while (true) {
		try {
			cout << "enter date in format dd.mm.yyyy "; cin >> input_data;
			cmatch result;
			regex regular("(\\d{2})"
				"(\\.|-|\\/)"
				"(\\d{2})"
				"(\\.|-|\\/)"
				"(\\d{4})"
			);
			string day, month, year;
			int int_day, int_month, int_year;
			if (regex_match(input_data.c_str(), result, regular)) {
				if (result[2] != result[4]) throw 1; 
				if (result[2] == '-') {
					day = result[3];
					month = result[1];
				}
				else {
					day = result[1];
					month = result[3];
				}
				year = result[5];
			}
			else throw 1;
		
			int_day = atoi(day.c_str());
			if (int_day == 0 && int_day > 31) throw 1;
			int_month = atoi(month.c_str());
			if (int_month > 12) throw 1;
			int_year = atoi(year.c_str());
			bool is_leap = (int_year % 4 == 0 && int_year % 100 != 0 || int_year % 400 == 0);
			int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			if (is_leap) days_in_month[1] = 29;
			if (int_day > days_in_month[int_month - 1]) throw 1;
			if (input_data[2] == '-') {
				string temp = input_data.substr(0, 2);
				input_data[0] = input_data[3];
				input_data[1] = input_data[4];
				input_data[3] = temp[0];
				input_data[4] = temp[1];
			}
			cout << "enter time in format hh:mm:ss "; cin >> input_time;
			regex regular2("(([0-1]\\d)|(2[0 - 3]))"
				"((:[0-5]\\d){2})");
			if (!regex_match(input_time.c_str(), regular2)) throw 1;
			t.init(input_data, input_time);
			return in;
		}
		catch (int a) { cout << "incorrect input, try again.." << endl; }
	}
}

ostream & operator<<(ostream & out, const Date & t)
{
	return (out << t.date_string << "  " << t.time_string << endl);
}
