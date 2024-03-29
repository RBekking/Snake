#pragma once

#include "Location.h"
#include "WorldGrid.h"
#include "InputBuffer.h"
#include <random>

template <typename T>
T constrain(const T var, const T low_bound, const T high_bound)
{
	return (var < low_bound ? low_bound : (var > high_bound ? high_bound : var));
}

class Player
{
private:
	class Segment 
	{
	public:
		void Reset();
		void Init(const Location& loc, const Color& color);
		void MoveBy(const Location& delta_loc);
		void Follow(const Segment& next);
		void Follow(const Location& new_loc);
		void Draw(WorldGrid& grid, const Location& offset = Location(0,0)) const;
		Location GetLocation() const;

	private:
		Location location_;
		Color    color_;
	};

public:
	static constexpr int N_SEGMENTS_MAX = 100;//(WorldGrid::WIDTH * WorldGrid::HEIGHT) - 1;

	explicit Player(const Location& loc);
	void Reset();
	void WithGrid(WorldGrid& grid);
	void WithRNG(std::mt19937& rng);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(const int frame_number);
	Location GetLocation() const;
	int GetLength() const;
	bool IsDead() const;
	bool LocationIsOnSnake(const Location& loc) const;
	void Decay(const int frame_counter, const int max_death_frames);

private:
	static constexpr int INIT_N_SEGMENTS = 3;
	static constexpr int INIT_NEXT_LOCATION_X = 0;
	static constexpr int INIT_NEXT_LOCATION_Y = 0;
	static constexpr int INIT_SEGMENT_COLOR_VAL = 128;

	void _ReColor(const Color& head_color, const Color& body_color);
	Color _CalcSegmentColor(const int n_segment, const Color& base_color);

private:
	Color			head_color_		{ Colors::Yellow };
	Color			body_color_		{ Colors::Green };
	Location		start_location_ { 0,0 };
	int				n_segments_		{ INIT_N_SEGMENTS };
	WorldGrid*		grid_			{ nullptr };
	Location		next_location_	{ Location(INIT_NEXT_LOCATION_X, INIT_NEXT_LOCATION_Y) };
	bool			collided_		{ false };
	std::mt19937*	rng_			{ nullptr };
	std::uniform_int_distribution<int>			x_dist_			{ -1, 1 };
	std::uniform_int_distribution<int>			y_dist_			{ -1, 1 };
	Segment			segments_[N_SEGMENTS_MAX];
	int segment_color_intensity_ = INIT_SEGMENT_COLOR_VAL;
};
