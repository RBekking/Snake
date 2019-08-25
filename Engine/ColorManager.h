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
	Color GetWorldGridFrame() const;	
	Color GetSnakeHead() const;
	Color GetSnakeBody() const;
	Color GetSnakeDeadHead() const;
	Color GetSnakeDeadBody() const;
	Color GetTargetNote(const int note) const;
	Color GetTargetNoteHit(const int note) const;
	Color GetProgressBar() const;
	Color GetProgressFrame() const;

private:
	static constexpr int N_LEVELS = 6;
	static constexpr int level_to_length_map[N_LEVELS] {
		3, 5, 8, 11, 14, 17
	};

	int		level_;
	bool	updated_;

	const struct world_grid_struct {
		Color grid;
		Color frame;
	} world_grid_colors_[N_LEVELS];

	const struct player_colors_struct{
		Color head;
		Color body;
		Color dead_head;
		Color dead_body;
	} player_colors_[N_LEVELS];

	const struct target_colors_struct {
		Color notes[3];
		Color notes_hit[3];
	} target_colors_[N_LEVELS];

	const struct progressbar_colors_struct {
		Color bar;
		Color frame;
	} progressbar_colors_[N_LEVELS];
};

