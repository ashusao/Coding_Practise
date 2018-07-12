/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinglyLinkedList.h
 * Author: ashu
 *
 * Created on July 6, 2018, 3:55 PM
 */

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

struct Node{
    int val;
    Node* next;
};

class SinglyLinkedList {
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& orig);
    virtual ~SinglyLinkedList();
    void print_LL();
    void insertAtFirst(int val);
    void insertAtTail(int val);
    void insertAtPos(int pos, int val);
    void remove(int val);
    
private:
    
    Node *head;
};

#endif /* SINGLYLINKEDLIST_H */

