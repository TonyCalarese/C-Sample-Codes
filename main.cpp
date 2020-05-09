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

#include <iostream>
//#include "bst.h"
#include "sortingFunctions.h"
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main()
{
    int size = 20, *mData = new int[size], j = 0;
    int LB = 0, UB = size - 1;
    //creating worse case scenario
    for (int i = size; i > 0; i--)
    {
        mData[j] = i;
        j++;
    }
    
    quickSort(size, mData, LB, UB);
    selectionSort(size, mData);
    insertionSort(size, mData);
    bubbleSort(size, mData);
    cycleSort(size, mData);
    shellSort(size, mData);
    mergeSort(mData, LB, UB);
    
    BST<int> tree;
    for (int i = 0; i < size; i = i + 2)
    {
        cout << "Inserting:  " << i << "\n";
        tree.insert(i);
    }
    tree.displayTree();
    tree.destroyTree();
    system("pause");
    
    
    
    
    

    return 0;
}
