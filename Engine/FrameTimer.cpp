#include "FrameTimer.h"

FrameTimer::FrameTimer(const timer_t timeout) :
	frame_count_(0),
	frame_count_max_(timeout),
	timed_out_(false)
{
}

void FrameTimer::Update()
{
	if (IsSet()) {
		++frame_count_;
	}
}

void FrameTimer::SetTimeout(const timer_t timeout)
{
	frame_count_max_ = timeout;
}

void FrameTimer::Clear()
{
	frame_count_ = 0;
	frame_count_max_ = infinity;
	timed_out_ = false;
}

bool FrameTimer::IsSet() const
{
	return (frame_count_max_ != infinity);
}

bool FrameTimer::IsTimedOut()
{
	if (frame_count_ == infinity) {
		timed_out_ = false;
		return false;
	}
	else {
		return (frame_count_ >= frame_count_max_);
	}
}
