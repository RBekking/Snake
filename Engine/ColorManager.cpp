#include "ColorManager.h"

ColorManager::ColorManager(const int level) :
	level_(level),
	updated_(false)
{
}

void ColorManager::UpdateLevel(const int player_length)
{
	for (int i = 0; i < N_LEVELS; ++i) {
		if (player_length == level_to_length_map[i]) {
			level_ = i;
			updated_ = true;
			return;
		}
	}

	return;
}

bool ColorManager::IsUpdated()
{
	bool ret_val = updated_;
	updated_ = false;

	return ret_val;
}

Color ColorManager::GetWorldGrid() const
{
	return colors_[level_].world_grid;
}

Color ColorManager::GetSnakeHead() const
{
	return colors_[level_].snake_head;
}

Color ColorManager::GetSnakeBody() const
{
	return colors_[level_].snake_body;
}

Color ColorManager::GetSnakeDeadHead() const
{
	return colors_[level_].snake_dead_head;
}

Color ColorManager::GetSnakeDeadBody() const
{
	return colors_[level_].snake_dead_body;
}

Color ColorManager::GetTarget() const
{
	return colors_[level_].target;
}

Color ColorManager::GetProgressBar() const
{
	return colors_[level_].progress_bar;
}

Color ColorManager::GetProgressFrame() const
{
	return colors_[level_].progress_frame;
}

Color ColorManager::GetWorldGridFrame() const
{
	return colors_[level_].worldgrid_frame;
}
