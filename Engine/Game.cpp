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
	gfx(wnd)
{
	colormgr.UpdateLevel(0);
	grid.WithGraphics(gfx);
	player.WithGrid(grid);
	player.WithColorManager(colormgr);
	player.WithRNG(rng);
	player.Reset(Location{PLAYER_INITIAL_X, PLAYER_INITIAL_Y});

	for (int i = 0; i < N_TARGETS; ++i) {
		targets[i].WithGrid(grid);
		targets[i].WithRNG(rng);
		targets[i].WithPlayer(player);
		targets[i].Reposition();
	}

	progress_bar.WithGraphics(gfx);
	progress_bar.WithPlayer(player);
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

	if (player.IsDead()) {
		player.Decay(frame_counter, SNAKE_DEATH_FRAMES);
		if (frame_counter > SNAKE_DEATH_FRAMES) {
			frame_counter = 0;
			RestartGame();
		}
	} 
	else {
		if (frame_counter >= SNAKE_MOVE_RATE) {
			frame_counter = 0;
			player.MoveBy(in_buff.Get());
			for (int i = 0; i < N_TARGETS; ++i) {
				targets[i].HandleCollection();
			}
		}
	}
	++frame_counter;
}

void Game::ComposeFrame()
{	
	grid.DrawBg();
	player.Draw(frame_counter);
	for (int i = 0; i < N_TARGETS; ++i) {
		targets[i].Draw(frame_counter);
	}
	grid.DrawFg();
	progress_bar.Draw(frame_counter);
}

void Game::HandleInput()
{
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		in_buff.Push(Location(0, -1));
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		in_buff.Push(Location(0, 1));
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		in_buff.Push(Location(-1, 0));
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		in_buff.Push(Location(1, 0));
	}
}

void Game::RestartGame()
{
	colormgr.UpdateLevel(0);
	player.Reset(Location{ PLAYER_INITIAL_X, PLAYER_INITIAL_Y});
	for (int i = 0; i < N_TARGETS; ++i) {
		targets[i].Reposition();
	}
	in_buff.Reset(Location{1, 0});
}
