/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircularLL.h
 * Author: ashu
 *
 * Created on July 7, 2018, 1:42 PM
 */

#ifndef CIRCULARLL_H
#define CIRCULARLL_H

struct Node{
    int val;
    Node* next;
};

class CircularLL {
public:
    CircularLL();
    CircularLL(const CircularLL& orig);
    virtual ~CircularLL();
    void print_LL();
    void insertAtHead(int val);
    void insertAtTail(int val);
    void insertAtPos(int pos, int val);
    void remove(int pos);
    
private:
    Node* head;

};

#endif /* CIRCULARLL_H */

