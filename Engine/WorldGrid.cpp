#include "WorldGrid.h"

void WorldGrid::WithColorManager(ColorManager& colors)
{
	colors_ = &colors;
}

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
	double c;
	Color new_color;

	for (int i = 0; i < 5; ++i) {
		c = static_cast<double>(i) / 10;
		new_color = Colors::DimColor(colors_->GetWorldGridFrame(), c);
		gfx_->DrawRectangleDim(location_.GetX() - i, location_.GetY() - i, (WIDTH * CELL_SIZE) + (2 * i), (HEIGHT * CELL_SIZE) + (2 * i), new_color);
	}
	for (int i = 5; i < 10; ++i) {
		c = static_cast<double>(10 - i) / 10;
		new_color = Colors::DimColor(colors_->GetWorldGridFrame(), c);
		gfx_->DrawRectangleDim(location_.GetX() - i, location_.GetY() - i, (WIDTH * CELL_SIZE) + (2 * i), (HEIGHT * CELL_SIZE) + (2 * i), new_color);
	}
}

void WorldGrid::DrawBg(const unsigned int frame_counter)
{
	gfx_->DrawFilledRectDim(location_.GetX() + 1, location_.GetY() + 1, (WIDTH * CELL_SIZE) - 2, (HEIGHT * CELL_SIZE) - 2, colors_->GetWorldGrid());
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
