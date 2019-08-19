#pragma once

#include "Graphics.h"
#include "Player.h"

//if (n_segments_ == 5) {
//	head_color_ = Colors::LightBlue;
//	body_color_ = Colors::Purple;
//	_ReColor(head_color_, body_color_);
//}
//else if (n_segments_ == 7) {
//	head_color_ = Colors::Yellow;
//	body_color_ = Colors::Red;
//	_ReColor(head_color_, body_color_);
//}
//else if (n_segments_ == 9) {
//	head_color_ = Colors::Cyan;
//	body_color_ = Colors::Teal;
//	_ReColor(head_color_, body_color_);
//}
//else if (n_segments_ == 11) {
//	head_color_ = Colors::Pink;
//	body_color_ = Colors::LightGreen;
//	_ReColor(head_color_, body_color_);
//}

class ColorManager
{
public:
	explicit ColorManager(const int level = 0);
	ColorManager(const ColorManager& copy) = delete;
	ColorManager& operator=(const ColorManager& rhs) = delete;
	void WithPlayer(Player& player);
	void UpdateLevel();
	Color GetSnakeHead() const;
	Color GetSnakeBody() const;
	Color GetSnakeDeadHead() const;
	Color GetSnakeDeadBody() const;
	Color GetTarget() const;
	Color GetProgressBar() const;
	Color GetProgressFrame() const;
	Color GetWorldGridFrame() const;

private:
	static constexpr int N_LEVELS = 10;
	static constexpr int level_to_length_map[N_LEVELS] {
		3, 10, 20, 30, 40, 50, 60, 70, 80, 90
	};

	int		level_	{ 0 };
	Player*	player_	{ nullptr };

	typedef struct {
		Color world_grid;
		Color snake_head;
		Color snake_body;
		Color snake_dead_head;
		Color snake_dead_body;
		Color target;
		Color progress_bar;
		Color progress_frame;
		Color worldgrid_frame;
	} ColorMap;

	ColorMap colors_[N_LEVELS] {
		{
			{ 19, 19, 57 },
			Colors::Yellow,
			Colors::LightGreen,
			Colors::White,
			Colors::Gray,
			Colors::Orange,
			Colors::Green,
			Colors::Gray,
			Colors::LightGreen
		},
		{
			{ 19, 19, 57 },
			Colors::Yellow,
			Colors::LightGreen,
			Colors::White,
			Colors::Gray,
			Colors::Orange,
			Colors::Green,
			Colors::Gray,
			Colors::LightGreen
		},
		{
			{ 19, 19, 57 },
			Colors::Yellow,
			Colors::LightGreen,
			Colors::White,
			Colors::Gray,
			Colors::Orange,
			Colors::Green,
			Colors::Gray,
			Colors::LightGreen
		}
	};
};

