#pragma once
#include "media.h"
#include "movie.h"
#include "tvshows.h"
#include "music.h"
#include <cmath>
#include <iostream>


using namespace std;

namespace databases
{
    class database
    {
    private:
        int movieArrSize = 0;
        int tvshowArrSize = 0;
        int musicArrSize = 0;
        string name;
        string db_id;
        movies::movie* movieList[100];
        tvshows::tvshow* tvshowList[100];
        musics::music* musicList[100];
        
    public:
        //constuctor
        database(string = "", string = "");

        //destructor
        ~database();

        //Getters
        string getName();
        string getdb_id();
        // database* getmovies();

        //setters
        void setName(string);
        void setdb_id(string);
        // void setMovies(database*);

        // void database::initdatabase(database* data[],int arrSize);
        void initmedia();
        void readFile();
        void printMedia();
        void addMedia();
        void removeMedia();
        void searchMedia();
        void transferData();
        void freemem();

    };
};