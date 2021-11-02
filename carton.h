#ifndef CARTON
#define CARTON
#include <iostream>
// Define class
class Carton
{
public:
    // constructors
    Carton() : width_(1.0), length_(1.0), height_(1.0) {}
    Carton(float length, float width, float height);

    // destructor
    ~Carton();

    // getters
    float GetLength() const {return length_;}
    float GetWidth() const {return width_;}
    float GetHeight() const {return height_;}

    // setters
    void SetLength(float length);
    void SetWidth(float width);
    void SetHeight(float height);

    // formatters
    void WriteData(std::ostream &out) const;
    void WriteCarton(std::ostream &out) const;

    // Calculation method
    float Volume() const;

//private variables
private:
    float length_;
    float width_;
    float height_;
};

#endif