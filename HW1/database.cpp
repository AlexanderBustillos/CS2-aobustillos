#include "database.h"
#include "movie.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// using namespace databases;

// constructor
databases::database::database(string _name, string _db_id)
{
    name = _name;
    db_id = _db_id;
    // forloop
    //  movies::movie* movies[100];
    initmovies();
}

// database::database()
// {
//     this->name = _name;
//     this->db_id = _db_id;

// }

// destructor
databases::database::~database()
{
}

// getters
string databases::database::getName()
{
    return name;
}

string databases::database::getdb_id()
{
    return db_id;
}

// database* databases::database::getmovies()
// {
//     return movieList;
// }

// setters
void databases::database::setName(string newName)
{
    this->name = newName;
}

void databases::database::setdb_id(string newdb_id)
{
    this->db_id = newdb_id;
}
// void database::setMovies(database* newMovies)
// {
//     this->movies = newMovies;
// }

// void database::initmovies(movie* movieList[],int arrSize)
// {
//     for(int i = 0; i < arrSize ; i++)
//     {
//         movies[i] = new movies[i];
//     }
//     //parse line
// }
//I am just setting every movie in the array to a new movie/giving it memory to work off of
void databases::database::initmovies()
{
    for (int i = 0; i < 100; i++)
    {
        // movies::movie *newmovie = new movies::movie;
        movieList[i] = nullptr;
    }
}
// Once the user exits the loop this fucntion is called that deletes every movie list and frees the memory that the code initially created
void databases::database::freemem()
{
    for (int i = 0; i < arrSize; i++)
    {
        delete movieList[i];
    }
}
//Reading the file from a csv file
void databases::database::readFile()
{
    // I set the filename equal to nothing, it doesnt matter because its going to be replaced anyway
    string filename = "";
    //ifstrema is going to be called with input
    ifstream input;
    //I get the filename
    cout << "What is the filename?"<< endl;
    cin >> filename;
    //I then open the filename with ifstream
    input.open(filename);
    //a new string that is equl to nothing
    string line = "";
    //This counts the rows in the csv, meaning the i variable will technically be column counter, it is set to arrSize because arrSize is 0 and this is how
    //it knows how much data we are currently holding in our movielist
    int rowCounter = 0;
    // While we are reading the file and putting it into line
    while (getline(input, line))
    {
        // movies::movie* tmpmovie;
        // tmpmovie = new movies::movie;
        // while we read in the file we are allocating new memory for movies
        movieList[rowCounter]= new movies::movie;
        // column counter
        int i = 0;
        // string stream is neccessary in order to parse the csv file and extract the data properly
        stringstream inputString;
        // a tmp variable to be able to put the data into the movielist
        string tmp;
        // this returns a copy of the contents of the stream
        inputString.str(line);
        // While we are reading the file from a csv file parsing it, there is two because its a double for loop that works much better
        while (getline(inputString, tmp, ','))
        {
            // the rowcounter is set to 1, meaning we are reading the first line of data, now we are putting the data into movielist with a loop that goes throough evert 
            // part in that first line untill the line is done then it changes the row counter to go to the next line and restarts this column counter till every part of the
            //csv file is put into the movieList
            if (i == 0)
            {
                movieList[rowCounter]->setId(tmp);
            }
            if (i == 1)
            {
                movieList[rowCounter]->setTitle(tmp);
            }
            if (i == 2)
            {
                movieList[rowCounter]->setYear(tmp);
            }
            if (i == 3)
            {
                movieList[rowCounter]->setGenre(tmp);
            }
            if (i == 4)
            {
                movieList[rowCounter]->setRating(tmp);
            }
            if (i == 5)
            {
                movieList[rowCounter]->setDirector(tmp);
            }
            i++;
            
        }
        // at the end rowcounte is incremented which is then set equal to arrSize
        rowCounter++;
        arrSize = rowCounter;
    }
    //closing the file after use
    input.close();
}
//Print the current movies and movie data held in movieList
void databases::database::printMovies()
{
    //this is a menu to help read the print
    cout <<"ID"<<setw(13)<<"Title"<<setw(60)<<"Year"<< setw(7)<< "Genre"<< setw(19)<< "Director"<< endl;
    //a loop that loops arrsize, arrsize is how large our database of movies is
    for(int i = 0; i < arrSize; i++)
    {
        //getting the data using the getters i made
        cout << left << setw(9) << movieList[i]->getId()<<" "
        <<setw(60) << movieList[i]->getTitle()<<" " 
        <<setw(5) << movieList[i]->getYear()<<" "
        <<setw(15)<< movieList[i]->getGenre()<<" "
        <<setw(20)<< movieList[i]->getDirector()<<endl;;
        
    }

}

