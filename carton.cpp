#include "carton.h"
#include <iostream>

//Conditionally sets private data member - length_.
void Carton::SetLength(float length)
{
    if (length <=0)
        {
        length_ = 1;
        }
    else
        {
        length_ = length;
        }
}

//Conditionally sets private data member - width_.
void Carton::SetWidth(float width)
{
    if (width <=0)
        {
        width_ = 1;
        }
    else
        {
        width_ = width;
        }
}

//Conditionally sets private data member - height_.
void Carton::SetHeight(float height)
{
    if (height <=0)
        {
        height_ = 1;
        }
    else
        {
        height_ = height;
        }
}

// Constructor
Carton::Carton(float length, float width, float height)
{
    SetLength(length);
    SetWidth(width);
    SetHeight(height);
}

//Destructor
Carton::~Carton() {}

// formats private data members
void Carton::WriteData(std::ostream &out) const
{
    auto CartonObject = Carton();
    out << length_ << ' '
    << width_ << ' '
    << height_ << std::endl;
}

//formats private data members
void Carton::WriteCarton(std::ostream &out) const
{
    auto CartonObject = Carton();
    out << "A carton with length " << length_
    << ',' << " width " << width_ << ','
    << " and height " << height_ << '.';
}

// Multiplies each private data member together.
float Carton::Volume() const
{
    float VolCalc = length_ * width_ * height_;
    return VolCalc;
}

