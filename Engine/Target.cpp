#include "Target.h"

Target::Target() :
	Target(Location{ 0, 0 })
{
}

Target::Target(const Location& location) :
	location_(location),
	grid_(nullptr),
	player_(nullptr),
	colors_(nullptr),
	chord_(location),
	timer_(FrameTimer::infinity),
	rng_(std::random_device()()),
	x_dist_(std::uniform_int_distribution<int>(0, WorldGrid::WIDTH - 1)),
	y_dist_(std::uniform_int_distribution<int>(0, WorldGrid::HEIGHT - 1)),
	rand_color_(std::uniform_int_distribution<int>(0, 255))
{
	chord_.AddNote(musical::note_c4);
	chord_.AddNote(musical::note_e4);
	chord_.AddNote(musical::note_g4);
}

void Target::WithGrid(WorldGrid& grid)
{
	grid_ = &grid;
}

void Target::WithRNG(std::mt19937& rng)
{
	rng_ = rng;
}

void Target::WithPlayer(Player& player)
{
	player_ = &player;
}

void Target::WithColorManager(ColorManager& colors)
{
	colors_ = &colors;
}

void Target::Draw(const int frame_number)
{
	if (Player::N_SEGMENTS_MAX == player_->GetLength()) {
		grid_->DrawFilledCell(location_, Color(rand_color_(rng_), rand_color_(rng_), rand_color_(rng_)));
	}
	else {
		grid_->DrawFilledCell(location_, colors_->GetTarget());
	}
}

void Target::DrawChord(const int frame_number)
{
	chord_.Draw(*grid_);
}

void Target::HandleCollection()
{
	constexpr uint64_t TIMEOUT = WorldGrid::CELL_SIZE * 7;

	if (chord_.IsOnChord(player_->GetLocation())) {
		if (!timer_.IsSet()) {
			timer_.SetTimeout(TIMEOUT);
		}

		if (chord_.IsCleared()) {
			timer_.Clear();
			chord_.Reset();
			PlaySound(TEXT("sounds/eat_food.wav"), NULL, SND_ASYNC);

			if ((Player::N_SEGMENTS_MAX) == player_->GetLength()) {
				// Won the game!
				Reposition();
			}
			else {
				player_->Grow();
				Reposition();
			}
		}
	}
	else {
		// Do nothing here
	}
}

void Target::Update()
{
	timer_.Update();
	if (timer_.IsTimedOut()) {
		PlaySound(TEXT("sounds/chord_cancel.wav"), NULL, SND_ASYNC);
		timer_.Clear();
		chord_.Reset();
		Reposition();
	}
}

void Target::Reposition()
{
	constexpr auto MAX_RETRIES = 100UL;
	unsigned long retry_count = 0;
	rng_ = std::mt19937(std::random_device()());
	do {
		location_ = Location{ x_dist_(rng_), y_dist_(rng_) };

		if (!grid_->CheckInGridBounds(location_ + chord_.Dimensions())) {
			location_ -= chord_.Dimensions();
		}
		chord_.SetLocation(location_);

		++retry_count;
	} while ((retry_count < MAX_RETRIES) || (player_->LocationIsOnSnake(location_)));
}
