#include "music.h"

//constructor
musics::music::music(string _composer, string _numTracks , string _totalPlaytime)
{
    this->composer = _composer;
    this->numTracks = _numTracks;
    this->totalPlaytime = _totalPlaytime;
}
//destructor
musics::music::~music()
{

}

//getters

string musics::music::getComposer()
{
    return composer;
}
string musics::music::getNumTracks()
{
    return numTracks;
}
string musics::music::getTotalPlaytime()
{
    return totalPlaytime;
}

//setters
void musics::music::setComposer(string newComposer)
{
    this->composer = newComposer;
}

void musics::music::setNumTracks(string newNumTracks)
{
    this->numTracks = newNumTracks;
}

void musics::music::setTotalPlaytime(string newTotalPlaytime)
{
    this->totalPlaytime = newTotalPlaytime;
}