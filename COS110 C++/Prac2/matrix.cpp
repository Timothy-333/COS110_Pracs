//Timothy Whitaker u22744968
#include <iostream>

#include "matrix.h"

using namespace std;
//Do not change the displayMatrix() function
Matrix::Matrix(int in_rows, int in_columns)
{
    
    if(in_rows < 1 || in_columns < 1)
    {
        rows = 3;
        columns = 3;
        matrix = new int**[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int*[columns];
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = new int;
                *matrix[i][j] = 1;
            }
        }
    }
    else
    {
        rows = in_rows;
        columns = in_columns;
        matrix = new int**[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int*[columns];
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = new int;
                *matrix[i][j] = 0;
            }
        }
    }
}
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete [] matrix;
}
void Matrix::resizeRows(int num_rows)
{
    if (num_rows < 1)
    {
        cout << "Error: cannot have less than 1 row" << endl;
    }
    else if(num_rows < rows)
    {
        int*** temp = new int**[num_rows];
        for (int i = 0; i < num_rows; i++)
        {
            temp[i] = new int*[columns];
            for (int j = 0; j < columns; j++)
            {
                temp[i][j] = new int;
                *temp[i][j] = *matrix[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                delete matrix[i][j];
            }
            delete [] matrix[i];
        }
        delete [] matrix;
        matrix = temp;
        temp = NULL;
        rows = num_rows;
    }
    else if(num_rows > rows)
    {
        int*** temp = new int**[num_rows];
        for (int i = 0; i < rows; i++)
        {
            temp[i] = new int*[columns];
            for (int j = 0; j < columns; j++)
            {
                temp[i][j] = new int;
                *temp[i][j] = *matrix[i][j];
            }
        }
        for (int i = rows; i < num_rows; i++)
        {
            temp[i] = new int*[columns];
            for (int j = 0; j < columns; j++)
            {
                temp[i][j] = new int;
                *temp[i][j] = 0;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                delete matrix[i][j];
            }
            delete [] matrix[i];
        }
        delete [] matrix;
        matrix = temp;
        temp = NULL;
        rows = num_rows;
    }
}
void Matrix::resizeColumns(int num_cols)
{
    if (num_cols < 1)
    {
        cout << "Error: cannot have less than 1 column" << endl;
    }
    else if(num_cols < columns)
    {
        int*** temp = new int**[rows];
        for (int i = 0; i < rows; i++)
        {
            temp[i] = new int*[num_cols];
            for (int j = 0; j < num_cols; j++)
            {
                temp[i][j] = new int;
                *temp[i][j] = *matrix[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                delete matrix[i][j];
            }
            delete matrix[i];
        }
        delete matrix;
        matrix = temp;
        temp = NULL;
        columns = num_cols;
    }
    else if (num_cols > columns)
    {
        int*** temp = new int**[rows];
        for (int i = 0; i < rows; i++)
        {
            temp[i] = new int*[num_cols];
            for (int j = 0; j < columns; j++)
            {
                temp[i][j] = new int;
                *temp[i][j] = *matrix[i][j];
            }
            for (int j = columns; j < num_cols; j++)
            {
                temp[i][j] = new int;
                *temp[i][j] = 0;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                delete matrix[i][j];
            }
            delete [] matrix[i];
        }
        delete [] matrix;
        matrix = temp;
        temp = NULL;
        columns = num_cols;
    }
}
void Matrix::setMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> *matrix[i][j];
        }
    }
}
void Matrix::displayMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
        {
            cout << *matrix[i][j];

            if (j != columns - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}