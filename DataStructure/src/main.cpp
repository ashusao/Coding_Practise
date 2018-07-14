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
    
	SinglyLinkedList obj;
//	 int param_1 = obj.get(index);
	 obj.insertAtFirst(2);
	 obj.insertAtTail(3);
	 obj.insertAtPos(1,4);
	 obj.print_LL();


    return 0;
}

