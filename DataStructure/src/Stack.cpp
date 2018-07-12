/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.cpp
 * Author: ashu
 * 
 * Created on July 7, 2018, 3:23 PM
 */

#include "Stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Stack::Stack() {
    capacity = 0;
    top = 0;
}

Stack::Stack(const Stack& orig) {
}

Stack::Stack(int c){
    capacity = c;
    top = 0;
    stack = new int[capacity];
}

Stack::~Stack() {
}

void Stack::print_stack(){
    if (top == 0){
        cout << "Empty stack" << endl;
        return;
    }
    
    for(int i=0; i<top; i++){
        cout << stack[i] << " | ";
    }
    cout << endl;
}

void Stack::push(int val){
    if(top == capacity){
        cout << "Overflow" << endl;
        return;
    }
    
    stack[top++] = val;
}

int Stack::pop(){
    if(top == 0){
        cout << "Underflow" << endl;
        return -1;
    }
    --top;
}

int Stack::peek(){
    if(top == 0){
        cout << "Underflow" << endl;
        return -1;
    }
    return stack[top-1];
}
