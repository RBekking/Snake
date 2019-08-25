#pragma once

#include "Location.h"
#include "WorldGrid.h"
#include "Graphics.h"

namespace musical {

	typedef enum class pitch {
		SILENT = 0,
		C4,						// Middle C
		E4,
		G4
	} musical_pitch_t;

	class Note {
	public:
		Note();
		Note(const ::Location& location, const musical_pitch_t pitch, const Color& color, const Color& hit_color);
		void Reset();
		void Draw(const ::Location& offset, WorldGrid& grid);
		::Location RelativeLocation() const;
		bool IsHit() const;
		bool IsOnNote(const ::Location& location);

	private:
		bool			hit_;
		musical_pitch_t pitch_;
		Color			color_;
		Color			hit_color_;
		::Location		location_;
	};

	extern Note note_c4;
	extern Note note_e4;
	extern Note note_g4;
}