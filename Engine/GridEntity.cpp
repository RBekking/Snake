#include "GridEntity.h"

GridEntity::GridEntity() :
	GridEntity(Location{0, 0})
{
}

GridEntity::GridEntity(const Location& location) :
	location_(location),
	grid_(nullptr)
{
}

void GridEntity::WithGrid(WorldGrid& grid)
{
	grid_ = &grid;
}
