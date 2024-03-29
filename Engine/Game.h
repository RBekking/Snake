/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "WorldGrid.h"
#include "Player.h"
#include "Target.h"
#include "Location.h"
#include "InputBuffer.h"
#include "ProgressBar.h"
#include <random>

class Game
{
public:

	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void HandleInput();
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	static constexpr unsigned int SNAKE_MOVE_RATE = WorldGrid::CELL_SIZE;
	static constexpr unsigned int SNAKE_DEATH_FRAMES = 100;
	static constexpr int PLAYER_INITIAL_X = 0;
	static constexpr int PLAYER_INITIAL_Y = 0;
	static constexpr int N_TARGETS = 1;
	void RestartGame();

	WorldGrid    grid			{ Location{150, 60} };
	ProgressBar  progress_bar	{ Location{150, 40} };
	Player       player			{ Location{PLAYER_INITIAL_X, PLAYER_INITIAL_Y} };
	Target		 targets[N_TARGETS];
	InputBuffer	 in_buff		{ Location{1, 0} };
	int          frame_counter  { 0 };
	std::mt19937 rng            { std::random_device()() };
};