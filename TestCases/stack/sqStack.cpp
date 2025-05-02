#include <string>

#include "../../DSLog/DSLog.h"
#include "../../Stack/Stack.h"

int main()
{
    sqStack S;

    // init
    Log(INFO,"InitStack");
    sqStackInitStack(S);

    // Empty
    if(sqStackStackEmpty(S))
        Log(INFO,"sqStack is empty");
    else
        Log(INFO,"sqStack is NOT empty");

    // push 69
    sqStackElementType data = 69;
    if(sqStackPush(S, data))
        Log(INFO,"pushed value " + std::to_string(data) + " into the stack");
    else
        Log(INFO,"failed to push value " + std::to_string(data) + " into the stack");

    // peek
    sqStackElementType peekedValue;
    if(sqStackGetTop(S, peekedValue))
        Log(INFO,"got value at the top is " + std::to_string(peekedValue));
    else
        Log(ERROR,"failed to get the value at the top of the stack");

    // pop 69
    sqStackElementType poped;
    if(sqStackPop(S, poped))
        Log(INFO,"poped value " + std::to_string(poped));
    else
        Log(ERROR,"failed to pop value at the top of the stack");


    // push 1,2
    sqStackPush(S, 1);
    sqStackPush(S, 2);

    // peek 2
    if(sqStackGetTop(S, peekedValue))
        Log(INFO,"got value at the top is " + std::to_string(peekedValue));
    else
        Log(ERROR,"failed to get the value at the top of the stack");

    // push 3,4
    sqStackPush(S, 3);
    sqStackPush(S, 4);

    // peek 4
    if(sqStackGetTop(S, peekedValue))
        Log(INFO,"got value at the top is " + std::to_string(peekedValue));
    else
        Log(ERROR,"failed to get the value at the top of the stack");

    return 0;
}
