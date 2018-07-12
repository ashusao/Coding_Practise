/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arrays.h
 * Author: ashu
 *
 * Created on July 6, 2018, 2:08 PM
 */

#ifndef ARRAYS_H
#define ARRAYS_H


class Array {
public:
    Array();
    Array(int c);
    Array(const Array& orig);
    virtual ~Array();
    int get_capacity();
    void print_array();
    bool insert(int val, int pos);
    bool remove(int pos);
    int get_size();
    
private:
    int capacity; // size of array
    int* arr;
    int sz;

};

#endif /* ARRAYS_H */

