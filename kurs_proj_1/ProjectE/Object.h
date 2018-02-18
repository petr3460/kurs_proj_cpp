#pragma once
#include "Event.h"

class Object
{
public:
	Object() {};
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual void HandleEvent(const TEvent &e) {};
	virtual ~Object() {};
};

