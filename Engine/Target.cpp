#include "Target.h"

Target::Target() :
	Target(Location{ 0, 0 })
{
}

Target::Target(const Location& loc) :
	GridEntity(loc),
	player_(nullptr),
	colors_(nullptr),
	rng_(std::random_device()()),
	x_dist_(std::uniform_int_distribution<int>(0, WorldGrid::WIDTH - 1)),
	y_dist_(std::uniform_int_distribution<int>(0, WorldGrid::HEIGHT - 1)),
	rand_color_(std::uniform_int_distribution<int>(0, 255))
{
}

void Target::WithRNG(std::mt19937& rng)
{
	rng_ = rng;
}

void Target::WithPlayer(Player& player)
{
	player_ = &player;
}

void Target::WithColorManager(ColorManager& colors)
{
	colors_ = &colors;
}

void Target::Draw(const int frame_number)
{
	if (Player::N_SEGMENTS_MAX == player_->GetLength()) {
		grid_->DrawFilledCell(location_, Color(rand_color_(rng_), rand_color_(rng_), rand_color_(rng_)));
	}
	else {
		grid_->DrawFilledCell(location_, colors_->GetTarget());
	}
}

void Target::HandleCollection()
{
	// TODO BUG sometimes GetLocation != location although we did hit the target.
	if (player_->GetLocation() == location_) {
		if ((Player::N_SEGMENTS_MAX) == player_->GetLength()) {
			// Won the game!
			Reposition();
		}
		else {
			player_->Grow();
			Reposition();
		}
	}
	else {
		// Do nothing here
	}
}

void Target::Reposition()
{
	rng_ = std::mt19937(std::random_device()());
	do {
		location_ = Location{ x_dist_(rng_), y_dist_(rng_) };
	} while (player_->LocationIsOnSnake(location_));
}
