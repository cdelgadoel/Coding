#include "math2DVector.h"
#include <cmath>

// Empty constructor
math2DVector::math2DVector() : x(0), y(0) {}

// Parameterized constructor
math2DVector::math2DVector(int x_val, int y_val) : x(x_val), y(y_val) {}

// Copy constructor
math2DVector::math2DVector(const math2DVector &other) : x(other.x), y(other.y) {}

// Addition operator
math2DVector math2DVector::operator+(const math2DVector &other) const
{
    return math2DVector(x + other.x, y + other.y);
}

// Substraction operator
math2DVector math2DVector::operator-(const math2DVector &other) const
{
    return math2DVector(x - other.x, y - other.y);
}

bool math2DVector::operator==(const math2DVector &other) const
{
    return x == other.x && y == other.y;
}
