/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkClass.cpp
 * Author: Neeraj
 * 
 * Created on June 24, 2018, 6:26 PM
 */

#include "linkClass.h"
#include <iostream>
using namespace std;

int linkClass::linkObjectCount = 0;

linkClass::linkClass() {
    head = NULL;
    tail = NULL;
    linkObjectCount++;
}

void linkClass::linkInsert(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    
    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    
    else{
        tail->next = temp;
        tail = tail->next;

//        Node *tempNode;
//        tempNode = head;
//        
//        while(tempNode->next !=  NULL){
//            tempNode = tempNode->next;
//        }
//        
//        tempNode->next = temp;
            
    }   
}

void linkClass::printList(){
    Node *storeHead;
    storeHead = head;
    
    while(storeHead->next != NULL)
    {
        cout << storeHead->data << endl;
        storeHead = storeHead->next;
    }
    cout << storeHead->data << endl;
    
    
    return;
}
