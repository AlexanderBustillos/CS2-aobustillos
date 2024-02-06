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
            board[j][k] = new Cell;
            // A simple double for loop to access all the elements of the 2D array and place a "new Cell", this means
            //allocating memory from a large pool outside of the runtime memory. Each cell has an address now
         }
        
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
    // here i declare what i will use to read the file, i also have an empty variable strings, and filename
    //I ask for the name of the file to use and place it into filename
    

    fin.open(filename);
    //I open filename
    char num;
    int x(0),y(0);
    //this is the same as doing x = 0; it just looks nicer
    while(fin>>num)
    //while we can still read the file and put each individual char into num then do this
    {
        if (x >= boardSize)
        {
            //this is just a different looking forloop, because this fucntion is in a while loop
            // this function will repeat again, once x reaches 10 it resets x and adds 1 to y
            // its the same thing a double for loop would do its just better
            x = 0;
            y++;
            
        }

        board[y][x]->x = y;
        board[y][x]->y = x;
        // the boards x and y positions are switched due to the way the code is structured, dont pay
        //too much attention     
        if(num == '0')
        {
            board[y][x]->state = 0;
            //here i used num as char so i can read each element of the baord.txt file individually
            //then i check if its equal to 0 and set the board state of the cell to 0
        }
        if(num =='1')
        {
            board[y][x]->state = 1;
            //same thing but with 1
        }
    
        x++;
        //adding 1 to x so the loop goes on
    }
    fin.close();
    //closeing the file

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
         //simple double for loop to print the state of the board
        }
        cout << endl;
   
 }
    
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
            //these two for loops in the start are to check the 3 by 3 box around the cell 
            // to check the surrounding cells
            if((x + i >= 0 && x + i <= boardSize-1) && (y + g >= 0 && y + g <= boardSize-1))
            {
                // x is going to equal the current position of the current cell, and making sure that 
                // the positon we are checking is now out of bounds, bewteen 0 and 9
                if(i !=0 || g !=0)
                {
                    // the if statement is to check if we are not checking our current cell
                    // because you cant be your owen neighbor 
                    if(board[x + i][y + g]->state == 1)
                    {
                        // here is where we check every possible cell around our current cell
                        // by adding -1,0, and 1 to our current position, and checking 
                        // if the surrounding cell state is equal to 1, this part isnt current cell
                        //because we are checking other cells
                        curCell->numLiveNeighbors++;
                        //adding 1 to the live neighbors of the current cell
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
    // this flag is set to false every time the void is called just incase nothing changes so the program
    //can stop

    for(int j = 0; j < boardSize; j++)
    {
        for(int k = 0; k < boardSize; k++)
        {
            //a double for loop to find the neighbors for every cell every time the function is called
            findNumNeighbors(board,boardSize,board[j][k]);
        }
    } 
    for(int j = 0; j < boardSize; j++)
    {
        for(int k = 0; k < boardSize; k++)
        {
            //ANOTHER double for loop
            if(board[j][k]->state == 0)
            {
                if(board[j][k]->numLiveNeighbors == 3)
                {
                    //this time we are checking if the current cell is dead and if it has 3 neighbors  then it comes
                    // to life and the flag is changed to true to show that the board changed
                    // and the program will keep running
                    board[j][k]->state = 1;
                    flag = true;
                }
            }else if (board[j][k]->state == 1)
            {
                if (board[j][k]->numLiveNeighbors < 2 || board[j][k]->numLiveNeighbors > 3 )
                {
                    //if the cell is alive, then check if its underpopulated or overpopulated and 
                    //changed the flag aswell so the board continues
                    board[j][k]->state = 0;
                    flag = true;
                }
            }
        }
    }  
    //return the flag
    return flag;
}