#include "main.h"
#include "Queue/Queue.h"

int main()
{
    sqQueue Q;
    sqQueueInitQueue(Q);

    // enqueue 1,2,3,4
    sqQueueEnQueue(Q,1);
    sqQueueEnQueue(Q,2);
    sqQueueEnQueue(Q,3);

    sqQueueElementType removedVal;
    sqQueueDeQueue(Q,removedVal);
    sqQueueDeQueue(Q,removedVal);

    sqQueueEnQueue(Q,69);
    sqQueueEnQueue(Q,96);

    sqQueueEnQueue(Q,111);
    sqQueueEnQueue(Q,222);

}
