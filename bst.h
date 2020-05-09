/*
Author: Tony Calarese
Description :
This lab is designed for us to learn and execute How a binary search Tree works and functions
Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fullydocumented
references to the work of others.I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of
academic staff; and / or
-Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
Note: Most of this work is referenced from professor Wei's answer he provided to us students
*/

#ifndef _BST_H
#define _BST_H

#include <iostream>

using namespace std;

template <class T>
class BST
{
private:
    template <class T>
    struct Node
    {
        T mData;
        Node<T> *mLeft, *mRight;

        Node()
        {
            mData = T();
            mLeft = NULL;
            mRight = NULL;
        }

        Node(T data)
        {
            mData = data;
            mLeft = NULL;
            mRight = NULL;
        }
        Node(T data, Node<T> *left, Node<T> *right)
        {
            mData = data;
            mLeft = left;
            mRight = right;
        }
    };

    Node<T> *mRootNode;

    BST(T data, Node<T> *left = NULL, Node<T> *right = NULL);

    void destroySubtree(Node<T> *node);
    void displayInOrder(Node<T> *node);
    void displayPreOrder(Node<T> *node);
    void displayPostOrder(Node<T> *node);
    void displayTree(Node<T> *node, int tab);
    void insert(Node<T> *&node, const T &data);
    void makeDeletion(Node<T> *&node);
    void remove(Node<T> *&node, const T &searchKey);

public:
    BST();
    ~BST();

    void insert(T data);
    bool isEmpty();
    bool isExists(T searchKey);
    void remove(T searchKey);
    void showInOrder();
    void showPreOrder();
    void showPostOrder();
    void displayTree();
    void destroyTree();
};

/*
Pre:none
Post: none
Purpose: to provide an acccessor to the Binary search tree
*/
template <class T>
BST<T>::BST()
{
    mRootNode = NULL;
}

/*
Pre:node *left and node *right and data
Post: this accessor creates the initial Binary Search tree
Purpose: this is to get the Binary search tree started
*/
template <class T>
BST<T>::BST(T data, Node<T> *left = NULL, Node<T> *right = NULL)
{
    Node<T> *newNode;

    newNode = new Node(data, left, right);
    if (newNode != NULL)
        mRootNode = newNode;
}

/*
Pre: none
Post:none
Purpose: Deconstructor
*/
template <class T>
BST<T>::~BST()
{
    destroySubtree(mRootNode);
}


/*
Pre: node
Post: node
Purpose: to display the search tree's elements in asccending order
*/
//Done by me with the help from
//http://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
template <class T>
void BST<T>::displayInOrder(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    displayInOrder(node->mLeft);
    cout << "\t" << node->mData;
    displayInOrder(node->mRight);
}

/*
Pre: node
Post: node
Purpose: To display the search Tree's element's hierarchal order
*/
template <class T>
void BST<T>::displayPreOrder(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->mData << " ";
    displayPreOrder(node->mLeft);
    displayPreOrder(node->mRight);
}

/*
Pre: node
Post: node
Purpose: To display the search Tree's element's in descending order
*/
template <class T>
void BST<T>::displayPostOrder(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }

    displayPostOrder(node->mLeft);
    displayPostOrder(node->mRight);
    cout << node->mData << " ";
}

/*
Pre: Data
Post: none
Purpose: inserts objects into the tree
*/
template <typename T>
void BST<T>::insert(T data)
{
    Node<T> *tmp, *newNode;
    bool    inserted = false;

    newNode = new Node<T>(data);
    if (newNode == NULL)
    {
        return;
    }

    if (mRootNode == NULL)
    {
        mRootNode = newNode;
    }
    else
    {
        tmp = mRootNode;

        while (!inserted)
        {
            if (tmp->mData == data)
            {
                delete newNode;
                inserted = true;
            }
            else if (tmp->mData > data)
            {
                if (tmp->mLeft != NULL)
                    tmp = tmp->mLeft;
                else
                {
                    tmp->mLeft = newNode;
                    inserted = true;
                }
            }
            else
            {
                if (tmp->mRight != NULL)
                    tmp = tmp->mRight;
                else
                {
                    tmp->mRight = newNode;
                    inserted = true;
                }
            }
        }
    }
}


/*
Pre: node
Post: node
Purpose:private function to insert objects into the tree
*/
template <class T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
    if (node == NULL)
    {
        return;
    }
    else if (node->mData > data)
    {
        insert(node->mLeft, data);
    }
    else if (node->mData < data)
    {
        insert(node->mRight, data);
    }
    else
    {
        // We have found the node to delete.
        insert(data);
    }
}

/*
Pre: none
Post: true or false
Purpose: to determine if there is anything in the list
*/
template <class T>
bool BST<T>::isEmpty()
{
    return (mRootNode == NULL);
}

/*
Pre: SearchKey
Post: SearchKey
Purpose: To check if a certain value in the array exists or not
*/
template <class T>
bool BST<T>::isExists(T searchKey)
{
    Node<T> *tmp, *oneAbove;
    tmp = mRootNode;
    oneAbove = mRootNode;

    while (tmp != NULL)
    {
        oneAbove = tmp;

        if (tmp->mData == searchKey)
        {
            return true;
        }
        else if (tmp->mData > searchKey)
        {
            tmp = tmp->mLeft;
        }
        else
        {
            tmp = tmp->mRight;
        }
    }
    return false;
}

