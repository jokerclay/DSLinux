#include <string>

#include "../../Log/log.h"
#include "../../Stack/Stack.h"

int main()
{
    sqStack S;
    Log(INFO,"InitStack");
    sqStackInitStack(S);

    if(sqStackStackEmpty(S))
        Log(INFO,"sqStack is empty");
    else
        Log(INFO,"sqStack is NOT empty");

    sqStackElementType data = 69;
    if(sqStackPush(S, data))
        Log(INFO,"pushed value " + std::to_string(data) + " into the stack");
    else
        Log(INFO,"failed to push value " + std::to_string(data) + " into the stack");

    sqStackElementType peekedValue;
    if(sqStackGetTop(S, peekedValue))
        Log(INFO,"got value at the top is " + std::to_string(peekedValue));
    else
        Log(ERROR,"failed to get the value at the top of the stack");

    return 0;
}
