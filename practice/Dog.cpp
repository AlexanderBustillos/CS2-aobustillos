#include "Dog.h"

#include <iostream>

using namespace std;

Dog::Dog()//default cosntrutor
{
   y = 10;
   x = 5;

}

Dog::Dog(int x)//constructor w a parameter
{
    y = 1;
    this->x = x;
}
