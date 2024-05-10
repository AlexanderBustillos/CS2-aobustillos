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
    //Very cool recursion, if there IS something in the root then you call to delete the left side of the root and the right side of the roo then deleteing the root
    destroyTree(root->getLeft());
    destroyTree(root->getRight());
    delete root;
}

// Public method that takes in some data and passes that into the removeData method. Don't forget to update _root as you may end up deleting the original root.
template <class T1>
void BST<T1>::remove(T1 data)
{
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
          if (root == nullptr)
    {
        return root;
    }

    if (data < root->getData())
    {
        root->setLeft(removeData(root->getLeft(), data));
    }
    else if (data > root->getData())
    {
        root->setRight(removeData(root->getRight(), data));
    }
    else
    {
        if (root->getLeft() == nullptr)
        {
            Node<T1> *temp = root->getRight();
            delete root;
            return temp;
        }
        else if (root->getRight() == nullptr)
        {
            Node<T1> *temp = root->getLeft();
            delete root;
            return temp;
        }
        else
        {
            Node<T1> *temp = minVal(root->getRight());
            root->setData(temp->getData());
            root->setRight(removeData(root->getRight(), temp->getData()));
        }
    }

    return root;
}

// Given a node, find the smallest value in that subtree. Return that node
template <class T1>
Node<T1> *BST<T1>::minVal(Node<T1> *root)
{
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
  if (root == nullptr || root->getData() == data)
    {
        return root;
    }

    if (data < root->getData())
    {
        return searchData(root->getLeft(), data);
    }
    else
    {
        return searchData(root->getRight(), data);
    }
}

// Wrapper function for searchData. Pass data, root into searchData and return true if data found, return false if data not found.
template <class T1>
bool BST<T1>::search(T1 data)
{
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
    inOrderPrint(_root);
}

// Give some data and a node, recursively walk the tree until you get to a nullptr and store the value there.
// You should ensure that if data < the current node's data, you walk the left. If data > current node's data, walk right.
// You should check if the value already exists and say so (it's just adding an else with a cout).
template <class T1>
Node<T1> *BST<T1>::insertNode(Node<T1> *root, T1 data)
{
    if(root == nullptr)
    {
     Node<T1>* _root = new Node<T1>();
     _root->setData(data);
     return _root;
    }
     if (data < root->getData())
    {
        root->setLeft(insertNode(root->getLeft(), data));
    }
    else if (data > root->getData())
    {
        root->setRight(insertNode(root->getRight(), data));
    }
    else if(data == root->getData())
    {
        cout << "Duplicate data" << endl;
    }

    return root;
}

// Wrapper for insertNode. Take in data to pass that and _root to insertNode. Ensure you update _root since if the tree is empty, that would be the new _root.
template <class T1>
void BST<T1>::insert(T1 data)
{
    // if( _root ==  nullptr)
    // {
    //     // Node<T1>* _root = new Node<T1>();
    //     Node<T1>* _root = nullptr;

    // }
    _root= insertNode(_root, data);
}