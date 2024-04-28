#include "database.h"
#include "movie.h"
#include "tvshows.h"
#include "music.h"

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
    initmedia();
}
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
// setters
void databases::database::setName(string newName)
{
    this->name = newName;
}

void databases::database::setdb_id(string newdb_id)
{
    this->db_id = newdb_id;
}

// I am just setting every movie in the array to a new movie/giving it memory to work off of
void databases::database::initmedia()
{
    for (int i = 0; i < 100; i++)
    {
        // movies::movie *newmovie = new movies::movie;
        movieList[i] = nullptr;
    }
    for (int i = 0; i < 100; i++)
    {
        tvshowList[i] = nullptr;
    }
    for (int i = 0; i < 100; i++)
    {
        musicList[i] = nullptr;
    }
}
// Once the user exits the loop this fucntion is called that deletes every movie list and frees the memory that the code initially created
void databases::database::freemem()
{
    for (int i = 0; i < movieArrSize; i++)
    {
        delete movieList[i];
    }
    for (int i = 0; i < tvshowArrSize; i++)
    {
        delete tvshowList[i];
    }
    for (int i = 0; i < musicArrSize; i++)
    {
        delete musicList[i];
    }
}
// Reading the file from a csv file
void databases::database::readFile()
{
    // I set the filename equal to nothing, it doesnt matter because its going to be replaced anyway
    string filenameMovie = "movies.csv";
    string filenameTvshow = "tvshows.csv";
    string filenameMusic = "music.csv";
    // ifstrema is going to be called with input
    ifstream input;
    // I get the filename
    // cout << "What is the filename in order?(movie,tvshow,music)?" << endl;
    // cin >> filenameMovie >> filenameTvshow >> filenameMusic;
    // I then open the filename with ifstream
    input.open(filenameMovie);
    // a new string that is equl to nothing
    string line = "";
    // This counts the rows in the csv, meaning the i variable will technically be column counter, it is set to arrSize because arrSize is 0 and this is how
    // it knows how much data we are currently holding in our movielist
    int rowCounter = 0;
    // While we are reading the file and putting it into line
    while (getline(input, line))
    {
        // movies::movie* tmpmovie;
        // tmpmovie = new movies::movie;
        // while we read in the file we are allocating new memory for movies
        movieList[rowCounter] = new movies::movie;
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
            // csv file is put into the movieList
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
        movieArrSize = rowCounter;
    }
    // closing the file after use
    input.close();

    input.open(filenameTvshow);
    // a new string that is equl to nothing
    line = "";
    // This counts the rows in the csv, meaning the i variable will technically be column counter, it is set to arrSize because arrSize is 0 and this is how
    // it knows how much data we are currently holding in our movielist
    rowCounter = 0;
    // While we are reading the file and putting it into line
    while (getline(input, line))
    {
        // movies::movie* tmpmovie;
        // tmpmovie = new movies::movie;
        // while we read in the file we are allocating new memory for movies
        tvshowList[rowCounter] = new tvshows::tvshow;
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
            // csv file is put into the movieList
            if (i == 0)
            {
                tvshowList[rowCounter]->setId(tmp);
            }
            if (i == 1)
            {
                tvshowList[rowCounter]->setTitle(tmp);
            }
            if (i == 2)
            {
                tvshowList[rowCounter]->setYear(tmp);
            }
            if (i == 3)
            {
                tvshowList[rowCounter]->setGenre(tmp);
            }
            if (i == 4)
            {
                tvshowList[rowCounter]->setNumEpisodes(tmp);
            }
            if (i == 5)
            {
                tvshowList[rowCounter]->setRating(tmp);
            }
            i++;
        }
        // at the end rowcounte is incremented which is then set equal to arrSize
        rowCounter++;
        tvshowArrSize = rowCounter;
    }
    // closing the file after use
    input.close();

    input.open(filenameMusic);
    // a new string that is equl to nothing
    line = "";
    // This counts the rows in the csv, meaning the i variable will technically be column counter, it is set to arrSize because arrSize is 0 and this is how
    // it knows how much data we are currently holding in our movielist
    rowCounter = 0;
    // While we are reading the file and putting it into line
    while (getline(input, line))
    {
        // movies::movie* tmpmovie;
        // tmpmovie = new movies::movie;
        // while we read in the file we are allocating new memory for movies
        musicList[rowCounter] = new musics::music;
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
            // csv file is put into the movieList
            if (i == 0)
            {
                musicList[rowCounter]->setId(tmp);
            }
            if (i == 1)
            {
                musicList[rowCounter]->setTitle(tmp);
            }
            if (i == 2)
            {
                musicList[rowCounter]->setYear(tmp);
            }
            if (i == 3)
            {
                musicList[rowCounter]->setComposer(tmp);
            }
            if (i == 4)
            {
                musicList[rowCounter]->setGenre(tmp);
            }
            if (i == 5)
            {
                musicList[rowCounter]->setNumTracks(tmp);
            }
            if (i == 6)
            {
                musicList[rowCounter]->setTotalPlaytime(tmp);
            }
            i++;
        }
        // at the end rowcounte is incremented which is then set equal to arrSize
        rowCounter++;
        musicArrSize = rowCounter;
    }
    // closing the file after use
    input.close();
}
// Print the current movies and movie data held in movieList
void databases::database::printMedia()
{
    // this is a menu to help read the print
    cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Director" << endl;
    // a loop that loops arrsize, arrsize is how large our database of movies is
    for (int i = 0; i < movieArrSize; i++)
    {
        // getting the data using the getters i made
        cout << left << setw(9) << movieList[i]->getId() << " "
             << setw(60) << movieList[i]->getTitle() << " "
             << setw(5) << movieList[i]->getYear() << " "
             << setw(15) << movieList[i]->getGenre() << " "
             << setw(15) << movieList[i]->getRating() << " "
             << setw(20) << movieList[i]->getDirector() << endl;
        ;
    }
    cout << "ID" << setw(23) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Rating" << setw(19) << "Number of Episodes" << endl;
    for (int i = 0; i < tvshowArrSize; i++)
    {
        // getting the data using the getters i made
        cout << left << setw(9) << tvshowList[i]->getId() << " "
             << setw(60) << tvshowList[i]->getTitle() << " "
             << setw(5) << tvshowList[i]->getYear() << " "
             << setw(15) << tvshowList[i]->getGenre() << " "
             << setw(15) << movieList[i]->getRating() << " "
             << setw(20) << tvshowList[i]->getNumEpisodes() << endl;
        ;
    }
    cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Composer" << setw(19) << "Number of Tracks" << "Total Playtime" << endl;
    for (int i = 0; i < musicArrSize; i++)
    {
        // getting the data using the getters i made
        cout << left << setw(9) << tvshowList[i]->getId() << " "
             << setw(60) << musicList[i]->getTitle() << " "
             << setw(5) << musicList[i]->getYear() << " "
             << setw(15) << musicList[i]->getGenre() << " "
             << setw(15) << musicList[i]->getComposer() << " "
             << setw(20) << musicList[i]->getNumTracks() << " "
             << setw(20) << musicList[i]->getTotalPlaytime() << endl;
        ;
    }
}

