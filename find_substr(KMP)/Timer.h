#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>


class Timer
{
private:
	using elapsed_t = std::chrono::duration<double>;
	using clock_t = std::chrono::steady_clock;
	using point_t = clock_t::time_point;

	point_t points[2];
	int count;

private:
	elapsed_t elapsed();

public:
	void now();
	friend std::ostream& operator<<(std::ostream& out, Timer& t);
};


#endif

