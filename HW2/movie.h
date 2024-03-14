#pragma once
#include "media.h"
#include <cmath>
#include <iostream>

using namespace std;

namespace movies
{
    class movie : public medias::media
    {
        private:
            string director;
            string rating;
        public:
            //constructor
            movie( string = "", string = "");
            //destructor
            ~movie();

            //getters
            string getRating();
            string getDirector();

            //setters
            void setRating(string);
            void setDirector(string);
    };
    
    
    
}