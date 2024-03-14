#include "media.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


// using namespace databases;

// constructor
medias::media::media(string _id, string _title, string _year, string _genre)
{
    this->id = _id;
    this->title = _title;
    this->year = _year;
    this->genre = _genre;
   
}
//Getters
string medias::media::getId()
{
    return id;
}

string medias::media::getTitle()
{
    return title;
}
string medias::media::getYear()
{
    return year;
}
string medias::media::getGenre()
{
    return genre;
}

//setters
void medias::media::setId(string newId)
{
    this->id = newId;
}
void medias::media::setTitle(string newTitle)
{
    this->title = newTitle;
}
void medias::media::setYear(string newYear)
{
    this->year = newYear;
}
void medias::media::setGenre(string newGenre)
{
    this->genre = newGenre;
}