/*
 * removeNthfromEnd.cpp
 *
 *  Created on: Jul 17, 2018
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


// Move cur pointer n steps forward
// intialize prev pointer and move both so that  gap of n is maintained, until cur next equals NULL.
// Now prev points previous of node to be deleted
// special case to be taken care when single element is there

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode* cur = head;

		for (int i = 0; i < n; i++) {
			cur = cur->next;
		}

		if (cur == NULL) { // case when there is single element
			head = head->next;
			return head;
		}

		ListNode* prev = head;
		while (cur->next != NULL) {
			cur = cur->next;
			prev = prev->next;
		}

		prev->next = prev->next->next;

		return head;
	}
};

