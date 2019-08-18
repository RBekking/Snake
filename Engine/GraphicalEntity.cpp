#include "GraphicalEntity.h"

GraphicalEntity::GraphicalEntity() :
	GraphicalEntity(Location{ 0,0 })
{
}

GraphicalEntity::GraphicalEntity(const Location& location) :
	location_(location)
{
}

void GraphicalEntity::WithGraphics(Graphics& gfx)
{
	gfx_ = &gfx;
}

void GraphicalEntity::Draw(const unsigned int frame_counter)
{
}

Location GraphicalEntity::GetLocation() const
{
	return location_;
}
