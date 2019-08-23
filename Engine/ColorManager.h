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
	static constexpr int N_LEVELS = 6;
	static constexpr int level_to_length_map[N_LEVELS] {
		3, 5, 8, 11, 14, 17
	};

	int		level_;
	bool	updated_;

	struct {
		Color world_grid;
		Color worldgrid_frame;
		Color snake_head;
		Color snake_body;
		Color snake_dead_head;
		Color snake_dead_body;
		Color target;
		Color progress_bar;
		Color progress_frame;
	} colors_[N_LEVELS];
};

