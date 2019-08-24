#include "Chord.h"

namespace musical {

	Chord::Chord() :
		width_{ 0 },
		height_{ 0 },
		n_notes_{ 0 },
		notes_{ Note(),
				Note(),
				Note() },
		location_{ Location(5,5) }
	{
	}

	Chord::Chord(const Location& location) :
		width_{ 0 },
		height_{ 0 },
		n_notes_{ 0 },
		notes_{ note_c4,
				note_e4,
				note_g4 },
		location_{ location }
	{
	}

	void Chord::Reset()
	{
		for (unsigned int i = 0; i < n_notes_; ++i) {
			notes_[i].Reset();
		}
	}

	void Chord::SetLocation(const Location& location)
	{
		location_ = location;
	}

	void Chord::AddNote(Note& note)
	{
		if (n_notes_ < MAX_N_NOTES) {
			unsigned int new_width  = note.RelativeLocation().GetX() + 1;
			unsigned int new_height = note.RelativeLocation().GetY() + 1;

			if (new_width > width_) {
				width_ = new_width;
			}

			if (new_height > height_) {
				height_ = new_height;
			}

			notes_[n_notes_] = note;
			++n_notes_;
		}
	}

	void Chord::Draw(WorldGrid& grid)
	{
		for (int i = 0; i < 3; ++i) {
			notes_[i].Draw(location_, grid);
		}
	}

	Location Chord::Dimensions() const
	{
		return Location(width_, height_);
	}

	bool Chord::IsOnChord(const Location& location)
	{
		for (unsigned int i = 0; i < n_notes_; ++i) {
			if (notes_[i].IsOnNote(location - location_)) {
				return true;
			}
		}

		return false;
	}

	bool Chord::IsCleared() const
	{
		bool cleared = true;

		for (unsigned int i = 0; i < n_notes_; ++i) {
			cleared = cleared && notes_[i].IsHit();
		}

		return cleared;
	}

}