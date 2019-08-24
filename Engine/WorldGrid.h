#pragma once
#include "GraphicalEntity.h"
#include "Graphics.h"
#include "Location.h"
#include "ColorManager.h"
#include <random>


class WorldGrid : public GraphicalEntity
{
public:
	static constexpr int CELL_SIZE = 10;
	static constexpr int WIDTH = 20;
	static constexpr int HEIGHT = 20;

	using GraphicalEntity::GraphicalEntity;

	void WithColorManager(ColorManager& colors);
	void DrawCell(const Location& loc, const Color c);
	void DrawCell(const Location& loc, const Location& offset, const Color c);
	void DrawFilledCell(const Location& loc, const Color c);
	void DrawFilledCell(const Location& loc, const Location& offset, const Color c);
	void DrawFg(const unsigned int frame_counter = 0);
	void DrawBg(const unsigned int frame_counter = 0);
	void Draw(const unsigned int frame_counter = 0) override {} ;
	bool CheckInScreenBounds(const Location& loc);
	bool CheckInGridBounds(const Location& loc);

private:
	ColorManager* colors_ = nullptr;
};

