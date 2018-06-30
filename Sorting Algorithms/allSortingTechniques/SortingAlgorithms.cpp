/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Neeraj
 *
 * Created on March 30, 2018, 1:18 AM
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "dataGenerator.h"  // data is generated in a seperate File and included in the main Program

using namespace std;

//Global Variable declarations //
static long swapCount = 0;
static long compare = 0;
vector <int> sizeArray = {25000}; // Can Add any size here and compare the performance
vector <string> dataType = {"All Zeros", "Sequential Data", "Reverse Data", "Random Data"};
vector <string> sortType = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Shell Sort", "Merge Sort", "Quick Sort"};

// Basic Sorts
void bubbleSort(vector<int>&data, string dataType);
void selectionSort(vector<int>&data, string dataType);
void insertionSort(vector<int>&data, string dataType);
void shellSort(vector<int>&data, string dataType);

// Merge Sort
void mergeSort(vector<int>&data, string dataType);
void merge(vector<int>&left, vector<int>&right, vector<int>&sortedArray);

// Quick Sort // One of the fastest. Default sorting technique in sort algorithm
void quickSort(vector<int>&data, int start, int end);
int partition(vector<int>&data, int start, int end);

// General Program usage //
void swapData(vector<int>&data, int index1, int index2);
bool isSorted(const vector<int> data);
void printData(const vector<int> data, auto totTime, string dataType, string SortType);

/*
 * Main Program, keeps iterting for each sorting technique and each sort size
 */
int main() 
{
    srand(time(0));    
    vector<int> data;    
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Sort Method"  << setw(20) << "Sort Data Type" << setw(20) << "Total Data Size" << setw(20) << "Time Taken in ms" << setw(20) << "Total Swaps" << setw(20) << "Total Compares" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    
    for(int k = 0; k < sortType.size(); k++)
    {    
        for(int i = 0; i < sizeArray.size(); i++)
        {
            for(int j = 0; j < dataType.size(); j++)
            {
                if ( j == 0 )
                    allZeros(data, sizeArray[i]);  
                else if ( j == 1 )
                    sequentialDataGen(data, sizeArray[i]); 
                else if ( j == 2 )
                    reverseDataGen(data, sizeArray[i]);
                else
                    randomDataGen(data, sizeArray[i]);
                
                if ( k == 0)
                    bubbleSort(data, dataType[j]);
                else if ( k == 1)
                    selectionSort(data, dataType[j]);
                else if (k == 2)
                    insertionSort(data, dataType[j]);
                else if ( k == 3)
                    shellSort(data, dataType[j]);
                else if (k == 4)
                {
                    auto tStart = chrono::high_resolution_clock::now();
                    mergeSort(data, dataType[j]);
                    auto tEnd = chrono::high_resolution_clock::now();    
                    auto tTotal = chrono::duration<double, milli>(tEnd-tStart).count();
                    printData(data, tTotal, dataType[j], "Merge Sort");
                }
                else if(k == 5)
                {
                    auto tStart = chrono::high_resolution_clock::now();
                    quickSort(data, 0, data.size() - 1);
                    auto tEnd = chrono::high_resolution_clock::now();    
                    auto tTotal = chrono::duration<double, milli>(tEnd-tStart).count();
                    printData(data, tTotal, dataType[j], "Quick Sort");                    
                }
            }
            cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        }    
    }    
    return 0;
}

// Bubble Sort Begin // 
void bubbleSort(vector<int>& data, string dataType)
{    
    auto tStart = chrono::high_resolution_clock::now();    
    int temp; 
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data.size() - i - 1; j++)
        {
            compare++;                    
            if(data[j] > data[j+1])            
                swapData(data, j, j+1);                      
        }
    }
    
    auto tEnd = chrono::high_resolution_clock::now();    
    auto tTotal = std::chrono::duration<double, std::milli>(tEnd-tStart).count();
    
    printData(data, tTotal, dataType, "Bubble Sort");
    return;
}
// Bubble Sort End // 

// Selection Sort Begin //
void selectionSort(vector<int>&data, string dataType)
{
    auto tStart = chrono::high_resolution_clock::now();
    for(int i = 0; i < data.size(); i++)
    {
        int min = data[i];
        int minIndex = i;
        
        for(int j = i + 1; j < data.size(); j++)
        {
            compare++;
            if(data[j] < min)         
            {
                min = data[j];
                minIndex = j;
            }
        }
        
        if ( i != minIndex)
            swapData(data, i, minIndex) ;//min, i) ;//, min);        
    }
    
    auto tEnd = chrono::high_resolution_clock::now();    
    auto tTotal = std::chrono::duration<double, std::milli>(tEnd-tStart).count();
    
    printData(data, tTotal, dataType, "Selection Sort");
    return;
}
// Selection Sort Ends //

