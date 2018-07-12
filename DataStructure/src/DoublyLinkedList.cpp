/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoublyLinkedList.cpp
 * Author: ashu
 * 
 * Created on July 6, 2018, 11:31 PM
 */

#include "DoublyLinkedList.h"
#include <iostream>
#include <cstddef>
using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& orig) {
}

DoublyLinkedList::~DoublyLinkedList() {
}

void DoublyLinkedList::printDLL(){
    if(head == NULL){
        cout << "Empty LL"<<endl;
    }
    
    Node *tmp = head;
    while(tmp != NULL){
        cout << tmp->val << "->"; 
        tmp = tmp->next;
    }
    cout<<endl;
}

void DoublyLinkedList::insertAtHead(int val){
    Node* new_node = new Node;
    new_node->val = val;
    new_node->prev = NULL;
    
    if(head == NULL){ // empty LL
        new_node->next = NULL;
        head = new_node;
    }else{
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
}

void DoublyLinkedList::insertAtTail(int val){
    
    if(head == NULL){
        insertAtHead(val);
    }else{
        Node* new_node = new Node;
        new_node->val = val;
        new_node->next = NULL;
        
        Node* tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

void DoublyLinkedList::insertAtPos(int pos, int val){
    
    if(pos < 0){
        cout << "Pos Value Negative" << endl;
        return;
    }
    
    if(head == NULL && pos != 0){
        cout << "LL empty"<<endl;
        return;
    }
    
    if(pos == 0){
        insertAtHead(val);
        return;
    }
    
    int i=0;
    Node* tmp = head;
    bool insert = false;
    // traverse if found insert before
    while(tmp != NULL){
        
        if(i == pos){ // insert before node
            Node* new_node = new Node;
            new_node->val = val;
            new_node->next = tmp;
            new_node->prev = tmp->prev;
            tmp->prev = new_node;
            new_node->prev->next = new_node;
            insert = true;
            break;
        }
        ++i;
        tmp = tmp->next;
    }
    
    if(!insert && i==pos){
        insertAtTail(val);
        return;
    }else{
        cout<<"Pos out of range"<<endl;
    }
}

void DoublyLinkedList::remove(int pos){
    
    if(pos < 0){
        cout << "Pos Value Negative" << endl;
        return;
    }
    
    if(head == NULL){
        cout << "LL empty"<<endl;
        return;
    }
    
    Node *tmp = NULL;
    tmp = head;
    int i=0;
    bool deleted = false;
    
    while(tmp != NULL){
        if( i == pos){  //found     
            //case at first
            if(i==0){
                tmp->next->prev = NULL;
                head = tmp->next;
            }else if(tmp->next == NULL){ //case at tail
                tmp->prev->next = NULL;
            }else{//case in between
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
            }
            deleted = true;
            delete tmp;
            break;
        }
        tmp = tmp->next;
        ++i;
    }
    
    if(!deleted){
        cout<<"Pos incorrect"<<endl;
    }
    
}