/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Neeraj
 *
 * Created on June 28, 2018, 1:16 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    srand(time(0));    
    vector <int> array;
    int gap = 1;
    
    for(int i = 0; i < 1000; i++)
        array.push_back(rand()%10000);
    
    while((array.size() / 3) > gap)    
        gap = (3 * gap ) + 1;   
    // Knuth Formula = 3k + 1    
    // Got the Gap required to evaluate according to size    
    
    while (gap >= 1)
    {
        for(int i = gap; i < array.size(); i++)
        {
            int key = array[i];
            int j;
            
            for(j = i; j >= gap && key < array[j - gap]; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = key;
        }
        
        gap--;
        gap /= 3;  
        // Following Reverse Knuth Formula if gap = 3k + 1 then, previous gap, 
        // k = (gap - 1) / 3
    }
    
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << endl;
    
    return 0;
}