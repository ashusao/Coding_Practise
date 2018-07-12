/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arrays.cpp
 * Author: ashu
 * 
 * Created on July 6, 2018, 2:08 PM
 */

#include "Array.h"
#include <iostream>
#include <cstddef>
using namespace std;

Array::Array() {
    capacity = 0;
    sz = 0;
    arr = NULL;
}

Array::Array(int c){
    capacity = c;
    arr = new int[c];
}

Array::Array(const Array& orig) {
}

Array::~Array() {
    if(sz == 0)
        arr = NULL;
    else
        delete arr;
}

int Array::get_capacity(){
    return capacity;
}

int Array::get_size(){
    return sz;
}

void Array::print_array(){
    
    if( sz == 0){
        cout << "Empty Array" << endl;
    }else {
        for(int i=0; i < sz; i++)
        cout<< " | "<< arr[i]<< " | ";
        cout<<endl;
    }
}

bool Array::insert(int val, int pos){  
    
    if(capacity == 0){
        cout << "Array not intialized capacity = 0"<<endl;
        return false;
    }
    
    if(sz == capacity){
        cout << "Array Full "<<endl;
        return false;
    }
    
    if (pos > capacity || pos < 1 || pos > sz+1){
        cout << "Position value incorrect"<<endl;
        return false;
    }
    
    // move elements to one position right from pos -1 to sz
    for( int i = sz; i>=pos ; --i){  //O(n)
        arr[i] = arr[i-1];
    }
    
    //insert new element and increment size
    arr[pos-1] = val;
    sz++;   
    
    return true;
    
}

bool Array::remove(int pos){
    
    if(capacity == 0){
        cout << "Array not intialized capacity = 0"<<endl;
        return false;
    }
    
    // check if empty
    if( sz == 0){
        cout << "Array Empty"<<endl;
        return false;
    }
    
     // check correct val of position
    if (pos > sz || pos < 1){
        cout << "Position value incorrect"<<endl;
        return false;
    }  
    
    //move element from pos-1 to sz to one position left and decrement the size
    for(int i=pos-1; i < sz-1; i++){
        arr[i] = arr[i+1];
    }
    
    sz--;
    return true;
}