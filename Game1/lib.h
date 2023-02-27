#include <cmath>
#include <iostream>


#pragma once
class vec2
{
public:
	vec2() : x(0.), y(0.) {}
	vec2(double a, double b) : x(a), y(b) {}

	double getX() { return x; }
	double getY() { return y; }

	void setX(double a) { x = a; }
	void setY(double b) { y = b; }

	double length() { return sqrt(x * x + y * y); }

	void normalize();

	void operator+=(vec2& v1);
	vec2 operator+(double a) const;
	vec2 operator*(double a) const;
	vec2 operator/(double a) const;
	vec2 operator+ (vec2& v1) const;
	vec2 operator- (vec2& v1) const;
	vec2 operator* (vec2& v1) const;

private:
	double x, y;
};

