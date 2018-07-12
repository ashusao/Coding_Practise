/*
 * CircularQ.h
 *
 *  Created on: Jul 12, 2018
 *      Author: ashu
 */

#ifndef CIRCULARQ_H_
#define CIRCULARQ_H_

class CircularQ {
public:
	CircularQ();
	CircularQ(int c);
	virtual ~CircularQ();
	void printQ();
	void enQueue(int val);
	void deQueue();

private:
	int* Data;
	int front, rear;
	int capacity;
};

#endif /* CIRCULARQ_H_ */
