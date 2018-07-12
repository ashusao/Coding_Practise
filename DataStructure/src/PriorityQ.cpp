/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQ.cpp
 * Author: ashu
 * 
 * Created on July 9, 2018, 5:38 PM
 */
#include <iostream>
#include "PriorityQ.h"
using namespace std;

PriorityQ::PriorityQ() {
    capacity = 0;
    front = rear = -1;
}

PriorityQ::PriorityQ(const PriorityQ& orig) {
}

PriorityQ::~PriorityQ() {
}

PriorityQ::PriorityQ(int c){
    if(c == -1){
        cout << "Capacity Negative" << endl;
        return;
    }
    
    front = rear = -1;
    capacity = c;
    
    queue = new Data[c];
    cout << "Size Allocated: "<< sizeof(queue) <<endl;
}

void PriorityQ::printQ(){
    
    if(rear == -1){
        cout << " Q Empty" << endl;
        return;
    }
    
    for(int i = front; i <= rear ; i++){
        cout << "v:" << queue[i].val << ",p:" << queue[i].priority << " -> ";
    }
    cout << endl;
}

void PriorityQ::enQueue(int val, int prio){
    
    if(rear == capacity-1){
        cout << "Q Full" << endl;
        return;
    }
    
    if(rear == -1){
        ++front;
    }
    ++rear;

    queue[rear].val = val;
    queue[rear].priority = prio;
    
}

void PriorityQ::deQueue(){
    
    if(rear == -1){
        cout << " Q Empty" << endl;
        return;
    }
    
    if( front == rear){
        cout << "Q is empty now"<<endl;
        front = rear = -1;
        return;
    }
    
    int high_id = front;
    int high_p = queue[front].priority;
    //search for highest priority item
    for(int i = front+1; i <= rear ; i++){
        if(queue[i].priority > high_p ){
            high_p = queue[i].priority;
            high_id = i;
        }
    }
    
    //remove and shift all item to left
    for(int i=high_id; i<=rear; i++){
        if(i == rear){
            break;
        }
        //shift
        queue[i].val = queue[i+1].val;
        queue[i].priority = queue[i+1].priority;
    }
    
    --rear;
    //rear = rear-1
    
}
