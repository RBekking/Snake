#pragma once

#include "WorldGrid.h"
#include "Location.h"

class GridEntity
{
public:
	GridEntity();
	explicit GridEntity(const Location& location);
	virtual void Draw(const int frame_number = 0) = 0;
	void WithGrid(WorldGrid& grid);

protected:
	Location	location_;
	WorldGrid*	grid_;
};

