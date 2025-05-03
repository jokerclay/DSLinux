#include "../../Queue/Queue.h"
#include "../../DSLog/DSLog.h"
#include <string>

int main()
{
    sqQueue Q;
    sqQueueInitQueue(Q);
    Log(INFO, "initing sqQueue ... ");

    // Empty
    if(sqQueueQueueEmpty(Q))
        Log(INFO,"sqQueue is empty");
    else
        Log(INFO,"sqQueue is NOT empty");

    // enqueue 1,2,3,4
    sqQueueEnQueue(Q,1);
    sqQueueEnQueue(Q,2);
    sqQueueEnQueue(Q,3);
    sqQueueEnQueue(Q,4);

    // get heade 1
    sqQueueElementType headValue;
    if(sqQueueGetHead(Q,headValue))
        Log(INFO, "got head value of the queue which is " + std::to_string(headValue));
    else
        Log(ERROR, "failed to get the head value of the queue" );


    sqQueueElementType removedValue;

    if(sqQueueDeQueue(Q,removedValue))
    {
        Log(INFO, "deQueued value " + std::to_string(removedValue));
        sqQueueGetHead(Q,headValue);
        Log(INFO, "now the head value is " + std::to_string(headValue));
    }else{
        Log(ERROR, "failed to deQueue the queue");
    }
}