/*
Pre: node
Post: node
Purpose: the wrapper function to make a deletion in the tree
*/
template <class T>
void BST<T>::makeDeletion(Node<T> *&node)
{
    remove(node->mData);
}

/*
Pre: node and searchkey
Post: none
Purpose: the private function to remove a node
*/
template <class T>
void BST<T>::remove(Node<T> *&node, const T &searchKey)
{
    if (node == NULL)
    {
        return;
    }
    else if (node->mData > searchKey)
    {
        remove(node->mLeft, searchKey);
    }
    else if (node->mData < searchKey)
    {
        remove(node->mRight, searchKey);
    }
    else
    {
        // We have found the node to delete.
        makeDeletion(node);
    }
}


/*
Pre: node
Post:Remove()
Purpose: Wrapper Function to remove a node
*/
template <typename T>
void BST<T>::remove(T searchKey)
{
    Node<T> *tmp, *oneAbove, *attachPoint;

    tmp = mRootNode;
    oneAbove = mRootNode;

    while (tmp != NULL)
    {
        if (tmp->mData == searchKey) {
            break;
        }
        
        oneAbove = tmp;
        if (tmp->mData > searchKey) {
            tmp = tmp->mLeft;
        }
        else {
            tmp = tmp->mRight;
        }
    }

    if (tmp != NULL)
    {
        // tmp does not have a right child
        if (tmp->mRight == NULL)
        {
            // Replace tree with its left subtree.
            if (tmp == mRootNode)
                mRootNode = tmp->mLeft;
            else
            {
                if (tmp == oneAbove->mLeft)
                    oneAbove->mLeft = tmp->mLeft;
                else
                    oneAbove->mLeft = tmp->mRight;
            }
        }
        // tmp does not have a left child
        else if (tmp->mLeft == NULL)
        {
            if (tmp == mRootNode)
                mRootNode = tmp->mRight;
            else
            {
                if (tmp == oneAbove->mRight)
                    oneAbove->mRight = tmp->mRight;
                else
                    oneAbove->mRight = tmp->mLeft;
            }
        }
        //  tmp has two children
        else
        {
            // Move to right subtree.
            attachPoint = tmp->mRight;

            // Locate the smallest node in the right subtree
            // by moving as far to the left as possible.
            while (attachPoint->mLeft != NULL)
                attachPoint = attachPoint->mLeft;

            // Attach the left subtree of the original tree
            // as the left subtree of the smallest node
            // in the right subtree.
            attachPoint->mLeft = tmp->mLeft;

            // Replace the original tree with its right subtree.
            if (tmp == oneAbove->mLeft)
                oneAbove->mLeft = tmp->mRight;
            else
                oneAbove->mRight = tmp->mRight;
        }

        tmp->mLeft = NULL;
        tmp->mRight = NULL;
        // Delete root of original tree
        delete tmp;
    }
}

/*
Pre: node
Post: node
Purpose: wrapper function To display the search Tree's element's
*/
template <class T>
void BST<T>::showInOrder()
{
    displayInOrder(mRootNode);
}

/*
Pre: none
Post: displayPreOrder()
Purpose: wrapper function for the search Tree's element's in heirarchical order
*/
template <class T>
void BST<T>::showPreOrder()
{
    displayPreOrder(mRootNode);
}

/*
Pre: node
Post: ShowPostOrder()
Purpose:Wrapper function to display the search Tree's element's in descending order
*/
template <class T>
void BST<T>::showPostOrder()
{
    displayPostOrder(mRootNode);
}

/*
Pre: none
Post: displayTree()
Purpose: Wrapper function to display the tree's elements
*/
template <class T>
void BST<T>::displayTree()
{
    displayTree(mRootNode, 0);
}
/*
Pre: node, tab
Post: node
Purpose: To display the search Tree's element's
*/
template <class T>
void BST<T>::displayTree(Node<T> *node, int tab)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < tab; i++)
    {
        cout << "\t";
    }
    cout << node->mData << endl;
    tab++; //Push it more towards the center
    //Recursively follow out till null
    displayTree(node->mLeft, tab);
    displayTree(node->mRight, tab);

}
/*
Pre: node
Post: none
Purpose: This fuction will burn everything and make sure no element of the tree survives, also this is the wrapper function for destroy Tree
*/
template <class T>
void BST<T>::destroySubtree(Node<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    destroySubtree(node->mLeft);
    node->mLeft = NULL;
    destroySubtree(node->mRight);
    node->mRight = NULL;
    delete node;
    mRootNode = NULL;
}
/*
Pre: node
Post: none
Purpose: This fuction will burn everything and make sure no element of the tree survives
*/
template <class T>
void BST<T>::destroyTree()
{
    cout << "Destroying Tree..." << endl;
    destroySubtree(mRootNode);
}

#endif
