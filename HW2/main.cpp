#include "database.h"

#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char* argv[])
{
    int options = 0;
    databases::database Mydatabase;
    while(options !=7)
    {
        cout<<"-------------------------"<< endl;

        cout<<"|"<< "[1]Add Movies"<< setw(11)<< "|"<<endl;
        cout<<"|"<< "[2]Delete Movies"<< setw(8)<<"|"<<endl;
        cout<<"|"<< "[3]Print Current Movies"<<"|"<< endl;
        cout<<"|"<< "[4]Search for Movies"<< setw(4)<<"|"<<endl;
        cout<<"|"<< "[5]Write data to csv"<< setw(4)<<"|"<<endl;
        cout<<"|"<< "[6]Read a file"<< setw(10)<<"|"<<endl;
        cout<<"|"<< "[7]Stop running"<< setw(9)<<"|"<< endl;
        cout<<"-------------------------"<< endl;

        cin >> options;

        if(options == 1)
        {  
            Mydatabase.addMovie();
        }
        if(options == 2)
        {
            Mydatabase.removeMovie();

        }
        if(options == 3)
        {
            Mydatabase.printMovies();

        }
        if(options == 4)
        {
            Mydatabase.searchMovies();
        }
        if(options == 5)
        {
            Mydatabase.transferData();
        }
        if(options == 6)
        {
            Mydatabase.readFile();
        }


    }
    
    return 0;
}
