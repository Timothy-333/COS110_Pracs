#include "vector.h"
#include "arithmetic.h"
#include <iomanip>
#include <sstream>
using namespace std;
Vector::Vector(unsigned s): Arithmetic::Arithmetic()
{
    size = s;
    vector = new double[size];
    for (unsigned i = 0; i < size; i++) 
    {
        vector[i] = 0;
    }
}
Vector::Vector(const Vector& rhs) 
{
    size = rhs.size;
    vector = new double[size];
    for (unsigned i = 0; i < size; i++) 
    {
        vector[i] = rhs.vector[i];
    }
}
Vector::Vector(const double *temp, unsigned s)
{
    size = s;
    vector = new double[size];
    for(unsigned i = 0; i < size; i++)
    {
        vector[i] = temp[i];
    }
}
Vector::~Vector() 
{
    delete[] vector;
}
unsigned Vector::getSize() const
{
    return size;
}
void Vector::print() 
{
    for (unsigned i = 0; i < size; i++) 
    {
        cout << setprecision(3) << setw(10) << vector[i];
    }
    cout << endl;
}
void Vector::readFile(istream &infile) 
{
    for (unsigned i = 0; i < size; i++) 
    {
        infile >> vector[i];
    }
}
const Vector& Vector::operator=(const Vector& rhs) 
{
    if (this != &rhs) 
    {
        delete[] vector;
        size = rhs.size;
        vector = new double[size];
        for (unsigned i = 0; i < size; i++) 
        {
            vector[i] = rhs.vector[i];
        }
    }
    return *this;
}
double& Vector::operator[](const unsigned r)
{
    if(r < size)
        {return vector[r];}
    else
        {throw "Error: index out of range";}
}
const double& Vector::operator[](const unsigned r) const
{
    if(r < size)
        {return vector[r];}
    else
        {throw "Error: index out of range";}
}
Vector Vector::operator+(const Vector& rhs)
{
    if (size != rhs.size) 
    {
        throw "Error: adding vectors of different dimensionality";
    }
    else
    {
        Vector result(size);
        for (unsigned i = 0; i < size; i++) 
        {
            result.vector[i] = vector[i] + rhs.vector[i];
        }
        return result;
    }
}
Vector& Vector::operator+=(const Vector& rhs) 
{
    if (size != rhs.size) 
    {
        throw "Error: adding vectors of different dimensionality";
    }
    else
    {
        for (unsigned i = 0; i < size; i++) 
        {
            vector[i] += rhs.vector[i];
        }
        return *this;
    }
}
Vector Vector::operator-(const Vector& rhs) 
{
    if (size != rhs.size) 
    {
        throw "Error: subtracting vectors of different dimensionality";
    }
    else
    {
        Vector result(size);
        for (unsigned i = 0; i < size; i++) 
        {
            result.vector[i] = vector[i] - rhs.vector[i];
        }
        return result;
    }
}
Vector& Vector::operator-=(const Vector& rhs) 
{
    if (size != rhs.size) 
    {
        throw "Error: subtracting vectors of different dimensionality";
    }
    else
    {
        for (unsigned i = 0; i < size; i++) 
        {
            vector[i] -= rhs.vector[i];
        }
        return *this;
    }
}
Vector Vector::operator^(int pow)
{
    if (pow < 0) 
    {
        throw "Error: negative power is not supported";
    }
    else
    {
        Vector result(size);
        for (unsigned i = 0; i < size; i++) {
            for (int j = 0; j < pow; j++) {
                result.vector[i] *= vector[i];
            }
        }
        return result;
    }
}
Vector& Vector::operator^=(int pow)
{
    if (pow < 0) 
    {
        throw "Error: negative power is not supported";
    }
    else
    {

        for (unsigned i = 0; i < size; i++) {
            for (int j = 0; j < pow; j++) {
                vector[i] *= vector[i];
            }
        }
        return *this;
    }
    
}
Vector Vector::operator~()
{
    Vector result(size);
    for (unsigned i = 0; i < size; i++) 
    {
        result.vector[i] = vector[size - i - 1];
    }
    return result;
}
Vector Vector::operator*(const double& rhs)
{
    Vector result(size);
    for (unsigned i = 0; i < size; i++) 
    {
        result.vector[i] = vector[i] * rhs;
    }
    return result;
}
Vector& Vector::operator*=(const double& rhs)
{
    for (unsigned i = 0; i < size; i++) 
    {
        vector[i] *= rhs;
    }
    return *this;
}
Vector Vector::operator/(const double& rhs)
{
    if (rhs == 0) 
        {throw "Error: division by zero";}
    else
    {
        Vector result(size);
        for (unsigned i = 0; i < size; i++) 
        {
            result.vector[i] = vector[i] / rhs;
        }
        return result;
    }
}
Vector operator* (const double& input, const Vector& v)
{
    Vector *temp = new Vector(v.size);
    for(unsigned x = 0; x < v.size; x++)
    {
        temp->vector[x] = v[x] * input;
    }

    return *temp;
}

