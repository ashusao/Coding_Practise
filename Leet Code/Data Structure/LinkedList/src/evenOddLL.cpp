/*
 * evenOddLL.cpp
 *
 *  Created on: Jul 18, 2018
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

// Intialize  even head, and odd and even to update odd pos and evne pos
// loop until even or even next is  null since even is to be attached behind odd
// update odd next and then even next
// then update odd and even
// after loop update odd next to even head
// thats is.


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

    	if(head == NULL)
    		return head;

    	ListNode* odd = head;
    	ListNode* even_head = head->next;
    	ListNode* even = even_head;

    	while(even && even->next){
    		odd->next = odd->next->next;
    		even->next = even->next->next;
    		odd = odd->next;
    		even = even->next;
    	}
    	odd->next = even_head;

    	return head;

    }
};

