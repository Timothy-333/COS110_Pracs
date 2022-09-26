#include <iostream>
using namespace std;
int main()
{
    int baseSize = 3;
    bool gameNotFinished = true;
    char** board = new char*[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        board[i] = new char[baseSize];
        for (int j = 0; j < baseSize; j++)
        {
            board[i][j] = '#';
            cout << board[i][j];
            if(j < baseSize - 1)    
                cout << "|";
        }
        cout << endl;
    }
    while(gameNotFinished)
    {
        cout << "Player 1 Move: ";
        int x;
        int y;
        cin >> x;
        cin >> y;
        board[x-1][y-1] = 'X';
        for (int i = 0; i < baseSize; i++)
        {
            for (int j = 0; j < baseSize; j++)
            {
                cout << board[i][j];
                if(j < baseSize - 1)    
                    cout << "|";
            }
            cout << endl;
        }
        cout << "Player 2 Move: ";
        cin >> x;
        cin >> y;
        board[x-1][y-1] = 'O';
        for (int i = 0; i < baseSize; i++)
        {
            for (int j = 0; j < baseSize; j++)
            {
                cout << board[i][j];
                if(j < baseSize - 1)    
                    cout << "|";
            }
            cout << endl;
        }
    }
    return 0;
}