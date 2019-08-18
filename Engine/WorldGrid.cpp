#include "WorldGrid.h"
#include "Location.h"
#include "Graphics.h"

void WorldGrid::DrawCell(const Location& loc, const Color c)
{
	if (CheckInGridBounds(loc)) {
		Location new_loc{ location_.GetX() + (loc.GetX() * CELL_SIZE), 
						  location_.GetY() + (loc.GetY() * CELL_SIZE) };
		gfx_->DrawRectangleDim(new_loc.GetX(), new_loc.GetY(), CELL_SIZE, CELL_SIZE, c);
	}
}

void WorldGrid::DrawCell(const Location& loc, const Location& offset, const Color c)
{
	int x = (location_.GetX() + (loc.GetX() * CELL_SIZE)) + offset.GetX();
	int y = (location_.GetY() + (loc.GetY() * CELL_SIZE)) + offset.GetY();
	if (CheckInScreenBounds(Location(x, y))) {
		gfx_->DrawRectangleDim(x, y, CELL_SIZE, CELL_SIZE, c);
	}
}

void WorldGrid::DrawFilledCell(const Location& loc, const Color c)
{
	if (CheckInGridBounds(loc)) {
		Location new_loc{ location_.GetX() + (loc.GetX() * CELL_SIZE),
						  location_.GetY() + (loc.GetY() * CELL_SIZE) };
		gfx_->DrawFilledRectDim(new_loc.GetX(), new_loc.GetY(), CELL_SIZE, CELL_SIZE, c);
	}
}

void WorldGrid::DrawFilledCell(const Location& loc, const Location& offset, const Color c)
{
	int x = (location_.GetX() + (loc.GetX() * CELL_SIZE)) + offset.GetX();
	int y = (location_.GetY() + (loc.GetY() * CELL_SIZE)) + offset.GetY();
	if (CheckInScreenBounds(Location(x, y))) {
		gfx_->DrawFilledRectDim(x, y, CELL_SIZE, CELL_SIZE, c);
	}
}

void WorldGrid::DrawFg(const unsigned int frame_counter)
{
	unsigned char c;
	for (int i = 0; i < 5; ++i) {
		c = static_cast<unsigned char>((255 / 10) * i);
		gfx_->DrawRectangleDim(location_.GetX() - i, location_.GetY() - i, (WIDTH * CELL_SIZE) + (2 * i), (HEIGHT * CELL_SIZE) + (2 * i), Color{ c, c, c });
	}
	for (int i = 5; i < 10; ++i) {
		c = static_cast<unsigned char>((255 / 10) * (10 - i));
		gfx_->DrawRectangleDim(location_.GetX() - i, location_.GetY() - i, (WIDTH * CELL_SIZE) + (2 * i), (HEIGHT * CELL_SIZE) + (2 * i), Color{ c, c, c });
	}
}

void WorldGrid::DrawBg(const unsigned int frame_counter)
{
	gfx_->DrawFilledRectDim(location_.GetX() + 1, location_.GetY() + 1, (WIDTH * CELL_SIZE) - 2, (HEIGHT * CELL_SIZE) - 2, Color{ 19, 19, 57 });
}

bool WorldGrid::CheckInScreenBounds(const Location& loc)
{
	int x = loc.GetX();
	int y = loc.GetY();
	return (x >= location_.GetX()) && 
		   (y >= location_.GetY()) && 
		   (x < (location_.GetX() + (WIDTH * CELL_SIZE))) && 
		   (y < (location_.GetY() + (HEIGHT * CELL_SIZE)));
}

bool WorldGrid::CheckInGridBounds(const Location& loc)
{
	int x = loc.GetX();
	int y = loc.GetY();
	return (x >= 0) && (y >= 0) && (x < WIDTH) && (y < HEIGHT);
}
