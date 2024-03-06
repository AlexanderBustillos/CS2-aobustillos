#include "database.h"
#include "movie.h"

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
void databases::database::initmovies()
{
    for (int i = 0; i < 99; i++)
    {
        movies::movie *newmovie = new movies::movie;
        movieList[i] = newmovie;
    }
}
void databases::database::readFile()
{
    string filename = "";
    ifstream input;
    cout << "What is the filename?"<< endl;
    cin >> filename;
    input.open(filename);
    string line = "";
    
    int rowCounter = 0;
    while (getline(input, line))
    {
        
        int i = 0;
        stringstream inputString;
        string tmp;
        inputString.str(line);
        while (getline(inputString, tmp, ','))
        {
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

        rowCounter++;
        arrSize = rowCounter;
    }
    input.close();
}
void databases::database::printMovies()
{
    cout <<"ID"<<setw(13)<<"Title"<<setw(60)<<"Year"<< setw(7)<< "Genre"<< setw(19)<< "Director"<< endl;
    for(int i = 0; i < arrSize; i++)
    {
        cout << left << setw(9) << movieList[i]->getId()<<" "
        <<setw(60) << movieList[i]->getTitle()<<" " 
        <<setw(5) << movieList[i]->getYear()<<" "
        <<setw(15)<< movieList[i]->getGenre()<<" "
        <<setw(20)<< movieList[i]->getDirector()<<endl;;
        
    }

}

void databases::database::addMovie()
{
    
    string tmp;
    cout << "Enter movie data in order of, ID , TITLE, YEAR , GENRE, DIRECTOR: "<< endl;
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
void databases::database::removeMovie()
{
    // arrSize = arrSize-1;
    string movieID = "";
    cout << "What movie do you want to delete?(ID): " <<endl;
    cin >> movieID;
    for(int i = 0; i <= arrSize; i++)
    {
        if(movieList[i]->getId() == movieID)
        {
            for (int j = i; j <= arrSize-1; j++)
            {
                movieList[j] = movieList[j+1];

                // movieList[j]->getId() = movieList[j+1]->getId();
                // movieList[j]->getTitle() = movieList[j+1]->getTitle();
                // movieList[j]->getYear() = movieList[j+1]->getYear();
                // movieList[j]->getGenre() = movieList[j+1]->getGenre();
                // movieList[j]->getDirector() = movieList[j+1]->getDirector();

            }
        arrSize = arrSize - 1;
        // cout <<"DEBUG: "<< arrSize << endl;
        }
    }

}
void databases::database::searchMovies()
{   
    int answer;
    string movieID = "";
    string movieGenre = "";
    cout << "Search movie by ID[1] or Genre[2]? "<<endl;
    cin >> answer;
    if (answer == 1)
    {
        cout << "What is the ID?"<< endl;
        cin >> movieID;
        cout <<"ID"<<setw(13)<<"Title"<<setw(60)<<"Year"<< setw(7)<< "Genre"<< setw(19)<< "Director"<< endl;
        for(int i = 0; i < arrSize; i++)
        {
            if(movieList[i]->getId()== movieID)
            {
                cout << left << setw(9) << movieList[i]->getId()<<" "
                <<setw(60) << movieList[i]->getTitle()<<" " 
                <<setw(5) << movieList[i]->getYear()<<" "
                <<setw(15)<< movieList[i]->getGenre()<<" "
                <<setw(20)<< movieList[i]->getDirector() << endl;
            }
        }
    }
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
void databases::database::transferData()
{
    ofstream myfile("newMovies.csv");

    for(int i = 0 ; i < arrSize; i++)
    {
        myfile << movieList[i]->getId()<<",";
        myfile << movieList[i]->getTitle()<<",";
        myfile << movieList[i]->getYear()<<",";
        myfile << movieList[i]->getGenre()<<",";
        myfile << movieList[i]->getDirector()<<endl;

    }
    myfile.close();
}