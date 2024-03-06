#include "movie.h"
#include "database.h"

//constructor
movies::movie::movie(string _id, string _title, string _year, string _genre, string _rating, string _director)
{
    this->id = _id;
    this->title = _title;
    this->year = _year;
    this->genre = _genre;
    this->rating = _rating;
    this->director = _director;
}

//destructor for when i need one?
movies::movie::~movie()
{

}

//getters
string movies::movie::getId()
{
    return id;
}

string movies::movie::getTitle()
{
    return title;
}

string movies::movie::getYear()
{
    return year;
}

string movies::movie::getGenre()
{
    return genre;
}

string movies::movie::getRating()
{
    return rating;
}

string movies::movie::getDirector()
{
    return director;
}

//setters
void movies::movie::setId(string newId)
{
    this->id = newId;
}

void movies::movie::setTitle(string newTitle)
{
    this->title = newTitle;
}

void movies::movie::setYear(string newYear)
{
    this->year = newYear;
}

void movies::movie::setGenre(string newGenre)
{
    this->genre = newGenre;
}

void movies::movie::setRating(string newRating)
{
    this->rating = newRating;
}

void movies::movie::setDirector(string newDirector)
{
    this->director = newDirector;
}
