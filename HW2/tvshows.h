#pragma once
#include "media.h"
#include <cmath>
#include <iostream>


using namespace std;

namespace tvshows 
{
    class tvshow  : public medias::media
    {
        private:
            string numEpisodes;
            string rating;
            // movies::movie* movieList[100];
        public:
            //constuctor
            tvshow(string = "", string = "");

            //destructor
            ~tvshow();

            //Getters
            string getRating();
            string getNumEpisodes();
            // database* getmovies();
        
            //setters
            void setRating(string);
            void setNumEpisodes(string);
            
    };
};