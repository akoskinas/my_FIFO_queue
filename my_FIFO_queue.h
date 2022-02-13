// this file contains the interface details regarding the FIFO queue

class myFifoQueue
{
static constexpr int maxSize=10;
public:
    bool enqueue(int element);
    int* dequeue();
    int getFifoQueueSize() const;
    void printQueue() const;
    
private:
    int start{0};
    int stop{0}; 
    int my_array[maxSize]{0};
};