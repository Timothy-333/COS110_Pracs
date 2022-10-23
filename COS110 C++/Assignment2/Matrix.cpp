#include "matrix.h"
#include <iomanip>
Matrix::Matrix(unsigned r, unsigned c) : Arithmetic::Arithmetic()
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
            matrix[i][j] = rhs.matrix[i][j];
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
                cout << setprecision(3) << setw(10) << matrix[i][j];
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
                matrix[i][j] = rhs.matrix[i][j];
            }
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix& rhs) 
{
    if(rows != rhs.getRows() || cols != rhs.getCols())
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        Matrix result(rows, cols);
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++) 
            {
                result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
            }
        }
        return result;
    }
}
Matrix& Matrix::operator+=(const Matrix& rhs) 
{
    if(rows != rhs.getRows() || cols != rhs.getCols())
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++) 
            {
                matrix[i][j] += rhs.matrix[i][j];
            }
        }
        return *this;
    }
}
Matrix Matrix::operator-(const Matrix& rhs) 
{
    if (rows != rhs.getRows() || cols != rhs.getCols()) 
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
    else 
    {
        Matrix result(rows, cols);
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++) 
            {
                result.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
            }
        }
        return result;
    }
}
Matrix& Matrix::operator-=(const Matrix& rhs) 
{
    if (rows != rhs.getRows() || cols != rhs.getCols()) 
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
    else 
    {
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++) 
            {
                matrix[i][j] -= rhs.matrix[i][j];
            }
        }
        return *this;
    }
}
Matrix Matrix::operator*(const Matrix& rhs) 
{
    if (cols != rhs.getRows()) 
    {
        throw "Error: invalid matrix multiplication";
    }
    else 
    {
        Matrix result(rows, rhs.getCols());
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < rhs.getCols(); j++) 
            {
                for (unsigned k = 0; k < cols; k++) 
                {
                    result.matrix[i][j] += matrix[i][k] * rhs[k][j];
                }
            }
        }
        return result;
    }
}
Matrix& Matrix::operator*=(const Matrix& rhs) 
{
    if (cols != rhs.getRows()) 
    {
        throw "Error: invalid matrix multiplication";
    }
    else 
    {
        Matrix result(rows, rhs.getCols());
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < rhs.getCols(); j++) 
            {
                for (unsigned k = 0; k < cols; k++) 
                {
                    result.matrix[i][j] += matrix[i][k] * rhs[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }
}
Matrix Matrix::operator^(int pow)
{
    if (rows != cols) 
    {
        throw "Error: non-square matrix provided";
    }
    else if(pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else 
    {
        Matrix result(rows, cols);
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++)
            {
                if (i == j) 
                {
                    result.matrix[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < pow; i++) 
        {
            result *= *this;
        }
        return result;
    }
}
Matrix& Matrix::operator^=(int pow)
{
    if(rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if(pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else
    {
        Matrix result(rows, cols);
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++) 
            {
                if (i == j) 
                {
                    result.matrix[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < pow; i++) 
        {
            result *= *this;
        }
        *this = result;
        return *this;
    }
}
Matrix Matrix::operator~() 
{
    Matrix result(rows, cols);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            result.matrix[j][i] = matrix[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator*(const double& rhs) 
{
    Matrix result(rows, cols);
    for (unsigned i = 0; i < rows; i++) 
    {
        for (unsigned j = 0; j < cols; j++) 
        {
            result.matrix[i][j] = matrix[i][j] * rhs;
        }
    }
    return result;
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
    if(rhs == 0)
    {
        throw "Error: division by zero";
    }
    else
    {
        Matrix result(rows, cols);
        for (unsigned i = 0; i < rows; i++) 
        {
            for (unsigned j = 0; j < cols; j++) 
            {
                result.matrix[i][j] = matrix[i][j] / rhs;
            }
        }
        return result;
    }
}
double& Matrix::operator()(const unsigned r, const unsigned c)
{
    if (r < 0 || r >= rows)
        throw "Error: invalid row index";
    else if(c < 0 || c >= cols)
        throw "Error: invalid column index";
    else
    {
        return matrix[r][c];
    }
}
const double& Matrix::operator()(const unsigned r, const unsigned c)const
{
    if (r < 0 || r >= rows)
        throw "Error: invalid row index";
    else if(c < 0 || c >= cols)
        throw "Error: invalid column index";
    else
    {
        return matrix[r][c];
    }
}
Vector Matrix::operator[](const unsigned r) const
{
    if (r < 0 || r >= rows)
        throw "Error: invalid row index";
    else
    {
        Vector result(cols);
        for (unsigned i = 0; i < cols; i++) 
        {
            result[i] = matrix[r][i];
        }
        return result;
    }
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
    if (cols != rows)
        throw "Error: non-square matrix provided";
    else if(rhs.getRows() != rows || rhs.getCols() != 1)
        throw "Error: incorrect augmentation";
    else
    {
        bool flag = true;
        Matrix temp1(*this);
        Matrix temp2(rhs);
        for (unsigned i = 1; i < rows; i++)
        {
            for (unsigned j = 0; j <= i; j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    flag = false;
                }
            }
        }
        if(!flag)
            temp1|=temp2;

        Matrix result(temp2);
        for (unsigned i = temp1.getRows()-1; i >= 0; i--)
        {
            for (unsigned j = i+1; j < temp1.getCols(); j++)
            {
                result.matrix[i][0] -= temp1.matrix[i][j] * result.matrix[j][0];
            }
            if(temp1.matrix[i][i] == 0)
            {
                throw "Error: division by zero";
            }
            else
            {
                result.matrix[i][0] /= temp1.matrix[i][i];
            }
        }
        return result;
    }
}
Matrix& Matrix::operator|=(Matrix& rhs) 
{
    if (cols != rows)
        throw "Error: non-square matrix provided";
    else if(rhs.getRows() != rows || rhs.getCols() != 1)
        throw "Error: incorrect augmentation";
    else
    {
        double factor = 0;
        for (unsigned i = 0; i < rows; i++)
        {
            for (unsigned j = i+1; j < rows; j++)
            {
                if(matrix[i][i] == 0)
                    throw "Error: division by zero";

                factor = matrix[j][i] / matrix[i][i];
                for (unsigned k = 0; k < cols; k++)
                {
                    matrix[j][k] -= factor * matrix[i][k];
                }
                rhs.matrix[j][0] -= factor * rhs.matrix[i][0];
            }
        }
        return *this;
    }
}