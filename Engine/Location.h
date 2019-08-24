#pragma once
class Location
{
public:
	Location();
	Location(const int x, const int y);
	Location& operator+=(const Location& rhs);
	Location& operator-=(const Location& rhs);

	int GetX() const;
	int GetY() const;

private:
	int x_;
	int y_;
};

bool operator==(const Location& lhs, const Location& rhs);     // if (a == b) {};
bool operator!=(const Location& lhs, const Location& rhs);     // if (a != b) {};
Location operator+(const Location& lhs, const Location& rhs);  // Location q = (a + b);
Location operator-(const Location& lhs, const Location& rhs);  // Location q = (a - b); 
Location operator-(const Location& expr);                      // Location q = -a;
Location operator*(const Location& lhs, const int& rhs);       // Location q = (a * 4);
Location operator*(const int& lhs, const Location& rhs);       // location q = (2 * b);

