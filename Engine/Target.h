#pragma once

#include "GridEntity.h"
#include "Location.h"
#include "WorldGrid.h"
#include "Graphics.h"
#include "Player.h"

class Target : public GridEntity
{
public:
	Target();
	explicit Target(const Location& loc);
	void WithRNG(std::mt19937& rng);
	void WithPlayer(Player& player);
	void Draw(const int frame_number = 0) override ;
	void HandleCollection();
	void Reposition();

private:
	Player* player_;
	Color color_;
	std::mt19937 rng_;
	std::uniform_int_distribution<int> x_dist_;
	std::uniform_int_distribution<int> y_dist_;
	std::uniform_int_distribution<int> rand_color_;
};

