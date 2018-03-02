#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int days;
	int seconds;
	string date_string;
	string time_string;
	void seconds_to_string();
	void days_to_string();
public:
	Date();
	~Date();
	void init(string, string);
	void init(int, int);
	int get_days();
	int get_sec();	
	Date&operator=(const Date&);
	Date operator+(const Date&);
	Date operator+(const int&);
	Date operator-(const Date&);
	Date operator-(const int&);
	friend istream&operator>>(istream&in, Date&t);
	friend ostream&operator<<(ostream&out, const Date&t);
};




