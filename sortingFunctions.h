/*
Author: Tony Calarese
Description :
This lab is designed for us to learn and execute different types of sorting algorithms for an array
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
#ifndef _SORTINGFUNCTIONS_H
#define _SORTINGFUNCTIONS_H

#include <iostream>
#include <array>
#include <random>
#include <stdlib.h>
#include <time.h>


/*
pre:the size of the array and the array numbers[]
post:print()
purpose:The purpose of theis sorting algorithm is to use more of a brute force methodology to sort an actual array
*/
template <typename T>
void bubbleSort(T size, T numbers[])
{
    T i, j, tmp;

            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {
                    if (numbers[i] < numbers[j])
                    {
                        tmp = numbers[j];
                        numbers[j] = numbers[i];
                        numbers[i] = tmp;
                    }
                }
            }
            //printing
            for (T i = 0; i < size; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    std::cout << numbers[i] << " ";
                    i++;
                    if (i >= size)
                    {
                        break;
                    }
                }
                std::cout << std::endl;
            }
}
/*
pre: numbers, size
post: print
purpose: to circle through the aray until the array is sorted.
essentially this is used to prevent so many different memory writes at once
source for reference : http://www.geeksforgeeks.org/cycle-sort/
*/
template <typename T>
void cycleSort(T size, T numbers[])
{
    int tmp;
    //i is the start
    for (int i = 0; i <= size - 2; i++)
    {
        int start = numbers[i];
        int position = i;
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < start)
                position++;
        }
        if (position == i)
        {
            continue;
        }
        //if it is already at the start
        while (start == numbers[position])
        {
            position++;
        }

        if (position != i)
        {
            tmp = start;
            start = numbers[position];
            numbers[position] = tmp;
        }

        while (position != i)
        {
            position = i;
            for (int k = i + 1; k < size; k++)
            {
                if (numbers[k] < start)
                    position++;
            }
            while (start == numbers[position])
            {
                position++;
            }
            if (start != numbers[position])
            {
                tmp = start;
                start = numbers[position];
                numbers[position] = tmp;
            }
        }
    }
     //printing
     for (T i = 0; i < size; i++)
     {
         for (int j = 0; j < 10; j++)
         {
             std::cout << numbers[i] << " ";
             i++;
             if (i >= size)
             {
                 break;
             }
         }
         std::cout << std::endl;
     };
}
/*
pre:numbers, LB, UB
post:none
purpose: to loop throught the algorithm to eventually create the two arrays in merge
*/
template <typename T>
void mergeSort(T numbers[], T LB, T UB)
{
    T mid;

    if (LB < UB)
    {
        mid = (LB + UB) / 2;
        mergeSort(numbers, LB, mid);
        mergeSort(numbers, (mid + 1), UB);
        //Merge everything back together
        T i, j, k;

        T size1 = mid - LB + 1;
        T size2 = UB - mid;

        T *tmp1 = new T[size1 + 1];
        T *tmp2 = new T[size2 + 1];

        for (i = 0; i < size1; i++)
        {
            tmp1[i] = numbers[LB + i];
        }

        for (j = 0; j < size2; j++)
        {
            tmp2[j] = numbers[mid + j + 1];
        }
        //Make a very large number  for both indexes
        tmp1[i] = INT_MAX;
        tmp2[j] = INT_MAX;

        i = 0;
        j = 0;

        for (k = LB; k <= UB; k++)
        {
            if (tmp1[i] <= tmp2[j])
            {
                numbers[k] = tmp1[i];
                i++;
            }
            else
            {
                numbers[k] = tmp2[j];
                j++;
            }
        }
        delete[]tmp1;
        delete[]tmp2;
    }
    
}
/*
pre:size, numbers
post:print(size, numbers)
purpose: This algorithm is designed to sort an array using the insertion method as if it was like trading cards in your hand, picking and then placing the cards in the right order.
Source of reference: http://www.geeksforgeeks.org/insertion-sort/
*/
template <typename T>
void insertionSort(T size, T numbers[])
{
    T point, switchingPoint, tmp; //<-- This variable will act like a point at which the sorting will take place
                                    //switchingPoint is the point at which the switch is made
            for (T i = 1; i < size; i++)
            {
                // + 1 so switching point is begining
                point = numbers[i];
                //start at the begining
                switchingPoint = i - 1;

                // need to go through the array until it hits a number it cannot be greater than then work up the list
                while (switchingPoint >= 0 && numbers[switchingPoint] > point)
                {
                    tmp = numbers[switchingPoint];
                    numbers[switchingPoint + 1] = tmp;
                    switchingPoint--;
                }
                numbers[switchingPoint + 1] = point;
            }
    //printing
    for (T i = 0; i < size; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << numbers[i] << " ";
            i++;
            if (i >= size)
            {
                break;
            }
        }
        std::cout << std::endl;
    }
}

/*
pre:numbers size, UB, LB
post: print(sie, numbers)
purpose: to use the quickly sort the algorithm by using the divide and conquer technique
*/
template <typename T>
void quickSort(T size, T numbers[], T LB, T UB)
{
    T tmp, i = LB, j = UB;
    T pivot = numbers[(LB + UB) / 2];

    while (i <= j)
    {
        while (numbers[i] < pivot)
        {
            i++;
        }
        while (numbers[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            tmp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmp;
            i++;
            j--;
        }
    }
    if (LB < j)
    {
        quickSort(size, numbers, LB, j);
    }

    if (i < UB)
    {
        quickSort(size, numbers, i, UB);
    }
     //printing
     for (T i = 0; i < size; i++)
     {
         for (int j = 0; j < 10; j++)
         {
             std::cout << numbers[i] << " ";
             i++;
             if (i >= size)
             {
                 break;
             }
         }
         std::cout << std::endl;
     }
}
/*
Pre:numbers and size
Post: print(size, numbers)
purpose: Selection sort uses a selectioning method when it divides, by finding the minimum number and then rearranging by counting upwards
*/
template <typename T>
void selectionSort(T size, T numbers[]) {
    T minIndex, tmp;

    for (T i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (T j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            tmp = numbers[i];
            numbers[i] = numbers[minIndex];
            numbers[minIndex] = tmp;
        }
    }
     //printing
     for (T i = 0; i < size; i++)
     {
         for (int j = 0; j < 10; j++)
         {
             std::cout << numbers[i] << " ";
             i++;
             if (i >= size)
             {
                 break;
             }
         }
         std::cout << std::endl;
     }
}
/*
pre:size and numbers are needed before this can execute
post:print(size, numbers)
purpose: Shell sorting basically divides the array into a certain amount of parts dependng on the size of the array
and compares them to the corresponding value in the other created arrays and then sorts then accordingly.
*/
template <typename T>
void shellSort(T size, T numbers[]) {
    T gap, tmp, subDivider;
    gap = size / 2;
    do
    {
        subDivider = size - gap;
        for (int i = 0; i < subDivider; i++)
        {
            if (numbers[i] > numbers[i + gap])
            {
                tmp = numbers[i];
                numbers[i] = numbers[i + gap];
                numbers[i + gap] = tmp;
            }
        }
        gap = gap / 2;
    } while (gap > 0);
    
    //printing
    for (T i = 0; i < size; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << numbers[i] << " ";
            i++;
            if (i >= size)
            {
                break;
            }
        }
        std::cout << std::endl;
    }

}
#endif
