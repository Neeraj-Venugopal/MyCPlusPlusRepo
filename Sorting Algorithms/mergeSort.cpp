/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Neeraj
 *
 * Created on June 29, 2018, 1:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */


void mergeSort(vector<int>& array);

void merge(vector<int>& left, vector<int>& right, vector<int>& sortedArray);


int main(int argc, char** argv) {
    
    srand(time(0));
    vector <int> array;
    
    
    for(int i = 0; i < 10; i++)
        array.push_back(rand()%10000);
    
    mergeSort(array);
    
//    
    for(int i = 0; i < 10; i++)
        cout << array[i] << endl;
    
    return 0;
}

void mergeSort(vector<int>& array)
{
//    cout << "Hello" << endl;
    
    int arraySize = array.size();
    int mid = arraySize / 2;
    vector<int> left;
    vector<int> right;
    
    if (arraySize < 2)
        return;
//    
//    for(int i = 0; i < array.size(); i++)
//        cout << array[i] << endl;
    
    for(int i = 0; i <= mid - 1; i++)
        left.push_back(array[i]);
    
    for(int j = mid; j < arraySize; j++)    
        right.push_back(array[j]);
    
    mergeSort(left);
    mergeSort(right);
    
    merge(left, right, array);
    
    
//    for(int i = 0; i < left.size(); i++)
//        cout << left[i] << " Left" << endl;
//    
//    for(int i = 0; i < right.size(); i++)
//        cout << right[i] << " Right" << endl;
}


void merge(vector<int>& left, vector<int>& right, vector<int>& sortedArray)
{
    int sizeLeft = left.size();
    int sizeRight = right.size();
    
    int leftInc = 0;
    int rightInc = 0;
    int index = 0;
    
    
    while ( leftInc < sizeLeft && rightInc < sizeRight)
    {
        if(left[leftInc] < right[rightInc])
        {
            sortedArray[index] = left[leftInc];
            index++;
            leftInc++;
        }
        
        else
        {
            sortedArray[index] = right[rightInc];
            index++;
            rightInc++;
        }
    }
    
    while(leftInc < sizeLeft)
    {
        sortedArray[index] = left[leftInc];
        index++;
        leftInc++;
    }
    
    while(rightInc < sizeRight)
    {
        sortedArray[index] = right[rightInc];
        index++;
        rightInc++;
    }
    return;    
}