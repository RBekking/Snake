#include "ColorManager.h"

ColorManager::ColorManager(const int level) :
	level_(level),
	updated_(false),
	world_grid_colors_{ 
		{Color(43,43,43), Color(118,212,34)},
		{Color(43,43,43), Color(118,212,34)},
		{Color(43,43,43), Color(118,212,34)},
		{Color(43,43,43), Color(118,212,34)},
		{Color(43,43,43), Color(118,212,34)},
},
	player_colors_{ 
		{Color(237,92,38), Color(237,92,38), Colors::White, Colors::Gray},
		{Color(237,92,38), Color(237,92,38), Colors::White, Colors::Gray},
		{Color(237,92,38), Color(237,92,38), Colors::White, Colors::Gray},
		{Color(237,92,38), Color(237,92,38), Colors::White, Colors::Gray},
		{Color(237,92,38), Color(237,92,38), Colors::White, Colors::Gray},
	},
	target_colors_{ 
		{{{Color(118,212,34)},{Color(27,164,101)},{Color(237,92,38)}}, 
         {{Colors::White},    {Colors::White},    {Colors::White}}},
		{{{Color(118,212,34)},{Color(27,164,101)},{Color(237,92,38)}},
		 {{Colors::White},    {Colors::White},    {Colors::White}}},
		{{{Color(118,212,34)},{Color(27,164,101)},{Color(237,92,38)}},
		 {{Colors::White},    {Colors::White},    {Colors::White}}},
		{{{Color(118,212,34)},{Color(27,164,101)},{Color(237,92,38)}},
		 {{Colors::White},    {Colors::White},    {Colors::White}}},
		{{{Color(118,212,34)},{Color(27,164,101)},{Color(237,92,38)}},
		 {{Colors::White},    {Colors::White},    {Colors::White}}},
},
	progressbar_colors_{
		{Color(237,92,38), Color(237,92,38)},
		{Color(237,92,38), Color(237,92,38)},
		{Color(237,92,38), Color(237,92,38)},
		{Color(237,92,38), Color(237,92,38)},
		{Color(237,92,38), Color(237,92,38)},
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
	return world_grid_colors_[level_].grid;
}

Color ColorManager::GetWorldGridFrame() const
{
	return world_grid_colors_[level_].frame;
}

Color ColorManager::GetSnakeHead() const
{
	return player_colors_[level_].head;
}

Color ColorManager::GetSnakeBody() const
{
	return player_colors_[level_].body;
}

Color ColorManager::GetSnakeDeadHead() const
{
	return player_colors_[level_].dead_head;
}

Color ColorManager::GetSnakeDeadBody() const
{
	return player_colors_[level_].dead_body;
}

Color ColorManager::GetTargetNote(const int note) const
{
	return target_colors_[level_].notes[note];
}

Color ColorManager::GetTargetNoteHit(const int note) const
{
	return target_colors_[level_].notes_hit[note];
}

Color ColorManager::GetProgressBar() const
{
	return progressbar_colors_[level_].bar;
}

Color ColorManager::GetProgressFrame() const
{
	return progressbar_colors_[level_].frame;
}
