#include "tvshows.h"

//constructor
tvshows::tvshow::tvshow(string _numEpisodes, string _rating)
{
    this->numEpisodes = _numEpisodes;
    this->rating = _rating;
}

//destructor for when i need one?
tvshows::tvshow::~tvshow()
{

}

//getters

string tvshows::tvshow::getNumEpisodes()
{
    return numEpisodes;
}

string tvshows::tvshow::getRating()
{
    return rating;
}

//setters

void tvshows::tvshow::setNumEpisodes(string newNumEpisodes)
{
    this->rating = newNumEpisodes;
}

void tvshows::tvshow::setRating(string newRating)
{
    this->rating = newRating;
}
