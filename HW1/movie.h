#pragma once
#include <cmath>
#include <iostream>

using namespace std;

namespace movies
{
    class movie
    {
    private:
        int id;
        string title;
        int year;
        string genre;
        int rating;
        string director;
        // int numMovies;
    public:
        //constructor
        movie(int = 0, string = "", int = 0, string = "", int = 0, string = "");//nummovies
        //destructor
        ~movie();

        //getters
        int getId();
        string getTitle();
        int getYear();
        string getGenre();
        int getRating();
        string getDirector();

        //setters
        void setId(int);
        void setTitle(string);
        void setYear(int);
        void setGenre(string);
        void setRating(int);
        void setDirector(string);

        //functions
         

        
    };
    
    
    
}