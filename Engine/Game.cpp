/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	grid_(Location{ 150, 60 }),
	progress_bar_(Location{ 150, 40 }),
	in_buff_(Location{ 1, 0 }),
	colormgr_(0),
	frame_counter_(0),
	rng_(std::random_device()())
{
	grid_.WithGraphics(gfx);
	grid_.WithColorManager(colormgr_);
	player_.WithGrid(grid_);
	player_.WithColorManager(colormgr_);
	player_.WithRNG(rng_);
	player_.Reset(Location{PLAYER_INITIAL_X, PLAYER_INITIAL_Y});

	for (int i = 0; i < N_TARGETS; ++i) {
		targets_[i].WithGrid(grid_);
		targets_[i].WithColorManager(colormgr_);
		targets_[i].WithRNG(rng_);
		targets_[i].WithPlayer(player_);
		targets_[i].Reposition();
	}

	progress_bar_.WithColorManager(colormgr_);
	progress_bar_.WithGraphics(gfx);
	progress_bar_.WithPlayer(player_);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	HandleInput();

	if (player_.IsDead()) {
		player_.Decay(frame_counter_, SNAKE_DEATH_FRAMES);
		if (frame_counter_ > SNAKE_DEATH_FRAMES) {
			frame_counter_ = 0;
			RestartGame();
		}
	} 
	else {
		if (frame_counter_ >= SNAKE_MOVE_RATE) {
			frame_counter_ = 0;
			player_.MoveBy(in_buff_.Get());
			for (int i = 0; i < N_TARGETS; ++i) {
				targets_[i].HandleCollection();
			}
		}
	}
	++frame_counter_;
}

void Game::ComposeFrame()
{	
	grid_.DrawBg();
	player_.Draw(frame_counter_);
	for (int i = 0; i < N_TARGETS; ++i) {
		targets_[i].Draw(frame_counter_);
	}
	grid_.DrawFg();
	progress_bar_.Draw(frame_counter_);
}

void Game::HandleInput()
{
	if (wnd.kbd.KeyIsPressed(VK_UP)) {		
		in_buff_.Push(Location(0, -1));
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		in_buff_.Push(Location(0, 1));
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		in_buff_.Push(Location(-1, 0));
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		in_buff_.Push(Location(1, 0));
	}
}

void Game::RestartGame()
{
	player_.Reset(Location{ PLAYER_INITIAL_X, PLAYER_INITIAL_Y });
	colormgr_.CheckPlayerLength(player_.GetLength());
	for (int i = 0; i < N_TARGETS; ++i) {
		targets_[i].Reposition();
	}
	in_buff_.Reset(Location(1, 0));
}
