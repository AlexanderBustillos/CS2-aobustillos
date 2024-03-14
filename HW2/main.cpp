#include "database.h"

#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char* argv[])
{
    //in order to make a menu i will make a options setting so the user can choose what they want to do
    int options = 0;
    //I am creating a database to be able to use all the functions that have access to variables from database
    databases::database Mydatabase;
    //While the user doesnt want to exit, if the user pressed 7 then the while loop stops
    while(options !=7)
    {
        //Menu
        cout<<"-------------------------"<< endl;
        cout<<"[1]Add Movies"<<endl;
        cout<< "[2]Delete Movies"<< endl;
        cout<< "[3]Print Current Movies"<<endl;
        cout<< "[4]Search for Movies"<<endl;
        cout<< "[5]Write data to csv"<<endl;
        cout<< "[6]Read a file"<< endl;
        cout<< "[7]Stop running"<<endl;
        cout<<"-------------------------"<< endl;
        //asking for the option
        cin >> options;
        // whatever the user chooses it calls the functions then restarts the loop
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
    //once the user wants to exit i call a fucntion to free the memory
    if (options == 7)
    {
        Mydatabase.freemem();
    }
    
    return 0;
}
