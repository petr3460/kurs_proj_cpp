#pragma once
#include "Date.h"

class Calculator {
public:
	Calculator() {};
	Calculator(Date, char, int, int);
	~Calculator() {};
	void calculate();
	void set_oper1();
	void set_sign();
	void set_type2op();
	void set_oper2();
	void set_format();
	void print_res();
private:
	Date oper1, oper2;
	int oper3;
	char sign;
	char type_answer;
	char type_2oper;

};