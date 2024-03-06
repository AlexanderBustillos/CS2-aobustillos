#pragma once
#include <cmath>
#include <iostream>

using namespace std;

namespace movies
{
    class movie
    {
        private:
            string id;
            string title;
            string year;
            string genre;
            string rating;
            string director;
            // int numMovies;
        public:
            //constructor
            movie(string = "", string = "", string = "", string = "", string = "", string = "");//nummovies
            //destructor
            ~movie();

            //getters
            string getId();
            string getTitle();
            string getYear();
            string getGenre();
            string getRating();
            string getDirector();

            //setters
            void setId(string);
            void setTitle(string);
            void setYear(string);
            void setGenre(string);
            void setRating(string);
            void setDirector(string);

        //functions
         

        
    };
    
    
    
}