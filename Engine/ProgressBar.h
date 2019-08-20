#pragma once

#include "GraphicalEntity.h"
#include "WorldGrid.h"
#include "Player.h"
#include "ColorManager.h"

class ProgressBar : public GraphicalEntity
{
public:
	explicit ProgressBar(const Location& location);
	void WithPlayer(Player& player);
	void WithColorManager(ColorManager& colors);
	void Draw(const unsigned int frame_count) override;

private:
	Player* player_;
	ColorManager* colors_;
	double	percentage_;
};

