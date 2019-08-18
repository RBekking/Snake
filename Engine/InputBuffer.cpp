#include "InputBuffer.h"

InputBuffer::InputBuffer(Location& initial_direction)
{
	Reset(initial_direction);
}

void InputBuffer::Reset(Location& initial_direction)
{
	buffer_[0] = initial_direction;
	read_index_ = 0;
	write_index_ = 0;
}

bool InputBuffer::IsEmpty() const
{
	return empty_;
}

Location InputBuffer::Get()
{
	Location next_item{ 0, 0 };

	if (!empty_) {
		next_item = buffer_[read_index_++];
		read_index_ &= (N_ELEMENTS - 1);
		full_ = false;
		if (read_index_ == write_index_) {
			empty_ = true;
		}
	}
	else {
		next_item = buffer_[read_index_];
	}

	return next_item;
}

void InputBuffer::Push(Location& new_direction)
{
	if (!full_) {
		bool valid_command = true;

		if ((new_direction == LEFT) || (new_direction == RIGHT)) {
			for (int i = 0; i < N_ELEMENTS; ++i) {
				valid_command = valid_command && (buffer_[i] != LEFT) && (buffer_[i] != RIGHT);
			}
		}
		else if ((new_direction == UP) || (new_direction == DOWN)) {
			for (int i = 0; i < N_ELEMENTS; ++i) {
				valid_command = valid_command && (buffer_[i] != UP) && (buffer_[i] != DOWN);
			}
		}
		else {
			valid_command = false;
			// Illegal command
		}

		if (valid_command) {
			buffer_[write_index_++] = new_direction;
			empty_ = false;
			write_index_ &= (N_ELEMENTS - 1);
			if (write_index_ == read_index_) {
				full_ = true;
			}
		}
	}
}

