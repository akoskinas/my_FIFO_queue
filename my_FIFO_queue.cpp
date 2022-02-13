// this file contains the FIFO queue implementation

//includes
#include <iostream>
#include <stdlib.h>   // for the random ints to be entered in the queue    
#include "my_FIFO_queue.h"

bool myFifoQueue::enqueue(int element)
{
    if ((stop+1)%maxSize != start)
    {
        my_array[stop] = element;
        stop=(stop+1)%maxSize;
        return true;
    } else {
        return false;
    }
}

int* myFifoQueue::dequeue()
{   
    // to-do: change the next statement after
    int* temp_ptr{nullptr};
    if (start != stop)
    {
        temp_ptr = &(my_array[start]);
        start = (start+1)%maxSize;
    }
    return temp_ptr;
    
}
int myFifoQueue::getFifoQueueSize() const
{
    if (start<=stop)
    {
        return stop-start;
    } else
    {
        return maxSize - (start-stop);
    }
}

void myFifoQueue::printQueue() const
{
    std::cout << "\n===== printing the contents of the queue ==========" << std::endl;
    
    // Question:
    // my goal is to print the elements of the queue in one line
    // I want the displayed integers in one line while being comma-separated
    // Is there any better solution, e.g using iterators?
    int queueSize = this->getFifoQueueSize();
    for(int temp_ind=0;temp_ind< queueSize;temp_ind++)
    {
        if (temp_ind<queueSize-1) //not the last element
        {
            std::cout << my_array[(start+temp_ind)%maxSize] << " ,";
        } else // last element
        {
            std::cout << my_array[(start+temp_ind)%maxSize] << std::endl;
        }
    }
    std::cout << "===== end of queue ==========" << std::endl;
}