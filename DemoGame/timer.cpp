#include"timer.h"

using namespace std;

void timer::restart() {
	start();
}

void timer::start() {
	st = clock();
}

unsigned int timer::look() {
	return (unsigned int)((double)(clock() - st))/((double)CLOCKS_PER_SEC)*1000;
}