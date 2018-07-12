/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoublyLinkedList.h
 * Author: ashu
 *
 * Created on July 6, 2018, 11:31 PM
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct Node{
    int val;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& orig);
    virtual ~DoublyLinkedList();
    void printDLL();
    void insertAtHead(int val);
    void insertAtTail(int val);
    void insertAtPos(int pos, int val);
    void remove(int pos);
private:
    Node* head;
};

#endif /* DOUBLYLINKEDLIST_H */

