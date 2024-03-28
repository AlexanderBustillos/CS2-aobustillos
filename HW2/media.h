#pragma once
#include <cmath>
#include <iostream>


using namespace std;

namespace medias
{
    class media
    {
        private:
            string id;
            string title;
            string year;
            string genre;
            // movies::movie* movieList[100];
        public:
            //constuctor
            media(string = "", string = "", string = "", string = "");

            //destructor
            virtual ~media();

            //Getters
            string getId();
            string getTitle();
            string getYear();
            string getGenre();
            // database* getmovies();
        
            //setters
            void setId(string);
            void setTitle(string);
            void setYear(string);
            void setGenre(string);

            //functions
    };
}