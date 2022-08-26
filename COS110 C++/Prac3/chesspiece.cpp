#include "chesspiece.h"

int Chesspiece::numberOfPieces = 0;
Chesspiece::Chesspiece()
{
    name = "";
    type = true;
    numberOfPieces++;
}
Chesspiece::Chesspiece(Chesspiece &obj)
{
        name = obj.getName();
        type = obj.getType();
        numberOfPieces++;
}
Chesspiece::Chesspiece(string in_name)
{
    name = in_name;
    type = true;
    numberOfPieces++;
}
Chesspiece::~Chesspiece()
{
    numberOfPieces--;
}
string Chesspiece::getName() const
{
    return name;
}
int Chesspiece::getNumberOfPieces() const
{
    return numberOfPieces;
}
bool Chesspiece::getType() const
{
    return type;
}
Chesspiece::Chesspiece(string in_name, bool in_type)
{
    name = in_name;
    type = in_type;
    numberOfPieces++;
} 