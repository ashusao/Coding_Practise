/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.cpp
 * Author: ashu
 * 
 * Created on July 9, 2018, 4:22 PM
 */
#include <iostream>
#include "Queue.h"
#include <cstddef>
using namespace std;

Queue::Queue() {
    front = rear =  -1;
    q_size = 0;
}

Queue::Queue(const Queue& orig) {
}

Queue::~Queue() {
}

Queue::Queue(int capacity){
    
    if(capacity < 0){
        cout << "capacity less than 0" << endl;
        return;
    }
    front = rear = -1;
    q_size = capacity;
    queue = new int[capacity];
}

void Queue::print_Q(){
    
    if( rear == -1){
        cout << "Empty Q"<<endl;
        return;
    }
    
    for (int i=front; i<=rear; i++){
        cout << queue[i] << "->";
    }
    cout << endl;
}

void Queue::enQueue(int val){

    if(rear == q_size-1){
        cout << "Q Full . EnQueue not possible !!"<<endl;
        return;
    }
    
    if( rear == -1){
        ++front;
    }
    
    queue[++rear] = val;
}

void Queue::deQueue(){
    
    if( rear == -1){
        cout << "Empty Q"<<endl;
        return;
    }
    
    if( front == rear){
        cout << "Q is empty now"<<endl;
        front = rear = -1;
    }else{
        ++front;
    }
    
}
