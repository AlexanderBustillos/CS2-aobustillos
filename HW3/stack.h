#pragma once
#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

class Stack
{
    private:
        Node<double> *_top;
        size_t stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(double);
        double pop();
        double top();
};

// set to nullptr and initialize stackSize
Stack::Stack()
{
    _top = nullptr;
    stackSize = 0;
}

// iteratively delete the stack starting at top
Stack::~Stack()
{
    if (empty()== false )
    {
    Node<double>* current = _top;
    while (current != nullptr) 
    {
        Node<double>* next = current->getNext(); 
        delete current;
        current = next; 
        if (current != nullptr) {
            current->setPrev(nullptr); 
        }
        stackSize--;
    }
    }
}

// return true if the Stack is empty, false otherwise.
// Do not just check stackSize, should actually check top
bool Stack::empty()
{
    return(_top == nullptr && stackSize == 0);
}

// return number of elements in Stack
size_t Stack::size()
{
    return(stackSize);
}

// add an element to the beginning of the Stack, updating top
void Stack::push(double data)
{
    Node<double>* newNode = new Node<double>();  // Create a new node
    newNode->setData(data);  // Set the data of the new node
    if(empty() == true)
    {
        _top = newNode;
        stackSize++;
        return;
    }
        newNode->setNext(_top);
        _top=newNode;
        stackSize++;
}

// return the first element in the Stack.
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::top()
{
    if(empty() == true)
    {
        cout << "Error"<< endl;
        return NAN;
    }
    else 
    {
        return _top->getData();
    }
}

// remove the first element from the Stack and return its data
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::pop()
{
    if (empty()) {
        cout << "Error" << endl;
        return NAN;
    }
    Node<double>* oldTop = _top; 
    double data = oldTop->getData(); 

    _top = _top->getNext(); 
    if (_top != nullptr) {
        _top->setPrev(nullptr);
    } 
    else if ( _top == nullptr)
    {
        _top = nullptr;
    }
    delete oldTop;  
    stackSize--;
    return data;  
}