#include <chrono>

#include "timer.h"


void Timer::now()
{
	points[count++] = clock_t::now();
}

Timer::elapsed_t Timer::elapsed()
{
	count = 0;
	return points[1] - points[0];
}

std::ostream& operator<<(std::ostream& out, Timer& t)
{
	out << t.elapsed().count();
	return out;
}
