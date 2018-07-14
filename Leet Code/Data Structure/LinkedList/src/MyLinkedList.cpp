/*
 * MyLinkedList.cpp
 *
 *  Created on: Jul 14, 2018
 *      Author: ashu
 */

#include <cstddef>
#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int v) : val(v), next(NULL){}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
    	head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {

    	//check index is negative or LL empty
    	if(index < 0 || head == NULL)
    		return -1;

    	int i = 0;
    	Node* tmp = head;

    	while(tmp != NULL){
    		if(i == index)
    			return tmp->val;
    		i++;
    		tmp = tmp->next;
    	}

    	return -1;

    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

    	Node* new_node = new Node(val);
    	new_node->next = head;
    	head = new_node;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

    	if(head == NULL){
    		addAtHead(val);
    		return;
    	}

    	Node* tmp = head;
    	while(tmp->next != NULL){
    		tmp = tmp->next;
    	}

    	Node* new_node = new Node(val);
    	tmp->next = new_node;

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

    	Node *cur = head;
    	Node* prev = head;
    	int i=0;
    	bool inserted = false;

    	while(cur != NULL){
    		if(i == index){
    			Node* new_node = new Node(val);

    			new_node->next = cur;
    			if(i==0)
    				prev = new_node;
    			else
    				prev->next = new_node;

    			inserted = true;
    			break;
    		}
    		i++;
    		prev = cur;
    		cur = cur->next;
    	}

    	// if i == index && not inserted, then insert at tail
    	if(!inserted){
    		if(i==index){
    			addAtTail(val);
    		}
    	}

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

    	if(index < 0 || head == NULL)
    		return;

    	Node* prev = head;
    	Node* cur = head;
    	int i=0;

    	while(cur != NULL){
    		if(i==index){
    			if(i==0)
    				prev = cur->next;
    			else
    				prev->next = cur->next;
    			delete cur;
    		}
    		i++;
    		prev = cur;
    		cur = cur->next;
    	}
    }

    void printLL(){
    	Node* tmp = head;
    	while(tmp != NULL){
    		cout << tmp->val << "->";
    		tmp = tmp->next;
    	}

    	cout << endl;

    }

private:
    Node* head;
};



int main() {

	MyLinkedList linkedList;
	cout << linkedList.get(0) << endl;
	linkedList.addAtIndex(1, 2);
	cout << linkedList.get(0) << endl;
	cout << linkedList.get(1) << endl;
	linkedList.addAtIndex(0, 1);
	linkedList.printLL();
	cout << linkedList.get(0) << endl;
	cout << linkedList.get(1) << endl;


	return 0;
}

