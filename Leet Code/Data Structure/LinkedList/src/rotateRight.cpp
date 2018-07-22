/*
 * rotateRight.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: ashu
 */
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// find length of list and circle the list
// find the position of new tail make next of it NULL and next of tail as new head

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

    	if(!head) return head;

    	int len = 1;
    	ListNode *newHead, *tail;
    	tail = head;

    	while(tail->next){
    		tail = tail->next;
    		++len;
    	}

    	tail->next = head;

    	if(k = k%len){
    		for(int i=0; i<len-k; i++) tail=tail->next;
    	}

    	newHead = tail->next;
    	tail->next = NULL;

    	return newHead;
    }
};



