#pragma once
#include "Vector.h"
#include "Calculator.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;
class Dialog :
	public Vector {
public:
	Dialog();
public:
	virtual ~Dialog();
	virtual void GetEvent(TEvent &event);
	virtual int Execute();
	virtual void HandleEvent(TEvent &event);
	virtual void ClearEvent(TEvent &event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};
