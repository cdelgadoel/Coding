#pragma once

struct math2DVector
{
    int x, y;

    // Constructors
    math2DVector();
    math2DVector(int x_val, int y_val);
    math2DVector(const math2DVector &other);

    // Operations
    math2DVector operator+(const math2DVector &other) const;
    math2DVector operator-(const math2DVector &other) const;
    bool operator==(const math2DVector &other) const;
};