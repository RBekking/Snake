#pragma once
#pragma comment(lib, "winmm.lib")

#include "Location.h"
#include "WorldGrid.h"
#include "ColorManager.h"
#include <random>

#include <mmsystem.h>

class Player
{
static constexpr int INIT_N_SEGMENTS = 3;
static constexpr int INIT_NEXT_LOCATION_X = 0;
static constexpr int INIT_NEXT_LOCATION_Y = 0;
static constexpr int INIT_SEGMENT_COLOR_VAL = 128;

public:

	static constexpr int N_SEGMENTS_MAX = (20*20) - 2; //(WorldGrid::WIDTH * WorldGrid::HEIGHT) - 1;

	Player();
	virtual ~Player();
	void Reset(const Location& start_location = Location{ 0,0 });

	void WithGrid(WorldGrid& grid);
	void WithColorManager(ColorManager& colors);
	void WithRNG(std::mt19937& rng);

	void Draw(const int frame_number = 0);

	void MoveBy(const Location& delta_loc);
	void Grow();
	void Decay(const int frame_counter, const int max_death_frames);
	bool IsDead() const;
	bool LocationIsOnSnake(const Location& loc) const;
	Location GetLocation() const;
	int GetLength() const;

private:

	class Segment
	{
	public:

		void Init(const Location& loc, const Color& color);
		void MoveBy(const Location& delta_loc);
		void Follow(const Segment& next);
		void Follow(const Location& new_loc);
		void Draw(WorldGrid& grid, const Location& offset = Location(0, 0)) const;
		Location GetLocation() const;

	private:

		Location location_;
		Color    color_;
	};

private:

	Color _CalcSegmentColor(const int n_segment, const Color& base_color);
	void _ReColor(const Color& head_color, const Color& body_color);

	Location		start_location_;
	int				n_segments_;
	WorldGrid*		grid_;
	ColorManager*	colors_;
	Location		next_location_;
	bool			collided_;
	std::mt19937*	rng_;
	std::uniform_int_distribution<int> x_dist_;
	std::uniform_int_distribution<int> y_dist_;
	int				segment_color_intensity_;
	Segment*		segments_;
};
