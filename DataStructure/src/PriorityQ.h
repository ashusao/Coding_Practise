/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQ.h
 * Author: ashu
 *
 * Created on July 9, 2018, 5:38 PM
 */

#ifndef PRIORITYQ_H
#define PRIORITYQ_H

struct Data{
    int val;
    int priority;
};

class PriorityQ {
public:
    PriorityQ();
    PriorityQ(const PriorityQ& orig);
    virtual ~PriorityQ();
    PriorityQ(int c);
    void printQ();
    void enQueue(int val, int prio);
    void deQueue();
    
private:
    Data* queue;
    int front, rear, capacity;

};

#endif /* PRIORITYQ_H */

