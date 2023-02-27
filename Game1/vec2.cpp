#include "lib.h"

void vec2::operator+=(vec2& v1)
{
    this->x += v1.getX();
    this->y += v1.getY();
}

vec2 vec2::operator+(double a) const
{
    return vec2(x + a, y + a);
}

vec2 vec2::operator*(double a) const
{
    return vec2(x * a, y * a);
}

vec2 vec2::operator/(double a) const
{
    return vec2(x / a, y / a);
}

vec2 vec2::operator+(vec2& v1) const
{
    return vec2(x+v1.getX(), y+v1.getY());
}

vec2 vec2::operator-(vec2& v1) const
{
    return vec2(x - v1.getX(), y - v1.getY());
}

vec2 vec2::operator*(vec2& v1) const
{
    return vec2(x * v1.getX(), y * v1.getY());
}


void vec2::normalize() {
    int n = length();
    *this = *this / n;
}
