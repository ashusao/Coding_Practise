/*
 * isPalindrome.cpp
 *
 *  Created on: Jul 19, 2018
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

// Find the middle element by traversing slow and fast pointer
// termination condition will be fast.next && fast.next.next != NULL
// in this case slow will be at middle for odd LL and ll be at end of half for even ll
// reverse LL from slow.next
// move slow to next and loop and compare from head and slow until slow reaches null if disagrees return false

class Solution {
public:
	bool isPalindrome(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return true;

		ListNode *slow = head, *fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}

		slow->next = reverse(slow->next);
		slow = slow->next;

		while (slow != NULL) {
			if (slow->val != head->val)
				return false;

			head = head->next;
			slow = slow->next;
		}

		return true;

	}

	ListNode* reverse(ListNode* head) {
		ListNode *prev = NULL, *next = NULL;
		while (head != NULL) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}

		return prev;
	}
};

