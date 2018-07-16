/*
 * detectCycle.cpp
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

// fast = 2 * slow, they meet when fast == slow
// suppose slow has traveled A + B node when they meet
// At same time fast has traveled = 2*A + 2*B  and it completed 1 cycle to meet slow
// Therefore A + B + C = 2*A + 2*B, implies A+B = C which implies B = C - A meaning slow is A steps away to start of cycle
// so take another pointer at head and move slow and new pointer one step at a time
// They ill meet at cycle start.


class Solution {
public:

	ListNode *detectCycle(ListNode *head) {

		if (head == NULL)
			return NULL;

		ListNode* slow = head;
		ListNode* fast = head;

		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast){
				ListNode* tmp=head;
				while(tmp != slow){
					tmp = tmp->next;
					slow = slow->next;
				}
				return slow;
			}

		}

		return NULL;

	}
};

