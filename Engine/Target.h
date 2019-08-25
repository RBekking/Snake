#pragma once

#include "Location.h"
#include "Player.h"
#include "Note.h"
#include "Chord.h"
#include "FrameTimer.h"
#include "WorldGrid.h"
#include <random>

class Target
{
public:
	Target();
	explicit Target(const Location& loc);
	void WithGrid(WorldGrid& grid);
	void WithRNG(std::mt19937& rng);
	void WithPlayer(Player& player);
	void WithColorManager(ColorManager& colors);
	void Draw(const int frame_number = 0);
	void DrawChord(const int frame_number = 0);
	void HandleCollection();
	void Update();
	void Reposition();

private:
	static constexpr Color DEFAULT_COLOR = Colors::Orange;

	Location		location_;
	WorldGrid*		grid_;
	Player*			player_;
	ColorManager*	colors_;
	musical::Chord 	chord_;
	FrameTimer		timer_;
	std::mt19937	rng_;
	std::uniform_int_distribution<int> x_dist_;
	std::uniform_int_distribution<int> y_dist_;
	std::uniform_int_distribution<int> rand_color_;
};

