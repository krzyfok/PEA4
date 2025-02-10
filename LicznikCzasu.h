#pragma once
#include <cstdint>
class LicznikCzasu {
public:
	void start();
	double stop();
	double PCFreq = 0.0;
	int64_t CounterStart = 0;
	
};
extern LicznikCzasu licznik;