// adding individual movies to the list rather then readign from a file
void databases::database::addMedia()
{
    int choice = 0;
    // asking the user to properly enter the info then making a tmp variable to add to the movieList properly
    cout << "Do you want to add to movie[1], tvshows[2], or music[3]?" << endl;
    cin >> choice;
    if (choice == 1)
    {
        string tmp;
        movieList[movieArrSize] = new movies::movie;
        cout << "Enter movie data in order of, ID TITLE YEAR GENRE DIRECTOR: " << endl;
        cin >> tmp;
        movieList[movieArrSize]->setId(tmp);
        cin.ignore();
        getline(cin, tmp);
        movieList[movieArrSize]->setTitle(tmp);
        cin >> tmp;
        movieList[movieArrSize]->setYear(tmp);
        cin >> tmp;
        movieList[movieArrSize]->setGenre(tmp);
        cin >> tmp;
        movieList[movieArrSize]->setRating(tmp);
        cin.ignore();
        getline(cin, tmp);
        movieList[movieArrSize]->setDirector(tmp);
        movieArrSize++;
    }
    if (choice == 2)
    {
        string tmp;
        tvshowList[tvshowArrSize] = new tvshows::tvshow;
        cout << "Enter tvshow data in order of, ID TITLE YEAR GENRE RATING NUMEPISODES: " << endl;
        cin >> tmp;
        tvshowList[tvshowArrSize]->setId(tmp);
        cin.ignore();
        getline(cin, tmp);
        tvshowList[tvshowArrSize]->setTitle(tmp);
        cin >> tmp;
        tvshowList[tvshowArrSize]->setYear(tmp);
        cin >> tmp;
        tvshowList[tvshowArrSize]->setGenre(tmp);
        cin >> tmp;
        tvshowList[tvshowArrSize]->setRating(tmp);
        cin >> tmp;
        tvshowList[tvshowArrSize]->setNumEpisodes(tmp);
        tvshowArrSize++;
    }
    if (choice == 3)
    {
        string tmp;
        musicList[musicArrSize] = new musics::music;
        cout << "Enter music data in order of, ID TITLE YEAR GENRE COMPOSER NUMTRACKS TOTALPLAYTIME: " << endl;
        cin >> tmp;
        musicList[musicArrSize]->setId(tmp);
        cin.ignore();
        getline(cin, tmp);
        musicList[musicArrSize]->setTitle(tmp);
        cin >> tmp;
        musicList[musicArrSize]->setYear(tmp);
        cin >> tmp;
        musicList[musicArrSize]->setGenre(tmp);
        cin.ignore();
        getline(cin, tmp);
        musicList[musicArrSize]->setComposer(tmp);
        cin >> tmp;
        musicList[musicArrSize]->setNumTracks(tmp);
        cin >> tmp;
        musicList[musicArrSize]->setTotalPlaytime(tmp);
        musicArrSize++;
    }
}
// removing an individual movie
void databases::database::removeMedia()
{
    string ID;
    cout << "What is the ID" << endl;
    cin >> ID;
    cout << "DEBUG "<< ID << endl;
    for (int i = 0; i < movieArrSize; i++)
    {
        if (movieList[i]->getId() == ID)
        {
            delete movieList[i];
            // I am going through the list starting at the point where we found where the id from the user is equal to the id from the movie list
            //  i am going through arrsize-1 because i am subtracting a movie
            for (int j = i; j <= movieArrSize - 1; j++)
            {
                // I am moving all the movies up by one instead of directly deleting the movie
                while (movieList[i] != nullptr)
                {
                    movieList[j] = movieList[j + 1];
                }
                movieList[i] = nullptr;
                break;
            }
            // arrSize is now one less
            movieArrSize = movieArrSize - 1;
            // cout <<"DEBUG: "<< arrSize << endl;
        }
    }
    for (int i = 0; i < tvshowArrSize; i++)
    {
        cout << "In tvshow Loop"<<endl;
        if (tvshowList[i]->getId() == ID)
        {
            delete tvshowList[i];
            // I am going through the list starting at the point where we found where the id from the user is equal to the id from the movie list
            //  i am going through arrsize-1 because i am subtracting a movie
            for (int j = i; j <= tvshowArrSize - 1; j++)
            {
                // I am moving all the movies up by one instead of directly deleting the movie
                cout << "Inside while loop" << endl;
                tvshowList[j] = tvshowList[j + 1];
                
            }
            // arrSize is now one less
            tvshowArrSize = tvshowArrSize - 1;
            // cout <<"DEBUG: "<< arrSize << endl;
        }
    }
    cout <<"out of loops"<< endl;
    for (int i = 0; i < musicArrSize; i++)
    {
        if (musicList[i]->getId() == ID)
        {
            delete musicList[i];
            // I am going through the list starting at the point where we found where the id from the user is equal to the id from the movie list
            //  i am going through arrsize-1 because i am subtracting a movie
            for (int j = i; j <= musicArrSize - 1; j++)
            {
                // I am moving all the movies up by one instead of directly deleting the movie
                while (musicList[i] != nullptr)
                {
                    musicList[j] = musicList[j + 1];
                }
                musicList[i] = nullptr;
                break;
            }
            // arrSize is now one less
            musicArrSize = musicArrSize - 1;
            // cout <<"DEBUG: "<< arrSize << endl;
        }
    }
}
// searching for a movie in the database
void databases::database::searchMedia()
{
    // a little redundent but the assignment did say search the database with a tittle or genre
    int answer;
    string mediaTitle = "";
    string mediaGenre = "";
    cout << "Search media by Tile[1] or Genre[2]? " << endl;
    cin >> answer;
    // once the option is chosen
    if (answer == 1)
    {
        // ask for the title
        cout << "What is the Title?" << endl;
        cin.ignore();
        getline(cin, mediaTitle);
        // menu
        cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Director" << endl;
        // going through the movielist looking for the movie that matches the name
        for (int i = 0; i < movieArrSize; i++)
        {
            if (movieList[i]->getTitle() == mediaTitle)
            {
                cout << left << setw(9) << movieList[i]->getId() << " "
                     << setw(60) << movieList[i]->getTitle() << " "
                     << setw(5) << movieList[i]->getYear() << " "
                     << setw(15) << movieList[i]->getGenre() << " "
                     << setw(15) << movieList[i]->getRating() << " "
                     << setw(20) << movieList[i]->getDirector() << endl;
            }
        }
        cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Rating" << setw(19) << "Number of Episodes" << endl;
        for (int i = 0; i < tvshowArrSize; i++)
        {
            if (tvshowList[i]->getTitle() == mediaTitle)
            {
                cout << left << setw(9) << tvshowList[i]->getId() << " "
                     << setw(60) << tvshowList[i]->getTitle() << " "
                     << setw(5) << tvshowList[i]->getYear() << " "
                     << setw(15) << tvshowList[i]->getGenre() << " "
                     << setw(15) << tvshowList[i]->getRating()
                     << setw(20) << tvshowList[i]->getNumEpisodes() << endl;
            }
        }
        cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Composer" << setw(19) << "Number of Tracks" << "Total Playtime" << endl;
        for (int i = 0; i < musicArrSize; i++)
        {
            if (musicList[i]->getTitle() == mediaTitle)
            {
                cout << left << setw(9) << tvshowList[i]->getId() << " "
                     << setw(60) << musicList[i]->getTitle() << " "
                     << setw(5) << musicList[i]->getYear() << " "
                     << setw(15) << musicList[i]->getGenre() << " "
                     << setw(15) << musicList[i]->getComposer() << " "
                     << setw(20) << musicList[i]->getNumTracks() << " "
                     << setw(20) << musicList[i]->getTotalPlaytime() << endl;
            }
        }
    }
    // this is the same thing but looping for the movies that match the genre
    if (answer == 2)
    {
        cout << "What is the Genre(capital first letter)?" << endl;
        cin >> mediaGenre;
        cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Director" << endl;
        for (int i = 0; i < movieArrSize; i++)
        {
            if (movieList[i]->getGenre() == mediaGenre)
            {
                cout << left << setw(9) << movieList[i]->getId() << " "
                     << setw(60) << movieList[i]->getTitle() << " "
                     << setw(5) << movieList[i]->getYear() << " "
                     << setw(15) << movieList[i]->getGenre() << " "
                     << setw(20) << movieList[i]->getDirector() << endl;
            }
        }
        cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Rating" << setw(19) << "Number of Episodes" << endl;

        for (int i = 0; i < tvshowArrSize; i++)
        {
            if (tvshowList[i]->getGenre() == mediaGenre)
            {
                cout << left << setw(9) << tvshowList[i]->getId() << " "
                     << setw(60) << tvshowList[i]->getTitle() << " "
                     << setw(5) << tvshowList[i]->getYear() << " "
                     << setw(15) << tvshowList[i]->getGenre() << " "
                     << setw(15) << tvshowList[i]->getRating()
                     << setw(20) << tvshowList[i]->getNumEpisodes() << endl;
            }
        }
        cout << "ID" << setw(13) << "Title" << setw(60) << "Year" << setw(7) << "Genre" << setw(19) << "Composer" << setw(19) << "Number of Tracks" << "Total Playtime" << endl;

        for (int i = 0; i < musicArrSize; i++)
        {
            if (musicList[i]->getGenre() == mediaGenre)
            {
                cout << left << setw(9) << tvshowList[i]->getId() << " "
                     << setw(60) << musicList[i]->getTitle() << " "
                     << setw(5) << musicList[i]->getYear() << " "
                     << setw(15) << musicList[i]->getGenre() << " "
                     << setw(15) << musicList[i]->getComposer() << " "
                     << setw(20) << musicList[i]->getNumTracks() << " "
                     << setw(20) << musicList[i]->getTotalPlaytime() << endl;
            }
        }
    }
}
// this makes a csv file and prints the current movielist into the new file
void databases::database::transferData()
{
    // ofstream uses my file then creates a csv file
    ofstream myfile("newMedias.csv");
    // goes through the whole arrSize
    for (int i = 0; i < movieArrSize; i++)
    {
        // printing into the file
        myfile << movieList[i]->getId() << ",";
        myfile << movieList[i]->getTitle() << ",";
        myfile << movieList[i]->getYear() << ",";
        myfile << movieList[i]->getGenre() << ",";
        myfile << movieList[i]->getDirector() << endl;
    }
    for (int i = 0; i < tvshowArrSize; i++)
    {
        // printing into the file
        myfile << tvshowList[i]->getId() << ",";
        myfile << tvshowList[i]->getTitle() << ",";
        myfile << tvshowList[i]->getYear() << ",";
        myfile << tvshowList[i]->getGenre() << ",";
        myfile << tvshowList[i]->getRating() << ",";
        myfile << tvshowList[i]->getNumEpisodes() << endl;
    }
    for (int i = 0; i < musicArrSize; i++)
    {
        // printing into the file
        myfile << musicList[i]->getId() << ",";
        myfile << musicList[i]->getTitle() << ",";
        myfile << musicList[i]->getYear() << ",";
        myfile << musicList[i]->getGenre() << ",";
        myfile << musicList[i]->getComposer() << ",";
        myfile << musicList[i]->getNumTracks() << ",";
        myfile << musicList[i]->getTotalPlaytime() << "," << endl;
    }
    // closing when done
    myfile.close();
}