#pragma once
#include "movie.h"
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
        void initmovies();
        //get arr size?
        void readFile();
        void printMovies();
        void addMovie();
        void removeMovie();
        void searchMovies();
        void transferData();

    };
};