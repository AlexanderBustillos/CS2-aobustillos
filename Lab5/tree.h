#pragma once
#include "node.h"
using namespace std;
template <class T1>
class BST
{
private:
    Node<T1> *_root;
    Node<T1> *insertNode(Node<T1> *, T1);
    void inOrderPrint(Node<T1> *);
    Node<T1> *searchData(Node<T1> *, T1);
    Node<T1> *removeData(Node<T1> *, T1);
    Node<T1> *minVal(Node<T1> *);
    // void BST<T1>::destroyTree(Node<T1>* root);
    void destroyTree(Node<T1>* root);

public:
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1);
    ~BST();
};

// Destructor, should call destroyTree, passing _root to that method
template <class T1>
BST<T1>::~BST()
{
    destroyTree(_root);
}

// This should recursively walk the tree and delete a node if both leafs are null. You can return from a void function if you just have the return statement.
// This is useful if root == nullptr...
template <class T1>
void BST<T1>::destroyTree(Node<T1>* root)
{
    // if there is nothing in the root then return/do nothing
    if(_root == nullptr)
    {
    return;
    }
    //Very cool recursion, if there IS something in the root then you call to delete the left side of the root and the right side of the root then deleteing the root
    // this means that technically the leafs of the root are not there own seperate roots with leafs.
    destroyTree(root->getLeft());
    destroyTree(root->getRight());
    delete root;
}

// Public method that takes in some data and passes that into the removeData method. Don't forget to update _root as you may end up deleting the original root.
template <class T1>
void BST<T1>::remove(T1 data)
{
    // wrapper? updating root and removing thhe data
    _root = removeData(_root, data);
    return;
}

// Private method to recursively walk the tree until the data is found.
// Then using the process built in class, check if there is only one leaf, if so then move that leaf into the root position.
// If there are two leafs, find the smallest value in the right subtree (or the largest value in the left subtree but you would have to rename minVal method) and then replace
// the current node with that.
// Don't forget to clean up your memory!
template <class T1>
Node<T1> *BST<T1>::removeData(Node<T1> *root, T1 data)
{   
    // if the root is nothing then there is noting to do
    if (root == nullptr)
    {
        return root;
    }
    // the root that is passed in is the main root of the whole tree, so if data is smaller then that root then it MUST mean that we are going somewhere left
    if (data < root->getData())
    {
        //now we are setting the left of the root to be removed, because we havnt found the data yet in the list
        root->setLeft(removeData(root->getLeft(), data));
    }
    else if (data > root->getData())
    {
        // we are still looking for the data so we have to look on the right side incase its bigger
        root->setRight(removeData(root->getRight(), data));
    }
    else
    {
        //for this section i used AI to get a outline
        //if the left side of the root is equal to nullptr that means nothing is there, then we get the right side and return it
        if (root->getLeft() == nullptr)
        {
            Node<T1> *temp = root->getRight();
            delete root;
            return temp;
        }
        //same thing if the right is nothing then we get the left side and return it
        else if (root->getRight() == nullptr)
        {
            Node<T1> *temp = root->getLeft();
            delete root;
            return temp;
        }
        else
        {
            // we get the minimum value of the left side and set it to the temp, we then get the value of that data and set it to the root
            //then the left side of the root is removed
            Node<T1> *temp = minVal(root->getLeft());
            root->setData(temp->getData());
            root->setLeft(removeData(root->getLeft(), temp->getData()));
        }
    }

    return root;
}

// Given a node, find the smallest value in that subtree. Return that node
template <class T1>
Node<T1> *BST<T1>::minVal(Node<T1> *root)
{
    //we get our node and go left, as long as the left leaf does not equal null ptr then we an keep walking the left side of the tree untill we get a 
    // nullptr, because we know once we  get null ptr thats the last leaf and the smallest, then we return that value
    Node<T1>* current = root;
    while(current->getLeft() != nullptr)
    {
    current = current->getLeft();
    }
    return current;
}

// Given data and a node, recursively walk the tree to find that node if it exists.
template <class T1>
Node<T1> *BST<T1>::searchData(Node<T1> *root, T1 data)
{
    // if the root is a null ptr we dont do anything, or if the root is equal to data then we already have our node!
    if (root == nullptr || root->getData() == data)
    {
        return root;
    }
    // this uses the same logic as one of the previous functions, if the data is less then the root then we know that its going to be left of the main root
    if (data < root->getData())
    {
        // I love recursion !!!!!!!!!!!
        // we return the root that we are current at,(left of the main root) and put that into search data, if that root is equal to data then it instantly return back the root and 
        // it returns the root here aswell
        return searchData(root->getLeft(), data);
    }
    else
    {
        // same thing here but if its not equal or smaller then it has to be bigger so we go to the right
        return searchData(root->getRight(), data);
    }
}

// Wrapper function for searchData. Pass data, root into searchData and return true if data found, return false if data not found.
template <class T1>
bool BST<T1>::search(T1 data)
{
    //Once all the awesome recursion happens we get the result and check if its true, it should be true because the code works, i think
    Node<T1>* result = searchData(_root, data);
    if (result->getData() == data)
    {
        return true;
    }
    else
    {
    return false;
    }
}

// Given a node, recursively walk the tree to print out the inOrder format. That's left->root->right.
// Make sure you cout with a space separating each value as I based my tests on that!
// For example, you would end up cout (do not add the "): "1 2 3 4 5 "
// Notice that there is an extra space at the end.
template <class T1>
void BST<T1>::inOrderPrint(Node<T1> *root)
{
    // as long as root equals something we can print the function by going left first then right and a space in the middle
    if (root != nullptr)
    {
        inOrderPrint(root->getLeft());
        cout << root->getData()<< " ";
        inOrderPrint(root->getRight());
    }

}

// Wrapper for inOrderPrint
template <class T1>
void BST<T1>::inOrder()
{
    //wrapper???????
    inOrderPrint(_root);
}

// Give some data and a node, recursively walk the tree until you get to a nullptr and store the value there.
// You should ensure that if data < the current node's data, you walk the left. If data > current node's data, walk right.
// You should check if the value already exists and say so (it's just adding an else with a cout).
template <class T1>
Node<T1> *BST<T1>::insertNode(Node<T1> *root, T1 data)
{
    //if the root is empty then lets do something about it and make a root
    if(root == nullptr)
    {
     Node<T1>* _root = new Node<T1>();
     _root->setData(data);
     return _root;
    }
    //if the data is smaller then the root then insert the data into the left side of the root
     if (data < root->getData())
    {
        root->setLeft(insertNode(root->getLeft(), data));
    }
    //same thing but for the right side if its better
    else if (data > root->getData())
    {
        root->setRight(insertNode(root->getRight(), data));
    }
    //if the number is the same then just say it is
    else if(data == root->getData())
    {
        cout << "Already inputed" << endl;
    }

    return root;
}

// Wrapper for insertNode. Take in data to pass that and _root to insertNode. Ensure you update _root since if the tree is empty, that would be the new _root.
template <class T1>
void BST<T1>::insert(T1 data)
{
    // i tried getting fancy here but i didnt know what i was doing
    // if( _root ==  nullptr)
    // {
    //     // Node<T1>* _root = new Node<T1>();
    //     Node<T1>* _root = nullptr;

    // }
    // wrapper and updating root
    _root= insertNode(_root, data);
}