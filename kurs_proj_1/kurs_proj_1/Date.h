#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	int days;
	string date_string;
public:
	Date();
	//Date(const Date&t);
	~Date();
	void init(string);
	void days_to_string();
	void string_to_days();
	
	Date&operator=(const Date&);
	Date operator+(const Date&);
	Date operator-(const Date&);
	friend istream&operator>>(istream&in, Date&t);
	friend ostream&operator<<(ostream&out, const Date&t);
};

