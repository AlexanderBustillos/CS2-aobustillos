#include <iostream>

using namespace std;


int main()
{
    // cout << "Hello"<< endl;
    // int board[10][10];
    int j = 0,k = 0;
    // int board[][10];
    int board[10][10];

    for (int j = 0; j < 10; j++)
    {
        for (int k = 0; k < 10 ; k++)
         {
             board[j][k]=0;
             cout << board[j][k];

         }
         cout <<""<< endl;

    }
    


    
    return 0;
} 