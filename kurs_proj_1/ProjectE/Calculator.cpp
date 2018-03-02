#include "Calculator.h"
#include <fstream>


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
	case '-': oper4 = oper1 - oper2; break;
	case '+': oper4 = oper1 + oper2; break;
	}; break;

	case '2': switch (sign) {
	case '-': oper2 = oper1 - oper3; break;
	case '+': oper2 = oper1 + oper3; break;
	}; break;

	case '3': switch (sign) {
	case '-': oper2 = oper1 - oper3; break;
	case '+': oper2 = oper1 + oper3; break;
	}; break;

	case '4': switch (sign) {
	case '-': oper2 = oper1 - oper3; break;
	case '+': oper2 = oper1 + oper3; break;
	}; break;

	case '5': switch (sign) {
	case '-': oper2.init(oper1.get_days(), oper1.get_sec() - oper3); break;
	case '+': oper2.init(oper1.get_days(), oper1.get_sec() + oper3); break;
	}; break;

	case '6': switch (sign) {
	case '-': oper2.init(oper1.get_days(), oper1.get_sec() - oper3); break;
	case '+': oper2.init(oper1.get_days(), oper1.get_sec() + oper3); break;
	}; break;

	case '7': switch (sign) {
	case '-': oper2.init(oper1.get_days(), oper1.get_sec() - oper3); break;
	case '+': oper2.init(oper1.get_days(), oper1.get_sec() + oper3); break;
	}; break;
	}
	ofstream fout;
	fout.open("log.txt", ofstream::app);
	if (!fout.is_open()) {
		cout << "error of log recording!";
	}
	else {
		fout << oper1  << " " << sign << " ";
		switch (type_2oper) {
		case '1': fout << oper2; break;
		case '2': fout << oper3 / 30 << " months "; break;
		case '3': fout << oper3 / 7 << " weeks "; break;
		case '4': fout << oper3 << " days "; break;
		case '5': fout << oper3 / 3600 << " hours "; break;
		case '6': fout << oper3 / 60 << " minutes "; break;
		case '7': fout << oper3 << " seconds "; break;
		}
		fout << " = ";
		fout.close();
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
	cout << "enter type of second operand: 1.Date 2.Month 3.Week 4.Day 5.Hour 6.Minute 7.Second: (Date by default):" << endl;
	cin >> type_2oper;
	if ((int)type_2oper < 49 && (int)type_2oper > 55 ) type_2oper = '1';
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
	if (type_2oper == '5') oper3 *= 3600;
	if (type_2oper == '6') oper3 *= 60;
}

void Calculator::set_format()
{
	if (type_2oper == '1') {
		cout << "enter type of answer: (1-month, 2-week, 3-day(default), 4-hour, 5-min, 6-sec: ";
		cin >> type_answer;
		if (type_answer != '1' && type_answer != '2' && type_answer != '4' && type_answer != '5' && type_answer != '6') type_answer = '3';
	}
	else type_answer = '0';
}

void Calculator::print_res()
{
	ofstream fout;
	fout.open("log.txt", ofstream::app);
	switch (type_answer) {
	case '0': { 
		cout << "answer is : " << oper2;  
		fout << oper2; 
		break;
	}
	case '1': { 
		cout << "answer is : " << oper4.get_days() / 30 << " months"; 
		fout << oper4.get_days() / 30 << " months";
		break; 	
	}
	case '2': {
		cout << "answer is : " << oper4.get_days() / 7 << " weeks"; 
		fout << oper4.get_days() / 7 << " weeks";
		break; 
	}
	case '3': {
		cout << "answer is : " << oper4.get_days() << " days"; 
		fout << oper4.get_days() << " days";
		break; 
	}
	case '4': {
		unsigned int temp = 24 * oper4.get_days() + oper4.get_sec() / 3600;
		cout << "answer is : " << temp << " hours";
		fout << temp << " hours";
		break;
	}
	case '5': {
		unsigned int temp = 1440 * oper4.get_days() + oper4.get_sec() / 60;
		cout << "answer is : " << temp << " minutes";
		fout << temp << " minutes";
		break;
	}
	case '6': {
		unsigned long long temp = 86400ULL * oper4.get_days() + oper4.get_sec();
		cout << "answer is : " << temp << " seconds";
		fout << temp << " seconds";
		break;
	}
	}
	fout << "\n";
	fout.close();
}


