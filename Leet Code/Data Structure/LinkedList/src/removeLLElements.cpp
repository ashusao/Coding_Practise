/*
 * removeLLElements.cpp
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

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {

		ListNode* cur = head;
		ListNode* prev = NULL;

		while (cur != NULL) {

			if (cur->val == val) {
				if (prev == NULL) {
					head = head->next;
				} else {
					prev->next = cur->next;
				}
			} else {
				prev = cur;
			}
			cur = cur->next;
		}

		return head;
	}
};
