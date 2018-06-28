/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Neeraj
 *
 * Created on June 27, 2018, 11:46 PM
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
    
    for (int i = 0; i < 100; i++)
        array.push_back(rand()%1000);
    
    for(int i = 1; i < array.size(); i++)
    {
        int j, key;
        key = array[i];
        j = i - 1;
        
        while(j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    
    
    for(int i = 0; i < array.size(); i++)
        cout << array[i] << endl;
    
    return 0;
}

