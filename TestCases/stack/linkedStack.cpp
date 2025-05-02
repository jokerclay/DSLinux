#include <string>

#include "../../DSLog/DSLog.h"
#include "../../Stack/Stack.h"


int main()
{
    linkedStack S;
    linkedStackInitStack(S);

    // push 69
    linkedStackElementType data = 69;
    if(linkedStackPush(S, data))
        Log(INFO,"pushed value " + std::to_string(data) + " into the stack");
    else
        Log(INFO,"failed to push value " + std::to_string(data) + " into the stack");

    linkedStackPush(S,1);
    linkedStackPush(S,2);
    linkedStackPush(S,3);
    linkedStackPush(S,4);

    // peek 4
    linkedStackElementType peekedValue;
    if(linkedStackGetTop(S, peekedValue))
        Log(INFO,"got value at the top is " + std::to_string(peekedValue));
    else
        Log(ERROR,"failed to get the value at the top of the stack");

    // pop 4
    linkedStackElementType poped;
    if(linkedStackPop(S, poped))
        Log(INFO,"poped value " + std::to_string(poped));
    else
        Log(ERROR,"failed to pop value at the top of the stack");

    // peek 3
    if(linkedStackGetTop(S, peekedValue))
        Log(INFO,"got value at the top is " + std::to_string(peekedValue));
    else
        Log(ERROR,"failed to get the value at the top of the stack");


    // pop 3
    if(linkedStackPop(S, poped))
        Log(INFO,"poped value " + std::to_string(poped));
    else
        Log(ERROR,"failed to pop value at the top of the stack");


    // pop 2
    if(linkedStackPop(S, poped))
        Log(INFO,"poped value " + std::to_string(poped));
    else
        Log(ERROR,"failed to pop value at the top of the stack");


    // peek 1
    if(linkedStackGetTop(S, peekedValue))
        Log(INFO,"got value at the top is " + std::to_string(peekedValue));
    else
        Log(ERROR,"failed to get the value at the top of the stack");

    // DestoryStack
    Log(INFO,"destorying linked stack");
    linkedStackDestoryStack(S);

    return 0;

}
