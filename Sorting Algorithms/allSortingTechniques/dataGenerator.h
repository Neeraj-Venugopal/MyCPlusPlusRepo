/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dataGenerator.h
 * Author: Neeraj
 *
 * Created on June 29, 2018, 6:41 PM
 */

#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H
#include <cstdlib>
#include <vector>

using namespace std;

void allZeros(vector<int>& data, int size);
void sequentialDataGen(vector<int>& data, int size);
void reverseDataGen(vector<int>& data, int size);
void randomDataGen(vector<int>& data, int size);


#endif /* DATAGENERATOR_H */

