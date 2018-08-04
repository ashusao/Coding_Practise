
A simple multi-threaded C++ application developed using POSIX threads where the synchronization between thread is done using **Mutex** and **Condition Variables**.

## Problem Description

- Two Producer thread inserts random integer value into the queue of size Q_SIZE
- Whenever the size increases beyond Q_SIZE producer thread signals the consumer and waits for his signal.
- Consumer then removes the item from front and signals the producers back.
- At last when any producer thread finishes it signals any other producer thread to complete his task.