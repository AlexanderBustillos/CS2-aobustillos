#include "movie.h"

//constructor
movies::movie::movie(int _id, string _title, int _year, string _genre, int _rating, string _director)
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
int movies::movie::getId()
{
    return id;
}

string movies::movie::getTitle()
{
    return title;
}

int movies::movie::getYear()
{
    return year;
}

string movies::movie::getGenre()
{
    return genre;
}

int movies::movie::getRating()
{
    return rating;
}

string movies::movie::getDirector()
{
    return director;
}

//setters
void movies::movie::setId(int newId)
{
    this->id = newId;
}

void movies::movie::setTitle(string newTitle)
{
    this->title = newTitle;
}

void movies::movie::setYear(int newYear)
{
    this->year = newYear;
}

void movies::movie::setGenre(string newGenre)
{
    this->genre = newGenre;
}

void movies::movie::setRating(int newRating)
{
    this->rating = newRating;
}

void movies::movie::setDirector(string newDirector)
{
    this->director = newDirector;
}
