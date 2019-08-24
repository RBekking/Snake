#pragma once

#undef max
#include <cstdint>
#include <limits>

typedef int64_t timer_t;

class FrameTimer
{
public:
	static constexpr timer_t infinity = std::numeric_limits<timer_t>::max();
	static constexpr timer_t immediately = 0;

	FrameTimer(const timer_t timeout = infinity);
	void Update();
	void SetTimeout(const timer_t timeout);
	void Clear();
	bool IsSet() const;
	bool IsTimedOut();

private:
	bool    timed_out_;
	timer_t frame_count_;
	timer_t frame_count_max_;
};