//adding individual movies to the list rather then readign from a file
void databases::database::addMovie()
{
    // asking the user to properly enter the info then making a tmp variable to add to the movieList properly
    string tmp;
    cout << "Enter movie data in order of, ID TITLE YEAR GENRE DIRECTOR: "<< endl;
    cin >> tmp;
    movieList[arrSize]->setId(tmp);
    cin >> tmp;
    movieList[arrSize]->setTitle(tmp);
    cin >> tmp;
    movieList[arrSize]->setYear(tmp);
    cin >> tmp;
    movieList[arrSize]->setGenre(tmp);
    cin >> tmp;
    movieList[arrSize]->setDirector(tmp);
    arrSize++;
}
//removing an individual movie 
void databases::database::removeMovie()
{
    // arrSize = arrSize-1;
    string movieID = "";
    //asking for what movie they want to delete by getting the ID
    cout << "What movie do you want to delete?(ID): " <<endl;
    cin >> movieID;
    //I am searching through every single movie list till i find the id
    for(int i = 0; i <= arrSize; i++)
    {
        if(movieList[i]->getId() == movieID)
        {
            delete movieList[i];
            //I am going through the list starting at the point where we found where the id from the user is equal to the id from the movie list
            // i am going through arrsize-1 because i am subtracting a movie
            for (int j = i; j <= arrSize-1; j++)
            {
                //I am moving all the movies up by one instead of directly deleting the movie 
                while(movieList[i]!= nullptr)
                {
                    movieList[j] = movieList[j+1];
                
                }
                movieList[i] = nullptr;
                break;
            }
            //arrSize is now one less
        arrSize = arrSize - 1;
        // cout <<"DEBUG: "<< arrSize << endl;
        }
    }

}
//searching for a movie in the database
void databases::database::searchMovies()
{   
    // a little redundent but the assignment did say search the database with a tittle or genre
    int answer;
    string movieTitle = "";
    string movieGenre = "";
    cout << "Search movie by Tile[1] or Genre[2]? "<<endl;
    cin >> answer;
    //once the option is chosen
    if (answer == 1)
    {
        //ask for the title
        cout << "What is the Title?"<< endl;
        cin >> movieTitle;
        //menu
        cout <<"ID"<<setw(13)<<"Title"<<setw(60)<<"Year"<< setw(7)<< "Genre"<< setw(19)<< "Director"<< endl;
        //going through the movielist looking for the movie that matches the name 
        for(int i = 0; i < arrSize; i++)
        {
            if(movieList[i]->getTitle()== movieTitle)
            {
                cout << left << setw(9) << movieList[i]->getId()<<" "
                <<setw(60) << movieList[i]->getTitle()<<" " 
                <<setw(5) << movieList[i]->getYear()<<" "
                <<setw(15)<< movieList[i]->getGenre()<<" "
                <<setw(20)<< movieList[i]->getDirector() << endl;
            }
        }
    }
    //this is the same thing but looping for the movies that match the genre
    if (answer == 2)
    {
        cout << "What is the Genre(capital first letter)?"<< endl;
        cin >> movieGenre;
        cout <<"ID"<<setw(13)<<"Title"<<setw(60)<<"Year"<< setw(7)<< "Genre"<< setw(19)<< "Director"<< endl;
        for(int i = 0; i < arrSize; i++)
        {
            if(movieList[i]->getGenre()== movieGenre)
            {
                cout << left << setw(9) << movieList[i]->getId()<<" "
                <<setw(60) << movieList[i]->getTitle()<<" " 
                <<setw(5) << movieList[i]->getYear()<<" "
                <<setw(15)<< movieList[i]->getGenre()<<" "
                <<setw(20)<< movieList[i]->getDirector() << endl;
            }
        }
    }

}
//this makes a csv file and prints the current movielist into the new file
void databases::database::transferData()
{
    //ofstream uses my file then creates a csv file
    ofstream myfile("newMovies.csv");
    //goes through the whole arrSize
    for(int i = 0 ; i < arrSize; i++)
    {
        //printing into the file
        myfile << movieList[i]->getId()<<",";
        myfile << movieList[i]->getTitle()<<",";
        myfile << movieList[i]->getYear()<<",";
        myfile << movieList[i]->getGenre()<<",";
        myfile << movieList[i]->getDirector()<<endl;

    }
    //closing when done
    myfile.close();
}