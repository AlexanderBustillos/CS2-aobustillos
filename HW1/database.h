#include "movie.h"

#pragma once
#include <cmath>
#include <iostream>


using namespace std;

namespace databases
{
    class database
    {
    private:
        int arrSize;
        string name;
        string db_id;
        movies::movie* movieList[100];
    public:
        //constuctor
        database();
        database(string = "", string = "", database* = nullptr );

        //destructor
        ~database();

        //Getters
        string getName();
        string getdb_id();
        database* getmovies();

        //setters
        void setName(string);
        void setdb_id(string);
        void setMovies(database*);

        // void database::initdatabase(database* data[],int arrSize);
        void initmovies(database* movies[], int arrSize);
        //get arr size?
        void readFile(movies::movie* movies[],int arrSize);
    };
};