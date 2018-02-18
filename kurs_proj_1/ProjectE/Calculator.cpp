#include "Calculator.h"

Calculator::Calculator(Date op1, char sig, int type2op, int typeans) {
	oper1 = op1;
	sign = sig;
	type_answer = typeans;
	type_2oper = type2op;
}

void Calculator::calculate()
{
	switch (type_2oper)
	{
	case '1': switch (sign) {
	case '-': oper3 = oper1.get_days() - oper2.get_days(); break;
	case '+': oper3 = oper1.get_days() + oper2.get_days(); break;
	}; break;
	case '2': switch (sign) {
	case '-': oper2.init(oper1.get_days() - oper3); break;
	case '+': oper2.init(oper1.get_days() + oper3); break;
	}; break;
	case '3': switch (sign) {
	case '-': oper2.init(oper1.get_days() - oper3); break;
	case '+': oper2.init(oper1.get_days() + oper3); break;
	}; break;
	case '4': switch (sign) {
	case '-': oper2.init(oper1.get_days() - oper3); break;
	case '+': oper2.init(oper1.get_days() + oper3); break;
	}; break;
	}

}

void Calculator::set_oper1()
{
	cin >> oper1;
}

void Calculator::set_sign()
{
	cout << "enter sign of operation ('+', '-') ('+' by default): "; cin >> sign;
	if (sign != '-') sign = '+';
}

void Calculator::set_type2op()
{
	cout << "enter type of second operand: 1.Date 2.Month 3.Week 4.Day: (Date by default):" << endl;
	cin >> type_2oper;
	if (type_2oper != '2' && type_2oper != '3' && type_2oper != '4') type_2oper = '1';
}

void Calculator::set_oper2()
{
	if (type_2oper == '1') cin >> oper2;
	else {
		cout << "enter a second operator : ";
		while (1) {
			cin >> oper3;
			if (oper3 > 0 && oper3 < 10000)  break;
			else cout << "incorrect input, try again..";
		}
	}
	if (type_2oper == '2') oper3 *= 30;
	if (type_2oper == '3') oper3 *= 7;

}

void Calculator::set_format()
{
	if (type_2oper == '1') {
		cout << "enter type of answer: (1 - month, 2 - week, 3 - day(default): ";
		cin >> type_answer;
		if (type_answer != '1' && type_answer != '2') type_answer = '3';
	}
	else type_answer = '0';
}

void Calculator::print_res()
{
	if (type_answer == '0') cout << "answer is : " << oper2;
	if (type_answer == '1') cout << "answer is : " << oper3 / 30;
	if (type_answer == '2') cout << "answer is : " << oper3 / 7;
	if (type_answer == '3') cout << "answer is : " << oper3;

}

