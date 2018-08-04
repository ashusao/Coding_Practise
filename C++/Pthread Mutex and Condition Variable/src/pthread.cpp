/*
 * pthread.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: ashu
 */

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <queue>
using namespace std;

#define NUM_THREADS 3
#define Q_SIZE 5
#define NUM_TIMES 7

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var_p = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_var_c = PTHREAD_COND_INITIALIZER;

queue<int> my_Q;


void print_queue(queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}


// inserts the value into queue
void *producer_thread(void *arg) {

	int id = *(int *) arg;

	for (int i = 0; i < NUM_TIMES; i++) {

		pthread_mutex_lock(&mut);

		if (my_Q.size() == Q_SIZE + 1 ) {

			pthread_cond_signal(&cond_var_c);

			printf("producer_thread(): thread %d Queue Threshold reached.\n",id);

			pthread_cond_wait(&cond_var_p, &mut);

		}else{

			my_Q.push(rand()%100 + 1);

		}

		printf("producer_thread(): thread %d, unlocking mutex\n",id);
		pthread_mutex_unlock(&mut);

		// sleep for 1 sec
		sleep(1);
	}

	cout << "Thread "<< id << " ending" << endl;

	pthread_cond_signal(&cond_var_p);	// awake any other producer thread waiting

	pthread_exit((void *)1);
}

// removes the value from queue when size is greater than max Q size
void *consumer_thread(void *arg) {

	int id = *(int *) arg;

	printf("Starting consumer_thread(): thread %d\n", id);

	pthread_mutex_lock(&mut);

	while(my_Q.size() <= Q_SIZE){

		cout<<"consumer_thread(): waiting ..." << endl;
		pthread_cond_wait(&cond_var_c, &mut);

		printf("consumer_thread(): thread %d Condition signal received.\n", id);
		print_queue(my_Q);
		my_Q.pop();

		cout<< "Queue after removing from front"<<endl;
		print_queue(my_Q);

		pthread_cond_signal(&cond_var_p);

	}

	pthread_mutex_unlock(&mut);

	pthread_exit(NULL);
}

int main(int argc, char **argv) {

	int thread_id[3] = { 1, 2, 3 };
	int exit_1, exit_2;
	pthread_t threads[3];

	pthread_create(&threads[0], NULL, producer_thread, (void *) &thread_id[0]);	// producer thread
	pthread_create(&threads[1], NULL, producer_thread, (void *) &thread_id[1]); // producer thread
	pthread_create(&threads[2], NULL, consumer_thread, (void *) &thread_id[2]); // consumer thread


	pthread_join(threads[0], (void **)&exit_1);
	pthread_join(threads[1], (void **)&exit_2);


//	sleep(1);	// wait for consumer thread to finish

	if(exit_1 == 1 && exit_2 == 1){ // both producer thread finished cancel consumer thread
		pthread_cancel(threads[2]);
	}


	printf("Main(): Waited on %d  threads. Done.\n", NUM_THREADS);
	cout<< "Final values in Queue: "<<endl;
	print_queue(my_Q);

	pthread_mutex_destroy(&mut);
	pthread_cond_destroy(&cond_var_p);
	pthread_cond_destroy(&cond_var_c);

}

