/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircularLL.cpp
 * Author: ashu
 * 
 * Created on July 7, 2018, 1:42 PM
 */

#include "CircularLL.h"
#include<iostream>
#include<cstddef>
using namespace std;


CircularLL::CircularLL() {
    head = NULL;
}

CircularLL::CircularLL(const CircularLL& orig) {
}

CircularLL::~CircularLL() {
}

void CircularLL::print_LL(){
    if(head == NULL){
        cout << "Empty LL"<<endl;
    }
    
    Node *tmp = head;
    do{
        cout << tmp->val << "->"; 
        tmp = tmp->next;
    }while(tmp != head);
    
    cout<<endl;
}

void CircularLL::insertAtHead(int val){
    Node* new_node = new Node;
    new_node->val = val;
    Node* tmp = head;
    
    if(head == NULL){
        head = new_node;
        new_node->next = head;
    }else{
        while(tmp->next != head)
            tmp = tmp->next;
        
        tmp->next = new_node;
        new_node->next = head;
        head = new_node;
    }
}

void CircularLL::insertAtTail(int val){
    Node* new_node = new Node;
    new_node->val = val;    
    Node* tmp = head;
    
    if(head == NULL){
        head = new_node;
    }else{
        while(tmp->next != head)
            tmp = tmp->next;
        
        tmp->next = new_node;
    }
    new_node->next = head;
}

void CircularLL::insertAtPos(int pos, int val){
    
    if(pos < 0){    // wrong pos
        cout << "Pos Val negative" << endl;
        return;
    }
    
    int i=0;
    if(i==0 && pos == 0){
        insertAtHead(val);
        return;
    }
    Node* tmp = head;
    Node* prev = tmp;
    bool insert = false;
    do{
        if(i == pos){   // found insert before
            Node* new_node = new Node;
            new_node->val = val;
            prev->next = new_node;
            new_node->next = tmp;
            insert = true;
            break;
        }
        ++i;
        prev = tmp;
        tmp = tmp->next;
    }while(tmp != head);
    
    if(!insert && i==pos){
        insertAtTail(val);
        return;
    }else{
        cout<<"Pos Value incorrect"<<endl;
    }
}

void CircularLL::remove(int pos){
    if(pos < 0){
        cout << "Pos Value Negative" << endl;
        return;
    }
    
    if(head == NULL){
        cout << "LL empty"<<endl;
        return;
    }
    
    int i=0;
    bool deleted = false;

    Node* tmp = head;    
    Node *prev = tmp;
    
    if(pos==0){
        Node* rem = tmp;
        while(tmp->next != head)
            tmp = tmp->next;  
        head = rem->next;
        tmp->next = head;
        delete rem;
        return;
    }
    
    
    do{
        if(i == pos){
            prev->next = tmp->next;
            deleted = true;
            delete tmp;
            break;
        }
    ++i;
    prev = tmp;
    tmp = tmp->next;
    }while(tmp != head);
    
    if(!deleted)
        cout<< "Pos value incorrect"<<endl;
}