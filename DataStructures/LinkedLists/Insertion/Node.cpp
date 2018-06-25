/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Neeraj
 * 
 * Created on June 23, 2018, 3:06 AM
 */

#include "Node.h"
#include <iostream>

using namespace std;

int Node::nodeCount = 0;

Node::Node() {
    data = 0;
    next = nullptr;
//    cout << "Inside Node Class Constructor" << endl;
    nodeCount++;
}