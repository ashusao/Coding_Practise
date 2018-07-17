/*
 * reverseIteratively.cpp
 *
 *  Created on: Jul 17, 2018
 *      Author: ashu
 */

#include <iostream>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  class Solution {
  public:
      ListNode* reverseList(ListNode* head) {

    	  ListNode* prev = NULL;
    	  while(head != NULL){
    		  ListNode* next = head->next;
    		  head->next = prev;
    		  prev = head;
    		  head = next;
    	  }

    	  return prev;
      }
  };


