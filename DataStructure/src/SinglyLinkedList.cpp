/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinglyLinkedList.cpp
 * Author: ashu
 * 
 * Created on July 6, 2018, 3:55 PM
 */

#include "SinglyLinkedList.h"
#include <iostream>
#include <cstddef>
using namespace std;

SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& orig) {
}

SinglyLinkedList::~SinglyLinkedList() {
}

void SinglyLinkedList::print_LL(){
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

void SinglyLinkedList::insertAtFirst(int val){
    
    // create node
    Node* new_node = new Node();
    new_node->val = val;
    new_node->next = head;
    head = new_node;
}

void SinglyLinkedList::insertAtTail(int val){  
    
    Node* tmp = head;
    if(tmp == NULL){    // empty LL
        insertAtFirst(val);
    }
    
    Node* new_node = new Node();
    new_node->val = val;
    new_node->next = NULL;
    
    while(tmp->next != NULL){   // O(n)
        tmp = tmp->next;
    }
    tmp->next = new_node;
    
}

void SinglyLinkedList::insertAtPos(int pos, int val){
    
    // create node
    Node* new_node = new Node();
    new_node->val = val;
    new_node->next = NULL;
    
    // check pos is non negative
    if(pos < 0){
        cout<<"Pos Val negative"<<endl;
        return;
    }
    
    int i=0;
    Node* tmp = head;
    Node* prev = tmp;
    bool insert = false;
    // traverse to pos if NULL reached return else insert
    do{
        if(i == pos){
            insert = true;
            
            if(i==0){
                insertAtFirst(val);
                return;
            }
            
            new_node->next = tmp;
            prev->next = new_node;
            return;
            //insert node and break
        }
        prev = tmp;
        tmp = tmp->next;
        ++i;
    }while(tmp != NULL);    //O(n)
    
    if(i == pos){   // At end insert
        insert = true;
        insertAtTail(val);
    }
    
    if (!insert){
        cout << "Pos out of range"<<endl;
    }
    
}

void SinglyLinkedList::remove(int val){
    
    // if empty return
    if(head == NULL){
        cout << "Empty list"<<endl;
        return;
    }
    
    Node* tmp = head;
    Node* prev = tmp;
    
    // loop and maintain prev node if found delete and return
    while(tmp != NULL){
        
        //remove and exit
        if(tmp->val == val){
            
            //if first node
            if(tmp == prev){
                head = tmp->next;
            }else{
               prev->next = tmp->next; 
            }
            delete tmp;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    
    cout<<"Value not in LL"<<endl;
    
}