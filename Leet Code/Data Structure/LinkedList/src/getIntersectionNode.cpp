/*
 * getIntersectionNode.cpp
 *
 *  Created on: Jul 16, 2018
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

// When shorter LL reach at end point it to head of bigger & vice versa
// ultimately they ll meet at intersection.

// Simpler Alternate:
// Calculate lengths of LL & start bigger at difference then  they ll meet at intersection

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    	if(headA == NULL || headB == NULL)
    		return NULL;

    	ListNode* a = headA;
    	ListNode* b = headB;

    	while(a != b){
    		if (a == NULL)
    			a = headB;
    		else
    			a = a->next;

    		if(b == NULL)
    			b = headA;
    		else
    			b = b->next;
    	}

    	return a;

    }
};
