    #include "database.h"

    #include <iostream>
    #include <fstream>



    using namespace databases;


    //constructor
    database::database() 
    {
        name = "No name";
        db_id = "No id";
        //forloop
        movieList[100] = nullptr ;
    }

    // database::database()
    // { 
    //     this->name = _name;
    //     this->db_id = _db_id;

    // }

    //destructor
    database::~database()
    {

    }

    //getters
    string database::getName()
    {
        return name;
    }

    string database::getdb_id()
    {
        return db_id;
    }

    // database* databases::database::getmovies()
    // {
    //     return movieList;
    // }

    //setters
    void database::setName(string newName)
    {
        this->name = newName;
    }

    void database::setdb_id(string newdb_id)
    {
        this->db_id = db_id;
    }
    // void database::setMovies(database* newMovies)
    // {
    //     this->movies = newMovies;
    // }

    // void database::initmovies(movie* movieList[],int arrSize)
    // {
    //     for(int i = 0; i < arrSize ; i++)
    //     {
    //         movies[i] = new movies[i];
    //     }
    //     //parse line 
    // }
    void readFile(movies::movie* movies[],int arrSize)
    {
        ifstream fin;
        string filename = "movies.csv";

        string num;
        
        fin.open(filename);

        while(fin>>num)
        {
            cout << num<< endl;;
        }

    }