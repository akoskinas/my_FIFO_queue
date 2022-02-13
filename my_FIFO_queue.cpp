// this file contains the FIFO queue implementation

//includes
#include <iostream>
#include "my_FIFO_queue.h"

bool myFifoQueue::enqueue(int element)
{
    if (fullQueue)
    {
        return false;
    }
    else // queue is NOT full
    {
        my_array[stop] = element;
        stop=(stop+1)%maxSize;
        if (start == stop)
        {
            fullQueue = true;
        }
        return true;        
    }
}

int* myFifoQueue::dequeue()
{   
    int* temp_ptr{nullptr};
    if ((start != stop) || fullQueue)
    {
        temp_ptr = &(my_array[start]);
        start = (start+1)%maxSize;
        fullQueue = false;
    }
    return temp_ptr;
    
}
int myFifoQueue::getFifoQueueSize() const
{
    if (start<stop)
    {
        return stop-start;
    }
    else if (stop < start)
    {
        return maxSize - (start-stop);
    }
    else // stop==start
    {
        if (fullQueue)
        {
            return maxSize;
        }
        else
        {
            return 0;
        }
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