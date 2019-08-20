#pragma once

#include "Graphics.h"

class ColorManager
{
public:
	explicit ColorManager(const int level = 0);
	ColorManager(const ColorManager& copy) = delete;
	ColorManager& operator=(const ColorManager& rhs) = delete;
	void  CheckPlayerLength(const int player_length);
	bool  LevelUpdated();
	Color GetWorldGrid() const;
	Color GetSnakeHead() const;
	Color GetSnakeBody() const;
	Color GetSnakeDeadHead() const;
	Color GetSnakeDeadBody() const;
	Color GetTarget() const;
	Color GetProgressBar() const;
	Color GetProgressFrame() const;
	Color GetWorldGridFrame() const;

private:
	static constexpr int N_LEVELS = 5;
	static constexpr int level_to_length_map[N_LEVELS] {
		3, 5, 7, 9, 11
	};

	int		level_;
	bool	updated_;

	typedef struct {
		Color world_grid;
		Color worldgrid_frame;
		Color snake_head;
		Color snake_body;
		Color snake_dead_head;
		Color snake_dead_body;
		Color target;
		Color progress_bar;
		Color progress_frame;
	} ColorMap;

	ColorMap colors_[N_LEVELS] {
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
		}
	};
};

