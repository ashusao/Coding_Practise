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

  // intialize pre and next to NULL
  // Loop untill head reaches null
  // save next node
  // point heads next to previous
  // update previous to head
  // update heas to next

  class Solution {
  public:
      ListNode* reverseList(ListNode* head) {

    	  ListNode* prev = NULL;
    	  ListNode* next = NULL;
    	  while(head != NULL){
    		  next = head->next;
    		  head->next = prev;
    		  prev = head;
    		  head = next;
    	  }

    	  return prev;
      }
  };


