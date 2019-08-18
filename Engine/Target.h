#pragma once

#include "Player.h"
#include "Location.h"
#include "GridEntity.h"
#include <random>

class Target : public GridEntity
{
public:
	Target();
	explicit Target(const Location& loc);
	void WithRNG(std::mt19937& rng);
	void WithPlayer(Player& player);
	void Draw(const int frame_number = 0) override;
	void HandleCollection();
	void Reposition();

private:
	static constexpr Color DEFAULT_COLOR = Colors::Orange;

	void _ReColor(const Color& new_color);

	Player* player_;
	Color color_;
	std::mt19937 rng_;
	std::uniform_int_distribution<int> x_dist_;
	std::uniform_int_distribution<int> y_dist_;
	std::uniform_int_distribution<int> rand_color_;
};

