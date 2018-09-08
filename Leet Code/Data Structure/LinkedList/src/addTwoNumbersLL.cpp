/*
 * addTwoNumbersLL.cpp
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

// Des:Digits are sorted in reverse order

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

// loop until both reaches NULL and add if sum greater than 10 make carry flag true
// if carry flag true add 1 to sum and make it false
// if one reaches NULL only increment the other
// at end of loop if carry flag is true add new node to accomodate carry (e.g 5 + 5 = 10)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    	ListNode *head = new ListNode(0);
    	ListNode *cur = head;

    	bool carry_flag = false;
    	while( l1 != NULL || l2 != NULL){

    		int sum;
    		if(l1 == NULL){
    			sum =  l2->val;
    			l2 = l2->next;
    		}
    		else if( l2 == NULL){
    			sum = l1->val;
    			l1 = l1->next;
    		}else{
    			sum =l1->val + l2->val;
    			l1 = l1->next;
    			l2 = l2->next;
    		}

    		if(carry_flag){
    			sum += 1;
    			carry_flag = false;
    		}

    		if(sum >= 10){
    			carry_flag = true;
    			sum = sum % 10;
    		}

    		ListNode *new_node = new ListNode(sum);
    		cur->next = new_node;
    		cur = cur->next;

    	}

    	if(carry_flag){
    		ListNode *new_node = new ListNode(1);
    		cur->next = new_node;
    		cur = cur->next;
    	}

    return head->next;
    }
};
