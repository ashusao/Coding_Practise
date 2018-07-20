/*
 * mergeTwoSortedLL.cpp
 *
 *  Created on: Jul 21, 2018
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

// Create a dummy node and make it head
// point next of dummy node to ll whose val is small and move ll and dummy node
// which ever node reaches node assign other to dummy next
// at end return next of head node


class Solution {
public:

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode *dummy = new ListNode(0);
		ListNode *head = dummy;

		while( l1 != NULL && l2 != NULL){

			if(l1->val < l2->val){
				dummy->next = l1;
				l1 = l1->next;
			}else{
				dummy->next = l2;
				l2 = l2->next;
			}
		dummy = dummy->next;
		}

		if(l1 == NULL)
			dummy->next = l2;
		else
			dummy->next = l1;

		return head->next;

    }
};


