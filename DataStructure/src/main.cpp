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
#include "SinglyLinkedList.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    SinglyLinkedList* LL = new SinglyLinkedList();
    LL->insertAtFirst(8);
    LL->print_LL();
    LL->insertAtFirst(3);
    LL->insertAtTail(34);
    LL->print_LL();
    LL->insertAtPos(3, 45);
    LL->print_LL();
    LL->reverseIterative();
    LL->print_LL();

    return 0;
}

