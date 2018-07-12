/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: ashu
 *
 * Created on July 7, 2018, 3:23 PM
 */

#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();
    Stack(const Stack& orig);
    Stack(int c);
    virtual ~Stack();
    void print_stack();
    void push(int val);
    int pop();
    int peek();
    
private:
    int capacity;
    int* stack;
    int top;
};

#endif /* STACK_H */

