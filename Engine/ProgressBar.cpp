#include "ProgressBar.h"

void ProgressBar::WithPlayer(Player& player)
{
	player_ = &player;
}

void ProgressBar::Draw(const unsigned int frame_count)
{
	gfx_->DrawRectangleDim(location_.GetX(), location_.GetY(), 
						   WorldGrid::WIDTH * WorldGrid::CELL_SIZE, 
		                   WorldGrid::CELL_SIZE, 
						   Colors::Gray);
	int max_bar_width = WorldGrid::WIDTH * WorldGrid::CELL_SIZE;
	int bar_width = (player_->GetLength() * (max_bar_width / Player::N_SEGMENTS_MAX)) - 2;
	if (bar_width < 1) {
		bar_width = 1;
	}
	gfx_->DrawFilledRectDim(location_.GetX() + 1, location_.GetY() + 1, bar_width, WorldGrid::CELL_SIZE - 2, Colors::Green);
}
