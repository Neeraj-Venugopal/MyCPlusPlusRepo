/* 
 * File:   dataGenerator.cpp
 * Author: Neeraj
 * 
 * Created on June 29, 2018, 6:41 PM
 */

#include "dataGenerator.h"

void allZeros(vector<int>& data, int size)
{
    data.clear();     
    for(int i = 0; i < size; i++)
        data.push_back(0);    
    return;
}

void sequentialDataGen(vector<int>& data, int size)
{
    data.clear();     
    for(int i = 0; i < size; i++)
        data.push_back(i);    
    return ;    
}

void reverseDataGen(vector<int>& data, int size)
{
    data.clear();        
    for(int i = size; i != 0; i--)
        data.push_back(i);    
    return;
}

void randomDataGen(vector<int>& data, int size)
{
    data.clear();        
    for(int i = 0; i < size; i++)
        data.push_back(rand() % 100000);    
    return;
}
