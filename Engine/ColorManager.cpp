#include "ColorManager.h"

ColorManager::ColorManager(const int level) :
	level_(level),
	updated_(false),
	colors_{
		{
			{ 10, 10, 10},
			Colors::White,
			Colors::White,
			Colors::LightBlue,
			Colors::White,
			Colors::Gray,
			Colors::Magenta,
			Colors::LightBlue,
			Colors::Gray,
		},
		{
			{ 20, 20, 20},
			Colors::LightGreen,
			Colors::LightGreen,
			Colors::Pink,
			Colors::White,
			Colors::Gray,
			Colors::Purple,
			Colors::Pink,
			Colors::Gray,
		},
		{
			{ 30, 30, 30},
			Colors::Yellow,
			Colors::Yellow,
			Colors::Green,
			Colors::White,
			Colors::Gray,
			Colors::Red,
			Colors::Green,
			Colors::Gray,
		},
		{
			{ 40, 40, 40},
			Colors::Orange,
			Colors::Orange,
			Colors::LightBrown,
			Colors::White,
			Colors::Gray,
			Colors::Yellow,
			Colors::LightBrown,
			Colors::Gray,
		},
		{
			{ 50, 50, 50},
			Colors::Purple,
			Colors::Purple,
			Colors::LightBlue,
			Colors::White,
			Colors::Gray,
			Colors::Gray,
			Colors::LightBlue,
			Colors::Gray,
		},
		{
			{ 60, 60, 60},
			Colors::LightBrown,
			Colors::LightBrown,
			Colors::Green,
			Colors::White,
			Colors::Gray,
			Colors::Magenta,
			Colors::Green,
			Colors::Gray,
		}
}
{
}

void ColorManager::CheckPlayerLength(const int player_length)
{
	for (int i = 0; i < N_LEVELS; ++i) {
		if ((player_length == level_to_length_map[i])) {
			if (i > 0) {
				level_ = i;
				updated_ = true;
				return;
			}
			else {
				level_ = 0;
				updated_ = false;
				return;
			}
		}
	}

	return;
}

bool ColorManager::LevelUpdated()
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
