#include "Location.h"

Location::Location() :
	x_(0),
	y_(0)
{
}

Location::Location(const int x, const int y) :
	x_(x),
	y_(y)
{
}

Location& Location::operator+=(const Location& rhs)
{
	x_ += rhs.GetX();
	y_ += rhs.GetY();
	return *this;
}

int Location::GetX() const
{
	return x_;
}

int Location::GetY() const
{
	return y_;
}

bool operator==(const Location& lhs, const Location& rhs)
{
	return (lhs.GetX() == rhs.GetX()) && (lhs.GetY() == rhs.GetY());
}

bool operator!=(const Location& lhs, const Location& rhs)
{
	return (lhs.GetX() != rhs.GetX()) || (lhs.GetY() != rhs.GetY());
}

Location operator+(const Location& lhs, const Location& rhs)
{
	return Location(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}

Location operator-(const Location& lhs, const Location& rhs)
{
	return Location(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY());
}

Location operator-(const Location& expr)
{
	return Location(-expr.GetX(), -expr.GetY());
}

Location operator*(const Location& lhs, const int& rhs)
{
	return Location(lhs.GetX() * rhs, lhs.GetY() * rhs);
}

Location operator*(const int& lhs, const Location& rhs)
{
	return Location(rhs.GetX() * lhs, rhs.GetY() * lhs);
}
