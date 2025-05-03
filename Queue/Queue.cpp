#include "Queue.h"

void sqQueueInitQueue(sqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool sqQueueQueueEmpty(sqQueue Q)
{
    return Q.front == Q.rear;
}

bool sqQueueQueueFull(sqQueue Q)
{
    return (Q.rear+1)%sqQueueMaxSize == Q.front;
}


bool sqQueueEnQueue(sqQueue &Q,sqQueueElementType e)
{
    if((Q.rear+1) % sqQueueMaxSize == Q.front)
        return false;

    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % sqQueueMaxSize;
    return true;
}

bool sqQueueDeQueue(sqQueue &Q,sqQueueElementType &e)
{
    if(sqQueueQueueEmpty(Q))
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % sqQueueMaxSize;
    return true;
}

bool sqQueueGetHead(sqQueue Q ,sqQueueElementType  &e)
{
    if(sqQueueQueueEmpty(Q))
        return false;
    e = Q.data[Q.front];
    return true;
}
