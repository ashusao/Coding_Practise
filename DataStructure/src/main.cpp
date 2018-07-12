/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ashu
 *
 * Created on July 6, 2018, 2:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "PriorityQ.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    PriorityQ q(4);
    q.enQueue(1, 10);
    q.enQueue(2, 20);
    q.enQueue(3, 15);
    q.printQ();
    q.deQueue();
    q.printQ();
            
   
    return 0;
}

