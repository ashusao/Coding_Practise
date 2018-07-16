/*
 * hasCycle.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: ashu
 */


#include <iostream>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  // Speed of fast is twice that of slow
  // If they meet, there is cycle


class Solution {
public:
    bool hasCycle(ListNode *head) {

    	if(head == NULL)
    		return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
        	slow = slow->next;
        	fast = fast->next->next;

        	if(slow == fast)
        		return true;

        }

        return false;

    }
};
