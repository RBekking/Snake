#include "ProgressBar.h"

ProgressBar::ProgressBar(const Location& location) :
	GraphicalEntity(location),
	player_(nullptr),
	colors_(nullptr),
	percentage_(0)
{
}

void ProgressBar::WithPlayer(Player& player)
{
	player_ = &player;
}

void ProgressBar::WithColorManager(ColorManager& colors)
{
	colors_ = &colors;
}

void ProgressBar::Draw(const unsigned int frame_count)
{
	gfx_->DrawRectangleDim(location_.GetX(), location_.GetY(), 
						   WorldGrid::WIDTH * WorldGrid::CELL_SIZE, 
		                   WorldGrid::CELL_SIZE, 
						   colors_->GetProgressFrame());
	int max_bar_width = WorldGrid::WIDTH * WorldGrid::CELL_SIZE;
	int bar_width = (player_->GetLength() * (max_bar_width / Player::N_SEGMENTS_MAX)) - 2;
	if (bar_width < 1) {
		bar_width = 1;
	}
	gfx_->DrawFilledRectDim(location_.GetX() + 1, location_.GetY() + 1, bar_width, WorldGrid::CELL_SIZE - 2, colors_->GetProgressBar());
}
