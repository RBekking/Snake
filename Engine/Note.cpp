#include "Note.h"

namespace musical {
	Note note_c4{ Note(Location(0, 0), pitch::C4, Color(Colors::LightBlue)) };
	Note note_e4{ Note(Location(1, 1), pitch::E4, Color(Colors::Orange)) };
	Note note_g4{ Note(Location(2, 0), pitch::G4, Color(Colors::Magenta)) };

	Note::Note() :
		hit_(false),
		pitch_(pitch::SILENT),
		color_(Colors::Black),
		location_(Location(0, 0))
	{
	}

	Note::Note(const Location& location, const musical_pitch_t pitch, const Color& color) :
		hit_(false),
		pitch_(pitch),
		color_(color),
		location_(location)
	{
	}

	void Note::Reset()
	{
		hit_ = false;
	}

	void Note::Draw(const Location& offset, WorldGrid& grid)
	{
		grid.DrawFilledCell(location_ + offset, color_);
	}

	Location Note::RelativeLocation() const
	{
		return location_;
	}

	bool Note::IsHit() const
	{
		return hit_;
	}

	bool Note::IsOnNote(const Location& location)
	{
		if (location == location_) {
			if (!hit_) {
				hit_ = true;
				PlaySound(TEXT("sounds/click.wav"), NULL, SND_ASYNC);
			}
			return true;
		}
		return false;
	}

}