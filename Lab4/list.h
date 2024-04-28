#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
   _tail = nullptr;
    listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    while (_head->getNext() != nullptr)
    {

        _head= _head->getNext();
        delete _head->getPrev();

    }
    
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
return(_head == nullptr && listSize == 0 && _tail == nullptr);
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    // int numOfEl;
    // if (_head == nullptr)
    // {
    //     return numOfEl = listSize +2;
    // }
    // else
    // {
    //     return 0;
    // }
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1>* newNode = new Node<T1>();  // Create a new node
    newNode->setData(data);  // Set the data of the new node
    if(empty() == true)
    {
        _head = newNode;
        _tail = newNode;
    }
        newNode->setNext(_head);
        _head->setPrev(newNode);
        _head=newNode;
        listSize++;

}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if(empty() == true)
    {
        cout << "Empty"<< endl;
        return 0;
    }
    else 
    {
        return _head->getData();
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
     if (empty()) {
        cout << "Empty" << endl;
        return 0;
    }
    Node<T1>* oldHead = _head; 
    T1 data = oldHead->getData(); 

    _head = _head->getNext(); 
    if (_head != nullptr) {
        _head->setPrev(nullptr);
    } 
    delete oldHead;  
    listSize--;
    return data;  
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1>* newNode = new Node<T1>();  // Create a new node
    newNode->setData(data);  // Set the data of the new node
    if(empty() == true)
    {
        _head = newNode;
        _tail = newNode;
    }
        newNode->setPrev(_tail);
        _tail->setNext(newNode);
        _tail=newNode;
        listSize++;
    

}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if(empty() == true)
    {
        cout << "Empty"<<endl;
       return 0;
    }
    else
    {
    return _tail->getData();
    }
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if (empty()) {
        cout << "Empty" << endl;
        return 0;
    }
    Node<T1>* oldTail = _tail; 
    T1 data = oldTail->getData();
    _tail = _tail->getPrev(); 
    if (_tail != nullptr) {
        _tail->setNext(nullptr); 
    }
    delete oldTail;
    listSize--;
    return data;  
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    Node<T1>* curnode =list._head;
    while (curnode!=nullptr)
    {
    os << curnode->getData() << " ";
    curnode = curnode->getNext();
    }
    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    if (listSize != rhs.listSize) {
        return false;
    }
    Node<T1>* currentList1 = _head;
    Node<T1>* currentList2 = rhs._head;
    while (currentList1 != nullptr && currentList2 != nullptr) {
       
        if (currentList1->getData() != currentList2->getData()) {
            return false; 
        }

        currentList1 = currentList1->getNext();
        currentList2 = currentList2->getNext();
    }

    if(currentList1 == nullptr && currentList2 == nullptr )
    {
    return true;
    }

}