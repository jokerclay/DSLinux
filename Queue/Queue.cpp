#include "Queue.h"

void sqQueueInitQueue(sqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool sqQueueQueueEmpty(sqQueue Q)
{
    return Q.front == Q.rear;
}

/*

This is the key part of make the queue circular
    * you reserve(预定预留) one slot to distinguish full VS empty
    * rear is about to warp and land on `front` -> means the queue is full

Example: `sqQueueMaxSize = 5`, then the valid positions:
    * `front = 0`,`rear = 4` -> full because `(4+1)%5 ==0`
    * if you didn't reserve that one slot, `front == rear`
    would be ambiguous (empty or full ?)

*/
bool sqQueueQueueFull(sqQueue Q)
{
    return (Q.rear+1)%sqQueueMaxSize == Q.front;
}


bool sqQueueEnQueue(sqQueue &Q,sqQueueElementType e)
{
    if((Q.rear+1) % sqQueueMaxSize == Q.front)
        return false; // full

    Q.data[Q.rear] = e; // store element at `rear`
    Q.rear = (Q.rear + 1) % sqQueueMaxSize; // move `rear` forward,  
    return true;                            // if it reaches the end, `%` wraps it to 0
}

bool sqQueueDeQueue(sqQueue &Q,sqQueueElementType &e)
{
    if(sqQueueQueueEmpty(Q))
        return false;
    e = Q.data[Q.front]; // read from `front`
    Q.front = (Q.front + 1) % sqQueueMaxSize; // move `front` forward, use `%` to warp
    return true;
}

// just read the heade  without remove it
bool sqQueueGetHead(sqQueue Q ,sqQueueElementType  &e)
{
    if(sqQueueQueueEmpty(Q))
        return false;
    e = Q.data[Q.front];
    return true;
}


/*

* The `%sqQueueMaxSize`  ensure circlar behavior
* The `front == rear` queue is empty
* The `(rear +1)%sqQueueMaxSize == front` queue is full
   one  slot is sacrificed to make the logic clean

*/

