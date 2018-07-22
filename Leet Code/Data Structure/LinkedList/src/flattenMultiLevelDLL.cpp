/*
 * flattenMultiLevelDLL.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: ashu
 */

#include <iostream>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val = NULL;
	Node* prev = NULL;
	Node* next = NULL;
	Node* child = NULL;

	Node() {
	}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

// intialize stack
// loop untill cur next!= NULL or stack not empty or cur child is not null
// if cur next is null and stack not empty, pop from stack, point its prev to cur and cur next to pop item
// if cur child is not null, if its next is not null push it into stack
// set cur next to cur child and cur->next->prev to curr and cur child to null
// return head;

class Solution {
public:
	Node* flatten(Node* head) {

		if (head == NULL)
			return head;

		stack<Node*> st;
		Node* cur = head;
		while (cur->next != NULL || !st.empty() || cur->child != NULL) {

			if (cur->next == NULL && !st.empty()) {
				Node* tmp = st.top();
				st.pop();
				cur->next = tmp;
				tmp->prev = cur;
			}

			if (cur->child != NULL) {
				// cout << p->val << endl;
				if (cur->next != NULL)
					st.push(cur->next);

				cur->next = cur->child;
				cur->next->prev = cur;
				cur->child = NULL;
			}
			cur = cur->next;
		}
		return head;

	}
};

