/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkClass.h
 * Author: Neeraj
 *
 * Created on June 24, 2018, 6:26 PM
 */

#ifndef LINKCLASS_H
#define LINKCLASS_H
#include "Node.h"

class linkClass {
public:
    linkClass();
    void linkInsert(int data);
    void printList();
private:
    Node *head;
    Node *tail;
    static int linkObjectCount;
};

#endif /* LINKCLASS_H */

