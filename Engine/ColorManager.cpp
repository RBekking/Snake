#include "ColorManager.h"

ColorManager::ColorManager(const int level) :
	level_(level)
{
}

void ColorManager::WithPlayer(Player& player)
{
	player_ = &player;
}

Color ColorManager::GetSnakeHead() const
{
	return Color();
}

Color ColorManager::GetSnakeBody() const
{
	return Color();
}

Color ColorManager::GetSnakeDeadHead() const
{
	return Color();
}

Color ColorManager::GetSnakeDeadBody() const
{
	return Color();
}

Color ColorManager::GetTarget() const
{
	return Color();
}

Color ColorManager::GetProgressBar() const
{
	return Color();
}

Color ColorManager::GetProgressFrame() const
{
	return Color();
}

Color ColorManager::GetWorldGridFrame() const
{
	return Color();
}
