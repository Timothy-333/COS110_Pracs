#include "Vector.h"
Vector::Vector(unsigned s) 
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
Vector::~Vector() 
{
    delete[] vector;
}
void Vector::print() 
{
    for (unsigned i = 0; i < size; i++) 
    {
        cout << vector[i] << setw(10) << setprecision(3);
    }
    cout << endl << setw(0);
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
        size = rhs.getSize();
        vector = new double[size];
        for (unsigned i = 0; i < size; i++) 
        {
            vector[i] = rhs.vector[i];
        }
    }
    return *this;
}
Vector Vector::operator+(const Vector& rhs) 
{
    Vector* result = new Vector(size);
    for (unsigned i = 0; i < size; i++) 
    {
        vector[i] = vector[i] + rhs[i];
    }
    return *result;
}
Vector& Vector::operator+=(const Vector& rhs) 
{
    for (unsigned i = 0; i < size; i++) 
    {
        vector[i] += rhs[i];
    }
    return *this;
}
Vector Vector::operator-(const Vector& rhs) 
{
    Vector* result = new Vector(size);
    for (unsigned i = 0; i < size; i++) 
    {
        result[i] = vector[i] - rhs[i];
    }
    return *result;
}
Vector& Vector::operator-=(const Vector& rhs) 
{
    for (unsigned i = 0; i < size; i++) 
    {
        vector[i] -= rhs[i];
    }
    return *this;
}
Vector Vector::operator^(int pow)
{
    Vector* result = new Vector(size);
    *result = *this;
    for (unsigned i = 1; i < size; i++) 
    {
        for (unsigned j = 0; j < size; j++)
        {
            (*result)[j] *= (*result)[j];
        }
    }
    return *result;
}
Vector& Vector::operator^=(int pow)
{
    for (unsigned i = 1; i < size; i++) 
    {
        for (unsigned j = 0; j < size; j++)
        {
            vector[j] *= vector[j];
        }
    }
    return *this;
}
Vector Vector::operator~()
{
    Vector* result = new Vector(size);
    *result = *this;
    for (unsigned i = 0; i < size; i++) 
    {
        (*result)[i] = vector[size - i - 1];
    }
    return *result;
}
Vector Vector::operator*(const double& rhs)
{
    Vector* result = new Vector(size);
    for (unsigned i = 0; i < size; i++) 
    {
        (*result)[i] = vector[i] * rhs;
    }
    return *result;
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
    Vector* result = new Vector(size);
    for (unsigned i = 0; i < size; i++) 
    {
        (*result)[i] = vector[i] / rhs;
    }
    return *result;
}
double& Vector::operator[](const unsigned r)
{
    if(r < size)
    {
        return vector[r];
    }
    else
    {
        throw "Error: invalid index";
    }
}
const double& Vector::operator[](const unsigned r) const
{
    if(r < size)
    {
        return vector[r];
    }
    else
    {
        throw "Error: invalid index";
    }
}
unsigned Vector::getSize() const
{
    return size;
}