#pragma once

#include "Graphics.h"
#include "Location.h"

class GraphicalEntity
{
public:
	GraphicalEntity();
	explicit GraphicalEntity(const Location& location);

	void WithGraphics(Graphics& gfx);
	virtual void Draw(const unsigned int frame_counter = 0);
	Location GetLocation() const;

protected:
	Graphics* gfx_{ nullptr };
	Location location_{ 50, 40 };
};

