/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Neeraj
 *
 * Created on June 29, 2018, 5:49 PM
 */


#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */


void quickSort(vector<int>& array, int start, int end);

int partition(vector<int>&array, int start, int end);


int main(int argc, char** argv) {
    
    srand(time(0));
    vector <int> array;
    
    
    for(int i = 0; i < 10; i++)
        array.push_back(rand()%10000);
    
    quickSort(array, 0, array.size() - 1);
    cout << "Hello" << endl;
    
//    
    for(int i = 0; i < 10; i++)
        cout << array[i] << endl;
    
    return 0;
}

void quickSort(vector<int>& array, int start, int end)
{
    int pivotIndex;
    
    if(start < end)
    {
        pivotIndex = partition(array, start, end);    
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);   
    }    
}

int partition(vector<int>&array, int start, int end)
{
//    cout << " Printing end " << end << endl;
    int pivot = array[end];
    int pivotIndex = start;
    
    for(int i = start; i < end; i++)
    {
        if(array[i] <= pivot)
        {
            int temp = array[pivotIndex];
            array[pivotIndex] = array[i];
            array[i] = temp;
            pivotIndex++;
        }
    }
    
    int temp = array[pivotIndex];
    array[pivotIndex] = array[end];
    array[end] = temp;
    
    return pivotIndex;
}