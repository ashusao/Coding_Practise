/*
 * QHEAP.cpp
 *
 *  Created on: Nov 3, 2018
 *      Author: ashu
 */


#include <iostream>
#include<climits>
using namespace std;

void swap(int *p, int *q){
	int t = *p;
	*p = *q;
	*q = t;
}

class MinHeap{
private:
	int *arr;
	int capacity;
	int h_size;

public:
	MinHeap(int capacity);
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return 2*i+1; }
	int right(int i) { return 2*i+2; }
	int extractMin();
	int getMin() { return this->arr[0]; }
	void insertVal(int val);
	void deleteVal(int val);
	void minHeapify(int i);
};

MinHeap::MinHeap(int capacity){
	this->arr = new int[capacity];
	this->capacity = capacity;
	this->h_size = 0;
}

void MinHeap::minHeapify(int i){
	int smallest = i;
	int l = left(i);
	int r = right(i);

	if( l < h_size && arr[l] < arr[smallest])
		smallest = l;

	if( r < h_size && arr[r] < arr[smallest])
		smallest = r;

	if( smallest != i){
		swap(&arr[smallest], &arr[i]);
		minHeapify(smallest);
	}
}

int MinHeap::extractMin(){

	if(this->h_size == 1){
		--h_size;
		return this->arr[h_size];
	}

	int val = this->arr[0];
	this->arr[0] = this->arr[h_size-1];
	--h_size;
	minHeapify(0);

	return val;
}

void MinHeap::insertVal(int v){
	if( h_size == capacity){
		cerr << "OverFlow " << endl;
		return;
	}

	h_size++;
	int i = h_size - 1;
	this->arr[i] = v;

	cout << h_size << " " << arr[i] << endl;
	while( i != 0 && arr[parent(i)] > arr[i]){
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}

}

void MinHeap::deleteVal(int v){

	for(int i=0; i<h_size; ++i){
		if(arr[i] == v){
			arr[i] = INT_MIN;
			while( i!=0 && arr[parent(i)] > arr[i]){
				swap(&arr[i], &arr[parent(i)]);
				i = parent(i);
			}
			extractMin();
			break;
		}
	}
}

int main()
{
	cout << "running minHeap" << endl;
    MinHeap h(11);
    h.insertVal(3);
    h.insertVal(2);
    h.insertVal(15);
    h.deleteVal(3);
    h.insertVal(5);
    h.insertVal(4);
    h.insertVal(45);
    cerr << h.getMin() << " ";
    cerr << h.extractMin() << " ";
    cerr << h.getMin() << " " << endl;
    return 0;
}
