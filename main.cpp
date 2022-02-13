// this file contains the requirements, sample tests and possible extensions regarding
// a custom FIFO queue implementation

// A. Requirements
// 1. The FIFO queue should contain integers
// 2. The FIFO queue should not throw any exceptions
// 3. The FIFO queue should be in stack and has a max size
// 4. The FIFO queue should support the following API
//      - enqueue
//      - dequeue
//      - getSize

// B. extensions
// 1. make the queue have a dynamic size (heap)
// 2. make the queue accept generic types of elements (template)
// 3. implement similar data structures (e.g LIFO), any ideas?
// 4. what is the behavior when a new int is enqueued and the queue is full?
//      - the enqueue is NOT happening (current implementation)
//      - the queue drops the "oldest" element to make space for the newly arrived element

// C. Extras
//      - how one could write proper tests for that class --> C#

//includes
#include <iostream>
#include "my_FIFO_queue.h"

int main()
{
    std::cout << "start of the testing of the FIFO" << std::endl;
    
    // define a new queue
    myFifoQueue sampleQueue;

    // test some enqueue operations
    std::cout << "\ntesting the enqueueing - part1" << std::endl;
    int maxInterNumberEnq = 5;
    for (int nInter=0; nInter<maxInterNumberEnq;nInter++)
    {
        int temp_int = rand()%100;
        if (sampleQueue.enqueue(temp_int))
        {
            std::cout << "the element " << temp_int << " was enqueued successfully" << std::endl;    
        } else
        {
            std::cout << "the element " << temp_int << "was NOT enqueued successfully" << std::endl;    
        }
    }
    // print the queue
    sampleQueue.printQueue();
    std::cout << "the size of the queue is now: " << sampleQueue.getFifoQueueSize() << std::endl;

    // test some dequeue operations
    std::cout << "\ntesting the dequeueing - part2 " << std::endl;
    int maxInterNumberDeq = 4;
    for (int nInter=0; nInter<maxInterNumberDeq;nInter++)
    {
        int* temp_int = new int;
        temp_int = sampleQueue.dequeue();
        if (temp_int!=nullptr)
        {
            std::cout << "the element " << *temp_int << " was dequeued successfully" << std::endl;    
        } else
        {
            std::cout << "no element dequeued" << std::endl;
        }
    }
    // print the queue
    sampleQueue.printQueue();
    std::cout << "the size of the queue is now: " << sampleQueue.getFifoQueueSize() << std::endl;

    // test some enqueue operations - AGAIN
    std::cout << "\ntesting the enqueueing - part2" << std::endl;
    int maxInterNumberEnq2 = 10;
    for (int nInter=0; nInter<maxInterNumberEnq2;nInter++)
    {
        int temp_int = rand()%100;
        if (sampleQueue.enqueue(temp_int))
        {
            std::cout << "the element " << temp_int << " was enqueued successfully" << std::endl;    
        } else
        {
            std::cout << "the element " << temp_int << " was NOT enqueued successfully" << std::endl;    
        }
    }
    // print the queue
    sampleQueue.printQueue();
    std::cout << "the size of the queue is now: " << sampleQueue.getFifoQueueSize() << std::endl;


    // test some dequeue operations
    std::cout << "\ntesting the dequeueing - part2 " << std::endl;
    int maxInterNumberDeq2 = 12;
    for (int nInter=0; nInter<maxInterNumberDeq2;nInter++)
    {
        int* temp_int = new int;
        temp_int = sampleQueue.dequeue();
        if (temp_int!=nullptr)
        {
            std::cout << "the element " << *temp_int << " was dequeued successfully" << std::endl;    
        } else
        {
            std::cout << "no element dequeued" << std::endl;
        }
    }
    // print the queue
    sampleQueue.printQueue();
    std::cout << "the size of the queue is now: " << sampleQueue.getFifoQueueSize() << std::endl;

    return 0;
}