#include "Dialog.h"

Dialog::Dialog() :Vector()
{
	EndState = 0;
}

Dialog::~Dialog()
{
}

//получение события
void Dialog::GetEvent(TEvent &event) {
	string OpInt = "clq";
	string s;
	string param;
	char code;
	cout << endl << "c- calculate, l - show log, q - quit > ";
	cin >> s; code = s[0];
	if (OpInt.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'c':event.command = cmCalc; break;
		case 'l':event.command = cmLog; break;
		case 'q':event.command = cmQuit; break;
		}
		//выделяем параметры комманды , если они есть 
		if (s.length() > 1) {
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());  // преобразуем параметр в число
			event.a = A;  // записываем в сообщение
		}
	}
	else event.what = evNothing;  // пустое событие
}

int Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

int Dialog::Valid() {
	if (EndState == 0) return 0;
	else return 1;
}

void Dialog::ClearEvent(TEvent &event) {
	event.what = evNothing;
}

void Dialog::EndExec() {
	EndState = 1;
}

//обработчик событий
void Dialog::HandleEvent(TEvent &event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmCalc:{ 
			Calculator *calc = new Calculator;
			calc->set_oper1();
			calc->set_sign();
			calc->set_type2op();
			calc->set_oper2();
			calc->set_format();
			calc->calculate();
			calc->print_res();
			delete calc;
			ClearEvent(event);
			break; }
		case cmLog:
			
			ClearEvent(event);
			break;

		case cmQuit:EndExec();
			ClearEvent(event);
			break;

		default:Vector::HandleEvent(event);
		};
	};
}