#include "point.h"


//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    // im constructing my variables from main.cpp to be used for later
    this->nearestPoint = closestPoint;
    this->x = X;
    this->y = Y;
    
}
//Destructor
points::Point::~Point()
{
    // whenever delete is called,this deletes nearest point to not cause a memoy leak automatically
    // and then kills itself 
    // delete nearestPoint;
}

//Getters
int points::Point::getX()
{
    // get the x from the class, for a specific point (ei. test1)
    return x;
}

int points::Point::getY()
{
    //get the y from the class, for a specific point 
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    // returns the nearest point from the class of the specific point
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    // making doubles of dist and set
    int set;
    // making a class point named temp that has access to all the variables and functions under the class
    points::Point* temp;
    // calc nearest point is available to any class point, this means whenever i try to use calc nearest point i need to be specific
    // by saying THIS im saying that i want to use the distPoints from that specific class point, in this im setting to this distPoint which
    //calls distPoint and runs the calculations for the class point pointsList[1]
    // set = this->distPoints(*pointList[1]);
    set = 100000000;

    // a for loop that loops however long the size of the list is
    // cout<< " Debug"<< endl;
    for(unsigned long i = 0 ; i < arrSize; i++)
    {
    //dist is set to the distance of pointList[i] to my point i entered, it calls the function basically and we say this so it calls the distpoints of that 
    //specefic class point
        double closestPoint = distPoints(*pointList[i]);
        if( closestPoint < set )
        {
            set = closestPoint;
            temp = pointList[i];
            
        }

        // cout << pointList[i]->getX()<<" "<< pointList[i]->getY()<<  endl;
        //this just finds the closest point to my point
    }
    // cout << x <<" "<< y << endl;
    // cout << temp->getX()<<" "<< temp->getY()<<  endl;
    // cout<< set<< endl;
    return temp;
    //returns the final product
}

//Setters
void points::Point::setX(int newVal)
{
    // this is made to change the value of x, without it x is not changable
    this->x = newVal;
}

void points::Point::setY(int newVal)
{
    // this is made to be able to change the value of y, without it y is not changable
    this->y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    //so we can change nearest point, THIS is here because we want to acces the "setNearestPoint" from the class point, and the
    //only we to change private variavles is with a setter
    this->nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    //im taking the address of the point then im getting the x and y values of the point and calculating the distacne bewteen
    //my value and the value of the point and returning it
    return sqrt(((point.getX())-x)*((point.getX())-x)+ ((point.getY())-y)*((point.getY())-y));
}