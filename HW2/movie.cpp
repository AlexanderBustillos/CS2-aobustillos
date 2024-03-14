#include "movie.h"

//constructor
movies::movie::movie(string _rating, string _director)
{
    this->rating = _rating;
    this->director = _director;
}

//destructor for when i need one?
movies::movie::~movie()
{

}

//getters

string movies::movie::getRating()
{
    return rating;
}

string movies::movie::getDirector()
{
    return director;
}

//setters

void movies::movie::setRating(string newRating)
{
    this->rating = newRating;
}

void movies::movie::setDirector(string newDirector)
{
    this->director = newDirector;
}
