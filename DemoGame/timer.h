#pragma once

#include<ctime>

/*
Gibt die Zeit in Millisekunden seit dem letzten Start.
*/
class timer {
public:
	unsigned int look();
	void start();
	void restart();

private:
	std::clock_t st;
};