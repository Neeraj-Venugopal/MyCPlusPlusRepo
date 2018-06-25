/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Neeraj
 *
 * Created on June 23, 2018, 3:06 AM
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    void nodeInsert(Node *head, int number);
    void printNode(Node *head) const;
    
    static int nodeCount;
    int data;
    Node *next;
    Node *prev;
};

#endif /* NODE_H */

