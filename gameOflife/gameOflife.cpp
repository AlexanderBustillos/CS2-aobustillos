#include "gameOfLife.h"

#include <iostream>
#include <fstream>

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], int boardSize)
{
     for (int j = 0; j < boardSize; j++)
    {
        for (int k = 0; k < boardSize ; k++)
         {
            // Cell* newCell = new Cell;
            board[j][k] = new Cell;
            // cout << "(" << board[j][k]->x << ","<< board[j][k]->y<< ")";

         }
        //cout<<endl;
     }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    ifstream fin;

    string input = "";
    string filename;
    cout << "Name of file: "<< endl;
    cin >> filename; 
    

    fin.open(filename);

    char num;
    int x(0),y(0);

    while(fin>>num)
    {
        if (x >= boardSize)
        {
            x = 0;
            y++;
            // cout << endl;
        }
        board[y][x]->x = y;
        board[y][x]->y = x;

        if(num == '0')
        {
            board[y][x]->state = 0;
        }
        if(num =='1')
        {
            board[y][x]->state = 1;
        }
        // cout << board[y][x]->state;
        x++;
    }
    fin.close();

}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for(int j = 0; j < boardSize; j++)
    {
        for(int k = 0; k < boardSize; k++)
        {
         cout << board[j][k]->state<<" ";
        }
        cout << endl;
   
 }
    
    // cout<< board[10][10]->state << endl;
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell)
{
    int x = curCell->x;
    int y = curCell->y;
    curCell->numLiveNeighbors = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int g = -1; g <= 1; g++)
        {
            if((x + i >= 0 && x + i <= boardSize-1) && (y + g >= 0 && y + g <= boardSize-1))
            {
                if(i !=0 || g !=0)
                {
                    if(board[x + i][y + g]->state == 1)
                    {
                        curCell->numLiveNeighbors++;
                    }
                }
            }
        } 
    }
}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    bool flag = false;

    for(int j = 0; j < boardSize; j++)
    {
        for(int k = 0; k < boardSize; k++)
        {
            findNumNeighbors(board,boardSize,board[j][k]);
        }
    } 
    for(int j = 0; j < boardSize; j++)
    {
        for(int k = 0; k < boardSize; k++)
        {
            if(board[j][k]->state == 0)
            {
                if(board[j][k]->numLiveNeighbors == 3)
                {
                    board[j][k]->state = 1;
                    flag = true;
                }
            }else if (board[j][k]->state == 1)
            {
                if (board[j][k]->numLiveNeighbors < 2 || board[j][k]->numLiveNeighbors > 3 )
                {
                    board[j][k]->state = 0;
                    flag = true;
                }
            }
        }
    }  

    return flag;
}