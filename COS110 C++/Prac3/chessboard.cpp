#include "chessboard.h"
#include "chesspiece.h"

Chessboard::Chessboard(Chessboard &obj)
{
    rows = obj.rows;
    columns = obj.columns;
    board = new Chesspiece**[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Chesspiece*[columns];
        for (int j = 0; j < this->columns; j++)
        {
            if(&obj.at(i,j) != NULL)
                this->board[i][j] = new Chesspiece(obj.at(i,j));
            else
                this->board[i][j] = NULL;
        }
    }
    
}
Chessboard::Chessboard(int in_rows, int in_columns)
{
    rows = in_rows;
    columns = in_columns;
    board = new Chesspiece**[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Chesspiece*[columns];
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = NULL;
        }
    }
}
Chessboard::~Chessboard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}
void Chessboard::addChesspiece(Chesspiece* piece, int row, int column)
{
    board[row][column] = piece;
}
void Chessboard::removeChesspiece(int row, int column)
{
    delete board[row][column];
    board[row][column] = NULL;
}
Chesspiece& Chessboard::at(int row, int column) const
{
    return *board[row][column];
}
Chessboard& Chessboard::operator=(const Chessboard& other)
{
    this->rows = other.rows;
    this->columns = other.columns;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            if(&other.at(i,j) != NULL)
                this->board[i][j] = new Chesspiece(other.at(i,j));
            else
                this->board[i][j] = NULL;
        }
    }
    return *this;
}
Chessboard& Chessboard::operator+=(const Chessboard& rhs)
{
    this->rows = rhs.rows;
    this->columns = rhs.columns;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            if(this->board[i][j] == NULL && &rhs.at(i,j) != NULL)
                this->board[i][j] = new Chesspiece(rhs.at(i,j));
        }
        
    }
    return *this;
}