/*
 * CircularQ.cpp
 *
 *  Created on: Jul 12, 2018
 *      Author: ashu
 */

#include "CircularQ.h"
#include <iostream>
using namespace std;

CircularQ::CircularQ() {
	// TODO Auto-generated constructor stub
	front = rear = -1;
	capacity  = 0;
	Data = NULL;

}

CircularQ::~CircularQ() {
	// TODO Auto-generated destructor stub
	delete Data;
}

CircularQ::CircularQ(int c){

	if(c<=0){
		cout << "Queue capacity less <= 0"<<endl;
		return;
	}
	front = rear = -1;
	capacity = c;
	Data = new int[c];
}

void CircularQ::printQ(){
	if(rear < 0){
		cout << "Empty Q" << endl;
		return;
	}

	// print until last element
	for(int i = front; i!=rear; i = (i+1)%capacity){
		cout<< Data[i] << "->";
	}

	//print last element
	cout<<Data[rear]<<endl;
}

void CircularQ::enQueue(int val){

	//full
	if((rear+1)%capacity == front){
		cout << "Q Full"<<endl;
		return;
	}

	//empty
	if(rear == -1){
		front = 0;
	}
	rear = (rear+1)%capacity;
	Data[rear] = val;

}


void CircularQ::deQueue(){

	//empty
	if(rear < 0){
		cout << "Empty Q" << endl;
		return;
	}

	//only element
	if(front == rear){
		front = rear = -1;
		return;
	}

	front = (front+1)%capacity;

}
