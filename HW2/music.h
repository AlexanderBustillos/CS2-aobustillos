#pragma once
#include "media.h"
#include <cmath>
#include <iostream>


using namespace std;

namespace musics
{
    class music  : public medias::media
    {
        private:
            string composer;
            string numTracks;
            string totalPlaytime;
            // movies::movie* movieList[100];
        public:
            //constuctor
            music(string = "", string = "",string = "");

            //destructor
            ~music();

            //Getters
            string getComposer();
            string getNumTracks();
            string getTotalPlaytime();
            // database* getmovies();
        
            //setters
            void setComposer(string);
            void setNumTracks(string);
            void setTotalPlaytime(string);

            
    };
};