#pragma once

#include "GraphicalEntity.h"
#include "Location.h"
#include "Graphics.h"
#include "WorldGrid.h"
#include "Player.h"

class ProgressBar : public GraphicalEntity
{
public:
	using GraphicalEntity::GraphicalEntity;
	void WithPlayer(Player& player);
	void Draw(const unsigned int frame_count) override;

private:
	Player* player_		{ nullptr };
	double	percentage_ { 10.0 };
};

