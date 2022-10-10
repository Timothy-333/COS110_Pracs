#include "matrix.h"
Matrix::Matrix(unsigned r, unsigned c) 
{
    rows = r;
    cols = c;
    matrix = new double*[rows];
    for (unsigned i = 0; i < rows; i++) 
    {
        matrix[i] = new double[cols];
        for (unsigned j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}
Matrix::Matrix(const Matrix& rhs) 
{
    rows = rhs.getRows();
    cols = rhs.getCols();
    matrix = new double*[rows];
    for (unsigned i = 0; i < rows; i++) 
    {
        matrix[i] = new double[cols];
        for (unsigned j = 0; j < cols; j++) 
        {
            matrix[i][j] = rhs[i][j];
        }
    }
}
Matrix::~Matrix() 
{
    for (unsigned i = 0; i < rows; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void Matrix::print() 
{
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
                cout << matrix[i][j] << setw(10) << setprecision(3);
        }
        cout << endl << setw(0);
    }
}
void Matrix::readFile(istream &infile) 
{
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            infile >> matrix[i][j];
        }
    }
}
const Matrix& Matrix::operator=(const Matrix& rhs) 
{
    if (this != &rhs) 
    {
        for (unsigned i = 0; i < rows; i++) 
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        rows = rhs.getRows();
        cols = rhs.getCols();
        matrix = new double*[rows];
        for (unsigned i = 0; i < rows; i++) 
        {
            matrix[i] = new double[cols];
            for (unsigned j = 0; j < cols; j++) 
            {
                matrix[i][j] = rhs[i][j];
            }
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix& rhs) 
{
    Matrix* result = new Matrix(rows, cols);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            (*result)[i][j] = matrix[i][j] + rhs[i][j];
        }
    }
    return *result;
}
Matrix& Matrix::operator+=(const Matrix& rhs) 
{
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            matrix[i][j] += rhs[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator-(const Matrix& rhs) 
{
    Matrix* result = new Matrix(rows, cols);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            (*result)[i][j] = matrix[i][j] - rhs[i][j];
        }
    }
    return *result;
}
Matrix& Matrix::operator-=(const Matrix& rhs) 
{
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            matrix[i][j] -= rhs[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator*(const Matrix& rhs) 
{
    Matrix* result = new Matrix(rows, rhs.getCols());
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < rhs.getCols(); j++) 
        {
            for (unsigned k = 0; k < cols; k++) 
            {
                (*result)[i][j] += matrix[i][k] * rhs[k][j];
            }
        }
    }
    return *result;
}
Matrix& Matrix::operator*=(const Matrix& rhs) 
{
    Matrix* result = new Matrix(rows, rhs.getCols());
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < rhs.getCols(); j++) 
        {
            for (unsigned k = 0; k < cols; k++) 
            {
                (*result)[i][j] += matrix[i][k] * rhs[k][j];
            }
        }
    }
    *this = *result;
    return *this;
}
Matrix Matrix::operator^(int pow)
{
    Matrix* result = new Matrix(rows, cols);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            (*result)[i][j] = matrix[i][j];
        }
    }
    for (int i = 1; i < pow; i++) 
    {
        *result *= *this;
    }
    return *result;
}
Matrix& Matrix::operator^=(int pow)
{
    Matrix* result = new Matrix(*this);
    for (int i = 1; i < pow; i++) 
    {
        *result *= *this;
    }
    *this = *result;
    return *this;
}
Matrix Matrix::operator~() 
{
    Matrix* result = new Matrix(cols, rows);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            (*result)[j][i] = matrix[i][j];
        }
    }
    return *result;
}
Matrix Matrix::operator*(const double& rhs) 
{
    Matrix* result = new Matrix(rows, cols);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            (*result)[i][j] = matrix[i][j] * rhs;
        }
    }
    return *result;
}
Matrix& Matrix::operator*=(const double& rhs)
{
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            matrix[i][j] *= rhs;
        }
    }
    return *this;
}
Matrix Matrix::operator/(const double& rhs) 
{
    Matrix* result = new Matrix(rows, cols);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            matrix[i][j] = matrix[i][j] / rhs;
        }
    }
    return *result;
}
double& Matrix::operator()(const unsigned r, const unsigned c)
{
    if (r < 0 || r > rows)
        throw "Error: invalid row index";
    else if(c < 0 || c > cols)
        throw "Error: invalid column index";
    else
    {
        return matrix[r][c];
    }
}
const double& Matrix::operator()(const unsigned r, const unsigned c)const
{
    if (r < 0 || r > rows)
        throw "Error: invalid row index";
    else if(c < 0 || c > cols)
        throw "Error: invalid column index";
    else
    {
        return matrix[r][c];
    }
}
Vector Matrix::operator[](const unsigned r) const
{
    Vector* temp = new Vector(cols);
    for (unsigned i = 0; i < cols; i++)
    {
        (*temp)[i] = matrix[r][i];
    }
    return *temp;
}
unsigned Matrix::getRows() const
{
    return rows;
}
unsigned Matrix::getCols() const
{
    return cols;
}
Matrix Matrix::operator|(const Matrix& rhs) 
{
    Matrix* result = new Matrix(rows, cols + rhs.getCols());
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            (*result)[i][j] = matrix[i][j];
        }
    }
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < rhs.getCols(); j++) 
        {
            (*result)[i][j + cols] = rhs[i][j];
        }
    }
    return *result;
}
Matrix& Matrix::operator|=(Matrix& rhs) 
{
    Matrix* result = new Matrix(rows, cols + rhs.getCols());
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            (*result)[i][j] = matrix[i][j];
        }
    }
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < rhs.getCols(); j++) 
        {
            (*result)[i][j + cols] = rhs[i][j];
        }
    }
    *this = *result;
    return *this;
}