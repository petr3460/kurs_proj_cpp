#pragma once
#include "Object.h"
#include "Event.h"
class Vector
{
public:
	Vector(int);
	Vector();
	~Vector();
	virtual void HandleEvent(const TEvent &e);
	void Del();
	void Get(int);
	void Show();
	int operator()();
protected:
	Object * *beg;
	int size;
	int cur;

};

