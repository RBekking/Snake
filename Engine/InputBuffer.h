#pragma once
#include "Location.h"

class InputBuffer {
public:

	explicit InputBuffer(Location& initial_direction) ;
	void Reset(Location& initial_direction);
	bool IsEmpty() const;
	Location Get();
	void Push(Location& new_direction);

private:
	const Location LEFT  = Location(-1, 0);
	const Location RIGHT = Location(1, 0);
	const Location UP    = Location(0, -1);
	const Location DOWN  = Location(0, 1);

	static constexpr int N_ELEMENTS = 1;

	Location	buffer_[N_ELEMENTS];
	bool		full_			{ false };
	bool		empty_			{ true };
	int			read_index_		{ 0 };
	int			write_index_	{ 0 };
};

