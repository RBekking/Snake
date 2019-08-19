#include "Player.h"

void Player::Segment::Init(const Location& loc, const Color& color)
{
	location_ = loc;
	color_ = color;
}

void Player::Segment::MoveBy(const Location& delta_loc)
{
	location_ += delta_loc;
}

void Player::Segment::Follow(const Segment& next)
{
	location_ = next.location_;
}

void Player::Segment::Follow(const Location& new_loc)
{
	location_ = new_loc;
}

void Player::Segment::Draw(WorldGrid& grid, const Location& offset) const
{
	grid.DrawFilledCell(location_, offset, color_);
}

Location Player::Segment::GetLocation() const
{
	return location_;
}

void Player::Reset(const Location &start_location)
{
	n_segments_ = INIT_N_SEGMENTS;
	next_location_ = start_location;
	collided_ = false;
	segment_color_intensity_ = INIT_SEGMENT_COLOR_VAL;
	colors_->UpdateLevel(n_segments_);
	if (colors_->IsUpdated()) {
		segments_[0].Init(start_location_, colors_->GetSnakeHead());
		for (int i = 1; i < n_segments_; ++i) {
			segments_[i].Init(start_location_, _CalcSegmentColor(i, colors_->GetSnakeBody()));
		}
	}
}

void Player::WithGrid(WorldGrid& grid)
{
	grid_ = &grid;
}

void Player::WithColorManager(ColorManager& colors)
{
	colors_ = &colors;
}

void Player::WithRNG(std::mt19937& rng)
{
	rng_ = &rng;
}

void Player::MoveBy(const Location& delta_loc)
{
	Location new_location = next_location_ + delta_loc;

	for (int i = n_segments_ - 1; i > 0; --i) {
		if ((segments_[i].GetLocation() == new_location) ||  // Collision with self
			(!grid_->CheckInGridBounds(new_location)))       // Collision with wall
		{
			collided_ = true;
		}
		segments_[i].Follow(segments_[i - 1]);
	}
	
	segments_[0].Follow(next_location_);
	
	if (!collided_) {
		next_location_ += delta_loc;
	}
}

void Player::Grow()
{
	if (n_segments_ < N_SEGMENTS_MAX) {
		colors_->UpdateLevel(n_segments_);
		if (colors_->IsUpdated()) {
			_ReColor(colors_->GetSnakeHead(), colors_->GetSnakeBody());
		}
		segments_[n_segments_].Init(segments_[n_segments_ - 1].GetLocation(), _CalcSegmentColor(n_segments_, colors_->GetSnakeBody()));
		++n_segments_;
	}
	else {
		// We've won the game!
	}
}

void Player::Draw(const int frame_number) 
{
	Location delta{ 0, 0 };
	for (int i = n_segments_ - 1; i > 0; --i) {
		delta = segments_[i - 1].GetLocation() - segments_[i].GetLocation();
		segments_[i].Draw(*grid_, (delta * frame_number) + Location{i % 2, i % 2});
	}
	delta = next_location_ - segments_[0].GetLocation();
	segments_[0].Draw(*grid_, delta * frame_number);
}

Location Player::GetLocation() const
{
	return next_location_;
}

int Player::GetLength() const
{
	return n_segments_;
}

bool Player::IsDead() const
{
	return collided_;
}

bool Player::LocationIsOnSnake(const Location& loc) const
{
	for (int i = 0; i < n_segments_; ++i) {
		if (loc == segments_[i].GetLocation()) {
			return true;
		}
	}
	return false;
}

void Player::Decay(const int frame_counter, const int max_death_frames)
{
	static int last_frame_counter = -1;
	double dim_factor = 0;
	
	if (frame_counter != last_frame_counter) {
		last_frame_counter = frame_counter;
		if (max_death_frames >= 0) {
			dim_factor = (double(max_death_frames) - double(frame_counter)) / double(max_death_frames);
		}
		else {
			dim_factor = 1;
		}
		_ReColor(Colors::DimColor(colors_->GetSnakeDeadHead(), dim_factor), Colors::DimColor(colors_->GetSnakeDeadBody(), dim_factor));
	}
}

Color Player::_CalcSegmentColor(const int n_segment, const Color& base_color)
{
	static signed char dir = -1;

	if ((n_segment % 5) == 0) {
		dir = -dir;
	}
	segment_color_intensity_ += (16 * dir);

	//segment_color_intensity_ = constrain(segment_color_intensity_, 0, 255);
	return Colors::DimColor(base_color, double(segment_color_intensity_) / 255);
}

void Player::_ReColor(const Color& head_color, const Color& body_color)
{
	segment_color_intensity_ = INIT_SEGMENT_COLOR_VAL;
	segments_[0].Init(segments_[0].GetLocation(), head_color);
	for (int i = 1; i < n_segments_; ++i) {
		if (!collided_) {
			segments_[i].Init(segments_[i].GetLocation(), _CalcSegmentColor(i, body_color));
		}
		else {
			segments_[i].Init(segments_[i].GetLocation(), body_color);
		}
	}
}
