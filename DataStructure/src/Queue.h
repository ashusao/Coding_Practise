/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: ashu
 *
 * Created on July 9, 2018, 4:22 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    Queue();
    Queue(const Queue& orig);
    virtual ~Queue();
    Queue(int capacity);
    void enQueue(int val);
    void deQueue();
    void print_Q();

private:
    int *queue;
    int q_size;
    int front;
    int rear;

};

#endif /* QUEUE_H */

