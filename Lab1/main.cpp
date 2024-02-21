#include <iostream>
#include <string>
#include "gameOfLife.h"

using namespace std;

int main(int argc, char* argv[])
{
    int stage = 0;
    bool boardChanged = true;
    size_t boardSize = 10;
    Cell* board[10][10];
    

    initCells(board, boardSize);
    readBoard(board, boardSize);


    while(boardChanged) {
        clearScreen();
        cout << "Stage: " << stage << endl;

        printCells(board, boardSize);
        boardChanged = updateCellState(board, boardSize);

        cin.get();
        stage++;
    }

    for(int j = 0; j < boardSize; j++)
    {
        for(int k = 0; k < boardSize; k++)
        {
            delete  board[j][k];
        }
    }
    return 0;
}