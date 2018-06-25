/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Neeraj
 *
 * Created on June 23, 2018, 2:35 AM
 */

#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "linkClass.h"
#include <time.h>

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    
    linkClass objects;    
    for(int i = 0; i < 100; i++)
    {
        int k = rand() % 1000;
        objects.linkInsert(k);        
    }
    
    cout << "Printing List: " << endl;
    objects.printList();
    return 0;
}

