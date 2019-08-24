#pragma once

#include "Location.h"
#include "WorldGrid.h"
#include "Note.h"

namespace musical {

	class Chord {
	public:
		Chord();
		Chord(const Location& location);
		void Reset();
		void SetLocation(const Location& location);
		void AddNote(Note& note);
		void Draw(WorldGrid& grid);
		Location Dimensions() const;
		bool IsOnChord(const Location& location);
		bool IsCleared() const;

	private:
		static constexpr unsigned int MAX_N_NOTES = 7;
		unsigned int width_;
		unsigned int height_;
		unsigned int n_notes_;
		Note		 notes_[MAX_N_NOTES];
		Location	 location_;
	};

}