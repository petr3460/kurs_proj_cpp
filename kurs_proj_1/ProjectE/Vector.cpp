#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int n)
{
	beg = new Object*[n];
	cur = 0;
	size = n;
}
Vector::Vector()
{
	beg = new Object*[10];  //~
	cur = 0;
	size = 10;
}


Vector::~Vector()
{
	if (beg != 0)delete[]beg;
	beg = 0;
}


//просмотр вектора
void Vector::Show() {
	if (cur == 0) cout << "empty" << endl;
	Object **p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->Show();
		p++;
	}
}

//операция, возвращающая размер вектора
int Vector::operator()() {
	return cur;
}
//удаление элемента из вектора, память не освобождается
void Vector::Del() {
	if (cur == 0) return;
	cur--;
}

void Vector::HandleEvent(const TEvent &e) {
	if (e.what == evMessage) {
		Object**p = beg;
		for (int i = 0; i < cur; i++) {
			(*p)->HandleEvent(e);
			p++;
		}
	}
}

//получение элемента по номеру
void Vector::Get(int ind) {
	if (cur == 0) cout << "empty" << endl;
	else if (ind >= cur) cout << "Index Error!" << endl;
	else {
		Object **p = beg;
		p += ind;
		(*p)->Show();
	}
}