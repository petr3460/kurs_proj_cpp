#pragma once
const int evNothing = 0;
const int evMessage = 100;
const int cmCalc = 1;
const int cmLog = 2;
const int cmQuit = 101;

struct TEvent {
	int what;
	union {
		int command;
		struct {
			int message;
			int a;
		};
	};
};