// Insertion Sort Begins //
void insertionSort(vector<int>&data, string dataType)
{
    auto tStart = chrono::high_resolution_clock::now();
    for(int i = 1; i < data.size(); i++)
    {
        int j;
        int current = data[i];
        
        for(j = i; j > 0 && current < data[j - 1]; j--)
        {
            compare++;
            //swapData(data, j, j - 1);
            //swapCount++;
            data[j] = data[j-1];
        }
        
        if(data[i] != current)
            swapCount++;
        
        data[j] = current;		
    }    
    auto tEnd = chrono::high_resolution_clock::now();    
    auto tTotal = std::chrono::duration<double, std::milli>(tEnd-tStart).count();
    
    printData(data, tTotal, dataType, "Insertion Sort");
    return;
}
// Insertion Sort Ends //

// Shell sort Begins //
void shellSort(vector<int>&data, string dataType)
{
    // h = 3 * x + 1
    auto tStart = chrono::high_resolution_clock::now();
    int size = data.size();
    int counter = 1;
    int gap = 1;
        
    while(gap < size / 3)
        gap = 3 * gap + 1;
        //counter++;
    
    while(gap != 1)
    {
        //cout << "Doing for Gap " << gap << endl;
        for(int i = 0; i < data.size() - gap; i++)
        {
            compare++;
            if(data[i] > data[i + gap - 1])
                swapData(data, i, i + gap - 1);
        }
        
        gap -= 1;
        gap /= 3;
    }
    if(gap == 1)
    {

        for(int i = 1; i < data.size(); i++)
        {
            int current = data[i];
            int j;
            
            for(j = i; j > 0 && current < data[j - 1]; j--)
            {
                compare++;
                data[j] = data[j - 1];
            }
            
            if(data[i] != current)
                swapCount++;
            
            data[j] = current;
        }
    }

    auto tEnd = chrono::high_resolution_clock::now();    
    auto tTotal = std::chrono::duration<double, std::milli>(tEnd-tStart).count();
    
    printData(data, tTotal, dataType, "Shell Sort");
    return;
}
// Shell sort Ends //

//Merge Sort Logic Begin //
void mergeSort(vector<int>&data, string dataType)
{
    int arraySize = data.size();
    int mid = arraySize / 2;    
    vector<int> left;
    vector<int> right;
    
    if (arraySize < 2)
        return;
    
    for(int i = 0; i <= mid - 1; i++)
        left.push_back(data[i]);
    
    for(int i = mid; i < arraySize; i++)
        right.push_back(data[i]);
    
    mergeSort(left, dataType);
    mergeSort(right, dataType);
    merge(left, right, data);
    
    return;    
}

void merge(vector<int>&left, vector<int>&right, vector<int>&sortedArray)
{
    int leftSize = left.size();
    int rightSize = right.size();
    
    int leftInc = 0, rightInc = 0, index = 0;
    
    while(leftInc < leftSize && rightInc < rightSize)
    {
        compare++;
        if(left[leftInc] < right[rightInc])
        {
            sortedArray[index] = left[leftInc];
            leftInc++;
        }
        else
        {
            sortedArray[index] = right[rightInc];
            rightInc++;
        }
        index++;
    }
    
    while(leftInc < leftSize)
    {
        sortedArray[index] = left[leftInc];
        index++;
        leftInc++;
    }
    
    while(rightInc < rightSize)
    {
        sortedArray[index] = right[rightInc];
        index++;
        rightInc++;
    }
    
    return;
}
//Merge Sort Logic ends //

// Quicksort Logic Begin // 
void quickSort(vector<int>&data, int start, int end)
{
    if(start < end)
    {
        int pivotIndex = partition(data, start, end);
        quickSort(data, start, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, end);
    }
}

int partition(vector<int>&data, int start, int end)
{
    int pivot = data[end];
    int pivotIndex = start;
    
    for(int i = start; i < end; i++)
    {
        compare++;
        if(data[i] < pivot)
        {
            swapData(data, i, pivotIndex);
            pivotIndex++;
        }
    }
    
    swapData(data, pivotIndex, end);    
    return pivotIndex;    
}

// Quicksort Logic End // 

// General Program Needs Begin //
void swapData(vector<int>&data, int index1, int index2)
{   
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
    
    swapCount++;    
    return;
}

void printData(const vector<int> data, auto totTime, string dataType, string sortType)
{ 
    if(isSorted(data))
        cout << setw(20) << left << sortType << setw(20) << dataType << setw(20) 
             << data.size() << setw(20) << totTime << setw(20) << swapCount 
             << setw(20) << compare << endl;
    else    
        cout << "Incorrect data Appearing, Please Check" << endl;
    
    swapCount = 0;
    compare = 0;
    return;
}

bool isSorted(const vector<int> data)
{
    for(int i = 0; i < data.size(); i++)
        for(int j = i; j < data.size(); j++)
            if(data[i] > data[j])
                return false;
        
    return true;
}
// General Program Needs End //